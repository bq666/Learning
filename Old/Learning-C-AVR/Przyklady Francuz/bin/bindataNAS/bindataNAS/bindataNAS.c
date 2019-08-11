/*
 * bindataNAS.c
 *
 * Created: 2013-09-15 21:08:32
 *  Author: tmf
 */


#include <avr/io.h>

extern __memx const uint8_t _binary____intro8kHz8PWMHL_raw_end;
extern __memx const uint8_t _binary____intro8kHz8PWMHL_raw_size;
extern __memx const uint8_t _binary____intro8kHz8PWMHL_raw_start;

extern __memx const uint8_t _binary____intro16kHz16PCM_raw_start;
extern __memx const uint8_t _binary____intro16kHz16PCM_raw_size;
extern __memx const uint8_t _binary____intro16kHz16PCM_raw_end;

uint8_t bufor[10];

int main(void)
{
	__memx const uint8_t *start1=&_binary____intro8kHz8PWMHL_raw_start;
	for(uint8_t i=0; i<10; i++) bufor[i]=*start1++;

	volatile __uint24 start=(__uint24)&_binary____intro16kHz16PCM_raw_start;
    __memx const uint8_t *ptr;
	ptr=(__memx const uint8_t*)(__uint24)start;

	for(uint8_t i=0; i<10; i++) bufor[i]=*ptr++;

	while(1)
	{
		//TODO:: Please write your application code
	}
}