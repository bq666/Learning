/*
 * d_led.c
 *
 * Created: 2017-03-12 22:16:28
 *  Author: bq666
 */ 

#include <avr/io.h>			// do��czenie g��wnego pliku nag��wkowego
#include <avr/interrupt.h>	// do��czenie pliku naag��wkowego obs�ugi przerwa� 
#include "d_led.h"			// do��czenie naszego pliku nag��wkowego, w nim znajduj� si� potrzebne m.in. definicje preprocesora
#include <avr/pgmspace.h>	// do��czenie obs�ugi eeprom

/* definicje zmiennych globalnych przechowuj�cych cyfry do wy�wietlacza 
volatitle - poniewa� b�d� wykorzystywane do odczytu i zapisu zar�wno w przerwaniu, jak i w programie g��wnym.
Trzeba wi�c w��czy� optymalizacj� dost�pu do nich (zmienne ulotne) */

volatile uint8_t cy1;
volatile uint8_t cy2;
volatile uint8_t cy3;
volatile uint8_t cy4;


// -----------------------Definicja tablicy z cyframi do wy�wietlacza 7 seg. 
const uint8_t cyfry[15] PROGMEM = {								
	~ (SEG_A|SEG_B|SEG_C|SEG_D|SEG_E|SEG_F),		//0
	~ (SEG_B|SEG_C),								//1
	~ (SEG_A|SEG_B|SEG_D|SEG_E|SEG_G),				//2
	~ (SEG_A|SEG_B|SEG_C|SEG_D|SEG_G),				//3
	~ (SEG_B|SEG_C|SEG_F|SEG_G),					//4
	~ (SEG_A|SEG_C|SEG_D|SEG_F|SEG_G),				//5
	~ (SEG_A|SEG_C|SEG_D|SEG_E|SEG_F|SEG_G),		//6
	~ (SEG_A|SEG_B|SEG_C|SEG_F),					//7
	~ (SEG_A|SEG_B|SEG_C|SEG_D|SEG_E|SEG_F|SEG_G),	//8
	~ (SEG_A|SEG_B|SEG_C|SEG_D|SEG_F|SEG_G),		//9
};



// **** Definicja funkcji inicjalizuj�cej prac� z wy�wietlaczem multipleksowanym 
void d_led_init (void)
{
	LED_DATA_DIR = 0xFF;					// wszystkie piny portu A jako wyj�cia (katody)
	LED_DATA = 0xFF;						// wygaszenie wszystkich katod - stan wysoki 
	ANODY_DIR |= CA1 | CA2 | CA3 | CA4;		// 4 piny portu C jako wyj�cia (anody) 
	ANODY_PORT |= CA1 | CA2 | CA3 | CA4;	// wygaszenie wszystkich wy�wietlaczy (anody) 
	
	TCCR0 |= (1<<WGM01);					// Ustawienie TIMER0 w tryb CTC
	TCCR0 |= (1<<CS02);						// Ustawienie preskalera na 256
	OCR0=172;								// Ustawienie rejestru por�wnania na podzia� przez (11059200hz kwarcu/256 preskaler/250hz wy�wietlacza )-1=171,8
	TIMSK |= (1<<OCIE0);					// Zezwolenie na przerwanie Compare Match
	// TCCR0 &=~((1<<CS02)|(1<<CS01)|(1<<CS00)); // Zatrzymywanie preskalera
}
// ========================= PROCEDURA OBS�UGI PRZERWANIA - COMPARE MATCH 
ISR (TIMER0_COMP_vect)
{
	static uint8_t licznik=1;				// zmienna do prze��czania kolejno anod wy�wietacza 
	ANODY_PORT = (ANODY_PORT & 0xF0) | (~licznik & 0x0F);					// cykliczne prze��czanie w ka�dym przerwaniu anod ka�dego wy�wietlacza (warto�� negowana aby kr��y�o 0)
	
	if (licznik==1) LED_DATA = pgm_read_byte (&cyfry[cy1]);					// gdy zapalony wy�wietlacz 1 podaj stan zmiennej c1, 0001
	else if (licznik==2) LED_DATA = pgm_read_byte (&cyfry[cy2]);			// 2 = 0010   <---------------------
	else if (licznik==4) LED_DATA = pgm_read_byte (&cyfry[cy3]);			// 4 = 0100
	else if (licznik==8) LED_DATA = pgm_read_byte (&cyfry[cy4]);			// 8 = 1000
	licznik <<= 1;							// cykliczne przes�wanie warto�ci bit�w licznika o 1 w lewo 
	if (licznik>8) licznik=1;				// je�li licznik wi�kszy ni� 8 (1000) , to ustaw 1 (0001) 	
}
// 

