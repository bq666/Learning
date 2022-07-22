/* wysw1.c -- wyswietla lancuch bez dodawania \n */
#include <stdio.h>
void wysw1(const char * lancuch) /* lancuch nie ulega zmianie */
{
    while (*lancuch != '\0')
        putchar(*lancuch++);
}

