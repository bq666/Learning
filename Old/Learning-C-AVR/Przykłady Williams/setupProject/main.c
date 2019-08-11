
#include "main.h" 

// -------- Global Variables --------- //

// -------- Functions --------- //

int main(void) {
  // -------- Inicjalizacja --------- //
  
  // clock_prescale_set(clock_div_1);                 /* CPU Clock: 8 MHz */
  initUSART();
  printString("OK");

  // ------ Pętla zdarzeń ------ //
  while (1) {



  }                                                  /* Koniec pętli zdarzeń */
  return (0);                            /* Ta instrukcja nie zostanie wykonana */
}
