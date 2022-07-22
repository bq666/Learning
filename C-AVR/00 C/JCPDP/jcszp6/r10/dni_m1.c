/* dni_m1.c -- wyswietla liczbe dni w kazdym z miesiecy */
#include <stdio.h>
#define MIESIACE 12
int main(void)
{
  int dni[MIESIACE] = {31,28,31,30,31,30,31,31,30,31,30,31};
  int index;
  for (index = 0; index < MIESIACE; index++)
     printf("Miesiac %d ma %d dni.\n", index +1,
             dni[index]);
  return 0;
}

