/*
 * Fuses_avr_libc.c
 *
 * Created: 2012-05-20 17:53:49
 *  Author: tmf
 */ 


#include <avr/io.h>
#include <avr/fuse.h>
#include <avr/lock.h>

FUSES =
{
	.low = LFUSE_DEFAULT,        //Domyœlne ustawienia
	.high = (FUSE_BOOTSZ0 & FUSE_BOOTSZ1 & FUSE_EESAVE & FUSE_DWEN),
	.extended = EFUSE_DEFAULT,   //Domyœlne ustawienia
};

LOCKBITS = LB_MODE_1 & BLB0_MODE_3 & BLB1_MODE_4; //Konfguruj bity zabezpieczaj¹ce

int main(void)
{
    while(1)
    {
        //TODO:: Please write your application code 
    }
}