/* global.c  -- uzycie zmiennych globalnych */
#include <stdio.h>
int jednostki = 0;         /* zmienna zewnetrzna      */
void krytyka(void);
int main(void)
{
    extern int jednostki;  /* powtorna (opcjonalna) deklaracja */
    printf("Ile funtow masla miesci sie w barylce?\n");
    scanf("%d", &jednostki);
    while ( jednostki != 56)
        krytyka();
    printf("Musiales podejrzec!\n");
   
    return 0;
}
void krytyka(void)
{
    /* pominieto powtorna (opcjonalna) deklaracje */
      
    printf("Nie masz szczescia, sprobuj ponownie.\n");
    scanf("%d", &jednostki);
}

