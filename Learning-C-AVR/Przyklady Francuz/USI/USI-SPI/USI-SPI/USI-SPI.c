/*
 * USI_SPI.c
 *
 * Created: 2014-08-17 14:27:56
 *  Author: tmf
 */ 


/*
 * GccApplication1.c
 *
 * Created: 2014-08-17 14:23:56
 *  Author: tmf
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define GLUE(a, b)     a##b

/* single-bit macros, used for control bits */
#define SET_(what, p, m) GLUE(what, p) |= (1 << (m))
#define CLR_(what, p, m) GLUE(what, p) &= ~(1 << (m))
#define GET_(/* PIN, */ p, m) GLUE(PIN, p) & (1 << (m))
#define SET(what, x) SET_(what, x)
#define CLR(what, x) CLR_(what, x)

#define SPI_SS      A, 0
#define SPI_CLK     B, 2
#define SPI_DI      B, 0
#define SPI_DO      B, 1

void USI_SPI_master_init()
{
	SET(DDR, SPI_DO);
	SET(DDR, SPI_CLK); //Piny DO i CLK maj¹ byæ wyjœciami
}

uint8_t USI_SPI_Transmit(uint8_t data)
{
	USIDR=data;
	USISR=_BV(USIOIF); //Wyzeruj licznik
	do
	{
		USICR=_BV(USIWM0) | _BV(USICS1) | _BV(USICLK) | _BV(USITC);
	} while((USISR & _BV(USIOIF))==0);
	return USIDR;
}

void USI_SPI_slave_init()
{
	SET(DDR, SPI_DO);
	CLR(DDR, SPI_DI);
	CLR(DDR, SPI_CLK);
	CLR(DDR, SPI_SS);
	USICR=_BV(USIOIE) | _BV(USIWM0) | _BV(USICS0) | _BV(USICS1);
	USISR=_BV(USIOIF); //Skasuj flagê nadmiaru
	sei();
}

volatile uint8_t dane_in, dane_out;
volatile uint8_t flaga;

ISR(USI_OVF_vect)
{
	dane_in=USIDR;
	USISR=_BV(USIOIF);
	USIDR=dane_out;
	flaga=255;
}

int main()
{
	uint8_t x=0;
	SET(PORT, SPI_SS);
	SET(DDR, SPI_SS);; //Skonfiguruj pin wykorzystywany jako SS
	USI_SPI_master_init();
	while(1)
	{
		_delay_ms(1000);

		CLR(PORT, SPI_SS);; //Uaktywnij pin SS urz¹dzenia slave
		USI_SPI_Transmit(x);
		SET(PORT, SPI_SS);
		x^=0xFF;
	};
}
