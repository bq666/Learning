                                           /* Bezpośrednia synteza cyfrowa */

// ------- Preambuła -------- //
#include <avr/io.h>                        /* Definiuje piny, porty, itd. */
#include <util/delay.h>                     /* Funkcje marnujące czas */
#include <avr/power.h>

#include "pinDefines.h"

#include "fullSaw15.h"

static inline void initTimer0(void) {
  TCCR0A |= (1 << COM0A1);                      /* wyjście PWM na OCR0A */
  SPEAKER_DDR |= (1 << SPEAKER);               /* włacz wyjście na pinie */

  TCCR0A |= (1 << WGM00);                             /* Szybki tryb PWM */
  TCCR0A |= (1 << WGM01);                       /* Szybki tryb PWM, część 2. */

  TCCR0B |= (1 << CS00);                    /* zegar z podzielnikiem /1 */
}

int main(void) {

  uint16_t accumulator;
  uint16_t accumulatorSteps = 880;                    /* mniej więcej 440 Hz */
  uint8_t waveStep;
  int8_t pwmValue;

  // -------- Inicjalizacja --------- //

  clock_prescale_set(clock_div_1);                  /* Częstotliwość CPU - 8 MHz */
  initTimer0();
  BUTTON_PORT |= (1 << BUTTON);                    /* opornik podciagajacy dla przycisku */

  // ------ Pętla zdarzeń ------ //
  while (1) {

    if (bit_is_clear(BUTTON_PIN, BUTTON)) {

      SPEAKER_DDR |= (1 << SPEAKER);                 /* włącz głośnik */
      accumulator += accumulatorSteps;          /* zwiększ akumulator */
      waveStep = accumulator >> 8;           /* która pozycja w tablicy? */
      pwmValue = fullSaw15[waveStep];                 /* pobierz wartość napięcia */

      loop_until_bit_is_set(TIFR0, TOV0);        /* czekaj na cykl PWM */
      OCR0A = 128 + pwmValue;                     /* ustal nową wartość PWM */
      TIFR0 |= (1 << TOV0);                  /* kasuj bit przepełnienia PWM */
    }

    else {                                       /* przycisk nie jest naciśnięty */
      SPEAKER_DDR &= ~(1 << SPEAKER);              /* wyłącz głośnik */
    }

  }                                                  /* Koniec pętli zdarzeń */
  return (0);                            /* Ta instrukcja nie zostanie wykonana */
}
