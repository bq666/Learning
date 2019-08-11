/* showf_pt.c -- wyswietla wartosci typu float na dwa sposoby */
#include <stdio.h>
int main(void)
{
    float aboat = 32000.0;
    double abet = 2.14e9;
    long double dip = 5.32e-5;
   
    printf("%f mozna przedstawic jako %e\n", aboat, aboat);
    // poniższy wiersz wymaga kompilatora C99 lub nowszego
    printf("albo jako %a w szesnastkowym zapisie potegowym\n", aboat);

    printf("%f mozna przedstawic jako%e\n", abet, abet);
    printf("%f mozna przedstawic jako %e\n", dip, dip);
   
    return 0;
}

