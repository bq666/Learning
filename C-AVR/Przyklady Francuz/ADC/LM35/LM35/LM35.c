/*
 * LM35.c
 *
 * Created: 2014-08-21 17:18:13
 *  Author: tmf
 */ 


#include <avr\io.h>
#include <stdio.h>
#include <avr\interrupt.h>
#include <util\atomic.h>
#include <string.h>
#include <util\delay.h>
#include "KS0108lib.h"
#include "graphics.h"

#define NOOFSAMPLES	128

volatile uint32_t ADCVal;

ISR(ADC_vect)
{
	static uint32_t ADCaccum;
	static uint8_t sampleno;

	ADCaccum+=ADC;
	sampleno++;
	if(sampleno==NOOFSAMPLES)
	{
		ADCVal=ADCaccum;
		ADCaccum=0;
		sampleno=0;
	}
}

void ADC_init()
{
	ADMUX=_BV(REFS0) | _BV(REFS1) | 0b0101;	//Wew. referencyjne, kana³ 5, wyrównanie do prawej
	ADCSRA=_BV(ADEN) | _BV(ADIE) | _BV(ADPS2) | _BV(ADPS1) | _BV(ADPS0);	//W³¹cz ADC, przerwania, preskaler 128
	ADCSRA|=(_BV(ADATE) | _BV(ADSC));
}

uint16_t GetTemperature()
{
	uint32_t adc;
	ATOMIC_BLOCK(ATOMIC_FORCEON)
	{
		adc=ADCVal;
	}

	return (adc*11000UL)/(1024UL*NOOFSAMPLES);
}

int main()
{
	char wynik[7];

	GLCD_init();
	ADC_init();
	GLCD_cls();
	GLCD_goto(0,0);

	GLCD_puttext(PSTR("Temperatura:"));
	while(1)
	{
		sprintf(wynik, "%5d", GetTemperature());
		uint8_t len=strlen(wynik);
		memmove(&wynik[len-1], &wynik[len-2], 3);
		wynik[len-2]=',';
		GLCD_goto(0, 10);
		GLCD_puttext(wynik);
		_delay_ms(500);
	}
}
