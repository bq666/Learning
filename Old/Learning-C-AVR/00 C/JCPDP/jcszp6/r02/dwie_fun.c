/* dwie_fun.c -- program wykorzystujacy dwie funkcje w jednym pliku */
#include <stdio.h>
void lokaj(void);            /* Prototyp funkcji wg ANSI/ISO C      */
                             /* w K&R C byloby to: void lokaj();    */
int main(void)
{
   printf("Wywolam funkcje lokaja.\n");
   lokaj();
   printf("Tak. Przynies mi herbate i zapisywalne DVD.\n");
   return 0;
}

void lokaj(void)             /* poczatek definicji funkcji          */
{
   printf("Pan wzywal?\n");
}

