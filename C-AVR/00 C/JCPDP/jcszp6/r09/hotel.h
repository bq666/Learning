/* hotel.h -- stale i deklaracje dla hotel.c */
#define KONIEC       5
#define HOTEL1    80.00
#define HOTEL2   125.00
#define HOTEL3   155.00
#define HOTEL4   200.00
#define RABAT   0.95
#define GWIAZDKI "**********************************"
// pokazuje liste wyborow
int menu(void);
// zwraca zadana liczbe nocy
int pobierz_noce(void);
// oblicza cene na podstawie stawki i liczby noclegów
// i wyswietla wynik
void pokaz_cene(double hotel, int noce);

