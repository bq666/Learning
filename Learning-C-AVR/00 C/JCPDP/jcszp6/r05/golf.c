/* golf.c -- tablica wynikow turnieju golfa */
#include <stdio.h>
int main(void)
{
  int jane, tarzan, gepard;

  gepard = tarzan = jane = 68;
  printf("                      gepard   tarzan    jane\n");
  printf("Wynik pierwszej rundy %4d %8d %8d\n", gepard, tarzan, jane);
  return 0;
}

