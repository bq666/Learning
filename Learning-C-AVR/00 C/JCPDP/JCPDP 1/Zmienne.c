#include <stdint-gcc.h>     //zmienne uint8_t itp.
#include <inttypes.h>       // np.                <--- zawiera stdint.h
#include <stdlib.h>         // np. exit() rand() srand()
#include <time.h>           //

#include <stdio.h>          // np. printf() scanf() putchar() getchar()
#include <string.h>         // np. strcpy ()
#include <ctype.h>          // np. isalpha()
#include <complex.h>


#include <math.h>           // np. celi() floor() fabs() pow() sqrt()


int zmienne(void){

        char y;
        short int a;
        short b;
        int c;
        long int d;
        long e;
        long long int f;
        long long g;
        unsigned gg;

        float h;
        double i;

        int_least8_t j;
        int_fast8_t k;
        intmax_t l;




        _Bool x;
        _Complex z;
        complex zz;
         //int (_Imaginary) w;


      //  !!!!!!!!!!!!! dopisz float long float duble _bool itp.



        printf("char = \t\t%d bajtów\n", sizeof(y));
        printf("short int = \t%d bajtów\n", sizeof(a));
        printf("short = \t%d bajtów\n", sizeof(b));
        printf("int = \t\t%d bajtów\n", sizeof(c));
        printf("long int = \t%d bajtów\n", sizeof(d));
        printf("long = \t\t%d bajtów\n", sizeof(e));
        printf("long long int = %d bajtów\n", sizeof(f));
        printf("long long = \t%d bajtów\n", sizeof(g));
        printf("unsigned = \t%d bajtów\n\n", sizeof(gg));

        printf("float = \t%d bajtów\n", sizeof(h));
        printf("double = \t%d bajtów\n\n", sizeof(i));

        printf("int_least8_t = \t%d bajtów\n", sizeof(j));
        printf("int_fast8_t = \t%d bajtów\n", sizeof(k));
        printf("intmax_t = \t%d bajtów\n\n", sizeof(l));

        printf("_Bool = \t%d bajtów\n", sizeof(x));
        printf("_Complex = \t%d bajtów\n", sizeof(z));
        printf("complex = \t%d bajtów  <--- typ z complex.h\n", sizeof(zz));
        //printf("       = %d bajtów\n", sizeof(w));







        for(c=-10; c<=20; c++){
            printf("%#d \t%#.4X\n",c,(int)c);
        }
return (0);
}
