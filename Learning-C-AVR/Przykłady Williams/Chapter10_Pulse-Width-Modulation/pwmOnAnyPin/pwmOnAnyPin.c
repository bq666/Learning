// Szybki przykład modulowania impulsu na dowolnym pinie z wykorzystaniem przerwań
// ------- Preambuła -------- //
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "pinDefines.h"

#define DELAY 3

volatile uint8_t brightnessA;
volatile uint8_t brightnessB;

// -------- Funkcje --------- //
static inline void initTimer0(void) {
                                 /* musi mieć wartość /64 ze względu na zależności czasowe */
  TCCR0B |= (1 << CS01) | (1 << CS00);
                                                    /* oba przerwania porwónywania wyjścia */
  TIMSK0 |= ((1 << OCIE0A) | (1 << OCIE1B));
  TIMSK0 |= (1 << TOIE0);                            /* włączenie przerwania przepełnienia */
  sei();
}

ISR(TIMER0_OVF_vect) {
  LED_PORT = 0xff;
  OCR0A = brightnessA;
  OCR0B = brightnessB;
}
ISR(TIMER0_COMPA_vect) {
  LED_PORT &= 0b11110000;                                    /* wyłącz dolne cztery diody */
}
ISR(TIMER0_COMPB_vect) {
  LED_PORT &= 0b00001111;                                    /* wyłącz górne cztery diody */
}

int main(void) {
  // -------- Initcjalizacja --------- //

  uint8_t i;
  LED_DDR = 0xff;
  initTimer0();

  // ------ Pętla zdarzeń ------ //
  while (1) {

    for (i = 0; i < 255; i++) {
      _delay_ms(DELAY);
      brightnessA = i;
      brightnessB = 255 - i;
    }

    for (i = 254; i > 0; i--) {
      _delay_ms(DELAY);
      brightnessA = i;
      brightnessB = 255 - i;
    }

  }                                                              /* Koniec pętli zdarzeń */
  return (0);                                     /* ta instrukcja nie zostanie wykonana */
}
