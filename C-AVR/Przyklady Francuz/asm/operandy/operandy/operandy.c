/*
 * operandy.c
 *
 * Created: 2014-07-01 21:35:06
 *  Author: tmf
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>

uint8_t x;

ISR(TIMER1_OVF_vect)
{
	x++;
}

int main(void)
{
	PORTB=0x01;       // Wybór pierwszej kolumny
	asm volatile("nop");
	uint8_t kbd=PINB; // Odczyt wiersza

	
	uint8_t nibbles=0xF0;
	asm volatile("swap %0" : "=r" (nibbles) : "0" (nibbles));
	asm volatile("swap %0" : "=y" (nibbles) : "0" (nibbles));
	
	asm volatile("swap %[nibbles]" : [nibbles] "=r" (nibbles) : "0" (nibbles));

	uint16_t dodaj=0;
	asm volatile("ADIW %0 , 1" : "=y" (dodaj) : "0" (dodaj));

	uint8_t value =0xff;
	asm volatile("out %0, %1":: "I" (_SFR_IO_ADDR(PORTB)), "r" (value));
}