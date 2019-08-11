/*
 * assert_stderr.c
 *
 * Created: 2014-08-19 15:57:09
 *  Author: tmf
 */ 


#include <avr/interrupt.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "usart.h"

#define __ASSERT_USE_STDERR

#include <assert.h>

static int uart_putchar(char c, FILE *stream);   //Funkcja wysy³aj¹ca bajt poprzez strumieñ
static FILE mystderr = FDEV_SETUP_STREAM(uart_putchar, NULL, _FDEV_SETUP_WRITE); //Strumieñ wyjœciowy dla b³êdów

static int uart_putchar(char c, FILE *stream)
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

void cpy(void *src, void *dst, int size)
{
	assert(src != NULL);
	assert(dst != NULL);
	memcpy(src, dst, size);
}

int main(void)
{
	USART_init();
	
	stderr= &mystderr;  //Ustaw wskaŸnik strumienia b³êdów (stderr) na zdefiniowany wczeœniej strumieñ

	sei();


	while (1)
	{
		if((PINB & _BV(PB7)) == 0)
		{
			cpy(NULL, NULL, 0);
		}
	}
}

