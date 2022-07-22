/*
 * Pierwszy program Francuz.c
 *
 * Created: 2017-03-17 14:26:23
 * Author : bq666
 */ 

#include <avr/io.h>
#include <util/delay.h>

#define LED A
#define GLUE(a,b) a##b
#define LEDPORT1(s) GLUE(PORT,s)
#define LEDPORT LEDPORT1(LED)
#define LEDDDR1(s) GLUE(DDR,s)
#define LEDDDR LEDDDR1(LED)


static const uint8_t  __flash DIGITS[11]={0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90, 0xBF};	// definicje cyfr 1.2....9 i symbol -
const uint8_t DP=0x80;																							// definicja kropki


void ShowOnLed(uint8_t val)
{
	uint8_t tmp=0xFF;
	if ((val & 0x7f)<11) tmp=DIGITS[val&0x7F];				// odczytaj kod znaku
	if (val & DP) tmp&=~DP;
	LEDPORT=tmp;
	
}




int main(void)
{
    /* Replace with your application code */
	DDRC=0xFF;
	PORTC=0b11111111;
	PORTC=PORTC&(~(1<<PC3));
	LEDDDR=0xFF;			// wszystkie piny s¹ wyjœciami 
	uint8_t x=0;
    while (1) 
    {
		ShowOnLed(x);
		x=(x+1)%12;
		_delay_ms(1000);
    }
}

