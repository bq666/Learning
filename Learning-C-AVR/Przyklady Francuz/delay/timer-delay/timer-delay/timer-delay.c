/*
 * timer_delay.c
 *
 * Created: 2014-06-29 14:00:25
 *  Author: tmf
 */ 


#include <avr/io.h>

void Wait_for(uint16_t delay)              //Realizuje op�nienie o zadanym czasie liczonym
{                                          //w odcinkach co 100 us
	TCCR1B=(1<<CS12) | (1<<CS10);          //Preskaler timera 1024
	TCNT1=0;                               //Pobierz aktualny stan licznika timera
	uint16_t val=delay*(F_CPU/10000UL)/1024;   //Przelicz op�nienie
	
	while(TCNT1 < val);                    //Czekaj
}


int main(void)
{
	DDRB=1<<PB5;  //Port steruj�cy LEDem
	while(1)
	{
		PORTB^=(1<<PB5);     //Zmie� stan wyj�cia steruj�cego LED na przeciwny
		Wait_for(10000);     //Odczekaj sekund�
	}
}
