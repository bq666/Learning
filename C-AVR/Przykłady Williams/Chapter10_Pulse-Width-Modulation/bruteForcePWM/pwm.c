/*
 * Quick and dirty PWM Demo
 */

// ------- Preambuła -------- //
#include <avr/io.h>                        /* Definiuje piny, porty, itd. */
#include <util/delay.h>                     /* Funkcje marnujące czas */
#include "pinDefines.h"

#define LED_DELAY 2

int main(void) {

  uint8_t brightness = 0;
  int8_t direction = 1;
  uint8_t i;

  // -------- Inicjalizacja --------- //

  LED_DDR = 0xff;                                     /* Inicjuj wszystkie diody */

  // ------ Pętla zdarzeń ------ //
  while (1) {

    // PWM
    for (i = 0; i < 255; i++) {
      if (i < brightness) {
        LED_PORT = 0xff;                                    /* włącz */
      }
      else {
        LED_PORT = 0;                                      /* wyłącz */
      }
      _delay_us(LED_DELAY);
    }

    // Rozjaśniaj i przyciemniaj
    if (brightness == 0) {
      direction = 1;
    }
    if (brightness == 255) {
      direction = -1;
    }
    brightness += direction;

  }                                                  /* Koniec pętli zdarzeń */
  return (0);                            /* Ta instrukcja nie zostanie wykonana */
}
