/* podwdol.c -- dwukrotnie dolacza plik naglowkowy */
#include <stdio.h>
#include "daneos.h"
#include "daneos.h"   /* przypadkowe drugie dolaczenie */
int main()
{
    daneos zwyciezca = {"Less", "Ismoor"};
    printf("Zwyciezca jest %s %s.\n", zwyciezca.imie,
            zwyciezca.nazw);
    return 0;
}

