#ifndef _MENU_H
#define _MENU_H

#include <stdbool.h>
#include <stdint.h>

typedef void (*menuitemfuncptr)();

struct _menuitem
{
	const __flash char * const  text;            //Nazwa pozycji menu
	menuitemfuncptr menuitemfunc;                //Funkcja callback zwi�zana z pozycj� menu
	const __flash struct _menuitem *parent;      //Obiekt - rodzic
	const __flash struct _menuitem *submenu;     //Podmenu, lub NULL je�li nie ma
	const __flash struct _menuitem *next;        //Kolejna pozycja lub NULL je�li nie ma
};

void Menu_Show();
void Menu_SelectNext();
void Menu_SelectPrev();
void Menu_Click();
void Menu_Back();

extern struct _menuitem const __flash menu;                 //Struktura menu

#endif
