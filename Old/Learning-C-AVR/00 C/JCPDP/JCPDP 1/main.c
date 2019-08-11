//#include <delay.h>

#include <limits.h>         // Max i Min wartoœci typów ca³kowitych int, char itp.
#include <float.h>          // Max i Min wartoœci typów zmiennoprzecinkowych float itp.
#include <stdint-gcc.h>     //zmienne uint8_t itp.
#include <stdbool.h>        // typ bool, true, false
#include <inttypes.h>       // np.                <--- zawiera stdint.h
#include <stdlib.h>         // np. exit() rand() srand() malloc() realloc() calloc() free()
#include <time.h>           //
#include <iso646.h>         //  &&  --->  and    || --->  or   ! ---> not

#include <stdio.h>          // np. printf() scanf() putchar() getchar() <--- zawiera <stddef.h>  EOF
#include <stddef.h>         // np. NULL
#include <string.h>         // np. strcpy ()
#include <ctype.h>          // np. isalpha()
#include <time.h>           //
//#include <iostream>         // C++ std::cin.clear();



#include <math.h>           // np. celi() floor() fabs() pow() sqrt()


#include "JCACP.h"
//#include "czescb.h"
//#include "Stale.h"
//#include "Zmienne.h"
//#include "JCSP.h"
//#include "hotel.h"
//#include "Wskazniki.h"


//#define CURRENTYEAR 2017
//#define wielkoscTab 5

//EOF <--- ctrl + z

// #include <cstdio>
// #include <windows.h>
// #include <clocale>


int main (){                     //int main(int argc, char *argv[])  main() == int main(void) ?   {
//system ("chcp 28591");  (8859-1)
//system("chcp 65001"); // 65001 – UTF-8 Unicode
//system ("chcp 28592"); // 28592 – ISO-8859-2
system("chcp 1250");  //CP1250 windows1250
//setlocale(LC_CTYPE, ".1250");
//setlocale(LC_ALL, "Polish");



        jcacp();
        //jcpdp();
        //getchar();
        //wskazniki();
        //JCSP();
        //zmienne();
        //printf ("\nZa¿ó³æ gêœl¹ jaŸñ\n");
printf("\a");
return 0;
}











