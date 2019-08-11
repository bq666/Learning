/* mniejsze.c -- znajduje mniejsze zlo */
#include <stdio.h>
int imin(int, int);
int main(void)
{
  int zlo1, zlo2;
  printf("Podaj dwie liczby calkowite (q konczy program):\n");
  while (scanf("%d %d", &zlo1, &zlo2) == 2)
  {
     printf("Mniejsza liczba sposrod %d i %d jest %d.\n",
            zlo1, zlo2, imin(zlo1,zlo2));
     printf("Podaj dwie liczby calkowite (q konczy program):\n");
  }
  printf("Gotowe.\n");

  return 0;
}
int imin(int n,int m)
{
  int min;
  if (n < m)
     min = n;
  else
     min = m;
  return min;
}

