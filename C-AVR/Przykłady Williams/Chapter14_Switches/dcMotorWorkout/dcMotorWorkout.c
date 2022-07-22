 /* Sterowanie silnikiem prądu stałego za pomocą modulacji szerokości impulsów */

// ------- Preambuła -------- //
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "pinDefines.h"
#include "USART.h"

#define SPEED_STEP_DELAY 2                                      /* milisekundy */

// -------- Funkcje --------- //
static inline void initTimer0(void) {
  TCCR0A |= (1 << WGM00);                                   /* Szybki tryb PWM */
  TCCR0A |= (1 << WGM01);                          /* szybki tryb PWM, część 2 */
  TCCR0A |= (1 << COM0B1);                       /* wyjście PWM skieruj na pin */
  TCCR0B |= (1 << CS02);                        /* zegar z podzielnikiem /1024 */
  //TCCR0B |= (1 << CS00);             /* zegar z podzielnikiem /1024, część 2 */
}


int main(void) {

  uint8_t updateSpeed;

  // -------- Inicjalizacja --------- //
  initTimer0();
  OCR0B = 0;

  ANTENNA_DDR |= (1 << ANTENNA);   /* wyjście, teraz podłączone do tranzystora */
  LED_DDR |= (1 << LED0);
  LED_DDR |= (1 << LED1);

  initUSART();
	printString("Ćwiczenia z silnikiem prądu stałego\r\n");

  // ------ Pętla zdarzeń ------ //
  while (1) {

    updateSpeed = getNumber();

                                   /* zmieniaj wybraną prędkość w górę i w dół */
    if (OCR0B < updateSpeed) {
      LED_PORT |= (1 << LED0);
      while (OCR0B < updateSpeed) {
        OCR0B++;
        _delay_ms(SPEED_STEP_DELAY);
      }
    }
    else {
      LED_PORT |= (1 << LED1);
      while (OCR0B > updateSpeed) {
        OCR0B--;
        _delay_ms(SPEED_STEP_DELAY);
      }
    }
    LED_PORT = 0;                                           /* wyłącz wszystko */

  }                                                    /* Koniec pętli zdarzeń */
  return (0);                           /* ta instrukcja nie zostanie wykonana */
}
