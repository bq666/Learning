/* print2.c-wiecej cech printf() */
#include <stdio.h>
int main(void)
{
    unsigned int un = 3000000000;    /* system z 32-bitowym typem int */
    short koniec = 200;              /* i 16-bitowym typem short      */
    long duza = 65537;
    long long bardzoduza = 12345678908642;
    
    printf("un = %u, lecz nie %d\n", un, un);
    printf("koniec = %hd i %d\n", koniec, koniec);
    printf("duza = %ld, lecz nie %hd\n", duza, duza);
    printf("bardzoduza= %lld, lecz nie %ld\n", bardzoduza, bardzoduza);
    
    return 0;
}

