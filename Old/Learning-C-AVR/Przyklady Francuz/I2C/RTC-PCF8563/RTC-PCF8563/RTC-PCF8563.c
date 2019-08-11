/*
 * RTC_PCF8563.c
 *
 * Created: 2014-08-19 12:51:50
 *  Author: tmf
 */ 


#include <avr/io.h>
#include "I2cbase.h"
#include "PCF8563.h"

int main(void)
{
	I2C_Init();
	
	Date data;
	 data.Year=bin2bcd(10);
	 data.Month=bin2bcd(1);
	 data.Day=bin2bcd(19);
	 
	Time czas; 
	 czas.Second=bin2bcd(0);
	 czas.Minute=bin2bcd(0);
	 czas.Hour=bin2bcd(23);

	 if(!PCF8563_IsDataValid())
	 {
		 PCF8563_SetTime(&czas);
		 PCF8563_SetDate(&data);
	 }

    while(1)
    {
        //TODO:: Please write your application code 
    }
}