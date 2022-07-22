/* porown2.c -- wartosci zwracane przez strcmp() */
#include <stdio.h>
#include <string.h>
int main(void)
{
    printf("strcmp(\"A\", \"A\") = ");
    printf("%d\n", strcmp("A", "A"));

    printf("strcmp(\"A\", \"B\") = ");
    printf("%d\n", strcmp("A", "B"));

    printf("strcmp(\"B\", \"A\") = ");
    printf("%d\n", strcmp("B", "A"));

    printf("strcmp(\"C\", \"A\") = ");
    printf("%d\n", strcmp("C", "A"));

    printf("strcmp(\"Z\", \"a\") = ");
    printf("%d\n", strcmp("Z", "a"));
    
    printf("strcmp(\"koty\", \"kot\") = ");
    printf("%d\n", strcmp("koty", "kot"));
      return 0;
}

