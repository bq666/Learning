/* entry.c -- petla o warunku wejsciowy */
#include <stdio.h>
int main(void)
{
    const int tajny_kod = 13;
    int wprowadzony_kod;
    
    printf("Aby wejsc do klubu terapeutycznego agorafobii,\n");
    printf("wprowadz wlasciwy kod: ");
    scanf("%d", &wprowadzony_kod);
    while (wprowadzony_kod != tajny_kod)
    {
        printf("Aby wejsc do klubu terapeutycznego agorafobii,\n");
        printf("wprowadz wlasciwy kod: ");
        scanf("%d", &wprowadzony_kod);
    }
    printf("Gratulacje! Jestes wyleczony!\n");
    
    return 0;
}

