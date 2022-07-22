/*

serialOrgan.c

Poprzez port szeregowy odczytuje znak z klawiatury i gra wybraną nutę.

Definicje i inne makra znajdziesz w pliku organ.h
W pliku organ.c (nie zapomnij dodać go do pliku makefile) znajdziesz funkcje playNote() i rest()

*/

// ------- Preambuła -------- //
#include <avr/io.h>
#include <util/delay.h>
#include "organ.h"
#include "scale16.h"
#include "pinDefines.h"
#include "USART.h"

#define NOTE_DURATION     0xF000          /* określa czas trwania nuty */

int main(void) {

  // -------- Inicjalizacja --------- //
  SPEAKER_DDR |= (1 << SPEAKER);                 /* wyjście na głośnik */
  initUSART();
  printString("----- Organy z portem szeregowym ------\r\n");

  char fromCompy;              /* przechowuje dane z portu szeregowego */
  uint16_t currentNoteLength = NOTE_DURATION / 2;
  const uint8_t keys[] = { 'a', 'w', 's', 'e', 'd', 'f', 't',
    'g', 'y', 'h', 'j', 'i', 'k', 'o',
    'l', 'p', ';', '\''
  };
  const uint16_t notes[] = { G4, Gx4, A4, Ax4, B4, C5, Cx5,
    D5, Dx5, E5, F5, Fx5, G5, Gx5,
    A5, Ax5, B5, C6
  };
  uint8_t isNote;
  uint8_t i;

  // ------ Pętla zdarzeń ------ //
  while (1) {

                                                          /* Pobierz klawisz */
    fromCompy = receiveByte();          /* poczekaj aż ktoś naciśnie klawisz */
    transmitByte('N');   /* poinformuj komputer, że czekamy na następną nutę */

                                                                /* Graj nuty */
    isNote = 0;
    for (i = 0; i < sizeof(keys); i++) {
      if (fromCompy == keys[i]) {                /* dopasowanie w tabeli nut */
        playNote(notes[i], currentNoteLength);
        isNote = 1;                        /* zapamiętaj, że znaleziono nutę */
        break;                                        /* wyjście z pętli for */
      }
    }

                                   /* Obsluga klawiszy bez przypisanej nuty: */
					                           /* zmiana tempa i oczekiwanie */
    if (!isNote) {
      if (fromCompy == '[') {                         /* kod skracający nuty */
        currentNoteLength = NOTE_DURATION / 2;
      }
      else if (fromCompy == ']') {                   /* kod wydłużający nuty */
        currentNoteLength = NOTE_DURATION;
      }
      else {                                   /* nierozpoznane, oczekiwanie */
        rest(currentNoteLength);
      }
    }

  }                                                  /* Koniec pętli zdarzeń */
  return (0);
}
