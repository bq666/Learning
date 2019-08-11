//  Gadający woltomierz

#include <inttypes.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/pgmspace.h>
#include "pinDefines.h"

#include "DPCM_rich_hello_world_8000.h"
#define TABLE_NAME  DPCM_rich_hello_world_8000

volatile uint16_t sampleNumber;         // indeks próbki
volatile int8_t   out, lastout;		// wartości wyjścia
volatile uint8_t  p1, p2, p3, p4;	// przechowuje 4 wartości różnicowe
const int8_t      PCMvalue[4] = {-20, -4, 4, 20};

ISR (TIMER2_COMPA_vect){ 
  /* Licznik 2 steruje szybkością próbkowania -- 
     przerwanie odczytuje nowe dane, ładuje wartość PWM do OCR0A */
  /* Skoro w jednym cyklu możemy zdekodować 4 wartości 2-bitowe, to musimy wiedzieć
     w którym miejscu tego 4-krokowego cyklu się znajdujemy. */
  uint8_t cycle = sampleNumber & 0b00000011; 	/* 4 kroki */
  uint16_t tableEntry = sampleNumber >> 2;	/* 4 kroki na każdy bajt z tabeli */
  uint8_t  packedData;				/* nowy bajt */
  switch(cycle){
  case 0:  // Początek cyklu, rozpakuj następny bajt z próbkami
    if (tableEntry < sizeof(TABLE_NAME)){  
      packedData = pgm_read_byte(&TABLE_NAME[tableEntry]) ;
      p1 = (packedData>>6) & 3 ;
      p2 = (packedData>>4) & 3 ;
      p3 = (packedData>>2) & 3 ;
      p4 = (packedData & 3); 
    }
    /* Dodaj kolejną wartość różnicową PCM  */
    out = lastout + PCMvalue[p1] - (lastout>>3) ;  	
    break;
  case 1:
    out = lastout + PCMvalue[p2] - (lastout>>3) ;
    break;
  case 2:
    out = lastout + PCMvalue[p3] - (lastout>>3) ; 
    break;
  case 3:
    out = lastout + PCMvalue[p4] - (lastout>>3) ;
    break;
  }
  /* Aktualizuj wartość wyjścia PWM */
  OCR0A = out + 128;		/* wyśrodkuj w zakresie 0-255 */
  lastout = out;		/* aktualizuj ostatnią wartość */
  sampleNumber++;		/* przejdź do następnej próbki */
  
  /* po zakończeniu wyłącz PWM w liczniku 0 */
  if (sampleNumber == 4*sizeof(TABLE_NAME)-1) {
    TCCR2B = 0;			/* wyłącz zegar odtwarzania próbek */
    OCR0A = 128;	       	/* ustal wartość w połowie zakresu */
    lastout = 0;		/* następnym razem zacznij od 0 */
  }
} // koniec przerwania

void initTimer0(void){
  // Konfigurowanie licznika 0 do działania w wolnym trybie PWM 
  TCCR0A |= (1<<WGM00) | (1<<WGM01); /* Szybki tryb PWM */
  TCCR0A |= (1<<COM0A0) | (1<<COM0A1); /* wyjście na PD6/OC0A */
  TCCR0B = (1<<CS00);		       /* najszybszy zegar */
  OCR0A = 128 ;			       /* inicjowanie wartości środkowej */
  SPEAKER_DDR |= (1<<SPEAKER);	       /* wyjście PD6 / OC0A */
}

void initTimer2(void){
  // Licznik 2 ładuje rejestr OCR0A, definiuje częstotliwość próbkowania
  // Staramy się uzyskać 8kHz
  TCCR2A = (1<<WGM21);	      /* tryb CTC, zliczaj do OCR2A */
  OCR2A = 128;		      /* steruje częstotliwością odtwarzania próbek */
  TCCR2B = (1<<CS21);	      /* źródło zegara / 8 = 1MHz */
  TIMSK2 = (1<<OCIE2A);	      /* włącz przerwanie porównania */
  sei();
}

void initADC(void){
  // Konwerter AC dla woltomierza
  ADMUX  |= (0b00001111 & PC5);  /* ustaw multiplekser na ADC5 */
  DIDR0 |= _BV(ADC5D);		 /* wyłącz układy cefrowe wokół pinu PC5 */
  ADMUX  |= (1 << REFS0);        /* napęcie referencyjne to AVCC, 5V */
  ADCSRA |= (1 << ADPS1) | (1 << ADPS2); /* podzielnik zegara konwertera /64 */
  ADCSRA |= (1 << ADEN);        /* włącz konwerter AC */
}

int main(void){ 
  uint8_t adcValue;
  
  initTimer0();
  initTimer2();
  initADC();

  while(1) {  
    sampleNumber = 0;		/* przejdź na początek tablicy próbek */
    TCCR2B = (1<<CS21);		/* zacznij ładować próbki */
    
    /* Poczekaj na koniec odtwarzania i poczekaj jeszcze chwilę. */
    loop_until_bit_is_clear(TCCR2B, CS21);
    _delay_ms(1000);
    
  } /*  koniec pętli */
  return(0);
}  



