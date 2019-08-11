/* wejscie.c -- kiedy uzywac & */
#include <stdio.h>
int main(void)
{
   int wiek;                 /* zmienna */
   float majatek;            /* zmienna */
   char zwierzatko[30];      /* lancuch */

   printf("Podaj swoj wiek, majatek i ulubione zwierzatko.\n");
   scanf("%d %f", &wiek, &majatek); /* tu uzywamy &                  */
   scanf("%s", zwierzatko);         /* przy tablicy znakowej nie ma & */
   printf("%d, %.0f zl, %s\n", wiek, majatek, zwierzatko);
   return 0;
}

