// Pozytywka z przyciskiem

// ------- Preambula -------- //
#include <avr/io.h>
#include <util/delay.h>
#include "organ.h"
#include "scale16.h"
#include "pinDefines.h"

#define SONG_LENGTH  (sizeof(song) / sizeof(uint16_t))

int main(void) {
  const uint16_t song[] = {
    E6, E6, E6, C6, E6, G6, G5,
    C6, G5, E5, A5, B5, Ax5, A5,
    G5, E6, G6, A6, F6, G6, E6, C6, D6, B5,
    C6, G5, E5, A5, B5, Ax5, A5,
    G5, E6, G6, A6, F6, G6, E6, C6, D6, B5,
                                                                /* itd */
  };
  /* Zaczynamy od końca, ponieważ procedura odtwarzająca najpierw
     zwiększa indeks, a potem odtwarza dźwięk. W ten sposób po
	 uruchomieniu procesora zaczynamy dotwarzanie do początku. */
  uint8_t whichNote = SONG_LENGTH - 1;
  uint8_t wasButtonPressed = 0;

  // -------- Inicjalizacja --------- //
  SPEAKER_DDR |= (1 << SPEAKER);               /* głośnik jako wyjście */
  BUTTON_PORT |= (1 << BUTTON);  /* opornik podciągający dla przycisku */

  // ------ Pętla zdarzeń ------ //
  while (1) {
    if (bit_is_clear(BUTTON_PIN, BUTTON)) {
      if (!wasButtonPressed) {           /* jeżeli naciśnięto przycisk */
        whichNote++;                      /* przejdź do następnej nuty */
                                  /* ale nie wyjdź poza koniec tablicy */
        if (whichNote == SONG_LENGTH) {
          whichNote = 0;
        }
        wasButtonPressed = 1;
      }
      playNote(song[whichNote], 1600);
    }
    else {
      wasButtonPressed = 0;
    }
  }                                           /* koniec pętli zdarzeń */
  return (0);
}
