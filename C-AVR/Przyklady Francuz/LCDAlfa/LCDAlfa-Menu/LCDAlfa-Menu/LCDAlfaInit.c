/*
 * LCDAlfa_Menu.c
 *
 * Created: 2014-08-15 11:03:19
 *  Author: tmf
 */ 


#include <avr/interrupt.h>
#include <util/delay.h>
#include "menu.h"
#include "LCD.h"
#include "encoder.h"

int main()
{
	EncoderInit();
	lcd_init();
	//Timer0Init();  //Jeœli wykorzystujemy przerwania do obs³ugi enkodera
	Menu_Show();
	sei();

 int8_t enc;
 _Bool btn=false;
 while(1)
 {
  enc=Read4StepEncoder();
  if(enc>0)
   {
    Menu_SelectPrev();
	enc++;
   }
  if(enc<0)
   {
    Menu_SelectNext();
	enc--;
   }
  if(GetEncButton()^btn)
   {
    btn=GetEncButton();
	if(btn) Menu_Click();
   }
 }
}


