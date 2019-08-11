/* mak_arg.c -- makra z argumentami */
#include <stdio.h>
#define KWADR(X) X*X
#define PR(X)   printf("Wynik to %d.\n", X)
int main(void)
{
    int x = 5;
    int z;
    printf("x = %d\n", x);
    z = KWADR(x);
    printf("Wartosc SQUARE(x): ");
    PR(z);
    z = KWADR(2);
    printf("Wartosc SQUARE(2): ");
    PR(z);
    printf("Wartosc SQUARE(x+2): ");
    PR(KWADR(x+2));
    printf("Wartosc 100/SQUARE(2): ");
    PR(100/KWADR(2));
    printf("x wynosi %d.\n", x);
    printf("Wartosc SQUARE(++x): ");
    PR(KWADR(++x));
    printf("Po zwiekszeniu x wynosi %x.\n", x);
    return 0;
}

