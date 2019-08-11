                       /* Przykład obsługi silnika krokowego z przyspieszaniem */

// ------- Preambula -------- //
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/power.h>
#include "USART.h"

/* Tym definicjom nadaj wartość +/- 1 żeby stosować półkroki 
   albo wartość +/- 2 żeby stosować pełne kroki silnika */
#define FORWARD    1
#define BACKWARD  -1
#define TURN       400          /* liczba kroków na obrót
                                   zależy od modelu silnika */

    /* Te parametry są uzależnione do rodzaju silnika i sposobu jego działania */
#define MAX_DELAY    255            /* definiuje minimalną prędkość początkową */
#define MIN_DELAY     10              /* definiuje maksymalną prędkość silnika */
#define ACCELERATION  16        /* niższa wartość = płynniejsze przyspieszenie */

#define RAMP_STEPS    (MAX_DELAY - MIN_DELAY) / ACCELERATION

// -------- Zmienne globalne --------- //
const uint8_t motorPhases[] = {
  (1 << PB0) | (1 << PB2),                                       /* pełny krok */
  (1 << PB0),                                                     /* pół kroku */
  (1 << PB0) | (1 << PB3),                                       /* pełny krok */
  (1 << PB3),                                                     /* pół kroku */
  (1 << PB1) | (1 << PB3),                                             /* itd. */
  (1 << PB1),
  (1 << PB1) | (1 << PB2),
  (1 << PB2)
};

volatile uint8_t stepPhase = 0;
volatile int8_t direction = FORWARD;
volatile uint16_t stepCounter = 0;

// -------- Funkcje --------- //
void initTimer(void) {
  TCCR0A |= (1 << WGM01);                                          /* tryb CTC */
  TCCR0B |= (1 << CS00) | (1 << CS02);
  OCR0A = MAX_DELAY;                 /* ustal domyślną prędkość jako najniższą */
  sei();                                         /* globalnie włącz przerwania */
        /* Zauważ, że nie włączyliśmy jeszcze znacznika przerwania licznika 0. */
}

ISR(TIMER0_COMPA_vect) {
  stepPhase += direction;                              /* wykonaj krok w prawo */
  stepPhase &= 0b00000111;                    /* faza pozostaje w zakresie 0-7 */
  PORTB = motorPhases[stepPhase];           /* zapisz fazę do rejestru silnika */
  stepCounter++;                                     /* zliczaj wykonane kroki */
}

void takeSteps(uint16_t howManySteps, uint8_t delay) {
  UDR0 = delay;                  /* wyślij szybkość/opóźnienie, bez blokowania */
  OCR0A = delay;                 /* zapisz opóźnienie w rejestrze porównującym */
  stepCounter = 0;                      /* na razie nie zrobiliśmy nawet kroku */
  TIMSK0 |= (1 << OCIE0A);        /* włącz przerwania obsługujące ruch silnika */
  while (!(stepCounter == howManySteps)) {;
  }                                                                  /* czekaj */
  TIMSK0 &= ~(1 << OCIE0A);                               /* wyłącz przerwania */
}

void trapezoidMove(int16_t howManySteps) {
  uint8_t delay = MAX_DELAY;
  uint16_t stepsTaken = 0;

                            /* ustal kierunek sprawdzając czy howManySteps > 0 */
  if (howManySteps > 0) {
    direction = FORWARD;
  }
  else {
    direction = BACKWARD;
    howManySteps = -howManySteps;
  }

  if (howManySteps > (RAMP_STEPS * 2)) {
                                    /* Czy mamy dość kroków na jeden trapezoid */
                                                             /* przyspieszanie */
    while (stepsTaken < RAMP_STEPS) {
      takeSteps(1, delay);
      delay -= ACCELERATION;
      stepsTaken++;
    }
                                                             /* stała szybkość */
    delay = MIN_DELAY;
    takeSteps((howManySteps - 2 * RAMP_STEPS), delay);
    stepsTaken += (howManySteps - 2 * RAMP_STEPS);
                                                                 /* zwalnianie */
    while (stepsTaken < howManySteps) {
      takeSteps(1, delay);
      delay += ACCELERATION;
      stepsTaken++;
    }
  }
  else {
                                      /* Częściowe przyspieszenie i zwolnienie */
    while (stepsTaken <= howManySteps / 2) {
      takeSteps(1, delay);
      delay -= ACCELERATION;
      stepsTaken++;
    }
    delay += ACCELERATION;
    while (stepsTaken < howManySteps) {
      takeSteps(1, delay);
      delay += ACCELERATION;
      stepsTaken++;
    }
  }
}

int main(void) {
  // -------- Inicjalizacja --------- //
  clock_prescale_set(clock_div_1);                    /* zegar procesora 8 MHz */
  initUSART();
  _delay_ms(1000);
  initTimer();
  DDRB = (1 << PB0) | (1 << PB1) | (1 << PB2) | (1 << PB3);

  // ------ Pętla zdarzeń ------ //
  while (1) {

                                     /* Płynne ruchy, przyspieszanie trapezowe */
    trapezoidMove(2 * TURN);                               /* dwa pełne obroty */
    trapezoidMove(-TURN / 2);                                    /* pół obrotu */
    trapezoidMove(TURN / 4);                                  /* ćwierć obrotu */
    trapezoidMove(-TURN / 8);                             /* jedna ósma obrotu */
    _delay_ms(TURN);
    trapezoidMove(-TURN / 4);                          /* teraz w drugą stronę */
    trapezoidMove(TURN / 8);
    trapezoidMove(TURN / 2);              /* pół obrotu do pozycji początkowej */
    _delay_ms(1000);

  }                                                    /* Koniec pętli zdarzeń */
  return (0);                           /* ta instrukcja nie zostanie wykonana */
}
