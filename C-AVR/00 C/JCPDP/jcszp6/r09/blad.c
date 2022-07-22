/* blad.c -- korzysta z funkcji w niewlasciwy sposob */
#include <stdio.h>
int imax();      /* deklaracja w starym stylu */
int main(void)
{
  printf("Wieksza liczba z %d i %d jest %d.\n",
       3, 5, imax(3));
  printf("Wieksza liczba z %d i %d jest %d.\n",
       3, 5, imax(3.0, 5.0));
  return 0;
}
int imax(n, m)
int n, m;
{
  return (n > m ? n : m);
}

