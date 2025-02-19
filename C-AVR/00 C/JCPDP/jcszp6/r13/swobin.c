/* swobin.c -- dostep swobodny, binarne we-wy  */
#include <stdio.h>
#include <stdlib.h>
#define DL_TAB 1000
int main()
{
    double liczby[DL_TAB];
    double wartosc;
    const char * plik = "liczby.dat";
    int i;
    long poz;
    FILE *plikwewy;

    // tworzy zestaw wartosci typu double
    for(i = 0; i < DL_TAB; i++)
        liczby[i] = 100.0 * i + 1.0 / (i + 1);
    // probuje otworzyc plik
    if ((plikwewy = fopen(plik, "wb")) == NULL)
    {
        fprintf(stderr, "Blad otwarcia pliku %s do zapisu.\n", plik);
        exit(EXIT_FAILURE);
    }
    // zapisuje tablice do pliku w formacie binarnym
    fwrite(liczby, sizeof (double), DL_TAB, plikwewy);
    fclose(plikwewy);
    if ((plikwewy = fopen(plik, "rb")) == NULL)
    {
        fprintf(stderr, 
            "Blad otwarcia pliku %s do dostepu swobodnego.\n", plik);
        exit(EXIT_FAILURE);
    }
    // odczytuje z pliku wybrane pozycje
    printf("Podaj indeks z przedzialu 0-%d.\n", DL_TAB - 1);
    while (scanf("%d", &i) == 1 && i >= 0 && i < DL_TAB)
    {
        poz = (long) i * sizeof(double);   /* oblicza offset            */
        fseek(plikwewy, poz, SEEK_SET);    /* przechodzi w odp. miejsce */
        fread(&wartosc, sizeof (double), 1, plikwewy);
        printf("Wartosc pod tym indeksem to %f.\n", wartosc);
        printf("Kolejny indeks (wyjscie poza przedzial konczy program):\n");
    }   
    // sprzatanie
    fclose(plikwewy);
    puts("Na razie!");
    return 0;
}

