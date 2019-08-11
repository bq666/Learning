// Bardzo proste oświetlenie nocne z regulacją.

// ------- Preambuła -------- //
#include <avr/io.h>
#include <util/delay.h>
#include "pinDefines.h"

uint16_t readADC(uint8_t channel) {
  ADMUX = (0xf0 & ADMUX) | channel;
  ADCSRA |= (1 << ADSC);
  loop_until_bit_is_clear(ADCSRA, ADSC);
  return (ADC);
}

int main(void) {
  // -------- Inicjalizacja --------- //
  uint16_t lightThreshold;
  uint16_t sensorValue;
  // konfiguracja konwertera AC
  ADMUX |= (1 << REFS0);                  /* napięcie referencyjne z AVCC */
  ADCSRA |= (1 << ADPS1) | (1 << ADPS0);           /* preskaler zegara /8 */
  ADCSRA |= (1 << ADEN);                            /* włącz konwerter AC */

  LED_DDR = 0xff;
  // ------ Pętla zdarzeń ------ //
  while (1) {

    lightThreshold = readADC(POT);
    sensorValue = readADC(LIGHT_SENSOR);

    if (sensorValue < lightThreshold) {
      LED_PORT = 0xff;
    }
    else {
      LED_PORT = 0x00;
    }
  }                                               /* Koniec pętli zdarzeń */
  return (0);                      /* Ta instrukcja nie zostanie wykonana */
}
