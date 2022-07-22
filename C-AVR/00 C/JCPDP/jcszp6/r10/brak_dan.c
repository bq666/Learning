/* brak_dan.c -- niezainicjalizowana tablica */
#include <stdio.h>
#define ROZMIAR 4
int main(void)
{
    int brak_danych[ROZMIAR];  /* niezainicjalizowana tablica */
    int i;
    printf("%2s%14s\n",
           "i", "brak_danych[i]");
    for (i = 0; i < ROZMIAR; i++)
        printf("%2d%14d\n", i, brak_danych[i]);
  
    return 0;
}

