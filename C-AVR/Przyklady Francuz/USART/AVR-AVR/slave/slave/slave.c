/*
 * slave.c
 *
 * Created: 2014-08-18 12:59:20
 *  Author: tmf
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/crc16.h>
#include <stdbool.h>
#include <string.h>
#include "multi.h"

#define BUF_MAX 10

static void uart_9600()
{
	#define BAUD 9600
	#include <util/setbaud.h>
	UBRR0H=UBRRH_VALUE;
	UBRR0L=UBRRL_VALUE;
	#if USE_2X
	UCSR0A|=_BV(U2X0);
	#else
	UCSR0A&=~(_BV(U2X0));
	#endif
}

void USART_slave_init()
{
	//uart_9600();
	UCSR0C=_BV(USBS0) | _BV(UCSZ01) | _BV(UCSZ00); //8 bitów danych, 2 bity stopu, bez parzystoœci, transmisja asynchroniczna
	UCSR0C|=_BV(UMSEL00);
	UCSR0B=_BV(RXEN0) | _BV(TXEN0) | _BV(RXCIE0); //Odblokuj przerwania odbiornika
}

volatile char Bufor[BUF_MAX];
volatile uint8_t status;

ISR(USART_RX_vect)
{
	static uint8_t bufpos, n, crc;

	if(status) return; //B??d - poprzednia ramka jeszcze nieobs?u?ona

	if(n==0)
	{
		n=UDR0;
		bufpos=0;
		crc=_crc_ibutton_update(0, n);
		return;
	}

	if(bufpos<n)
	{
		Bufor[bufpos]=UDR0;
		crc=_crc_ibutton_update(crc, Bufor[bufpos++]);
	}
	else if(crc==UDR0)
	{
		status=n;
		n=0;
	}
}

int main()
{
	Timer0Init();
	USART_slave_init();
	sei();
	while(1)
	{
		if(status)
		{//Odebrano pakiet
			memcpy((char*)LEDDIGITS, (char*)Bufor, LEDDISPNO);
			status=0; //Pakiet obs?u?ony
		}
	}
}
