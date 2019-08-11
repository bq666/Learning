/* while2.c -- uwazaj na sredniki */
#include <stdio.h>
int main(void)
{
  int n = 0;

  while (n++ < 3);                          /* wiersz 7 */
       printf("n jest rowne %d\n", n);      /* wiersz 8 */
  printf("Na tym konczymy nasz program.\n");
  return 0;
}

