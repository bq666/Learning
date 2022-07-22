/* test.c -- test funkcji skracajacej lancuchy */
#include <stdio.h>
#include <string.h> /* zawiera prototypy funkcji lancuchowych */
void skroc(char *, unsigned int);
int main(void)
{
    char tekst[] = "Wyjasnienia powinny byc tak proste jak to mozliwe,"
                                    " ale nie prostsze. ";
    puts(tekst);
    skroc(tekst,49);
    puts(tekst);
    puts("Spojrzmy na reszte lancucha. ");
    puts(tekst+50);
    return 0;
}
void skroc(char *lancuch, unsigned int rozmiar)
{
    if (strlen(lancuch) > rozmiar)
        *(lancuch + rozmiar) = '\0';
}

