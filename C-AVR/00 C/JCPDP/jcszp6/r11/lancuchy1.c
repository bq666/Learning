// lancuchy1.c
#include <stdio.h>
#define NAPIS "To jest stala lancuchowa."
#define MAXDL 81

int main(void)
{
   char slowa[MAXDL] = "To jest lancuch w tablicy.";
   const char * wsk1 = "Cos mnie wskazuje.";
   puts("Oto kilka lancuchow:");
   puts(NAPIS);
   puts(slowa);
   puts(wsk1);
   slowa[1] = 'u';
   puts(slowa);

   return 0;
}

