                                 /* Przykład użycia pamięci SPI EEPROM 25LC256 */

// ------- Preambuła -------- //
#include <avr/io.h>
#include <util/delay.h>

#include "pinDefines.h"

#include "USART.h"
#include "25LC256.h"

int main(void) {
  uint8_t i;
  uint8_t address;

  // -------- Inicjalizacja --------- //
  initSPI();
  initUSART();

  // ------ Pętla zdarzeń ------ //
  while (1) {
    printString("\r\n====  Zabawy z pamięcią EEPROM ====\r\n");
    printString("Adres    Wartosc\r\n");

    for (i = 0; i < 10; i++) {            /* wypisz pierwszy 10 bajtów pamięci */
      printString("  ");
      printByte(i);
      printString("     ");
      printByte(EEPROM_readByte(i));
      printString("\r\n");
    }
    printString(" nacisnij [e] zeby wymazac cala pamiec\r\n");
    printString(" nacisnij [w] zeby zapisac do pamieci\r\n\r\n");

    switch (receiveByte()) {                                   /* pobierz dane */
    case 'e':
      printString("Czyszczenie pamieci EEPROM, to moze chwile potrwac.\r\n");
      EEPROM_clearAll();
      break;
    case 'w':
      printString("Ktora strone pamieci chcesz zapisac?\r\n");
      address = getNumber();
      printString("\r\nJaka liczbe chcesz tutaj zapisac?\r\n");
      i = getNumber();
      EEPROM_writeByte(address, i);
      printString("\r\n");
      break;
    default:
      printString("Slucham??\r\n");
    }


  }                                                    /* Koniec pętli zdarzeń */
  return (0);                           /* ta instrukcja nie zostanie wykonana */
}
