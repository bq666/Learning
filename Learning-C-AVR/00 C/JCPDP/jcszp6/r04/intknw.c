/* intkonw.c -- kilka niedopasowanych specyfikatorow calkowitych */
#include <stdio.h>
#define STRONY 336
#define SLOWA 65618
int main(void)
{
   short num = STRONY;
   short mnum = -STRONY;

   printf("num jako short i unsigned short: %hd %hu\n", num, num);
   printf("-num jako short i unsigned short: %hd %hu\n", mnum, mnum);
   printf("num jako int i char: %d %c\n", num, num);
   printf("SLOWA jako int, short i char: %d %hd\n", SLOWA, SLOWA, SLOWA);
   return 0;
}

