/*
   Bezpośrednia synteza cyfrowa
   Dynamiczna obwiednia dźwięku ADSR
*/

// ------- Preambuła -------- //
#include "adsr.h"           /* Definicje, dołączane pliki i funkcje inicjujące */

int main(void) {

  // -------- Inicjalizacja --------- //

  uint16_t accumulator = 0;
  uint8_t volume = 0;
  uint16_t noteClock = 0;
  uint16_t tuningWord = C1;

  uint8_t waveStep;
  int16_t mixer;
  uint8_t i;
  char serialInput;

  clock_prescale_set(clock_div_1);                    /* zegar procesora 8 MHz */
  initTimer0();
  initUSART();
  printString("  Serial Synth\r\n");
  printString("Notes: asdfghjkl;'\r\n");

  SPEAKER_DDR |= (1 << SPEAKER);                           /* wyjście głośnika */

  // ------ Pętla zdarzeń ------ //
  while (1) {

    // Ustawienie wyjścia PWM
    loop_until_bit_is_set(TIFR0, TOV0);  /* czekaj na przepełnienie licznika 0 */
    OCR0A = 128 + (uint8_t) mixer;
    TIFR0 |= (1 << TOV0);                           /* kasuj bit przepełnienia */

    // Aktualizowanie danych syntezatora
    accumulator += tuningWord;
    waveStep = accumulator >> 8;
    mixer = fullTriangle[waveStep] * volume;
    mixer = mixer >> 5;

                             /* Obsługa danych wejściowych: sprawdź port USART */
    if (bit_is_set(UCSR0A, RXC0)) {
      serialInput = UDR0;                       /* odczytaj dane z portu USART */
      tuningWord = lookupPitch(serialInput);
      noteClock = 1;
    }

                                              /* Obsługa dynamicznej głośności */
    if (noteClock) {                      /* jeżeli dźwięk jest już odtwarzany */
      noteClock++;
      if (noteClock < ATTACK_TIME) {                                   /* atak */
                            /* poczekaj na moment przejścia do kolejnego kroku */
        if (noteClock > ATTACK_RATE * volume) {
          if (volume < 31) {
            volume++;
          }
        }
      }
      else if (noteClock < DECAY_TIME) {                           /* opadanie */
        if ((noteClock - ATTACK_TIME) >
            (FULL_VOLUME - volume) * DECAY_RATE) {
          if (volume > SUSTAIN_LEVEL) {
            volume--;
          }
        }
      }
      else if (noteClock > RELEASE_TIME) {                    /* wybrzmiewanie */
        if ((noteClock - RELEASE_TIME) >
            (SUSTAIN_LEVEL - volume) * RELEASE_RATE) {
          if (volume > 0) {
            volume--;
          }
          else {
            noteClock = 0;
          }
        }
      }
    }


  }                                                    /* Koniec pętli zdarzeń */
  return (0);                           /* ta instrukcja nie zostanie wykonana */
}
