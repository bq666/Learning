/* szerok.c -- szerokosc pola */
#include <stdio.h>
#define STRONY 732
int main(void)
{
  printf("*%d*\n", STRONY);
  printf("*%2d*\n", STRONY);
  printf("*%10d*\n", STRONY);
  printf("*%-10d*\n", STRONY);
  return 0;
}

