/* Sterowany serwomotorem laserowy zegar słoneczny, prawie czasu rzeczywistego. */

// ------- Dołączane pliki -------- //
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/power.h>
#include "pinDefines.h"
#include "USART.h"
#include "servoSundial.h"
#include "_servoSerialHelpers.c"
#include "_servoClockFunctions.c"

// -------- Funkcje --------- //
// Funkcje konfigurujące serwomotor i użytkowe
void initTimer1_Servo(void) {
             /* Konfiguracja licznika 1 (16bit) do generowania impulsu do 20ms */
  TCCR1A |= (1 << WGM11);                         /* wybieramy szybki tryb PWM */
  TCCR1B |= (1 << WGM12);      /* w rejestrze ICR1 maksymalna wartość licznika */
  TCCR1B |= (1 << WGM13);
  TCCR1B |= (1 << CS11);               /* podzielnik /8 -- krok mikrosekundowy */
  TCCR1A |= (1 << COM1A1);     /* skieruj wyjście na PB1 / OC1A z serwomotorem */
  ICR1 = 20000;                                   /* wartość maksymalna = 20ms */
}

void enableServo(void) {
  while (TCNT1 < PULSE_OVER) {;
     }                            /* opóźnienie do zakończenia impulsu w cyklu */
  SERVO_DDR |= (1 << SERVO);                      /* włącz impulsy serwomotoru */
}

void disableServo(void) {
  while (TCNT1 < PULSE_OVER) {;
     }                            /* opóźnienie do zakończenia impulsu w cyklu */
  SERVO_DDR &= ~(1 << SERVO);                    /* wyłącz impulsy serwomotoru */
}

void setServoPosition(void) {
  uint32_t elapsedMinutes;
  /* 32 bity zmiennej elapsedMinutes * PULSE_RANGE przepełni licznik 16 bitowy */



  elapsedMinutes = (hours - START_TIME) * 60 + minutes;
  OCR1A = PULSE_MIN + elapsedMinutes * PULSE_RANGE / (HOURS_RANGE * 60);
  enableServo();
}

int main(void) {

  // -------- Inicjalizacja --------- //
  clock_prescale_set(clock_div_1);                        /* zegar CPU - 8 MHz */
  initUSART();
  printString("\r\nLaserowy zegar słoneczny.\r\n");
  printString("Wpisz S, żeby ustalić czas.\r\n");

  initTimer0_Clock();
  initTimer1_Servo();
  sei();                                                 /* włączenie przerwań */
  LED_DDR |= (1 << LED0);                              /* konfiguracja wyjścia */
  LASER_DDR |= (1 << LASER);                       /* włączenie wyjścia lasera */

  // ------ Pętla zdarzeń ------ //
  while (1) {

                                               /* Procedura sprawdzania zegara */
    if (ticks == OVERFLOWS_PER_SECOND) {
      ticks = 0;
      everySecond();
    }

    pollSerial();

  }                                                    /* Koniec pętli zdarzeń */
  return (0);                           /* ta instrukcja nie zostanie wykonana */
}
