/* pomin.c -- wykorzystuje continue do pominiecia czesci petli */
#include <stdio.h>
int main(void)
{
    const float MIN = 0.0f;
    const float MAX = 100.0f;

    float wynik;
    float suma = 0.0f;
    int n = 0;
    float min = MAX;
    float max = MIN;

    printf("Podaj pierwszy wynik (albo q zeby zakonczyc):\n");
    while (scanf("%f", &wynik) == 1)
    {
        if (wynik < MIN || wynik > MAX)
        {
            printf("%0.1f jest nieprawidlowa wartoscia.\n", wynik);
            continue; // skok do testu warunku wykonania petli 
        }
        printf("Przyjeto %0.1f:\n", wynik);
        min = (wynik < min)? wynik: min;
        max = (wynik > max)? wynik: max;
        suma += wynik;
        n++;
        printf("Podaj kolejny wynik (albo q zeby zakonczyc):\n");

    }
    if (n > 0)
    {
        printf("Srednia z %d wynikow wynosi %0.1f.\n", n, suma / n);
        printf("Najnizszy = %0.1f, najwyzszy = %0.1f\n", min, max);
    }
    else
        printf("Nie podano zadnych prawidlowych wynikow.\n");
    return 0;
}

