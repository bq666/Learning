/* fun_wsk.c -- wykorzystuje wskazniki do funkcji */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define DLUGOSC 81
char *wczytaj(char *z, int ile);
char pokazmenu(void);
void usunwiersz(void);  // usuwa dane do konca wiersza              
void pokaz(void (* fp)(char *), char * str);
void DuzeLit(char *);   // przetwarza male litery na duze               
void MaleLit(char *);   // przetwarza duze litery na male           
void Odwroc(char *);    // zamienia duze litery na male i odwrotnie 
void Atrapa(char *);    // pozostawia lancuch bez zmian             
int main(void)
{
    char wiersz[DLUGOSC]; 
    char kopia[DLUGOSC]; 
    char wybor;
    void (*wfun)(char *); // wskazuje na funkcje przyjmujaca 
                          // argument typu char *            
                          // i nie zwracajaca wartosci       
    puts("Podaj lancuch (pusty wiersz konczy program):");
    while (wczytaj(wiersz, DLUGOSC) != NULL && wiersz[0] != '\0')
    {
        while ((wybor = pokazmenu()) != 'n')
        {
            switch (wybor   )      // switch decyduje o wskazniku   
            {
                case 'd' : wfun = DuzeLit; break;
                case 'm' : wfun = MaleLit; break;
                case 'o' : wfun = Odwroc;  break;
                case 'b' : wfun = Atrapa;  break;
            }
            strcpy(kopia, wiersz); // tworzy kopie dla funkcji pokaz()  
            pokaz(wfun, kopia);    // korzysta z wybranej funkcji      
        }
        puts("Podaj lancuch (pusty wiersz konczy program):");
    }
    puts("Czesc!");
    return 0;
}
char pokazmenu(void)
{
    char odp;
    puts("Wybierz jedna opcje:");
    puts("d) duze litery        m) male litery");
    puts("o) odwrocenie liter   b) bez zmian");
    puts("n) nastepny lancuch");
    odp = getchar();    // pobiera odpowiedz
    odp = tolower(odp); // przetwarza odp. na mala litere
    usunwiersz();       // pozbywa sie reszty wiersza
    while (strchr("dmobn", odp) == NULL)
    {
        puts("Wpisz d, m, o, b lub n:");
        odp = tolower(getchar());
        usunwiersz();
    }
    return odp;
}
void usunwiersz(void)
{
    while (getchar() != '\n')
        continue;
}
void DuzeLit(char * lan)
{
    while (*lan != '\0')
    {
        *lan = toupper(*lan);
        lan++;
    }
}
void MaleLit(char * lan)
{
    while (*lan != '\0')
    {
        *lan = tolower(*lan);
        lan++;
    }
}
void Odwroc(char * lan)
{
    while (*lan != '\0')
    {
        if (islower(*lan))
            *lan = toupper(*lan);
        else if (isupper(*lan))
            *lan = tolower(*lan);
        lan++;
    }
}
void Atrapa(char * lan)
{
    // pozostawia lancuch bez zmian
}
void pokaz(void (* fw)(char *), char * lan)
{
    (*fw)(lan); // stosuje wybrana funkcje do lan
    puts(lan);  // wyswietla wynik
}
char *wczytaj(char *z, int ile)
{
    char * wynik;
    char * tutaj;
    wynik = fgets(z, ile, stdin);
    if (wynik)
    {
        tutaj = strchr(z, '\n'); // szukamy nowego wiersza
        if (tutaj) // jesli adres jest rozny od NULL
            *tutaj = '\0'; // zamieniamy znak nowego wiersza na pusty
        else
            while (getchar() != '\n')
                continue;  // porzucenie reszty wiersza
    }
    return wynik;
}

