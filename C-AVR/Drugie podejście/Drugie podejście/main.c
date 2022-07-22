/*
 * Drugie podejście.c
 *
 * Created: 2017-07-02 14:11:24
 * Author : bq666
 */ 

#include <avr/io.h>
#include <util/delay.h>
#define TIME 1000

int main(void)
{
int16_t i,j;
DDRC |= (1<<PC5);
PORTC |= (1<<PC5);

while(1){
	if (!(PINC & (1<<PC0))){
		for(i = 0; i < 100000; i++){
			PORTC &= ~(1<<PC5);
			for(j = 0; j >= i;j++);
			//_delay_ms(TIME);
			PORTC |= (1<<PC5);
			for(j = 0; j >= i;j++);
			//_delay_ms(TIME()));			
			}
		}else PORTC &= ~(1<<PC5);
	}
	
}


