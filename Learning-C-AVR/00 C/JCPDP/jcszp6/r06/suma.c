/* suma.c -- sumuje liczby calkowite wpisane przez uzytkownika */
#include <stdio.h>
int main(void)
{
  long num;
  long suma = 0L; /* przypisanie zmiennej suma wartosci poczatkowej 
                     zero */
  int stan;

  printf("Podaj liczbe calkowita do zsumowania ");
  printf("(albo q, aby zakonczyc program):\n");
  stan = scanf("%ld", &num);
  while (stan == 1)   /* == oznacza "jest rowny" */
  {
        suma = suma + num;
        printf("Podaj nastepna liczbe ");
        printf("(albo q, aby zakonczyc program):\n");
        stan = scanf("%ld", &num);
  }
  printf("Suma podanych liczb wynosi %ld.\n", suma);
  return 0;
}

