/*
 * ST7565r_Intro.c
 *
 * Created: 2014-08-16 11:58:25
 *  Author: tmf
 */ 


#include <avr/io.h>
#include "defines.h"
#include "SPI/SPI.h"
#include "ST7565/ST7565.h"
#include <stdbool.h>

void LCD_BackLight_Init()
{
	DDRB|=_BV(PB1);             //Pin na którym jest PWM ustawiamy jako wyjœcie
	TCCR1A=_BV(COM1A1) | _BV(WGM11) | _BV(WGM10); //Wygeneruj PWM na pinie OC1A, tryb fastPWM 10-bitowy
	OCR1A=0x1ff;                     //50% wype³nienie
	TCCR1B=_BV(WGM12) | _BV(CS11);   //Preskaler 8, na wyjœciu otrzymamy ok. 2 kHz
}

void LCD_Init()
{
	SET(DDR, ST7565_RESET);   //Pin RESET
	SET(DDR, ST7565_A0);
	SET(DDR, ST7565_SCK);
	SET(DDR, ST7565_MOSI);
	SET(DDR, ST7565_CS);
	
	st7565r_init();           //Zainicjuj kontroler
}

#include <util/delay.h>

int main(void)
{
	SPI_init();
	LCD_Init();
	//LCD_BackLight_Init();  //W³¹cz podœwietlenie

	st7565r_Clear(false);

	for(uint8_t x=0; x<128; x++)
	{
		st7565r_SetPixel(x, 10, true);
		st7565r_SetPixel(x, 12, true);
		st7565r_SetPixel(x, 20, true);
		st7565r_SetPixel(x, 22, true);
	}

	GLCD_x=0; GLCD_y=0;
	st7565r_LineTo(127, 31, true);
	GLCD_x=0; GLCD_y=31;
	st7565r_LineTo(127, 0, true);
	st7565r_Circle(30, 16, 10, 3);
	while(1);

}