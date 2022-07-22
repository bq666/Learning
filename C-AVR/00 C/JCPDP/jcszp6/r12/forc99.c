// forc99.c -- nowe zasady dla zasiegu blokowego w petli for(C99)
#include <stdio.h>
int main()
{
    int n = 8;
    
    printf("Poczatkowo n = %d, pod adresem %p\n", n, &n);
    for (int n = 1; n < 3; n++)
        printf("petla 1: n = %d, pod adresem %p\n", n, &n);
    printf("Po petli 1, n = %d, pod adresem %p\n", n, &n);
    for (int n = 1; n < 3; n++)
    {
        printf("petla 2 indeks n = %d, pod adresem %p\n", n, &n);
        int n = 6;
        printf("petla 2: n = %d, pod adresem %p\n", n, &n);
        n++;
    }
    printf("Po petli 2, n = %d, pod adresem %p\n", n, &n);
 
    return 0;
}

