// file_eof.c --otwiera plik i wyswietla jego zawartosc
#include <stdio.h>
#include <stdlib.h>                   // potrzebujemy funkcji exit()
int main()
{
    int ch;
    FILE * fp;
    char nazwplik[50];                // przechowuje nazwe pliku

    printf("Podaj nazwe pliku: ");
    scanf("%s", nazwplik);
    fp = fopen(nazwplik, "r");        // otwiera plik do odczytu
    if (fp == NULL)                   // proba nieudana
    {
        printf("Blad przy probie otwarcia pliku.\n"); 
        exit(1);                      // wyjscie z programu
    }
    // getc(fp) pobiera znak z otwartego pliku
    while ((ch = getc(fp)) != EOF)
        putchar(ch);
    fclose(fp);                      // zamyka plik
  
    return 0;
}

