/*
 * Klawiatura.c
 *
 * Created: 2014-08-12 15:56:41
 *  Author: tmf
 */ 


#include <avr\io.h>
#include <util\delay.h>

#define LED	D

#define GLUE(a, b)     a##b

#define LEDPORT1(s)	GLUE(PORT,s)
#define LEDPORT LEDPORT1(LED)
#define LEDDDR1(s)	GLUE(DDR,s)
#define LEDDDR	LEDDDR1(LED)

//Cyfry 0,1,2,3,4,5,6,7,8,9 i symbol -
static const uint8_t __flash DIGITS[11]={0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90, 0xBF};
const uint8_t DP=0x80;

void ShowOnLED(uint8_t val)
{
	uint8_t tmp=0xFF;
	if((val & 0x7F)<11) tmp=DIGITS[val & 0x7F];  //Odczytaj kod znaku
	if(val & DP) tmp&=~DP;      //Sterowanie kropk� dziesi�tn� na LED
	LEDPORT=tmp;
}

uint8_t scankbd()
{
	uint8_t y=0;
	uint8_t x;
	while(y<4)		//S� 4 rz�dy
	{
		x=PORTB;
		x=(x | 0x0F) ^ (1<<y);	//Wybierz aktywny rz�d, nie zmieniaj�c stanu innych pin�w portu
		PORTB=x;
		asm volatile ("nop");	//Synchronizator
		x=PINB;
		if((x & 0x70)!=0x70)	//Jaki� klawisz by� wci�ni�ty?
		{
			if((x & 0x10)==0) x=0;	//Je�li tak, to z kt�rej kolumny?
			else if((x & 0x20)==0) x=1;
			else x=2;
			x=x+y*3;			//Oblicz numer klawisza
			return x;
		}
		y++;
	}
	return 255;
}

int main()
{
	LEDDDR=0xFF;		//Wszystkie piny portu s� wyj�ciem
	DDRB=0x0F;	//4 rz�dy s� wyj�ciami, 3 kolumny s� wej�ciami
	PORTB=0x7F;	//W��cz pull upy na kolumnach, ustaw rz�dy w stanie 1

	uint8_t kbd;
	while(1)
	{
		kbd=scankbd();
		ShowOnLED(kbd);
	}
}