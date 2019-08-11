/* echo_eof.c -- powtarza wpisywane dane do konca pliku */
#include <stdio.h>
int main(void)
{
  int ch;

  while ((ch = getchar()) != EOF)
       putchar(ch);
   return 0;
}

