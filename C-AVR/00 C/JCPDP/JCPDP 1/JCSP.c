#include <stdio.h>
#include <string.h>
#include <ctype.h>






void JCSP(void){





/*
    int * i = (int*) malloc(sizeof(int));
    *i = 66;
    //int j = 0;
    *i = *i + 1 ;
    //printf("%d, %p\n", j, &j);
    printf("%d %p\n", *i, i);
*/

/*
int obszar_statyczny = 30;
const char *lcz = "Literal ciagu znakow";


    int obszar_automatyczny = 40;
    char ciag_automatyczny[] = "Automatyczny przydzial tablicy znakow";
    int *wski;
    char *wskl;

    wski = (int *) malloc(sizeof(int));
    *wski = 35;
    wskl = (char*) malloc(strlen("Ciag przydzielony dynamicznie") + 1);
    strcpy(wskl, "Ciag przydzielony dynamicznie");

    printf(" obszar statyczny: %d pod adresem %p\n", obszar_statyczny, &obszar_statyczny);
    printf(" obszar automatyczny: %d pod adresem %p\n", obszar_automatyczny, &obszar_automatyczny);
    printf(" *wski: %d pod adresem %p\n", *wski, wski);
    printf(" %s pod adresem %p\n", lcz, lcz);
    printf(" %s pod adresem %p\n", ciag_automatyczny, &ciag_automatyczny);
    printf(" %s pod adresem %p\n", wskl, wskl);
    printf(" %s pod adresem %p\n", "Literal w kodzie", "Literal w kodzie");
    free(wski);
    free(wskl);
*/




/*    double *wsk;
    int max = 0;
    int liczba;
    int i = 0;

    puts("Podaj maksymalna liczbe elementow (typu double):");
    if(scanf("%d", &max) != 1){
        puts("Nie poprawna liczba, do widzenia.");
        exit(EXIT_FAILURE);
    }
    wsk = (double*) malloc(max * sizeof(double));
    if (wsk == NULL){
        puts("Przydziel pamieci nie powiudl sie.");
        exit(EXIT_FAILURE);
    }
    puts("Podaj elementy (k to koniec):\n");
    while (i < max && scanf("%lf", &wsk[i]) == 1)
        ++i;
    printf("Oto %d wprowadzonych elementow:\n", liczba = i);
    for(i = 0; i < liczba; i++){
        printf("%7.2f ", wsk[i]);
        if (i % 7 == 6)
            putchar('\n');
    }
    if(i % 7 != 0)
        putchar('\n');
    puts("koniec.");
    free(wsk);
*/




/*-----------------------------------------------------rzut kościami
-------------------------------------------------------główny
#include "czescb.h"
int rzuty, wynik;
    int scianki, status;

    srand((unsigned int) time(0));
    printf("Podaj liczbe scianek, 0 oznacza koniec.\n");
    while(scanf("%d", &scianki) == 1 && scianki > 0){
        printf("Ile rzutow?\n");
        if((status = scanf("%d", &rzuty)) != 1){
            if(status == EOF)
                break;
            else{
                printf("Nalezy podac liczbe calkowita.");
                printf("Sprobujmy jeszcze raz.\n");
                while(getchar() != '\n')
                    continue;
                printf("Ile scianek? 0 oznacza koniec.\n");
                continue;
            }
        }
        wynik = rzucaj_n_razy(rzuty, scianki);
        printf("Wyrzucono razem %d uzywajac %d %d sciennych kosci.\n", wynik, rzuty, scianki);
        printf("Podaj liczbe scianek, 0 oznacza koniec.\n");
    }
    printf("Dunkacja rzucaj() zostala wywolana %d razy.\n", liczba_rzutow);
-------------------------------------------------------CZESCB_H
#ifndef CZESCB_H_INCLUDED
#define CZESCB_H_INCLUDED
extern int liczba_rzutow;
int rzucaj_n_razy(int rzuty, int scianki);


#endif // CZESCB_H_INCLUDED
-------------------------------------------------------czescb.c
#include "czescb.h"
#include <stdio.h>
#include <stdlib.h>
int liczba_rzutow = 0;
static int rzucaj(int scianki){
    int oczka;
    oczka = rand() % scianki + 1;
    ++liczba_rzutow;
    return oczka;
}

int rzucaj_n_razy(int rzuty, int scianki){
    int k;
    int suma = 0;
    if(scianki < 2){
        printf("Wymagane sa co najmniej 2 scianki. \n");
        return -2;
    }
    if(rzuty < 1){
        printf("Wymagany co najmniej 1 rzut.\n");
        return -1;
    }
    for(k = 0; k < rzuty; k++)
        suma += rzucaj(scianki);
    return suma;
}
-------------------------------------------------------------------------------------------
*/



/*
#include <stdio.h>
extern int liczba;
static int suma = 0;        // -------------(LP. 4) ------------- zmienna static, ³¹cznoœæ wewnêtrzna
void sumuj(int k);
void sumuj(int k){
    static int podsuma = 0; // -------------(LP. 5) ------------- zmienna static, brak ³¹cznoœci
    if(k <= 0){
        printf("Cykl petli: %d\n", liczba);
        printf("Podsuma: %d; Suma: %d\n", podsuma, suma);
        podsuma = 0;
    }else{
        podsuma += k;
        suma += k;
    }
}
*/













/*
----------------------------------główny.c------------------------------------------------------
------------------------------------------------------------------------------------------------
extern int rand0(void);
extern void srand1(unsigned int x);
extern int rand1(void);

   int liczba;
    unsigned ziarno;
    printf("Podaj wartość ziarna:\n");
    while(scanf("%u", &ziarno) == 1){
        srand1(ziarno);
        for(liczba = 0; liczba < 5; liczba++)
            printf("%hd\n", rand1());
        printf("Podaj następną wartość ziarna (k koniec):\n");
    }


    //for (liczba = 0; liczba < 5; liczba++)
    //    printf("%hd\n", rand0());
---------------------------------------inny.c---------------------

static unsigned long int nast = 1;
int rand0(void){
    nast = nast * 11035152245 + 12345;
    return (unsigned int) (nast / 65536) % 32768;
}

int rand1(void){
    nast = nast * 1103515245 + 12345;
    return(unsigned int) (nast/65536) % 32768;
}

void srand1(unsigned int ziarno){
    nast = ziarno;
}
*/





//------------------------------------------------------------------------------------------------------------
//--------------------------------zasięgi zmiennych-----------------------------------------------------------
/*
int globalna;
static int globalna_static;

void funkcja(void);
void funkcja_2();




void funkcja(void){
    int w_funkcji;
    static int w_funkcji_static;
    printf("wartosc globalna \t\t\t%d \t\tadres %p\n",globalna, &globalna);
    printf("wartosc globalna statyczna\t\t%d \t\tadres %p\n",globalna_static, &globalna_static);
    //printf("wartosc w_main \t%d \tadres %p\n",w_main, &w_main);
    //printf("wartosc w_main_statyczna statyczna\t%d \tadres %p\n",w_main_statyczna, &w_main_statyczna);
    printf("wartosc w_funkcji \t\t\t%d \tadres %p\n",w_funkcji, &w_funkcji);
    printf("wartosc w_funkcji_statyczna statyczna\t%d \t\tadres %p\n",w_funkcji_static, &w_funkcji_static);
    funkcja_2();
    }

void funkcja_2(){
    printf("wartosc w_funkcji2 \t\t\t%d \tadres %p\n",w_funkcji, &w_funkcji);
    printf("wartosc w_funkcji2_statyczna statyczna\t%d \t\tadres %p\n",w_funkcji_static, &w_funkcji_static);
}




   int w_main = 66;
    static int w_main_static;
    {
        printf("%d\n", w_main);
        funkcja();
    }
//------------------------------------------------------------------------------------------------------------
//--------------------------------zasięgi zmiennych-----------------------------------------------------------
*/


/*
int jednostki = 0;
void krytyka(void){
    printf("Nie masz szczęscia, sprobuj ponownie.\n");
    scanf(" %d", &jednostki);
}


    extern int jednostki;
    printf("Ile funtów masla miesci sie w barylce?\n");
    scanf(" %d", &jednostki);
    while (jednostki != 56)
        krytyka();
    printf("musiales podejrzec!\n");
*/


/*
void sprawdz_stat(void){
    int znikam = 1;
    static int trwam = 1;
    printf("znikam = %d, a trwam = %d\n", znikam++, trwam++);
    }

       int licznik;
    for(licznik = 1; licznik <= 3; licznik++){
        printf("Interacja nr: %d:\n",licznik);
        sprawdz_stat();
    }
*/






/*
    int n = 8;
    printf("Poczatkowo n(8) = %d, pod adresem %p\n", n, &n);
    for(int n = 1; n <3; n++)
        printf("petla 1: n(1,2) = %d, pod adresem %p\n", n, &n);
    printf("Po petli 1, n(8) = %d, pod adresem %p\n", n, &n);
    for(int i = 0; n < 3; n++){
        printf("petla 2 index n(0) = %d, pod adresem %p\n", n, &n);
        int n = 6;
        printf("petla 2: n(6) = %d, pod adresem %p\n", n, &n);
    }
    printf("Po petli 2, n(8) = %d, pod adresem %p\n", n, &n);
*/



/*
    int x = 30;
    printf("x w zewnętrznym bloku: %d spod adresu %p\n", x, &x);
    {
        int x = 77;
        printf("x w wewnętrznym bloku: %d spod adresu %p\n", x, &x);
    }
    printf("x w zewnętrznym bloku: %d spod adresu %p\n", x, &x);
    while(x++ < 33){
        int x = 100;
        x++;
        printf("x w pętli while: %d spod adresu %p\n", x, &x);
    }
    printf("x w zewnętrznym bloku: %d spod adresu %p\n", x, &x);
*/







/*
char *wczytaj(char *z, int ile){
    char *wynik;
    int i = 0;
    wynik = fgets(z, ile, stdin);
    if(wynik){
        while(z[i] != '\n' && z[i] != '\0')
            i++;
        if(z[i] == '\n')
            z[i] = '\0';
        else while (getchar() != '\n')
            continue;
    }
    return wynik;
}

void srtlan(char *lancuchy[], int num){
    char *temp;
    int dol, szuk;
    for(dol = 0; dol < num-1; dol++)
        for(szuk = dol + 1; szuk < num; szuk++)
            if(strcmp(lancuchy[dol], lancuchy[szuk]) > 0){
                temp = lancuchy[dol];
                lancuchy[dol] = lancuchy[szuk];
                lancuchy[szuk] = temp;
            }
}

void DuzeLit(char *lan){
    while(*lan){
        *lan = toupper(*lan);
        lan++;
    }
}

int LiczInter(const char*lan){
    int licz = 0;
    while(*lan){
        if(ispunct(*lan))
            licz++;
        lan++;
    }
    return licz;
}

#define LIMIT 30
    char liczba[LIMIT];
    char *koniec;
    long wartosc;
    puts("Podaj liczbe (wpisz pusty wiersz, aby zakonczyc):");
    while(wczytaj(liczba, LIMIT) && liczba[0] != '\0'){
        wartosc = strtol(liczba, &koniec, 10);
        printf("wartosć: %ld, poprzedza %s (%d)\n",wartosc,koniec,*koniec);
        wartosc = strtol(liczba, &koniec, 16);
        printf("wartosć: %ld, poprzedza %s (%d)\n",wartosc,koniec,*koniec);
        puts("Następna liczba:");

    }
*/


/*
----------------------------------------------------pobiera z linii komend
----------------------------------------------------pobiera z linii komend
----------------------------------------------------pobiera z linii komend

int main(int argc, char *argv[]){
   int i, razy;
   if(argc < 2 || (razy = atoi(argv[1])) < 1)
    printf("Sposób użycia: %s liczba-dodatnia\n", argv[0]);
   else
    for(i = 0; i < razy; i++)
        puts("Witaj przystojniaku!");



int main(int argc, char *argv[]){
system("chcp 65001"); // 65001 – UTF-8 Unicode
//system ("chcp 28592"); // 28592 – ISO-8859-2

    int licznik;
    printf("Wiersz poleceń zawiera %d argumentów:\n", argc - 1);
    for(licznik = 0; licznik < argc; licznik++)
        printf("%d: %s\n", licznik, argv[licznik]);
    printf("\n");
----------------------------------------------------pobiera z linii komend
----------------------------------------------------pobiera z linii komend
----------------------------------------------------pobiera z linii komend
*/







/*
#define GRANICA 80
    char wiersz[GRANICA];
    char *tutaj;

    puts("Podaj wiersz tekstu:");
    fgets(wiersz, GRANICA, stdin);
    tutaj = strchr(wiersz, '\n');
    if (tutaj)
        *tutaj = '\0';
    DuzeLit(wiersz);
    puts(wiersz);
    printf("Wpisany wiersz zawiera %d znaków interpunkcyjnych. \n", LiczInter(wiersz));
*/

/*
#define ROZMIAR 81
#define GRAN 20

    char dane[GRAN][ROZMIAR];
    char *wsklan[GRAN];
    int licz = 0;
    int k;
    printf("Podaj maksymalnie %d wierszy, a ja je uporządkuję. \n", GRAN);
    printf("Aby zakończyć, wciśnij ENTER na początku wiersza.\n");
    while(licz < GRAN && wczytaj(dane[licz], ROZMIAR) != NULL && dane[licz][0] != '\0'){
        wsklan[licz] = dane[licz];
        licz++;
    }
    srtlan(wsklan, licz);
    puts("\nOto uporządkowana liczta:\n");
    for(k = 0; k < licz; k++)
        puts(wsklan[k]);
*/


/*
#define MAX 20

    char imie[MAX];
    char nazwisko[MAX];
    char formal[2 * MAX + 10];
    double wygrana;

    puts("Podaj swoje imie:");
    wczytaj(imie, MAX);
    puts("Podaj swoje nazwisko");
    wczytaj(nazwisko, MAX);
    puts("Podaj wygraną sumę pieniędzy:");
    scanf(" %lf", &wygrana);
    sprintf(formal, "%s, %-19s: %6.2f zl\n", nazwisko, imie, wygrana);
    puts(formal);
*/

/*
#define ROZMIAR 40
#define ROZMIAR_CELU 7
#define GRAN 5

    char vslowa[GRAN][ROZMIAR_CELU];
    char temp[ROZMIAR];
    int i = 0;
    printf("Podaj %d slow zaczynających się od v:\n", GRAN);
    while(i < GRAN && wczytaj(temp,ROZMIAR)){
        if(temp[0] != 'v')
            printf("%s nie zaczyna się na v!\n", temp);
        else{
            strncpy(vslowa[i], temp, ROZMIAR_CELU - 1);
            vslowa[i][ROZMIAR_CELU - 1] = '\0';
            i++;
        }
    }
    puts("Oto przyjęte słowa: ");
    for(i = 0; i < GRAN; i++)
        puts(vslowa[i]);
*/


/*
#define SLOWO "cukier"
#define ROZMIAR 40

    const char *zrodlo = SLOWO;
    char kopia[ROZMIAR] = "Podaj mnie do sądu.";
    char *wl;
    puts(zrodlo);
    puts(kopia);
    wl = strcpy(kopia + 6, zrodlo);
    puts(kopia);
    puts(wl - 6);
*/



/*
#define ROZMIAR 40
#define GRAN 5

    char vslowa[GRAN][ROZMIAR];
    char temp[ROZMIAR];
    int i = 0;
    printf("Podaj %d słów zaczynających się na v:\n", GRAN);
    while(i < GRAN && wczytaj(temp, ROZMIAR)){
        if(temp[0] != 'v')
            printf("%s nie zaczyna się na v!\n", temp);
        else{
            strcpy(vslowa[i], temp);
            i++;
        }
    }
    puts("Oto przyjęte słowa: ");
    for(i = 0; i < GRAN; i++)
        puts(vslowa[i]);
*/




/*
#define ROZMIARLISTY 5

    const char *lista[ROZMIARLISTY] = {
            "astronomia", "asteroida",
            "astrofizyka", "ostroga",
            "asteryzm"};
    int licznik = 0;
    int i;
    for(i = 0; i < ROZMIARLISTY; i++)
        if(strncmp(lista[i],"astro", 5) == 0){
            printf("Znaleziono : %s\n", lista[i]);
            licznik++;
    }
    printf("Lista zawiera %d słowa zaczynające się na astro.\n", licznik);
*/

/*
#define ROZMIAR 81
#define GRAN 10
#define STOP "koniec"

    char wejscie[GRAN][ROZMIAR];
    int licz = 0;
    printf("Wpisz maksymalnie %d wierszy (wpisz koniec, aby zakończyć):\n", GRAN);
    while(licz < GRAN && wczytaj(wejscie[licz], ROZMIAR) != NULL && strcmp(wejscie[licz], STOP) != 0){
        licz++;
    }
    printf("Podano %d łańcuchów\n", licz);
*/





/*
    printf("strcmp(\"A\", \"A\") = ");
    printf("%d\n", strcmp("A", "A"));

    printf("strcmp(\"A\", \"C\") = ");
    printf("%d\n", strcmp("A", "C"));

    printf("strcmp(\"B\", \"A\") = ");
    printf("%d\n", strcmp("B", "A"));

    printf("strcmp(\"C\", \"A\") = ");
    printf("%d\n", strcmp("C", "A"));

    printf("strcmp(\"Z\", \"A\") = ");
    printf("%d\n", strcmp("Z", "A"));

    printf("strcmp(\"koty\", \"kot\") = ");
    printf("%d\n", strcmp("koty", "kot"));
*/


/*
char *wczytaj(char *z, int ile){
    char *wynik;
    int i = 0;
    wynik = fgets(z, ile, stdin);
    if(wynik){
        while(z[i] != '\n' && z[i] != '\0')
            i++;
        if(z[i] == '\n')
            z[i] = '\0';
        else while (getchar() != '\n')
            continue;
    }
    return wynik;
}
#define ODPOWIEDZ "Grant"
#define MAX 40

    char proba[MAX];

    puts("Kto jest pochowany w grobowcu Granta?");
    wczytaj(proba, MAX);
    while(strcmp(proba, ODPOWIEDZ) != 0){
        puts("Niestety to nie jest dobra odpowiedz. Spróbuj jeszcze raz.");
        wczytaj(proba, MAX);
    }
    puts("Tak jest !");
*/


/*
char *wczytaj(char *z, int ile){
    char *wynik;
    int i = 0;
    wynik = fgets(z, ile, stdin);
    if(wynik){
        while(z[i] != '\n' && z[i] != '\0')
            i++;
        if(z[i] == '\n')
            z[i] = '\0';
        else while (getchar() != '\n')
            continue;
    }
    return wynik;
}

#define ROZMIAR 30
#define ROZMIAR_OWADY 17

   char kwiaty[ROZMIAR];
   char dodatek[] = " smierdza jak stere buty.";
   char owady[ROZMIAR_OWADY];

   int wolne;
   puts("Jakie kwiaty lubisz najbardziej?");
   wczytaj(kwiaty, ROZMIAR);
   if((strlen(dodatek) + strlen(kwiaty) + 1) <= ROZMIAR)
    strcat(kwiaty, dodatek);
   puts(kwiaty);
   puts("Jakie owady lubisz najbardziej?");
   wczytaj(owady, ROZMIAR_OWADY);
   wolne = ROZMIAR_OWADY - strlen(owady) - 1;
   strncat(owady, dodatek, wolne);
   puts(owady);
*/



/*
char *wczytaj(char *z, int ile){
    char *wynik;
    int i = 0;
    wynik = fgets(z, ile, stdin);
    if(wynik){
        while(z[i] != '\n' && z[i] != '\0')
            i++;
        if(z[i] == '\n')
            z[i] = '\0';
        else while (getchar() != '\n')
            continue;
    }
    return wynik;
}
#define ROZMIAR 80
    int kwiat[ROZMIAR];
    char dodatek[] = " śmierdzą jak stare buty.";
    puts("Jakie kwiaty lubisz najbardziej ?");
    if (wczytaj(kwiat, ROZMIAR)){
        strcat(kwiat, dodatek);
        puts(kwiat);
        puts(dodatek);
    }
*/

/*
void skroc(char *lancuch, unsigned int rozmiar){
    if(strlen(lancuch) > rozmiar)
        *(lancuch + rozmiar) = '\0';
}

    char tekst[] = "Wyjaśnienia powinny być tak proste jak to możliwe, ale nie prostsze.";
    puts(tekst);
    skroc(tekst,12);
    puts(tekst);
    puts("Spójrzmy na resztę łańcucha. ");
    puts(tekst + 13);
*/



/*
void wysw1(const char *lancuch){
    while(*lancuch != '\0')
        putchar(*lancuch++);
}

int wysw2(const char *lancuch){
    int i = 0;
    while(*lancuch != '\0'){
        putchar(*lancuch++);
        i++;
    }
    putchar('\n');
    return i;
}


#define LL "listownie"
    wysw1("Gdybym mial fure kasy,");
    wysw1("zrobil bym zapasy");
    printf("Naliczyłem %d znaków.\n", wysw2("Albo pojechał na wczasy"));


    char tab[] = "Listownie";
    printf("\ntest\n");
    wysw1(LL);
    printf("\ntest\n");
    wysw1(tab);
    putchar("\n");
    while(putchar(tab) != '\0') continue;
*/




/*
    char slowo[] = "0";
    printf("%c %d\n", slowo[0], slowo[0]);
*/


/*  char przed[] = "Przed";
    char nie[] = {'N', 'I', 'E', '!', };
    char za [] = "Za";
    puts(nie);


#define DEF "Jestem zdefiniowanym łańcuchem."

    char lan1[80] = "Przypisano mnie tablicy";
    char *lan2 = "Przypisano mnie wskaźnikowi";
    puts("Jestem argumentem funkcji puts()");
    puts(DEF);
    puts(lan1);
    puts(lan2);
    puts(&lan1[5]);
    puts(lan2 + 4);
*/

/*
    char imie1[11], imie2[11];
    int i;

    printf("Podaj 2 imiona.\n");
    i = scanf("%5s %10s", imie1, imie2);
    printf("Odczytałem %d imiona: %s i %s.\n", i, imie1, imie2);
*/



/*
    char *tekst;
    wczytaj (&tekst, 10);
    printf("%s\n", &tekst);
*/



/*
char *wczytaj(char *z, int ile){
    char *wynik;
    int i = 0;
    wynik = fgets(z, ile, stdin);
    if(wynik){
        while(z[i] != '\n' && z[i] != '\0')
            i++;
        if(z[i] == '\n')
            z[i] = '\0';
        else while (getchar() != '\n')
            continue;
    }
    return wynik;
}
*/

/*
#define DLUGOSC 10

    char slowa[DLUGOSC];
    int i;

    puts("Wprowadź łańcuch (pusty wiersz zakończy program):");
    while (fgets(slowa, DLUGOSC, stdin) != NULL && slowa[0] != '\n'){
        i = 0;
        while(slowa[i] != '\n' && slowa[i] != '\0')
            i++;
        if (slowa[i] == '\n')
            slowa[i] = '\0';
        else while (getchar() != '\n')
            continue;
        puts(slowa);
    }
    puts("gotowe !");
    gets_s(slowa, DLUGOSC);
*/

/*
#define DLUGOSC 100

    char slowa[DLUGOSC];
    puts("Wprowadź łańcuchy (pusty wiersz zakończy program)");
    while (fgets(slowa, DLUGOSC, stdin) != NULL && slowa[0] != '\n')
        fputs(slowa,stdout);
    fputs(slowa, stdout);
    puts("gotowe!");
*/

/*
#define DLUGOSC 14
    char slowa[DLUGOSC];
    puts("Proszę wprowadzić łańcuch.");
    fgets(slowa, DLUGOSC, stdin);
    printf("Wprowadzony łańcuch dwa razy (puts i fputs):\n");
    puts(slowa);
    fputs(slowa, stdout);
    int i;
    for(i = 0; i < 10; i++){
        if(slowa[i] != 10)
        printf("%c %d\n", slowa[i], slowa[i]);
        else {printf("xxx 10\n"); continue;}
    }
*/


/*
#define DLUGOSC 81
    char slowa[DLUGOSC];
    puts("Proszę wprowadzić łańcuch.");
    fgets(slowa, 10, stdin);

    printf("Wprowadzony łańcuch (dwa razy):\n");
    printf("%s\n", slowa);
    puts(slowa);
    puts("Gotowe!");

    int i;
    for(i = 0; i < 10; i++)
        printf("%c %d\n", slowa[i], slowa[i]);
    puts("\n\n\n");
    //int i;
    for(i = 0; i != EOF; i++){
        printf("%c %d\n", slowa[i], slowa[i]);
        if(i > 10) break;
    }
*/





/*    char *tekst = "Nie bądź głupi!";
    char *kopia;

    kopia = tekst;
    printf("%s\n", kopia);
    printf("tekst = %s; &tekst = %p; wartość = %p\n", tekst, &tekst, tekst);
    printf("kopia = %s; &kopia = %p; wartość = %p\n", kopia, &kopia, kopia);
*/

/*
    char *p1 = "Klingon";
    //p1[0] = 'F';
    printf("Klingon");
    printf(": Uwaga %si!\n","Klingon");

#define DLUGOSC 40
#define MAX 5

    const char *wymagania[MAX] = {
        "Dodawanie w pamieci",
        "Bezbłędne mnożenie",
        "Szybkie zapamiętywanie",
        "Dosłowne wykonywanie poleceń",
        "Programowanie w C"
    };

    char umiejetnosci[MAX][DLUGOSC] = {
        "Chodzenie wzdłuż lini",
        "Spanie", "Oglądanie TV",
        "wysyłanie poczty", "Czytanie e-maili"
    };

    int i;
    puts("Porównajmy:");
    printf("%-36s %-25s\n", "Wymagania", "Umiejętności");
    for(i = 0; i < MAX; i++)
        printf("%-36s %-25s\n", wymagania[i], umiejetnosci[i]);
    printf("\nsizeof wymagania: %d, sizeof umiejetnosci: %d\n", sizeof(wymagania), sizeof(umiejetnosci));
*/






/*#define LANCUCH "Jestem wyjątkowy"
    char tab[] = LANCUCH;
    const char *wsk = LANCUCH;
    printf("adres \"Jestem wyjątkowy\": %p \n", "Jestem wyjątkowy");
    printf(" adres tab: %p\n", tab);
    printf(" adres wks: %p\n", wsk);
    printf(" adres LANCUCH-a: %p\n", LANCUCH);
    printf("adres \"Jestem wyjątkowy\": %p\n", "Jestem wyjątkowy");



    char t1 = "tata";
    int *napis[10];
    napis[0] = "to jest napis.";
    napis[1] = "drugi napis.";
    //char *wsk = t1;
    int i;
    for(i = 0; i < 20; i++)
        printf("%c %d\n", *(wsk + i), wsk + i);

    printf("%s, %p, %c\n", "Nie", "jesteśmy", *"kosmicznymi");
*/






/*
#define NAPIS "To jest stała łańcuchowa."
#define MAXDL 81

    char slowa[MAXDL] = "To jest łancuch w tablicy.";
    const char *wsk1 = "Coś mnie wskazuje.";

    puts("Oto kilka łańcuchów");
    puts(NAPIS);
    puts(slowa);
    puts(wsk1);
    slowa[1] = 'u';
    puts(slowa);
*/



/*    int (*wsk)[2];
    int torf[2][2] = {12,14,16};
    wsk = torf;
    printf(" %d %d\n", **wsk, **(wsk + 1));
    */

/*   int *wsk;
    int fort[2][2] = {{12}, {14,15}};
    wsk = fort[0];
    printf(" %d %d\n", *wsk, *(wsk + 1));
*/


/*    int tab[10][10] = {{0,1,2,3,4,5,6,7,8,9}, {10,11,22,33,44,55,66,77,88,99}};
    int (*wsk)[10];
    wsk = tab;

    printf("Adres początku tablicy   wsk = %p\n", wsk);
    printf("tab[0][0] = %d\n", tab[0][0]);
    printf("Adres początku tablicy   ((wsk+0)+0) = %p\n", ((wsk+0)+0));
    printf("**(wsk + 0) = %d\n", **(wsk + 0));
    printf("**(wsk + 1) = %d\n", **(wsk + 1));
    printf("*(*(wsk + 1) + 9) = %d\n", *(*(wsk+1) + 9));
 */



/*
#define KOLUMNY 4
int sumuj2d(const int tab[][KOLUMNY], int wiersze){
    int w;
    int k;
    int suma = 0;
    for (w = 0; w < wiersze; w++)
        for (k = 0; k < KOLUMNY; k++)
            suma += tab[w][k];
    return suma;
}
int sumuj(const int tab[], int n){
    int i;
    int suma = 0;
    for(i = 0; i < n; i++)
        suma += tab[i];
    return suma;
}
    int suma1, suma2, suma3;
    int *wsk1;
    int (*wsk2)[KOLUMNY];
    wsk1 = (int [2]){10,20};
    wsk2 = (int [2][KOLUMNY]){{1,2,3,-9},{4,5,6,-8}};

    suma1 = sumuj(wsk1 ,2);
    suma2 = sumuj2d(wsk2,2);
    suma3 = sumuj((int[]){4,4,4,5,5,5},6);
    printf("suma1 = %d\n", suma1);
    printf("suma2 = %d\n", suma2);
    printf("suma3 = %d\n", suma3);
*/











/*
#define WIERSZE 3
#define KOLUMNY 4
int sumuj2d(int wiersze, int kolumny, int tab[wiersze][kolumny]);
int sumuj2d(int wiersze, int kolumny, int tab[wiersze][kolumny]){
    int w;
    int k;
    int suma = 0;
    for (w = 0; w < wiersze; w++)
        for (k = 0; k < kolumny; k++)
            suma += tab[w][k];
    return suma;
}
    int i, j;
    int rw = 3;
    int rk = 10;
    int graty[WIERSZE][KOLUMNY] = {
            {2,4,6,8},
            {3,5,7,9},
            {12,10,8,6}
    };
    int wiecejgratow[WIERSZE-1][KOLUMNY+2] = {
        {20,30,40,50,60,70},
        {5,6,7,8,9,10}
    };

    int zmtab[rw][rk]; //VLA

    for(i = 0; i < rw; i++)
        for(j = 0; j < rk; j++)
            zmtab[i][j] = i * j + j;
    printf("tablica 3x5\n");
    printf("Suma wszystkich elementów = %d\n",sumuj2d(WIERSZE, KOLUMNY, graty));
    printf("tablica 2x6\n");
    printf("Suma wszystkich elementów = %d\n",sumuj2d(WIERSZE-1, KOLUMNY+2, wiecejgratow));
    printf("VLA 3x10\n");
    printf("Suma wszystkich elementów = %d\n", sumuj2d(rw, rk, zmtab));
*/







/*
#define WIERSZE 3
#define KOLUMNY 4

void sumuj_wiersze(int tab[][KOLUMNY], int wiersze);
void sumuj_kolumny(int [][KOLUMNY], int);
int sumuj2d(int (*tab)[KOLUMNY], int wiersze);

void sumuj_wiersze(int tab[][KOLUMNY], int wiersze){
    int w;
    int k;
    int suma;
    for (w = 0; w < wiersze; w++){
        suma = 0;
        for (k = 0; k < KOLUMNY; k++)
            suma += tab[w][k];
        printf("Wiersze %d: suma = %d\n", w, suma);
    }
}

void sumuj_kolumny(int tab[][KOLUMNY], int wiersze){
    int w;
    int k;
    int suma;
    for(k = 0; k < KOLUMNY; k++){
        suma = 0;
        for(w = 0; w < wiersze; w++)
            suma += tab[w][k];
        printf("Kolumna %d: suma = %d\n", k, suma);
    }
}

int sumuj2d(int tab[][KOLUMNY], int wiersze){
    int w;
    int k;
    int suma = 0;
    for(w = 0; w < wiersze; w++)
        for(k = 0; k < KOLUMNY; k++)
            suma += tab[w][k];
    return suma;
}


    int graty[WIERSZE][KOLUMNY] = {
            {2,4,6,8},
            {3,5,7,9},
            {12,10,8,6}
    };

    sumuj_wiersze(graty, WIERSZE);
    sumuj_kolumny(graty, WIERSZE);
    printf("Suma wszystkich elementów = %d\n", sumuj2d(graty,WIERSZE));
*/




/*
    int n = 5;
    double x;
    int *p1 = &n;
    double *p2 = &x;
    x = n;
    p2 = p1;
    printf("%d\n", *p2);
*/

/*
    int zippo[4][2] = { {2,4}, {6,8}, {1,3}, {5,7}};
    int (*pz)[2] = zippo;

    printf("   pz = %p,    pz + 1 = %p\n", pz, pz + 1);
    printf("pz[0] = %p, pz[0] + 1 = %p\n", pz[0], pz[0] + 1);
    printf("  *pz = %p,   *pz + 1 = %p\n", *pz, *pz + 1);
    printf("pz[0][0] = %d\n", pz[0][0]);
    printf("  *pz[0] = %d\n", *pz[0]);
    printf("    **pz = %d\n", **pz);
    printf("      pz[2][1] = %d\n", pz[2][1]);
    printf("*(*(pz +2) +1) = %d\n\n\n", *(*(pz +2) +1));






    //int zippo[4][2] = { {2,4}, {6,8}, {1,3}, {5,7}};

    printf("   zippo = %p,    zippo + 1 = %p\n", zippo, zippo + 1);
    printf("zippo[0] = %p, zippo[0] + 1 = %p\n", zippo[0], zippo[0] + 1);
    printf("  *zippo = %p,   *zippo + 1 = %p\n", *zippo, *zippo + 1);
    printf("zippo[0][0] = %d\n", zippo[0][0]);
    printf("  *zippo[0] = %d\n", *zippo[0]);
    printf("    **zippo = %d\n", **zippo);
    printf("      zippo[2][1] = %d\n", zippo[2][1]);
    printf("*(*(zippo +2) +1) = %d\n", *(*(zippo +2) +1));
*/



/*
#define ROZMIAR 5
    double dip[ROZMIAR] = {20.0, 17.66, 8.2, 15.3, 22.22};
    printf("Początkowa tablica dip:\n");
    pokaz_tablice(dip, ROZMIAR);
    pomnoz_tablice(dip, ROZMIAR, 2.5);
    printf("Tablica dip po powołaniu funkcji pomnoz_tablice():\n");
    pokaz_tablice(dip, ROZMIAR);


void pokaz_tablice(const double tab[], int n){
    int i;
    for(i = 0; i < n; i++)
        printf("%8.3f ", tab[i]);
    putchar('\n');
}

void pomnoz_tablice(double tab[], int n, double mnoz){
    int i;
    for(i = 0; i < n; i++){
        tab[i] *= mnoz;
    }
}
*/






/*    int urna[5] = {100, 200, 300, 400, 500};
    int *wsk1, *wsk2, *wsk3;
    wsk1 = urna;
    wsk2 =&urna[2];

    printf("wartość wskaźnika, wskazywana wartość, adres wskaźnika:\n");
    printf("wsk1 = %p, *wsk1 =%d, &wsk1 = %x\n", wsk1, *wsk1, &wsk1);

    wsk3 = wsk1 + 4;
    printf("\n dodawanie int do wskaźnika:\n");
    printf("wsk1 + 4 = %x, *(wsk1 + 3) = %d\n", wsk1 + 4, *(wsk1 + 3));

    wsk1++;
    printf("\n wartość po wsk1++:\n");
    printf("wsk1 = %x, *wsk1 = %d, &wsk1 = %x\n", wsk1, *wsk1, &wsk1);

    wsk2--;
    printf("\n wartość po wsk2--:\n");
    printf("wsk2 = %x, *wsk2 = %d, &wsk2 = %x\n", wsk2, *wsk2, &wsk2);

    --wsk1;
    ++wsk2;
    printf("\n wskaźniki przywrócone do początkowych wartości:");
    printf("wsk1 = %x, wsk2 = %x\n", wsk1, wsk2);

    printf("\n odejmowanie jednego wskaźnika od drugiego:\n");
    printf("wsk2 = %x, wsk1 = %x, wsk2 - wsk1 = %d\n", wsk2, wsk1, wsk2 - wsk1);

    printf("\n odejmowanie zmiennej int od wskaźnika:\n");
    printf("wsk3 = %x, wsk3 - 2 = %x\n", wsk3, wsk3 -2);
*/




/*  int dane[2] = {100, 200};
    int wiecejdanych[2] = {300, 400};
    int *w1, *w2, *w3;
    w1 = w2 = dane;
    w3 = wiecejdanych;
    printf("  *w1 = %d,   *w2 = %d,   *w3 = %d\n", *w1, *w2, *w3);
    printf("*w1++ = %d, *++w2 = %d, (*w3)++ = %d\n", *w1++, *++w2, (*w3)++);
    printf("  *w1 = %d,   *w2 = %d,   *w3 = %d\n", *w1, *w2, *w3);
*/


/*
    //long sumujw(int *poczatek, int *koniec);
    int kulki[] = {0};
    long wynik;
    wynik = sumujw(kulki, kulki + sizeof(kulki) / sizeof(kulki + 0));
    printf("Całkowita liczba kulek = %ld.\n", wynik);
}
long sumujw (int *poczatek, int *koniec){
    int suma = 0;
    while(poczatek < koniec){
        suma += *poczatek;
        poczatek++;
    }
    return suma;
}
*/


/*
    int kulki[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    long sumuj(int tab[], int n);
    long wynik;
    wynik = sumuj(kulki, sizeof(kulki) / sizeof(kulki + 0));
    printf("rozmiar w bajtach 1'ego elementu tablicy: %d\nrozmiar w bajtach całej tablicy: %d\nilość elementów w tablicy: %d\n",(sizeof(kulki[0])), (sizeof(kulki)), (sizeof(kulki) / sizeof(kulki+0)));
    printf("suma elementów w tablicy: %ld\n", wynik);


    long sumuj(int tab[], int n){
    int i;
    int suma = 0;
    for (i = 0; i < n; i++)
        suma += tab[i];
    return suma;
}
*/




/*
#define MIESIACE 12
    int dni[MIESIACE] = {31, 28, [4] = 31, 30, 31, [1] = 29};
    int i;
    for(i = 0; i < MIESIACE; i++)
        printf("%2d %d\n", i + 1, *(dni + i));
*/


/*
#define ROZMIAR 4

    short daty[ROZMIAR];
    short *wski;
    short index;
    double rachunki[ROZMIAR];
    double *wskf;
    wski = daty;
    wskf = rachunki;
    printf("%23s %15s\n", "short", "double");
    for(index = 0;  index < ROZMIAR; index++)
        printf("wskaźniki + %d: %10p %10p\n", index, wski + index, wskf + index);

    printf("%p %p\n", daty, rachunki);
*/





/*
#define MIESIACE 12
#define LATA 5

    const float deszcz[LATA][MIESIACE] = {
        {4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
        {8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3},
        {9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4},
        {7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2},
        {7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,5.2}};
    int rok, miesiac;
    float podsuma, suma;

    printf(" ROK        OPADY (w calach)\n");
    for(rok = 0, suma = 0; rok < LATA; rok++){
        for(miesiac = 0, podsuma = 0; miesiac < MIESIACE; miesiac++)
            podsuma += deszcz[rok][miesiac];
        printf("%5d %12.1f\n", 2000 + rok, podsuma);
        suma += podsuma;
    }
    printf("\nRoczna średnia wynosi %.1f cale\n\n", suma/LATA);
    printf("Średnie miesięczne: \n\n");
    printf(" Sty  Lut  Mar  Kwi  Maj  Cze  Lip  Sie  Wrz  Paz  Lis  Gru\n");

    for(miesiac = 0; miesiac < MIESIACE; miesiac++){
        for(rok = 0, podsuma = 0; rok < LATA; rok++)
            podsuma += deszcz[rok][miesiac];
        printf("%4.1f ", podsuma/LATA);
    }
    printf("\n");
*/



/*
#define ROZMIAR 4
    int zm1 = 44;
    int tab[ROZMIAR];
    int zm2 = 88;
    int i;
    printf("zm1 = %d, zm2 = %d\n", zm1, zm2);
    for(i = -1; i <= ROZMIAR; i++)
        tab[i] = 2 * i + 1;
    for (i = -1; i < 7; i++)
        printf("%2d %d\n", i, tab[i]);
    printf("zm1 = %d, zm2 = %d\n", zm1, zm2);
    printf("adres tab[-1]: %p\n", &tab[-1]);
    printf("adres tab[4]: %p\n", &tab[4]);
    printf("adres zm1: %p\n", &zm1);
    printf("adres zm2: %p\n", &zm2);
*/


/*
#define MIESIACE 12
    int dni[MIESIACE] = {31, 28, [4] = 31, 30, 31, [1] = 29};
    int i;
    for(i = 0; i < MIESIACE; i++)
        printf("%2d %d\n", i + 1, dni[i]);
*/



/*
    int dni[] = {31,28,31,30,31,30,31,31,30,31};
    int index;
    for(index = 0; index < sizeof dni / sizeof (int); index++)
        printf("Miesiąc %d ma %d dni.\n", index +1, dni[index]);
*/


/*
#define ROZMIAR 4

    int troche_danych[ROZMIAR] = {1492, 1066};
    int i;
    printf("%2s%14s\n", "i", "troche_danych[i]");
    for(i = 0; i < ROZMIAR; i++)
        printf("%2d%14d\n", i, troche_danych[i]);
*/



/*
#define ROZMIAR 4

    int brak_danych[ROZMIAR];
    int i;
    printf("%2s%14s\n", "i", "brak_danych[i]");
    for(i = 0; i < ROZMIAR; i++)
        printf("%2d%14d\n", i, brak_danych[i]);
*/



/*
#define MIESIACE 12

    int dni[MIESIACE] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int index;
    for(index = 0; index < MIESIACE; index++){
        printf("Miesiąc %d ma %d dni. \n", index + 1, dni[index]);
    }
*/






/*--------------------------------------WSKAŹNIKI-----------------------------------------------------------
int main(){
system("chcp 65001"); // 65001 – UTF-8 Unicode
//system ("chcp 28592"); // 28592 – ISO-8859-2

    int *p;
    while(1){
        p=(int *)malloc(4);
        if(!p)break;
        printf("%p\n", p);
    }



    int64_t last = 0;
    int64_t i;
    int64_t aSize;
    int64_t *randomNums;
    time_t t;
    double total = 0;
    int64_t biggest, smallest;
    float average;

    srand(time(&t));

    printf("Ile liczb losowych chcesz zapisać w tablicy? ");
    scanf(" %I64d", &aSize);
    printf("\naSize = %I64d\n", aSize);

    randomNums = (int64_t*) malloc(aSize * sizeof(int64_t));

    if(!randomNums){
        printf("Nie udało się alokować tablicy!\n");
        exit(1);
    }

    for (i = 0; i < aSize; i++){
        randomNums[i] = (rand() % 500) + 1;
    }

    biggest = 0;
    smallest = 500;

    for (i = 0; i < aSize; i++){
        total += randomNums[i];
        if (randomNums[i] > biggest){
            biggest = randomNums[i];
        }
        if (randomNums[i] < smallest){
            smallest = randomNums[i];
        }
    }

    average = ((float) total) / ((float)aSize);

    printf("Największa liczba: %ld\n", biggest);
    printf("Najmniejsza liczba: %ld\n", smallest);
    printf("Średnia: %.2f\n", average);

    randomNums[10] = 66;
    printf("randomNums[10] = %d \n", randomNums[10]);
    free(randomNums);
    printf("randomNums[10] = %d \n", randomNums[10]);

    for(i = 10000000000; i > last; i++){
       printf("%I64d\n", i);
       last = i;
    }




        //JCSP();
        //zmienne();
printf("\a");
return 0;
}
--------------------------------------WSKAŹNIKI-----------------------------------------------------------*/







/*
        int i;
        int ctr = 0;
        char ans;

        char *movies[9] = {"Miłość", "Operacja arbo", "Bestie z południowej krainy",
                            "Django", "Nędznicy", "Życie PI", "Lincoln", "Poradnik pozytywnego myślenia",
                            "Wróg numer jeden"};

        int movieratings[9];
        char * tempmovie = "Informacje te zostaną wykorzystane do posortowania ocenionych filmów";
        int outer, inner, didSwap, temprating;

        printf("\n\n*** Sezon oscarowy 2012! ***\n\n");
        printf("Czas ocenić najlepszych kandydatów do Oscara:");

        for (i=0; i<9; i++){
            printf("\nCzy oglądałeś film %s? (T/N):", movies[i]);
            scanf(" %c", &ans);
            if ((toupper(ans)) == 'T'){
                printf("\nJak oceniasz ten film w skali \n od 1 do 10 ? ");
                scanf(" %d", &movieratings[i]);
                ctr++;
                continue;
            }
            else{
                movieratings[i] = -1;

            }
        }


        for (outer = 0; outer < 8; outer++){
            didSwap = 0;
            for (inner = outer; inner < 9; inner++){
                if(movieratings[inner] > movieratings[outer]){
                    tempmovie = movies[inner];
                    temprating = movieratings[inner];
                    movies[inner] = movies[outer];
                    movieratings[inner] = movieratings[outer];
                    movies[outer] = tempmovie;
                    movieratings[outer] = temprating;
                    didSwap = 1;
                }
            }
            if (didSwap == 0) {
                break;
            }
        }


        printf("\n\n** Oto Twoje oceny filmów nominowanych do Oscara w 2012 roku**\n");

        for (i=0; i < ctr; i++){
            printf("Film %s otrzymał ocenę %d!\n", movies[i], movieratings[i]);
        }
*/


/*
        int i;
        int ctr = 0;
        char ans;

        char *movies[9] = {"Miłość", "Operacja arbo", "Bestie z południowej krainy",
                            "Django", "Nędznicy", "Życie PI", "Lincoln", "Poradnik pozytywnego myślenia",
                            "Wróg numer jeden"};

        int movieratings[9];
        char * tempmovie = "Informacje te zostaną wykorzystane do posortowania ocenionych filmów";
        int outer, inner, didSwap, temprating;

        printf("\n\n*** Sezon oscarowy 2012! ***\n\n");
        printf("Czas ocenić najlepszych kandydatów do Oscara:");

        for (i=0; i<9; i++){
            printf("\nCzy oglądałeś film %s? (T/N):", movies[i]);
            scanf(" %c", &ans);
            if ((toupper(ans)) == 'T'){
                printf("\nJak oceniasz ten film w skali \n od 1 do 10 ? ");
                scanf(" %d", &movieratings[i]);
                ctr++;
                continue;
            }
            else{
                movieratings[i] = -1;

            }
        }


        for (outer = 0; outer < 8; outer++){
            didSwap = 0;
            for (inner = outer; inner < 9; inner++){
                if(movieratings[inner] > movieratings[outer]){
                    tempmovie = movies[inner];
                    temprating = movieratings[inner];
                    movies[inner] = movies[outer];
                    movieratings[inner] = movieratings[outer];
                    movies[outer] = tempmovie;
                    movieratings[outer] = temprating;
                    didSwap = 1;
                }
            }
            if (didSwap == 0) {
                break;
            }
        }


        printf("\n\n** Oto Twoje oceny filmów nominowanych do Oscara w 2012 roku**\n");

        for (i=0; i < ctr; i++){
            printf("Film %s otrzymał ocenę %d!\n", movies[i], movieratings[i]);
        }

*/






















/*
void zamiana(int *u, int *v);

int main(){
system("chcp 65001"); // 65001 – UTF-8 Unicode
//system ("chcp 28592"); // 28592 – ISO-8859-2

    int x = 5, y = 10;
    printf("Początkowo x = %d, a y = %d.\n", x, y);
    zamiana(&x,&y);
    printf("A teraz x = %d, a y = %d.\n", x, y);








        //JCSP();
        //zmienne();
printf("\a");
return 0;
}

void zamiana (int *u, int *v){
    int temp;
    printf("Początkowo u = %d, a v = %d.\n", *u, *v);
    temp = *u;
    *u = *v;
    *v = temp;
    printf("A teraz u = %d, a v = %d.\n", *u, *v);
}
*/




/*
void mikado(int);

int main(){
system("chcp 65001"); // 65001 – UTF-8 Unicode
//system ("chcp 28592"); // 28592 – ISO-8859-2

    int ach = 2, och = 5;
    printf("W funkcji main () ach = %d, a &ach = %p\n", ach, &ach);
    printf("W funkcji main () och = %d, a &och = %p\n", och, &och);
    mikado(ach);







        //JCSP();
        //zmienne();
printf("\a");
return 0;
}


void mikado(int och){
    int ach = 10;
    printf("W funkcji mikado() ach = %d, a &ach = %p\n", ach, &ach);
    printf("W funkcji mikado() och = %d, a &och = %p\n", och, &och);
}
*/





/*
void do_binary(unsigned long n);


int main(){
system("chcp 65001"); // 65001 – UTF-8 Unicode
//system ("chcp 28592"); // 28592 – ISO-8859-2


    unsigned long liczba;
    printf("Podaj liczbę całkowitą (q kończy program):\n");
    while(scanf(" %ld", &liczba) == 1){
        printf("Odpowiednik dwójkowy: ");
        do_binary(liczba);
        putchar('\n');
        printf("Podaj liczbę całkowitą (q kończy program):\n");
    }
    printf("Koniec\n");





        //JCSP();
        //zmienne();
printf("\a");
return 0;
}

void do_binary(unsigned long n){
    int r;
    r = n %2;
    if (n >= 2)
        do_binary(n / 2);
    putchar(r == 0 ? '0' : '1');
    return;
}
*/












/*
long silnia (int n);
long rsilnia (int n);



int main(){
system("chcp 65001"); // 65001 – UTF-8 Unicode
//system ("chcp 28592"); // 28592 – ISO-8859-2

        int num;
        printf("Ten program liczy silnie.\n");
        printf("Podaj liczbę z przedziału 0-12 (k- koniec):\n");
        while(scanf(" %d", &num) == 1){
            if (num < 0)
                printf("Proszę nie podawać liczb ujemnych\n");
            else if (num > 20)
                printf("Proszę podać wartość mniejszą od 13.\n");
            else{
                printf("pętla: %d silnia = %ld\n", num, silnia(num));
                printf("rekurencja: %d silnia = %ld\n", num, rsilnia(num));
            }
            printf("Podaj liczbę z przedziału 0-12 (k-koniec):\n");
        }
        printf("Koniec!");






        //JCSP();
        //zmienne();
printf("\a");
return 0;
}

long silnia(int n){
    long wyn;
    for (wyn = 1; n > 1; n--)
        wyn *= n;
    return wyn;
}

long rsilnia(int n){
    long wyn;
    if (n > 0)
        wyn = n * rsilnia(n-1);
    else
        wyn = 1;
    return wyn;
}
*/



/*
void gora_i_dol(int);

int main(){
system("chcp 65001"); // 65001 – UTF-8 Unicode
//system ("chcp 28592"); // 28592 – ISO-8859-2

        gora_i_dol(1);




        //JCSP();
        //zmienne();
printf("\a");
return 0;
}

void gora_i_dol(int n){
        printf("Poziom: %d: adres zmiennej n: %p\n", n, &n);
        if (n < 4)
            gora_i_dol(n+1);
        printf("POZIOM %d: adres zmiennej n: %p\n", n, &n);

}

*/



/*
int imax(int, int);

int main(){
system("chcp 65001"); // 65001 – UTF-8 Unicode
//system ("chcp 28592"); // 28592 – ISO-8859-2

        printf("Większą liczbą z %d i %d jest %d\n", 3, 5, imax(3, 5));
        printf("Większą liczbą z %d i %d jest %d\n", 3, 5, imax(3.0, 5.0));



        //JCSP();
        //zmienne();
printf("\a");
return 0;
}

int imax(int n, int m){
    return (n > m ? n : m);
}
*/



/*
int imin(int,int);

int main(){
system("chcp 65001"); // 65001 – UTF-8 Unicode
//system ("chcp 28592"); // 28592 – ISO-8859-2

        int zlo1, zlo2;
        printf("Podaj dwie liczby całkowite (q kończy program):\n");
        while (scanf(" %d %d", &zlo1, &zlo2) == 2){
            printf("Mniejsza liczba spośród %d i %d jest %d.\n", zlo1, zlo2, imin(zlo1, zlo2));
            printf("Podaj dwie liczby całkowite (q kończy program):\n");
        }
        printf("Gotowe.\n");



        //JCSP();
        //zmienne();
printf("\a");
return 0;
}

int imin(int n,int m){
   if (n < m)
    return n;
   else
    return m;
}

*/





/*
void n_znak(char ch, int num);
const char LIMIT = 40;
const char ODSTEP = ' ';


int main(){
system("chcp 65001"); // 65001 – UTF-8 Unicode
//system ("chcp 28592"); // 28592 – ISO-8859-2


        const char NAZWA[] = "MEGATHINK, INC.";
        const char ADRES[] = "10 Megabuck Plaza";
        const char MIEJSCOWOSC[] = "Megapolis, CA 94904";
        int odstepy;

        n_znak('*', LIMIT);
        putchar('\n');
        n_znak(ODSTEP, 12);
        printf("%s\n", NAZWA);
        odstepy = (LIMIT - strlen(ADRES)) / 2;
        n_znak(ODSTEP, odstepy);
        printf("%s\n", ADRES);
        n_znak(ODSTEP, (LIMIT - strlen(MIEJSCOWOSC)) / 2);
        printf("%s\n", MIEJSCOWOSC);
        n_znak('*', LIMIT);
        putchar('\n');







        //JCSP();
        //zmienne();
printf("\a");
return 0;
}

void n_znak(char ch, int num){
        int licznik;
        for (licznik = 1; licznik <= num; licznik++)
            putchar(ch);
}
*/



/*
void n_znak(char ch, int num);
const char LIMIT = 40;
const char ODSTEP = ' ';


int main(){
system("chcp 65001"); // 65001 – UTF-8 Unicode
//system ("chcp 28592"); // 28592 – ISO-8859-2


        const char NAZWA[] = "MEGATHINK, INC.";
        const char ADRES[] = "10 Megabuck Plaza";
        const char MIEJSCOWOSC[] = "Megapolis, CA 94904";
        int odstepy;

        n_znak('*', LIMIT);
        putchar('\n');
        n_znak(ODSTEP, 12);
        printf("%s\n", NAZWA);
        odstepy = (LIMIT - strlen(ADRES)) / 2;
        n_znak(ODSTEP, odstepy);
        printf("%s\n", ADRES);
        n_znak(ODSTEP, (LIMIT - strlen(MIEJSCOWOSC)) / 2);
        printf("%s\n", MIEJSCOWOSC);
        n_znak('*', LIMIT);
        putchar('\n');







        //JCSP();
        //zmienne();
printf("\a");
return 0;
}

void n_znak(char ch, int num){
        int licznik;
        for (licznik = 1; licznik <= num; licznik++)
            putchar(ch);
}

*/






/*
void gwiazdki(void);
const char LIMIT = 40;

 const char NAZWA[] = "MEGATHINK, INC.";
        const char ADRES[] = "10 Megabuck Plaza";
        const char MIEJSCOWOSC[] = "Megapolis, CA 94904";


        gwiazdki();
        printf("%s\n", NAZWA);
        printf("%s\n", ADRES);
        printf("%s\n", MIEJSCOWOSC);
        gwiazdki();



void gwiazdki(void){
        int licznik;
        for (licznik = 1;licznik <= LIMIT; licznik++)
            putchar('*');
        putchar('\n');
*/






/*
char pobierz_wybor (void);
char pobierz_pierwszy(void);
int pobierz_int(void);
void liczenie(void);




int wybor;
            void liczenie(void);

        while(( wybor = pobierz_wybor()) != 'q'){
            switch(wybor){
                case 'a':   printf("kup po nieskiej cenie, sprzedaj po wysokiej.\n");
                            break;
                case 'b':   putchar('\a');
                            break;
                case 'c':   liczenie();
                            break;
                default:    printf("Błąd!\n");
                            break;
            }
        }
        printf("Do widzenia.\n");





char pobierz_wybor (void){
        int ch;

        printf("Wpisz wybraną literę:\n");
        printf("a. porada           b. alarm\n");
        printf("c. liczenie         q. koniec\n");
        ch = pobierz_pierwszy();
        while ((ch < 'a' || ch > 'c') && ch != 'q'){
            printf("Wpisz a, b, c lub q.\n");
            ch = pobierz_pierwszy();
        }
        return ch;
}


char pobierz_pierwszy(void){
        int ch;

        ch = getchar();
        while (getchar() != '\n')
            continue;
        return ch;


}


int pobierz_int(void){
    int we;
        char ch;

        while (scanf(" %d", &we) != 1){
            while((ch = getchar()) != '\n');
            putchar(ch);
            printf(" nie jest liczą całkowitą.\n Proszę podać wartość całkowitą, np 25, -178 czy 13:");
        }
        return we;
}


void liczenie(void){
        int n,i;
        printf("Jak długo liczyć ? Podaj liczę całkowitą:\n");
        n = pobierz_int();
        for (i = 1; i <= n; i++)
            printf("%d\n", i);
        while (getchar() != '\n')
            continue;
}

*/







/*
long pobierz_long(void);
bool zle_granice(long poczatek, long koniec, long dolna, long gorna);
double suma_kwadrat(long a, long b);



        const long MIN = -10000000;
        const long MAX = 10000000;
        long start;
        long stop;
        double wynik;

        printf("Program oblicza sumę kwadratową liczb całkowitych.\n"
               "Dolna granica przedziału nie powinna być "
               "mniejsza od -10 000 000\n"
               "Górna granica przedziału nie powinna być "
               "większa od 10 000 000\n"
               "(podanie 0 dla obu oznacza koniec).\n"
               "Dolna granica: ");
        start = pobierz_long();
        printf("Górna granica: ");
        stop = pobierz_long();
        while (start != 0 || stop != 0){
            if (zle_granice(start, stop, MIN, MAX))
                printf("Spróbuj ponownie.\n");
            else {
                wynik = suma_kwadrat(start, stop);
                printf("Suma kwadratów liczb całkowitych ");
                printf("w przedziale od %ld do %ld wynosi %g\n", start, stop, wynik);
            }
            printf("Podaj granice przedziału "
                   "(podanie 0 dla obu oznacza koniec)\n");
            printf("Dolna granica: ");
            start = pobierz_long();
            printf("Górna granica: ");
            stop = pobierz_long();
        }
        printf("KONIEC\n");




        long pobierz_long(void){
    long we;
    char ch;

    while(scanf(" %ld", &we) != 1){
        while((ch = getchar()) != '\n')
            putchar(ch);
        printf(" nie jest liczbą całkowitą.\n Proszę podać ");
        printf("wartość całkowitą, np. 25, - 178 czy 3: ");
    }
    return we;
}


bool zle_granice(long poczatek, long koniec, long dolna, long gorna){
    bool zle = false;
    if (poczatek > koniec){
        printf("%ld nie jest mniejsze od %ld.\n", poczatek, koniec);
        zle = true;
    }
    if (poczatek < dolna || koniec < dolna){
        printf("Wartości muszą mieć wartość co najmniej: $ld.\n", dolna);
        zle = true;
    }
    if (poczatek > gorna || koniec > gorna){
        printf("Wartości muszą mieć wartość co najwyżej: %;d.\n", gorna);
        zle = true;
    }
    return zle;
}


double suma_kwadrat(long a, long b){
    double suma = 0;
    int i;
    for (i = a; i <= b; i++)
        suma += i * i;
    return suma;
}

*/


















/*

void wyswietl (char c, int wysokosc, int szerokosc);

        char ch;
        int rzedy, kolumny;

        printf("Podaj znak i dwie liczby całkowite:\n");
        while ((ch = getchar()) != '\n' ){
            if (scanf(" %d %d", &rzedy, &kolumny) != 2)
                break;
            wyswietl(ch, rzedy, kolumny);
            printf("Podaj kolejny znak i dwie liczby całkowite,\n");
            printf("Aby zakończyć, za symuluj EOF:\n");
            while ((getchar()) == '`')         // <--- moje udziwnienie
                continue;
        }
        printf("Koniec\n");


void wyswietl (char c, int wysokosc, int szerokosc){
        int rzad, kol;

        for (rzad = 1; rzad <= wysokosc; rzad++){
            for (kol = 1; kol <= szerokosc; kol++)
                putchar(c);
            putchar('\n');
            }
        }

*/






/*
        int proba = 1;

        printf("Wybierz liczbe od 1 do 100. Spróbuję ją odgadnąć.\n");
        printf("Wpisz t, jeśli moja próba jest udana lub n jeśli jest nie udana.");
        printf("Czy Twoja liczba to %d\n", proba);
        while (getchar() != 't'){
            while (getchar() != '\n')
                continue;
            printf("A może: %d\n", ++proba);
        }
        printf("Bingo");
*/




/*
        int ch;
        FILE * fp;
        char nazwaplik[50];

        printf("Podaj nazwe pliku: ");
        scanf(" %s", nazwaplik);
        fp = fopen(nazwaplik, "r");
        if (fp == NULL){
            printf("Błąd przy próbie otwarcia pliku.\n");
            exit(1);
        }
        while (( ch = getc(fp)) != EOF)
            putchar(ch);
        fclose(fp);

        getchar();
        getchar();
*/



/*
        int ch;
        while ((ch = getchar()) != EOF)
            putchar(ch);        // pod windows nie działą
*/


/*
        char ch;

        while ((ch = getchar()) != '#')
            putchar(ch);
*/


/*
        char ch;
        int a_licz, e_licz, i_licz, o_licz, u_licz, y_licz;
        a_licz = e_licz = i_licz = o_licz = u_licz = y_licz = 0;

        printf("Wpisz jakiś tekst; # koniec programu.\n");
        while ((ch = getchar()) != '#'){
            switch (ch){
                case 'a':
                case 'A':   a_licz++;
                            break;
                case 'e':
                case 'E':   e_licz++;
                            break;
                case 'i':
                case 'I':   i_licz++;
                            break;
                case 'o':
                case 'O':   o_licz++;
                            break;
                case 'u':
                case 'U':   u_licz++;
                            break;
                case 'y':
                case 'Y':   y_licz++;
                            break;
                default :   break;
            }
        }
        printf("liczba samogłosek: A     E     I     O     U     Y\n");
        printf("                 %4d %4d %4d %4d %4d %4d\n",a_licz, e_licz, i_licz, o_licz, u_licz, y_licz);
*/





/*
char ch;
        printf("Podaj mi literę, a ja podam CI ");
        printf("nazwę zwierzęcia\nna tą literę.\n");
        printf("Wpisz małą literę; # kończy zabwę.\n");
        while(( ch = getchar()) != '#'){
            if ('\n' == ch)
                continue;
            if (islower(ch))
                switch (ch){
                case 'a':
                    printf("aguti, reoślinożerny gryzoń z Ameryki Łacińskiej\n");
                    break;
                case 'b':
                    printf("babirus, dzika świnia indonezyjska\n");
                    break;
                case 'c':
                    printf("cierlik, nieduży ptak śródziemnomorski\n");
                    break;
                case 'd':
                    printf("desman, wodny ssak podobny do kreta\n");
                    break;
                case 'e':
                    printf("edredon, arktyczny ptak morski z rodziny kaczek\n");
                    break;
                case 'f':
                    printf("fretka, udomowiona odmiana tchórza pospolitego\n");
                    break;
                default :
                    printf("To za trudne!\n");
                }
            else
                printf("Rozpoznaje tylko małe litery.\n");
            while (getchar() != '\n')
                continue;
            printf("Podaj kolejną literę lub znak #.\n");
        }
        printf("Koniec\n");
*/




/*
        float dlugosc, szerokosc;

        printf("Podaj d³ugoœæ prostok¹ta:\n");
        while (scanf(" %f", &dlugosc) == 1){
            printf("D³ugoœæ = %0.2f:\n", dlugosc);
            printf("Podaj szerokoœæ prostok¹ta:\n");
            if (scanf(" %f", &szerokosc) != 1)
                break;
            printf("Szerokoœæ = %0.2f:\n", szerokosc);
            printf("Pole = %0.2f:\n", dlugosc * szerokosc);
            printf("Podaj d³ugoœæ prostok¹ta:\n");
        }
        printf("Koniec.\n");
*/


/*
        const float MIN = 0.0f;
        const float MAX = 100.0f;

        float wynik;
        float suma = 0.0f;
        int n = 0;
        float min = MAX;
        float max = MIN;

        printf("Podaj pierwszy wynik (albo q ¿eby wyjœæ):\n");
        while (scanf(" %f", &wynik) == 1){
            if (wynik < MIN || wynik > MAX){
                printf("%0.1f jest nieprawid³ow¹ wartoœci¹.\n", wynik);
                continue;
            }
            printf("Przyjêto %0.1f:\n", wynik);
            min = (wynik < min) ? wynik: min;
            max = (wynik > max) ? wynik: max;
            suma += wynik;
            n++;
            printf("Podaj kolejny wynik (albo q ¿eby wyjœæ):\n");
        }

        if (n > 0){
            printf("Œrednia z %d wyników wynosi %0.1f.\n", n, suma / n);
            printf("Najni¿szy = %0.1f, najwy¿szy = %0.1f\n", min, max);
        }
        else
            printf("Nie podano ¿adnych prawid³owych wartoœci.\n");
*/




/*
        const char POKRYCIE = 18;
        int m_kw;
        int puszki;
        printf("Podaj liczbê metrów kwadratowych do pomalowania:\n");
        while(scanf(" %d", &m_kw) == 1){
            puszki = m_kw / POKRYCIE;
            puszki += ((m_kw % POKRYCIE == 0) ? 0 : 1);
            printf("Potrzeba %d %s farby.\n", puszki, puszki == 1 ? "puszki" : "puszek");
            printf("Podaj kolejn¹ wartoœæ (q koñczy program):\n");
        }
*/




/*
        const char STOP = '|';
        char c;
        char poprz;
        long ile_znakow =0L;
        int ile_wierszy = 0;
        int ile_slow = 0;
        int ile_np_wierszy = 0;
        bool w_slowie = false;

        printf("WprowadŸ tekst do analizy (znak | przerywa pracê programu):\n");
        poprz = '\n';
        while (( c = getchar()) != STOP){
            ile_znakow++;
            if (c == '\n')
                ile_wierszy++;
            if (!isspace(c) && !w_slowie){
                w_slowie = true;
                ile_slow++;
            }
            if (isspace(c) && w_slowie)
                w_slowie = false;
            poprz = c;
        }

        if (poprz != '\n')
            ile_np_wierszy = 1;
        printf("znaków = %ld, s³ów = %d, wierszy = %d, ", ile_znakow, ile_slow, ile_wierszy);
        printf("niepe³nych wierszy = %d\n", ile_np_wierszy);
*/




/*
        const char KROPKA = '.';
        char ch;
        int licznik = 0;

        while ((ch = getchar()) != KROPKA){
            if (ch != '"' && ch != '\'')
                licznik++;
        }printf("W Zdaniu jest %d znaków niebêd¹cych cudzys³owami lub apostrofami.\n", licznik);
*/




/*
        unsigned long num;
        unsigned long dziel;
        bool pierwsza;
        printf("Podaj dodatni¹ liczbê ca³kowit¹ do analizy; ");
        printf("Wpisz q, aby wyjœæ\n");
        while(scanf(" %ld", &num) == 1){
            for (dziel = 2, pierwsza = true; (dziel * dziel) <= num; dziel++){
                if(num % dziel == 0){
                    if((dziel * dziel) != num)
                        printf("%ld dzieli siê przez %ld i % ld.\n",num, dziel, num / dziel);
                    else
                        printf("%ld dzieli siê przez %ld.\n", num, dziel);
                    pierwsza = false;
                }
            }
            if (pierwsza)
                printf("%ld jest liczb¹ pierwsz¹.\n", num);
            printf("Podaj nastêpn¹ liczbê do analizy; ");
            printf("Wpisz q. aby wyjœæ.\n");
        }
        printf("KONIEC.\n");
*/













/*
#define STAWKA1 0.2401
#define STAWKA2 0.2881
#define STAWKA3 0.3457
#define STAWKA4 0.3877
#define PROG1 360.0
#define PROG2 468.0
#define PROG3 720.0
#define PODSTAWA1 (STAWKA1 * PROG1)
#define PODSTAWA2 (PODSTAWA1 + (STAWKA2 * (PROG2 - PROG1)))
#define PODSTAWA3 (PODSTAWA1 + PODSTAWA2 + (STAWKA3 * (PROG3 - PROG2)))


        double kwh;
        double oplata;

        printf("Podaj liczbê zu¿ytych kWh.\n");
        scanf("%lf", &kwh);
        if (kwh <= PROG1)
            oplata = STAWKA1 * kwh;
        else if (kwh <= PROG2)
            oplata = PODSTAWA1 + (STAWKA2 * (kwh - PROG1));
        else if (kwh <= PROG3)
            oplata = PODSTAWA2 + (STAWKA3 * (kwh - PROG2));
        else
            oplata = PODSTAWA3 + (STAWKA4 * (kwh - PROG3));
        printf("Oplata za %.1f kWh wynosi %1.2f zl.\n", kwh, oplata);
*/



/*
        char ch;
        while((ch = getchar()) != '\n'){
            if (isalpha(ch))
                putchar(ch + 1);
            else
                putchar(ch);
        }
        putchar(ch);
*/


/*

        const char ODSTEP = ' ';

        char ch;
        //ch = getchar();
        while ((ch = getchar())!= '\n'){
            if (ch == ODSTEP)
                putchar(ch);
            else
                putchar(ch + 1);
            //ch = getchar();
        }
        putchar(ch);

*/







/*
        const char ODSTEP = ' ';

        char ch;
        ch = getchar();
        while (ch != '\n'){
            if (ch == ODSTEP)
                putchar(ch);
            else
                putchar(ch + 1);
            ch = getchar();
        }
        putchar(ch);

*/


/*
        const int MROZ = 0;
        float temperatura;
        int mrozne_dni = 0;
        int wszystkie_dni = 0;

        printf("Podaj listê najni¿szych temperatur dnia.\n");
        printf("U¿yj skali Celsjusza. Aby zakoñczyæ, wpisz q.\n");
        while (scanf(" %f", &temperatura)){
            wszystkie_dni++;
            if (temperatura < MROZ)
                mrozne_dni++;
        }
        if (wszystkie_dni != 0)
            printf("Ca³kowita liczba dni: %d, z czego %.1f%% by³o mroŸne.\n", wszystkie_dni, 100.00 * (float) mrozne_dni / wszystkie_dni); else
            printf("Nie wpisano danych!\n");
*/


/*
        const int MROZ = 0;
        float temperatura;
        int mrozne_dni = 0;
        int wszystkie_dni = 0;

        printf("Podaj listê najni¿szych temperatur dnia.\n");
        printf("U¿yj skali Celsjusza. Aby zakoñczyæ, wpisz q.\n");
        while (scanf(" %f", &temperatura) == 1){
            wszystkie_dni++;
            if (temperatura < MROZ)
                mrozne_dni++;
        }
        if (wszystkie_dni != 0)
            printf("Ca³kowita liczba dni: %d, z czego %.1f%% by³o mroŸne.\n", wszystkie_dni, 100.00 * (float) mrozne_dni / wszystkie_dni);
        if (wszystkie_dni == 0)
            printf("Nie wpisano danych!\n");

*/





/*
double potega (double a, int b);


double x, xpot;
        int n;

        printf("Podaj liczbe oraz potenge naturalna,");
        printf(" do której podniesiona\n zostanie liczba. Wpisz q,");
        printf(" aby zakoñczyæ program.\n");
        while (scanf("%lf%d", &x, &n) == 2){
            xpot = potega(x,n);
            printf("%.3g do potêgi %d to %.5g\n", x, n, xpot);
            printf("Podaj kolejn¹ parê liczb lub wpisz q, aby wyjœæ\n");
        }
        printf("Koniec");


double potega (double a, int b){

        double pot = 1;
        int i;

        for(i = 1; i <= b; i++)
            pot *= a;
        return pot;
}
*/


















/*
        const char ROZMIAR = 10;
        const char PAR = 72;

        int index, wynik[ROZMIAR];
        int suma = 0;
        float srednia;

        printf("Podaj %d wynikow gry w golfa:\n", ROZMIAR);
        for (index = 0; index < ROZMIAR; index++)
            scanf(" %d", &wynik[index]);
        printf("Odczytane wyniki to:\n");
        for (index = 0; index < ROZMIAR; index++)
            printf("%5d", wynik[index]);
        printf("\n");
        for(index = 0; index < ROZMIAR; index++)
            suma += wynik[index];
        srednia = (float) suma / ROZMIAR;

        printf("Suma wyników = %d, Œrednia = %.2f\n", suma, srednia);
        printf("Oznacza to handicap w wysokoœci %.0f.\n", srednia - PAR);
*/



/*
        const char RZEDY = 6;
        const char ZNAKI = 10;
        int rzad;
        char ch;

        for (rzad = 0; rzad < RZEDY; rzad++){
            for (ch = ('A' + rzad); ch < ('A' +ZNAKI); ch++){
                printf("%c", ch);
            }
            printf("\n");
        }
*/



/*
        const char RZEDY = 6;
        const char ZNAKI = 10;
        int rzad;
        char ch;

        for (rzad = 0; rzad < RZEDY; rzad++){
            for (ch = 'A'; ch < ('A' +ZNAKI); ch++){
                printf("%c", ch);
            }
            printf("\n");
        }
*/


/*
        const tajny_kod = 13;
        int wprowadzony_kod;
        printf("Aby wejœæ podaj kod:");
        scanf(" %d", &wprowadzony_kod);
        while (wprowadzony_kod != tajny_kod){
            printf("B³êdny kod, podaj prawid³owy:");
            scanf(" %d", &wprowadzony_kod);
        }
        printf("Gratulacje");
*/


/*
        const int tajny_kod = 13;
        int wprowdzony_kod;

        do{
            printf("Aby wejœæ do klubu wprowadŸ w³aœciwy kod:"),
            scanf(" %d", &wprowdzony_kod);
        } while (wprowdzony_kod != tajny_kod);
        printf("Gratulacje !");
*/




/*
        int licznik;
        double czas, potenga_2;
        int granica;

        printf("Ile wyrazów chcesz zsumowaæ?\n");
        scanf(" %d", &granica);

        for (czas = 0, potenga_2 = 1, licznik = 1; licznik <= granica; licznik++, potenga_2 *= 2.0){
            czas += 1.0/potenga_2;
            printf("czas = %f, gdy licznik = %d.\n", czas, licznik);
        }
*/



/*
        int x;
        int z;
        int y;

        x = (y = 3,(z = ++y + 2) + 5);
        printf("x(11) = %d, y(4) = %d, z(6) = %d", x, y, z);
*/



/*
        const float PIERWSZE = 0.70;
        const float NASTEPNE = 0.30;
        const int G = 25;

        int gramy;
        float cena;

        printf(" waga     cena\n");
        for(gramy = G, cena = PIERWSZE; gramy <= 400; gramy += G, cena += NASTEPNE)
            printf("%5d %7.2f\n", gramy, cena);
*/


/*
        int num;

        printf("    n    n do szescianu\n");
        for (num = 1; num <= 6; num++)
            printf("%5d %5d\n", num, num*num*num);
*/



/*
        const int LICZBA = 4;
        int licznik;

        for(licznik = 1; licznik <= LICZBA; licznik++)
            printf("Weso³ych œwiat !\n");
*/


/*
        const int LICZBA = 4;
        int licznik = 1;

        while (licznik <= LICZBA){
            printf("Weso³ych œwi¹t!\n");
            licznik++;
        }
*/



/*
        long num;
        long suma = 0L;
        int stan;

        printf("Podaj liczbê ca³kowit¹ do zsumowania ");
        printf("(albo q, aby zakoñczyæ program):\n");
        stan = scanf("%ld", &num);
        while (stan == 1){
            suma += num;
            printf("Podaj nastêpn¹ liczbê ca³kowit¹ ");
            printf("(albo q aby wyjœæ):");
            stan = scanf("%ld", &num);
        }
        printf("Suma podanych liczb wynosi %ld.\n", suma);
*/


/*
        int n = 3;

        while (n)
            printf("%d to prawda\n", n--);
        printf("%d to fa³sz\n", n);
        n = -3;
        while (n)
            printf("%d to prawda\n", n++);
        printf("%d to fa³sz\n", n);
*/



/*
        int prawda, falsz;

        prawda = (10 > 2);
        falsz = (10 == 2);
        printf("prawda = %d; falsz = %d \n", prawda, falsz);
*/



/*
        const double ODPOWIEDZ = 3.14159;
        double odp;

        printf("Jaka jest wartoœæ liczby PI?\n");
        scanf(" %lf", &odp);
        while (fabs(odp - ODPOWIEDZ) > 0.0001){
            printf("Spróbuj ponownie!\n");
          //  printf("%lf",fabs(odp - ODPOWIEDZ));
            scanf(" %lf", &odp);
        }
        printf("Wystarczaj¹co blisko!\n");
*/


/*
        int n = 0;

        while (n++ < 3)
            printf("n jest równe %d\n", n);
        printf("Na tym koñczymy nasz program.\n");
*/



/*
        int n = 0;

        while (n < 3)       // b³¹d braku klamer !!!!!!
            printf("n jest równe %d\n", n);
            n++;
        printf("Koniec\n");
*/




/*
        int n = 5;
        while (n < 7){
            printf("n = %d\n", n);
            n++;
            printf("Teraz n = %d\n", n);
        }
        printf("Pêtla zakoñczona\n");
*/




/*
        long num;
        long suma = 0L;

        int stan;

        printf("Podaj liczbê ca³kowit¹ do sumowania ");
        printf(" (albo q, aby wyjœæ):\n");
        //stan = scanf(" %ld", &num);
        while (scanf(" %ld", &num) == 1){
            suma = suma + num;
            printf("Podaj nastêpn¹ liczbê ");
            printf(" (albo q, aby wyjœæ):\n");
            //stan = scanf(" %ld", &num);
        }
        printf("Suma podanych liczb wynosi %ld.\n", suma);
*/





/*
        const int S_W_M = 60;
        const int S_W_H = 3600;

        double dyst;
        double predkosc;
        int min, sek;
        int czas;
        double  czas_km;
        int min_km, sek_km;

        printf("Ten program zamienia Twój czas w biegu na dowolny dystans\n");
        printf("na czas przebiegniêcia 1 km oraz œredni¹ prêdkoœæ w km/h\n");
        printf("Wpisz pokonan¹ odleg³oœæ w kilometrach.\n");
        scanf(" %lf", &dyst);
        printf("Wpisz swój czas w minutach i sekundach.\n");
        printf("Zacznij od podania minut.\n");
        scanf(" %d", &min);
        printf("Teraz podaj liczê sekund.\n");
        scanf(" %d", &sek);
        czas = S_W_M * min + sek;
        predkosc = dyst / czas * S_W_H;
        czas_km = (double) czas / dyst;
        min_km = (int) czas_km / S_W_M;
        sek_km = (int) czas_km % S_W_M;
        printf("Przebieg³eœ %1.2f km w czasie %d minut, %d sekund.\n", dyst, min, sek);
        printf("Odpowiada to przebiegniêciu 1 km w czasie %d minut, ", min_km);
        printf("%d sekund. \nTwoja œrednia prêdkoœæ to %1.2f km/h.\n", sek_km, predkosc);
*/







/*

void hash(int n){
    while( n-- >0)
        printf("#");
    printf("\n");
}

// int main(void){


        int razy = 5;
        char ch = '!';
        float f = 6.0;

        hash(razy);
        hash(ch);
        hash(f);
*/










/*
        char ch;
        int i;
        float fl;

        fl = i = ch = 'C';
        printf("ch(C) = %c, i(67) = %d, fl(67.00) = %2.2f\n", ch, i, fl);
        ch = ch + 1;
        i = fl + 2 * ch;
        fl = 2.0 * ch + i;
        printf("ch(D) = %c, i(203) = %d, fl(339) = %2.2f\n",ch, i, fl);
        ch = 1107;
        printf("Teraz ch (%d bo 1107%256)= %c\n", ch, ch % 256);
        ch = 80.89;
        printf("Teraz ch(80 to jest 'P') = %c\n", ch);
*/



/*
        int licznik, suma;

        licznik = 0;
        suma = 0;
        while(licznik++ < 20){
            suma = suma + licznik;
            printf("suma = %d\n", suma);
        }
*/



/*
        int num = 2;
        int odp;

        printf("num(2) = %d, num*num+1(5) = %d\n", num, num * num + 1);
        printf("num(2) = %d\n", num);
        num = 2;
        odp = num / 2 + 5 * (1 + num++);
        printf("odp(16) = %d\n", odp);
        printf("num(3) = %d\n", num);
*/

/*
#define MAX 50

        int licznik = MAX + 1;

        while(--licznik > 0){
            printf("%d butelek piwa na stole, "
                   "%d butelek piwa!\n", licznik, licznik);
            printf("WeŸ jedn¹ i puœæ ja w kr¹g,\n");
            printf("%d butelek piwa!\n\n", licznik - 1);
        }
*/



/*
#define MAX 50

        int licznik = MAX + 1;

        while(--licznik > 0){
            printf("%d butelek piwa na stole, "
                   "%d butelek piwa!\n", licznik, licznik);
            printf("WeŸ jedn¹ i puœæ ja w kr¹g,\n");
            printf("%d butelek piwa!\n\n", licznik - 1);
        }
*/



/*
        int a = 1, b = 1;
        int aplus, plusb;

        aplus = a++;
        plusb = ++b;
        printf("a    aplus    b    plusb  \n");
        printf("%1d  %5d  %5d  %d\n", a, aplus, b, plusb);
*/




/*
        float but = 23.0;
        float stopa;

        while(but++ < 45){
            stopa = 0.666666 * but -1;
            printf("%8.1f %15.2f cm\n", but, stopa);
            //but++;
        }
*/




/*
        int ultra = 0, super = 0;

        while (super < 5){
            super ++;
            ++ ultra;
            printf("super = %d, ultra = %d\n", super, ultra);
        }

//        ultra = 0;
//        printf("%d %d %d %d \n %d %d %d %d", 11 / 5, 11 / -5, -11 / -5, -11 / 5, 11 % 5, 11 % -5, -11 % -5, -11 % 5);

*/


/*
#define SEK_NA_MIN 60


        int sec, min, left;

        printf("Konwertuje sekundy na minuty i sekundy!\n");
        printf("Podaj liczbê sekund (<=0 to koniec):\n");
        scanf(" %d", &sec);
        while(sec > 0){
            min = sec / SEK_NA_MIN;
            left = sec % SEK_NA_MIN;
            printf("%d sekund to %d minut, %d sekund.\n", sec, min, left);
            printf("Podaj liczbê sekund (<=0 to koniec):\n");
            scanf(" %d", &sec);
        }
        printf("Koniec!\n");
*/





/*
        int n = 0;
        size_t intsize;

        intsize = sizeof (int);
        printf("n = %d, n ma %lu bajty; wszystkie liczby ca³kowite maj¹ %lu bajty.\n", n, sizeof n, intsize);
*/






/*
        int rekord, wynik;
        rekord = wynik = -(2 + 5) * 6 + (4 + 3 *(2 + 3));
        printf("rekord ( -23 )= %d, wynik ( -23 )= %d\n", rekord, wynik);
*/



/*
        printf("dzielenie ca³kowie:     5/4 = %d \n", 5/4);
        printf("dzielenie ca³kowie:     6/3 = %d \n", 6/3);
        printf("dzielenie ca³kowie:     7/4 = %d \n", 7/4);
        printf("dzielenie ca³kowie:     7./4. = %f \n", 7./4.);
        printf("dzielenie ca³kowie:     7./4 = %f \n", 7./4);
*/


/*
#define POLA 64

        const double PLON = 2E16;
        double biezace, suma;
        int licznik = 1;

        printf("Pole    dodane ziarna    suma ziaren     ");
        printf("czêœæ rocznej\n\n"); // <--- a jak dan 2x\n to rozjedzie siê format, prod. œwiat bêdzie Ÿle wyœwiatlane
        printf("                                         ");
        printf("produkcji œwiatowej\n");
        suma = biezace = 1.0;
        printf("%3d %15.2e %14.2e %14.2e\n", licznik, biezace, suma, suma/PLON);
        while (licznik < POLA){
            licznik = licznik + 1;
            biezace = 2.0 * biezace;
            suma = suma + biezace;
            printf("%3d %15.2e %14.2e %14.2e\n", licznik, biezace, suma, suma/PLON);
        }
*/



/*
        int num = 1;

        while (num < 21){
            printf("%4d %6d\n", num, num * num);
            num = num + 1;
        }
*/


/*
        int jane, tarzan, gepard;

        gepard = tarzan = jane = 68;
        printf("                      gepard   tarzan    jane\n");
        printf("Wynik pierwszej rundy %4d %8d %8d\n", gepard, tarzan, jane);
*/


/*
#define KOREKTA -1

        const double MNOZNIK = 0.666666;
        double but, stopa;

        printf("Rozmiar buta    D³ugoœæ stopy\n");
        but = 24.0;
        while (but < 45){
                stopa = MNOZNIK * but + KOREKTA;
                printf("%8.1f %15.2f cm\n", but, stopa);
                but = but + 1.0;
        }
        printf("Koniec");
*/




/*
#define KOREKTA -1

        const double MNOZNIK = 0.666666;
        double but, stopa;

        but = 42.0;
        stopa = MNOZNIK * but + KOREKTA;
        printf("Rozmiar buta    D³ugoœæ stopy\n");
        printf("%8.1f %15.2f cm\n", but, stopa);

*/
}

