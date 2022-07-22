/*
 * bindata.c
 *
 * Created: 2013-09-15 16:51:36
 *  Author: tmf
 */


#include <avr/io.h>
#include <avr/pgmspace.h>

extern __memx const uint8_t _binary____intro8kHz8PWMHL_raw_end;
extern __memx const uint8_t _binary____intro8kHz8PWMHL_raw_size;
extern __memx const uint8_t _binary____intro8kHz8PWMHL_raw_start;

extern __memx const uint8_t _binary____intro16kHz16PCM_raw_start;
extern __memx const uint8_t _binary____intro16kHz16PCM_raw_size;
extern __memx const uint8_t _binary____intro16kHz16PCM_raw_end;

uint8_t bufor[10];

#define GET_FAR_ADDRESS(var)                \
({                                           \
	__uint24 tmp;                            \
	__asm__ __volatile__(                    \
	"ldi	%A0, lo8(%1)"           "\n\t"   \
	"ldi	%B0, hi8(%1)"           "\n\t"   \
	"ldi	%C0, hh8(%1)"           "\n\t"   \
	: "=d" (tmp) : "p"  (&(var)));           \
	tmp;                                     \
})

int main(void)
{
	__uint24 start1=GET_FAR_ADDRESS(_binary____intro8kHz8PWMHL_raw_start);
	for(uint8_t i=0; i<10; i++) bufor[i]=pgm_read_byte_far(start1++);

	volatile uint32_t size=GET_FAR_ADDRESS(_binary____intro16kHz16PCM_raw_size);
	volatile __uint24 start=GET_FAR_ADDRESS(_binary____intro16kHz16PCM_raw_start);
	for(uint8_t i=0; i<10; i++) bufor[i]=pgm_read_byte_far(start++);

	while(1)
	{
		//TODO:: Please write your application code
	}
}