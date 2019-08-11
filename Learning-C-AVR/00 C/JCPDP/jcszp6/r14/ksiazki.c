/* ksiazki.c -- spis wielu ksiazek */
#include <stdio.h>
#include <string.h>
char * wczytaj(char * z, int ile);
#define MAXTYT   40
#define MAXAUT   40
#define MAXKS   100              /* maksymalna liczba ksiazek     */
struct ksiazka {                 /* definiuje szablon ksiazka     */
    char tytul[MAXTYT];
    char autor[MAXAUT];
    float wartosc;
};
int main(void)
{
     struct ksiazka bibl[MAXKS]; /* tablica struktur typu ksiazka */
     int licznik = 0;
     int index;
     printf("Podaj tytul ksiazki.\n");
     printf("Aby zakonczyc, wcisnij nacisni j [enter] na poczatku wiersza.\n");
     while (licznik < MAXKS
          && wczytaj(bibl[licznik].tytul, MAXTYT) != NULL
          && bibl[licznik].tytul[0] != '\0')
     {
          printf("Teraz podaj autora.\n");
          wczytaj(bibl[licznik].autor, MAXTYT);
          printf("Teraz podaj wartosc.\n");
          scanf("%f", &bibl[licznik++].wartosc);
          while (getchar() != '\n')
               continue;               /* czysci wiersz wejsciowy */
          if (licznik < MAXKS)
          printf("Podaj kolejny tytul.\n");
     }
     if (licznik > 0)
     {
          printf("Oto lista Twoich ksiazek:\n");
          for (index = 0; index < licznik; index++)
               printf("%s, autor: %s, cena: %.2f zl\n", bibl[index].tytul,
                    bibl[index].autor, bibl[index].wartosc);
     }
     else
          printf("Zadnych ksiazek? Szkoda\n");
     return 0;
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

