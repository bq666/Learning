// czescb.c -- dalsza czesc programu
// kompilowac razem z czesa.c
#include <stdio.h>
extern int liczba;       // deklaracja nawiazujaca, lacznosc zewnetrzna
static int suma = 0;     // definicja static, lacznosc wewnetrzna
void sumuj(int k);       // prototyp funkcji
void sumuj(int k)        // k ma zasieg blokowy i brak lacznosci
{
    static int podsuma = 0;  // statyczna, brak lacznosci
    
    if (k <= 0)
    {
        printf("Cykl petli: %d\n", liczba);
        printf("Podsuma: %d; Suma: %d\n", podsuma, suma);
        podsuma = 0;
    }
    else
    {
        podsuma += k;
        suma += k;
    }
}

