/*
 * wear_leveling1.c
 *
 * Created: 2012-09-14 22:09:13
 *  Author: tmf
 */ 


#include <avr/eeprom.h>

#define ILE_WYDLUZYC    10
EEMEM unsigned int bufor[ILE_WYDLUZYC];

void skasuj_bufor()
{
	int i=0;
	while(i<ILE_WYDLUZYC) eeprom_write_word(&bufor[i], 0xFFFF);
}

void zapisz_bufor(unsigned int wartosc)
{
	int i=0;
	while((i<ILE_WYDLUZYC) && (eeprom_read_word(&bufor[i])!=0xFFFF)) i++;
	if(i==ILE_WYDLUZYC) skasuj_bufor();
	eeprom_write_word(&bufor[i%ILE_WYDLUZYC], wartosc);
}

unsigned int odczytaj_bufor()
{
	int i=0;
	unsigned int wartosc=eeprom_read_word(&bufor[i]);
	while((i<ILE_WYDLUZYC) && (eeprom_read_word(&bufor[i])!=0xFFFF))
	{
		wartosc=eeprom_read_word(&bufor[i]);
		i++;
	}
	return wartosc;
}


int main(void)
{
    while(1)
    {
        //TODO:: Please write your application code 
    }
}