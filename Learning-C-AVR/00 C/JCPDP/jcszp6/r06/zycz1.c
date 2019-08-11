/* zycz1.c -- petla liczaca */
#include <stdio.h>
int main(void)
{
  const int LICZBA = 22;
  int licznik = 1;               // inicjalizacja

  while (licznik <= LICZBA)           // test
  {
       printf("Wesolych Swiat!\n");   // czynnosc
       licznik++;                     // aktualizacja licznika
  }
  return 0;
}

