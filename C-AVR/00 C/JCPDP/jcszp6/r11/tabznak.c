// tabznak.c -- tablice wskaznikow, tablice lancuchow
#include <stdio.h>
#define DLUGOSC 40
#define MAX 5

int main(void)
{
   const char *wymagania[MAX] = {
     "Dodawanie w pamieci",
     "Bezbledne mnozenie",
     "Szybkie zapamietywanie",
     "Doslowne wykonywanie polecen",
     "Programowanie w C"
   };

   char umiejetnosci[MAX][DLUGOSC] = {
     "Chodzenie wzdluz linii",
     "Spanie", "Ogladanie telewizji",
     "Wysylanie poczty", "Czytanie e-maili"
   };

   int i;
   puts("Porownajmy:");
   printf ("%-36s %-25s\n", "Wymagania", "Umiejetnosci");
   for (i = 0; i < MAX; i++)
      printf("%-36s %-25s\n", wymagania[i], umiejetnosci[i]);
   printf("\nsizeof wymagania: %zd, sizeof umiejetnosci: %zd\n",
      sizeof(wymagania), sizeof(umiejetnosci));

   return 0;
}

