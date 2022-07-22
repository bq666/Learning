/*
 * PUADP.c
 *
 * Created: 2017-03-19 12:05:50
 * Author : bq666
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include <avr/power.h>

#define szybkosc	100
#define LED_DDR		DDRC
#define LED_PORT	PORTC
#define LED_PIN		PINC

int main(void)
{
	int8_t i;
	uint8_t powtarzanie;
	uint8_t ktoryLED;
	uint16_t losowa = 0x1234;
	
		
	LED_DDR = 0xFF;	
	
	
    while (1) 
    {
		LED_PORT = 0xFF;
		
		
		for (i = 0; i < 8; i++)					// zaœwicaj¹ siê z prawej do lewej 
		{
			LED_PORT = LED_PORT & ~(1<<i);
			_delay_ms (szybkosc);
		}
		
		
		for (i = 0; i < 8; i++)					// gasn¹ z prawej do lewej 
		{
			LED_PORT = LED_PORT | (1<<i);
			_delay_ms (szybkosc);
		}
		
		
		for (i = 7; i >= 0; i--)				// zaœwiecaj¹ z lewej do prawej 
		{
			LED_PORT = LED_PORT & ~(1<<i);
			_delay_ms (szybkosc);
		}
		
		
		for (i = 7; i >= 0; i--)
		{
			LED_PORT = LED_PORT | (1<<i);
			_delay_ms (szybkosc);
		}
		
		
		for (powtarzanie = 0; powtarzanie < 75; powtarzanie++)			// generator pseudolosowy 
		{
			losowa = 2053 * losowa + 13849;
			ktoryLED = (losowa >> 8) & 0b00000111;
			LED_PORT ^= (1<<ktoryLED);
			_delay_ms(szybkosc);
		}
		LED_PORT=0xFF;
		_delay_ms(5*szybkosc);
		
		
		
	/*	while (i>=0)
		{
			LED_PORT = LED_PORT | (1<<i);
			_delay_ms(szybkosc);
			i = i - 1;
		}	*/

	}  
	
return(0);
/*	-----------Serce-----------
	
		wzor (~0b11111111);
		wzor (~0b11111111);
		wzor (~0b11111111);
		wzor (~0b11111111);
		wzor (~0b11111111);
		wzor (~0b11111111);		
		wzor (~0b00110000);
		wzor (~0b01001100);
		wzor (~0b10000010);
		wzor (~0b10000001);
		wzor (~0b01100001);
		wzor (~0b01100001);
		wzor (~0b10000001);
		wzor (~0b10000010);
		wzor (~0b01001100);
		wzor (~0b00110000);
		wzor (~0b11111111);
		wzor (~0b11111111);
		wzor (~0b11111111);
		wzor (~0b11111111);
		wzor (~0b11111111);
		wzor (~0b11111111);		*/
}