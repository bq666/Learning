/* wejscie.c -- poczatek jakiegos programu */
#include <stdio.h>
#include <string.h>
#define ROZMIAR 81
#define GRAN 100
#define STOP "koniec"
char *wczytaj(char *z, int ile);

int main(void)
{
  char wejscie[GRAN][ROZMIAR];
  int licz = 0;
 
  printf("Wpisz maksymalnie %d wierszy (wpisz koniec, aby zakonczyc):\n",
    GRAN);
  while (licz < GRAN && wczytaj(wejscie[licz], ROZMIAR) != NULL &&
         strcmp(wejscie[licz],STOP) != 0)
  {
      licz++;
  }
  printf("Podano %d lancuchow\n", licz);
  return 0;
}
char *wczytaj(char *z, int ile)
{
    char * wynik;
    int i = 0;

    wynik = fgets(z, ile, stdin);
    if (wynik) // wynik rozny od NULL 
    {
        while (z[i] != '\n' && z[i] != '\0')
            i++;
        if (z[i] == '\n')
            z[i] = '\0'; // znak nowego wiersza -> znak pusty 
        else             // z[i] == '\0'
            while (getchar() != '\n')
                continue;
    }
    return wynik;
}

