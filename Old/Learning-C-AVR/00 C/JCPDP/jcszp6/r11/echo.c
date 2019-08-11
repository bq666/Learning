/* echo.c -- funkcja main() z argumentami */
#include <stdio.h>
int main(int argc, char *argv[])
{
   int licznik;
   printf("Wiersz polecen zawiera %d argumentow:\n", argc - 1);
   for (licznik = 1; licznik < argc; licznik++) 
      printf("%d: %s\n", licznik, argv[licznik]); 
   printf("\n");
   return 0;
}

