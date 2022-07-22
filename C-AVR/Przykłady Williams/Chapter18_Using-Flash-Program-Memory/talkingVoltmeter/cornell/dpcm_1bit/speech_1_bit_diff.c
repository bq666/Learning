//Przykład dekompresji głosu
#include <inttypes.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/pgmspace.h>
#include "USART.h"

#define TableSize 3280 //dotyczy poniższego pliku nagłówkowego
//Zawiera spakowane 1-bitowe dane dla syntezatora
#include "mega644_1_bit.h" 

//rakonstrukcyjne wartości różnicowe
//volatile signed char PCMvalue[4] = {-78, -16, 16, 78};
volatile signed char PCMvalue[2] = {-10, 10};

volatile unsigned int outI, tableI;     //indeksy
volatile unsigned char cycle ;  		//licznik dekodera fazy
volatile signed char out, lastout, newvalue;		//wartości wyjściowe
volatile unsigned char p1,p2,p3,p4,p5,p6,p7,p8;	//przechowują 8 wartości różnicowych
volatile unsigned char packed	;		//bajt przechowujący 4 wartości 2-bitowe
volatile uint8_t speaking;			/* znacznik określający, czy aktualnie odtwarzany jest dźwięk */

//generuje przebieg z częstością 7812 próbek/sekundę
ISR (TIMER2_COMPA_vect){ 
  //wylicz następną próbkę
  cycle = outI & 7;  // outI modulo 8
  if (cycle==0)      //musimy rozpakować więcej danych?
    {
      if (tableI<TableSize)  
        {
	  //rozpakuj wartość z tablicy do postawi 2-bitowych indeksów
	  // pgm_read_byte (address_short) 
	  packed = pgm_read_byte(&mega644[tableI]) ;
	  //packed = DPCMAllDigits[tableI];
	  p1 = (packed & 128) == 128 ;
	  p2 = (packed & 64) == 64 ;
	  p3 = (packed & 32) == 32 ;
	  p4 = (packed & 16) == 16 ; 
	  p5 = (packed & 8) == 8 ; 
	  p6 = (packed & 4) == 4 ; 
	  p7 = (packed & 2) == 2 ; 
	  p8 = (packed & 1) == 1 ; 
	  tableI++ ; 
        } //koniec rozpakowywania wartości z tablicy
      //wylicz wartość wujściową i wyślij ją do PWM
      newvalue = PCMvalue[p1] ;  	
    }
  else if (cycle==1)    //nie trzeba rozpakowywać, wystarczy wysłać na wyjście
    newvalue = PCMvalue[p2] ; 
  else if (cycle==2)
    newvalue = PCMvalue[p3] ; 
  else if (cycle==3) 
    newvalue = PCMvalue[p4] ; 
  else if (cycle==4) 
    newvalue = PCMvalue[p5] ; 
  else if (cycle==5) 
    newvalue = PCMvalue[p6] ; 
  else if (cycle==6) 
    newvalue = PCMvalue[p7] ; 
  else if (cycle==7) 
    newvalue = PCMvalue[p8] ; 
  
  out = lastout + newvalue - (lastout>>3);
  //zaktualizuj wyjścia
  OCR0A = out + 128;
  lastout = out;
  outI++;
  //na koniec wyłącz TCCRO
  if (tableI==TableSize) TCCR2B = 0;	  
} //ISR

int main(void){ 
  DDRD |= (1<<PD6); 
  DDRB |= (1<<PB0); 
  // Włącz pwm z okresem równym 256 cykli
  // (62,500 próbek/sek) w szybkim trybie PWM.
  // Jednak aktualizowanie OCR0A wykonywane jest przez licznik2 z częstością 7800/sek
  // licznik 0 działa z pełną szybkością ustaloną w pętli głównej; TCCR0B = 1 ;
  // włącz szybki tryb PWM oraz wyjście OC0A 
  // 16 mikrosekund na cykl PWM 
  TCCR0A = (1<<COM0A0) | (1<<COM0A1) | (1<<WGM00) | (1<<WGM01) ; 
  OCR0A = 128 ; // inicjowanie wyjścia PWM do połowy skali
  TCCR0B = (1<<CS00);	 /* pełna szybkość */
  // licznik2 ma się przepełniać z częstością 7812 Hz 
  // (podzielnik ustawiony na wartość 8)
  TCCR2A = (1<<WGM21);		/* CTC, zliczanie do OCR2A */
  OCR2A = 128;			/* ustal częstotliwość odtwarzania próbek */
  TCCR2B = (1<<CS21); 		/* źródło zegara / 8 = 1MHz */
  TIMSK2 = (1<<OCIE2A);   // włącz przerwanie porównania 

  sei();
  
  while(1) {  
    
    //inicjuj indeksy wyjściowe
    outI = 0; 
    tableI = 0; 
    //inicjuj wartość wyjściową
    lastout = 0; 
    // włącz PWM
    TCCR2B = (1<<CS21);
    //czekaj aż odtwarzanie się zakończy a potem
    //odczekach chwilę przed kolejnym odtworzeniem.
    while (TCCR2B>0){}; 
    OCR0A = 128 ;
    _delay_ms(500);
    PORTB ^= (1<<PB0); 
    
  } // end while  
}  //end main


