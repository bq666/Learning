/*
 * PCF8574A.c
 *
 * Created: 2014-08-19 11:12:58
 *  Author: tmf
 */ 


#include <avr\io.h>
#include <stdint.h>
#include <util\delay.h>
#include "I2Cbase.h"

#define PCF8574ADDR 0x70

void I2C_StartSelectWait(uint8_t addr)
{
	do
	{
		I2C_SendStartAndSelect(addr);
	} while(I2C_Error==I2C_NoACK);
}

int main()
{
	uint8_t x=0xaa;
	I2C_Init();

	I2C_StartSelectWait(PCF8574ADDR);
	while(1)
	{
		I2C_SendByte(x);
		x^=0xff;
		_delay_ms(1000);
	}
	I2C_Stop();
}
