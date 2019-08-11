/*
   Demonstrajca wykorzystania stanu do wykrywania naciśnięcia przycisku
*/

// ------- Preambuła -------- //
#include <avr/io.h>
#include "pinDefines.h"

#include <util/delay.h>
#define DEBOUNCE_TIME  5                               /* mikrosekundy */

uint8_t debouncePress(void) {
  if (bit_is_clear(BUTTON_PIN, BUTTON)) {      /* przycisk jest właśnie naciśnięty */
    _delay_ms(DEBOUNCE_TIME);
    if (bit_is_clear(BUTTON_PIN, BUTTON)) {            /* nadal naciśnięty */
      return (1);
    }
  }
  return (0);
}

int main(void) {
  // -------- Inicjalizacja --------- //
  uint8_t buttonWasPressed;                                   /* stan */
  BUTTON_PORT |= (1 << BUTTON);     /* włącz opornik podciągający dla przycisku */
  LED_DDR = (1 << LED0);                      /* skonfiguruj diodę LED jako wyjście */

  // ------ Pętla zdarzeń ------ //
  while (1) {
    if (debouncePress()) {
      if (buttonWasPressed == 0) {     /* Ostatnio przycik nie był naciśnięty */
        LED_PORT ^= (1 << LED0);                        /* zrób coś */
        buttonWasPressed = 1;                      /* zaktualizuj stan */
      }
    }
    else {                                /* przycisk nie jest już naciśnięty */
      buttonWasPressed = 0;                        /* zaktualizuj stan */
    }

  }                                                  /* Koniec pętli zdarzeń */
  return (0);                            /* Ta instrukcja nie zostanie wykonana */
}
