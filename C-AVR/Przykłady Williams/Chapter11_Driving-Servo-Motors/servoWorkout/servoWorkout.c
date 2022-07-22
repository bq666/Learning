/* Interaktywny przykład sterowania serwomotorem za pomocą licznika 1 */

// ------- Preambuła -------- //
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "pinDefines.h"
#include "USART.h"

#define PULSE_MIN         1000             /* eksperymentuj z tymi wartościami */
#define PULSE_MAX         2000            /* dopasowując je do swojego silnika */
#define PULSE_MID         1500

static inline uint16_t getNumber16(void);

static inline void initTimer1Servo(void) {
         /* Konfiguracja licznika 1 (16 bitów) do generowania impulsów co 20ms */
  /* Używamy szybkiego trybu PWM, maksymalną wartość licznika wpisując do ICR1 */
  TCCR1A |= (1 << WGM11);
  TCCR1B |= (1 << WGM12) | (1 << WGM13);
  TCCR1B |= (1 << CS10);        /* podzielnik /1 -- odliczamy w mikrosekundach */
  ICR1 = 20000;                                   /* wartość maksymalna = 20ms */
  TCCR1A |= (1 << COM1A1);           /* Bezpośrednie wyjście na pin PB1 / OC1A */
  DDRB |= (1 << PB1);                        /* konfiguracja pinu jako wyjście */
}

static inline void showOff(void) {
  printString("Środek\r\n");
  OCR1A = PULSE_MID;
  _delay_ms(1500);
  printString("Maksymalnie w prawo\r\n");
  OCR1A = PULSE_MIN;
  _delay_ms(1500);
  printString("Maksymalnie w lewo\r\n");
  OCR1A = PULSE_MAX;
  _delay_ms(1500);
  printString("Środek\r\n");
  OCR1A = PULSE_MID;
  _delay_ms(1500);
}

int main(void) {

  // -------- Inicjalizacja --------- //
  uint16_t servoPulseLength;
  OCR1A = PULSE_MID;                      /* Początkowo ustaw silnik na środku */
  initTimer1Servo();
  initUSART();
  printString("\r\nWitaj w przykładzie sterowania serwomotorem\r\n");
  showOff();

  // ------ Pętla zdarzeń ------ //
  while (1) {

    printString("\r\nWprowadź czterocyfrową długość impulsu:\r\n");
    servoPulseLength = getNumber16();

    printString("Do roboty...\r\n");
    OCR1A = servoPulseLength;
    DDRB |= (1 << PB1);                          /* ponownie włącz pin wyjścia */

    _delay_ms(1000);
    printString("Zwalniam...\r\n");
    while (TCNT1 < 3000) {;
    }                                       /* Poczekaj na zakończenie impulsu */
    DDRB &= ~(1 << PB1);                                 /* wyłącz pin wyjścia */

  }                                                    /* Koniec pętli zdarzeń */
  return (0);                           /* ta instrukcja nie zostanie wykonana */
}

static inline uint16_t getNumber16(void) {
  // Pobiera wartość PWM z portu szeregowego.
  // Odbiera znaki i zmienia je w liczbę
  char thousands = '0';
  char hundreds = '0';
  char tens = '0';
  char ones = '0';
  char thisChar = '0';

  do {
    thousands = hundreds;                             /* Przesunięcie wartości */
    hundreds = tens;
    tens = ones;
    ones = thisChar;
    thisChar = receiveByte();                             /* pobierz nowy znak */
    transmitByte(thisChar);                                            /* echo */
  } while (thisChar != '\r');

  transmitByte('\n');                                           /* nowy wiersz */
  return (1000 * (thousands - '0') + 100 * (hundreds - '0') +
          10 * (tens - '0') + ones - '0');
}
