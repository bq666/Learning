/* pobr_lan.c -- korzystanie z funkcji scanf() */
#include <stdio.h>
int main(void)
{
    char imie1[11], imie2[11];
    int licznik;
    printf("Podaj 2 imiona.\n");
    licznik = scanf("%5s %10s", imie1, imie2);
    printf("Odczytalem %d imiona: %s i %s.\n",
           licznik, imie1, imie2);
    return 0;
}

