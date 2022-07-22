// Powolny oscyloskop używający konwertera AC w trybie ciągłym

// ------- Preambuła -------- //
#include <avr/io.h>
#include <util/delay.h>
#include "pinDefines.h"
#include "USART.h"

#define SAMPLE_DELAY  20 /* ms, steruje szybkością przewijania oscyloskopu */

// -------- Funkcje --------- //
static inline void initFreerunningADC(void) {
  ADMUX |= (1 << REFS0);                  /* napięcie referencyjne to AVCC */
  ADCSRA |= (1 << ADPS1) | (1 << ADPS0); /* preskaler zegara konwertera /8 */

  ADMUX |= (1 << ADLAR); /* wyrównaj wynik do lewej, zwracaj tylko 8 bitów */

  ADCSRA |= (1 << ADEN);                             /* włącz konwerter AC */
  ADCSRA |= (1 << ADATE);                             /* włącz tryb ciągły */
  ADCSRA |= (1 << ADSC);                     /* uruchom pierwszą konwersję */
}

int main(void) {
  // -------- Inicjalizacja --------- //
  initUSART();
  initFreerunningADC();
  // ------ Pętla zdarzeń ------ //
  while (1) {
    transmitByte(ADCH);           /* wyślij górny bajt, wyrównany do lewej */
    _delay_ms(SAMPLE_DELAY);
  }                                                /* koniec pętli zdarzeń */
  return (0);                          /* Ten wiersz nie zostanie wykonany */
}
