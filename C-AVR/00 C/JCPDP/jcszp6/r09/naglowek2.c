/* naglowek2.c */
#include <stdio.h>
#include <string.h>          /* zawiera prototyp strlen()     */
#define NAZWA "MEGATHINK, INC."
#define ADRES "10 Megabuck Plaza"
#define MIEJSCOWOSC "Megapolis, CA 94904"
#define LIMIT 40
#define ODSTEP ' '
void n_znak(char ch, int num);
int main(void)
{
  int odstepy;
  n_znak('*', LIMIT);        /* stale jako argumenty          */
  putchar('\n');
  n_znak(ODSTEP, 12);        /* stale jako argumenty          */
  printf("%s\n", NAZWA);
  odstepy = (LIMIT - strlen(ADRES)) / 2;
                             /* program oblicza, ile odstepow */
                             /* nalezy wyswietlic             */
  n_znak(ODSTEP, odstepy);   /* zmienna jako argument         */
  printf("%s\n", ADRES);
  n_znak(ODSTEP, (LIMIT - strlen(MIEJSCOWOSC)) / 2);
                             /* wyrazenie jako argument       */
  printf("%s\n", MIEJSCOWOSC);
  n_znak('*', LIMIT);
  putchar('\n');
  return 0;
}
/* definicja funkcji n_znak() */
void n_znak(char ch, int num)
{
  int licznik;
  for (licznik = 1; licznik <= num; licznik++)
    putchar(ch);
}

