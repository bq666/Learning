/* wartzwr.c -- okreslanie wartosci zwracanej przez printf() */
#include <stdio.h>
int main(void)
{
  int n = 100;
  int wz;

  wz = printf("Woda wrze w temperaturze %d C.\n", n);
  printf("Funkcja printf() wyswietlila %d znaki.\n", wz);
  return 0;
}

