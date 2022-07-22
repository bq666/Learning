/*

Krótki przykład generowania dźwięków za pomocą zegara numer 0.

*/

// ------- Preambuła -------- //
#include <avr/io.h>                        /* Definicje pinów, portów itp. */
#include <util/delay.h>                          /* Funkcje marnujące czas */
#include "pinDefines.h"
#include "scale8.h"                         /* 8-bitowe definicje dźwięków */

static inline void initTimer(void) {
  TCCR0A |= (1 << WGM01);                                      /* Tryb CTC */
  TCCR0A |= (1 << COM0A0);      /* Przełączanie stanu pinu po każdym cyklu */
  TCCR0B |= (1 << CS00) | (1 << CS01);                   /* Zegar CPU / 64 */
}

static inline void playNote(uint8_t wavelength, uint16_t duration) {

  OCR0A = wavelength;                      /* ustawienie wysokości dźwięku */
  SPEAKER_DDR |= (1 << SPEAKER);           /* włączenie wyjścia na głośnik */

  while (duration) {                                 /* zmienne opóźnienie */
    _delay_ms(1);
    duration--;
  }
  SPEAKER_DDR &= ~(1 << SPEAKER);         /* wyłączenie wyjścia na głośnik */
}

int main(void) {
  // -------- Inicjalizacja --------- //
  initTimer();
  // ------ Pętla zdarzeń ------ //
  while (1) {
                                                    /* Zagrajmy kilka nut */
    playNote(C2, 200);
    playNote(E2, 200);
    playNote(G2, 200);
    playNote(C3, 400);

    _delay_ms(1000);
    _delay_ms(1000);
    _delay_ms(1000);

  }                                               /* Koniec pętli zdarzeń */
  return (0);                      /* Ta instrukcja nie zostanie wykonana */
}
