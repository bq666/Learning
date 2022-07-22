//  Przyklad gadającego woltomierza

#include <inttypes.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/pgmspace.h>
#include <avr/power.h>
#include "pinDefines.h"
#include "USART.h"

#include "talkingVoltmeter.h"

void startSampleTimer(void) {
  sampleNumber = 0;                       /* powrót na początek tablicy próbek */
  TCCR2B = (1 << CS21);                           /* włączenie zegara licznika */
      /* powyższe opcje generują częstotliwość ~8kHz w systemie z zegarem 8MHz */
}
void stopSampleTimer(void) {
  TCCR2B = 0;                              /* wyłącz zegar odtwarzający próbki */
  OCR0A = 128;              /* spoczynkowa wartość PWM przy napięciu środkowym */
  lastout = 0;                                /* następnym razem zaczynaj od 0 */
}
void speak(void) {
  startSampleTimer();
  loop_until_bit_is_clear(TCCR2B, CS21);           /* czekaj aż do zakończenia */
}

void updatePWMAudio(void) {
  OCR0A = out + 128;                /* wyśrodkowanie wartości w zakresie 0-255 */
  lastout = out;                               /* zaktualizuj ostatnią wartość */
  sampleNumber++;                               /* przejdź do następnej próbki */
}
void unpackByte(uint8_t dataByte) {
                                   /* wybiera pary bitów z bajtu i zapisuje je */
  differentials[0] = (dataByte >> 6) & 0b00000011;
  differentials[1] = (dataByte >> 4) & 0b00000011;
  differentials[2] = (dataByte >> 2) & 0b00000011;
  differentials[3] = (dataByte & 0b00000011);
}

/* Licznik 2 steruje szybkością odtwarzania.
   Przerwanie czyta nowe dane, i ładuje wartości PWM do rejestru OCR0A */
ISR(TIMER2_COMPA_vect) {
  /* Skoro możemy na raz dekodować 4 2-bitowe wartości, musimy wiedzieć
     gdzie znajdujemy się w tym 4-krokowym minicyklu. */
  uint8_t cycle = sampleNumber & 0b00000011;       /* zachowaj 2 ostatnie bity */
  uint16_t tableEntry;
  uint8_t packedData;

  if (cycle == 0) {                  /* przy pierwszej próbce załaduj ponownie */
    tableEntry = sampleNumber >> 2;                /* gdzie jesteśmy w tablicy */
    if (tableEntry < thisTableLength) {
                                  /* odczytaj następny bajt z wybranej tablicy */
      packedData = pgm_read_byte(&thisTableP[tableEntry]);
      unpackByte(packedData);     /* podziel bajt na części do differentials[] */
    }
    else {                                /* przy końcu tablicy zakończ pracę. */
      stopSampleTimer();
    }
  }
                  /* Dekodowanie różnic: aktualna wartość = ostatnia + różnica */
  out = lastout + dpcmWeights[differentials[cycle]] - (lastout >> 4);
  updatePWMAudio();
}                               // koniec przerwania (TIMER2_COMPA_vect)

void printString_Progmem(const char *stringP) {
  char oneLetter;
  while ((oneLetter = pgm_read_byte(stringP))) {
    transmitByte(oneLetter);
    stringP++;
  }
}


int main(void) {
  uint16_t voltage;
  uint8_t volts;
  uint8_t tenths;
  uint8_t vcc = 51;                                      /* 10x VCC, w woltach */

  clock_prescale_set(clock_div_1);                                    /* 8 MHz */
  initTimer0();
  initTimer2();
  sei();                                  /* na potrzeby przerwania licznika 2 */
  initADC();
  initUSART();

  printString_Progmem(PSTR("\r\n--=( Gadający woltomierz )=--\r\n"));

  selectTable(INTRO);
  speak();

  while (1) {

    ADCSRA |= (1 << ADSC);                             /* uruchom konwerter AC */
    loop_until_bit_is_clear(ADCSRA, ADSC);

    voltage = ADC * vcc + vcc / 2;            /* vcc/2 pozwala na zaokrąglanie */
    voltage = voltage >> 10;              /* podziel przez 10-bitów konwertera */
                   /* "voltage" przechowuje 10-krotność rzeczywistego napięcia */
    volts = voltage / 10;
    tenths = voltage % 10;

    transmitByte('0' + volts);          /* wypisz wartość przez port szeregowy */
    selectTable(volts);                 /* 0 wskazuje tablicę ZERO_TABLE, itd. */
    speak();

    transmitByte('.');
    selectTable(POINT);
    speak();

    transmitByte('0' + tenths);
    selectTable(tenths);
    speak();

    printString_Progmem(PSTR("  woltow\r\n"));
    selectTable(VOLTS);
    speak();

    _delay_ms(SPEECH_DELAY);

  }                                                            /* koniec pętli */
  return (0);
}
