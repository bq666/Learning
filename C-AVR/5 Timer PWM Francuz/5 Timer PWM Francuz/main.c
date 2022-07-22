/*
 * _5_Timer_PWM_Francuz.c
 *
 * Created: 2017-03-25 18:21:03
 * Author : bq666
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>



void timer_init()
{
	TCCR0 |= (1<<COM00);								//Toggle OC0 on compare match	
	OCR0=255;
	TCCR0 |= ((1<<WGM01) | (1<<CS00) | (1<<CS02));					//CTC,clkI/O/(No prescaling) 
}



int main(void)
{
	DDRB |= (1<<PB3);
	timer_init();
	while(1);

}

