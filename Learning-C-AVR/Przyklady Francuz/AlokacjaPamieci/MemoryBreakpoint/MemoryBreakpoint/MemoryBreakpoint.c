/*
 * MemoryBreakpoint.c
 *
 * Created: 2014-07-28 22:07:34
 *  Author: tmf
 */ 


#include <avr/io.h>

uint16_t zmienna;

void Inc()
{
	zmienna++;
	Inc();
}

int main(void)
{
	Inc();
    while(1);
}