#include <limits.h>         // Max i Min wartości typów całkowitych int, char itp.
#include <float.h>          // Max i Min wartości typów zmiennoprzecinkowych float itp.
#include <stdint-gcc.h>     //zmienne uint8_t itp.
#include <stdbool.h>        // typ bool, true, false
#include <inttypes.h>       // np.                <--- zawiera stdint.h
#include <stdlib.h>         // np. exit() rand() srand()
#include <time.h>           //
#include <iso646.h>         //  &&  --->  and    || --->  or   ! ---> not

#include <stdio.h>          // np. printf() scanf() putchar() getchar() <--- zawiera <stddef.h>
#include <stddef.h>         // np. NULL
#include <string.h>         // np. strcpy ()
#include <ctype.h>          // np. isalpha()
#include <time.h>           //
//#include <iostream>         // C++ std::cin.clear();



#include <math.h>           // np. celi() floor() fabs() pow() sqrt()


void wskazniki (void){
//system("chcp 65001");






/*    int *pi_p;
    {
        int tmp = 5;
        pi_p = &tmp;
    }
    float i;
    long int tablica[10000];
    int b = 0;
    tablica[b] = 1;
    printf("%d\n", tablica[b]);
    getchar();
    for(i = 0; i != -1; i++){
        printf(("%d %20.0f %d\n"), *pi_p, i, tablica[b-1]);
        ((int)i % 10000 == 0 ? ((tablica[b] = i), b++):printf(""));
    }
*/


/*    char *string1_p;
    char *string2_p;
    string1_p = (char*)malloc(16);
    strcpy(string1_p, "0123456789AB");
    string2_p = realloc(string1_p, 64);
    printf("lancuch string1_p wartość: %2p [%s]\n", string1_p, string1_p);
    printf("lancuch string2_p wartość: %2p [%s]\n", string2_p, string2_p);
*/

  /*  int g;
    int p;
    int tablica2[20] = {1,2,3};
    g = sizeof(tablica2);
    p = sizeof(tablica2[0]);
    printf("%d\n", g);
    printf("%d\n", p);



    char *string1_p;
    char *string2_p;

    string1_p = (char*)malloc(20);
    strcpy(string1_p, "0123456789AB");
    printf("string1_p = %s\n", string1_p);

    printf("%d\n", ( sizeof(string1_p));
    printf("%d\n", sizeof(*string1_p));

    string2_p = realloc(string1_p, sizeof(string1_p) / sizeof(*string1_p));
    printf("lancuch string1_p wartość: %2p [%s]\n", string1_p, string1_p);
    printf("lancuch string2_p wartość: %2p [%s]\n", string2_p, string2_p);



    double tablica[10] = {66.6, 66.6, 60.9};
    int i;
    for (i = 0; i < 11; i++){
        printf("%.1f\n", tablica[i]);
    }
    for(i = 0; i < 20; i++){
        printf("string1_p[%d] = %c   string2_p[%d] = %c\n", i, *(string1_p + i), i, *(string2_p + i));
    }
*/







/*
    char *p_name = (char*)malloc(20);
    printf("%p\n", p_name);
    scanf("%s", p_name);
    int i=0;
    int c;
    for(i = 0; i < 20; i++){
        c = (int)*(p_name + i);
    }
    i = 0;
    while(*(p_name + i) != 0){
        printf("%c", *(p_name + i));
        i++;
    }
*/




/*    char *name = (char*)malloc(strlen("Zuzia") + 1);
    strcpy(name,"Zuzia");
    while(*name != 0){
        printf("%c", *name);
        name++;
    }
*/


/*
//--------------------------------------------------------------------------
    int c = 2000000;
    int *p_int = (int*) malloc((c+1)*sizeof(int));
    *p_int = 0;

    *(p_int + 1) = 10;
    //printf("*p_int: %d\n", *p_int);
    int i;
    for(i = 1; i < c; i++){
        *(p_int + i) = *(p_int + i - 1) + 1;
    }
    for(i = 0; i < c; i++){
        printf("*(p_int + i) = %2d\t(p_int + i) = %10p\t&p_int + i = %x\n", *(p_int + i), (p_int + i), &p_int + i);
    }
    free(p_int);
//------------------------------------------------------------------------
*/



















/*    int num = 5;
    int num2 = 9;
    const int limit = 500;
    int *p_num = &num;
    int *const p_limit = &limit;
    const int *const p_num2 = &num2;


    printf("\n\np_num2 - Adres: %x *p_num2: %d Limit = %d\n", &p_num2, *p_num2, limit);
    *p_num2 = 1;
    printf("\n\np_num2 - Adres: %x *p_num2: %d Limit = %d\n", &p_num2, *p_num2, limit);
    *p_num2 = 100;
    printf("\n\np_num2 - Adres: %x *p_num2: %d Limit = %d\n", &p_num2, *p_num2, limit);
    printf("\n\nnum - Adres: %x wartość: %x\n", &num, num);
    printf("limit - Adres: %x wartość: %x\n", &limit, limit);
    printf("p_num - Adres: %x wartość: %x\n", &p_num, p_num);
    printf("p_limit - Adres: %x wartość: %x\n\n", &p_limit, p_limit);

    *p_num = 10;
//    *p_limit = 500;
    printf("\n\nnum - Adres: %x wartość: %x\n", &num, num);




    char *p_t_titles[] = {"Opowieść od dwóch miastach", "Komu bije dzwon", "Don Kichot", "Odyseja", "Moby Dick", "Hamlet", "Podróże Guliwera"};
    char **pp_t_bestBooks[3];
    char **pp_t_englishBooks[4];

    pp_t_bestBooks[0] = &p_t_titles[0];
    pp_t_bestBooks[1] = &p_t_titles[3];
    pp_t_bestBooks[2] = &p_t_titles[5];
    pp_t_englishBooks[0] = &p_t_titles[0];
    pp_t_englishBooks[1] = &p_t_titles[1];
    pp_t_englishBooks[2] = &p_t_titles[5];
    pp_t_englishBooks[3] = &p_t_titles[6];
    printf("%s\n",*pp_t_englishBooks[1]);








    int i;
    for (i = 0; i < 10; i++){
        printf("Adres p_t_titles[%d] = %x\n", i, p_t_titles + i);
        printf("Wartość p_t_titles[%d] = %x\n", i, *(p_t_titles + i));
    }
    printf("%d\n", *(p_t_titles + 6) - *(p_t_titles + 5));




    char a_char_1B; // = 5;
    short b_short_2B;

    char *p_a = &a_char_1B;
    short *p_b = &b_short_2B;

    //int num = 64;
    //int *p_num = &num;
    int **pp_num = &p_num;
    void *p_void_num = &b_short_2B;

    printf("p_void_num przed: %x\n", p_void_num);
    //p_void_num (short*) += 1;  <--- ZLE !!!
    p_void_num = (long*) p_void_num + 1;
    printf("p_void_num po: %x\n\n", p_void_num);






    printf("Wartość p_num: %p\n", p_num);
    p_num = pp_num;
    printf("Wartość p_num: %p\n", p_num);
    p_num = (int) p_void_num;
    printf("Wartość p_num: %p\n", p_num);

    size_t sizet = -5;
    printf("%d\n", sizet);
    printf("%u\n", sizet);  // <--- błędnie wyświetla ujemne
    printf("Rozmiar *char: %d\n", sizeof(char*));


    intptr_t *p2_num = &num;
    p2_num = &num;

    int vector[] = {28, 41, 7};
    int *p_p0 = vector;
    int *p_p1 = vector + 1;
    int *p_p2 = vector + 2;
    printf("p2-p0: %d\n", p_p2 - p_p0);
    printf("p0-p2: %d\n", p_p0 - p_p2);
    printf("p2 > p0: %d\n", p_p2 > p_p0);
    printf("p0 > p2: %d\n", p_p0 > p_p2);









    p_num = vector;
    printf("%d\n", *p_num);
    printf("%d\n", *(++p_num));
    printf("%d\n", *(++p_num));




    printf("Zawartość p_a przed: %x\n", p_a);
    p_a++;
    printf("Zawartość p_a po: %x\n", p_a);

    printf("Zawartość p_b przed: %x\n", p_b);
    p_b++;
    printf("Zawartość p_b po: %x\n", p_b);
*/



     /*  p_num = NULL;
    //p_num = 100;

    if(p_num){
        printf("NIE Pusty\n");
    }else {
        printf("Pusty\n");
    }
    */


  /*  printf("%d\n", **pp_num);
    **pp_num = 99;
    printf("%d\n", num);
    */


  /*  printf("Adres p_num = %d Wartość: %d\n", &p_num, p_num);
    printf("*p_num = %d\n", *p_num);
    num = 99;
    printf("Adres p_num = %d Wartość: %d\n", &p_num, p_num);
    printf("*p_num = %d\n", *p_num);
    printf("Adres p_num = %x Wartość: %x\n", &p_num, p_num);
    printf("Adres p_num = %o Wartość: %o\n", &p_num, p_num);
    printf("Adres p_num = %p Wartość: %p\n", &p_num, p_num);
    printf("Adres p_num = %p Wartość: %p\n", &p_num, (void*)p_num);
    */

  /*  printf("p_num = %p\n", p_num);
    printf("numm = %p\n", numm);

    num = 1;
    p_num = (int*) num;
    printf("p_num = %p\n", p_num); */



 /*   num = 0;
    p_num = &num;
    printf("num = %d\n", num);
    printf("*p_num = %x\n", *p_num);
    printf("adres num = %x\n", &num);
    printf("p_num = %x\n", p_num);
    printf("&p_num = %x\n\n", &p_num);





    char *names[] = {"kowalski","Nowak","Kowalczyk"};

    //names[2][8] = 'A';
    printf("%c\n", *(*(names+2)+8));
    printf("%c\n", names[1][2]);

*/



}
