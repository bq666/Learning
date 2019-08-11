// Prosty przykład użycia mostka H

// ------- Preambuła -------- //
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "pinDefines.h"

static inline void setBridgeState(uint8_t bridgeA, uint8_t bridgeB) {
  /* Funkcja pomocnicza włączająca diodę LED przy przełączaniu strony mostka w stan wysoki */
  if (bridgeA) {
    PORTD |= (1 << PD6);
    LED_PORT |= (1 << LED0);
  }
  else {
    PORTD &= ~(1 << PD6);
    LED_PORT &= ~(1 << LED0);
  }
  if (bridgeB) {
    PORTD |= (1 << PD5);
    LED_PORT |= (1 << LED1);
  }
  else {
    PORTD &= ~(1 << PD5);
    LED_PORT &= ~(1 << LED1);
  }
}


int main(void) {
  // -------- Inicjalizacja --------- //

  DDRD |= (1 << PD6);                 /* teraz podłączone do 1. wejścia mostka */
  DDRD |= (1 << PD5);                 /* teraz podłączone do 2. wejścia mostka */
  LED_DDR |= (1 << LED0);
  LED_DDR |= (1 << LED1);

  // ------ Pętla zdarzeń ------ //
  while (1) {

    setBridgeState(1, 0);                                         /* "naprzód" */
    _delay_ms(2000);

    setBridgeState(0, 0);              /* oba wyjścia niskie zatrzymują silnik */
    _delay_ms(2000);

    setBridgeState(0, 1);                                          /* "wstecz" */
    _delay_ms(2000);

    setBridgeState(1, 1);     /* oba wyjścia wysokie również zatrzymują silnik */
    _delay_ms(2000);

    // Super szybkie hamowanie po wstecznym zasileniu silnika
    setBridgeState(1, 0);
    _delay_ms(2000);
    setBridgeState(0, 1);
    _delay_ms(75);    /* zmień ten czas tak, żeby dopasować do swojego systemu */
    setBridgeState(0, 0);
    _delay_ms(2000);

  }                                                    /* koniec pętli zdarzeń */
  return (0);
}
