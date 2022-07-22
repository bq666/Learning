/* str_cat.c -- laczy dwa lancuchy */
#include <stdio.h>
#include <string.h>  /* deklaruje funkcje strcat() */
#define ROZMIAR 80
char *wczytaj(char *z, int ile);
int main(void)
{
   char kwiat[ROZMIAR];
   char dodatek[] = " smierdza jak stare buty.";

   puts("Jakie kwiaty lubisz najbardziej?");
   if (wczytaj(kwiat, ROZMIAR))
   {
      strcat(kwiat, dodatek);
      puts(kwiat);
      puts(dodatek);
}
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

