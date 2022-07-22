/* Plik naglówkowy z danymi DPCM */
#include "allDigits.h"
#include <avr/pgmspace.h>

// Teraz definiujemy tabelę próbej używaną w pliku z cyframi
// Dzięki temu, niezależnie od tego jak nazwiesz te próbki,
//   możesz się do nich odwoływać poprzez nazwy "ONE_TABLE", itd.
#define ONE_TABLE    DPCM_one_8000
#define TWO_TABLE    DPCM_two_8000
#define THREE_TABLE  DPCM_three_8000
#define FOUR_TABLE   DPCM_four_8000
#define FIVE_TABLE   DPCM_five_8000
#define SIX_TABLE    DPCM_six_8000
#define SEVEN_TABLE  DPCM_seven_8000
#define EIGHT_TABLE  DPCM_eight_8000
#define NINE_TABLE   DPCM_nine_8000
#define ZERO_TABLE   DPCM_zero_8000
#define POINT_TABLE  DPCM_point_8000
#define VOLTS_TABLE  DPCM_volts_8000
#define INTRO_TABLE  DPCM_talkingvoltmeter_8000

#define SPEECH_DELAY   2000   /* milisekundy */

/* --------- Zmienne globalne używane przez przerwanie -------------- */
volatile uint8_t* thisTableP; /* wskazuje aktualną tablicę z próbkami */
volatile uint16_t thisTableLength; /* długość aktualnej tablicy z próbkami */

volatile uint16_t sampleNumber;         // indeks próbki
volatile int8_t   out, lastout;		// wartości wyjścia
volatile uint8_t  differentials[4] = {0,0,0,0};	 
const    int8_t   dpcmWeights[4]   = {-12, -3, 3, 12};


/* Te tablice pozwalają na numeryczne wybieranie tabeli (i jej długości) */
const uint16_t tableLengths[]  = {	/* wszystkie próbki w tabeli są 8-bitowe */
  sizeof(ZERO_TABLE), sizeof(ONE_TABLE), sizeof(TWO_TABLE), 
  sizeof(THREE_TABLE), sizeof(FOUR_TABLE), sizeof(FIVE_TABLE),
  sizeof(SIX_TABLE), sizeof(SEVEN_TABLE), sizeof(EIGHT_TABLE), 
  sizeof(NINE_TABLE), sizeof(POINT_TABLE), sizeof(VOLTS_TABLE), 
  sizeof(INTRO_TABLE)
};

// Tworzenie tabeli indeksującej adresy początkowe wszystkich
// wymawianych cyfr.  Wartości te zapisujemy w pamięci programu.
const uint8_t* const tablePointers[] PROGMEM = { 
  ZERO_TABLE, ONE_TABLE, TWO_TABLE, THREE_TABLE, FOUR_TABLE, 
  FIVE_TABLE, SIX_TABLE, SEVEN_TABLE, EIGHT_TABLE, NINE_TABLE, 
  POINT_TABLE, VOLTS_TABLE, INTRO_TABLE
};

void selectTable(uint8_t whichTable){
  /* Konfiguracja globalnego wskaźnika tabeli i jej długości */
  uint16_t pointerAddress;
  thisTableLength = tableLengths[whichTable];
  pointerAddress = (uint16_t) &tablePointers[whichTable];
  thisTableP =  (uint8_t*) pgm_read_word(pointerAddress);
}

/* Dodatkowe definicje wartości nienumerycznych */
#define   POINT  10
#define   VOLTS  11 
#define   INTRO  12


///-----------------   Funkcje inicjujące  -------------------///

void initTimer0(void){
  // Licznik 0 konfigurujemy w trybie wolnym z wyjściem PWM
  TCCR0A |= (1<<WGM00) | (1<<WGM01); /* szybki tryb PWM */
  TCCR0A |= (1<<COM0A0) | (1<<COM0A1); /* wyjście na pin PD6/OC0A */
  TCCR0B = (1<<CS00);		       /* najszybszy zegar */
  OCR0A = 128 ;			       /* początkowa wartość środkowa */
  SPEAKER_DDR |= (1<<SPEAKER);	       /* wyjście na PD6 / OC0A */
}

void initTimer2(void){
  // Licznik 2 ładuje wartości do rejestru OCR0A, ustala częstotliwość próbkowania
  TCCR2A = (1<<WGM21);	      /* tryb CTC, odliczaj do wartości w OCR2A */
  TIMSK2 = (1<<OCIE2A);	      /* włącz przerwanie porównywania */
  OCR2A = 128;	    /* ustala częstotliwość odtwarania próbek */
  /* uwaga: nie wybraliśmy źródła zegara, więc licznik nie ruszy */
}

void initADC(void){
  // Funkcja inicjująca konwerter AC dla woltomierza
  ADMUX  |= (0b00001111 & PC5);  /* przełącz multiplekser na kanał ADC5 */
  DIDR0 |= _BV(ADC5D);		 /* wyłącz dodatkową elektronikę z pinu PC5 */
  ADMUX  |= (1 << REFS0);        /* napięcie referencyjne to AVCC, 5V */
  ADCSRA |= (1 << ADPS1) | (1 << ADPS2); /* podzielnik zegara /64 */
  ADCSRA |= (1 << ADEN);        /* włączenie konwertera AC */
}
