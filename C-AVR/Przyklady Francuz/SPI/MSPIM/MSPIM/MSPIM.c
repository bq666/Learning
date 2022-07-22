/*
 * MSPIM.c
 *
 * Created: 2014-08-18 20:57:11
 *  Author: tmf
 */ 


#include <avr/io.h>
#include <util/delay.h>

static void uart_1M()
{
	#define BAUD 1000000UL
	#include <util/setbaud.h>
	UBRR0H=UBRRH_VALUE;
	UBRR0L=UBRRL_VALUE;
	#if USE_2X
	UCSR0A|=_BV(U2X0);
	#else
	UCSR0A&=~(_BV(U2X0));
	#endif
}

void usart_MSPIM_Init()
{
	UBRR0=0;
	DDRD|=_BV(PD4); //SCK jest wyjùciem
	UCSR0C=_BV(UMSEL01) | _BV(UMSEL00) | _BV(UCPHA0) | _BV(UCPOL0); //Tryb SPI 0
	UCSR0B=_BV(RXEN0) | _BV(TXEN0); //W≥πcz nadajnik i odbiornik
	uart_1M(); //SzybkoúÊ transmisji 1Mbps
}

uint8_t usart_Transmit(uint8_t data)
{
	while(!(UCSR0A & _BV(UDRE0))); //Czy bufor jest pusty?
	UDR0=data;
	while(!(UCSR0A & _BV(RXC0))); //Zaczekaj na odebranie bajtu
	return UDR0;
}

int main()
{
	uint8_t data=0;
	PORTD|=_BV(PD2); //Pin SS dla urzπdzenia slave
	DDRD|=_BV(PD2);
	usart_MSPIM_Init();
	while(1)
	{
		PORTD&=(~_BV(PD2)); //Zaadresuj urzπdzenie
		usart_Transmit(data);
		PORTD|=_BV(PD2); //Wy≥πcz je
		data^=0xFF;
		_delay_ms(1000);
	}
}