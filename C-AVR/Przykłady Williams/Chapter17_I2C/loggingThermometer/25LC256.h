                                         /* biblioteka SPI EEPROM 25LC256 */
#include <avr/io.h>
#include "pinDefines.h"


                                 /* który pin wybiera pamięć EEPROM? */
#define SLAVE_SELECT    SPI_SS_PORT &= ~(1 << SPI_SS)
#define SLAVE_DESELECT  SPI_SS_PORT |= (1 << SPI_SS)

// Zestaw instrukcji z arkusza danych
#define EEPROM_READ      0b00000011                     /* odczyt pamięci */
#define EEPROM_WRITE     0b00000010                 /* zapis do pamięci */

#define EEPROM_WRDI      0b00000100                   /* wyłączenie zapisu */
#define EEPROM_WREN      0b00000110                    /* włączenie zapisu */

#define EEPROM_RDSR      0b00000101            /* odczyt rejestru statusu */
#define EEPROM_WRSR      0b00000001           /* zapis do rejestru statusu */

// Bity rejestru statusu pamięci EEPROM z arkusza danych
// Używaj do analizowania rejestru
#define EEPROM_WRITE_IN_PROGRESS    0
#define EEPROM_WRITE_ENABLE_LATCH   1
#define EEPROM_BLOCK_PROTECT_0      2
#define EEPROM_BLOCK_PROTECT_1      3

#define EEPROM_BYTES_PER_PAGE       64
#define EEPROM_BYTES_MAX            0x7FFF

// Funkcje

void initSPI(void);
                  /* Incjowanie SPI do pracy z pamięcią EEPROM z fazą i polaryzacją = 0,0 */

void SPI_tradeByte(uint8_t byte);
                  /* Ogólna funkcja. Ładuje rejestr SPI i czeka */

void EEPROM_send16BitAddress(uint16_t address);
                     /* dzieli adres 16-bitowy na dwa bajty i wysyła oba */

uint8_t EEPROM_readStatus(void);
                                   /* odczytuje rejestr statusu pamięci EEPROM */

void EEPROM_writeEnable(void);
                                   /* funkcja pomocnicza: włącza zapis do pamięci EEPROM */

uint8_t EEPROM_readByte(uint16_t address);
                           /* pobiera bajt z podanego adresu z pamięci */

uint16_t EEPROM_readWord(uint16_t address);
                        /* pobiera dwa bajty z podanego adresu z pamięci */

void EEPROM_writeByte(uint16_t address, uint8_t byte);
                           /* zapisuje bajt pod wskazany adres w pamięci */

void EEPROM_writeWord(uint16_t address, uint16_t word);
                          /* zapisuje dwa bajty pod wskazanym adresem w pamięci */

void EEPROM_clearAll(void);
                                  /* wpisuje zero do wszystkich komórek pamięci */
