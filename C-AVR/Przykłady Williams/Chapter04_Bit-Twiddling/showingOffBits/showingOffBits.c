              /* Ćwiczymy manipulowanie bitami i trochę się popisujemy */

// ------- Preambuła -------- //
#include <avr/io.h>
#include <avr/power.h>
#include <util/delay.h>                 /* Funkcje do marnowania czasu */

#define DELAYTIME 85                                   /* millisekundy */
#define LED_PORT                PORTB
#define LED_DDR                 DDRB

int main(void) {

  uint8_t i;
  uint8_t repetitions;
  uint8_t whichLED;
  uint16_t randomNumber = 0x1234;

  // -------- Inicjalizacja --------- //
  LED_DDR = 0xff;             /* Wszystkie piny ustawione jako wyjścia */
  // ------ Pętla zdarzeń ------ //
  while (1) {
                                                             /* W lewo */
    for (i = 0; i < 8; i++) {
      LED_PORT |= (1 << i);                       /* włącz pin numer i */
      _delay_ms(DELAYTIME);                                  /* czekaj */
    }
    for (i = 0; i < 8; i++) {
      LED_PORT &= ~(1 << i);                     /* wyłącz pin numer i */
      _delay_ms(DELAYTIME);                                  /* czekaj */
    }
    _delay_ms(5 * DELAYTIME);                                 /* pauza */

                                                            /* W prawo */
    for (i = 7; i < 255; i--) {
      LED_PORT |= (1 << i);                       /* włącz pin numer i */
      _delay_ms(DELAYTIME);                                  /* czekaj */
    }
    for (i = 7; i < 255; i--) {
      LED_PORT &= ~(1 << i);                     /* wyłącz pin numer i */
      _delay_ms(DELAYTIME);                                  /* czekaj */
    }
    _delay_ms(5 * DELAYTIME);                                 /* pauza */

                              /* Przez chwilę przełączaj "losowe" bity */
    for (repetitions = 0; repetitions < 75; repetitions++) {
                                         /* generator liczb "losowych" */
      randomNumber = 2053 * randomNumber + 13849;
                                      /* dolne trzy bity górnego bajtu */
      whichLED = (randomNumber >> 8) & 0b00000111;
      LED_PORT ^= (1 << whichLED);               /* przełącz diodę LED */
      _delay_ms(DELAYTIME);
    }
    LED_PORT = 0;                            /* wyłącz wszystkie diody */
    _delay_ms(5 * DELAYTIME);                                 /* pauza */

  }                                            /* koniec pętli zdarzeń */
  return (0);                   /* Ta instrukcja nie zostanie wykonana */
}
