/*
 * TEST_DIODA.c
 *
 * Created: 2017-03-22 16:36:01
 * Author : bq666
 */ 

#include <avr/io.h>
#include <util/delay.h>



int main(void)
{
    /* Replace with your application code */
	DDRA|=(1<<PA0);
	
    while (1) 
    {
		for (int i=0; i<100; i=i+1)
		{
			PORTA^=(1<<PA0);
			_delay_ms(150);
		}
	
    }
}

	