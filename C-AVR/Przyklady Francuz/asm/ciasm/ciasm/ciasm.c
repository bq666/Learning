/*
 * ciasm.c
 *
 * Created: 2013-01-20 12:09:29
 *  Author: tmf
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>

uint8_t x;

/*ISR(TCC0_CCA_vect)
{
	x++;
}*/

uint32_t asm_add;
uint8_t asm_txt='a';

void c_zero()
{
	asm_add=0;
}

extern uint32_t asm_inc(uint32_t arg);
extern uint8_t asm_read_byte();
extern void asm_zero();

int main(void)
{

	asm_add=1;
	asm_add=asm_inc(asm_add);
	asm_add=asm_inc(asm_add);
	asm_add=asm_inc(asm_add);
	asm_zero();
	asm_add=asm_read_byte();
	asm_add=asm_inc(asm_add);
	
    while(1)
    {
        //TODO:: Please write your application code 
    }
}