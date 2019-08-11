/* 
 *  "Symfonie algorytmiczne"
 *  Po połączeniu arytmetyki modulo ze zmienną licznikową
 *   powstaną sekwencje brzmiące jak generowane przez 4-bitowy syntezator.
 *  Zauważ, że bezpośrednio przekształcamy tu wartości
 *   liczbowe w wartość napięcia.
 *  Pozmieniaj zdefiniowane tutaj formuły albo przejrzyj inne
 *   znajdujące się w pliku "music_formula_collection.txt".
 * */

// ------- Preambuła -------- //
#include <avr/io.h>		/* Definiuje piny, porty, itd. */
#include <util/delay.h>		/* Funkcje marnujące czas */
#include <avr/power.h>
#include "pinDefines.h"
#include "macros.h"

static inline void initTimer0(void){

  set_bit(TCCR0A, COM0A1);	/* wyjście PWM na OCR0A */
  set_bit(SPEAKER_DDR, SPEAKER); /* włącz wyjście na pinie */
  set_bit(TCCR0A, WGM00);	/* Szybki tryb PWM */
  set_bit(TCCR0A, WGM01);	/* Szybki tryb PWM, część 2. */
  set_bit(TCCR0B, CS00);	/* zegar z podzielnikiem /1 */
}

static inline void pollButton(void){
  if (bit_is_clear(BUTTON_PIN, BUTTON)) {
    set_bit(SPEAKER_DDR, SPEAKER); /* włącz wyjście na pinie */
    clear_bit(LED_PORT, LED0);
  }
  else {
    clear_bit(SPEAKER_DDR, SPEAKER); /* wyłącz wyjście na pinie */
    set_bit(LED_PORT, LED0);
  }
}

int main(void){
  uint16_t t;  
  uint8_t i;

  // -------- Inicjalizacja --------- //
  clock_prescale_set(clock_div_1);                  /* zegar CPU 8 MHz */
  initTimer0();
   
  set_bit(BUTTON_PORT, BUTTON);	/* opornik podciągający dla przycisku */

  set_bit(LED_DDR, LED0);	/* włącz diody dla diagnostyki */
  set_bit(LED_PORT, LED0);
  _delay_ms(100);
  clear_bit(LED_PORT, LED0);
   
  set_bit(SPEAKER_DDR, SPEAKER);
  OCR0A = 210;
  // ------ Pętla zdarzeń ------ //
  while(1){	
    
    t++;
	OCR0A = (uint8_t) ((t<<1)^((t<<1)+(t>>7)&t>>12))|t>>(4-(1^7&(t>>19)))|t>>7; /* "tłum" */ 
	// OCR0A = (uint8_t) t;		  /* piła */
	// OCR0A = (uint8_t) t * (t >> 8);	/* narastająca częstotliwość + różne aliasy */
	// OCR0A = (uint8_t) t & (t >> 8);     /* arpeggios */
	// OCR0A = (uint8_t) t*( 42 & t >> 10 );  
	// OCR0A = (uint8_t)  t*(t>>((t>>9)|(t>>8))&(63&(t>>4))); /* space invaders kontra pong */
	// OCR0A = (uint8_t) t*(t>>8*((t>>15)|(t>>8))&(20|(t>>19)*5>>t|(t>>3)));
	// OCR0A = (uint8_t) (t*5&t>>7)|(t*3&t>>10);
	// OCR0A = (uint8_t) (t*9 & t>>4 | t* 5 & t>> 7 | t * 3 & t/1024)-1; 
	// OCR0A = (uint8_t) (t>>5)|(t>>4)|((t%42)*(t>>4)|(0x15483113)-(t>>4))/(t>>16)^(t|(t>>4)); 
	// OCR0A = (uint8_t) t*(( (t>>12) | (t>>8)) & (63 & (t>>4)) );		  /* dziwne */
    pollButton();
    _delay_us(124);		/* częstość próbkowania powinna wynosić 8kHz */
    
  } /* Koniec pętli zdarzeń */
  return(0);		      /* Ta instrukcja nie zostanie wykonana */
}




