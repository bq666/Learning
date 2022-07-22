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
#include "SPI.h"
#include "../defines.h"

enum st7565r {ST_Low=0, ST_High=1, BufferDirty, BufferClean};

uint8_t LCD_FrameBuffer[GFX_SCREEN_HEIGHT / 8][GFX_SCREEN_WIDTH + 1];  //Bufor obrazu, ostatni bajt wiersza wskazuje na koniecznoœæ przerysowania strony
uint8_t GLCD_x, GLCD_y;

static inline void st7565r_Reset_pin(enum st7565r state)
{
	if(state == ST_High) SET(PORT, ST7565_RESET); else CLR(PORT, ST7565_RESET);
}

static inline void st7565r_A0_pin(enum st7565r state)
{
	if(state == ST_High) SET(PORT, ST7565_A0); else CLR(PORT, ST7565_A0);
}

static inline void st7565r_CS_pin(enum st7565r state)
{
	if(state == ST_High) SET(PORT, ST7565_CS); else CLR(PORT, ST7565_CS);
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

void st7565r_wr_data(uint8_t data)
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
	LCD_FrameBuffer[y >> 3][GFX_SCREEN_WIDTH]=BufferDirty;
}

void st7565r_CpyFramebuffer()
{
	uint8_t *ptr=(uint8_t*)LCD_FrameBuffer;
	for(uint8_t y=0; y < (GFX_SCREEN_HEIGHT >> 3); y++)
	{
		st7565r_set_page_address(y);
		st7565r_set_column_address(0);
		for(uint8_t x=0; x < GFX_SCREEN_WIDTH; x++) st7565r_wr_data(*ptr++);
		ptr++; //Synchronizacja ze wzglêdu na bajt Dirty w buforze
	}
}

void st7565r_CpyDirtyPages()
{
	uint8_t *ptr=(uint8_t*)LCD_FrameBuffer;
	for(uint8_t y=0; y < (GFX_SCREEN_HEIGHT >> 3); y++)
	{
		if(ptr[GFX_SCREEN_WIDTH] == BufferDirty)  //Wysy³amy dane tylko jeœli dana strona by³a zmieniona
		{
			st7565r_set_page_address(y);
			st7565r_set_column_address(0);
			for(uint8_t x=0; x < GFX_SCREEN_WIDTH; x++) st7565r_wr_data(*ptr++);
			*ptr++=BufferClean;                //Skasuj flagê Dirty
		} else ptr+=GFX_SCREEN_WIDTH+1;
	}
}

void st7565r_Clear(_Bool color)
{
	uint8_t pix=0;
	if(color) pix=0xff;
	uint8_t *ptr=(uint8_t*)LCD_FrameBuffer;
	for(uint8_t y=0; y < (GFX_SCREEN_HEIGHT >> 3); y++)
	{
		for(uint16_t i=0; i < GFX_SCREEN_WIDTH; i++) *ptr++=pix;
		*ptr++=BufferDirty; //Bajt dirty
	}
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

void st7565r_SetText(uint8_t x, uint8_t y, const __memx char *tekst, const uint8_t __flash * const __flash font[], _Bool invert)
{
	GLCD_y=y; GLCD_x=x;
	uint8_t rows=(uint8_t)(uint16_t)font[0]; //Pobierz wysokoœæ fontu
	y+=rows-1;
	char ch;

	while((ch=*tekst++))  //Wyœwietl kolejne znaki a¿ do koñca tekstu (znaku NUL)
	{
		const uint8_t __flash *znak=font[ch-30]; //Adres pocz¹tku opisu znaku
		uint8_t col=*znak++;                     //Szerokoœæ znaku w pikselach
		uint8_t page=0, coldesc=0, colmask=0;

		for(uint8_t ox=0; ox < col; ox++)        //Wyœwietlamy kolejne kolumny tworz¹ce znak
		{
			uint8_t dispmask=1 << (y % 8);
			for(uint8_t oy=0; oy < rows; oy++)   //Narysuj jedn¹ kolumnê znaku
			{
				if(colmask == 0)
				{
					colmask=0x80;
					coldesc=*znak++;             //Pobierz bajt opisu znaku
				}
				page=((y - oy) >> 3) & 0b111;    //Zabezpieczenie przed zapisem poza bufor
				LCD_FrameBuffer[page][GLCD_x]&=~dispmask;
				if(coldesc & colmask) LCD_FrameBuffer[page][GLCD_x]|=dispmask;
				if(invert) LCD_FrameBuffer[page][GLCD_x]^=dispmask;  //Dokonaj inwersji obrazu
				colmask>>=1;
				dispmask>>=1;
				if(dispmask == 0)   //Przekraczamy stronê - nale¿y zapisaæ kompletny bajt
				{
					LCD_FrameBuffer[page][GFX_SCREEN_WIDTH]=BufferDirty;
					dispmask=0x80;
				}
			}
			if(dispmask != 0x80) LCD_FrameBuffer[page][GFX_SCREEN_WIDTH]=BufferDirty;
			GLCD_x++;
			if(GLCD_x == GFX_SCREEN_WIDTH) return; //Wychodzimy za LCD
		}
	}
}

void st7565r_DrawRect(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, _Bool isSet)
{
	do
	{
		st7565r_MoveTo(x1, y1);
		st7565r_DrawHLine(x2, y1);
		y1++;
	} while (y1<y2);
}

void st7565r_draw_bitmap_mono(uint8_t x, uint8_t y, const __flash uint8_t image[], _Bool invert)
{
	uint8_t page, imagedata=0;
	uint8_t rows=image[1];                  //Pobierz szerokoœæ bitmapy
	uint8_t cols=image[0];                  //Pobierz wysokoœæ bitmapy
	const __flash uint8_t *data=&image[2];  //WskaŸnik do danych obrazu

	uint8_t datamask=0x00;

	for(uint8_t ox=x; ox < (x + cols); ox++)   //Rysujemy kolumny
	{
		page=(y >> 3) & 0b111;                 //Zabezpieczenie przed zapisem poza bufor
		uint8_t dispmask=1<<(y & 0b0111);      //Maska pozycji od której rysujemy bitmapê

		for(uint8_t oy=y; oy < (y + rows); oy++)
		{
			if(dispmask == 0)        //Zapisujemy kolejne 8 bitów
			{
				LCD_FrameBuffer[page][GFX_SCREEN_WIDTH]=BufferDirty;
				dispmask=0x01;
				page++;
			}
			if(datamask == 0)        //Pobieramy kolejny bajt danych bitmapy
			{
				datamask=0x80;
				imagedata=*data++;
			}

			LCD_FrameBuffer[page][ox]&=~dispmask;
			if(imagedata & datamask) LCD_FrameBuffer[page][ox]|=dispmask;
			if(invert) LCD_FrameBuffer[page][ox]^=dispmask;  //Dokonaj inwersji obrazu
			dispmask<<=1;
			datamask>>=1;
		}
	}
}