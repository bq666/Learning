/* sekwenc.c -- korzysta ze znakow sterujacych */
#include <stdio.h>
int main(void)
{
    float pensja;
    printf("Podaj miesieczne wynagrodzenie, na jakie zaslugujesz:"); /* 1 */
    printf(" _________ zl\b\b\b\b\b\b\b\b\b\b\b\b");                 /* 2 */
    scanf("%f", &pensja);
    printf("\n\t%.2f zl miesiecznie to %.2f zl rocznie.", pensja,
               pensja * 12.0);                                       /* 3 */
    printf("\rHo, ho!\n");                                           /* 4 */
    return 0;
}

