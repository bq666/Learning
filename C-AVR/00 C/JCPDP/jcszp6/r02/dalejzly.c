/* dalejzly.c -- program z usunietymi bledami skladniowymi */
#include <stdio.h>
int main(void)
{
  int n, n2, n3;

/* ten program zawiera blad semantyczny */
  n = 5;
  n2 = n * n;
  n3 = n2 * n2;
  printf("n = %d, n do kwadratu = %d, n do szescianu = %d\n", n, n2, n3);
  return 0;
}

