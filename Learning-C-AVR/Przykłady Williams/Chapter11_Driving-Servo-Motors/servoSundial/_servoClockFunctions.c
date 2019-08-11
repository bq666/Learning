

// Funkcje obsługi zegara czasu rzeczywistego
void initTimer0_Clock(void) {
           /* Trybu normalnego używamy do wywoływania przerwania przepełnienia */
  TCCR0B |= (1 << CS00);        /* zegar 8 MHz = ~31250 przepełnień na sekundę */
  TIMSK0 |= (1 << TOIE0);       /* włączenie przerwania przepełnienia licznika */
}

ISR(TIMER0_OVF_vect) {
           /* Ta funkcja będzie wywoływane bardzo często, więc musi być krótka */
  ticks++;
}
void everySecond(void) {
  seconds++;
  if (seconds > 59) {
    seconds = 0;
    everyMinute();
  }
  LED_PORT ^= (1 << LED0);                                          /* błyśnij */
  printTime(hours, minutes, seconds);                     /* wyjście szeregowe */
                         /* Wyłącz serwomotor po trzech sekundach nowej minuty */
  if (seconds == 3) {
    disableServo();
  }
}
void everyMinute(void) {
  minutes++;
  if (minutes > 59) {
    minutes = 0;
    everyHour();
  }
  // Jeżeli jesteśmy w czasie pracy, to przestaw serwomotor na nową minutę
  // Poza tym, nie trzeba ruszać motoru skoro laser jest wyłączony
  if ((hours >= START_TIME) && (hours < STOP_TIME)) {
    setServoPosition();
    enableServo();
    LASER_PORT |= (1 << LASER);         /* upewnij się, że laser jest włączony */
  }
  else {                               /* upewnij się, że laser jest wyłączony */
    LASER_PORT &= ~(1 << LASER);
  }
}
void everyHour(void) {
  hours++;
  if (hours > 23) {                          /* Na koniec dnia wyzeruj licznik */
    hours = 0;
  }
}
