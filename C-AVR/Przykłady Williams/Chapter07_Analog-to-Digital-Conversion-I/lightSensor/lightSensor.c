// Prosty przykład czujnika światła

// ------- Preambuła -------- //
#include <avr/io.h>
#include <util/delay.h>
#include "pinDefines.h"

// -------- Funkcje --------- //
static inline void initADC0(void) {
  ADMUX |= (1 << REFS0);            /* napięcie referencyjne pinu AVCC */
  ADCSRA |= (1 << ADPS2);                      /* preskaler zegara /16 */
  ADCSRA |= (1 << ADEN);                         /* włącz konwerter AC */
}

int main(void) {

  // -------- Inicjalizacja --------- //
  uint8_t ledValue;
  uint16_t adcValue;
  uint8_t i;

  initADC0();
  LED_DDR = 0xff;

  // ------ Pętla zdarzeń ------ //
  while (1) {

    ADCSRA |= (1 << ADSC);                        /* uruchom konwersję AC */
    loop_until_bit_is_clear(ADCSRA, ADSC); /* poczekaj na jej zakończenie */
    adcValue = ADC;                                     /* odczytaj wynik */
                 /* Z 10 bitów interesują nas tylko 3 (mamy tylko 8 diod) */
    ledValue = (adcValue >> 7);
                   /* Zapal diody zgodnie z wynikiem ze zmiennej ledValue */
    LED_PORT = 0;
    for (i = 0; i <= ledValue; i++) {
      LED_PORT |= (1 << i);
    }
    _delay_ms(50);
  }                                               /* koniec pętli zdarzeń */
  return (0);                      /* Ten kod nigdy nie zostanie wykonany */
}
