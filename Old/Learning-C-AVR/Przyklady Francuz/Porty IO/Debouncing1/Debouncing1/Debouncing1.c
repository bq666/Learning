/*
 * Debouncing1.c
 *
 * Created: 2014-08-12 15:04:20
 *  Author: tmf
 */ 


#include <avr\io.h>
#include <util\delay.h>

#define LED	D

#define GLUE(a, b)     a##b

#define LEDPORT1(s)	GLUE(PORT,s)
#define LEDPORT LEDPORT1(LED)
#define LEDDDR1(s)	GLUE(DDR,s)
#define LEDDDR	LEDDDR1(LED)

//Cyfry 0,1,2,3,4,5,6,7,8,9 i symbol -
static const uint8_t __flash DIGITS[11]={0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90, 0xBF};
const uint8_t DP=0x80;

void ShowOnLED(uint8_t val)
{
	uint8_t tmp=0xFF;
	if((val & 0x7F)<11) tmp=DIGITS[val & 0x7F];  //Odczytaj kod znaku
	if(val & DP) tmp&=~DP;      //Sterowanie kropk¹ dziesiêtn¹ na LED
	LEDPORT=tmp;
}

int main()
{
	LEDDDR=0xFF;		//Wszystkie piny portu s¹ wyjœciem
	PORTB|=_BV(PB7);	//W³¹cz pull up na pinie PB7
	uint8_t oldkey=PINB & _BV(PB7);
	uint8_t key;
	uint8_t x=0;
	uint8_t counter=0;
	while(1)
	{
		ShowOnLED(x);
		if(counter==0)
		{
			key=PINB & _BV(PB7);		//Odczytaj stan klawisza
			if((key^oldkey) && (key==0))
			{
				x=(x+1)%2;		//Jeœli siê zmieni³ i jest wciœniêty to zmieñ x
				counter=200;	//Czas przez jaki stan przycisku bêdzie ignorowany
			}
			oldkey=key;
		} else
		{
			_delay_ms(1);
			counter--;
		}
	}
}