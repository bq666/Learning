// mojtyp.c
#include <stdio.h>

#define MOJTYP(X) _Generic((X),\
    int: "int",\
    float : "float",\
    double: "double",\
    default: "inny"\
)

int main(void)
{
    int d = 5;

    printf("%s\n", MOJTYP(d));     // d jest typu int
    printf("%s\n", MOJTYP(2.0*d)); // 2.0* d jest typu double
    printf("%s\n", MOJTYP(3L));    // 3L jest typu long
    printf("%s\n", MOJTYP(&d));    // &d jest typu int *
    return 0;
}

