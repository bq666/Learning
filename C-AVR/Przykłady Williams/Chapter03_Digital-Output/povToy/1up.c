/*
  Program POV autorstwa Patricka Roanhouse'a
*/

#include <avr/io.h>
#include <util/delay.h>
#define DELAYTIME 2                                              /* ms */

uint8_t Star1UP[] = {
  0b10000100,
  0b01101100,
  0b01111110,
  0b00011111,
  0b01111110,
  0b01101100,
  0b10000100,
  0b00000000,
  0b00000000,
  0b00000000,
  0b10000010,
  0b11111111,
  0b11111111,
  0b10000000,
  0b00000000,
  0b00000000,
  0b01111111,
  0b11111111,
  0b10000000,
  0b11111111,
  0b01111111,
  0b00000000,
  0b00000000,
  0b11111111,
  0b11111111,
  0b00110011,
  0b00110011,
  0b00011110,
  0b00011110,
};


int main(void) {
  uint8_t i;

  DDRB = 0xff;                                                 /* same wyjścia */

  while (1) {                                                  /* pętla główna */
    for (i = 0; i <= sizeof(Star1UP); ++i) {
           /* sizeof(Star1UP) zwraca liczbę bitów w tablicy */
      PORTB = Star1UP[i];
      _delay_ms(DELAYTIME);
    }

    PORTB = 0;                /* zerowanie tworzy przerwę między powtórzeniami */
    _delay_ms(5 * DELAYTIME);

  }                                                    /* koniec pętli głównej */
  return (0);
}
