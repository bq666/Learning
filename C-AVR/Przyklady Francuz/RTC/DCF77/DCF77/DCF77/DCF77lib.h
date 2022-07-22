/*
 * DCF77.h
 *
 * Created: 2012-03-06 19:21:38
 *  Author: tmf
 */ 


#ifndef DCF77_H_
#define DCF77_H_

#include <stdint.h>

typedef union
{
 struct  
 {
	uint8_t  begin       : 1;                //Bit startu
	uint16_t reserved    : 14;               //Zarezerwowane
	uint8_t  backupant   : 1;                //1 - antena pomocnicza, 0 - normalna
	uint8_t  TimeZoneChg : 1;                //1 - zapowied� zmiany czasu
	uint8_t  TimeZone    : 2;                //10 - czas zimowy (UTC+1), 01 - czas letni (UTC+2)
	uint8_t  LeapSec     : 1;                //1- zapowied� dodatkowej sekundy
	uint8_t  TimeSep     : 1;                //Separator pola czasu, zawsze 1
	uint8_t  Minute      : 7;                //Minuty w BCD (0-59)
	uint8_t  MinParity   : 1;                //Parzysto�� dla pola Minute
	uint8_t  Hour        : 6;                //Godziny w BCD (0-23)
	uint8_t  HourParity  : 1;                //Parzysto�� dla pola Mour
	uint8_t  Day         : 6;                //Dzie� w BCD (1-31)
	uint8_t  DayNumber    : 3;               //Numer dnia (1-Poniedzia�ek, 7-Niedziela)
	uint8_t  Month       : 5;                //Miesi�c w BCD (1-12)
	uint8_t  Year        : 8;                //Rok w BCD (00-99)
	uint8_t  DateParity  : 1;                //Parzysto�� dla p�l Day-Year
	uint8_t  LastBit     : 1;                //Ostatni bit ko�cz�cy ramk�
 };
 uint8_t Byte[0];                            //Umo�liwia bitowy dost�p do powy�szej struktury 
} DCF77_t;

extern volatile uint8_t DCF77_bitcounter;    //Licznik odebranych bit�w
extern volatile DCF77_t DCF77Record[2];      //Rekord danych DCF77
extern volatile uint32_t Timestamp;          //Czas w formacie EPOCH
extern volatile _Bool TimestampUpdate;       //true - uaktualnij warto�� zmiennej Timestamp wg aktualnego rekordu DCF77

void DCF77_Rec_Init();                       //Zainicjuj obs�ug� odbiornika DCF77
void DCF77_Rec_Dis();                        //Zablokuj odbiornik
void DCF77_Rec_En();                         //Odblokuj odbiornik

_Bool DCF77_Data_Valid(DCF77_t *data);       //Sprawd� czy wskazany rekord zawiera prawid�ow� ramk� danych DCF77
_Bool GetDCF77Record(DCF77_t *);             //Zwr�� aktualne dane DCF77, zwraca false je�li ich brak
uint8_t BCDtoBIN(uint8_t aBCD)               //Konwersja z BCD na format binarny
{
	return ((aBCD & 0xF0)>>4)*10 + (aBCD & 0x0F);
}

#endif /* DCF77_H_ */