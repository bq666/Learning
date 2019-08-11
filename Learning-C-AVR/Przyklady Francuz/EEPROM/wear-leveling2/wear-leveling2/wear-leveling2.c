/*
 * wear_leveling2.c
 *
 * Created: 2012-09-14 22:13:07
 *  Author: tmf
 */ 


#include <avr/eeprom.h>

#define ILE_WYDLUZYC    8
EEMEM unsigned int bufor[ILE_WYDLUZYC];
EEMEM unsigned char wskaznik[ILE_WYDLUZYC];

void skasuj_wskaznik()
{
	int i=0;
	while(i<ILE_WYDLUZYC) eeprom_write_byte(&wskaznik[i], 0xFF);
}

void zapisz_bufor(unsigned int wartosc)
{
	int i=0;
	while((i<ILE_WYDLUZYC) && (eeprom_read_byte(&wskaznik[i])!=0xFF)) i++;
	if(i==ILE_WYDLUZYC) skasuj_wskaznik();
	eeprom_write_byte(&wskaznik[i%ILE_WYDLUZYC], 0);
	eeprom_write_word(&bufor[i%ILE_WYDLUZYC], wartosc);
}

unsigned int odczytaj_bufor()
{
	int i=0;
	unsigned int wartosc=eeprom_read_word(&bufor[i]);
	while((i<ILE_WYDLUZYC) && (eeprom_read_byte(&wskaznik[i])!=0xFF))
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