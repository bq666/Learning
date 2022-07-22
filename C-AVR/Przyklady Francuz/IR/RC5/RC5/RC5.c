/*
 * RC5.c
 *
 * Created: 2014-09-01 14:34:29
 *  Author: tmf
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdlib.h>

#include "usart.h"
#include "RingBuffer.h"

#define IR_HALF_BIT      889     //Czas trwania p�bitu
#define IR_BIT_TOLERANCE 100     //Tolerancja czasu trwania p�bitu
#define IR_BITSNO         13     //Liczba bit�w kodu - 9 + 1 prebit

volatile uint16_t IR_RecCmd;     //Odebrana komenda z pilota
volatile uint8_t  IR_recpos;     //Nr aktualnie odbieranego bitu

CircBuffer IR_CMD_Buffer; //Instancja bufora ko�owego przechowuj�cego polecenia
static uint8_t IR_Polarity;           //Stan dekodera Manchester

static inline uint16_t IR_CalcTime(uint16_t time)
{
	return time*(F_CPU/1000000UL)/64;   //Przelicz czas w mikrosekundach na tykni�cia timera
	                                    //Przy timerze taktowanym CLKPER/64
}

ISR(PCINT0_vect)
{
	uint8_t Pin=0;
	if(PINB & _BV(PB0)) Pin=1;
	if(IR_Polarity ^ Pin)       //Sprawd� czy przerwanie wywo�a�o zbocze opadaj�ce czy narastaj�ce
	{	
	 TCNT1=0;
	 if(IR_recpos==0)           //Inicjujemy odbi�r
	 {
		IR_RecCmd=1;
		IR_Polarity=1;
		TCCR1B=_BV(ICNC1) | _BV(WGM12) | _BV(CS11) | _BV(CS10);  // wybierz tryb 4, OCR1A okre�la top, preskaler 64, noise canceller, zdarzenie na opadaj�cym zboczu
	 }
	}
}

//Przerwanie wywo�ywane przy przekroczeniu czasu bitu
ISR(TIMER1_COMPA_vect)
{
	IR_recpos=0;
	TCCR1B=0;        //Wy��cz timer
	IR_Polarity=1;   //Czekamy na nowy pocz�tek ramki
}

//Przerwanie wywo�ywane przy pr�bkowaniu stanu bitu
ISR(TIMER1_COMPB_vect)
{
	uint8_t tmp=PINB;
	if(tmp & _BV(PB0))  //Stan wej�cia PB0 jest r�wny 1?
		IR_Polarity=1; else IR_Polarity=0;
	
	IR_RecCmd<<=1;
	IR_RecCmd|=IR_Polarity;   //Wsu� warto�� bitu
	++IR_recpos;
	if(IR_recpos==IR_BITSNO)
	{
		TCCR1B=0;   //Wy��cz timer, wszystko odebrane
		IR_recpos=0;
		cb_Add(&IR_CMD_Buffer, IR_RecCmd);     //Dodaj odczytane polecenie do kolejki
	}
}

void IR_init()
{
	PORTB=_BV(PB0);       //W��cz pullup na pinie PB0
	PCMSK0=_BV(PCINT0);   //W��cz przerwania zwi�zane z PB0
	PCICR=_BV(PCIE0);     //Zezw�l na przerwanie PCINT0
	TCCR1A=0;             //Od��cz piny OCx, wybierz tryb CTC
	OCR1A=IR_CalcTime(3*IR_HALF_BIT);    //Okres timera
	OCR1B=IR_CalcTime(1.5*IR_HALF_BIT);  //Moment pr�bkowania - 3/4 bitu
	TIMSK1=_BV(OCIE1A) | _BV(OCIE1B);    //Odblokuj przerwanie compare match z OC1A oraz OC1B
	IR_Polarity=1;
}

int main(void)
{
	char bufor[13];
	
	IR_init();
	USART_init();
	sei();
	
	USART_send("Odbior RC5. Nacisnij przycisk...");
	while(1)
	{
		if(cb_IsEmpty(&IR_CMD_Buffer)==false)
		{
			CB_Element cmd=cb_Read(&IR_CMD_Buffer);
			ultoa(cmd, bufor, 16);
			USART_send(bufor);
			USART_putchar('\n');
			USART_putchar('\r');
		}
	}
}
