/* chwal1.c -- wykorzystuje lancuchy */
#include <stdio.h>
#define POCHWALA "Ach, jakie wspaniale imie!"
int main(void)
{
  char imie[40];

  printf("Jak masz na imie?\n");
  scanf("%s", imie);
  printf("Witaj, %s. %s\n", imie, POCHWALA);
  return 0;
}

