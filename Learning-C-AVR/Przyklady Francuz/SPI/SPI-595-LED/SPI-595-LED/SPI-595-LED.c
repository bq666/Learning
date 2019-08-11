/*
 * SPI_595_LED.c
 *
 * Created: 2014-08-18 20:44:20
 *  Author: tmf
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr\pgmspace.h>
#include <util/delay.h>

#define LEDDISPNO	4

volatile uint8_t LEDDIGITS[LEDDISPNO];

//Cyfry 0,1,2,3,4,5,6,7,8,9 i symbol -
static const uint8_t __flash DIGITS[11]={0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90, 0xBF};
const uint8_t DP=0x80;

struct ISR_Status
{
	uint8_t no : 4;
	uint8_t byte : 1;
};

static inline void SPI_Set_SS()
{
	PORTB|=_BV(PB2);
}

static inline void SPI_Reset_SS()
{
	PORTB&=~(_BV(PB2));
}

ISR(SPI_STC_vect)
{
	static struct ISR_Status status;

	if(status.byte==0)
	{
		SPI_Set_SS();          //Przepisz zawartoœæ rejestru do zatrzasków wyjœciowych
		asm volatile ("nop");  //Konieczne ze wzglêdu na synchronizator
		SPI_Reset_SS();        //Wsuwamy now¹ wartoœæ
		uint8_t tmp=0xFF;
		uint8_t val=LEDDIGITS[status.no];  //Cyfra do wyœwietlenia
		if((val & 0x7F)<11) tmp=DIGITS[val & 0x7F]; //Jej reprezentacja na LED
		if(val & DP) tmp&=~(DP); //Kropka dziesiêtna
		SPDR=tmp;  //Wyœlij dane o wyœwietlanej cyfrze
	}
	else
	{
		SPDR=~(1<<status.no);	//Wybierz wyœwietlacz
		status.no=(status.no+1)%LEDDISPNO;
	}
	status.byte^=1;
}

void SPI_master_init()
{
	SPI_Set_SS();
	DDRB|=(_BV(PB2) | _BV(PB3) | _BV(PB5));	//Piny SS, MOSI, SCK jako wyjœcie
	SPCR=_BV(SPIE) | _BV(SPE) | _BV(MSTR); //Tryb master, CLK/128, przerwania
	SPCR|=_BV(SPR1) | _BV(SPR0);
	SPSR;
	SPDR; //Skasuj flagê SPIF
}

int main()
{
	SPI_master_init();

	sei();

	LEDDIGITS[0]=1;
	LEDDIGITS[1]=2;
	LEDDIGITS[2]=3;
	LEDDIGITS[3]=4;

	SPDR=0; //Zainicjuj przerwania SPI

	while(1);
}
