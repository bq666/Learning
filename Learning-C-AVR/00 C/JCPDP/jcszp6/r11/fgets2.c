/* fgets2.c -- stosowanie fgets() i fputs() */
#include <stdio.h>
#define DLUGOSC 10
int main(void)
{
   char slowa[DLUGOSC];

   puts("Wprowadz lancuchy (pusty wiersz zakonczy program):");
   while (fgets(slowa, DLUGOSC, stdin) != NULL && slowa[0] != '\n')
      fputs(slowa, stdout);
   puts("Gotowe.");

   return 0;
}

