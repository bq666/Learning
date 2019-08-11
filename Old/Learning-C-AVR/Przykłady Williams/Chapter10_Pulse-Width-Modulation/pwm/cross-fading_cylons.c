/*

Oczy cylonów z rozjaśnianiem
Demonstracja działania PWM

*/

// ------- Preambuła -------- //
#include <avr/io.h>                        /* Definiuje piny, porty, itd. */
#include <util/delay.h>                     /* Funkcje marnujące czas */
#include "pinDefines.h"


int main(void) {

  uint8_t thisEye = 0;
  uint8_t nextEye = 1;
  uint8_t brightness = 0;
  int8_t direction = 1;
  uint8_t i;

  // -------- Inicjalizacja --------- //

  // Inicjacja wszystkich diod
  LED_DDR = 0xff;
  SPEAKER_DDR |= (1 << SPEAKER);
  // ------ Pętla zdarzeń ------ //
  while (1) {

    // PWM
    for (brightness = 0; brightness < 255; brightness++) {
      for (i = 0; i < 255; i++) {
        if (i < brightness) {
          LED_PORT &= ~(1 << thisEye);                     /* przyciemnianie */
          LED_PORT |= (1 << nextEye);              /* rozjaśnienie */
        }
        else {
          LED_PORT |= (1 << thisEye);
          LED_PORT &= ~(1 << nextEye);
        }
        LED_PORT &= ~(1 << thisEye);            /* upewnij się, że jest wyłączona */
      }
    }

    // ruch oka Cylonów
    thisEye += direction;                       /* przejdź do kolejnego oka */

    if (thisEye == 0) {
      direction = 1;
    }
    if (thisEye == 7) {
      direction = -1;
    }

    nextEye = thisEye + direction;


  }                                                  /* Koniec pętli zdarzeń */
  return (0);                            /* Ta instrukcja nie zostanie wykonana */
}
