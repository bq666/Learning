/* wysw2.c -- wyswietla lancuch i zlicza znaki */
#include <stdio.h>
int wysw2(const char * lancuch)
{
    int licznik = 0;
    while (*lancuch)
    {
        putchar(*lancuch++);
        licznik++;
    }
    putchar('\n');           /* znak nowej linii nie jest liczony */
    return(licznik);
}

