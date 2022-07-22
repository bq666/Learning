/* filmy3.c -- korzystanie z listy laczonej zgodnie z ATD */
/* kompilowac z plikiem list.c */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>    /* prototyp funkcji exit()         */
#include "lista.h"     /* definiuje typy Lista, Pozycja   */
void pokazfilm(Pozycja pozycja);
char * wczytaj(char *z, int ile);
int main(void)
{
   Lista filmy;
   Pozycja tymcz;

   /* inicjalizacja */
   InicjujListe(&filmy);
   if (PelnaLista(&filmy))
   {
      fprintf(stderr,"Brak pamieci! Do widzenia!\n");
      exit(1);
   }
   /* wczytywanie i zapis danych */
   puts("Podaj pierwszy tytul filmu:");
   while (wczytaj(tymcz.tytul, ROZT) != NULL && tymcz.tytul[0] != '\0')
   {
      puts("Podaj Twoja ocene <0-10>:");
      scanf("%d", &tymcz.ocena);
      while(getchar() != '\n')
         continue;
      if (DodajPozycje(tymcz, &filmy)== false)
      {
         fprintf(stderr,"Blad alokacji pamieci\n");
         break;
      }
      if (PelnaLista(&filmy))
      {
         puts("Lista jest juz pelna.");
         break;
      }
      puts("Podaj nastepny tytul filmu (pusty wiersz konczy wpisywanie):");
   }
   /* wypisywanie zawartosci listy */
   if (PustaLista(&filmy))
      printf("Nie wpisano zadnych danych. ");
   else
   {
      printf ("Oto lista filmow:\n");
      Przejdz(&filmy, pokazfilm);
   }
   printf("Wpisales %d filmow.\n", LiczbaPozycji(&filmy));

   /* porzadki */
   CzyscListe(&filmy);
   printf("Do widzenia!\n");
   return 0;
}
void pokazfilm(Pozycja pozycja)
{
      printf("Film: %s  Ocena: %d\n", pozycja.tytul,
         pozycja.ocena);
}
char * wczytaj(char *z, int ile)
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

