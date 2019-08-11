                                    /* Drugi krok do używania pamięci programu */
                                      /* Przechowywanie adresów we wskaźnikach */

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

  const char *stringPointer;
  const uint16_t *wordPointer;
  uint8_t i;
  char oneLetter;

  stringPointer = &myVeryLongString[0];              /* adres pierwszego znaku */
  // stringPointer = myVeryLongString;                   /* to samo co powyżej */
  wordPointer = &sixteenBits;                        /* adres pierwszego bajtu */

  while (1) {
    for (i = 0; i < sizeof(myVeryLongString); i++) {
      oneLetter = pgm_read_byte(stringPointer + i);
      transmitByte(oneLetter);
      _delay_ms(100);  /* pauza symulująca wpisywanie tekstu na klawiaturze :) */
    }
    _delay_ms(1000);

    printWord(pgm_read_word(wordPointer));
  }                                                    /* koniec pętli zdarzeń */
  return (0);                           /* ta instrukcja nie zostanie wykonana */
}
