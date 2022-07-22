/*
 * WS2812B_bb.c
 *
 * Created: 2014-08-23 21:40:18
 *  Author: tmf
 */ 


#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>


#define GLUE(a, b)     a##b

/* single-bit macros, used for control bits */
#define SET_(what, p, m) GLUE(what, p) |= (1 << (m))
#define CLR_(what, p, m) GLUE(what, p) &= ~(1 << (m))
#define GET_(/* PIN, */ p, m) GLUE(PIN, p) & (1 << (m))
#define SET(what, x) SET_(what, x)
#define CLR(what, x) CLR_(what, x)
#define GET(/* PIN, */ x) GET_(x)

/* nibble macros, used for data path */
#define ASSIGN_(what, p, m, v) GLUE(what, p) = (GLUE(what, p) & \
~((1 << (m)) | (1 << ((m) + 1)) | \
(1 << ((m) + 2)) | (1 << ((m) + 3)))) | \
((v) << (m))
#define READ_(what, p, m) (GLUE(what, p) & ((1 << (m)) | (1 << ((m) + 1)) | \
(1 << ((m) + 2)) | (1 << ((m) + 3)))) >> (m)
#define ASSIGN(what, x, v) ASSIGN_(what, x, v)
#define READ(what, x) READ_(what, x)


#define WS2812B_PIN D, 1    //Pon na który wysy³ane s¹ dane
#define LEDNO   30           //Liczba LEDów

void WS2812B_init()
{
	CLR(PORT, WS2812B_PIN);
	SET(DDR, WS2812B_PIN);   //Pin jest wyjœciem
}

void WS2812B_reset()
{
	CLR(PORT, WS2812B_PIN);
	_delay_us(50);
}

void WS2812B_send(uint8_t byte)
{
	void WS2812B_sendOne()
	{
		SET(PORT, WS2812B_PIN);
		_delay_loop_2(8*F_CPU/10000000UL/3);
		CLR(PORT, WS2812B_PIN);
		_delay_loop_1(1);
	}
	
	void WS2812B_sendZero()
	{
		SET(PORT, WS2812B_PIN);

		asm volatile ("nop"); asm volatile ("nop"); 
		CLR(PORT, WS2812B_PIN);
		_delay_loop_2(8*F_CPU/10000000UL/3);		
	}
	
	uint8_t cnt=8;
	while(cnt--)
	{
		if(byte & 0x80) WS2812B_sendOne();
		    else WS2812B_sendZero();
		byte<<=1;
	}
}

int main(void)
{
	WS2812B_init();
	WS2812B_reset();
	
	for(uint8_t x=0; x < 5; x++) 
	 {
		 WS2812B_send(255);
		 WS2812B_send(255);
		 WS2812B_send(0);
	 }
	 
	for(uint8_t x=0; x < 5; x++) 
	 {
		 WS2812B_send(255);
		 WS2812B_send(0);
		 WS2812B_send(0);
	 }
	
	for(uint8_t x=0; x < 5; x++) 
	 {
		 WS2812B_send(0);
		 WS2812B_send(255);
		 WS2812B_send(0);
	 }

	for(uint8_t x=0; x < 5; x++) 
	 {
		 WS2812B_send(0);
		 WS2812B_send(0);
		 WS2812B_send(255);
	 }
	 
	uint8_t cnt=LEDNO;
	uint8_t offset=0;
	uint8_t delta=256/LEDNO;
	
    while(1)
    {
        WS2812B_reset();	
		while(cnt--)
		{
			WS2812B_send(cnt*delta+offset);
			WS2812B_send(0);
			WS2812B_send(0);
		}
		offset+=delta;
		_delay_ms(10);
    }
}