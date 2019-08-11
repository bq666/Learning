/* p_i_f.c -- wartosci prawdziwe i falszywe w C */
#include <stdio.h>
int main(void)
{
  int prawda, falsz;

  prawda = (10 > 2);    /* wartosc prawdziwej relacji  */
  falsz = (10 == 2);    /* wartosc falszywej relacji   */
  printf("prawda = %d; falsz = %d \n", prawda, falsz);
  return 0;
}

