/* butelki.c -- odliczanie w dol */
#include <stdio.h>
#define MAX 100
int main(void)
{
  int licznik = MAX + 1;

  while (--licznik > 0) {
     printf("%d butelek piwa na stole, "
            "%d butelek piwa!\n", licznik, licznik);
     printf("Wez jedna i pusc ja w krag,\n");
     printf("%d butelek piwa!\n\n", licznik - 1);
  }
  return 0;
}

