/*
 * d_led.h
 *
 * Created: 2017-03-12 22:16:45
 *  Author: bq666
 */ 


#ifndef D_LED_H_				//dyrektywy zabezpiecz�j�ce przed wielokrotnym do��czeniem tego samego pliku nag��wkowego,
#define D_LED_H_				//je�li b�dzie do��czony w wielu r�nych plikach programu 

//definicje port�w i pin�w wy�wietlacza dla u�atwienia jako sta�e preprocesora:
#define LED_DATA PORTA			//port z pod��czonymi segmentami 
#define LED_DATA_DIR DDRA
#define ANODY_PORT PORTC
#define ANODY_DIR DDRC 

#define CA1 (1<<PC0)			// CA1 oznacza bit nr 0 portu C
#define CA2 (1<<PC1)			// CA2 oznacza bit nr 1 portu C
#define CA3 (1<<PC2)			// CA3 oznacza bit nr 2 portu C
#define CA4 (1<<PC3)			// CA4 oznacza bit nr 3 portu C

#define SEG_A (1<<0)            // Definicje segment�w 
#define SEG_B (1<<1)
#define SEG_C (1<<2)
#define SEG_D (1<<3)
#define SEG_E (1<<4)
#define SEG_F (1<<5)
#define SEG_G (1<<6)
#define SEG_DP (1<<7)


extern volatile uint8_t cy1;	//same DEKLARACJE zmiennych globalnych na potrzeby wykorzystania ich w innych plikach projektu
extern volatile uint8_t cy2;	//przydomek EXTERN powoduje, �e te zmienne b�d� dost�pne we wszystkich mod�ach, 
extern volatile uint8_t cy3;	//kt�re do��cz� plik d_led.h za pomoc� dyrektywy #include 
extern volatile uint8_t cy4;

void d_led_init(void);



#endif /* D_LED_H_ */