/*
 * Debouncing2.c
 *
 * Created: 2014-08-12 15:11:23
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
	if(val & DP) tmp&=~DP;      //Sterowanie kropk� dziesi�tn� na LED
	LEDPORT=tmp;
}

uint8_t counters[2];	//Tablica zawieraj�ca liczniki

int main()
{
	LEDDDR=0xFF;		//Wszystkie piny portu s� wyj�ciem
	PORTB|=_BV(PB0) | _BV(PB7);	//W��cz pull up na pinie PB0 i PB7
	uint8_t oldkey=PINB & (_BV(PB0) | _BV(PB7));
	uint8_t key;
	uint8_t x=0;
	uint8_t przerwa;

	while(1)
	{
		ShowOnLED(x);
		if(counters[0]==0)
		{
			key=PINB & _BV(PB0);		//Odczytaj stan klawisza
			if(((key^oldkey) & _BV(PB0)) && ((key & _BV(PB0))==0))
			{
				if(x>0) x--;		//Je�li si� zmieni� i jest wci�ni�ty to zmie� x
				counters[0]=200;	//Czas przez jaki stan przycisku b�dzie ignorowany
			}
			oldkey&=~_BV(PB0);
			oldkey|=key;
		}

		if(counters[1]==0)
		{
			key=PINB & _BV(PB7);		//Odczytaj stan klawisza
			if(((key^oldkey) & _BV(PB7)) && ((key & _BV(PB7))==0))
			{
				if(x<9) x++;		//Je�li si� zmieni� i jest wci�ni�ty to zmie� x
				counters[1]=200;	//Czas przez jaki stan przycisku b�dzie ignorowany
			}
			oldkey&=~_BV(PB7);
			oldkey|=key;
		}

		przerwa=0;
		for(uint8_t c=0;c<2;c++)
		if(counters[c])
		{
			counters[c]--;
			przerwa=1;			//Robimy op�nienie tylko je�li kt�ry� z licznik�w by� !=0
		}
		if(przerwa) _delay_ms(1);
	}
}
