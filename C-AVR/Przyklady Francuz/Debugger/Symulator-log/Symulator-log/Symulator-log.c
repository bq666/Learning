/*
 * Symulator_log.c
 *
 * Created: 2014-08-19 15:46:57
 *  Author: tmf
 */ 



#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRD=0xff;
	while(1)
	{
		PORTD=0xff;
		_delay_us(2);
		PORTD=0;
		_delay_us(2);
	}
}
