     /* Wykorzystanie perzerwania zmiany stanu pinu 
	      w procedurze eliminowania odbić */

// ------- Preambuła -------- //
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "pinDefines.h"


ISR(PCINT2_vect) {              /* Uruchamiane przy każdej zmianie stanu przycisku */
  if (bit_is_set(BUTTON_PIN, BUTTON)) {
    LED_PORT |= (1 << LED1);
  }
  else {
    LED_PORT &= ~(1 << LED1);
  }
}

void initPinChangeInterrupt18(void) {
  PCICR |= (1 << PCIE2);        /* włączenie przerwania zmiany stanu dla pinów portu D */
  PCMSK2 |= (1 << PCINT18);      /* użyj maski, żeby sprawdzić bit PCINT18 / PD2 */
  sei();                          /* ustaw (globalny) bit włączenia przerwań */
}

int main(void) {
  // -------- Inicjalizacja --------- //
  LED_DDR = 0xff;                                   /* wszystkie diody aktywne */
  BUTTON_PORT |= (1 << BUTTON);                              /* opornik podciągający */
  initPinChangeInterrupt18();

  // ------ Pętla zdarzeń ------ //
  while (1) {

    _delay_ms(200);
    LED_PORT ^= (1 << LED0);

  }                                                  /* Koniec pętli zdarzeń */
  return (0);                            /* Ta instrukcja nie zostanie wykonana */
}
