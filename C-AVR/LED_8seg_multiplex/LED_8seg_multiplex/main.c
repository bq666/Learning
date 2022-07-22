/*
 * LED_8seg_multiplex.c
 *
 * Created: 2017-03-12 20:57:32
 * Author : bq666
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "d_led.h"

uint8_t klawisz_wcisniety (uint8_t klawisz);

int main(void)
{
	// **** Inicjalizajca ****
	_delay_ms(1000);
	DDRD |= (0<<PD0);
	DDRD |= (0<<PD1);
	PORTD |= (0<<PD1);
	
	d_led_init(); // Inicjalizacja wyœwietlacza multiplexowanego 
	cy1=9;
	cy2=9;
	cy3=9;
	cy4=9;   // Testowe liczby

	
	
	sei ();  // W³¹czenie globalnego zezwolenia na przerwania 
	
	
	
	
    /* Replace with your application code */

	
  	while(1)
	  {
		  if (klawisz_wcisniety(1<<PD0)){
			  while(1){
				 _delay_ms(50);
			  cy4--;
			  if (cy4>10){cy4=9;cy3--;}
				  if (cy3>10){cy3=9;cy2--;}
					  if (cy2>10){cy2=9;cy1--;}
						  if(cy1>10){cy1=9;}
					  }				  
					  }
				  }
	
	
}

	uint8_t klawisz_wcisniety(uint8_t klawisz)
	{
		if (!(PIND&klawisz))
		{
			_delay_ms(80);
			if (!(PIND&klawisz)) return 1;
		}
		return 0;
	}