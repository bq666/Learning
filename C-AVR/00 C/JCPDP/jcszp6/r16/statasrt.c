// statasrt.c
#include <stdio.h>
#include <limits.h>

_Static_assert(CHAR_BIT == 16, "niepoprawne zalozenie: 16-bitowy char");

int main(void)
{
    puts("char ma 16 bitow.");
    return 0;
}

