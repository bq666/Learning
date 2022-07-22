
// ------- Preambuła -------- //
#include <avr/io.h>		/* Definiuje piny, porty, itd. */
#include <util/delay.h>		/* Funkcje marnujące czas */
#include <avr/interrupt.h>	
#include <avr/power.h>
#include "pinDefines.h"
#include "macros.h"
#include "fullSaw15.h"

#define BASEPITCH       220 /* w krokach o wielkości tuningWord, czyli ~1/2 Hz */
#define PHASE_RATE      7   /* steruje szybkością efektu zmiany fazy */

#define NUMBER_OSCILLATORS  4
/* 2 i 4 działają świetnie.
   8 i 16 zajmują za wiele czasu, żeby utrzymać częstotliwość 31,25kHz 
   dlatego dźwięk się obniża i pojawiają się różne zniekształcenia.
   Jeżeli podobają Ci się przerazające dźwięki, to 8 i 16 sprawdzą się świetnie, 
   lepiej zwiększ wartość parametru BASEPITCH. */

#define  OSCILLATOR_SHIFT   2
/* To liczba bitów przesuwana podczas mieszania głośności. 
   2**OSCILLATOR_SHIFT = NUMBER_OSCILLATORS 
   Jeżeli nie dopasujesz tej wartości do liczby oscylatorów, to pojawią
   się przycięcia i zniekształcenia cyfrowe.  */


static inline void initTimer0(void){
  set_bit(TCCR0A, WGM00);	/* Szybki tryb PWM */
  set_bit(TCCR0A, WGM01);	/* Szybki tryb PWM */

  set_bit(TCCR0A, COM0A1);	/* wyjście PWM na OCR0A */
  set_bit(SPEAKER_DDR, SPEAKER); /* włącz wyjście na pinie */

  set_bit(TCCR0B, CS00);	/* zegar z podzielnikiem /1 */
}
