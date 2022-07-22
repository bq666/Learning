/*
 * Preskaler.c
 *
 * Created: 2014-07-22 22:19:47
 *  Author: tmf
 */ 


#include <avr/io.h>
#include <util/atomic.h>

int main(void)
{
	CLKPR=_BV(CLKPCE);    //Zezwól na zmianê konfiguracji preskalera
	CLKPR=0;              //Zmieñ preskaler na brak podzia³u zegara
	//Od tego momentu stan bitu CKDIV8 jest bez znaczenia
	
    while(1)
    {
        //TODO:: Please write your application code 
    }
}