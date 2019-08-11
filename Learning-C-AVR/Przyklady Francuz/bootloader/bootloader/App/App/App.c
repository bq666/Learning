/*
 * App.c
 *
 * Created: 2014-08-23 18:03:19
 *  Author: tmf
 */ 


#include <avr\io.h>

static inline void bfunc1();
void bfunc1()
{
	asm("call 0x3e0e4");
}

typedef int (*INT_INT_PTR)(uint8_t);

static inline int bfunc2(int x)
{
	uint8_t EINDtmp;

	asm volatile
	(
	"IN %0, %1"    "\n\t"
	"ldi r30, 3"    "\n\t"
	"out %1, r30"   "\n\t"
	: "=r" (EINDtmp) : "I" (_SFR_IO_ADDR(EIND))
	: "r30"
	);

	x=((INT_INT_PTR) (0x3e0e8/2))(x);
	asm volatile
	(
	"out %1, %0"   "\n\t"
	:: "r" (EINDtmp), "I" (_SFR_IO_ADDR(EIND))
	);

	return x;
}

int main()
{

	bfunc1();
	volatile int x=bfunc2(10);
	x=bfunc2(x);
	x=bfunc2(x);
}
