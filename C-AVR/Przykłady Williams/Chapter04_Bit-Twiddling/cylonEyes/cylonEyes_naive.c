#include <avr/io.h>                        /* Definiuje piny, porty, itd. */
#define F_CPU 1000000UL          /* Ustala szybkość układu na potrzeby pliku delay.h */
#include <util/delay.h>                     /* Funkcje marnujące czas */

#define DELAYTIME 75                                   /* milisekundy */

int main(void) {

  DDRB = 0b11111111;           /* Rejestr DDRB
                                   wszystkie piny jako wyjście */

  while (1) {
    PORTB = 0b00000001;
    _delay_ms(DELAYTIME);
    PORTB = 0b00000010;
    _delay_ms(DELAYTIME);
    PORTB = 0b00000100;
    _delay_ms(DELAYTIME);
    PORTB = 0b00001000;
    _delay_ms(DELAYTIME);
    PORTB = 0b00010000;
    _delay_ms(DELAYTIME);
    PORTB = 0b00100000;
    _delay_ms(DELAYTIME);
    PORTB = 0b01000000;
    _delay_ms(DELAYTIME);
    PORTB = 0b10000000;
    _delay_ms(DELAYTIME);
    PORTB = 0b01000000;
    _delay_ms(DELAYTIME);
    PORTB = 0b00100000;
    _delay_ms(DELAYTIME);
    PORTB = 0b00010000;
    _delay_ms(DELAYTIME);
    PORTB = 0b00001000;
    _delay_ms(DELAYTIME);
    PORTB = 0b00000100;
    _delay_ms(DELAYTIME);
    PORTB = 0b00000010;
    _delay_ms(DELAYTIME);
  }
}
