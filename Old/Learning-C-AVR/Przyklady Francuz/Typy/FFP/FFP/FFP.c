/*
 * FFP.c
 *
 * Created: 2014-07-04 14:26:16
 *  Author: tmf
 */ 


#include <avr/io.h>
#include <math.h>
#include <avr/eeprom.h>

#include <stdfix.h>
#include <stdio.h>
#include <string.h>
#include <avr/pgmspace.h>


#include <string.h>
#include <stdlib.h>

_Fract f;

int main(void)
{
	char buf[10];
	char *ptr=buf;
	ptr[1]='a';
	char bufor[20];
	
	sprintf(bufor, "%r", f);
	
	f*=4;
	int res=f*100;
	_Fract x=0.01;
	res=__FRACT_FBIT__ ;
    while(1)
    {
        x+=0.01;
		res=x*100;
		res=roundr(x, 0);
    }
}

