                                                           /* Błyskające diody */

// ------- Preambuła -------- //
#include <avr/io.h>                             /* Definiuje piny, porty, itd. */
#include <util/delay.h>                              /* Funkcje marnujące czas */


int main(void) {

  // -------- Inicjalizacja --------- //
  DDRB |= (1 << PB0);           /* Rejestr kierunku danych portu B:
                                   wpisanie jedynki do bitu 
                                   włącza tryb wyjścia. */

  // ------ Pętla zdarzeń ------ //
  while (1) {

    PORTB = 0b00000001;          /* Włączenie pierwszej diody/pinu na porcie B */
    _delay_ms(1000);                                                 /* czekaj */

    PORTB = 0b00000000;    /* Wyłączenie wszystkich pinów portu B, w tym diody */
    _delay_ms(1000);                                                 /* czekaj */

  }                                                    /* koniec pętli zdarzeń */
  return (0);                            /* To polecenie nie zostanie wykonane */
}
