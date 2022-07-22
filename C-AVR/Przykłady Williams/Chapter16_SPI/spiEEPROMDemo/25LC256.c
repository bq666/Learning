#include "25LC256.h"

void initSPI(void) {
  SPI_SS_DDR |= (1 << SPI_SS);                             /* ustaw wyjście SS */
  SPI_SS_PORT |= (1 << SPI_SS);/* zaczynamy bez wybranego układu (stan wysoki) */

  SPI_MOSI_DDR |= (1 << SPI_MOSI);                    /* pin MOSI jako wyjście */
  SPI_MISO_PORT |= (1 << SPI_MISO);      /* opornik podciągający na pinie MISO */
  SPI_SCK_DDR |= (1 << SPI_SCK);                       /* pin SCK jako wyjście */

  /* Nie trzeba ustawiać fazy i polaryzacji, ponieważ
   * wartości domyślne dobrze działają z układami 25LCxxx */
  SPCR |= (1 << SPR1);              /* podzielnik /16 dla płytek prototypowych */
  SPCR |= (1 << MSTR);                                         /* główny zegar */
  SPCR |= (1 << SPE);                                             /* włączenie */
}

void SPI_tradeByte(uint8_t byte) {
  SPDR = byte;                                /* SPI zaczyna od razu wysyłanie */
  loop_until_bit_is_set(SPSR, SPIF);                 /* czekamy na zakończenie */
                                   /* rejestr SPDR zawiera teraz odebrany bajt */
}

void EEPROM_send16BitAddress(uint16_t address) {
  SPI_tradeByte((uint8_t) (address >> 8));           /* bardziej znaczący bajt */
  SPI_tradeByte((uint8_t) address);                     /* mniej znaczący bajt */
}

uint8_t EEPROM_readStatus(void) {
  SLAVE_SELECT;
  SPI_tradeByte(EEPROM_RDSR);
  SPI_tradeByte(0);                                   /* wysyłanie ośmiu bitów */
  SLAVE_DESELECT;
  return (SPDR);                                 /* zwracamy otrzymaną wartość */
}

void EEPROM_writeEnable(void) {
  SLAVE_SELECT;
  SPI_tradeByte(EEPROM_WREN);
  SLAVE_DESELECT;
}

uint8_t EEPROM_readByte(uint16_t address) {
  SLAVE_SELECT;
  SPI_tradeByte(EEPROM_READ);
  EEPROM_send16BitAddress(address);
  SPI_tradeByte(0);
  SLAVE_DESELECT;
  return (SPDR);
}

uint16_t EEPROM_readWord(uint16_t address) {
  uint16_t eepromWord;
  SLAVE_SELECT;
  SPI_tradeByte(EEPROM_READ);
  EEPROM_send16BitAddress(address);
  SPI_tradeByte(0);
  eepromWord = SPDR;
  eepromWord = (eepromWord << 8);                            /* najstarszy bit */
  SPI_tradeByte(0);
  eepromWord += SPDR;                                        /* najmłodszy bit */
  SLAVE_DESELECT;
  return (eepromWord);
}

void EEPROM_writeByte(uint16_t address, uint8_t byte) {
  EEPROM_writeEnable();
  SLAVE_SELECT;
  SPI_tradeByte(EEPROM_WRITE);
  EEPROM_send16BitAddress(address);
  SPI_tradeByte(byte);
  SLAVE_DESELECT;
  while (EEPROM_readStatus() & _BV(EEPROM_WRITE_IN_PROGRESS)) {;
  }
}

void EEPROM_writeWord(uint16_t address, uint16_t word) {
  EEPROM_writeEnable();
  SLAVE_SELECT;
  SPI_tradeByte(EEPROM_WRITE);
  EEPROM_send16BitAddress(address);
  SPI_tradeByte((uint8_t) (word >> 8));
  SPI_tradeByte((uint8_t) word);
  SLAVE_DESELECT;
  while (EEPROM_readStatus() & _BV(EEPROM_WRITE_IN_PROGRESS)) {;
  }
}

void EEPROM_clearAll(void) {
  uint8_t i;
  uint16_t pageAddress = 0;
  while (pageAddress < EEPROM_BYTES_MAX) {
    EEPROM_writeEnable();
    SLAVE_SELECT;
    SPI_tradeByte(EEPROM_WRITE);
    EEPROM_send16BitAddress(pageAddress);
    for (i = 0; i < EEPROM_BYTES_PER_PAGE; i++) {
      SPI_tradeByte(0);
    }
    SLAVE_DESELECT;
    pageAddress += EEPROM_BYTES_PER_PAGE;
    while (EEPROM_readStatus() & _BV(EEPROM_WRITE_IN_PROGRESS)) {;
    }
  }
}
