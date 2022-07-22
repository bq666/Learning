/*

Przykład użycia przerwań do realizacji dwóch zadań jednocześnie.

Dioda LED0 błyska ze stałą prędkością, a przerwanie uruchamiane jest naciśnięciem przycisku.

 */

// ------- Preambuła -------- //
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "pinDefines.h"

ISR(INT0_vect) {         /* Uruchamana przy każdej zmianie stanu przycisku */
  if (bit_is_set(BUTTON_PIN, BUTTON)) {
    LED_PORT |= (1 << LED1);
  }
  else {
    LED_PORT &= ~(1 << LED1);
  }
}

void initInterrupt0(void) {
  EIMSK |= (1 << INT0);                                     /* włącz INT0 */
  EICRA |= (1 << ISC00);          /* uruchom przy zmianie stanu przycisku */
  sei();                       /* ustaw (globalny) bit włączania przerwań */
}

int main(void) {
  // -------- Inicjalizacja --------- //
  LED_DDR = 0xff;                              /* wszystkie diody aktywne */
  BUTTON_PORT |= (1 << BUTTON);                  /* oporniki podciągające */
  initInterrupt0();

  // ------ Pętla zdarzeń ------ //
  while (1) {

    _delay_ms(200);
    LED_PORT ^= (1 << LED0);

  }                                              /* koniec pętli zdarzeń */
  return (0);                     /* ta instrukcja nie zostanie wykonana */
}
