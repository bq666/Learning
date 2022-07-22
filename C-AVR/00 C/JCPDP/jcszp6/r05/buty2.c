/* buty2.c -- oblicza dlugosc stopy dla kilku numerow buta */
#include <stdio.h>
#define KOREKTA -1  // jeden rodzaj stalej
int main(void)
{
  const double MNOZNIK = 0.666666; // drugi rodzaj stalej
  double but, stopa;

  printf("Rozmiar buta      Dlugosc stopy\n");
  but = 24.0;
  while (but < 45)            /* poczatek petli while */
  {                           /* poczatek bloku       */
     stopa = MNOZNIK * but + KOREKTA;
     printf("%8.1f %15.2f cm\n", but, stopa);
     but = but + 1.0;
  }                           /* koniec bloku         */
  printf("Jesli but pasuje, nos go.\n");
  return 0;
}

