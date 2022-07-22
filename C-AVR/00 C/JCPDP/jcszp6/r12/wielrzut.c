/* wielrzut.c -- wielokrotny rzut koscmi            */
/* kompilowac z rzutkosc.c                          */
#include <stdio.h>
#include <stdlib.h>              /* potrzeba funkcji srand() */
#include <time.h>                /* potrzeba funkcji time()  */
#include "rzutkosc.h"            /* potrzeba funkcji rzucaj_n_razy()   */
                                 /* i zmiennej liczba_rzutow */
int main(void)
{
  int rzuty, wynik;
  int scianki, status ;

  srand((unsigned int) time(0)); /* losowe ziarno      */
  printf("Podaj liczbe scianek, 0 oznacza koniec.\n");
  while (scanf("%d", &scianki) == 1 && scianki > 0)
  {
      printf("Ile rzutow?\n");
      if ((status = scanf("%d", &rzuty)) != 1)
      {
        if (status == EOF)
          break; /* przerwanie petli */
        else
        {
          printf("Nalezy podac liczbe calkowita.");
          printf(" Sprobujmy jeszcze raz.\n");
          while (getchar() != '\n')
            continue; /* odrzucenie niepoprawnego wejscia */
          printf("Ile scianek? 0 oznacza koniec.\n");
          continue; /* nowy przebieg petli*/
        }
      }

      wynik = rzucaj_n_razy(rzuty, scianki);
      printf("Wyrzucono razem %d uzywajac %d %d-sciennych kosci.\n",
              wynik, rzuty, scianki);
      printf("Podaj liczbe scianek, 0 oznacza koniec.\n");
  }
  printf("Funkcja rzucaj() zostala wywolana %d razy.\n",
          liczba_rzutow);           /* zmienna zewnetrzna */
  
  printf("ZYCZE DUZO SZCZESCIA!\n");
  
  return 0;
}

