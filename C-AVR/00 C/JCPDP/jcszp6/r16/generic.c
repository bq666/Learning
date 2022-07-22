// generic.c -- definiowanie makrodefinicji uogolnionych
#include <stdio.h> 
#include <math.h>

#define RAD_NA_ST (180/(4 * atanl(1)))

// uogolniona wersja pierwiastka kwadratowego
#define SQRT(X) _Generic((X),\
  long double: sqrtl, \
  default: sqrt, \
  float: sqrtf)(X)

// uogolniona wersja sinusa (kat wyrazony w stopniach)
#define SIN(X) _Generic((X),\
  long double: sinl((X)/RAD_NA_ST),\
  default: sin((X)/RAD_NA_ST),\
  float: sinf((X)/RAD_NA_ST)\
)

int main(void)
{
    float x = 45.0f;
    double xx = 45.0;
    long double xxx =45.0L;
    long double y = SQRT(x);
    long double yy= SQRT(xx);
    long double yyy = SQRT(xxx);

    printf("%.17Lf\n", y);    // dla typu float
    printf("%.17Lf\n", yy);   // dla typu domyslnego
    printf("%.17Lf\n", yyy);  // dla typu long double
    int i = 45;
    yy = SQRT(i);             // dla typu domyslnego
    printf("%.17Lf\n", yy);
    yyy= SIN(xxx);            // dla typu long double
    printf("%.17Lf\n", yyy);
    return 0;
}

