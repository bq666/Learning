/*
 * LCDAlfaInit.c
 *
 * Created: 2014-08-15 11:03:19
 *  Author: tmf
 */ 


#include <stdbool.h>
#include <stdint.h>
#include "defines.h"
#include "hd44780.h"
#include <avr\pgmspace.h>
#include <util\delay.h>

void lcd_init()
{

	hd44780_init();				//Podstawowa inicjalizacja modu�u
	hd44780_outcmd(HD44780_CLR);	//Wyczy�� pami�� DDRAM
	hd44780_wait_ready(1000);
	hd44780_outcmd(HD44780_ENTMODE(1, 0));	//Tryb autoinkrementacji AC
	hd44780_wait_ready(1000);
	hd44780_outcmd(HD44780_DISPCTL(1, 0, 0));	//W��cz wy�wietlacz, wy��cz kursor
	hd44780_wait_ready(1000);
}

void lcd_putchar(char c)
{
	static bool second_nl_seen;
	static uint8_t line=0;
	
	if ((second_nl_seen) && (c != '\n')&&(line==0))
	{//Odebrano pierwszy znak
		hd44780_wait_ready(40);
		hd44780_outcmd(HD44780_CLR);
		hd44780_wait_ready(1600);
		second_nl_seen=false;
	}
	if (c == '\n')
	{
		if (line==0)
		{
			line++;
			hd44780_outcmd(HD44780_DDADDR(64));	//Adres pierwszego znaku drugiej linii
			hd44780_wait_ready(1000);
		}
		else
		{
			second_nl_seen=true;
			line=0;
		}
	}
	else
	{
		hd44780_outdata(c);
		hd44780_wait_ready(40);
	}
}

void lcd_puttext_P(const char __flash *txt)
{
	char ch;
	while((ch=*txt))
	{
		lcd_putchar(ch);
		txt++;
	}
}

void lcd_puttext(const char __memx *txt)
{
	char ch;
	while((ch=*txt))
	{
		lcd_putchar(ch);
		txt++;
	}
}

int main()
{
	lcd_init();
	lcd_puttext(PSTR("Test LCD.\nDruga linia"));
	while(1) {}
}

