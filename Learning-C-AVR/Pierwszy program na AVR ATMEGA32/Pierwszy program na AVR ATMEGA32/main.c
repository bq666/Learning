/*
 * Pierwszy program na AVR ATMEGA32.c
 *
 * Created: 2017-03-07 00:02:35
 * Author : bq666
 */ 

#include <avr/io.h>
#include <util/delay.h>

// **** Definicje dla preprocesora
#define F_CPU 11059200UL

#define LED_PIN (1<<PC7)
#define LED_ON PORTC &= ~LED_PIN
#define LED_OFF PORTC |= LED_PIN
#define LED_TOG PORTC ^= LED_PIN

#define KEY1_PIN (1<<PC6)
#define KEY2_PIN (1<<PC5)
#define KEY3_PIN (1<<PC4)
#define KEY_DOWN ! (PINC & KEY_PIN)

uint8_t klawisz_wcisniety (uint8_t klawisz);

//************************************************************ Pêtla g³ówna 
int main(void)
{
	// ***************** INICJALIZACJA ****************
	// DDRC |= LED_PIN;	 /*DDRC |= (1<<PC7);	DDRC = DDRC|(1<<PC7);		DDRC=0b10000000;*/
	// PORTC |= LED_PIN;	 /*PORTC |= (1<<PC7);	PORTC = PORTC|(1<<PC7);		PORTC=0b01111111;*/
	// DDRC &=~ KEY_PIN; 
	// PORTC |= KEY_PIN;
	DDRC |= LED_PIN; //kierunek wyjœciowy
	PORTC |= LED_PIN; //wy³¹czenie diody 
	DDRC &= ~ (KEY1_PIN|KEY2_PIN|KEY3_PIN); //piny klawiszy kierunek wejœciowy 
	PORTC |= KEY1_PIN|KEY2_PIN|KEY3_PIN; //piny klawiszy podci¹ganie do VCC
	
	
	// ***************** PÊTLA G£ÓWNA PROGRAMU ****************
		while (1)
		{
			if(klawisz_wcisniety(KEY1_PIN)) LED_ON;
			if(klawisz_wcisniety(KEY2_PIN)) LED_OFF;
			if(klawisz_wcisniety(KEY3_PIN)) LED_TOG;			
		}
		

}
	
	// ***************** DEFINICJE FUNKCJI ****************
	uint8_t klawisz_wcisniety(uint8_t klawisz)
	{
		if (!(PINC&klawisz))
		{
			_delay_ms(80);
			if (!(PINC&klawisz)) return 1;
		}
		return 0;
	}
	
	
/*	
	while(1)
	{		
		LED_TOG;
		_delay_ms(1000);
	}
	
	
}
	

	
	
}
	DDRC |=LED_PIN;
	while(1)
	{
		
		LED_TOG;
		_delay_ms(1000);	
	}
}
{
	DDRC |= LED_PIN;
     Replace with your application code 
    while (1) 
    {
		LED_ON;
		_delay_ms(3000);
		LED_OFF;
		_delay_ms(1000);
    }
} */

