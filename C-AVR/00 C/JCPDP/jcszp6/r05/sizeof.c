// sizeof.c -- uzycie operatora sizeof 
// uzycie modyfikatora C99 %z -- sprobuj %u lub %lu, gdy nie ma %zd 
#include <stdio.h>
int main(void)
{
    int n = 0;
    size_t intsize;
  
    intsize = sizeof (int);
    printf("n = %d, n ma %zd bajty; wszystkie liczby calkowite maja %zd bajty.\n",
         n, sizeof n, intsize );
         
    return 0;
}

