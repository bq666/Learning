/* konwers.c -- modyfikuje lancuch */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define GRANICA 80
void DuzeLit(char *);
int LiczInter(const char *);
int main(void)
{
  char wiersz[GRANICA];
  char *tutaj;

  puts("Podaj wiersz tekstu:");
  fgets(wiersz, GRANICA, stdin);
  tutaj = strchr(wiersz, '\n');   // szukamy znaku nowego wiersza
  if (tutaj)             // jesli adres jest rozny od NULL
    *tutaj = '\0';       // zamieniamy na znak pusty

  DuzeLit(wiersz);
  puts(wiersz);
  printf("Wpisany wiersz zawiera %d znakow interpunkcyjnych.\n", 
         LiczInter(wiersz));
  return 0;
}
void DuzeLit(char * lan)
{
  while (*lan)
  {
      *lan = toupper(*lan);
       lan++;
  }
}
int LiczInter(const char * lan)
{
  int licz = 0;
  while (*lan)
  {
      if (ispunct(*lan))
         licz++;
      lan++;
  }
  return licz;
}

