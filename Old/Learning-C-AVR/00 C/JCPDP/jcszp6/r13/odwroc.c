/* odwroc.c -- wyswietla zawartosc pliku w odwrotnej kolejnosci */
#include <stdio.h>
#include <stdlib.h>
#define CNTL_Z '\032'   /* znacznik EOF w plikach tekstowych DOS */
#define DLAN 81
int main(void)
{
   char plik[DLAN];
   char ch;
   FILE *wp;
   long licznik, koniec;
   puts("Podaj nazwe pliku:");
   scanf("%80s", plik);
   if ((wp = fopen(plik,"rb")) == NULL)
   {                      /* tryb tylko do odczytu */
      printf("Nie moge otworzyc %s\n", plik);
      exit(EXIT_FAILURE);
   }
   fseek(wp, 0L, SEEK_END);        /* przejdz do konca pliku */
   koniec = ftell(wp);
   for (licznik = 1L; licznik <= koniec; licznik++)
   {
      fseek(wp, -licznik, SEEK_END);  /* idz do tylu         */
      ch = getc(wp);
      if (ch != CNTL_Z && ch != '\r') /* pliki MS-DOS */
         putchar(ch);
   }
   putchar('\n');
   fclose(wp);
   return 0;
}

