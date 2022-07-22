/*
 * LED_hardware.c
 *
 * Created: 2014-08-22 20:18:14
 *  Author: tmf
 */ 


#include <avr/io.h>

void timer_init()
{
	TCCR1A|=(_BV(COM1A0) | _BV(COM1B0));
	OCR1A=32678;
	OCR1B=32768;
	TCCR1B=_BV(CS12);  //Preskaler 256
	TCCR1C=_BV(FOC1A);
	DDRB|=(_BV(PB1) | _BV(PB2));
}


int main(void)
{
    timer_init();
}