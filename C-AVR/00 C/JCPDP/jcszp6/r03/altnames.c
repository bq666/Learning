/* altnames.c -- przenośne  typy calkowite i ich nazwy */
#include <stdio.h>
#include <inttypes.h> // naglowek pozwala uzyc typow przenosnych 
int main(void)
{
    int32_t me32;     // me16 jest 16-bitowa zmienna calkowita ze znakiem
   
    me32 = 45933945;
    printf("Po pierwsze, zalozmy, ze int32_t jest typu int: ");
    printf("me32 = %d\n", me32); 
    printf("Nastepnie nie czynmy zadnych zalozen.\n");
    printf("W zamian skorzystajmy z \"macro\" z pliku inttypes.h: ");
    printf("me32 = %" PRId32 "\n", me32);  
    
    return 0;
}

