/*
   Demonstracja wykorzystania stanu do wykrywania naciśnięcia przycisku
*/

// ------- Preambuła -------- //
#include <avr/io.h>
#include "pinDefines.h"

int main(void) {
  // -------- Inicjalizacja --------- //
  uint8_t buttonWasPressed;                                    /* stan */
  BUTTON_PORT |= (1 << BUTTON);   /* włączanie opornika podciągającego */
  LED_DDR = (1 << LED0);           /* diody konfigurujemy jako wyjścia */

  // ------ Pętla zdarzeń ------ //
  while (1) {
    if (bit_is_clear(BUTTON_PIN, BUTTON)) { /* przycisk jest teraz naciśnięty */
      if (buttonWasPressed == 0) {     /* ale czy był naciśnięty poprzednio? */
        LED_PORT ^= (1 << LED0);                           /* zrób coś */
        buttonWasPressed = 1;                      /* zaktualizuj stan */
      }
    }
    else {                       /* teraz przycisk nie jest naciśnięty */
      buttonWasPressed = 0;                        /* zaktualizuj stan */
    }
  }                                            /* koniec pętli zdarzen */
  return (0);             /* ta instrukcja nigdy nie zostanie wykonana */
}
