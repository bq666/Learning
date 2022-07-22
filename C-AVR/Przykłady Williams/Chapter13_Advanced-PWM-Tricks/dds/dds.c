                                               /* Bezpośrednia synteza cyfrowa */

// ------- Preambuła -------- //
#include <avr/io.h>                            /* Definicje portów, pinów itp. */
#include <util/delay.h>                              /* Funkcje marnujące czas */
#include <avr/power.h>

#include "pinDefines.h"

#include "fullSine.h"

static inline void initTimer0(void) {
  TCCR0A |= (1 << COM0A1);                     /* wyjście PWM z rejestru OCR0A */
  SPEAKER_DDR |= (1 << SPEAKER);                        /* włącz pin wyjściowy */

  TCCR0A |= (1 << WGM00);                                   /* szybki tryb PWM */
  TCCR0A |= (1 << WGM01);                          /* szybki tryb PWM, część 2 */

  TCCR0B |= (1 << CS00);                               /* podzielnik zegara /1 */
}

int main(void) {

  uint16_t accumulator;
  uint16_t accumulatorSteps = 880;                             /* około 440 Hz */
  uint8_t waveStep;
  int8_t pwmValue;

  // -------- Inicjalizacja --------- //

  clock_prescale_set(clock_div_1);                    /* zegar procesora 8 MHz */
  initTimer0();
  BUTTON_PORT |= (1 << BUTTON);          /* opornik podciągający dla przycisku */

  // ------ Pętla zdarzeń ------ //
  while (1) {

    if (bit_is_clear(BUTTON_PIN, BUTTON)) {

      SPEAKER_DDR |= (1 << SPEAKER);                     /* włączenie głośnika */
      accumulator += accumulatorSteps;              /* zwiększenie akumulatora */
      waveStep = accumulator >> 8;             /* wyznaczenie pozycji w tabeli */
      pwmValue = fullSine[waveStep];             /* pobranie wartości napięcia */

      loop_until_bit_is_set(TIFR0, TOV0);            /* odczekanie na cykl PWM */
      OCR0A = 128 + pwmValue;                        /* ustal nową wartość PWM */
      TIFR0 |= (1 << TOV0);                     /* zeruj bit przepełnienia PWM */
    }

    else {                                         /* nie naciśnięto przycisku */
      SPEAKER_DDR &= ~(1 << SPEAKER);                        /* wyłącz głośnik */
    }

  }                                                    /* koniec pętli zdarzeń */
  return (0);                           /* ta instrukcja nie zostanie wykonana */
}
