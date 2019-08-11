/* kiedy.c -- kiedy konczy sie petla? */
#include <stdio.h>
int main(void)
{
  int n = 5;

  while (n < 7)                        // wiersz 7 
  {
       printf("n = %d\n", n);
       n++;                            // wiersz 10
       printf("Teraz n = %d\n", n);    // wiersz 11
  }
  printf("Petla zakonczona\n");
  return 0;
}

