/*
 * intvectortable_case1.c
 *
 * Created: 2014-08-23 16:38:40
 *  Author: tmf
 */ 


#include <inttypes.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <avr\boot.h>
#include <util\delay.h>

__attribute__((naked,section(".vectors"))) void IntTable()
{
	asm("jmp reset");
	asm("jmp __bad_interrupt");
	asm("jmp __bad_interrupt");
	asm("jmp __bad_interrupt");
	asm("jmp __bad_interrupt");
	asm("jmp __bad_interrupt");
	asm("jmp __bad_interrupt");
	asm("jmp __bad_interrupt");
	asm("jmp __bad_interrupt");
	asm("jmp __bad_interrupt");
	asm("jmp __bad_interrupt");
	asm("jmp __bad_interrupt");
	asm("jmp __bad_interrupt");
	asm("jmp __bad_interrupt");
	asm("jmp __vector_14");
}

__attribute__((naked)) void reset()
{
	asm("clr r1");
	SP=RAMEND;
	SREG=0;
	asm("jmp __ctors_end");
}

__attribute__((naked,section(".init9"))) void jmp_main()
{
	asm("jmp main");
}

void __bad_interrupt()
{
	cli();
	while(1);
}

ISR(TIMER1_OVF_vect)
{
	PORTB |= _BV(0);
}



void boot_program_page(uint32_t strona, uint8_t *buf)
{
	uint16_t i;
	uint8_t sreg;

	sreg = SREG;	//Zapisz stan globalnej flagi zezwolenia na przerwania
	cli();
	
	boot_page_erase_safe(strona);
	
	for (i=0; i<SPM_PAGESIZE; i+=2)
	{
		uint16_t slowo=*buf++;
		slowo+=(*buf++)<<8;
		boot_page_fill_safe(strona+i, slowo);	//Zapisz dane do bufora
	}

	boot_page_write_safe(strona);     //Zapisz bufor do pamiêci FLASH
	boot_rww_enable_safe();			  //Odblokuj dostêp do pamiêci RWW
	SREG = sreg;					  //Odtwórz stan przerwañ
}


int main()
{
	volatile static int x=10;
	_delay_us(1000);
	x=x+1;
}
