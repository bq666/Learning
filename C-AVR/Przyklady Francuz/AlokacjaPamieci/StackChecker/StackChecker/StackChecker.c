/*
 * StackChecker.c
 *
 * Created: 2014-07-30 22:21:54
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