
/*Include file for ADSR synth project. */

#include <avr/io.h>		/* Definiuje piny, porty, itd. */
#include <util/delay.h>		/* Funkcje marnujące czas */
#include <avr/power.h>
#include <avr/interrupt.h>	
#include "pinDefines.h"
#include "macros.h"
#include "scale.h"
#include "fullSaw7.h"		/* przebieg piłokształtny z ograniczeniem do 7. harmonicznej */
                   /* ciekawi mogą zajrzeć do pliku generateWavetables.py */
#include "fullTriangle.h"
#include "USART.h"

#define FULL_VOLUME     31 	/* głośność 5-bitowa */

// Wartości domyślne obwiedni
// Spróbuj z nimi eksperymentować!
#define ATTACK_RATE    8	/* 0-255 */
#define DECAY_RATE     120	/* 0-255 */
#define SUSTAIN_LEVEL  25	/* 0-255 */
#define SUSTAIN_TIME   4000	/* 0-65535 */
#define RELEASE_RATE   200	/* 0-65535 */

// Wyliczenia stałych
#define ATTACK_TIME   ATTACK_RATE * FULL_VOLUME
#define DECAY_TIME   (ATTACK_TIME + (FULL_VOLUME-SUSTAIN_LEVEL) * DECAY_RATE)
#define RELEASE_TIME     DECAY_TIME + SUSTAIN_TIME

// -------------- Procedury inicjujące --------------- //

static inline void initTimer0(void){
  set_bit(TCCR0A, COM0A1);	/* wyjście PWM na OCR0A */
  set_bit(SPEAKER_DDR, SPEAKER); /* włącz pin wyjściowy */

  set_bit(TCCR0A, WGM00);	/* Szybki tryb PWM */
  set_bit(TCCR0A, WGM01);	/* Szybki tryb PWM, część 2. */
  
  set_bit(TCCR0B, CS00);	/* zegar z podzielnikiem /1 */
}

static inline void initLEDs(void){
  uint8_t i;
  LED_DDR = 0xff;	/* wszystkie diody w tryb diagnostyczny */
  for (i=0; i<8; i++){
    set_bit(LED_PORT, i);
    _delay_ms(100);
    clear_bit(LED_PORT, i);
  }
}

static inline uint16_t lookupPitch(char i){
  switch(i){
  case 'a':
    return(G1);
  case 's':
    return(A1);
  case 'd':
    return(B1);
  case 'f':
    return(C2);
  case 'g':
    return(D2);
  case 'h':
    return(E2);
  case 'j':
    return(F2);
  case 'k':
    return(G2);
  case 'l':
    return(A2);
  case ';':
    return(B2);
  case '\'':
    return(C3);   
  }	 
  // Wartość domyślma -- ktoś nacisnął inny klawisz
  return(C1);
}

