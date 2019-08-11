#include <avr/io.h>
#include <avr/eeprom.h>
#include <USART.h>

#define STRING_MAXLEN         0x20                    /* 32 znaki */
#define STRING_ADDRESS        0x20
#define COUNTER_ADDRESS       0x10


int main(void) {

  char myString[STRING_MAXLEN];
  char *eepromAddress = (char *) STRING_ADDRESS;
  uint16_t counter;

  initUSART();

  while (1) {
    // Odczytaj wartość z pamięci EEPROM i wypisz ją
    eeprom_read_block(myString, eepromAddress, STRING_MAXLEN);
    counter = eeprom_read_word((uint16_t *) COUNTER_ADDRESS);
    printString("\r\nTwoj stary ulubiony kolor to: ");
    printString(myString);

    // Pobierz dane, zapisz je w pamięci EEPROM
    printString("\r\n\r\n Wpisz swoj nowy ulubiony kolor.  ");
    readString(myString, sizeof(myString));
                   /* przekazywanie przez adres, funkcja zmieni już wartości */
    eeprom_update_block(myString, eepromAddress, STRING_MAXLEN);
    counter++;
    printString("Dziekuje! \r\nOdpowiadasz na to pytanie po raz ");
    printWord(counter);
    printString(" .  \r\n");
    eeprom_update_word((uint16_t *) COUNTER_ADDRESS, counter);
  }

  return (0);
}
