/*
 * Klawisze_ADC.c
 *
 * Created: 2014-08-21 18:13:07
 *  Author: tmf
 */ 


#include <avr\io.h>
#include <stdio.h>
#include <stdbool.h>
#include <avr\interrupt.h>
#include <util\atomic.h>
#include "KS0108lib.h"
#include "graphics.h"

#define KEY_ERROR	10
#define ADCERROR	10
#define KEY_1	512
#define KEY_2	615
#define KEY_1_2 768
#define NOKEY	0

volatile uint16_t ADCVal;

ISR(ADC_vect)
{
	static uint16_t lastADC;
	uint16_t tmp=ADC;
	TIFR1|=_BV(OCF1B);
	uint16_t low=0;
	if(lastADC>ADCERROR) low=lastADC-ADCERROR;

	if((tmp>(low)) && (tmp<(lastADC+ADCERROR))) ADCVal=tmp;
	lastADC=tmp;
}

void ADC_init()
{
	ADMUX=_BV(REFS0) | 0b0101;	//Nap. referencyjne Vcc, kana- 5, wyríwnanie do prawej
	ADCSRA=_BV(ADEN) | _BV(ADIE) | _BV(ADPS2) | _BV(ADPS1) | _BV(ADPS0);	//W-Žcz ADC, przerwania, preskaler 128
	ADCSRB=_BV(ADTS2) | _BV(ADTS0);	//W??cz wyzwalanie zdarzeniem timer1 compare match B
	ADCSRA|=_BV(ADATE);
}

void TMER_init()
{
	TCCR1B=_BV(CS11) | _BV(CS10) | _BV(WGM12);	//Preskaler 64, tryb CTC
	OCR1A=1250;	//Top zliczania w trybie CTC
	OCR1B=1250;
}

bool InRange(uint16_t val, uint16_t range, uint8_t error)
{
	if((val>(range-error)) && (val<(range+error))) return true;
	return false;
}

uint16_t GetKeyNo()
{
	uint16_t adc;
	ATOMIC_BLOCK(ATOMIC_FORCEON)
	{
		adc=ADCVal;
	}
	if(InRange(adc, KEY_1, KEY_ERROR)) return 1;
	if(InRange(adc, KEY_2, KEY_ERROR)) return 2;
	if(InRange(adc, KEY_1_2, KEY_ERROR)) return 3;

	return NOKEY;
}

int main()
{
	char wynik[6];

	GLCD_init();
	ADC_init();
	TMER_init();
	GLCD_cls();
	GLCD_goto(0,0);

	GLCD_puttext(PSTR("Klawisz:"));
	while(1)
	{
		sprintf(wynik, "%d", GetKeyNo());
		GLCD_goto(0, 10);
		GLCD_puttext(wynik);
	}
}
