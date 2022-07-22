/*
 * LEDMUXDim.c
 *
 * Created: 2014-08-13 09:01:58
 *  Author: tmf
 */ 


#include <avr\io.h>
#include <avr/interrupt.h>
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

static inline void ShowOnLED(uint8_t val)
{
	uint8_t tmp=0xFF;
	if((val & 0x7F)<11) tmp=DIGITS[val & 0x7F];  //Odczytaj kod znaku
	if(val & DP) tmp&=~DP;      //Sterowanie kropk¹ dziesiêtn¹ na LED
	LEDPORT=tmp;
}


#define LEDDISPNO	4          //Liczba wyœwietlaczy

volatile uint8_t LEDDIGITS[LEDDISPNO];  //Tablica zawieraj¹ca dane do wyœwietlania

ISR(TIMER0_OVF_vect)
{
	static uint8_t LEDNO;

	PORTC|=0x0F;		//Wy³¹cz wszystkie wywietlacze
	LEDNO=(LEDNO+1)%LEDDISPNO;
	ShowOnLED(LEDDIGITS[LEDNO]);
	PORTC=(PORTC & 0xF0) | (~(1<<LEDNO) & 0x0F);	//Wybierz kolejny wywietlacz
}

/*ISR(TIMER0_COMPA_vect)
{
	PORTC|=0x0F;	//Wy³¹cz wszystkie wywietlacze
}*/

ISR(TIMER0_COMPA_vect, ISR_NAKED)
{
	PORTC|=0x01;	//Wy³¹cz wszystkie wywietlacze
	PORTC|=0x02;
	PORTC|=0x04;
	PORTC|=0x08;
	asm volatile("RETI\n\t"::);
}

void Timer0Init()
{
	TCCR0B=_BV(CS01);	//Preskaler CLKIO/8
	TIMSK0|=_BV(TOIE0);	//Odblokuj przerwanie nadmiaru timera 0
}

void Timer0InitWithDimmer()
{
	TIMSK0|=_BV(OCIE0A);		//W³¹cz przerwanie Compare Match A
	OCR0A=255;
	Timer0Init();
}

int main()
{
	LEDDDR=0xFF;		//Wszystkie piny portu s¹ wyjœciem
	DDRC|=0x0F;			//Piny PB0-PB3 jako wyjœcia

	Timer0InitWithDimmer();
	sei();

	LEDDIGITS[0]=1;
	LEDDIGITS[1]=2;
	LEDDIGITS[2]=3;
	LEDDIGITS[3]=4;
	
	while(1)
	{
	 OCR0A=200;
	 _delay_ms(1000);
	 OCR0A=100;
	 _delay_ms(1000);
	};
}