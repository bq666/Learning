/*
Program szyfrującu i rozszyfrowujący za pomocą szyfru Vigenere'a
Stał się pretekstem do zabaw z pamięcią EEPROM
 */

#include "vigenereCipher.h"

// -------- Funkcje --------- //

void printFromEEPROM(char *eepromString);
void enterText(char text[]);
void displayCodes(void);
void changeCode(char codeBuffer[]);
void selectCode(char code[]);
void encodeVigenere(char text[], char code[]);
void decodeVigenere(char text[], char code[]);

int main(void) {
  // -------- Inicjalizacja --------- //

  char textBuffer[MAX_TEXT_LENGTH];
  char codeString[CODE_LEN];
  char input;
  initUSART();

  // ------ Pętla zdarzeń ------ //
  while (1) {

    // Menu
    printFromEEPROM(welcomeString);
    // .... kolejne instrukcje wypisujące pozycje menu
    printFromEEPROM(menuDecode);
    input = receiveByte();

    switch (input) {
    case 'e':                  // szyfrowanie
      encodeVigenere(textBuffer, codeString);
      break;
    case 'd':                  // rozszyfrowywanie
      decodeVigenere(textBuffer, codeString);
      break;
    case 'n':                  // nowy tekst
      printFromEEPROM(promptTypeText);
      enterText(textBuffer);
      break;
    case 'c':                  // wybieranie frazy
      selectCode(codeString);
      break;
    case 'x':                  // zmiana frazy
      changeCode(codeString);
      break;
    }
  }                                                    /* Koniec pętli zdarzeń */
  return (0);                     /* ta instrukcja nigdy nie zostanie wykonana */
}
