/* Woltomierz z konwertera AC
 * Ciągle wysyła zmierzone napięcie przez port szeregowy.
 */

// ------- Preambula -------- //
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>                 /* obsługa trybu uśpienia konwertera AC */
#include <math.h>                                 /* funkcje round() i floor() */

#include "pinDefines.h"
#include "USART.h"

/* Uwaga: Ten woltomierz jest tylko tak dokładny jak Twoje napięcie referencyjne.
 * Jeżeli chcesz uzyskać dokładność do czterech miejsc po przecinku, 
 *  to musisz dokładnie zmierzyć napięcie AVCC.
 * Zmierz wartość napięcia AVCC na pinie AREF i wprowadź je poniżej.
*/
#define REF_VCC 5.053
                                     /* zmierzona wartość podzielnika napięcia */
#define VOLTAGE_DIV_FACTOR  3.114


// -------- Funkcje --------- //
void initADC(void) {
  ADMUX |= (0b00001111 & PC5);        /* przełącz multiplekser na wejście ADC5 */
  ADMUX |= (1 << REFS0);                      /* napięcie referencyjne na AVCC */
  ADCSRA |= (1 << ADPS1) | (1 << ADPS2);   /* podzielnik zegara konwertera /64 */
  ADCSRA |= (1 << ADEN);                                 /* włącz konwerter AC */
}

void setupADCSleepmode(void) {
  set_sleep_mode(SLEEP_MODE_ADC);          /* zdefiniowane w pliku avr/sleep.h */
  ADCSRA |= (1 << ADIE);                   /* włączenie przerwań konwertera AC */
  sei();                                         /* włączenie systemu przerwań */
}

EMPTY_INTERRUPT(ADC_vect);

uint16_t oversample16x(void) {
  uint16_t oversampledValue = 0;
  uint8_t i;
  for (i = 0; i < 16; i++) {
    sleep_mode();                 /* procesor śpi, konwerter AC pobiera próbkę */
    oversampledValue += ADC;                             /* dodajemy 16 próbek */
  }
  return (oversampledValue >> 2);                /* dzielimy sumę przez cztery */
}

void printFloat(float number) {
  number = round(number * 100) / 100; /* zaokrąglenie do 2 miejsc po przecinku */
  transmitByte('0' + number / 10);                               /* dziesiątki */
  transmitByte('0' + number - 10 * floor(number / 10));           /* jednostki */
  transmitByte(',');
  transmitByte('0' + (number * 10) - floor(number) * 10);  /* dziesiąte części */
                                                               /* setne części */
  transmitByte('0' + (number * 100) - floor(number * 10) * 10);
  printString("\r\n");
}

int main(void) {

  float voltage;

  // -------- Inicjalizacja --------- //
  initUSART();
  printString("\r\nCyfrowy woltomierz\r\n\r\n");
  initADC();
  setupADCSleepmode();

  // ------ Pętla zdarzen ------ //

  while (1) {

    voltage = oversample16x() * VOLTAGE_DIV_FACTOR * REF_VCC / 4096;
    printFloat(voltage);
    /*  opcjonalnie możesz też wypisać tak:
     *  printWord(voltage*100);
     *  ale wtedy musisz pamiętać o miejscach po przecinku
     */
    _delay_ms(500);

  }                                                    /* Koniec pętli zdarzeń */
  return (0);                           /* ta instrukcja nie zostanie wykonana */
}
