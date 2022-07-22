/* fgets1.c -- stosowanie fgets() i fputs() */
#include <stdio.h>
#define DLUGOSC 14
int main(void)
{
   char slowa[DLUGOSC];

   puts("Prosze wprowadzic lancuch.");
   fgets(slowa, DLUGOSC, stdin);
   printf("Wprowadzony lancuch (dwa razy: z puts() i fputs()):\n");
   puts(slowa);
   fputs(slowa, stdout);
   puts("Prosze wprowadzic kolejny lancuch.");
   fgets(slowa, DLUGOSC, stdin);
   printf("Wprowadzony lancuch (dwa razy: z puts() i fputs()):\n");
   puts(slowa);
   fputs(slowa, stdout);
   puts("Gotowe.");

   return 0;
}

