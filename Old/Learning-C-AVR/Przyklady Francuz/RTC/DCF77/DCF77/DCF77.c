/*
 * DCF77.c
 *
 * Created: 2014-08-30 14:48:36
 *  Author: tmf
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <util/delay.h>
#include <util/atomic.h>

#include "defines.h"
#include "hd44780.h"
#include "LCD.h"
#include "calendar.h"


struct calendar_date dt={0, 0, 0, 0, 0, 2014};  //1 stycznia 2014, godzina 0:00
volatile uint32_t Timestamp;
_Bool TimestampUpdate;

uint32_t GetTimestamp();               //Pobierz timestamp w sposób atomowy
void SetTimestamp(uint32_t ats);       //Ustaw timestamp w sposób atomowy

uint32_t GetTimestamp()
{
	uint32_t tmp;
	ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
	{
		tmp=Timestamp;
	}
	return tmp;
}

void SetTimestamp(uint32_t ats)
{
	ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
	{
		Timestamp=ats;
	}
}

int main(void)
{
	char buf[21];        //Bufor do konwersji czasu
	
	DCF77_Rec_Init();   //Inicjuj obs³gê odbiornika DCF77
	lcd_init();         //Inicjuj obs³ugê LCD
	
	SetTimestamp(calendar_date_to_timestamp(&dt));  //Zamieñ datê na EPOCH
	TimestampUpdate=true;    //Jeœli bêdzie okazja to uaktualnij czas na podstawie danych z DCF77
	
	DDRB|=_BV(PB5);     //Pin steruj¹cy LEDem
	PORTB&=~_BV(PB5);
	
	sei();
	
	while(1)
	{
		calendar_timestamp_to_date(GetTimestamp(), &dt);  //Konwersja EPOCH na normalny zapis daty
		lcd_cls();
		sprintf(buf, "%02u:%02u:%02u\n%2u/%02u/%4u", dt.hour, dt.minute, dt.second, dt.date+1, dt.month+1, dt.year);      //Wyœwietl czas i datê
		lcd_puttext(buf);
		_delay_ms(1000);
		if(TimestampUpdate==0)
		{
			TimestampUpdate=1;
		}
	}
}