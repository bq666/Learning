/* Funkcje formatowania danych wysyłanych i odbieranych przez port szeregowy */

void printTime(uint8_t hours, uint8_t minutes, uint8_t seconds) {
  printByte(hours);
  transmitByte(':');
  printByte(minutes);
  transmitByte(':');
  printByte(seconds);
  transmitByte('\r');
  transmitByte('\n');
}

void pollSerial(void) {
                       /* Sprawdź wejście portu, żeby nastawić czas w zegarze. */
  char input;
  if (bit_is_set(UCSR0A, RXC0)) {
    input = UDR0;
    if (input == 'S') {                     /* wejście w tryb ustawiania czasu */
      printString("Ustawianie czasu...\r\n");
      printString("Godzina: ");
      hours = getNumber();
      printString("\r\nMinuty: ");
      minutes = getNumber();
      printString("\r\nSekundy: ");
      seconds = getNumber();
      printString("\r\n");
      ticks = 0;
      if ((hours >= START_TIME) && (hours < STOP_TIME)) {
        setServoPosition();
      }
    }
  }
}
