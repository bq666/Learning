/*
 * Drugi program Francuz.c
 *
 * Created: 2017-03-17 17:27:05
 * Author : bq666
 */ 


#include <avr\io.h>
#include <util\delay.h>

#define LED	A

#define GLUE(a, b)     a##b

#define LEDPORT1(s)	GLUE(PORT,s)
#define LEDPORT LEDPORT1(LED)
#define LEDDDR1(s)	GLUE(DDR,s)
#define LEDDDR	LEDDDR1(LED)

//Cyfry 0,1,2,3,4,5,6,7,8,9 i symbol -
static const uint8_t __flash DIGITS[11]={0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90, 0xBF};
const uint8_t DP=0x80;
uint8_t counters[2];

void ShowOnLED(uint8_t val)
{
	uint8_t tmp=0xFF;
	if((val & 0x7F)<11) tmp=DIGITS[val & 0x7F];  //Odczytaj kod znaku
	if(val & DP) tmp&=~DP;      //Sterowanie kropk¹ dziesiêtn¹ na LED
	LEDPORT=tmp;
}

int main()
{
	LEDDDR=0xFF;				//Wszystkie piny portu s¹ wyjœciem
	PORTD|=((1<<PD0)|(1<<PD1));	//W³¹cz pull upy na pinach PB0 i PB7
	DDRC|=(1<<PC3);
	PORTC|=(0<<PC3);
	uint8_t x=5;
	
	uint8_t oldkey=PIND & ((1<<PD0)|(1<<PD1));
	uint8_t key;
	counters[0]=0;
	counters[1]=0;
		
	while(1)
	{
		ShowOnLED(x);
		if (counters[0]==0)
		{
			key=PIND & (1<<PD0);		//odczytuje stan klawisza
			if((key^oldkey) && (key==0))
			{
				x--;
				counters[0]=150;
			}
			oldkey=key;
		} else
		{
			_delay_ms(1);
			counters[0]--;
		}
		
			if (counters[1]==0)
			{
				key=PIND & (1<<PD1);		//odczytuje stan klawisza
				if((key^oldkey) && (key==0))
				{
					x++;
					counters[1]=150;
				}
				oldkey=key;
			} else
			{
				_delay_ms(1);
				counters[1]--;
			}
		
		
		/*if((PIND & (1<<PD0))==0) {x--; _delay_ms(80);}
		if((PIND & (1<<PD1))==0) {x++; _delay_ms(80);} */
		//x=x%10;
		//_delay_ms(100);
	}
}
