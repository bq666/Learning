/*
 * SPI.c
 *
 * Created: 2013-08-12 13:55:54
 *  Author: tmf
 */

#include "SPI.h"
#include <avr/io.h>

void SPI_init()
{
	DDRB=_BV(PB3) | _BV(PB5);      //Piny SCK i MOSI s¹ wyjœciami
	SPCR=_BV(SPE) | _BV(MSTR)  | _BV(CPOL) | _BV(CPHA);  //Tryb SPI3, taktowanie CLK/2
	//SPSR=_BV(SPI2X);        //Taktujemy interfejs dwukrotnie szybciej
}

void SPI_RW_Byte(uint8_t byte)
{
	SPDR=byte;                     //Wyœlij bajt danych
	while(!(SPSR & (1<<SPIF)));    //Zaczekaj a¿ bajt zostanie wys³any
	SPDR;                          //Odczytaj rejestr odbiornika dla wyzerowania SPIF
}
