/* proto1.c -- wykorzystuje prototyp funkcji */
#include <stdio.h>
int imax(int, int);      /* prototyp */
int main(void)
{
  printf("Wieksza liczba z %d i %d jest %d.\n",
       3, 5, imax(3));
  printf("Wieksza liczba z %d i %d jest %d.\n",
       3, 5, imax(3.0, 5.0));
  return 0;
}
int imax(n, m)
{
  return (n > m ? n : m);
}

