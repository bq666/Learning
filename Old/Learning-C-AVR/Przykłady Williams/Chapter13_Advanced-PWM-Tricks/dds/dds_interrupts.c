                                           /* Bezpośrednia synteza cyfrowa */

// ------- Preambuła -------- //
#include <avr/io.h>                        /* Definiuje piny, porty, itd. */
#include <util/delay.h>                     /* Funkcje marnujące czas */
#include <avr/interrupt.h>
#include <avr/power.h>
#include "pinDefines.h"

#include "fullSine.h"
#include "USART.h"

volatile uint16_t accumulator;
volatile uint16_t tuningWord;

static inline void initTimer0(void) {
  TCCR0A |= (1 << COM0A1);                      /* wyjście PWM na OCR0A */
  SPEAKER_DDR |= (1 << SPEAKER);               /* włacz wyjście na pinie */

  TCCR0A |= (1 << WGM00);                             /* Szybki tryb PWM */
  TCCR0A |= (1 << WGM01);                       /* Szybki tryb PWM, część 2. */

  TCCR0B |= (1 << CS00);                    /* zegar z podzielnikiem /1 */
  TIMSK0 |= (1 << TOIE0);                        /* Overflow interrupt */
  sei();                                           /* Enable interrupt */
}

ISR(TIMER0_OVF_vect) {

  accumulator += tuningWord;          /* przejdź naprzód o tuningWord kroków */
                                              /* wyszukaj wartość i ustaw wyjście */
  OCR0A = 128 + fullSine[(uint8_t) (accumulator >> 8)];

}

static inline void pollButton(void) {
  if (bit_is_clear(BUTTON_PIN, BUTTON)) {
    SPEAKER_DDR |= (1 << SPEAKER);             /* włacz wyjście na pinie */
    LED_PORT &= ~(1 << LED0);
  }
  else {
    SPEAKER_DDR &= ~(1 << SPEAKER);          /* wyłacz wyjście na pinie */
    LED_PORT |= (1 << LED0);
  }
}

int main(void) {

  // -------- Inicjalizacja --------- //

  clock_prescale_set(clock_div_1);                  /* Częstotliwość CPU - 8 MHz */
  initTimer0();
  initUSART();

  BUTTON_PORT |= (1 << BUTTON);                    /* opornik podciagajacy dla przycisku */

  LED_DDR |= (1 << LED0);                    /* włacz diody LED dla diagnostyki */
  LED_PORT |= (1 << LED0);
  _delay_ms(100);
  LED_PORT &= ~(1 << LED0);

  SPEAKER_DDR |= (1 << SPEAKER);

  tuningWord = 880;
  transmitByte((uint8_t) tuningWord >> 2);       /* przybliżona wartość w Hz */

  // ------ Pętla zdarzeń ------ //
  while (1) {

    pollButton();

  }                                                  /* Koniec pętli zdarzeń */
  return (0);                            /* Ta instrukcja nie zostanie wykonana */
}
