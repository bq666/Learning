/* menuet.c -- techniki realizacji menu */
#include <stdio.h>
char pobierz_wybor(void);
char pobierz_pierwszy(void);
int pobierz_int(void);
void liczenie(void);
int main(void)
{
    int wybor;
        void liczenie(void);

    while ( (wybor = pobierz_wybor()) != 'q')
    {
        switch (wybor)
        {
            case 'a' :  printf("Kup po niskiej cenie, "
                                        "sprzedaj po wysokiej.\n");
                        break;
            case 'b' :  putchar('\a');  /* ANSI */
                        break;
            case 'c' :  liczenie();
                        break;
            default  :  printf("Blad programu!\n");
                        break;
        }
    }
    printf("Do widzenia.\n");

    return 0;
}

void liczenie(void)
{
    int n,i;
    printf("Jak dlugo liczyc? Podaj liczbe calkowita:\n"); 
    n = pobierz_int();
    for (i = 1; i <= n; i++)
        printf("%d\n", i);
    while ( getchar() != '\n')
        continue;
}

char pobierz_wybor(void)
{
    int ch;

    printf("Wpisz wybrana litere:\n"); 
    printf("a. porada           b. alarm\n"); 
    printf("c. liczenie         q. koniec\n"); 
    ch = pobierz_pierwszy(); 
    while (  (ch < 'a' || ch > 'c') && ch != 'q') 
    { 
        printf("Wpisz a, b, c lub q.\n"); 
        ch = pobierz_pierwszy(); 
    } 
    return ch; 
} 
 
char pobierz_pierwszy(void) 
{ 
    int ch; 
 
    ch = getchar(); 
    while (getchar() != '\n') 
        continue; 
    return ch; 
}

int pobierz_int(void)
{
    int we;
    char ch;

    while( scanf("%d", &we) != 1)
    {
        while((ch = getchar()) != '\n')
        putchar(ch); // pomija bledne dane wejsciowe
        printf(" nie jest liczba calkowita.\n Prosze podac ");
        printf("wartosc calkowita, np. 25, -178 czy 3: ");
    }
    return we;
}

