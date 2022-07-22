                                      /* Prosty przykład modulacji impulsu */

// ------- Preambuła -------- //
#include <avr/io.h>                        /* Definicje pinów, portów itp. */
#include <util/delay.h>                          /* Funkcje marnujące czas */
#include "pinDefines.h"

#define LED_DELAY  20                                      /* mikrosekundy */

void pwmAllPins(uint8_t brightness) {
  uint8_t i;
  LED_PORT = 0xff;                                            /* włączenie */
  for (i = 0; i < 255; i++) {
    if (i >= brightness) {            /* po odczekaniu dość długiego czasu */
      LED_PORT = 0;                                          /* wyłączenie */
    }
    _delay_us(LED_DELAY);
  }
}

int main(void) {

  uint8_t brightness = 0;
  int8_t direction = 1;

  // -------- Inicjalizacja --------- //

  // Inicjowanie wszystkich diod
  LED_DDR = 0xff;
  // ------ Pętla zdarzeń ------ //
  while (1) {
    // Rozjaśnianie i przygaszanie
    if (brightness == 0) {
      direction = 1;
    }
    if (brightness == 255) {
      direction = -1;
    }
    brightness += direction;
    pwmAllPins(brightness);


   }                                               /* Koniec pętli zdarzeń */
  return (0);                       /* ta instrukcja nie zostanie wykonana */
}
