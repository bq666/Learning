/* for_6.c -- wykorzystanie petli for do utworzenia tablicy szescianow */
#include <stdio.h>
int main(void)
{
  int num;

  printf("    n   n do szescianu\n");
  for (num = 1; num <= 6; num++)
     printf("%5d %5d\n", num, num*num*num);
  return 0;
}

