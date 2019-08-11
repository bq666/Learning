/* filmy2.c -- korzystanie z listy laczonej struktur */
#include <stdio.h>
#include <stdlib.h>      /* zawiera prototyp malloc()               */
#include <string.h>      /* zawiera prototyp strcpy()               */
#define ROZT    45       /* rozmiar tablicy przechowujacej tytul    */
struct film {
   char tytul[ROZT];
   int ocena;
   struct film * nast;   /* wskazuje na nastepna strukture w liscie */
};
char *wczytaj(char *z, int ile);
int main(void)
{
   struct film * glowny = NULL;
   struct film * poprz, * biezacy;
   char wejscie[ROZT];
   /* pobieranie i zapisywanie informacji */
   puts("Podaj pierwszy tytul filmu:");
   while (wczytaj(wejscie, ROZT) != NULL && wejscie[0] != '\0')
   {
      biezacy = (struct film *) malloc(sizeof(struct film));
      if (glowny == NULL)         /* pierwsza struktura    */
         glowny = biezacy;
      else                        /* kolejne struktury     */
         poprz->nast = biezacy;
      biezacy->nast = NULL;
      strcpy(biezacy->tytul, wejscie);
      puts("Podaj Twoja ocene <0-10>:");
      scanf("%d", &biezacy->ocena);
      while(getchar() != '\n')
         continue;
      puts("Podaj nastepny tytul filmu (pusty wiersz konczy program):");
      poprz = biezacy;
   }
   /* wypisanie listy filmow */
   if (glowny == NULL)
      printf("Nie wpisano zadnych danych. ");
   else
      printf ("Oto lista filmow:\n");
   biezacy = glowny;
   while (biezacy != NULL)
   {
      printf("Film: %s  Ocena: %d\n", biezacy->tytul, biezacy->ocena);
      biezacy = biezacy->nast;
   }
   /* Przebieg programu zakonczony, zwalniamy przydzielona pamiec */
   biezacy = glowny;
   while (biezacy != NULL)
   {
      poprz = biezacy; 
      biezacy = poprz->nast;
      free(poprz);
   }

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

