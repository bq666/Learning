/*
 * stream.c
 *
 * Created: 2014-08-18 11:56:51
 *  Author: tmf
 */ 


#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include "usart.h"

int get(FILE *stream)
{
	while(!(UCSR0A & _BV(RXC0)));  //Zaczekaj na odbiór znaku
	return UDR0;
}

int put(char c, FILE *stream)
{
	while(!(UCSR0A & _BV(UDRE0)));
	UDR0=c;
	return 0;
}

static void uart_9600()
{
	#define BAUD 9600
	#include <util/setbaud.h>
	UBRR0H = UBRRH_VALUE;
	UBRR0L = UBRRL_VALUE;
	#if USE_2X
	UCSR0A |= (1 << U2X0);
	#else
	UCSR0A &= ~(1 << U2X0);
	#endif
}

void USART_init()
{
	uart_9600();  //Ustal szybkoœæ transferu na 9600 bps
	UCSR0B=_BV(RXEN0) | _BV(TXEN0);  //Odblokuj nadajnik i odbiornik
	UCSR0C=_BV(UCSZ00) | _BV(UCSZ01); //8 bitów danych + 1 bit stopu
}

int main(void)
{
	USART_init();
	
	static FILE usartout = FDEV_SETUP_STREAM (put, get, _FDEV_SETUP_RW);
	
	while(1)
	{
		fgetc(&usartout);  //Zaczekaj na klawisz
		fprintf(&usartout, "Oto strumien\r");
	}
}