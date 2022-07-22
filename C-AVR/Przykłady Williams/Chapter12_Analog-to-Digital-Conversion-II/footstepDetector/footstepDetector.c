/*
 * Czujnik wykrywający kroki i przykład zastosowania
 * wykładniczo ważonej średniej kroczącej
 */

// ------- Preambula -------- //
#include <avr/io.h>
#include <util/delay.h>
#include <avr/sleep.h>
#include "pinDefines.h"
#include "USART.h"

#define ON_TIME            2000                                 /* milisekundy */
#define CYCLE_DELAY          10                                 /* milisekundy */
#define INITIAL_PADDING  16              /* wyższa wartość to mniejsza czułość */

#define SWITCH              PB7     /* Tutaj podłącz diodę LED albo przekaźnik */

#define USE_POT               0     /* zmień na 1 jeżeli używasz potencjometru */
#if USE_POT
#define POT               PC5                  /* opcjonalny pin potencjometru */
#endif

// -------- Funkcje --------- //
void initADC(void) {
  ADMUX |= (1 << REFS0);                      /* napięcie referencyjne to AVCC */
  ADCSRA |= (1 << ADPS1) | (1 << ADPS2);   /* podzielnik zegara konwertera /64 */
  ADCSRA |= (1 << ADEN);                                 /* włącz konwerter AC */
}

uint16_t readADC(uint8_t channel) {
  ADMUX = (0b11110000 & ADMUX) | channel;
  ADCSRA |= (1 << ADSC);
  loop_until_bit_is_clear(ADCSRA, ADSC);
  return (ADC);
}

int main(void) {
  // -------- Inicjalizacja --------- //
  uint16_t lightsOutTimer = 0;                      /* czasomierz przełącznika */
  uint16_t adcValue;
  uint16_t middleValue = 511;
  uint16_t highValue = 520;
  uint16_t lowValue = 500;
  uint16_t noiseVolume = 0;
  uint8_t padding = INITIAL_PADDING;

  LED_DDR = ((1 << LED0) | (1 << LED1) | (1 << SWITCH));
  initADC();
  initUSART();

  // ------ Pętla zdarzeń ------ //
  while (1) {
    adcValue = readADC(PIEZO);

                    /* średnia krocząca -- wyznacza napięcie środkowe czujnika */
    middleValue = adcValue + middleValue - ((middleValue - 8) >> 4);
                   /* średnie kroczące dla dodatnich i ujemnych części sygnału */
    if (adcValue > (middleValue >> 4)) {
      highValue = adcValue + highValue - ((highValue - 8) >> 4);
    }
    if (adcValue < (middleValue >> 4)) {
      lowValue = adcValue + lowValue - ((lowValue - 8) >> 4);
    }
                  /* "dopełnienie" definiuje minimalną wartość amplitudy szumu */
    noiseVolume = highValue - lowValue + padding;

          /* Teraz sprawdzamy, czy wartość z czujnika leży pod lub nad progiem */
                 /* Porównanie z wartością >> 4 ponieważ średnia ma inną skalę */
    if (adcValue < ((middleValue - noiseVolume) >> 4)) {
      LED_PORT = (1 << LED0) | (1 << SWITCH);       /* włącz diodę, przekaźnik */
      lightsOutTimer = ON_TIME / CYCLE_DELAY;              /* zeruj czasomierz */
    }
    else if (adcValue > ((middleValue + noiseVolume) >> 4)) {
      LED_PORT = (1 << LED1) | (1 << SWITCH);        /* inna dioda, przekaźnik */
      lightsOutTimer = ON_TIME / CYCLE_DELAY;              /* zeruj czasomierz */
    }
    else {                                 /* Nic nie widać, wyłączamy światła */
      LED_PORT &= ~(1 << LED0);
      LED_PORT &= ~(1 << LED1);                           /* wyłącz obie diody */
      if (lightsOutTimer > 0) {                  /* ile jeszcze zostało czasu? */
        lightsOutTimer--;
      }
      else {                                                   /* czas upłynął */
        LED_PORT &= ~(1 << SWITCH);                    /* wyłączamy przekaźnik */
      }
    }
#if USE_POT                /* opcjonalny potencjometr wyznaczajacy dopełnienie */
    padding = readADC(POT) >> 4;           /* przeskaluj do właściwego zakresu */
#endif
                                            /* wyjście szeregowe i oczekiwanie */
        /* Konwerter AC ma 10 bitów, na potrzeby wyświetlania wyśrodkuj na 127 */
    transmitByte(adcValue - 512 + 127);
    transmitByte((lowValue >> 4) - 512 + 127);
    transmitByte((highValue >> 4) - 512 + 127);
    _delay_ms(CYCLE_DELAY);
  }                                                    /* Koniec pętli zdarzeń */
  return (0);                           /* ta instrukcja nie zostanie wykonana */
}
