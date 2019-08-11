/*
 * bootloader.c
 *
 * Created: 2014-08-23 20:43:00
 *  Author: tmf
 */ 


#include <avr\io.h>

void bfunc1()
{
}

int bfunc2(int x)
{
	return x+1;
}

void jumptable() __attribute__((section(".vectors"), naked));
void jumptable()
{
	asm("jmp bfunc1");	//Udostêpnione dla aplikacji funkcje
	asm("jmp bfunc2");
}

int main()
{
	//Kod bootloadera
}
