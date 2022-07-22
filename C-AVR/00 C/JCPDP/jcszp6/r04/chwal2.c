/* chwal2.c */
// jesl twoj kompilator nie obsluguje
// specyfikatora %zd, uzyj %u albo %lu 

#include <stdio.h>
#include <string.h>      /* dostarcza prototypu dla strlen() */
#define POCHWALA "Ach, jakie wspaniale imie!"
int main(void)
{
  char imie[40];

  printf("Jak masz na imie?\n");
  scanf("%s", imie);
  printf("Witaj, %s. %s\n", imie, POCHWALA);
  printf("Twoje imie, skladajace sie z %zd liter, zajmuje %zd komorek pamieci.\n", strlen(imie), sizeof imie);
  printf("Pochwala sklada sie z %zd liter ", strlen(POCHWALA));
  printf("i zajmuje %zd komorek pamieci.\n", sizeof POCHWALA);
  return 0;
}

