#include <avr/io.h>
#include <avr/eeprom.h>

int main(void) {

  // Zapisz wartosc 8-bitową w komórce pamieci EEPROM o adresie 0
  uint8_t *address = (uint8_t *) 0;
  eeprom_update_byte(address, 5);

  // Zapisz wartosc 16-bitową (12345) w komórkach pamięci EEPROM o adresach 5 i 6:
  eeprom_update_word((uint16_t *) 5, 12345);

  // Zapisz ciąg znaków w komórkach pamięci EEPROM o adresach 16-29:
  char *stringPointer = (char *) 16;
  char myString[] = "witaj swiecie";
  eeprom_update_block(myString, stringPointer, sizeof(myString));

  return (0);
}
