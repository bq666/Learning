/* szyfr1.c -- zmienia dane wejsciowe, zachowujac  odstepy */
#include <stdio.h>
#define ODSTEP ' '            // apostrof-spacja-apostrof
int main(void)
{
   char ch;
   ch = getchar();            // odczytanie znaku
   while (ch != '\n')         // dopoki nie ma konca wiersza
   {
       if (ch == ODSTEP)      // pozostaw znak spacji
           putchar(ch);       // bez zmian
       else
           putchar(ch + 1);   // zmien pozostale znaki
       ch = getchar();        // wczytaj kolejny znak
   }
   putchar(ch);               // wyswietl znak nowej linii
   return 0;
}

