/* zle_arg.c -- nieprawidlowe argumenty */
#include <stdio.h>
int main(void)
{
    int n = 4;
    int m = 5;
    int f = 7.0f;
    int g = 8.0f;

    printf("%d\n", n, m);       /* za duzo argumentow   */
    printf("%d %d\n",n);        /* za malo argumentow   */
    printf("%d %d\n", f, g);    /* zle typy wartosci    */
    return 0;
}

