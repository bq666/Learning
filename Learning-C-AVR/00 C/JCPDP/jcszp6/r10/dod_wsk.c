// dod_wsk.c -- dodawanie wskaznikow
#include <stdio.h>
#define ROZMIAR 4
int main(void)
{
    short daty[ROZMIAR];
    short * wski;
    short indeks;
    double rachunki[ROZMIAR];
    double * wskf;
    wski = daty;    // przypisanie wskaznikowi adresu tablicy
    wskf = rachunki;
    printf("%23s %15s\n", "short", "double");
    for (indeks = 0; indeks < ROZMIAR; indeks++)
        printf("wskazniki+ %d: %10p %10p\n",
                indeks, wski + indeks, wskf + indeks);
  
    return 0;
}

