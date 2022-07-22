/*
 * WS2812B_SPI.c
 *
 * Created: 2014-08-24 17:18:27
 *  Author: tmf
 */ 

#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>

#define LEDNO   30           //Liczba LED�w

static inline void SPI_WS_Reset()   //Taktowanie SPI dla sygna�u RESET
{
	UBRR0=49;  //Dla 16 MHz daje to czas trwania bitu r�wny 6,25 us, a bajtu 50 us
}

static inline void SPI_WS_Data()   //Taktowanie SPI dla transferu danych
{
	UBRR0=2;    //Dla 16 MHz daje to czas wysy�ania bitu r�wny 375 ns
}

void WS2812B_init()
{
	DDRD|=_BV(PD4);     //Pin SCK jest wyj�ciem - master mode
	UCSR0C=_BV(UMSEL01) | _BV(UMSEL00) | _BV(UCPHA0); // | _BV(UCPOL0); //Tryb SPI
	UCSR0B=_BV(TXEN0);  //Potrzebujemy tylko MOSI
}

void WS2812B_reset()
{
	SPI_WS_Reset();     //Dostosuj szybko�� SPI
	while(!(UCSR0A & _BV(UDRE0)));  //Zaczekaj na miejsce w buforze
	UCSR0A|=_BV(TXC0);  //Skasuj flag� sygnalizuj�c� nadanie ramki
	UDR0=0;             //Wy�lij impuls ujemny o czasie trwania >50 us
	while((UCSR0A & _BV(TXC0)) == 0);  //Zaczekaj na koniec sygna�u RESET
	SPI_WS_Data();      //Prze��cz szybko�� SPI do nadawania danych
}

void WS2812B_send(uint8_t byte)
{
	void WS2812B_UDR(uint8_t byte)
	{
		while(!(UCSR0A & _BV(UDRE0)));  //Zaczekaj na miejsce w buforze
		UDR0 = byte;       //Umie�� w nim dane do wys�ania
	}
	
	uint8_t tmp=0x00;
	if(byte & 0x80) tmp=0b11100000; else tmp=0b10000000;
	if(byte & 0x40) tmp|=0b00001110; else tmp|=0b00001000;
	WS2812B_UDR(tmp);  //Wy�lij bity 7-6
	tmp=0x00;
	if(byte & 0x20) tmp=0b11100000; else tmp=0b10000000;
	if(byte & 0x10) tmp|=0b00001110; else tmp|=0b00001000;
	WS2812B_UDR(tmp);  //Wy�lij bity 5-4
	tmp=0x00;
	if(byte & 0x08) tmp=0b11100000; else tmp=0b10000000;
	if(byte & 0x04) tmp|=0b00001110; else tmp|=0b00001000;
	WS2812B_UDR(tmp);  //Wy�lij bity 3-2	
	tmp=0x00;
	if(byte & 0x02) tmp=0b11100000; else tmp=0b10000000;
	if(byte & 0x01) tmp|=0b00001110; else tmp|=0b00001000;
	WS2812B_UDR(tmp);  //Wy�lij bity 1-0	
}

int main(void)
{
	WS2812B_init();    //Zainicjuj interfejs

    while(1)
    {

/*	WS2812B_reset();   //Mamy zresetowany interfejs i SPI dostosowane do nadawania danych
	
	WS2812B_send(0);
	WS2812B_send(0);
	WS2812B_send(255);
	
	WS2812B_send(0);
	WS2812B_send(255);
	WS2812B_send(0);
	
	WS2812B_send(255);
	WS2812B_send(0);
	WS2812B_send(0);
*/
	uint8_t cnt=LEDNO;
	uint8_t offset=0;
	uint8_t delta=256/LEDNO;
	
	while(1)
	{
		WS2812B_reset();
		while(cnt--)
		{
			WS2812B_send(0);
			WS2812B_send(0);
			WS2812B_send(cnt*delta+offset);
		}
		offset+=delta;
		_delay_ms(10);
	}

    }
}