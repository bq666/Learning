/*
 * Szablon atmega32,F_CPU_16M.c
 *
 * Created: 2017-03-25 18:21:03
 * Author : bq666
 */ 

#include <avr/io.h>
#include <avr/delay.h>

int main(void)
{
    /* Replace with your application code */
    while (1) 
    {
		DDRC |= (1<<PC7);
		DDRC &= ~(1<<PC6);
		PORTC |= (1<<PC6);
		if (PINC & (1<<PC6))
		{
			_delay_ms(100);
			if (PINC & (1<<PC6))
			{
				PORTC ^= (1<<PC6)
			}
			
		}
    }
}

