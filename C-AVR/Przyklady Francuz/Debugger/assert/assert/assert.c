/*
 * assert.c
 *
 * Created: 2014-08-19 20:49:22
 *  Author: tmf
 */ 


#include <avr/io.h>
#include <assert.h>
#include <stdlib.h>

//void abort(void);

int dzielenie(int licznik, int mianownik)
{
	assert(mianownik != 0);    //Sprawd� poprawno�� argument�w
	return licznik/mianownik;
}

//void abort(void)
//{
//	while(1);  //Zako�cz wykonywanie programu
//}

int main(void)
{
	volatile int x=dzielenie(10, 1);
	x=dzielenie(10, 0);
	while(1)
	{
		//TODO:: Please write your application code
	}
}