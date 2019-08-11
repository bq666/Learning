/*
 * DCF77.c
 *
 * Created: 2012-03-06 19:21:08
 *  Author: tmf
 */ 

#include "DCF77lib.h"
#include <avr/io.h>
#include <string.h>
#include <avr/interrupt.h>
#include <util/atomic.h>
#include "calendar.h"
#include "defines.h"

#define DCF77_HI_beg (140ull*F_CPU/1024000ul)
#define DCF77_HI_end (250ull*F_CPU/1024000ul)
#define DCF77_LO_beg (40ull*F_CPU/1024000ul)
#define DCF77_LO_end (130ull*F_CPU/1024000ul)
#define DCF77_Interval (1730ull*F_CPU/1024000ul)

volatile uint8_t DCF77_bitcounter;
volatile DCF77_t DCF77Record[2];
volatile uint32_t Timestamp;
volatile bool TimestampUpdate;

static volatile uint8_t DCF77RecNo;   //Numer rekordu DCF77_t do kt�rego si� odwo�ujemy

//Funkcja obs�ugi przerwania capture z kana�u A - odczytywanie kolejnych bit�w
// Pole DCF77Record[DCF77RecNo].begin przechowuje tak�e wska�nik poprawno�ci rekordu 0 - ok, 1 - b��dny
ISR(TIMER1_CAPT_vect)
{
	TCNT1=0;             //Liczymy czas od pocz�tku
	uint16_t PW=ICR1;    //Moment w kt�rym zasz�o zdarzenie
	if(TCCR1B & _BV(ICES1))
	{
		PORTB|=_BV(PB5);  //W��cz LED
		TCCR1B=_BV(ICNC1) | _BV(WGM12) | _BV(CS12) | _BV(CS10);  //Nast�pne zdarzenie zostanie przechwycone na zboczu opadaj�cym
		return;
	}
	
	PORTB&=~_BV(PB5);  //Wy��cz LED
	
	TCCR1B=_BV(ICNC1) | _BV(ICES1) | _BV(WGM12) | _BV(CS12) | _BV(CS10);  //Nast�pne zdarzenie zostanie przechwycone na zboczu narastaj�cym
	if((PW >= DCF77_LO_beg) && (PW <= DCF77_LO_end)) DCF77Record[DCF77RecNo].Byte[DCF77_bitcounter / 8] &= ~(1<<DCF77_bitcounter % 8);  //Ustaw 0 na bicie odpowiadaj�cym aktualnie odbieranemu polu
     else if((PW < DCF77_HI_beg) || ( PW > DCF77_HI_end)) DCF77Record[DCF77RecNo].begin=1;   //Sprawd� timingi dla bitu o warto�ci 1

	DCF77_bitcounter++;
	if(DCF77_bitcounter == 59)
	{  //Ca�a struktura odebrana - sprawdzamy jej poprawno��
		DCF77Record[DCF77RecNo].begin=!DCF77_Data_Valid((DCF77_t*)&DCF77Record[DCF77RecNo]);  //Rzutowanie typ�w jest konieczne, gdy� porzucamy atrybut volatile
		if((DCF77Record[DCF77RecNo].begin==0) && (TimestampUpdate==true))
		{
			struct calendar_date cd={.second=58, .minute=BCDtoBIN(DCF77Record[DCF77RecNo].Minute), .hour=BCDtoBIN(DCF77Record[DCF77RecNo].Hour),
			                         .date=BCDtoBIN(DCF77Record[DCF77RecNo].Day)-1, .month=BCDtoBIN(DCF77Record[DCF77RecNo].Month)-1, .year=2000 + BCDtoBIN(DCF77Record[DCF77RecNo].Year)};
			//uint8_t hourtz=2;
			//if(DCF77Record[DCF77RecNo].TimeZone==2) hourtz=1;
		    //Timestamp=calendar_date_to_timestamp_tz(&cd,hourtz, 0);
			uint32_t tmp=calendar_date_to_timestamp(&cd);
			if(tmp)     //Nie uaktualniaj czasu je�li jest on b��dny
			{
				Timestamp=tmp;
				TimestampUpdate=false;
			}				
		}
	}
	
	if(DCF77_bitcounter > 59) DCF77Record[DCF77RecNo].begin=1; //B��d - za du�o bit�w
}

//Funkcja obs�ugi przerwania nadmiaru - wykrywanie przerwy synchronizacyjnej
ISR(TIMER1_COMPA_vect)
{
	TCCR1B=_BV(ICNC1) | _BV(ICES1) | _BV(WGM12) | _BV(CS12) | _BV(CS10);  //Oczekujemny na zdarzenie na zboczu narastaj�cym
	DCF77_bitcounter = 0;
	DCF77RecNo ^= 1;  //Zmieniamy bufor
	memset((void*)&DCF77Record[DCF77RecNo], 0xff, sizeof(DCF77_t));  //Zainicjuj struktur� zawieraj�c� dane DCF77	
}

void DCF77_Rec_Init()
{
//Konfiguracja struktur danych
	memset((void*)&DCF77Record[DCF77RecNo], 0xff, sizeof(DCF77_t));  //Zainicjuj struktur� zawieraj�c� dane DCF77
	
//Konfiguracja portu IO
	SET(DDR, DCF77_PD);       //Pin P1 - power down
	DCF77_Rec_En();           //Odblokuj odbiornik - pin P1
	
	OCR1A=DCF77_Interval;      //Okres licznika r�wny jest najd�u�szej przerwie synchronizacyjnej
	TCCR1A=0;                  //Od��cz piny OCx, wybierz tryb CTC
	TCCR1B=_BV(ICNC1) | _BV(ICES1) | _BV(WGM12) | _BV(CS12) | _BV(CS10);  // wybierz tryb 4, OCR1A okre�la top, preskaler 1024, noise canceller, zdarzenie na narastaj�cym zboczu
	TIMSK1=_BV(ICIE1) | _BV(OCIE1A);       //Odblokuj przerwanie compare match z OC1A oraz przerwanie przechwycenia zdarzenia
}

void DCF77_Rec_Dis()
{
	SET(PORT, DCF77_PD); //Zablokuj odbiornik (stan wysoki na pinie P1)
}

void DCF77_Rec_En()
{
	CLR(PORT, DCF77_PD); //Odblokuj odbiornik (stan niski na pinie P1)
}

bool GetDCF77Record(DCF77_t *dcf)
{
	bool ret=true;
	ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
	{
		uint8_t tmp=DCF77RecNo^1;       //B�dziemy kopiowa� ostatni aktualny rekord
		if(DCF77Record[tmp].begin==0)
		  memcpy(dcf, (void *)&DCF77Record[tmp], sizeof(DCF77_t));  //Kopiowanie danych musi przebiega� w spos�b atomowy
		   else ret=false;
	}
	return ret;
}

bool DCF77_Data_Valid(DCF77_t *data)
{
	if(data->begin != 0) return false;    //Ramka nie zaczyna si� od bitu 0
	if(data->TimeSep != 1) return false;  //Ramka nie ma separatora pola czasu r�wnego 1
	if(data->LastBit != 1) return false;  //Ostatni bit ramki musi by� r�wny 1
	
	return true;
}
