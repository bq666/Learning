/*
 * LCDAlfa_transact.c
 *
 * Created: 2014-08-15 11:03:19
 *  Author: tmf
 */ 


#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "defines.h"
#include "hd44780.h"
#include <avr\pgmspace.h>
#include <util\delay.h>
#include <avr/interrupt.h>
#include "Alloc_safe.h"
#include "LCD_trans.h"

ISR(TIMER1_OVF_vect)
{
	static char int_buf[sizeof(LCD_trans) + 7];
	static uint16_t cnt;
	char bufstr[6];
	
	utoa(cnt++, bufstr, 10);
	while(strlen(bufstr)<5) strcat(bufstr, " ");
	LCD_PutText_B(6,1, bufstr, (LCD_trans*)&int_buf, false);
}

void Timer1Init()
{
	TCCR1B=_BV(CS12);      //Timer w trybie 0, preskaler 256 - nadmiar co ok. 1 s
	TIMSK1=_BV(TOIE1);     //Odblokuj przerwanie nadmiaru timera
}

int main(void)
{
	LCD_Init();
	LCD_Timer_init();
	Timer1Init();         //Zainicjuj timer generuj¹cy okresowo komunikaty
	sei();
	
	LCD_PutText(0,0, "Numer:");
	LCD_PutText(0,1, "INT  :");
	uint16_t cnt=0;
	LCD_trans *buf=malloc_re(sizeof(LCD_trans) + 7);
	char bufstr[6];
	
	while(1)
	{
		_delay_ms(100);
		utoa(cnt++, bufstr, 10);
		while(strlen(bufstr)<5) strcat(bufstr, " ");
		LCD_PutText_B(6,0, bufstr, buf, false);
		while(!LCD_IsTransCompleted(buf));
	}
}


