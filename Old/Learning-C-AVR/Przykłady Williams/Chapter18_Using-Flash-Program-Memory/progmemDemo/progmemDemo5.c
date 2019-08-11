                              /* Czwarty krok do używania pamięci programu */
                           /* przekazywanie wskaźników na tablice do funkcji */

#include <avr/io.h>
#include <util/delay.h>
#include <avr/pgmspace.h>
#include "USART.h"

const uint16_t myData[] PROGMEM =
    { 1111, 2222, 3333, 4444, 5555, 6666, 7777, 8888, 9999, 10000 };

const char string1[] PROGMEM = "Hej, ciag znakow!\r\n";
const char string2[] PROGMEM = "Kolejny ciag znakow!\r\n";
const char *const stringIndex[] PROGMEM = { string1, string2 };


void printData_Progmem(const uint16_t * dataPointer, uint8_t length) {
  while (length) {
    printWord((uint16_t) dataPointer);            /* wypisz adres */
    printString(":  ");
    printWord(pgm_read_word(dataPointer));           /* wypisz dane */
    printString("\r\n");
    dataPointer++;                                /* przejdź do następnego bajtu */
    length--;                                   /* jeden mniej w kolejce */
    _delay_ms(100);
  }
}
void printString_Progmem(const char *stringP) {
  char oneLetter;
  while ((oneLetter = pgm_read_byte(stringP))) {
    transmitByte(oneLetter);
    stringP++;
  }
}

int main(void) {
  initUSART();

  uint8_t myArray[] = { 10, 11, 12 };
  uint8_t *p;
  uint8_t i;
  p = &myArray[0];
  for (i = 0; i < sizeof(myArray); i++) {
    printByte(*(p + i));
    printString("\r\n");
    _delay_ms(1000);
  }


                                                       /* instrukcja użycia: */
  char *stringPointer;
                /* pobierz wskaźnik na ciąg znaków do pobrania z pamięci programu */

  stringPointer = (char *) pgm_read_word(&stringIndex[0]);
  printString_Progmem(stringPointer);
                                                                 /* albo */
  stringPointer = (char *) pgm_read_word(&stringIndex[1]);
  printString_Progmem(&stringPointer[0]);
                                                                 /* albo */
  printString_Progmem(PSTR("A ten ciag znakow jest zapisany w kodzie.\r\n"));

  while (1) {
    printData_Progmem(myData, sizeof(myData) / sizeof(myData[0]));
    printString("\r\n");
    _delay_ms(1000);
  }                                                  /* Koniec pętli zdarzeń */
  return (0);                            /* Ta instrukcja nie zostanie wykonana */
}
