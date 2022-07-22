/* porown.c -- to dziala */
#include <stdio.h>
#include <string.h>   /* deklaruje strcmp() */
#define ODPOWIEDZ "Grant"
#define MAX 40
char *wczytaj(char *z, int ile);

int main(void)
{
    char proba[MAX];
    puts("Kto jest pochowany w grobowcu Granta?");
    wczytaj(proba, MAX);
    while (strcmp(proba,ODPOWIEDZ) != 0)
    {
     puts("Niestety to nie jest dobra odpowiedz. Sprobuj jeszcze raz.");
        wczytaj(proba, MAX);
    }
    puts("Tak jest!");
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

