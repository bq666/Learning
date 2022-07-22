/* zenon.c -- suma szeregu */
#include <stdio.h>

int main(void)
{
 int licznik;
 double czas, potega_2;
 int granica;

 printf("Ile wyrazow chcesz zsumowac?\n");
 scanf("%d", &granica);

 for (czas=0, potega_2=1, licznik=1; licznik <= granica; licznik++, potega_2 *= 2.0)
 {
    czas += 1.0/potega_2;
    printf("czas = %f, gdy  licznik = %d.\n", czas, licznik);
 }
 return 0;
}

