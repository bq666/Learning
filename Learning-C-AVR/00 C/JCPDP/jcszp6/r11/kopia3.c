/* kopia3.c -- demo funkcji strcpy() */
#include <stdio.h>
#include <string.h>  /* deklaruje strcpy() */
#define ROZMIAR 40
#define ROZMIAR_CELU 7
#define GRAN 5
char *wczytaj(char *z, int ile);

int main(void)
{
   char vslowa[GRAN][ROZMIAR_CELU];
   char temp[ROZMIAR];
   int i = 0;
   printf("Podaj %d slow zaczynajacych sie na v:\n", GRAN);
   while (i < GRAN && wczytaj(temp, ROZMIAR))
   {
      if (temp[0] != 'v')
         printf("%s nie zaczyna sie na v!\n", temp);
      else
      {
          strncpy(vslowa[i], temp, ROZMIAR_CELU - 1);
          vslowa[i][ROZMIAR_CELU - 1] = '\0';
          i++;
      }
    }
   puts("Oto przyjete slowa: ");
   for (i = 0; i < GRAN; i++)
       puts(vslowa[i]);
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

