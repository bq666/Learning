/* pszenica.c -- wzrost wykladniczy */
#include <stdio.h>
#define POLA 64       /* liczba pol na szachownicy                    */
int main(void)
{
   const double PLON = 2E16; /* roczna swiatowa produkcja pszenicy */
   double biezace, suma;
   int licznik = 1;

   printf("pole    dodane ziarna    suma ziaren    ");
   printf("czesc rocznej\n");
   printf("                                        ");
   printf("produkcji swiatowej\n");
   suma = biezace = 1.0;    /* zaczynamy od jednego ziarna         */
   printf("%3d %15.2e %14.2e %14.2e \n", licznik, biezace,
          suma, suma/PLON);
   while (licznik < POLA)
   {
      licznik = licznik + 1;
      biezace = 2.0 * biezace;
                        /* podwojna liczba ziaren na nastepnym polu */
      suma = suma + biezace;                   /* aktualizacja sumy */
      printf("%3d %15.2e %14.2e %14.2e \n", licznik, biezace,
             suma, suma/PLON);
   }
 
   return 0;
}

