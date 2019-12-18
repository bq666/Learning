#include <stdio.h>

int my_strlen(char *);

int forTests(char str[]){
    return my_strlen(str);
}

int main() {
//    printf("Hello, World!\n");
    printf("%d\n", my_strlen("test"));
//    printf("%d <--- last", forTests("bq666\n"));

    return 0;
}