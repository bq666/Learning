/* zmszer.c -- wykorzystuje pole o zmiennej szerokosci */
#include <stdio.h>
int main(void)
{
  unsigned szerokosc, dokladnosc;
  int liczba = 256;
  double waga = 242.5;

  printf("Jaka szerokosc pola?\n");
  scanf("%d", &szerokosc);
  printf("Liczba jest rowna :%*d:\n", szerokosc, liczba);
  printf("Teraz podaj szerokosc i dokladnosc:\n");
  scanf("%d %d", &szerokosc, &dokladnosc);
  printf("Waga = %*.*f\n", szerokosc, dokladnosc, waga);
  printf("Gotowe!\n");

  return 0;
}

