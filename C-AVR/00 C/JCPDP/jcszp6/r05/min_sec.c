// min_sec.c -- konwertuje sekundy na minuty i sekundy

#include <stdio.h>
#define SEK_NA_MIN 60            // sekundy w minuty
int main(void)
{
    int sec, min, left;

    printf("Konwertuje sekundy na minuty i sekundy!\n");
    printf("Podaj liczbe sekund (<=0 to koniec):\n");
    scanf("%d", &sec);           // wczytaj liczbe sekund
    while (sec > 0) 
    {
        min = sec / SEK_NA_MIN;  // obcina liczbe minut
        left = sec % SEK_NA_MIN; // pozostala liczba sekund
        printf("%d sekund to %d minut, %d sekund.\n", sec, 
                min, left);
        printf("Podaj kolejnosc wartosc (<=0 to koniec):\n");
        scanf("%d", &sec);           
    }
    printf("Koniec!\n");
  
    return 0;
}

