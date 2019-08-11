                              /* Biblioteka obsługi pamięci SPI EEPROM 25LC256 */
#include <avr/io.h>
#include "pinDefines.h"


                                    /* Który pin wybiera układ pamięci EEPROM? */
#define SLAVE_SELECT    SPI_SS_PORT &= ~(1 << SPI_SS)
#define SLAVE_DESELECT  SPI_SS_PORT |= (1 << SPI_SS)

// Zestaw instrukcji -- pochodzi z arkusza danych
#define EEPROM_READ      0b00000011                          /* odczyt pamięci */
#define EEPROM_WRITE     0b00000010                        /* zapis do pamięci */

#define EEPROM_WRDI      0b00000100                       /* wyłączenie zapisu */
#define EEPROM_WREN      0b00000110                        /* włączenie zapisu */

#define EEPROM_RDSR      0b00000101                 /* odczyt rejestru statusu */
#define EEPROM_WRSR      0b00000001               /* zapis do rejestru statusu */

// Bity rejestru statusu EEPROM -- pochodzą z arkusza danych
// Używaj do analizowania zawartości rejestru statusu
#define EEPROM_WRITE_IN_PROGRESS    0
#define EEPROM_WRITE_ENABLE_LATCH   1
#define EEPROM_BLOCK_PROTECT_0      2
#define EEPROM_BLOCK_PROTECT_1      3

#define EEPROM_BYTES_PER_PAGE       64
#define EEPROM_BYTES_MAX            0x7FFF

// Funkcje

// Inicjuje magistralę SPI do współpracy z pamięcią EEPROM 
// przy fazie i polaryzacji = 0,0
void initSPI(void);

// Funkcja ogólnego przeznaczenia 
// Ładuje tylko dane do rejestru sprzętowego SPI i czeka
void SPI_tradeByte(uint8_t byte);

// Dzieli 16-bitowy adres na dwa bajty i oba wysyła
void EEPROM_send16BitAddress(uint16_t address);

// Odczytuje rejestr statusu pamięci EEPROM
uint8_t EEPROM_readStatus(void);

// Funkcja pomocnicza:
// włącza zapis do pamięci EEPROM
void EEPROM_writeEnable(void);

// Odczytuje bajt z podanego adresu pamięci
uint8_t EEPROM_readByte(uint16_t address);

// Odczytuje dwa bajty z podanego adresu w pamięci
uint16_t EEPROM_readWord(uint16_t address);

// Zapisuje bajt pod podany adres w pamięci
void EEPROM_writeByte(uint16_t address, uint8_t byte);

// Zapisuje dwa bajty pod podany adres w pamięci
void EEPROM_writeWord(uint16_t address, uint16_t word);

// Zeruje wszystkie bajty w pamięci
void EEPROM_clearAll(void);
