// sprawdz.c -- sprawdzanie poprawnosci danych wejsciowych
#include <stdio.h>
#include <stdbool.h>
// sprawdz, czy  wejscie jest liczba calkowita
long pobierz_long(void);
// sprawdz prawidlowosc podanych granic zakresu
bool zle_granice(long poczatek, long koniec, long dolna, long gorna);
// oblicz sume kwadratow liczb calkowitych z zakresu od a do b
double suma_kwadr(long a, long b);
int main(void)
{
    const long MIN = -10000000;  // dolna granica zakresu
    const long MAX = +10000000;  // gorna granica zakresu
    long start;                  // poczatek przedzialu
    long stop;                   // koniec przedzialu
    double wynik;
   
    printf( "Program oblicza sume kwadratow liczb calkowitych.\n"
            "Dolna granica przedzialu nie powinna byc "
            "mniejsza od -10000000.\n"
            "Gorna granica nie powinna przekraczac +10000000.\n"
            "Podaj granice przedzialu"
            "(podanie 0 dla obu oznacza koniec).\n"
            "Dolna granica: ");
    start = pobierz_long();
    printf("Gorna granica: ");
    stop = pobierz_long();
    while (start !=0 || stop != 0) 
    {
        if (zle_granice(start, stop, MIN, MAX))
            printf("Sprobuj ponownie.\n");
        else
        {
            wynik = suma_kwadr(start, stop);
            printf("Suma kwadratow liczb calkowitych ");
            printf("w przedziale od %ld do %ld wynosi %g\n", start, stop, 
                    wynik);
        }
        printf("Podaj granice przedzialu "
               "(podanie 0 dla obu oznacza koniec)\n");
        printf("Dolna granica: ");
        start = pobierz_long();
        printf("Gorna granica: ");
        stop = pobierz_long();
    }
    printf("Koniec.\n");
   
    return 0;
}

long pobierz_long(void)
{
    long we;
    char ch;

    while( scanf("%ld", &we) != 1)
    {
        while((ch = getchar()) != '\n')
        putchar(ch);     // pomija bledne dane wejsciowe
        printf(" nie jest liczba calkowita.\n Prosze podac ");
        printf("wartosc calkowita, np. 25, -178 czy 3: ");
    }
    return we;
}

double suma_kwadr(long a, long b)
{
    double suma = 0;
    int i;
   
    for (i = a; i <= b; i++)
        suma += i * i;
   
    return suma;
}

bool zle_granice(long poczatek, long koniec, long dolna, long gorna)
{
    bool zle = false;
    if( poczatek > koniec )
    {
        printf("%ld nie jest mniejsze od %ld.\n", poczatek, koniec);
        zle = true;
    }
    if( poczatek < dolna || koniec < dolna )
    {
        printf("Wartosci musza miec wartosc co najmniej: %ld.\n", 
                      dolna);
        zle = true;
    }

    if( poczatek > gorna || koniec > gorna )
    {
        printf("Wartosci musza miec wartosc co najwyzej: %ld.\n", 
                      gorna);
        zle = true;
    }
    return zle;
}

