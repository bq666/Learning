/*
 * FirstApp.c
 *
 * Created: 2014-07-27 10:40:04
 *  Author: tmf
 */ 


#include <avr/io.h>

int main(void)
{
	DDRB|=_BV(PB5);   //Pin PB5 b�dzie wyj�ciem
	
    while(1)
    {
        if((PINB & _BV(PB7)) == 0) PORTB|=_BV(PB5);  //W��cz diod�
		    else PORTB&=~_BV(PB5);  //Wy��cz diod�
    }
}