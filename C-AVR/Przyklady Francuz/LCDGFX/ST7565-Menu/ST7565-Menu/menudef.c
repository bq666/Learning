/*
 * menudef.c
 *
 * Created: 2013-08-20 13:05:36
 *  Author: tmf
 */

#include "menu.h"
#include <util/delay.h>
#include "ST7565.h"
#include <avr\pgmspace.h>

//Prototypy funkcji obs³ugi wybranej pozycji menu
void menufunc1();
void menufunc2();
void menufunc3();
void menufunc4();
void menufunc5();
void menufunc6();
void menufunc7();

#define PGM_STR(X) ((const __flash char[]) { X })

struct _menuitem const __flash menu;
struct _menuitem const __flash menuA1;
struct _menuitem const __flash menuB1;

struct _menuitem const __flash menuB3 = {PGM_STR("<z powrotem>"), Menu_Back, &menuB1, 0, 0};
struct _menuitem const __flash menuB2 = {PGM_STR("Podmenu B2"), menufunc7, &menuB1, 0, &menuB3};
struct _menuitem const __flash menuB1 = {PGM_STR("Podmenu B1"), menufunc6, &menuA1, 0, &menuB2};

struct _menuitem const __flash menuA4 = {PGM_STR("<z powrotem>"), Menu_Back, &menuA1, 0, 0};
struct _menuitem const __flash menuA3 = {PGM_STR("Podmenu A3"), menufunc5, &menuA1, 0, &menuA4};
struct _menuitem const __flash menuA2 = {PGM_STR("Podmenu A2"), 0, &menuA1, &menuB1, &menuA3};
struct _menuitem const __flash menuA1 = {PGM_STR("Podmenu A1"), menufunc4, &menu, 0, &menuA2};

struct _menuitem const __flash menu4 = {PGM_STR("Menu5"), 0, &menu, 0, 0};
struct _menuitem const __flash menu3 = {PGM_STR("Menu4"), menufunc3, &menu, 0, &menu4};
struct _menuitem const __flash menu2 = {PGM_STR("Menu3"), menufunc2, &menu, 0, &menu3};
struct _menuitem const __flash menu1 = {PGM_STR("Menu2"), 0, &menu, &menuA1, &menu2};

const __flash struct _menuitem const __flash menu = {PGM_STR("Menu1"), menufunc1, 0, 0, &menu1};

extern const __flash uint8_t* const __flash system16_array[];
extern const __flash uint8_t* const __flash system12_array[];
extern const __flash uint8_t* const __flash system8_array[];

const __flash uint8_t* const __flash *Menu_font = system8_array;            //Czcionka u¿ywana do wyœwietlenia menu
//const __flash uint8_t* const __flash *Menu_font = system12_array;            //Czcionka u¿ywana do wyœwietlenia menu


void menufunc1()
{
	st7565r_Clear(false); //Wyczyœæ LCD
	st7565r_SetText(0, 0, PSTR("Menu 1!"), system8_array, false);
	st7565r_CpyDirtyPages();
	_delay_ms(2000);
}

void menufunc2()
{
	st7565r_Clear(false); //Wyczyœæ LCD
	st7565r_SetText(0, 0, PSTR("Menu 3!"), system8_array, false);
	st7565r_CpyDirtyPages();
	_delay_ms(2000);
}

void menufunc3()
{
	st7565r_Clear(false); //Wyczyœæ LCD
	st7565r_SetText(0, 0, PSTR("Menu 4!"), system8_array, false);
	st7565r_CpyDirtyPages();
	_delay_ms(2000);
}

void menufunc4()
{
	st7565r_Clear(false); //Wyczyœæ LCD
	st7565r_SetText(0, 0, PSTR("Podmenu A1!"), system8_array, false);
	st7565r_CpyDirtyPages();
	_delay_ms(2000);
}

void menufunc5()
{
	st7565r_Clear(false); //Wyczyœæ LCD
	st7565r_SetText(0, 0, PSTR("Podmenu A3!"), system8_array, false);
	st7565r_CpyDirtyPages();
	_delay_ms(2000);
}

void menufunc6()
{
	st7565r_Clear(false); //Wyczyœæ LCD
	st7565r_SetText(0, 0, PSTR("Podmenu B1!"), system8_array, false);
	st7565r_CpyDirtyPages();
	_delay_ms(2000);
}

void menufunc7()
{
	st7565r_Clear(false); //Wyczyœæ LCD
	st7565r_SetText(0, 0, PSTR("Podmenu B2!"), system8_array, false);
	st7565r_CpyDirtyPages();
	_delay_ms(2000);
}

