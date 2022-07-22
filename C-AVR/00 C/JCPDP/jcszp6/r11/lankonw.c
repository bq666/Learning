/* lankonw.c -- testujemy strtol()  */
#include <stdio.h>
#include <stdlib.h>
#define LIMIT 30
char *wczytaj(char *z, int ile);

int main()
{
    char liczba[LIMIT];
    char * koniec;
    long wartosc;
    puts("Podaj liczbe (wpisz pusty wiersz, aby zakonczyc):");
    while(wczytaj(liczba, LIMIT) && liczba[0] != '\0')
    {
        wartosc = strtol(liczba, &koniec, 10);
        printf("wartosc: %ld, poprzedza %s (%d)\n", 
                      wartosc, koniec, *koniec);
        wartosc = strtol(liczba, &koniec, 16);
        printf("wartosc: %ld, poprzedza %s (%d)\n", 
                      wartosc, koniec, *koniec);
        puts("Nastepna liczba:");
    }
    puts("Do widzenia!\n");
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

