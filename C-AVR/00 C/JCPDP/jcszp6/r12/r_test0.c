/* r_test0.c -- sprawdza funkcje rand0()  */
/* nalezy kompilowac z plikiem rand0.c    */
#include <stdio.h>
extern int rand0(void);
int main(void)
{
    int liczba;
    for (liczba = 0; liczba < 5; liczba++)
        printf("%hd\n", rand0());
    
    return 0;
}

