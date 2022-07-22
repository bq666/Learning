#include <avr\io.h>
#include <avr\pgmspace.h>
#include <avr\interrupt.h>
#include <stdlib.h>
#include "encoder.h"
#include "../defines.h"

static int8_t enc_delta;
static uint8_t laststate;

static inline void ReadEncoder();

ISR(TIMER0_OVF_vect)
{
	ReadEncoder();
}

void Timer0Init()
{
	TCCR0B=_BV(CS01);	//Preskaler CLKIO/8
	TIMSK0|=_BV(TOIE0);	//Odblokuj przerwanie nadmiaru timera 0
}

bool GetEncButton()
{
	if(laststate & BITPOS(ENCODER_BTN)) return false; else return true;
}

void ReadEncoder()
{
	static int8_t last;
	static uint8_t counters[3];	//Tablica zawieraj¹ca liczniki
	int8_t newpos, diff;
	
	uint8_t state=ENCODER_PIN;
	if(((state^laststate) & BITPOS(ENCODER_A)) && (counters[0]==0))
	{
		counters[0]=200;
		laststate&=(~BITPOS(ENCODER_A));
		laststate|=(state & BITPOS(ENCODER_A));
	}

	if(((state^laststate) & BITPOS(ENCODER_B)) && (counters[1]==0))
	{
		counters[1]=200;
		laststate&=(BITPOS(ENCODER_B));
		laststate|=(state & BITPOS(ENCODER_B));
	}

	if(((state^laststate) & BITPOS(ENCODER_BTN)) && (counters[2]==0))
	{
		counters[2]=200;
		laststate&=(~BITPOS(ENCODER_BTN));
		laststate|=(state & BITPOS(ENCODER_BTN));
	}

	for(uint8_t c=0;c<sizeof(counters)/sizeof(counters[0]);c++)		
		if(counters[c])	counters[c]--;

	newpos=0;
	if((state & BITPOS(ENCODER_A))==0) newpos=3;
	if((state & BITPOS(ENCODER_B))==0) newpos^=1;	// konwersja kodu Graya na binarny
	diff=last-newpos;
	if(diff & 1)
	{				// bit 0 = krok
    	last=newpos;
		enc_delta+=(diff & 2)-1;	//bit 1 - kierunek
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

void EncoderInit()
{	//Wyjœcia A i B enkodera pod³¹czone s¹ do PD5-7
	SET(PORT, ENCODER_A);
	SET(PORT, ENCODER_B);
	SET(PORT, ENCODER_BTN);
}

