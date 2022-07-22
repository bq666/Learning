/*
 * miernik.c
 *
 * Created: 2014-08-22 22:02:07
 *  Author: tmf
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/atomic.h>
#include <string.h>
#include <stdlib.h>
#include "KS0108lib.h"
#include "graphics.h"

void timer_init()
{
	TCCR1B=_BV(ICNC1) | _BV(ICES1);  //W³¹cz filtrowanie ICP, zdarzenie na zboczu narastaj¹cym
	TCCR1B|=_BV(CS11) | _BV(CS10);   //Preskaler 64, tryb normalny
	TIMSK1=_BV(ICIE1) | _BV(TOIE1);  //Przerwania ICP i overflow
}

volatile uint8_t isOk;

ISR(TIMER1_OVF_vect)
{
	isOk=0;  //B³¹d przepe³nienia licznika
}

volatile uint16_t timestamp;
volatile uint16_t period;

ISR(TIMER1_CAPT_vect)
{
	static uint16_t loctimestamp;

	if(TCCR1B & _BV(ICES1))
	{
		GTCCR=_BV(PSRSYNC);
		TCNT1=0;
		TCCR1B=TCCR1B & (~_BV(ICES1)); //Nastêpne zdarzenie na zboczu opadaj¹cym
		period=ICR1;
		timestamp=loctimestamp;
		isOk=255;
	} else
	{
		TCCR1B=TCCR1B | _BV(ICES1); //Nastêpne zdarzenie na zboczu narastaj¹cym
		loctimestamp=ICR1;
	}
}

int main()
{
	char bufor[6];
	uint16_t ts, pr;
	uint8_t ok, len;

	GLCD_init();
	GLCD_cls();
	GLCD_goto(0,0);
	GLCD_puttext(PSTR("Wsp. wypelnienia [%]:"));
	GLCD_goto(0,2);
	GLCD_puttext(PSTR("Czestotliwosc [Hz]:"));
	timer_init();
	sei();
	while(1)
	{
		ATOMIC_BLOCK(ATOMIC_FORCEON)
		{
			ok=isOk;
			ts=timestamp;
			pr=period;
		}
		if(ok==0)
		{
			ts=0; period=0;
		}
		GLCD_goto(0,1);
		if(ts) utoa(100*ts/pr, bufor, 10); else bufor[0]=0;
		len=strlen(bufor);
		memmove(&bufor[6-len], bufor, len+1);
		for(uint8_t i=0;i<(6-len);i++) bufor[i]=' ';
		GLCD_puttext(bufor);
		GLCD_goto(0,3);
		if(pr) utoa(F_CPU/64/pr, bufor, 10); else bufor[0]=0;
		len=strlen(bufor);
		memmove(&bufor[6-len], bufor, len+1);
		for(uint8_t i=0;i<(6-len);i++) bufor[i]=' ';
		GLCD_puttext(bufor);
	}
}
