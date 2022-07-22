/* reduktor.c -- zmniejsza rozmiar Twoich plikow o dwie trzecie ! */
#include <stdio.h>
#include <stdlib.h>      // dla exit()
#include <string.h>

#define DL 40 
int main(int argc, char *argv[])
{
    FILE  *we, *wy;     // deklaracja 2 wskaznikow plikowych
    int ch;
    char nazwa[DL];     // miejsce na nazwy pliku wyjsciowego
    int licznik = 0;
    if (argc < 2)       // sprawdza obecnosc argumentu
    {
         fprintf(stderr, "Sposob uzycia: %s nazwa_pliku\n", argv[0]);
         exit(EXIT_FAILURE);
    }
    // plik wejsciowy
    if ((we = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stderr, "Nie moglem otworzyc pliku \"%s\".\n",
                argv[1]);
        exit(EXIT_FAILURE);
    }

    // przygotowanie pliku wynikowego
    strncpy(nazwa,argv[1], DL-5); // kopiuje nazwe pliku do tablicy
    nazwa[DL-5] = '\0';
    strcat(nazwa,".red");    // dodaje .red do nazwy

    if ((wy = fopen(nazwa, "w")) == NULL)
    {                        // otwiera plik do zapisu
        fprintf(stderr,"Nie mozna utworzyc pliku wyjsciowego.\n");
        exit(EXIT_FAILURE);
    }
    // kopiowanie danych
    while ((ch = getc(we)) != EOF)
        if (licznik++ % 3 == 0)
            putc(ch, wy);    // wyswietla co trzeci znak
    // sprzatanie
    if (fclose(we) != 0 || fclose(wy) != 0)
        fprintf(stderr,"Blad przy zamykaniu plikow.\n");
    return 0;
}

