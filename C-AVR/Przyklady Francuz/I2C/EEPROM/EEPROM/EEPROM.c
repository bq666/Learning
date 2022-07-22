/*
 * EEPROM.c
 *
 * Created: 2014-08-19 11:15:13
 *  Author: tmf
 */ 


#include <avr/io.h>
#include <string.h>
#include <stddef.h>
#include "I2cbase.h"

#define I2C_MEM_PAGE_SIZE 64   //Wielkoœæ strony pamiêci EEPROM

void I2C_MEM_SetRWAddress(const __uint24 addr)
{
	do       //Wybierz urz¹dzenie o wskazanym adresie
	{
		I2C_SendStartAndSelect(addr >> 16);
	} while(I2C_Error==I2C_NoACK); //Czekaj, a¿ urz¹dzenie wyœle ACK

	I2C_SendByte((uint8_t)(addr>>8));
	I2C_SendByte((uint8_t)(addr & 0xFF));
}

uint8_t I2C_MEM_read_byte(const __uint24 addr)
{
	I2C_MEM_SetRWAddress(addr);                     //Wybierz uk³ad i adres odczytywanej komórki
	I2C_SendStartAndSelect((addr >> 16) | TW_READ); //Wykonaj operacjê Current Address Read
	uint8_t byte=I2C_ReceiveData_NACK();
	I2C_Stop();
	return byte;
}

void I2C_MEM_write_byte(const __uint24 addr, uint8_t data)
{
	I2C_MEM_SetRWAddress(addr);
	I2C_SendByte(data);
	I2C_Stop();
	I2C_WaitTillStopWasSent(); //Poczekaj na zakoñczenie wysy³ania sygna³u STOP
}

void I2C_MEM_read_block(void *dst, const __uint24 src, size_t len)
{
	I2C_MEM_SetRWAddress(src);
	I2C_SendStartAndSelect((src >> 16) | TW_READ);
	while(--len)
	{
		*(uint8_t*)dst=I2C_ReceiveData_ACK();
		dst=((uint8_t*)dst)+1;
	}
	*(uint8_t*)dst=I2C_ReceiveData_NACK(); //Ostatni odczytywany bajt nie mo¿e zostaæ potwierdzony, co koñczy operacjê odczytu
	I2C_Stop();
}

void I2C_MEM_write_block(const void *src, const __uint24 dst, size_t len)
{
	size_t ps;
	size_t adres=(uint16_t)dst;

	do
	{
		I2C_MEM_SetRWAddress(dst);
		ps=I2C_MEM_PAGE_SIZE - (adres % I2C_MEM_PAGE_SIZE); //Oblicz liczbê bajtów do koñca strony pamiêci
		adres+=ps;   //Adres kolejnej strony pamiêci
		if(ps>len) ps=len;
		len-=ps;
		while(ps--)
		{
			I2C_SendByte(*(uint8_t*)src);
			src=((uint8_t*)src)+1;
		}
		I2C_Stop();
		I2C_WaitTillStopWasSent(); //Zaczekaj do koñca operacji wysy³ania danych
	} while(len);
}

#define SIZEOF(s,m) ((size_t) sizeof(((s *)0)->m))

#define I2C_MEM_write_var(var, EEvarname) \
{       \
	__uint24 _addr;   \
	_addr=0xAC0000UL;  \
	_addr|=offsetof(I2CEEPROM, EEvarname); \
	I2C_MEM_write_block(&var, _addr, SIZEOF(I2CEEPROM, EEvarname)); \
}

#define I2C_MEM_read_var(var, EEvarname) \
{       \
	__uint24 _addr;   \
	_addr=0xAC0000UL;  \
	_addr|=offsetof(I2CEEPROM, EEvarname); \
	I2C_MEM_read_block(&var, &_addr, SIZEOF(I2CEEPROM, EEvarname)); \
}

int main(void)
{
	I2C_Init();   //Zainicjuj interfejs TWI
	
	__uint24 addr=0xAC0000UL;
	
	 I2C_MEM_write_byte(addr,0xab);
	 addr++;
	 I2C_MEM_write_byte(addr,0xbb);
	 addr++;
	 I2C_MEM_write_byte(addr,0xcc);

	 addr=0xAC0000UL;
	 uint8_t dana=I2C_MEM_read_byte(addr);
	 addr++;
	 dana=I2C_MEM_read_byte(addr);
	 addr++;
	 dana=I2C_MEM_read_byte(addr);


	
typedef struct
{
	uint16_t zmienna1;
	uint8_t zmienna2;
	char zmienna3[10];
} I2CEEPROM;
	
I2CEEPROM * const pEE=0x0000;
 uint16_t dana16=10;
 addr=0xAC0000 | (uint16_t)&pEE->zmienna1;
 addr=0xAC0000 | offsetof(I2CEEPROM, zmienna1);
 I2C_MEM_write_block(&dana16, addr, sizeof(pEE->zmienna1));

 I2C_MEM_write_var(dana, zmienna1);
 I2C_MEM_read_var(dana, zmienna1);

	
    while(1)
    {
        //TODO:: Please write your application code 
    }
}