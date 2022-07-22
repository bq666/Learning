/*
   Bezpośrednia synteza cyfrowa
   Program odtwarzający fale piłokształtne

*/

#include "fatSaw.h"

int main(void) {

  uint16_t accumulators[NUMBER_OSCILLATORS];
  uint8_t waveStep;
  int16_t mixer;
  uint8_t i;

  // -------- Inicjalizacja --------- //

  clock_prescale_set(clock_div_1);                    /* zegar procesora 8 MHz */
  initTimer0();
  SPEAKER_DDR |= (1 << SPEAKER);                           /* wyjście głośnika */
  LED_DDR |= (1 << LED0);

  // Początkowo wszystkie są w fazie
  for (i = 0; i < NUMBER_OSCILLATORS; i++) {
    accumulators[i] = 0;
  }

  // ------ Pętla zdarzeń ------ //
  while (1) {

                             /* Załaduj wartość PWM gdy wszystko będzie gotowe */
    loop_until_bit_is_set(TIFR0, TOV0);         /* czekaj na bit przepełnienia */
    OCR0A = 128 + mixer;     /* liczby ze znakiem wymagają przesunięcia w górę */
    TIFR0 |= (1 << TOV0);                      /* kasowanie bitu przepełnienia */

                          /* aktualizacja wszystkich akumulatorów i miksowanie */
    mixer = 0;
    for (i = 0; i < NUMBER_OSCILLATORS; i++) {
      accumulators[i] += BASEPITCH;
      waveStep = accumulators[i] >> 8;

      // Dodaj zmianę fazy.
      // Tworzy przesuwające się dudnienia 
      // gdy nakładają się różne częstotliwości
      if (waveStep == 0) {                         /* mniej więcej raz na cykl */
        accumulators[i] += PHASE_RATE * i;                 /* lekko zmień fazę */
      }

      mixer += fullSaw15[waveStep];
    }
    mixer = mixer >> OSCILLATOR_SHIFT;
                   /* Dzielenie przez przesunięcie bitowe jest bardzo szybkie. */

  }                                                    /* Koniec pętli zdarzeń */
  return (0);                           /* ta instrukcja nie zostanie wykonana */
}
