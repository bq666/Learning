/*
 * ST7565.h
 *
 * Created: 2013-08-12 13:15:37
 *  Author: tmf
 */


#ifndef ST7565_H_
#define ST7565_H_

//Polecenia rozpoznawane przez kontroler
#define ST7565R_CMD_DISPLAY_ON                     0xAF					//W³¹cz LCD
#define ST7565R_CMD_DISPLAY_OFF                    0xAE					//Wy³¹cz LCD
#define ST7565R_CMD_START_LINE_SET		           0x40					//Ustaw adres pierwszej wyœwietlanej linii
#define ST7565R_CMD_PAGE_ADDRESS_SET		       0xB0					//Ustaw adres strony
#define ST7565R_CMD_COLUMN_ADDRESS_SET_MSB		   0x10					//Ustaw adres kolumny
#define ST7565R_CMD_COLUMN_ADDRESS_SET_LSB         0x00
#define ST7565R_CMD_ADC_NORMAL                     0xA0
#define ST7565R_CMD_ADC_REVERSE                    0xA1
#define ST7565R_CMD_DISPLAY_NORMAL                 0xA6
#define ST7565R_CMD_DISPLAY_REVERSE                0xA7
#define ST7565R_CMD_DISPLAY_ALL_POINTS_OFF         0xA4					//Normalny tryb pracy LCD
#define ST7565R_CMD_DISPLAY_ALL_POINTS_ON          0xA5					//W³¹cz wszystkie piksele - dla testowania LCD
#define ST7565R_CMD_LCD_BIAS_1_DIV_5_DUTY33        0xA1
#define ST7565R_CMD_LCD_BIAS_1_DIV_6_DUTY33        0xA2
#define ST7565R_CMD_NORMAL_SCAN_DIRECTION          0xC0
#define ST7565R_CMD_REVERSE_SCAN_DIRECTION         0xC8
#define ST7565R_CMD_VOLTAGE_RESISTOR_RATIO_0       0x20
#define ST7565R_CMD_VOLTAGE_RESISTOR_RATIO_1       0x21
#define ST7565R_CMD_VOLTAGE_RESISTOR_RATIO_2       0x22
#define ST7565R_CMD_VOLTAGE_RESISTOR_RATIO_3       0x23
#define ST7565R_CMD_VOLTAGE_RESISTOR_RATIO_4       0x24
#define ST7565R_CMD_VOLTAGE_RESISTOR_RATIO_5       0x25
#define ST7565R_CMD_VOLTAGE_RESISTOR_RATIO_6       0x26
#define ST7565R_CMD_VOLTAGE_RESISTOR_RATIO_7       0x27
#define ST7565R_CMD_POWER_CTRL_ALL_ON              0x2F
#define ST7565R_CMD_SLEEP_MODE                     0xAC
#define ST7565R_CMD_NORMAL_MODE                    0xAD
#define ST7565R_CMD_RESET                          0xE2
#define ST7565R_CMD_NOP                            0xE3
#define ST7565R_CMD_ELECTRONIC_VOLUME_MODE_SET     0x81
#define ST7565R_CMD_BOOSTER_RATIO_SET              0xF8
#define ST7565R_CMD_BOOSTER_RATIO_2X_3X_4X         0x00
#define ST7565R_CMD_BOOSTER_RATIO_5X               0x01
#define ST7565R_CMD_BOOSTER_RATIO_6X               0x03
#define ST7565R_CMD_STATUS_READ                    0x00
#define ST7565R_CMD_END                            0xEE
#define ST7565R_CMD_READ_MODIFY_WRITE              0xE0

#define ST7565R_DISPLAY_CONTRAST_MIN	5			//Zakres zmian regulacji kontrastu
#define ST7565R_DISPLAY_CONTRAST_MAX	40			//Nie nale¿y go przekraczaæ ze wzglêdu na mo¿liwoœæ uszkodzenia LCD

#define GFX_SCREEN_WIDTH					128			//Liczba punktów w poziomie
#define GFX_SCREEN_HEIGHT					32			//Liczba punktów w pionie

extern uint8_t GLCD_x, GLCD_y;                        //Wspó³rzêdne X i Y ostatnio narysowanego punktu

void st7565r_init();         //Inicjalizacja kontrolera i w³¹czenie LCD
void st7565r_set_contrast(uint8_t contrast); //Zmieñ kontrast
void st7565r_set_display_start_line_address(uint8_t address); //Ustaw adres pierwszej wyœwietlanej linii obrazu
void st7565r_LCD_test(_Bool onoff);
void st7565r_CpyDirtyPages();                              //Uaktualnij VRAM
void st7565r_SetPixel(uint8_t x, uint8_t y, _Bool isSet);  //Narysuj piksel
void st7565r_LineTo(uint8_t x, uint8_t y, _Bool isSet);    //Narysuj prost¹
void st7565r_Clear(_Bool color);                           //Wyczyœæ ca³y bufor i LCD
void st7565r_Circle(uint8_t cx, uint8_t cy , uint8_t radius, uint8_t attrs); //Narysuj okr¹g lub ko³o. attrs & 2==1 rysuj ko³o, bit nr 0 attrs okreœla kolor pikseli
void st7565r_SetText(uint8_t cx, uint8_t cy, const __memx char *tekst, const uint8_t __flash * const __flash font[], _Bool invert); //Wyœwietl podany tekst u¿ywaj¹c wskazanego fontu
void st7565r_DrawRect(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, _Bool isSet);  //Rysuj prostok¹t o wierzcho³kach {x1,y1} i {x2, y2}
void st7565r_draw_bitmap_mono(uint8_t x, uint8_t y, const __flash uint8_t image[], _Bool invert); //Wyœwietl bitmapê
#endif /* ST7565_H_ */