/* lancuchy.c -- formatowanie lancuchow */
#include <stdio.h>
#define NOTATKA "Doskonala gra aktorow!"
int main(void)
{
   printf("[%2s]\n", NOTATKA);
   printf("[%25s]\n", NOTATKA);
   printf("[%25.5s]\n", NOTATKA);
   printf("[%-25.5s]\n", NOTATKA);
   return 0;
}

