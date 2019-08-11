/*
 * AwariaZasilania.c
 *
 * Created: 2012-11-17 21:48:09
 *  Author: tmf
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdbool.h>
#include <string.h>
#include <avr/eeprom.h>


typedef struct
{
	int Dane;
	int Temperatura;
	int PID_P;
} DaneStrona;

DaneStrona DaneEEPROM EEMEM = {.Dane=0xaabb, .Temperatura=0xac, .PID_P=0x10}; //Dane w EEPROM

DaneStrona DaneSRAM; //Kopia danych w SRAM

ISR(ANALOG_COMP_vect , ISR_NAKED)
{
    //Wy��cz zb�dne generatory i zmniejsz FCLK
	//Dodatkowo warto wszystkie piny ustawi� jako wej�cia
	//Rozpoczynamy zapis zmiennych do EEPROM

	eeprom_write_block(&DaneSRAM, &DaneEEPROM, sizeof(DaneStrona)); //Skopiuj dane do EEPROM
	
	while(1); //Ju� nic wi�cej nie robimy
}

void AC_init()
{
	DIDR1=_BV(AIN1D) | _BV(AIN0D);   //Wy��cz porty cyfrowe zwi�zane z wej�ciami komparatora
	ACSR=_BV(ACIE) | _BV(ACIS1);   //W��cz komparator i przerwanie komparatora zwi�zane ze zboczem opadaj�cym
}

void Data_init()
{
	eeprom_read_block(&DaneSRAM, &DaneEEPROM, sizeof(DaneStrona));  //Skopiuj dane z EEPROM do SRAM
}

int main(void)
{
	Data_init();
	AC_init();
	sei(); //Odblokuj przerwania
	
	DaneSRAM.Dane=0x4BCD;  //Modyfikujemy odtworzon� kopi� danych
	DaneSRAM.PID_P=0x0211; //Zostan� one automatycznie zapisane po od��czeniu zasilania
	DaneSRAM.Temperatura=0x1234;
    while(1)
    {
        //TODO:: Please write your application code 
    }
}