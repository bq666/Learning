/* dzielnik.c -- uzycie zagniezdzonych struktur if do znalezienia  
   dzielnikow liczby  */
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
   unsigned long num;              // liczba do sprawdzenia
   unsigned long dziel;            // potencjalne dzielniki
   bool pierwsza;                  // flaga
   printf("Podaj dodatnia liczbe calkowita do zanalizowania; ");
   printf("Wpisz q, aby zakonczyc.\n");
   while (scanf("%ld", &num) == 1)
   {
      for (dziel = 2, pierwsza = true; (dziel * dziel) <= num; dziel++)
      {
         if (num % dziel == 0)
         {
            if ((dziel * dziel) != num)
               printf("%ld dzieli sie przez %ld i %ld.\n",
                   num, dziel, num / dziel);
            else
               printf("%ld dzieli sie przez %ld.\n", num, dziel);
            pierwsza = false;     // liczba nie jest liczba pierwsza
         }
      }
      if (pierwsza)
         printf("%ld jest liczba pierwsza.\n", num);
      printf("Podaj nastepna liczbe do zanalizowania; ");
      printf("Wpisz q, aby zakonczyc.\n");
   }

   printf("Gotowe.\n");
   return 0;
}

