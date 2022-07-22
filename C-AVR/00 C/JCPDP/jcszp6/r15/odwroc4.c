/* odwroc4.c -- odwraca ostatnie 4 bity liczb calkowitych */
#include <stdio.h>
#include <limits.h>
char * do_binar(int n, char * wl);
int odwroc_koniec(int num, int bity);
void pokaz_binar(const char * lan);
int main(void)
{
   char bin_lan[CHAR_BIT * sizeof(int) + 1];
   int liczba;
   puts("Ten program przelicza liczby calkowite na system binarny.");
   puts("Wpisanie danych nienumerycznych konczy program.");
   while (scanf("%d", &liczba) == 1)
   {
         do_binar(liczba, bin_lan);
         printf("%d to inaczej %s\n", liczba, bin_lan);
         pokaz_binar(bin_lan);
         putchar('\n');
         liczba = odwroc_koniec(liczba, 4);
         printf("Odwrocenie ostatnich 4 bitow daje\n");
         pokaz_binar(do_binar(liczba, bin_lan));
         putchar('\n');
   }
   puts("Gotowe!");
   return 0;
}
char * do_binar(int n, char * wl)
{
   int i;
   static int rozmiar = CHAR_BIT * sizeof(int);
   for (i = rozmiar - 1; i >= 0; i--, n >>= 1)
        wl[i] = (01 & n) + '0';
   wl[rozmiar] = '\0';
   return wl;
}
/* wyswietl lancuch binarny w blokach po 4 */
void pokaz_binar(const char * lan)
{
    int i = 0;
    while (lan[i])  /* nie znak null */
    {
        putchar(lan[i]);
        if(++i % 4 == 0 && lan[i])
            putchar(' ');
    }
}
int odwroc_koniec(int num, int bity)
{
    int maska = 0;
    int wartbit = 1;
    while (bity-- > 0)
    {
        maska |= wartbit;
        wartbit <<= 1;
    }
    return num ^ maska;
}

