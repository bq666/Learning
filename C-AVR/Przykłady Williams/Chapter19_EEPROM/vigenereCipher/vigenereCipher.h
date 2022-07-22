
#include <avr/io.h>
#include <avr/eeprom.h>
#include "USART.h"

#define MAX_TEXT_LENGTH  256
#define CODE_LEN         64

// -------- Zmienne globalne --------- //
char EEMEM code0[CODE_LEN] = "ettubrute";
char EEMEM code1[CODE_LEN] = "attackatdawn";
char EEMEM code2[CODE_LEN] = "theraininspainfallsmainlyontheplain";
char EEMEM code3[CODE_LEN] = "ablewasiereisawelba";
char *codePointers[] = { code0, code1, code2, code3 };

// Menu strings.  Why not store them in EEPROM?
char EEMEM welcomeString[] = "\r\n--==  Szyfr Vigenere'a  ==--\r\n";
char EEMEM menuEncode[] = " [e] zeby zakodowac tekst\r\n";
char EEMEM menuDecode[] = " [d] zeby odkodowac tekst\r\n\r\n";
char EEMEM menuEnterText[] = " [n] zeby wprowadzic nowy tekst\r\n";
char EEMEM menuCodeText[] = " [c] zeby wybrac fraze szyfrujaca\r\n";
char EEMEM menuChangeCode[] = " [x] zeby zmienic frazy szyfrujace\r\n";
char EEMEM promptCode[] = "kod: ";
char EEMEM promptText[] = "\r\ntekst: ";

char EEMEM promptSelectCode[] = "Wybierz fraze szyfrujaca:\r\n\r\n";
char EEMEM promptTypeText[] = "Wpisz swoj tekst: ";

// Pobiera adres ciągu znaków w pamięci EEPROM i go wypisuje
// Używane do tworzenia menu
void printFromEEPROM(char *eepromString);

// Pobiera dane z portu szeregowego i zapisuje w tablicy znaków
void enterText(char text[]);

// Odczytuje frazy szyfrujące z pamięci EEPROM i wypisuje je.
// Jako tymczasowy bufor używa zmiennej codeBuffer
void displayCodes(void);

// Zmienia frazę szyfrującą zarówno w pamięci EEPROM jak i w aktualnym kodzie
void changeCode(char codeBuffer[]);

// Wybiera frazę szyfrującą z pamięci EEPROM
void selectCode(char code[]);

// Zaszyfrowuje ciąg znaków w miejscu
void encodeVigenere(char text[], char code[]);

// Rozszyfrowuje ciąg znaków w miejscu
void decodeVigenere(char text[], char code[]);
