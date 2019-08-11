/*
Odtwarza prostą melodię i wysyła ją na częstotliwości radiowej.
*/

// ------- Preambuła -------- //
#include <avr/io.h>                        /* Definicje pinów, portów itp. */
#include <util/delay.h>                          /* Funkcje marnujące czas */
#include <avr/power.h>
#include <avr/interrupt.h>
#include "pinDefines.h"
#include "scale16.h"

#define COUNTER_VALUE   3                /* definiuje częstotliwość nośnej */

// Ze wzoru f = f_cpu / ( 2* N* (1 + OCRnx) )
// Właściwe wartości dla pasma radiowego znajdują się w zakresie od 2 to 6:
// wybieramy tę ze środka przedziału
// Podzielimy ją przez 2, ponieważ w każdym obiegu przełączamy stan pinu
//  a pełny cykl wymaga dwóch obiegów licznika.
// 8Mhz / (2 * 1 * (1+2)) = 1333 kHz
// 8Mhz / (2 * 1 * (1+3)) = 1000 kHz
// 8Mhz / (2 * 1 * (1+4)) = 800 kHz
// 8Mhz / (2 * 1 * (1+5)) = 670 kHz
// 8Mhz / (2 * 1 * (1+6)) = 570 kHz
// 8Mhz / (2 * 1 * (1+7)) = 500 kHz

static inline void initTimer0(void) {
  TCCR0A |= (1 << WGM01);                                      /* tryb CTC */
  TCCR0A |= (1 << COM0B0);      /* Przełączanie stanu pinu po każdym cyklu */
  TCCR0B |= (1 << CS00);      /* Zegar działa z szybkością procesora ~8MHz */
  OCR0A = COUNTER_VALUE;                            /* częstotliwość nośna */
}

static inline void initTimer1(void) {
  TCCR1B |= (1 << WGM12);                                      /* tryb CTC */
  TCCR1B |= (1 << CS11);            /* zegar ma częstotliwość CPU/8, ~1MHz */
  TIMSK1 |= (1 << OCIE1A);      /* włącz przerwania rejestru porównującego */
}

ISR(TIMER1_COMPA_vect) {   /* Przerwanie rejestru porównującego licznika 1 */
  ANTENNA_DDR ^= (1 << ANTENNA);                 /* włącz lub wyłącz nośną */
}

static inline void transmitBeep(uint16_t pitch, uint16_t duration) {
  OCR1A = pitch;                  /* ustal wysokość dźwięku dla licznika 1 */
  sei();                                               /* włącz przerwania */
  do {
    _delay_ms(1);               /* opóźnienie pozwalające odtworzyć dźwięk */
    duration--;
  } while (duration > 0);
  cli();                   /* wyłącz przerwania, tak żeby zatrzymać dźwięk */
  ANTENNA_DDR |= (1 << ANTENNA);                   /* ponownie włącz nośną */
}

int main(void) {
  // -------- Inicjalizacja --------- //

  clock_prescale_set(clock_div_1);              /* zegar procesora = 8 MHz */
  initTimer0();
  initTimer1();

  // ------ Pętla zdarzeń ------ //
  while (1) {

    transmitBeep(E3, 200);
    _delay_ms(100);
    transmitBeep(E3, 200);
    _delay_ms(200);
    transmitBeep(E3, 200);
    _delay_ms(200);
    transmitBeep(C3, 200);
    transmitBeep(E3, 200);
    _delay_ms(200);
    transmitBeep(G3, 400);
    _delay_ms(500);
    transmitBeep(G2, 400);

    _delay_ms(2500);

  }                                                /* koniec pętli zdarzeń */
  return (0);                       /* ta instrukcja nie zostanie wykonana */
}
