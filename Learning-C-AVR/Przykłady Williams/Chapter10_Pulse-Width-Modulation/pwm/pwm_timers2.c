/*

PWM Demo with serial control over three LEDs

*/

// ------- Preambuła -------- //
#include <avr/io.h>                        /* Definiuje piny, porty, itd. */
#include <util/delay.h>                     /* Funkcje marnujące czas */
#include "pinDefines.h"


#define LED_DELAY  5                                   /* milisekundy */

static inline void initTimers(void) {
  // Timer 1 A,B
  TCCR1A |= (1 << WGM10);                      /* Szybki tryb PWM, 8-bitów */
  TCCR1B |= (1 << WGM12);                       /* Szybki tryb PWM, część 2. */
  TCCR1B |= (1 << CS11);            /* F_CPU/8 -- 1MHz with fast fuses */

  TCCR1A |= (1 << COM1A1);                      /* Wyjście PWM na OCR1A */
  TCCR1A |= (1 << COM1B1);                      /* Wyjście PWM na OCR1B */
  LED_DDR |= (1 << LED1);                      /* włacz wyjście na pinie */
  LED_DDR |= (1 << LED2);                      /* włacz wyjście na pinie */

  // Timer 2
  TCCR2A |= (1 << WGM20);                             /* Szybki tryb PWM */
  TCCR2A |= (1 << WGM21);                       /* Szybki tryb PWM, część 2. */
  TCCR2B |= (1 << CS21);            /* F_CPU/8 -- 1MHz with fast fuses */

  TCCR2A |= (1 << COM2A1);                      /* Wyjście PWM na OCR2A */
  LED_DDR |= (1 << LED3);                      /* włacz wyjście na pinie */
}

int main(void) {

  // -------- Inicjalizacja --------- //

  initTimers();

  // ------ Pętla zdarzeń ------ //
  while (1) {

    // Brighten
    while (OCR2A < 255) {
      OCR2A++;
      OCR1A++;
      OCR1B++;
      _delay_ms(LED_DELAY);
    }

    // Dim
    while (OCR2A > 0) {
      OCR2A--;
      OCR1A--;
      OCR1B--;
      _delay_ms(LED_DELAY);
    }

  }                                                  /* Koniec pętli zdarzeń */
  return (0);                            /* Ta instrukcja nie zostanie wykonana */
}
