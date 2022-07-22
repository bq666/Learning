/*
 * 4 Timer Francuz.c
 *
 * Created: 2017-03-24 19:24:20
 * Author : bq666
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


/* void timer_init() 
{
	TIMSK |= (1<<TOIE1);							//Timer/Counter1, Overflow Interrupt Enable
	TCCR1B |= (1<<CS12);							//Preskaler 256
	DDRD |= ((1<<PD4) | (1<<PD5));
	
} */
/* ISR (TIMER1_OVF_vect)
{
	
	static uint8_t LED=0b00100000;			//Pocz¹tkowy stan diod
	LED^=0b00110000;						//Zmieniam stan diody drugiej na przeciwny 
	uint8_t tmp=(PORTD & (~0b00110000));
	PORTD = (tmp | LED);
} */
/* void timer_init()
{
	TCCR1A |= ((1<<COM1A0) | (1<<COM1B0));			//w³¹czenie sterowania pinami IO
	OCR1A=50000;
	OCR1B=50000;
	TCCR1B |= (1<<CS12);							//preskaler 256
	TCCR1A |= (1<<FOC1A);							//zmieñ stan jednego z pinów na przeciwny 
	// TCCR1A |= (1<<FOC1B);
	DDRD |= ((1<<PD4) | (1<<PD5));
} */

void timer_init()
{
	TCCR1A |= ((1<<COM1A0) | (1<<COM1B0));								//Toggle OC1A/OC1B on compare match
	// TCCR1A |= ((1<<FOC1A) | (1<<FOC1B));
	TCCR1B |= (1<<WGM12);									// CTC
	TCCR1B |= ((1<<CS12) | (1<<CS11) | (1<<CS10));						// preskaler 1024
	OCR1A=10;
	OCR1B=F_CPU/1024/800;
	DDRD |= ((1<<PD4) | (1<<PD5));
}

int main(void)
{
    /* Replace with your application code */
    while (1) 
    {
		timer_init();	
		DDRD |= (1<<PD6);
		PORTD |= (1<<PD6);
		while(1)
		{
			PORTD^=(1<<PD6);
			_delay_ms(1000);			
		}
    }
}

/*
timer_init();
sei();
while(1); */

// timer_init();