/*
 * Tracepoint.c
 *
 * Created: 2014-08-19 20:33:02
 *  Author: tmf
 */ 


#include <avr/io.h>

const char __flash tekst[] = "Tekst w FLASH";

int main(void)
{
	volatile int count;

	for(int x=0; x < 10; x++)
	{
		count+=11;
		for(int y=1; y < 10; y++)
		{
			count+=y;
		}
	}

	for(int i=1; i < 10; i++)
	count+=i;

	for(int i=1; i < 1000; i++)
	count++;

	count=tekst[0];

	while(1)
	{
		//TODO:: Please write your application code
	}
}