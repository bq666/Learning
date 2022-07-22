/* rzedy1.c -- wykorzystuje petle zagniezdzone */
#include <stdio.h>
#define RZEDY  6
#define ZNAKI 10
int main(void)
{
    int rzad;
    char ch;

    for (rzad = 0; rzad < RZEDY; rzad++)          /* wiersz 10 */
    {
        for (ch = 'A'; ch < ('A' + ZNAKI); ch++)  /* wiersz 12 */
            printf("%c", ch);
        printf("\n");
    }
    return 0;
}

