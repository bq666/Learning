                                   /* Trzeci krok do używania pamięci programu */
                                        /* Przekazywanie wskaźników do funkcji */

#include <avr/io.h>
#include <util/delay.h>
#include <avr/pgmspace.h>
#include "USART.h"

const char myVeryLongString[] PROGMEM = "\r\nWitajcie, \
to jest przyklad bardzo dlugiego ciagu znakow.\r\n\
Dokladnie taki, jakiego nie chcemy przechowywac w pamieci RAM.\r\n";
const char myVeryLongString2[] PROGMEM = "Jesli wejdziesz między wrony,\
musisz krakac jakos tam.\r\n";

void printString_Progmem(const char *stringP) {
  char oneLetter;
  while ((oneLetter = pgm_read_byte(stringP))) {
    transmitByte(oneLetter);
    stringP++;
    _delay_ms(100);                                     /* bo tak jest ładniej */
  }
}

int main(void) {
  initUSART();
  while (1) {
    printString_Progmem(&myVeryLongString1[0]);
    printString_Progmem(&myVeryLongString1[50]);
    printString_Progmem(myVeryLongString2);
    _delay_ms(1000);
  }                                                    /* koniec pętli zdarzeń */
  return (0);                           /* ta instrukcja nie zostanie wykonana */
}
