/* naglowek1.c */
#include <stdio.h>
#define NAZWA "MEGATHINK, INC."
#define ADRES "10 Megabuck Plaza"
#define MIEJSCOWOSC "Megapolis, CA 94904"
#define LIMIT 40
void gwiazdki(void);  /* prototyp funkcji */
int main(void)
{
    gwiazdki();
    printf("%s\n", NAZWA);
    printf("%s\n", ADRES);
    printf("%s\n", MIEJSCOWOSC);
    gwiazdki();           /* wywolanie funkcji */
    return 0;
}
void gwiazdki(void)       /* definicja funkcji */
{
    int licznik;
    for (licznik = 1; licznik <= LIMIT; licznik++)
        putchar('*');
    putchar('\n');
}

