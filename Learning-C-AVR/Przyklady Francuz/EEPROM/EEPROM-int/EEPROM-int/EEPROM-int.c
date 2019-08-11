/*
 * EEPROM_int.c
 *
 * Created: 2012-11-18 23:49:02
 *  Author: tmf
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/eeprom.h>

uint8_t *EEPROMPtr;                  //Wska�nik do zapisywanego bloku
uint8_t *SRAMPtr;                    //Wska�nik do danych w SRAM
volatile uint16_t EEPROMWrBytes;     //Liczba bajt�w do zapisu

ISR(EE_READY_vect )
{
	eeprom_write_byte(EEPROMPtr, *SRAMPtr);
	EECR|=_BV(EERIE); //W��cz przerwania EEPROM
	EEPROMPtr++; SRAMPtr++;
	EEPROMWrBytes--;
	if(EEPROMWrBytes) EECR|=_BV(EERIE); //W��cz przerwania EEPROM
}

void EEPROM_write_int(uint8_t *src, uint8_t *dst, uint16_t size)
{
	while(EEPROMWrBytes); //Czekaj na zako�czenie poprzednich operacji
	EEPROMPtr=dst;
	SRAMPtr=src;
	EEPROMWrBytes=size-1;
	eeprom_write_byte(EEPROMPtr, *SRAMPtr);
	EEPROMPtr++; SRAMPtr++;
	EECR|=_BV(EERIE); //W��cz przerwania EEPROM
}

char napis[12] EEMEM;

int main(void)
{
	sei();
	EEPROM_write_int((uint8_t*)"Test EEPROM", (uint8_t*)napis, 12);
	EEPROM_write_int((uint8_t*)"Nowy zapis", (uint8_t*)napis, 11);
    while(1)
    {
        //TODO:: Please write your application code 
    }
}