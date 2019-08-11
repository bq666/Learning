/*
 * Symulator.c
 *
 * Created: 2014-08-19 15:33:47
 *  Author: tmf
 */ 


#include <avr/io.h>

int main(void)
{
	volatile uint16_t counter=0;
	do
	{
		counter ++;
	} while (PINB & _BV(PB7));

	do
	{
		counter ++;
	} while (!(PINB & _BV(PB7)));


	counter++;

	while(1)
	{
		//TODO:: Please write your application code
	}
}