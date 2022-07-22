/*
 * NoiseCanceler.c
 *
 * Created: 2014-08-14 14:34:29
 *  Author: tmf
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/atomic.h>
#include <avr/sleep.h>

ISR(ADC_vect)
{
}

void ADCInit()
{
	ADMUX=_BV(REFS1) | _BV(REFS0);    //Wewn�trzne nap. referencyjne, kana� 0, wyr�wnanie do prawej
	ADCSRA=_BV(ADEN) | _BV(ADIE) | _BV(ADPS2) | _BV(ADPS1) | _BV(ADPS0);    //W��cz ADC, przerwania, preskaler 128
}

int GetADC()
{
	set_sleep_mode(SLEEP_MODE_ADC);    //Tryb noise canceller
	ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {sleep_enable();};     //Odblokuj mo�liwo�� wej�cia w tryb sleep
	sleep_cpu();                       //Wejd� w tryb u�pienia
	sleep_disable();                   //Zablokuj mo�liwo�� wej�cia w tryb sleep
	return ADC;
}


int main(void)
{
	sei();
	ADCInit();
	static int res;
	res=GetADC();
	res=GetADC();
    while(1)
    {
        //TODO:: Please write your application code 
    }
}