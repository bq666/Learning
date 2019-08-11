

// ------- Preambula -------- //
#include <avr/io.h>
#include "pinDefines.h"

#include <util/delay.h>
#define DEBOUNCE_TIME  1000                            /* mikrosekundy */

uint8_t debounce(void) {
  if (bit_is_clear(BUTTON_PIN, BUTTON)) {   /* przycisk jest naciśnięty */
    _delay_us(DEBOUNCE_TIME);
    if (bit_is_clear(BUTTON_PIN, BUTTON)) {         /* nadal naciśnięty */
      return (1);
    }
  }
  return (0);
}

int main(void) {
  // -------- Inicjalizacja --------- //
  uint8_t buttonWasPressed;                                    /* stan */
  BUTTON_PORT |= (1 << BUTTON);          /* włącz opornik podciągający */
  LED_DDR = (1 << LED0);             /* skonfiguruj diody jako wyjścia */

  // ------ Pętla zdarzeń ------ //
  while (1) {
    if (debounce()) {                 /* naciśnięto przycisk bez odbić */
      if (buttonWasPressed == 0) {    /* a ostatnio nie był naciśnięty */
        LED_PORT ^= (1 << LED0);                           /* zrób coś */
        buttonWasPressed = 1;                      /* zaktualizuj stan */
      }
    }
    else {                       /* teraz przycisk nie jest naciśnięty */
      buttonWasPressed = 0;                        /* zaktualizuj stan */
    }

  }                                            /* koniec pętli zdarzeń */
  return (0);                   /* ta instrukcja nie zostanie wykonana */
}
