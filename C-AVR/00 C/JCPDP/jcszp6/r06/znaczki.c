/* znaczki.c -- ceny znaczkow na przesylki o roznej wadze */
#include <stdio.h>
int main(void)
{
    const float PIERWSZE = 0.70;
    const float NASTEPNE = 0.30;
    const int G = 25;

   int gramy;
   float cena;

   printf(" waga    cena\n");
   for(gramy=G, cena=PIERWSZE; gramy<= 400; gramy += G,
          cena += NASTEPNE)
      printf("%5d %7.2f\n", gramy, cena);
  return 0;
}

