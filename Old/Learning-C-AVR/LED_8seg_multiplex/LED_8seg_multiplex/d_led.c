/*
 * d_led.c
 *
 * Created: 2017-03-12 22:16:28
 *  Author: bq666
 */ 

#include <avr/io.h>			// do³¹czenie g³ównego pliku nag³ówkowego
#include <avr/interrupt.h>	// do³¹czenie pliku naag³ówkowego obs³ugi przerwañ 
#include "d_led.h"			// do³¹czenie naszego pliku nag³ówkowego, w nim znajduj¹ siê potrzebne m.in. definicje preprocesora
#include <avr/pgmspace.h>	// do³¹czenie obs³ugi eeprom

/* definicje zmiennych globalnych przechowuj¹cych cyfry do wyœwietlacza 
volatitle - poniewa¿ bêd¹ wykorzystywane do odczytu i zapisu zarówno w przerwaniu, jak i w programie g³ównym.
Trzeba wiêc w³¹czyæ optymalizacjê dostêpu do nich (zmienne ulotne) */

volatile uint8_t cy1;
volatile uint8_t cy2;
volatile uint8_t cy3;
volatile uint8_t cy4;


// -----------------------Definicja tablicy z cyframi do wyœwietlacza 7 seg. 
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



// **** Definicja funkcji inicjalizuj¹cej pracê z wyœwietlaczem multipleksowanym 
void d_led_init (void)
{
	LED_DATA_DIR = 0xFF;					// wszystkie piny portu A jako wyjœcia (katody)
	LED_DATA = 0xFF;						// wygaszenie wszystkich katod - stan wysoki 
	ANODY_DIR |= CA1 | CA2 | CA3 | CA4;		// 4 piny portu C jako wyjœcia (anody) 
	ANODY_PORT |= CA1 | CA2 | CA3 | CA4;	// wygaszenie wszystkich wyœwietlaczy (anody) 
	
	TCCR0 |= (1<<WGM01);					// Ustawienie TIMER0 w tryb CTC
	TCCR0 |= (1<<CS02);						// Ustawienie preskalera na 256
	OCR0=172;								// Ustawienie rejestru porównania na podzia³ przez (11059200hz kwarcu/256 preskaler/250hz wyœwietlacza )-1=171,8
	TIMSK |= (1<<OCIE0);					// Zezwolenie na przerwanie Compare Match
	// TCCR0 &=~((1<<CS02)|(1<<CS01)|(1<<CS00)); // Zatrzymywanie preskalera
}
// ========================= PROCEDURA OBS£UGI PRZERWANIA - COMPARE MATCH 
ISR (TIMER0_COMP_vect)
{
	static uint8_t licznik=1;				// zmienna do prze³¹czania kolejno anod wyœwietacza 
	ANODY_PORT = (ANODY_PORT & 0xF0) | (~licznik & 0x0F);					// cykliczne prze³¹czanie w ka¿dym przerwaniu anod ka¿dego wyœwietlacza (wartoœæ negowana aby kr¹¿y³o 0)
	
	if (licznik==1) LED_DATA = pgm_read_byte (&cyfry[cy1]);					// gdy zapalony wyœwietlacz 1 podaj stan zmiennej c1, 0001
	else if (licznik==2) LED_DATA = pgm_read_byte (&cyfry[cy2]);			// 2 = 0010   <---------------------
	else if (licznik==4) LED_DATA = pgm_read_byte (&cyfry[cy3]);			// 4 = 0100
	else if (licznik==8) LED_DATA = pgm_read_byte (&cyfry[cy4]);			// 8 = 1000
	licznik <<= 1;							// cykliczne przesówanie wartoœci bitów licznika o 1 w lewo 
	if (licznik>8) licznik=1;				// jeœli licznik wiêkszy ni¿ 8 (1000) , to ustaw 1 (0001) 	
}
// 

