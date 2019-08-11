/*
 * ST7565.c
 *
 * Created: 2013-08-12 13:13:11
 *  Author: tmf
 */

#include <util/delay.h>
#include <avr/io.h>
#include <stdbool.h>
#include "ST7565.h"
#include "../SPI/SPI.h"
#include "../defines.h"

enum st7565r {ST_Low=0, ST_High=1};

uint8_t LCD_FrameBuffer[GFX_SCREEN_HEIGHT / 8][GFX_SCREEN_WIDTH];  //Bufor obrazu
uint8_t GLCD_x, GLCD_y;

static inline void st7565r_Reset_pin(enum st7565r state)
{
	if(state == ST_High) SET(PORT, ST7565_RESET); else CLR(PORT, ST7565_RESET); //PORTA_OUTSET=PIN3_bm; else PORTA_OUTCLR=PIN3_bm;
}

static inline void st7565r_A0_pin(enum st7565r state)
{
	if(state == ST_High) SET(PORT, ST7565_A0); else CLR(PORT, ST7565_A0); //PORTD_OUTSET=PIN0_bm; else PORTD_OUTCLR=PIN0_bm;
}

static inline void st7565r_CS_pin(enum st7565r state)
{
	if(state == ST_High) SET(PORT, ST7565_CS); else CLR(PORT, ST7565_CS); //PORTF_OUTSET=PIN3_bm; else PORTF_OUTCLR=PIN3_bm;
}

void st7565r_reset()
{
	st7565r_Reset_pin(ST_Low);
	_delay_us(10);
	st7565r_Reset_pin(ST_High);
	_delay_us(10);
}

static inline void st7565r_wr_cmd(uint8_t cmd)
{
	st7565r_CS_pin(ST_Low);   //Wybierz uk³ad
	st7565r_A0_pin(ST_Low);   //Wybierz tryb przesy³ania polecenia
	SPI_RW_Byte(cmd);		  //Wyœlij polecenie
	st7565r_CS_pin(ST_High);
}

static void st7565r_wr_data(uint8_t data)
{
	st7565r_CS_pin(ST_Low);   //Wybierz uk³ad
	st7565r_A0_pin(ST_High);  //Wybierz tryb przesy³ania danych
	SPI_RW_Byte(data);
	st7565r_A0_pin(ST_Low);
	st7565r_CS_pin(ST_High);
}

static inline void st7565r_set_page_address(uint8_t address)
{
	address&=0x0F; //Zadres to tylko 4 bity
	st7565r_wr_cmd(ST7565R_CMD_PAGE_ADDRESS_SET | address);
}

static inline void st7565r_set_column_address(uint8_t address)
{
	address &= 0x7F;   //Adres to 7 najm³odszych bitów
	st7565r_wr_cmd(ST7565R_CMD_COLUMN_ADDRESS_SET_MSB | (address >> 4));
	st7565r_wr_cmd(ST7565R_CMD_COLUMN_ADDRESS_SET_LSB | (address & 0x0F));
}

void st7565r_write_data_at(uint8_t x, uint8_t y, uint8_t data)
{
	st7565r_set_page_address(y);
	st7565r_set_column_address(x);
	st7565r_wr_data(data);
}

void st7565r_set_display_start_line_address(uint8_t address)
{
	address &= 0x3F;
	st7565r_wr_cmd(ST7565R_CMD_START_LINE_SET | address);
}

static inline void st7565r_display_on(_Bool onoff)
{
	if(onoff) st7565r_wr_cmd(ST7565R_CMD_DISPLAY_ON);
	 else st7565r_wr_cmd(ST7565R_CMD_DISPLAY_OFF);
}

void st7565r_LCD_test(_Bool onoff)
{
	if (onoff) st7565r_wr_cmd(ST7565R_CMD_DISPLAY_ALL_POINTS_ON);
	 else st7565r_wr_cmd(ST7565R_CMD_DISPLAY_ALL_POINTS_OFF);
}

void st7565r_LCD_Invert(_Bool onoff)
{
	if (onoff) st7565r_wr_cmd(ST7565R_CMD_DISPLAY_REVERSE);
	else st7565r_wr_cmd(ST7565R_CMD_DISPLAY_NORMAL);
}

void st7565r_LCD_Reverse_Y(_Bool onoff)
{
	if (onoff) st7565r_wr_cmd(ST7565R_CMD_REVERSE_SCAN_DIRECTION);
	else st7565r_wr_cmd(ST7565R_CMD_NORMAL_SCAN_DIRECTION);
}

void st7565r_LCD_Reverse_X(_Bool onoff)
{
	if (onoff) st7565r_wr_cmd(ST7565R_CMD_ADC_REVERSE);
	else st7565r_wr_cmd(ST7565R_CMD_ADC_NORMAL);
}

void st7565r_set_contrast(uint8_t contrast) //Uwaga - Ÿle dobrany kontrast (przekroczenie napiêcia) mo¿e uszkodziæ LCD
{
	if (contrast < ST7565R_DISPLAY_CONTRAST_MIN)  contrast=ST7565R_DISPLAY_CONTRAST_MIN;
	if (contrast > ST7565R_DISPLAY_CONTRAST_MAX)  contrast=ST7565R_DISPLAY_CONTRAST_MAX;
	st7565r_wr_cmd(ST7565R_CMD_ELECTRONIC_VOLUME_MODE_SET);
	st7565r_wr_cmd(contrast);
}

void st7565r_init()
{
	st7565r_reset();
	st7565r_wr_cmd(ST7565R_CMD_ADC_NORMAL);              //Zwiêkszaj adres kolumny
	st7565r_wr_cmd(ST7565R_CMD_DISPLAY_NORMAL);          //W³¹cz normalny tryb wyœwietlania (nie testowy)
	st7565r_wr_cmd(ST7565R_CMD_REVERSE_SCAN_DIRECTION);  //Tryb sterowania elektrodami
	st7565r_wr_cmd(ST7565R_CMD_LCD_BIAS_1_DIV_6_DUTY33); //Ustaw bias voltage na 1/6
	st7565r_wr_cmd(ST7565R_CMD_POWER_CTRL_ALL_ON);       //W³¹cz wszystkie elementy sterownika
	st7565r_wr_cmd(ST7565R_CMD_BOOSTER_RATIO_SET);       //Konfiguracja boostera
	st7565r_wr_cmd(ST7565R_CMD_BOOSTER_RATIO_2X_3X_4X);
	st7565r_wr_cmd(ST7565R_CMD_VOLTAGE_RESISTOR_RATIO_7);
	st7565r_set_contrast(0x10);
	st7565r_set_display_start_line_address(0);            //Rozpocznij wyœwietlanie od linii nr 0
	st7565r_display_on(true);
}

void st7565r_SetPixel(uint8_t x, uint8_t y, _Bool isSet)
{
	GLCD_x=x; GLCD_y=y;
	if(isSet) LCD_FrameBuffer[y >> 3][x] |= (1 << (y%8));
	     else LCD_FrameBuffer[y >> 3][x] &= ~(1 << (y%8));
	st7565r_write_data_at(x, y >> 3, LCD_FrameBuffer[y >> 3][x]);
}

void st7565r_CpyFramebuffer()
{
	uint8_t *ptr=(uint8_t*)LCD_FrameBuffer;
	for(uint8_t y=0; y < (GFX_SCREEN_HEIGHT >> 3); y++)
	{
		st7565r_set_page_address(y);
		st7565r_set_column_address(0);
		for(uint8_t x=0; x < GFX_SCREEN_WIDTH; x++) st7565r_wr_data(*ptr++);
	}
}

void st7565r_Clear(_Bool color)
{
	uint8_t pix=0;
	if(color) pix=0xff;
	uint8_t *ptr=(uint8_t*)LCD_FrameBuffer;
	for(uint16_t i=0; i < GFX_SCREEN_WIDTH * (GFX_SCREEN_HEIGHT >> 3); i++) *ptr++=pix;
	st7565r_CpyFramebuffer();
}

void st7565r_LineTo(uint8_t x, uint8_t y, _Bool isSet)
{
    int dy = y - GLCD_y;
    int dx = x - GLCD_x;
    int8_t stepx, stepy;

    if (dy < 0) { dy = -dy;  stepy = -1; } else stepy = 1;
    if (dx < 0) { dx = -dx;  stepx = -1; } else stepx = 1;
    dy <<= 1;
    dx <<= 1;

    st7565r_SetPixel(GLCD_x, GLCD_y, isSet);
    if (dx > dy)
    {
        int fraction = dy - (dx >> 1);  // same as 2*dy - dx
        while (GLCD_x != x)
        {
           if (fraction >= 0)
           {
               GLCD_y += stepy;
               fraction -= dx;          // same as fraction -= 2*dx
           }
           GLCD_x += stepx;
           fraction += dy;              // same as fraction -= 2*dy
           st7565r_SetPixel(GLCD_x, GLCD_y, isSet);
        }
     } else {
        int fraction = dx - (dy >> 1);
        while (GLCD_y != y) {
           if (fraction >= 0) {
               GLCD_x += stepx;
               fraction -= dy;
           }
           GLCD_y += stepy;
           fraction += dx;
           st7565r_SetPixel(GLCD_x, GLCD_y, isSet);
        }
     }
 }

void st7565r_MoveTo(uint8_t x, uint8_t y)
{
	GLCD_x=x; GLCD_y=y;
}

void st7565r_DrawHLine(uint8_t x, _Bool isSet)
{
	x+=GLCD_x;
    for(uint8_t x1=GLCD_x; x1<x; x1++) st7565r_SetPixel(x1, GLCD_y, isSet);
}

void st7565r_Circle(uint8_t cx, uint8_t cy , uint8_t radius, uint8_t attrs)
{
    int8_t x, y, xchange, ychange, radiusError;
    x=radius;
    y=0;
    xchange=1-2*radius;
    ychange=1;
    radiusError=0;
	_Bool isSet=attrs & 1;

    while(x>=y)
    {
        if((attrs & 2)==0)
        {
            st7565r_SetPixel(cx+x, cy+y, isSet);
            st7565r_SetPixel(cx-x, cy+y, isSet);
            st7565r_SetPixel(cx-x, cy-y, isSet);
            st7565r_SetPixel(cx+x, cy-y, isSet);
            st7565r_SetPixel(cx+y, cy+x, isSet);
            st7565r_SetPixel(cx-y, cy+x, isSet);
            st7565r_SetPixel(cx-y, cy-x, isSet);
            st7565r_SetPixel(cx+y, cy-x, isSet);
        } else
        {
            st7565r_MoveTo(cx-x, cy+y); st7565r_DrawHLine(2*x, isSet);
            st7565r_MoveTo(cx-x, cy-y); st7565r_DrawHLine(2*x, isSet);
            st7565r_MoveTo(cx-y, cy+x); st7565r_DrawHLine(2*y, isSet);
            st7565r_MoveTo(cx-y, cy-x); st7565r_DrawHLine(2*y, isSet);
        }

        y++;
        radiusError+=ychange;
        ychange+=2;
        if(2*radiusError+xchange>0)
        {
            x--;
            radiusError+=xchange;
            xchange+=2;
        }
    }
}
