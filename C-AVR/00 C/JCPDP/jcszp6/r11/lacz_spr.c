/* lacz_spr.c -- laczy dwa lancuchy, sprawdzajac uprzednio rozmiar */
#include <stdio.h>
#include <string.h>
#define ROZMIAR 30
#define ROZMIAR_OWADY 17

char *wczytaj(char *z, int ile);
int main(void)
{
   char kwiaty[ROZMIAR];
   char dodatek[] = " smierdza jak stare buty.";
   char owady[ROZMIAR_OWADY];

   int wolne;
   puts("Jakie kwiaty lubisz najbardziej?");
   wczytaj(kwiaty, ROZMIAR);
   if ((strlen(dodatek) + strlen(kwiaty) + 1) <= ROZMIAR)
       strcat(kwiaty, dodatek);
   puts(kwiaty);
   puts("Jakie owady lubisz najbardziej?");
   wczytaj(owady, ROZMIAR_OWADY);
   wolne = ROZMIAR_OWADY - strlen(owady) - 1;
   strncat(owady, dodatek, wolne);
   puts(owady);

   return 0;
}
char *wczytaj(char *z, int ile)
{
    char * wynik;
    int i = 0;

    wynik = fgets(z, ile, stdin);
    if (wynik) // wynik rozny od NULL 
    {
        while (z[i] != '\n' && z[i] != '\0')
            i++;
        if (z[i] == '\n')
            z[i] = '\0'; // znak nowego wiersza -> znak pusty 
        else             // z[i] == '\0'
            while (getchar() != '\n')
                continue;
    }
    return wynik;
}

