/* kopia2.c -- demo strcpy() */
#include <stdio.h>
#include <string.h>             /* deklaruje strcpy() */
#define SLOWO "cukier"
#define ROZMIAR 40
int main(void)
{
   const char *zrodlo = SLOWO;
   char kopia[ROZMIAR] = "Podaj mnie do sadu.";
   char * wl;
   puts(zrodlo);
   puts(kopia);
   wl = strcpy(kopia + 6, zrodlo);
   puts(kopia);
   puts(wl);
   return 0;
}

