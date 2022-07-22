/* getsputs.c -- gets() w parze z puts() */
#include <stdio.h>
#define DLUGOSC 81
int main(void)
{
   char slowa[DLUGOSC];
   puts("Prosze wprowadzic  lancuch.");
   gets(slowa);
   printf("Wprowadzony lancuch (dwa razy):\n");
   printf("%s\n", slowa);
   puts(slowa);
   puts("Gotowe.");

   return 0;
}

