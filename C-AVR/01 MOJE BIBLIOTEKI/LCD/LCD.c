void LCD_init ()
{		
	data_dir_out();
	DDR(LCD_RSPORT) |= (1<<LCD_RS);
	DDR(LCD_EPORT) |= (1<<LCD_E);
	#if USE_RW == 1						// kompilacja warunkowa jeœli u¿ywamy RW
		DDR(LCD_RWPORT) |= (1<<LCD_RW);
	#endif	
	
	// zerowanie pinów linii steruj¹cych 
	PORT(LCD_RSPORT) |= (1<<LCD_RS);
	PORT(LCD_EPORT) |= (1<<LCD_E);
	#if USE_RW == 1
		PORT(LCD_RWPORT) |= (1<<LCD_RW);
	#endif
	
	_delay_ms(15);
	PORT(LCD_EPORT) &= ~(1<<LCD_E);
	PORT(LCD_RSPORT) &= ~(1<<LCD_RS);
	#if USE_RW == 1
		PORT(LCD_RWPORT) &= ~(1<<LCD_RW);
	// jeszcze nie mo¿emy u¿ywaæ Bussy Flag
	SET_E;
	lcd_sendHalf(0x03);				// tryb 8-bitowy DL=1
	CLR_E;
	_delay_ms(4.1);
	SET_E;
	lcd_sendHalf(0x03);				// tryb 8-bitowy DL=1
	CLR_E;
	_delay_us(100);
	SET_E;
	lcd_sendHalf(0x03);				// tryb 8-bitowy DL=1
	CLR_E;
	_delay_us(100);
	SET_E
	lcd_sendHalf(0x02);				// tryb 4-bitowy DL=0
	CLR_E;
	_delay_us(100);
	// ju¿ mo¿na u¿ywaæ Busy Flag - u¿ywamy ju¿ komend do wysy³ania 
	
	lcd_write_cmd((1<<5) | ~(1<<4) | (1<<3) | ~(1<<2));							// LCDC_FUNC|LCDC_FUNC4B|LCDC_FUNC2L|LCDC_FUNC5x7 tryb 4-bitowy, 2 wiersze, znak 5x7	
	// lcd_write_cmd(LCDC_ONOFF|LCDC_CURSOROFF);								// wy³¹cz kursor 
	lcd_write_cmd((1<<3) | (1<<2) | (1<<1) | (1<<0));							// w³¹czenie wyœwietlacza (LCDC_ONOFF|LCDC_DISPLAYON);	
	// lcd_write_cmd(LCDC_ENTRY|LCDC_ENTRYR);									// przesuwanie kursora w prawo bez przesuwania zawartoœci ekranu 
	lcd_cls();																	// czyszczenie ekranu 
}


void lcd_cls (void)
{
	lcd_write_cmd (1<<0);				//(LCDC_CLS);
	#if USE_RW == 0
		_delay_ms(4.9);
	#endif	
}


/* #if USE_LCD_CURSOR_HOME == 1
void lcd_home(void)
{
	lcd_write_cmd(LCDC_CLS|LCDC_HOME);
	#if USE_RW == 0
		_delay_ms(4.9);
	#endif
}
#endif */


/* #if USE_LCD_CURSOR_ON == 1
void lcd_cursor_on(void)
{
	lcd_write_cmd(LCDC_ONOFF|LCDC_DISPLAYON|LCDC_CURSORON);
}

void lcd_cursor_off(void)
{
	lcd_write_cmd(LCDC_ONOFF|LCDC_DISPLAYON);
}
#endif */


/* #if USE_LCD_CURSOR_BLINK == 1
void lcd_blink_on(void)
{
	lcd_write_cmd(LCDC_ONOFF|LCDC_DISPLAYON|LCDC_CURSORON|LCDC_BLINKON);
}

void lcd_blink_off(void)
{
	lcd_write_cmd(LCDC_ONOFF|LCDC_DISPLAYON);
}
#endif */


void lcd_str(char * str)
{
	register char znak;
	while ((znak = *(str++)))
	lcd_write_data((znak>=0x80 & znak <=0x87) ? (znak & 0x07) : znak);
}


#if USE_LCD_STR_P == 1
void lcd_str_P(char * str)
{
	register char znak;
	while ((znak = pgm_read_byte(str++)))
	lcd_write_data(((znak >= 0x80) && (znak <= 0x87)) ? (znak & 0x07) : znak);
}
#endif


#if USE_LCD_STR_E == 1
void lcd_str_E(char *str)
{
	register char znak;
	while(1)
	{
		znak = eeprom_read_byte((uint8_t *)(str++));
		if (!znak || znak == 0xFF) break;					// 0xFF traktujemy jako 0 w pamiêci EEPROM 
		else
		lcd_write_data(((znak>= 0x80) && (znak<=0x87)) ? (znak & 0x07) :znak);
	}
}
#endif


#if USE_LCD_INT == 1
void lcd_int(int val)
{
	char bufor[17];
	lcd_str(itoa (val, bufor, 10));
}
#endif


#if USE_LCD_HEX == 1
void lcd_hex(int val)
{
	char bufor [17];
	lcd_str (itoa(val, bufor, 16));
}
#endif
//-------------------------------------------------------------------------------------------------------

static void data_dir_out ()
{
	DDR(LCD_D7PORT) |= (1<<LCD_D7);
	DDR(LCD_D6PORT) |= (1<<LCD_D6);
	DDR(LCD_D5PORT) |= (1<<LCD_D5);
	DDR(LCD_D4PORT) |= (1<<LCD_D4);	
}

static void data_dir_in ()
{
	DDR(LCD_D7PORT) &= ~(1<<LCD_D7);
	DDR(LCD_D6PORT) &= ~(1<<LCD_D6);
	DDR(LCD_D5PORT) &= ~(1<<LCD_D5);
	DDR(LCD_D4PORT) &= ~(1<<LCD_D4);
}


static inline void lcd_sendHalf (uint8_t data)
{
	if (data&(1<<0)) PORT(LCD_D4PORT) |= (1<<LCD_D4);
	else PORT(LCD_D4PORT) &= ~(1<<LCD_D4);
	
	if (data&(1<<0)) PORT(LCD_D5PORT) |= (1<<LCD_D5);
	else PORT(LCD_D5PORT) &= ~(1<<LCD_D5);
	
	if (data&(1<<0)) PORT(LCD_D6PORT) |= (1<<LCD_D6);
	else PORT(LCD_D6PORT) &= ~(1<<LCD_D6);
	
	if (data&(1<<0)) PORT(LCD_D7PORT) |= (1<<LCD_D7);
	else PORT(LCD_D7PORT) &= ~(1<<LCD_D7);	
}


#if USE_RW == 1
static inline uint8_t lcd_readHalf (void)
{
	uint8_t result=0;
	if (PIN(LCD_D4PORT) & (1<<LCD_D4)) result |= (1<<0);
	if (PIN(LCD_D5PORT) & (1<<LCD_D5)) result |= (1<<1);
	if (PIN(LCD_D6PORT) & (1<<LCD_D6)) result |= (1<<2);
	if (PIN(LCD_D7PORT) & (1<<LCD_D7)) result |= (1<<3);
	return result;	
}
#endif


#if USE_RW == 1
static uint8_t check_BF(void)
{
	CLR_RS;
	return _lcd_read_byte();
}
#endif


static void _lcd_write_byte (unsigned char _data)
{
	data_dir_out ();
			
	#if USE_RW == 1
		CLR_RW;
	#endif
		SET_E;
		lcd_sendHalf(_data>>4);		// wysy³anie starszej czêœci bajtu danych D7-D4
		CLR_E;
		
		SET_E;
		lcd_sendHalf(_data);		// wysy³anie m³odsze czêœci bajtu danych D3-D0
		CLR_E;
		
	#if USE_RW == 1
		while (check_BF() & (1<<7) );
	#else
		_delay_us(120);
	#endif	
}


#if USE_RW == 1
uint8_t _lcd_read_byte (void)
{
	uint8_t result = 0;
	data_dir_in ();
		
	SET_RW;
	SET_E;
	result |= (lcd_readHalf() << 4); // odczyt starszej czêœci bajtu danych D7-D4
	CLR_E;
	SET_E;
	result |= lcd_readHalf();  // odczyt m³odszej czêœci bajtu danych D3-D0
	CLR_E;
	
	return result;
}
#endif






void lcd_write_cmd (uint8_t cmd)
{
	CLR_RS;
	_lcd_write_byte(cmd);
}

void lcd_write_data (uint8_t data)
{
	SET_RS;
	_lcd_write_byte(data);
}