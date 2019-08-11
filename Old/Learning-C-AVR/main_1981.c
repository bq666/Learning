/*
 * LED_8seg_multiplex.c
 *
 * Created: 2017-03-11 15:29:46
 * Author : bq666
 */ 

#include <avr/io.h>
#include <util/delay.h>

const uint16_t CZAS = 500;

int m1981 (void)
{
    /* Replace with your application code */
		DDRA=0b11111111;
		DDRC=0b00001111;
	while (1) 
    {		
		PORTA=0b11111001;
		PORTC=0b00001110;
		//PORTC=0b00001111;
		_delay_us( CZAS );
		PORTA=0b10010000;
		PORTC=0b00001101;
		//PORTC=0b00001111;
		_delay_us( CZAS );
		PORTA=0b10000000;
		PORTC=0b00001011;
		//PORTC=0b00001111;
		_delay_us( CZAS );
		PORTA=0b11111001;
		PORTC=0b00000111;
		//PORTC=0b00001111;
		_delay_us(CZAS);
    }
}

