/*
   Program czujnika pojemnościowego
*/

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/power.h>
#include "pinDefines.h"
#include "USART.h"

#define SENSE_TIME   50
#define THRESHOLD    12000

// -------  Zmienne globalne ---------- //
volatile uint16_t chargeCycleCount;

// ------- Funkcje -------- //

void initPinChangeInterrupt(void) {
  PCICR |= (1 << PCIE1);         /* włącz przerwania zmiany stanu (bank C) */
  PCMSK1 |= (1 << PC1);             /* włącz przerwania tylko dla pinu PC1 */
}

ISR(PCINT1_vect) {
  chargeCycleCount++;                                   /* zliczanie cykli */

  CAP_SENSOR_DDR |= (1 << CAP_SENSOR);                     /* tryb wyjścia */
  _delay_us(1);                                    /* opóźnienie ładowania */

  CAP_SENSOR_DDR &= ~(1 << CAP_SENSOR);                    /* tryb wejścia */
  PCIFR |= (1 << PCIF1);            /* wyczyść bit przerwania zmiany stanu */
}


int main(void) {
  // -------- Inicjalizacja --------- //
  clock_prescale_set(clock_div_1);                       /* pełna prędkość */
  initUSART();
  printString("==[ Cap Sensor ]==\r\n\r\n");

  LED_DDR = 0xff;
  MCUCR |= (1 << PUD);           /* wyłącz wszystkie oporniki podciągające */
  CAP_SENSOR_PORT |= (1 << CAP_SENSOR);   /* wyjście może mieć stan wysoki */

  initPinChangeInterrupt();

  // ------ Pętla zdarzeń ------ //
  while (1) {

    chargeCycleCount = 0;                            /* zerowanie licznika */
    CAP_SENSOR_DDR |= (1 << CAP_SENSOR);  /* zaczynamy z naładowanym kond. */
    sei();                                 /* włącz przerwania i zliczanie */
    _delay_ms(SENSE_TIME);
    cli();                                                       /* gotowe */
    if (chargeCycleCount < THRESHOLD) {
      LED_PORT = 0xff;
    }
    else {
      LED_PORT = 0;
    }
    printWord(chargeCycleCount);                             /* do analizy */
    printString("\r\n");

  }                                                /* koniec pętli zdarzeń */
  return (0);                       /* ta instrukcja nie zostanie wykonana */
}
