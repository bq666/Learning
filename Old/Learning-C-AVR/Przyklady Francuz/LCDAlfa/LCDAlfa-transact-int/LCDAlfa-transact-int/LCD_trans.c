#include "LCD_trans.h"
#include <avr/interrupt.h>
#include <string.h>
#include <util/atomic.h>
#include "defines.h"
#include "hd44780.h"
#include "Alloc_safe.h"
#include "PinMacros.h"

typedef struct
{
	LCD_trans *elements[LCD_MAXTRANS]; //Wska�niki do transakcji
	uint8_t Beg;                       //Pierwszy element bufora
	uint8_t Count;                     //Liczba element�w w buforze
} CircBuffer;

static CircBuffer LCD_TransBuffer;         //Bufor a transakcje

static inline bool cbIsFull(CircBuffer *cb)
{
	return cb->Count == LCD_MAXTRANS;
}

static inline bool cbIsEmpty(CircBuffer *cb)
{
	return cb->Count == 0;
}

bool cbAdd(CircBuffer *cb, LCD_trans *elem)
{
	ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
	{
		if(cbIsFull(cb)) return false;         //Czy jest miejsce w kolejce?
		uint8_t end = (cb->Beg + cb->Count) % LCD_MAXTRANS;
		cb->elements[end] = elem;              //Dodaj transakcj�
		++cb->Count;                           //Liczba element�w w buforze
	}
	return true;      //Wszystko ok
}

LCD_trans *cbRead(CircBuffer *cb)
{
	LCD_trans *elem;
	ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
	{
		if(cbIsEmpty(cb)) return NULL;       //Bufor pusty, nie mo�na zwr�ci� elementu
		elem = cb->elements[cb->Beg];
		cb->Beg = (cb->Beg + 1) % LCD_MAXTRANS;
		-- cb->Count;                        //Zmniejszamy liczb� element�w pozosta�ych
	}		                                 //w buforze
	return elem;
}

ISR(TIMER0_COMPA_vect)
{
	static struct
	{
		uint8_t pos    : 6;           //Pozycja w polu danych aktualnej transakcji
		uint8_t nibble : 1;           //Kt�ra tetrada jest wysy�ana
	} seq;
	static LCD_trans *trans;          //Bie��co realizowana transakcja
	
	SET(PORT, HD44780_E);
	
	if(trans == NULL)                 //Nic do zrobienia, sprawd�my czy jaka� transakcja oczekuje
	{
		trans=cbRead(&LCD_TransBuffer); //Czy jest jaka� oczekuj�ca transakcja
		seq.pos=0;
		seq.nibble=0;
		if(trans == NULL) TCCR0B=0;   //Nie ma �adnych transakcji - wy��cz timer
	}

	if(trans)
	{                                 //Jest transakcja do zrealizowania
		uint8_t dat=trans->data[seq.pos];
		if(seq.nibble == 0) dat>>=4;  //To trzeba zmieni� je�li linie danych nie s� po��czone
		                              // z pinami 0-3 portu IO
		hd44780_outnibble_nowait(dat & 0x0F, seq.pos != 0);    //Zapisujemy rejestr steruj�cy lub dane
		++seq.nibble;
		if(seq.nibble == 0) ++seq.pos; //Co drug� tetrad� zwi�kszamy pozycj� bufora
		if(seq.pos >= trans->len)
		{
			trans->Ready=true;              //Koniec transakcji
			if(trans->SelfDel) free_re(trans); //Zwolnij pami�� transakcji je�li tak sobie �yczy� programista
			trans=NULL;                     //Koniec transakcji
		}
		CLR(PORT, HD44780_E);
	}
}

void LCD_Timer_init()
{
	TCCR0A=_BV(WGM01);                 //Tryb CTC timera
	OCR0A=F_CPU*LCD_ACCESSTIME/8;      //Nadmiar co 40 us
	TIMSK0=_BV(OCIE0A);                //Odblokuj przerwanie por�wnania timera
}

void LCD_Init()
{
	hd44780_init();				            //Podstawowa inicjalizacja modu�u
	hd44780_outcmd(HD44780_CLR);	            //Wyczy�� pami�� DDRAM
	hd44780_wait_ready(1000);
	hd44780_outcmd(HD44780_ENTMODE(1, 0));	//Tryb autoinkrementacji AC
	hd44780_wait_ready(1000);
	hd44780_outcmd(HD44780_DISPCTL(1, 0, 0));	//W��cz wy�wietlacz, wy��cz kursor
	hd44780_wait_ready(1000);
}

bool LCD_PutText(uint8_t x, uint8_t y, char *txt)
{
	LCD_trans *trans=malloc_re(sizeof(LCD_trans) + strlen(txt) + 2);
    bool ret=LCD_PutText_B(x, y, txt, trans, true);
	return ret;
}

bool LCD_PutText_B(uint8_t x, uint8_t y, char *txt, LCD_trans *buf, bool autodel)
{
	buf->cmd=LCD_Text;
	buf->Ready=false;
	buf->SelfDel=autodel;  //Czy zwolni� pami�� po zako�czeniu transakcji
	buf->data[0]=HD44780_DDADDR(x+y*0x40);   //Ustaw adres w DDRAM
	strcpy((char*)&buf->data[1], txt);  //Skopiuj dane tekstowe + NULL
	buf->len=strlen(txt) + 1;    //D�ugo�� tekstu + pozycji + NULL - 1
	bool ret=cbAdd(&LCD_TransBuffer, buf);
	if((ret==false) && (autodel)) free_re(buf);    //Brak miejsca w kolejce
	        else TCCR0B=_BV(CS01);     //Preskaler /8 - odblokuj timer
	return ret;
}
