#ifndef LCD_trans_h__
#define LCD_trans_h__

#include <stdbool.h>
#include <stdint.h>
#include <avr/io.h>

#define LCD_ACCESSTIME 0.00004     //Czas jednej operacji IO na LCD to 4 us
#define LCD_MAXTRANS 10            //Maksymalna liczba pami�tanych transakcji
typedef enum {LCD_Text} LCD_Cmd;   //Lista polece� realizowanych przez sterownik

typedef struct
{
	volatile bool    Ready : 1;         //true je�li transakcja zrealizowana
	bool  SelfDel : 1;                  //true je�li pami�� przydzielona transakcji ma zosta� zwolniona
	LCD_Cmd   cmd : 2;                  //Polecenie do zrealizowania
	uint8_t   len : 6;                  //D�ugo�� polecenia
	unsigned      : 0;                  //Wyr�wnanie do granicy bajtu
	uint8_t  data[];                    //Dane transakcji
} LCD_trans;



void LCD_Init();                                   //Inicjalizacja LCD i transakcji
void LCD_Timer_init();                             //Inicjalizacja timera
bool LCD_PutText(uint8_t x, uint8_t y, char *txt); //Wy�wietl napis na LCD
bool LCD_PutText_B(uint8_t x, uint8_t y, char *txt, LCD_trans *buf, bool autodel);

static inline bool LCD_IsTransCompleted(LCD_trans *trans)  //Czy transakcja zako�czona?
{
	return trans->Ready;
}

#endif // LCD-trans_h__
