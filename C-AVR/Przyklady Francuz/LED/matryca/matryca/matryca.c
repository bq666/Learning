/*
 * matryca.c
 *
 * Created: 2014-08-24 21:39:52
 *  Author: tmf
 */ 


#include <avr/io.h>
#include <stdint.h>
#include <string.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "font5x8.h"         //Tablica czcionek 5x8

#define M_WITDTH   6         //D³ugoœæ wiersza matrycy w bajtach
#define M_HEIGHT   8         //Wysokoœæ matrycy w wierszach
#define LED_REFRESHRATE 300  //Czêstotliwoœæ odœwierzania matrycy

uint8_t Bufor[M_HEIGHT][M_WITDTH+1]={  //Miejsce na bufor i adres wiersza
	{0, 0, 0, 0, 0, 0, 0b11111110},
	{0, 0, 0, 0, 0, 0, 0b11111101},
	{0, 0, 0, 0, 0, 0, 0b11111011},
	{0, 0, 0, 0, 0, 0, 0b11110111},
	{0, 0, 0, 0, 0, 0, 0b11101111},
	{0, 0, 0, 0, 0, 0, 0b11011111},
	{0, 0, 0, 0, 0, 0, 0b10111111},
	{0, 0, 0, 0, 0, 0, 0b01111111}};
	
const char __flash tekst[]="ATMEGA328P wita!!!";      //Tekst wyœwietlany na matrycy

uint8_t *Buforptr;

ISR(USART_UDRE_vect)
{
	static uint8_t Pos;  //Bie¿¹cy bajt w linii
	
	UDR0=*Buforptr++;    //Wyœlij kolejny bajt danych
	if(Pos++ == M_WITDTH)
	{
		UCSR0A|=_BV(TXC0);             //Skasuj flagê TXC
		while(!(UCSR0A & _BV(TXC0)));  //Zaczekaj na koniec transferu linii

		PORTD|=_BV(PD2);               //Wygeneruj sygna³ zatrzaœniêcia danych
		PORTD&=~_BV(PD2);
		Pos=0;                         //Zaczynamy od nowej linii
		if(Buforptr == &Bufor[M_HEIGHT-1][M_WITDTH+1]) Buforptr=&Bufor[0][0];        //Zaczynamy generowanie obrazu od nowa
	}
}

void SPI_init()
{
	DDRD|=_BV(PD2);     //Pin steruj¹cy sygna³em Latch Enable
	DDRD|=_BV(PD4);     //Pin SCK jest wyjœciem - master mode
	UCSR0C=_BV(UMSEL01) | _BV(UMSEL00) | _BV(UCPHA0) | _BV(UCPOL0); //Tryb SPI
	UCSR0B=_BV(TXEN0) | _BV(UDRIE0);  //Potrzebujemy tylko MOSI, przerwanie pustego bufora
	UBRR0=58;            //Szybkoœæ wysy³ania bitów
}

void ASM_ROL(uint8_t cnt, uint8_t *buf) //Funkcja rotacji bitów, buf - adres bufora, cnt - jego d³ugoœæ
{
	__asm__ __volatile__
	(
	"  clc"                   "\n\t"
	"__l1:"                   "\n\t"
	"  ld __tmp_reg__, %a0"   "\n\t"
	"  rol __tmp_reg__"       "\n\t"
	"  st %a0+, __tmp_reg__"  "\n\t"
	"  dec %1"                "\n\t"
	"  brne __l1"             "\n\t"
	: "=e" (buf), "=r" (cnt)
	: "0" (buf), "1" (cnt)
	: "r0");
}

int main(void)
{
	Buforptr=&Bufor[0][0];   //Zainicjuj wskaŸnik do bufora
	SPI_init();              //Zainicjuj interfejs SPI (USART)
	
	sei();

	uint16_t txtcol=strlen_P(tekst)*FON_WIDTH;  //Oblicz ile pikseli ma tekst na szerokoœæ
	uint16_t currcol=0;                         //Numer ostatniej wyœwietlanej kolumny
	uint8_t kolor=0;
	
	while(1)
	{
		uint16_t ind=(tekst[currcol/FON_WIDTH] - ' ') * FON_WIDTH + (currcol % FON_WIDTH);
		uint8_t col=font5x8[ind];    //Pobierz bajt opisu czcionki
		for(uint8_t p=0; p<8; p++)
		{
			ASM_ROL(M_WITDTH, &Bufor[p][0]);
			ASM_ROL(M_WITDTH, &Bufor[p][0]); //Przesuñ tekst w lewo o 1 piksel (2 bity koloru)
			if(col & 1) Bufor[p][0]=Bufor[p][0] | (kolor + 1);
			col>>=1;
		}
		currcol=(currcol+1) % txtcol;
		if(currcol==0) kolor=(kolor + 1) % 3;  //Zmieñ kolor
		_delay_ms(50);
	}	
}