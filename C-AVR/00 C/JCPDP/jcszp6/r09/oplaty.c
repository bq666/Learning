/* oplaty.c -- program obliczajacy oplate za pokoj */
/* kompiluj razem z listingiem 9.10                */
#include <stdio.h>
#include "hotel.h" /* definiuje stale, deklaruje funkcje */
int main(void)
{
   int noce;
   double hotel;
   int kod;
   while ((kod = menu()) != KONIEC)
   {
      switch(kod)
      {
      case 1 : hotel = HOTEL1;
               break;
      case 2 : hotel = HOTEL2;
               break;
      case 3 : hotel = HOTEL3;
               break;
      case 4 : hotel = HOTEL4;
               break;
      default: hotel = 0.0;
               printf("Ups!\n");
               break;
      }
      noce = pobierz_noce();
      pokaz_cene(hotel, noce);
   }
   printf("Dziekuje i do widzenia\n");
   return 0;
}

