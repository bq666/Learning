/* prawda.c -- ktore wartosci sa prawdziwe? */
#include <stdio.h>
int main(void)
{
  int n = 3;

  while (n)
       printf("%d to prawda\n", n--);
  printf("%d to falsz\n", n);
  n = -3;
  while (n)
       printf("%2d to prawda \n", n++);
  printf("%d to falsz\n", n);
  return 0;
}

