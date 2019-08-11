                                                       /* Oczy Cylonów */

// ------- Preambuła -------- //
#include <avr/io.h>                     /* Definiuje piny, porty, itd. */
#include <util/delay.h>                      /* Funkcje marnujące czas */

#define DELAYTIME 85                                    /* milisekundy */
#define LED_PORT                PORTB
#define LED_PIN                 PINB
#define LED_DDR                 DDRB

int main(void) {

  // -------- Inicjalizacja --------- //
  uint8_t i;
  LED_DDR = 0xff;               /* Rejestr kierunku danych B:
                                   całość ustawiamy jako wyjście */

  // ------ Pętla zdarzeń ------ //
  while (1) {

    while (i < 7) {
      LED_PORT = (1 << i);                  /* zaświeć wyłącznie pin i */
      _delay_ms(DELAYTIME);                                  /* czekaj */
      i = i + 1;                         /* przejdź do następnej diody */
    }

    while (i > 0) {
      LED_PORT = (1 << i);                  /* zaświeć wyłącznie pin i */
      _delay_ms(DELAYTIME);                                  /* czekaj */
      i = i - 1;                         /* przejdź do następnej diody */
    }

  }                                            /* koniec pętli zdarzeń */
  return (0);
}
