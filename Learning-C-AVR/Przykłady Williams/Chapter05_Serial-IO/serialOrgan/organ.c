/*
Prosta procedura otdwarzajace dźwięku na głośniku
*/

#include <avr/io.h>
#include <util/delay.h>
#include "organ.h"
#include "pinDefines.h"

void playNote(uint16_t wavelength, uint16_t duration) {
  uint16_t elapsed;
  uint16_t i;
  for (elapsed = 0; elapsed < duration; elapsed += wavelength) {
                     /* Pętla for ze zmienną ustala wysokość dźwięku */
    for (i = 0; i < wavelength; i++) {
      _delay_us(1);
    }
    SPEAKER_PORT ^= (1 << SPEAKER);
  }
}

void rest(uint16_t duration) {
  do {
    _delay_us(1);
  } while (--duration);
}
