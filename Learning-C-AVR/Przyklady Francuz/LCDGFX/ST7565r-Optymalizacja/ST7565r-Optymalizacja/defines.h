#define GLUE(a, b)     a##b

/* single-bit macros, used for control bits */
#define SET_(what, p, m) GLUE(what, p) |= (1 << (m))
#define CLR_(what, p, m) GLUE(what, p) &= ~(1 << (m))
#define GET_(/* PIN, */ p, m) GLUE(PIN, p) & (1 << (m))
#define SET(what, x) SET_(what, x)
#define CLR(what, x) CLR_(what, x)

/*makra operuj¹ce na bajtach*/
#define DATA(what, b)	GLUE(what, b)

/* Po³¹czenia ST7565R z AVR */
#define ST7565_CS    C, 0
#define ST7565_RESET C, 1
#define ST7565_A0    C, 2
#define ST7565_MOSI	 B, 3
#define ST7565_SCK	 B, 5
