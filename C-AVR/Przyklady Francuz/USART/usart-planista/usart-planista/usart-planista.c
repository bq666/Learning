/*
 * usart_planista.c
 *
 * Created: 2014-08-18 10:05:20
 *  Author: tmf
 */ 


#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include <stdbool.h>
#include <avr/pgmspace.h>
#include <util/atomic.h>
#include <util/delay.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "usart.h"
#include "bufusart.h"
#include "RingBuffer.h"

#define MAX_CMD_LEN 10      //Maksymalna d?ugoùä polecenia w bajtach

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
	uart_9600();  //Ustal szybkoùä transferu na 9600 bps
	UCSR0B=_BV(RXEN0) | _BV(TXEN0) | _BV(RXCIE0) | _BV(TXCIE0);  //Odblokuj nadajnik i odbiornik oraz przerwania
	UCSR0C=_BV(UCSZ00) | _BV(UCSZ01); //8 bit°w danych + 1 bit stopu
}

ISR(TIMER0_OVF_vect)
{
	static uint8_t counter;
	if(counter++ == 64)
	{
		USART_send_buf(&sendBuf, PSTR("Witam w przerwaniu\r\n"));
		counter=0;
	}
}

void Timer_init()
{
	TCCR0B=_BV(CS02) | _BV(CS00);  //Preskaler 1024
	TIMSK0=_BV(TOIE0);             //Przerwanie nadmiaru
}

int main(void)
{
	USART_init();
	Timer_init();
	sei();
	
	while(1)
	{
		USART_send_buf(&sendBuf, PSTR("Witam w aplikacji\r\n"));
		_delay_ms(1000);
	}
}