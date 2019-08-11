/* Bezpośrednia synteza cyfrowa */

// ------- Preambuła -------- //
#include <avr/io.h>		/* Definiuje piny, porty, itd. */
#include <util/delay.h>		/* Funkcje marnujące czas */
#include <avr/interrupt.h>	
#include <avr/power.h>
#include "pinDefines.h"
#include "macros.h"
#include "fullSine.h"


static inline void initTimer0(void){
  set_bit(TCCR0A, COM0A1);	/* wyjście PWM na OCR0A */
  set_bit(SPEAKER_DDR, SPEAKER); /* włacz wyjście na pinie */

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

static inline void initLED(void){
  set_bit(LED_DDR, LED0);	/* włącz diody LED dla diagnostyki */
  set_bit(LED_PORT, LED0);
  _delay_ms(100);
  clear_bit(LED_PORT, LED0);
}

int main(void){

  volatile  uint16_t accumulator0;  
  volatile  uint16_t accumulator1;  
  volatile  uint16_t tuningWord0;
  volatile  uint16_t tuningWord1;
  volatile  uint16_t mixer;

  // -------- Inicjalizacja --------- //
  
  clock_prescale_set(clock_div_1);                  /* Częstotliwość CPU - 8 MHz */
  initLED();
  initTimer0();
  
  set_bit(BUTTON_PORT, BUTTON);	/* opornik podciagajacy dla przycisku */
  set_bit(SPEAKER_DDR, SPEAKER); /* wyjście głośnika */
  
  tuningWord0 = 440*2;		/* częstotliwości dźwięków wybierania */
  tuningWord1 = 350*2;
  
  // ------ Pętla zdarzeń ------ //
  while(1){		       
    
    loop_until_bit_is_set(TIFR0, TOV0); /* poczekaj na ustawienie bitu przepełnienia */
    set_bit(TIFR0, TOV0);		/* zapisanie powinno go skasować... */

    //  Pamiętaj, że to musi być naprawdę szybkie... mamy jedynie 256 cykli
    //  żeby ustalić następną wartość rejestru OCR0A, albo usłyszymy przeskoki

    accumulator0 += tuningWord0;	/* przejdź naprzód o tuningWord kroków */
    accumulator1 += tuningWord1;	/* przejdź naprzód o tuningWord kroków */

    mixer = fullSine[(uint8_t) (accumulator0 >> 8)]; /* sumowanie */
    mixer += fullSine[(uint8_t) (accumulator1 >> 8)];
    OCR0A = 128 + (mixer >> 1);		/* szybkie dzielenie przez 2 */
    
    pollButton();
    

  } /* Koniec pętli zdarzeń */
  return(0);		      /* ta instrukcja nie zostanie wykonana */
}



