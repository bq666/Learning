/*
   Program sprawdzajacy stan przycisku (włącz/wyłącz)
   Przycisk podłączony jest do pinu PD2
   Diody LED podłączone są do pinów PB0..PB7
*/

// ------- Preambuła -------- //
#include <avr/io.h>
#include <util/delay.h>

int main(void) {
  // -------- Inicjalizacja --------- //
  PORTD |= (1 << PD2);   /* włączenie opornika podciągającego dla pinu */
  DDRB = 0xff;          /* wszystkie diody skonfigurowane jako wyjścia */

  // ------ Pętla zdarzeń ------ //
  while (1) {
    if (bit_is_clear(PIND, PD2)) {   /* czy przycisk został naciśnięty */
                  /* równoważne z zapisem ((PIND & (1 << PD2)) == 0 ){ */
      PORTB = 0b00111100;                                /* naciśnięty */
    }
    else {                                           /* nie naciśnięty */
      PORTB = 0b11000011;
    }
  }                                            /* koniec pętli zdarzeń */
  return (0);
}
