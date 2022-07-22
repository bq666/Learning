#include <util\atomic.h>
#include <util\delay.h>
#include <avr\io.h>
#include "1wire_basic.h"

uint8_t Error;

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

static void uart_115200()
{
#undef BAUD
#define BAUD 115200
#include <util/setbaud.h>
 UBRR0H=UBRRH_VALUE;
 UBRR0L=UBRRL_VALUE;
#if USE_2X
 UCSR0A|=_BV(U2X0);
#else
 UCSR0A&=~(_BV(U2X0));
#endif
}

static void waitforTx()
{
 while(!(UCSR0A & _BV(TXC0)));
 UCSR0A|=_BV(TXC0); //Skasuj flagê TXC0
}

void OW_SendBit(bool bit)
{
 if(bit) UDR0=0xFF; else UDR0=0;
 waitforTx();
}

bool OW_ReadBit()
{
 while(UCSR0A & _BV(RXC0)) UDR0; //Usuñ ew. œmieci z bufora
 UDR0=0xFF;
 waitforTx();
 if(UDR0==0xFF) return 1;
 return 0;
}

void OW_ResetPulse()
{
 uart_9600();
 UDR0=0xF0;
 waitforTx(); //Poczekaj na koniec transmisji
 uart_115200();
}

bool OW_WaitForPresencePulse()
{
	OW_ResetPulse();
	if(UDR0==0xF0) return false;
	return true;
}

void OW_init()
{
 UCSR0B=_BV(RXEN0) | _BV(TXEN0); //8-bitów danych, 1 bit stopu, bez parzystoœci
}
