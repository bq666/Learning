/* lok_stat.c -- uzywanie statycznych zmiennych lokalnych */
#include <stdio.h>
void sprawdz_stat(void);
int main(void)
{
    int licznik;
    for (licznik = 1; licznik <= 3; licznik++)
    {
        printf("Iteracja nr: %d:\n", licznik);
        sprawdz_stat();
    }
   
    return 0;
}
void sprawdz_stat(void)
{
    int znikam = 1;
    static int trwam = 1;
    printf("znikam = %d, a trwam = %d\n", znikam++, trwam++);
}

