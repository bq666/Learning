

// ------- Preambuła -------- //
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/power.h>

#include "pinDefines.h"
#include "USART.h"

#include "i2c.h"                                      /* funkcje protokołu i2c */
#include "25LC256.h"                                 /* obsługa pamięci EEPROM */

// -------- Definicje --------- //

#define LM75_ADDRESS_W 0b10010000
#define LM75_ADDRESS_R 0b10010001
#define LM75_TEMP_REGISTER           0b00000000
#define LM75_CONFIG_REGISTER         0b00000001
#define LM75_THYST_REGISTER          0b00000010
#define LM75_TOS_REGISTER            0b00000011

#define CURRENT_LOCATION_POINTER  0
        /* miejsce przechowywania wskaźnika aktualnej pozycji w pamięci EEPROM */
#define SECONDS_POINTER           2
                                /* tutaj wpisz opóźnienie wyrażone w sekundach */
#define MEMORY_START              4
                    /* miejsce rozpoczęcia protokołowania wartości temperatury */
#define MENU_DELAY                5
                      /* liczba sekund oczekiwania na pominięcie głównego menu */

// -------- Funkcje --------- //

static inline void printTemperature(uint8_t tempReading) {
                             /* temperatura zapisana jako 2x stopnie Celsiusza */
  printByte((tempReading >> 1));
  if (tempReading & 1) {
    printString(".5\r\n");
  }
  else {
    printString(".0\r\n");
  }
}

int main(void) {
  uint16_t secondsDelay;                  /* czas oczekiwania między odczytami */
  uint16_t currentMemoryLocation;         /* aktualna pozycja w pamięci EEPROM */
  uint16_t i;                          /* zmienna zliczająca pozycje w pamięci */
  uint8_t tempHighByte, tempLowByte, temperatureByte;    /* dane z układu LM75 */
  uint8_t enterMenu;                                      /* znacznik logiczny */

  // -------- Inicjalizacja --------- //
  clock_prescale_set(clock_div_1);                                    /* 8 MHz */
  initSPI();
  initI2C();
  initUSART();
  LED_DDR |= (1 << LED0);

                            /* załadowanie ostatnich wartości z pamięci EEPROM */
  secondsDelay = EEPROM_readWord(SECONDS_POINTER);

                          /* Opóźnienie pozwalające na włączenie głównego menu */
  printString("*** Nacisnij [m] w ciagu ");
  printByte(MENU_DELAY);
  printString(" sekund, zeby wejsc do menu. ***\r\n ");

  for (i = 0; i < MENU_DELAY; i++) {
    _delay_ms(1000);
  }

  if (bit_is_set(UCSR0A, RXC0) && (UDR0 == 'm')) {
    enterMenu = 1;
  }
  else {
    enterMenu = 0;
  }

  while (enterMenu) {
    printString("\r\n====[  Termomentr protokolujacy ]====\r\n  ");
    currentMemoryLocation = EEPROM_readWord(CURRENT_LOCATION_POINTER);
	printString(" W protokole znajduja sie ");
    printWord(currentMemoryLocation - MEMORY_START);
    printString(" odczyty temperatury.\r\n");
	printString(" Odstep czasowy miedzy odczytami wynosi.");
    printWord(secondsDelay);
    printString(" sekund.\r\n");
    printString(" [<] zmniejsza odstep czasowy miedzy probkami\r\n");
    printString(" [>] zwieksza odstep czasowy miedzy probkami\r\n");
    printString(" [?] przywraca domyslny odstep czasowy (60 sek)\r\n");
    printString(" [d] wypisuje protokol przez port szeregowy\r\n");
    printString(" [e] czysci pamiec\r\n");
    printString(" [s] rozpoczyna protokolowanie\r\n\r\n");

    switch (receiveByte()) {
    case 'd':
      SLAVE_SELECT;
      SPI_tradeByte(EEPROM_READ);
      EEPROM_send16BitAddress(MEMORY_START);
      for (i = MEMORY_START; i < currentMemoryLocation; i++) {
        SPI_tradeByte(0);
        printTemperature(SPDR);
      }
      SLAVE_DESELECT;
      break;
    case '<':
      if (secondsDelay >= 10) {
        secondsDelay -= 5;
        EEPROM_writeWord(SECONDS_POINTER, secondsDelay);
      }
      break;
    case '>':
      if (secondsDelay < 65000) {
        secondsDelay += 5;
        EEPROM_writeWord(SECONDS_POINTER, secondsDelay);
      }
      break;
    case '?':
      secondsDelay = 60;
      EEPROM_writeWord(SECONDS_POINTER, secondsDelay);
      break;
    case 'e':
      printString("Czyszczenie pamiecie EEPROM moze zajac kilka sekund.\r\n");
      EEPROM_clearAll();
      EEPROM_writeWord(CURRENT_LOCATION_POINTER, MEMORY_START);
      EEPROM_writeWord(SECONDS_POINTER, secondsDelay);
      break;
    case 's':
      printString("Zaczynam protokolowanie...\r\n");
      enterMenu = 0;
      break;
    default:
      printString("Prosze? Tego nie rozumiem.\r\n");
    }
  }

  // ------ Pętla zdarzeń ------ //
  while (1) {

    currentMemoryLocation = EEPROM_readWord(CURRENT_LOCATION_POINTER);

                      /* Upewnij się, że działamy w trybie odczytu temperatury */
    i2cStart();
    i2cSend(LM75_ADDRESS_W);
    i2cSend(LM75_TEMP_REGISTER);
                                                /* pobierz wartość temperatury */
    i2cStart();                    /* Przygotuj i wyślij adres z bitem odczytu */
    i2cSend(LM75_ADDRESS_R);
    tempHighByte = i2cReadAck();            /* dwa bajty opisujące temperaturę */
    tempLowByte = i2cReadNoAck();
    i2cStop();
    temperatureByte = (tempHighByte << 1) | (tempLowByte >> 7);
                                          /* temperatureByte przechowuje teraz 
                                   podwojoną temperaturę w stopniach Celsjusza */
    printTemperature(temperatureByte);            /* wyjście na port szeregowy */

                                          /* zachowaj nową wartość temperatury */
    EEPROM_writeByte(currentMemoryLocation, temperatureByte);

    /* przejdź do następnej lokalizacji i zachowaj wskaźnik na tę pozycję
       chyba że skończyła się już wolna pamięć */
    if (currentMemoryLocation < EEPROM_BYTES_MAX) {
      currentMemoryLocation++;
      EEPROM_writeWord(CURRENT_LOCATION_POINTER, currentMemoryLocation);
    }

                                                                 /* opóźnienie */
    for (i = 0; i < secondsDelay; i++) {
      _delay_ms(1000);
      LED_PORT ^= (1 << LED0);              /* błyskanie sygnalizuje aktywność */
    }

  }                                                    /* koniec pętli zdarzeń */
  return (0);                           /* ta instrukcja nie zostanie wykonana */
}
