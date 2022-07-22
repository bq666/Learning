#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include "multi.h"

#define GLUE(a, b)     a##b

#define LEDPORT1(s)	GLUE(PORT,s)
#define LEDPORT LEDPORT1(LED)
#define LEDDDR1(s)	GLUE(DDR,s)
#define LEDDDR	LEDDDR1(LED)

//W poni¿szych definicjach zmienione zosta³y wartoœci ze wzglêdu na pod³¹czenie segmentu G wyœwietlacza do PB7, zamiast PB6!
//Cyfry 0,1,2,3,4,5,6,7,8,9 i symbol -
static const uint8_t __flash DIGITS[11]={0xC0, 0xF9, 0x64, 0x70, 0x59, 0x52, 0x42, 0xF8, 0x40, 0x50, 0x7F};

static inline void ShowOnLED(uint8_t val)
{
	uint8_t tmp=0xFF;
	if((val & 0x7F)<11) tmp=DIGITS[val & 0x7F];
	LEDPORT=tmp;
}

volatile uint8_t LEDDIGITS[LEDDISPNO];

ISR(TIMER0_OVF_vect)
{
	static uint8_t LEDNO;

	PORTC|=0x0F;		//Wy³¹cz wszystkie wyœwietlacze
	LEDNO=(LEDNO+1)%LEDDISPNO;
	ShowOnLED(LEDDIGITS[LEDNO]);
	PORTC=(PORTC & 0xF0) | (~(1<<LEDNO) & 0x0F);	//Wybierz kolejny wyœwietlacz
}

void Timer0Init()
{
    LEDDDR=0xFF;		//Wszystkie piny portu s¹ wyjœciem
	DDRC|=0x0F;         //Piny steruj¹ce cyframi jako wyjœcie
	TCCR0B=_BV(CS01);	//Preskaler CLKIO/8
	TIMSK0|=_BV(TOIE0);	//Odblokuj przerwanie nadmiaru timera 0
}
