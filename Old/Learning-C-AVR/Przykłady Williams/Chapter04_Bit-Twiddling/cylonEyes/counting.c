#include <avr/io.h>                        /* Definiuje piny, porty, itd. */
#define F_CPU 1000000UL          /* Ustala szybkość układu na potrzeby pliku delay.h */
#include <util/delay.h>                     /* Funkcje marnujące czas */

#define DELAYTIME 100

int main(void) {
  DDRB = 0b11111111;
  PORTB = 0;

  while (1) {
    PORTB = PORTB + 1;
    _delay_ms(DELAYTIME);
  }
}
