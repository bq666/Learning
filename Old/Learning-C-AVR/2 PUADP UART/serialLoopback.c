/*
Prosty test działania portu szeregowego.
Pobiera po jednym znaku i od razu wysyła go z powrotem,
przy okazji wyświetlając wartość ASCII za pomocą diod LED.
*/

// ------- Preambuła -------- //
#include <avr/io.h>
#include <util/delay.h>
#include "pinDefines.h"
#include "USART.h"

int main(void) {
  char serialCharacter;

  // -------- Inicjalizacja --------- //
  LED_DDR = 0xff;                /* skonfiguruj diody LED jako wyjścia */
  initUSART();
  printString("Witaj, świecie!\r\n");                 /* to tylko test */

  // ------ Pętla zdarzeń ------ //
  while (1) {

    serialCharacter = receiveByte();
    transmitByte(serialCharacter);
    LED_PORT = serialCharacter;
                      /* wyświetlanie wartości ASCII odebranych znaków */

  }                                            /* koniec pętli zdarzeń */
  return (0);
}
