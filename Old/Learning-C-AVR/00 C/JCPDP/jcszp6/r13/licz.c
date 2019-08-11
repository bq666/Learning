/* licz.c -- korzystanie ze standardowego we/-wy  */
#include <stdio.h>
#include <stdlib.h> // prototyp funkcji exit()
int main(int argc, char *argv[])
{
    int ch;         // przechowuje kolejne odczytywane znaki
    FILE *wp;       // "wskaznik plikowy"
    unsigned long licznik = 0;
    if (argc != 2)
    {
        printf("Sposob uzycia: %s nazwa_pliku\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if ((wp = fopen(argv[1], "r")) == NULL)
    {
        printf("Nie mozna otworzyc %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    while ((ch = getc(wp)) != EOF)
    {
       putc(ch,stdout);
       licznik++;
    }
    fclose(wp);
    printf("Plik %s zawiera %lu znakow\n", argv[1], licznik);
    return 0;
}

