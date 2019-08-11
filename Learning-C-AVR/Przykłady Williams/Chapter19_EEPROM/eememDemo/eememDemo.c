#include <avr/io.h>
#include <avr/eeprom.h>
#include <USART.h>

#define STRING_LEN   80

// Definiowanie zmiennych z makrem EEMEM
uint8_t eepromCounter EEMEM = 0;
char eepromString[STRING_LEN] EEMEM = "Witaj w programie uzywajacym makra EEMEM.\r\n";
uint16_t eepromWord EEMEM = 12345;

int main(void) {

  initUSART();
  char ramString[STRING_LEN];
  uint8_t counter;

  while (1) {
    printString("\r\n------------------\r\n");
    eeprom_read_block(ramString, eepromString, STRING_LEN);
    printString(ramString);

    printString("\r\nAktualny stan licznika: ");
    counter = eeprom_read_byte(&eepromCounter);
    printByte(counter);

    printString("\r\nMoja wartosc typu uint16_t: ");
    printWord(eeprom_read_word(&eepromWord));

    printString("\r\n   Podaj nowy tekst powitalny:\r\n");
    readString(ramString, STRING_LEN);
    eeprom_update_block(ramString, eepromString, STRING_LEN);
    counter++;
    eeprom_update_byte(&eepromCounter, counter);
  }
  return (0);
}
