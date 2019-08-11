/* w_i_l.c -- wskazniki i lancuchy */
#include <stdio.h>
int main(void)
{
  char * tekst = "Nie badz glupi!";
  char * kopia;
  kopia = tekst;
  printf("%s\n", kopia);
  printf("tekst = %s; &tekst = %p; wartosc = %p\n",
       tekst, &tekst, tekst);
  printf("kopia = %s; &kopia = %p; wartosc = %p\n",
       kopia, &kopia, kopia);
  return 0;
}

