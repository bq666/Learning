/* szyfr2.c -- zmienia dane wejsciowe, zachowujac  nie-litery */
#include <stdio.h>
#include <ctype.h>            // dla funkcji isalpha()
int main(void)
{
   char ch;
   while ((ch = getchar()) != '\n')
   {
       if (isalpha(ch))       // jesli znak jest litera,
           putchar(ch + 1);   // wyswietl nastepna litere
       else
           putchar(ch);       // jesli nie, wyswietl go bez zmian
   }
   putchar(ch);               // wyswietl znak nowej linii
   return 0;
}

