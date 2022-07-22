/*
 * _5_Timer_PWM_Francuz.c
 *
 * Created: 2017-03-25 18:21:03
 * Author : bq666
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

ISR (TIMER1_COMPA_vect)
{
	PORTD ^= (1<<PB2);
}


void timer_init()
{
	OCR1A = 0x3D08;
	TCCR1B |= (1<<WGM12);				//Mode 4, CTC on OCR1A
	TIMSK |= (1<<OCIE1A);				//Set interrupt on compare match
	TCCR1B |= ((1<<CS12) | (1<<CS10));	//clkI/O/1024 (From prescaler)	16M/1024/15624=1,0000640041
}



int main(void)
{
	DDRD |= (1<<PB2);
    /* Replace with your application code */
    while (1) 
    {
		timer_init();
		sei ();							 // W³¹czenie globalnego zezwolenia na przerwania 
		ISR (TIMER1_COMPA_vect);
		
    }
}

