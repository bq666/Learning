/* dodaj.c -- piec typow instrukcji */
#include <stdio.h>
int main(void)          /* oblicza sume pierwszych 20 liczb calkowitych */
{
  int licznik, suma;            /* instrukcja deklaracji           */

  licznik = 0;                  /* instrukcja przypisania          */
  suma = 0;                     /* jak wyzej                       */
  while (licznik++ < 20)        /* instrukcja                      */
     suma = suma + licznik;     /*       while                     */
  printf("suma = %d\n", suma);  /* instrukcja wywolania funkcji    */
  return 0;                     /* instrukcja zwrotu */
}

