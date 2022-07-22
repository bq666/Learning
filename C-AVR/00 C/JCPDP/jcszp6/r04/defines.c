// defines.c -- uzywa definicji stalych z biblioteki limit.h i typu float
#include <stdio.h>
#include <limits.h>    // granice liczb calkowitych
#include <float.h>     // granice liczb zmiennoprzecinkowych
int main(void)
{
    printf("Niektore granice liczbowe dla tego systemu:\n");
    printf("Najwiekszy int: %d\n", INT_MAX);
    printf("Najmniejszy long long: %lld\n", LLONG_MIN);
    printf("Jeden bajt = %d bitow (w tym systemie).\n", CHAR_BIT);
    printf("Najwiekszy double: %e\n", DBL_MAX);
    printf("Najmniejszy normalny float: %e\n", FLT_MIN);
    printf("float precyzja = %d cyfr\n", FLT_DIG);
    printf("float epsilon = %e\n", FLT_EPSILON);
    
    return 0;
}

