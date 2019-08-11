/* drzewo.c -- funkcje do obslugi drzewa */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "drzewo.h"
/* lokalny typ danych */
typedef struct para {
    Wezel * rodzic;
    Wezel * dziecko;
} Para;
/* prototypy funkcji lokalnych */
static Wezel * UtworzWezel(const Pozycja * wp);
static bool NaLewo(const Pozycja * p1, const Pozycja * p2);
static bool NaPrawo(const Pozycja * p1, const Pozycja * p2);
static void DodajWezel(Wezel * nowy, Wezel * korzen);
static void PoKolei(const Wezel * korzen, void (* wfun)(Pozycja pozycja));
static Para SzukajPozycji(const Pozycja * wp, const Drzewo * wdrzewo);
static void UsunWezel(Wezel **wsk);
static void UsunWszystkieWezly(Wezel* wsk);
/* definicje funkcji */
void InicjujDrzewo(Drzewo * wdrzewo)
{
    wdrzewo->korzen = NULL;
    wdrzewo->rozmiar = 0;
}
bool PusteDrzewo(const Drzewo * wdrzewo)
{
    if (wdrzewo->korzen == NULL)
        return true;
    else
        return false;
}
bool PelneDrzewo(const Drzewo * wdrzewo)
{
    if (wdrzewo->rozmiar == MAXPOZ)
        return true;
    else
        return false;
}
int LiczbaPozycji(const Drzewo * wdrzewo)
{
    return wdrzewo->rozmiar;
}
bool DodajPozycje(const Pozycja * wp, Drzewo * wdrzewo)
{
    Wezel * nowy;
    if (PelneDrzewo(wdrzewo))
    {
        fprintf(stderr,"Drzewo jest pelne\n");
        return false;             /* wczesny powrot              */
    }
    if (SzukajPozycji(wp, wdrzewo).dziecko != NULL)
    {
        fprintf(stderr, "Proba dodania istniejacej pozycji\n");
        return false;             /* wczesny powrot              */
    }
    nowy = UtworzWezel(wp);       /* nowy wskazuje na nowy wezel */
    if (nowy == NULL)
    {
        fprintf(stderr, "Nie mozna utworzyc wezla\n");
        return false;             /* wczesny powrot              */
    }
    /* utworzenie nowego wezla sie powiodlo */
    wdrzewo->rozmiar++;
    if (wdrzewo->korzen == NULL)  /* przypadek 1: drzewo jest puste     */
        wdrzewo->korzen = nowy;   /* nowy wezel jest korzeniem drzewa   */
    else                          /* przypadek 2: drzewo nie jest puste */
      DodajWezel(nowy,wdrzewo->korzen); /* dodaje nowy wezel do drzewa  */ 
    return true;             /* udalo sie dodac pozycje */
}
bool WDrzewie(const Pozycja * wp, const Drzewo * wdrzewo)
{
    return (SzukajPozycji(wp, wdrzewo).dziecko == NULL) ? false : true;
}
bool UsunPozycje(const Pozycja * wp, Drzewo * wdrzewo)
{
    Para szuk;
    szuk = SzukajPozycji(wp, wdrzewo);
    if (szuk.dziecko == NULL)
        return false;
    if (szuk.rodzic == NULL)      /* usuwa pozycje w korzeniu */
        UsunWezel(&wdrzewo->korzen);
    else if (szuk.rodzic->lewy == szuk.dziecko)
        UsunWezel(&szuk.rodzic->lewy);
    else
        UsunWezel(&szuk.rodzic->prawy);
    wdrzewo->rozmiar--;
    return true;
}
void Przejdz (const Drzewo * wdrzewo, void (* wfun)(Pozycja pozycja))
{
    if (wdrzewo != NULL)
        PoKolei(wdrzewo->korzen, wfun);
}
void UsunWszystko(Drzewo * wdrzewo)
{
    if (wdrzewo != NULL)
        UsunWszystkieWezly(wdrzewo->korzen);
    wdrzewo->korzen = NULL;
    wdrzewo->rozmiar = 0;
}
/* funkcje lokalne */
static void PoKolei(const Wezel * korzen, void (* wfun)(Pozycja pozycja))
{
    if (korzen != NULL)
    {
        PoKolei(korzen->lewy, wfun);
        (*wfun)(korzen->pozycja);
        PoKolei(korzen->prawy, wfun);
    }
}
static void UsunWszystkieWezly(Wezel * wsk)
{
    Wezel * wprawy;
    if (wsk != NULL)
    {
        wprawy = wsk->prawy;
        UsunWszystkieWezly(wsk->lewy);
        free(wsk);
        UsunWszystkieWezly(wprawy);
    }
}
static void DodajWezel (Wezel * nowy, Wezel * korzen)
{
    if (NaLewo(&nowy->pozycja, &korzen->pozycja))
    {
        if (korzen->lewy == NULL)       /* puste poddrzewo          */
            korzen->lewy = nowy;        /* wiec wstawiamy tu wezel  */
        else
            DodajWezel(nowy, korzen->lewy); /* w przeciwnym wypadku */
    }                                       /* szukamy szczescia w 
                                               poddrzewie */
    else if (NaPrawo(&nowy->pozycja, &korzen->pozycja))
    {
        if (korzen->prawy == NULL)
            korzen->prawy = nowy;
        else
            DodajWezel(nowy, korzen->prawy);
    }
    else                  /* nie powinno byc dwoch identycznych pozycji */
    {
        fprintf(stderr,"Blad funkcji DodajWezel()\n");
        exit(1);
    }
}
static bool NaLewo(const Pozycja * p1, const Pozycja * p2)
{
    int porown1;
    if ((porown1 = strcmp(p1->imie, p2->imie)) < 0)
        return true;
    else if (porown1 == 0 &&
                strcmp(p1->gatunek, p2->gatunek) < 0 )
        return true;
    else
        return false;
}
static bool NaPrawo(const Pozycja * p1, const Pozycja * p2)
{
    int porown1;
    if ((porown1 = strcmp(p1->imie, p2->imie)) > 0)
        return true;
    else if (porown1 == 0 &&
                strcmp(p1->gatunek, p2->gatunek) > 0 )
        return true;
    else
        return false;
}
static Wezel * UtworzWezel(const Pozycja * wp)
{
    Wezel * nowy;
    nowy = (Wezel *) malloc(sizeof(Wezel));
    if (nowy != NULL)
    {
        nowy->pozycja = *wp;
        nowy->lewy = NULL;
        nowy->prawy = NULL;
    }
    return nowy;
}
static Para SzukajPozycji(const Pozycja * wp, const Drzewo * wdrzewo)
{
    Para szuk;
    szuk.rodzic = NULL;
    szuk.dziecko = wdrzewo->korzen;
    if (szuk.dziecko == NULL)
        return szuk;                /* wczesny powrot   */
    while (szuk.dziecko != NULL)
    {
        if (NaLewo(wp, &(szuk.dziecko->pozycja)))
        {
            szuk.rodzic = szuk.dziecko;
            szuk.dziecko = szuk.dziecko->lewy;
        }
        else if (NaPrawo(wp, &(szuk.dziecko->pozycja)))
        {
            szuk.rodzic = szuk.dziecko;
            szuk.dziecko = szuk.dziecko->prawy;
        }
        else     /* jesli szukana pozycja nie znajduje sie ani po lewej,*/
            break;    /* ani po prawej stronie pozycji szuk.dziecko->
                         pozycja,   */ 
    }                 /* pozycje sa identyczne; szuk.dziecko jest adresem 
                         wezla */
    return szuk;      /* przechowujacego szukana pozycje                */
}
static void UsunWezel(Wezel **wsk)
/* wsk jest adresem skladnika rodzica, ktory wskazuje na usuwany wezel */
{
    Wezel * tymcz;
    if ( (*wsk)->lewy == NULL)
    {
        tymcz = *wsk;
        *wsk = (*wsk)->prawy;
        free(tymcz);
    }
    else if ( (*wsk)->prawy == NULL)
    {
        tymcz = *wsk;
        *wsk = (*wsk)->lewy;
        free(tymcz);
    }
    else    /* usuwany wezel ma dwoje dzieci */
    {
        /* szukamy miejsca dolaczenia prawego poddrzewa */
        for (tymcz = (*wsk)->lewy; tymcz->prawy != NULL;
                tymcz = tymcz->prawy)
            continue;
        tymcz->prawy = (*wsk)->prawy;
        tymcz = *wsk;
        *wsk =(*wsk)->lewy;
        free(tymcz);
    }
}

