/* r_test1.c -- sprawdza funkcje rand1() i srand1() */
/* nalezy kompilowac z plikiem s_i_r.c */
#include <stdio.h>
extern void srand1(unsigned int x);
extern int rand1(void);
int main(void)
{
    int liczba;
    unsigned ziarno;
    printf("Podaj wartosc ziarna:\n");
    while (scanf("%u", &ziarno) == 1)
    {
        srand1(ziarno);    /* reset ziarna */
        for (liczba = 0; liczba < 5; liczba++)
            printf("%hd\n", rand1());
        printf("Podaj nastepna wartosc ziarna (k to koniec):\n");
    }
    printf("Koniec\n");
    return 0;
}

