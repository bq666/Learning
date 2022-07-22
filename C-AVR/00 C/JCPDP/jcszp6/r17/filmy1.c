/* filmy1.c -- korzystanie z tablicy struktur */
#include <stdio.h>
#include <string.h>
#define ROZT        45      /* rozmiar tablicy przechowujacej tytul */
#define FMAX         5      /* maksymalna liczba filmow             */
struct film {
   char tytul[ROZT];
   int ocena;
};
char *wczytaj(char *z, int ile);
int main(void)
{
   struct film filmy[FMAX];
   int i = 0;
   int j;
   puts("Podaj pierwszy tytul filmu:");
   while (i < FMAX && wczytaj(filmy[i].tytul, ROZT) != NULL &&
      filmy[i].tytul[0] != '\0')
   {
      puts("Podaj Twoja ocene <0-10>:");
      scanf("%d", &filmy[i++].ocena);
      while(getchar() != '\n')
         continue;
      puts("Podaj nastepny tytul filmu (pusty wiersz konczy program):");
   }
   if (i == 0)
      printf("Nie wpisano zadnych danych. ");
   else
      printf ("Oto lista filmow:\n");
   for (j = 0; j < i; j++)
      printf("Film: %s  Ocena: %d\n", filmy[j].tytul, 
         filmy[j].ocena);
   printf("Do widzenia!\n");
   return 0;
}
char *wczytaj(char *z, int ile)
{
    char * wynik;
    char * tutaj;
    wynik = fgets(z, ile, stdin);
    if (wynik)
    {
        tutaj = strchr(z, '\n'); // szukamy nowego wiersza
        if (tutaj) // jesli adres jest rozny od NULL
            *tutaj = '\0'; // zamieniamy znak nowego wiersza na pusty
        else
            while (getchar() != '\n')
                continue;
    }
    return wynik;
}

