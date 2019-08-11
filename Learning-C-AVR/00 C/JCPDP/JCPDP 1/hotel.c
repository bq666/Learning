/*
int noce;
    double hotel;
    int kod;

    while((kod = menu()) != KONIEC){
        switch(kod){
        case 1:     hotel = HOTEL1;
                    break;
        case 2:     hotel = HOTEL2;
                    break;
        case 3:     hotel = HOTEL3;
                    break;
        case 4:     hotel = HOTEL4;
                    break;
        default:    hotel = 0.0;
                    printf("Ups!\n");
                    break;
        }
        noce = pobierz_noce();
        pokaz_cene(hotel,noce);
    }
    printf("Koniec !");
*/







#include <stdio.h>
#include "hotel.h"



int menu (void){
    int kod, stan;
    printf("\n%s%s\n", GWIAZDKI, GWIAZDKI);
    printf("Podaj numer hotelu:\n");
    printf("1) Marek Antoniusz              2) Olimpijski\n");
    printf("3) U Marynarza                  4) Savoy\n");
    printf("5) Koniec\n");
    printf("%s%s\n", GWIAZDKI, GWIAZDKI);
    while ((stan = scanf(" %d", &kod)) != 1 || (kod < 1 || kod > 5)){
        if (stan != 1)
            scanf("%*s"); // odrzucamy wejœcie nie liczbowe
        printf("Podaj liczbê z przedzia³u od 1 do 5.\n");
    }
    return kod;
}

int pobierz_noce(void){
    int noce;
    printf("Ile nocy bêdzie potrzebne? ");
    while (scanf("%d", &noce) != 1){
        scanf("%*s");
        printf("Podaj liczbê ca³kowit¹, np. 2.\n");
    }
    return noce;
}

void pokaz_cene(double hotel, int noce){
    int n;
    double suma = 0.0;
    double przelicznik = 1.0;
    for (n = 1; n <= noce; n++, przelicznik *= RABAT)
        suma += hotel * przelicznik;
    printf("Ca³kowity koszt pobytu wyniesie %0.2f $.\n", suma);
}
