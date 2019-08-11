/* pokaz_zn1.c -- program z problemem we-wy  */
#include <stdio.h>
void wyswietl(char c, int wysokosc, int szerokosc);
int main(void)
{
     int ch;                   /* znak do wyswietlenia   */
     int rzedy, kolumny;       /* liczba rzedow i kolumn */
     printf("Podaj znak i dwie liczby calkowite:\n");
     while ((ch = getchar()) != EOF)
     {
       scanf("%d %d", &rzedy, &kolumny);
       wyswietl(ch, rzedy, kolumny);
       printf("Podaj kolejny znak i dwie liczby calkowite;\n");
       printf("Aby zakonczyc, zasymuluj EOF.\n");
     }
     printf("Do widzenia.\n");

     return 0;
}

void wyswietl(char c, int wysokosc, int szerokosc)
{
     int rzad, kol;

     for (rzad = 1; rzad <= wysokosc; rzad++)
     {
          for (kol = 1; kol <= szerokosc; kol++)
               putchar(c);
          putchar('\n');   /* zakoncz wiersz i rozpocznij kolejny */
     }
}

