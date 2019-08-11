/*

Oczy cylonow świetnie nadają się do tworzenia efektu POV.
Jedyna zmiana dotyczy parametru DELAYTIME.

 */


#include <avr/io.h>                             /* Definiuje piny, porty, itd. */
#include <util/delay.h>                              /* Funkcje marnujące czas */

#define DELAYTIME 2                                             /* milisekundy */

int main(void) {
  uint8_t i;
  DDRB = 0b11111111;                        /* Rejestr DDRB: wszystko włączone */

  while (1) {

    while (i < 7) {
      PORTB = (1 << i);                      /* załączenie jedynie i-tego pinu */
      _delay_ms(DELAYTIME);                                        /* czekanie */
      i = i + 1;                               /* przejście do następnej diody */
    }

    while (i > 0) {
      PORTB = (1 << i);                      /* załączenie jedynie i-tego pinu */
      _delay_ms(DELAYTIME);                                        /* czekanie */
      i = i - 1;                               /* przejście do następnej diody */
    }
  }

  return (0);
}
