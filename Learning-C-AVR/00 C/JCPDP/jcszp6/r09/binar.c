/* binar.c -- wyswietla liczbe calkowita w postaci dwojkowej */
#include <stdio.h>
void do_binar(unsigned long n);
int main(void)
{
  unsigned long liczba;
  printf("Podaj liczbe calkowita (q konczy program):\n");
  while (scanf("%ld", &liczba) == 1)
  {
     printf("Odpowiednik dwojkowy: ");
     do_binar(liczba);
     putchar('\n');
     printf("Podaj liczbe calkowita (q konczy program):\n");
  }
  printf("Gotowe.\n");

  return 0;
}
void do_binar(unsigned long n)   /* funkcja rekurencyjna */
{
  int r;
  r = n % 2;
  if (n >= 2)
     do_binar(n / 2);
  putchar(r == 0 ? '0' : '1');
  return;
}

