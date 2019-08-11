// zasieg.c -- wyjscie poza granice tablicy
#include <stdio.h>
#define ROZMIAR 4
int main(void)
{
    int zm1 = 44;
    int tab[ROZMIAR];
    int zm2 = 88;
    int i;
    printf("zm1 = %d, zm2 = %d\n", zm1, zm2);
    for (i = -1; i <= ROZMIAR; i++)
        tab[i] = 2 * i + 1;
        
    for (i = -1; i < 7; i++)
        printf("%2d  %d\n", i , tab[i]);
    printf("zm1 = %d, zm2 = %d\n", zm1, zm2);
    printf("adres tab[-1]: %p\n", &tab[-1]);
    printf("adres tab[4]: %p\n", &tab[4]);
    printf("adres zm1: %p\n", &zm1);
    printf("adres zm2: %p\n", &zm2);
    return 0;
}

