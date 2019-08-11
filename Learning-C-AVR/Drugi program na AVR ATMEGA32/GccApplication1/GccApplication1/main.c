/*
 * GccApplication1.c
 *
 * Created: 2017-03-08 20:34:17
 * Author : bq666
 */ 

#include <avr/io.h>


int main(void)
{
    /* Replace with your application code */
    while (1) 
    {
		DDRC=0b11111111;
		PORTC=0b11111110;
    }
}

