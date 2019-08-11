                                 /* Pierwszy krok do używania pamięci programu */

#include <avr/io.h>
#include <util/delay.h>
#include <avr/pgmspace.h>
#include "USART.h"

const char myVeryLongString[] PROGMEM = "\r\nWitajcie, \
to jest przyklad bardzo dlugiego ciagu znakow.\r\n\
Dokladnie taki, jakiego nie chcemy przechowywac w pamieci RAM.\r\n";
const uint16_t sixteenBits PROGMEM = 12345;

int main(void) {
  initUSART();
  char oneLetter;
  uint8_t i;

  while (1) {
    for (i = 0; i < sizeof(myVeryLongString); i++) {
      oneLetter = pgm_read_byte(&(myVeryLongString[i]));
      transmitByte(oneLetter);
      _delay_ms(100);  /* pauza symulująca wpisywanie tekstu na klawiaturze :) */
    }
    _delay_ms(1000);

    printWord(&sixteenBits);   /* tutaj pojawia się ostrzeżenie kompilatora... */
    transmitByte('\r');
    transmitByte('\n');
    printWord(pgm_read_word(&sixteenBits));
  }                                                    /* koniec pętli zdarzeń */
  return (0);                           /* ta instrukcja nie zostanie wykonana */
}
