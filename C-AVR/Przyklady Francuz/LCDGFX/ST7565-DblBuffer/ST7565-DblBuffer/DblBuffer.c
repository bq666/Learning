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
#include <avr/pgmspace.h>
#include <util/delay.h>

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

extern const __flash uint8_t* const __flash system16_array[];
extern const __flash uint8_t* const __flash system12_array[];
extern const __flash uint8_t* const __flash system8_array[];


int main(void)
{
	SPI_init();
	LCD_Init();
	//LCD_BackLight_Init();  //W³¹cz podœwietlenie

	st7565r_Clear(false);

	st7565r_SetText(0, 8, PSTR("Bufor 1"), system16_array);
	st7565r_CpyToPage(0);
	st7565r_SetText(0, 8, PSTR("Bufor 2"), system16_array);
	st7565r_CpyToPage(4);
	while(1)
	{
		_delay_ms(1000);
		st7565r_set_display_start_line_address(32);
		_delay_ms(1000);
		st7565r_set_display_start_line_address(0);
	}
}