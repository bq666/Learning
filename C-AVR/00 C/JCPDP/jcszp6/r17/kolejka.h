/* kolejka.h -- interfejs dla kolejki */
#ifndef _KOLEJKA_H_
#define _KOLEJKA_H_
#include <stdbool.h>
/* TUTAJ WSTAW DEFINICJE TYPU POZYCJA */
/* NA PRZYKLAD, */
typedef int Pozycja; // na potrzeby programu uzyj_k.c
/* LUB typedef struct pozycja {int slon; int zyrafa;} Pozycja; */
#define MAXKOLEJKA 10
typedef struct wezel
{
   Pozycja pozycja;
   struct wezel * nast;
} Wezel;
typedef struct kolejka
{
   Wezel * przod;   /* wskaznik do przodu kolejki */
   Wezel * tyl;     /* wskaznik do tylu kolejki   */
   int pozycje;     /* liczba pozycji w kolejce   */
} Kolejka;
/* dzialanie:        inicjalizuje kolejke                          */
/* warunek wstepny:  wk wskazuje na kolejke                        */
/* warunek koncowy:  kolejka zostaja zainicjalizowana jako pusta   */
void InicjujKolejke(Kolejka * wk);
/* dzialanie:        sprawdza, czy kolejka jest pelna              */
/* warunek wstepny:  wk wskazuje na wczesniej zainicjowana kolejke */
/* warunek koncowy:  zwraca true, jesli kolejka jest pelna,        */
/*                   w przeciwnym wypadku - false                  */
bool PelnaKolejka(const Kolejka * wk);
/* dzialanie:        sprawdza, czy kolejka jest pusta              */
/* warunek wstepny:  wk wskazuje na wczesniej zainicjowana kolejke */
/* warunek koncowy:  zwraca true, jesli kolejka jest pusta,        */
/*                   w przeciwnym wypadku - false                  */
bool PustaKolejka(const Kolejka *wk);
/* dzialanie:        okresla liczbe pozycji w kolejce              */
/* warunek wstepny:  wk wskazuje na wczesniej zainicjowana kolejke */
/* warunek koncowy:  zwraca liczbe pozycji w kolejce               */
int LiczbaPozycji(const Kolejka * wk);
/* dzialanie:        ustawia pozycje z tylu kolejki                */
/* warunek wstepny:  wk wskazuje na wczesniej zainicjowana kolejke */
/* warunek koncowy:  jesli kolejka nie jest pusta, pozycja zostaje */
/*                   umieszczona z tylu kolejki a funkcja zwraca   */
/*                   true; w przeciwnym wypadku, kolejka  pozostaje */
/*                   niezmieniona, a funkcja zwraca false          */
bool Ustaw(Pozycja pozycja, Kolejka * wk);
/* dzialanie:        odlacza pozycje z przodu kolejki a            */
/* warunek wstepny:  wk wskazuje na wczesniej zainicjowana kolejke */
/* warunek koncowy:  jesli kolejka nie jest pusta, pozycja z       */
/*                   przodu kolejki zostaje skopiowana do          */
/*                   *wpozycja i usunieta z kolejki, a funkcja     */
/*                   zwraca true. Jesli usunieto ostatnia pozycje, */
/*                   kolejka jest zerowana (inicjowana). Jesli     */
/*                   kolejka byla pusta juz wczesniej, pozostaje   */
/*                   ona bez zmian, a funkcja zwraca false.        */
bool Odlacz(Pozycja *wpozycja, Kolejka * wk);
/* dzialanie:        oproznia kolejke                              */
/* warunek wstepny:  wk wskazuje na wczesniej zainicjowana kolejke */
/* warunek koncowy:  kolejka jest pusta                            */
void WyczyscKolejke(Kolejka * wk);
#endif

