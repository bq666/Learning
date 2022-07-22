/*
 * 3 PUADP SWETCH.c
 *
 * Created: 2017-03-22 20:45:33
 * Author : bq666
 */ 

#include <avr/io.h>
#include <util/delay.h>



int main(void)
{
	DDRC&=~(1<<PC7);
	PORTC|=(1<<PC7);
	uint8_t buttonWasPressed;
	
	
	DDRA|=(1<<0);
	PORTA&=~(1<<0);
	
    /* Replace with your application code */
    while (1) 
    {
		if (!(PINC & (1<<PC7)))
		{
			_delay_ms(100);
			if (buttonWasPressed == 0)
			{
				PORTA^=(1<<0);	
				buttonWasPressed = 1;
			}
		}
		else
		{
			buttonWasPressed = 0;
		}
    } 
}

