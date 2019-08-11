/*
 * RTC.c
 *
 * Created: 2014-08-30 20:35:27
 *  Author: tmf
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>

volatile uint32_t seconds;    //Licznik sekund

ISR(TIMER2_OVF_vect)
{
	TCCR2B=_BV(CS22) | _BV(CS20);
	seconds++;
}

void initRTC()
{
	ASSR|=_BV(AS2);               //Timer/Counter2 jest taktowany asynchronicznie
	TCNT2=0x00;
	TCCR2B=_BV(CS22) | _BV(CS20); //preskaler 128, nadmiar wyst¹pi co 1s
	while(ASSR&0x07);             //Poczekaj na uaktualnienie T/C2
	TIMSK2|=_BV(TOIE2);           //odblokuj przerwanie Timer/Counter2 Overflow
}

int main()
{
	initRTC();
	set_sleep_mode(SLEEP_MODE_PWR_SAVE);
	sei();
	while(1)
	{
		while(ASSR&0x07);
		sleep_mode();
	}
}
