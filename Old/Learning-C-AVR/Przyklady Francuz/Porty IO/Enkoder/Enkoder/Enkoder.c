/*
 * Enkoder.c
 *
 * Created: 2014-08-12 15:22:20
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

int8_t enc_delta;

void ReadEncoder()
{
	static int8_t last;
	int8_t newpos, diff;

	newpos=0;
	if((PINB & _BV(PB0))==0) newpos=3;
	if((PINB & _BV(PB7))==0) newpos^=1;  // konwersja kodu Graya na binarny
	diff=last-newpos;
	if(diff & 1)
	{                              // bit 0 = krok
		last=newpos;
		enc_delta+=(diff & 2)-1;      //bit 1 - kierunek
	}
}

int8_t Read1StepEncoder()
{
	ReadEncoder();
	int8_t val=enc_delta;
	enc_delta=0;
	return val;
}

int8_t Read2StepEncoder()
{
	ReadEncoder();
	int8_t val=enc_delta;
	enc_delta=val & 1;
	return val>>1;
}

int8_t Read4StepEncoder()
{
	ReadEncoder();
	int8_t val=enc_delta;
	enc_delta=val & 3;
	return val>>2;
}

int main()
{
	LEDDDR=0xFF;		//Wszystkie piny portu s¹ wyjœciem
	PORTB|=_BV(PB0) | _BV(PB7);	//W³¹cz pull up na pinie PB0 i PB7
	uint8_t x=0;


	while(1)
	{
		ShowOnLED(x);
		switch(Read4StepEncoder())
		{
			case -1 :	if(x>0) x-=1; break;
			case 0  :	break;
			case 1  :	if(x<9) x+=1; break;
		};
	}
}
