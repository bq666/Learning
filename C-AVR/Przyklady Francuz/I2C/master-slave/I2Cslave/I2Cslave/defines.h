/* Po��czenia KS0108 z AVR */
#define KS0108_RS C, 0
#define KS0108_RW C, 1
#define KS0108_E  C, 2
//#define KS0108_CS1	C, 3
#define KS0108_CS1	B, 0
#define KS0108_CS2	B, 1
//#define KS0108_RESET	C, 5		//Nale�y zdefiniowa� je�li u�ywamy RESET

/* Linie danych D0-D7 musz� odpowiada� PORTx0-PORTx7 */
#define KS0108_DATA D

#define SLOW_TEXT 0		//Je�li 1 to zostanie �yta wolniejsza procedura wy�wietlania tekstu
						//ale za to mo�na wy�wietla� z dok�adno�ci� do pixela
