/* float.c -- modyfikatory dla wartosci zmiennoprzecinkowych */
#include <stdio.h>

int main(void)
{
  const double CZYNSZ = 2345.67;  /* stala zdefiniowana za pomoca const */

  printf("*%f*\n", CZYNSZ);
  printf("*%e*\n", CZYNSZ);
  printf("*%4.2f*\n", CZYNSZ);
  printf("*%3.1f*\n", CZYNSZ);
  printf("*%10.3f*\n", CZYNSZ);
  printf("*%10.3E*\n", CZYNSZ);
  printf("*%+4.2f*\n", CZYNSZ);
  printf("*%010.2f*\n", CZYNSZ);
  return 0;
}

