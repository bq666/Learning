#include <avr/pgmspace.h>
#include <avr/eeprom.h>

// rozdzielczoœæ wyœwietlacza LCD (wiersze/kolumny)
#define LCD_Y 2					// liczba wierszy wyœwietlacza 
#define LCD_X 16				// liczka kolumn wyœwietlacza
#define USE_RW 1				// 0 - pin R/W do GND, 1 - pin R/W do uC

// konfiguracja pinów do linii D7-D4 LCD
#define LCD_D7PORT A
#define LCD_D7 6
#define LCD_D6PORT A
#define LCD_D6 5
#define LCD_D5PORT A
#define LCD_D5 4
#define LCD_D4PORT A
#define LCD_D4 3

// konfiguracja pinów do sygna³ów RS, R/W, E 
#define LCD_RSPORT A
#define LCD_RS 0
#define LCD_RWPORT A
#define LCD_RW 1
#define LCD_EPORT A
#define LCD_E 2

// konfiguracja adresów DDRAM dla wyœwietlacza 2 lub 4 wierszowego
#if ( (LCD_Y == 4) && (LCD_X == 20) )
#define LCD_LINE1 0x00	// adres 1 znaku 1 wiersza
#define LCD_LINE2 0x28	// adres 1 znaku 2 wiersza 
#define LCD_LINE3 0x14	// adres 1 znaku 3 wiersza 
#define LCD_LINE4 0x54	// adres 1 znaku 4 wiersza 
#else
#define LCD_LINE1 0x00	// adres 1 znaku 1 wiersza
#define LCD_LINE2 0x40	// adres 1 znaku 2 wiersza
#define LCD_LINE3 0x10	// adres 1 znaku 3 wiersza
#define LCD_LINE4 0x50	// adres 1 znaku 4 wiersza
#endif

// makra upraszczaj¹ce dostêp do portów
// *** PORT
#define PORT(x) SPORT(x)
#define SPORT(x) (PORT##x)
// *** PIN
#define PIN(x) SPIN(x)
#define SPIN(x) (PIN##x)
// *** DDR
#define DDR(x) SDDR(x)
#define SDDR(x) (DDR##x)

// makra upraszaj¹ce sterowanie RS, RW, E
#define SET_RS PORT(LCD_RSPORT) |= (1<<LCD_RS)		// stan wysoki na RS
#define CLR_RS PORT(LCD_RSPORT) &= ~(1<<LCD_RS)		// stan niski na RS
#define SET_RW PORT(LCD_RWPORT) |= (1<<LCD_RW)		// stan wysoki na RW
#define CLR_RW PORT(LCD_RWPORT) &= ~(1<<LCD_RW)		// stan niski na RW
#define SET_E PORT(LCD_EPORT) |= (1<<LCD_E)			// stan wysoki na E
#define CLR_E PORT(LCD_EPORT) |= (1<<LCD_E)			// stan niski na E

// konfiguracja LCD
#define USE_LCD_LOCATE 1							// ustawia kursor na pozycji Y,X (Y = 0-3, X = 0 - n)
#define USE_LCD_STR_P 0								// wysy³a string umieszczony w FLASH
#define USE_LCD_STR_E 0								// wysy³a string umieszczony w EEPROM 

#define USE_LCD_INT 0								// wyœwietla liczbê dziesiêtn¹ na LCD
#define USE_LCD_HEX 0								// wyœwietla liczbê szesnastkow¹ na LCD

#define USE_LCD_DEFCHAR 0							// wysy³a zdefiniowany znak z pamiêci RAM
#define USE_LCD_DEFCHAR_P 0							// wysy³a zdefiniowany znak z pamiêci FLASH
#define USE_LCD_DEFCHAR_E 0							// wysy³a zdefiniowany znak z pamiêci EEPROM

#define USE_LCD_CURSOR_ON 0							// obs³uga w³/wy³ kursora
#define USE_LCD_CURSOR_BLINK 0						// obs³uga w³/wy³ migania kursora 
#define USE_LCD_CURSOR_HOME 0						// ustaw kursor na pozycji pocz¹tkowej 


void LCD_init ();						// Ustawienie pinów pod³¹czonych do LCD jako wyjœcia, wyzerowanie linii steruj¹cych 
void lcd_write_cmd (uint8_t cmd);
void lcd_write_data (uint8_t data);
void lcd_cls (void);
void lcd_str (char * str);
void lcd_str_P(char * str);
void lcd_str_E(char *str);