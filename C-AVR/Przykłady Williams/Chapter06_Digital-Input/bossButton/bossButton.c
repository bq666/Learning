/*
bossButton.c

Skoro przycisk nadal jest przyłączony do układu AVR,
możemy wykorzystać go do zabawy.

Prześlij ten kod do mikrokontrolera, uruchom program bossButton.py.
Naciśnij przycisk.

*/

// ------- Preambuła -------- //
#include <avr/io.h>
#include <util/delay.h>
#include "pinDefines.h"
#include "USART.h"

static inline void blinkLED(void) {
  LED_PORT = (1 << LED0);
  _delay_ms(1000);
  LED_PORT &= ~(1 << LED0);
}


int main(void) {

  // -------- Inicjalizacja --------- //
  BUTTON_PORT |= (1 << BUTTON);    /* tryb wejścia, włącz opornik podciągający */

  LED_DDR = (1 << LED0);
  blinkLED();

  initUSART();
  transmitByte('O');

  // ------ Pętla zdarzeń ------ //
  while (1) {

    if (bit_is_clear(BUTTON_PIN, BUTTON)) {
      transmitByte('X');
      blinkLED();
    }

  }                                                  /* koniec pętli zdarzeń */
  return (0);
}
