#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//int power(int m, int n);

long long i;


int jcacp(){
    char a;
    printf("char max: \t\t%d\t\t\tmin: %d\t\tbajtów: %d\n", CHAR_MAX, CHAR_MIN, sizeof(char));
    printf("short max: \t\t%d\t\t\tmin: %d\t\tbajtów: %d\n",SHRT_MAX, SHRT_MIN, sizeof(short));
    printf("int max: \t\t%d\t\tmin: %d\tbajtów: %d\n", INT_MAX, INT_MIN, sizeof(int));
    printf("long max: \t\t%d\t\tmin: %d\tbajtów: %d\n", LONG_MAX, LONG_MIN, sizeof(long));


    printf("unsigned char max: \t%d\t\t\tmin: %d\t\t\tbajtów: %d\n",UCHAR_MAX, 0, sizeof(unsigned char));
    printf("unsigned short max: \t%d\t\t\tmin: %d\t\t\tbajtów: %d\n",USHRT_MAX, 0, sizeof(unsigned short));
    printf("unsigned int max: \t%lld\t\tmin: %d\t\t\tbajtów: %d\n", UINT_MAX, 0, sizeof(unsigned int));
    printf("unsigned long max: \t%lld\t\tmin: %d\t\t\tbajtów: %d\n", ULONG_MAX, 0, sizeof(unsigned long));

/*
char tab[500] = {0};
char tabbuf[500]  = {0};
char c;
int i = 0;
int j = 0;
int a = 0;
int b = 0;

    while((c = getchar()) != EOF){
        a++;
        if(a > 9){
            if(c != ' ' && c != '\t'){
                tab[i] = c;
                i++;
                continue;
            }
            if(c == ' '){
                tab[i] = '\n';
                a = 0;
                i++;
                continue;
            }

        }
        tab[i] = c;
        i++;
    }
    printf("%s", tab);
*/


/*
    printf("123456789123456789\n");
    printf("a\ta\ta\n\n");

    while((c = getchar()) != EOF){
        //tabbuf[i] = c;
        //i++;
        if(c == ' '){
            a++;
            continue;
        }
        if(a > 0 && a < 8){
            for(;a > 0; a--){
                tab[i] = ' ';
                i++;
            }
            a = 0;
            //i--;
        }
        if(a > 7 && c != ' '){
            j = a / 7;
            for(;j > 0; j--){
                tab[i] = '\t';
                if(j > 0) i++;
            }
            j = a % 7;
            for(;j > 1; j--){
                tab[i] = ' ';
                if(j > 0) i++;
            }

            //continue;
        }
        //j = a % 7;
        //if(j > 1) i = i - j + 1;
        a = 0;

        //if(c == '\t'){
        //    for(j = 0; j < 7; j++,i++){
        //        tab[i] = ' ';
        //    }
        //continue;
        //}
        tab[i] = c;
        i++;
    }
    printf("%s", tab);
*/




/*
int getline(char s[], int lim){
    int c,i;
    char b[20];
    for(i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; i++)
        b[i] = c;
    if(c == '\n'){
        //i++;
        b[i] = '\0';
    }

    //s[i] = '\0';
    c = 0;
    char x;
    for(i = strlen(b) - 1; i >= 0; i--){
        x = b[i];
        s[c] = x;
        c++;
    }
    s[c] = '\0';
    printf("%s\n", s);
    return c;
}

void copy(char to[], char from[]){
    int i;

    i = 0;
    while((to[i] = from[i]) != '0')
        i++;
}



#define MAXLINE 1000


    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while((len = getline(line, MAXLINE)) > 0 && printf("%d %s", len, line))
        if(len > max){
            max = len;
            copy(longest, line);
        }
    if(max > 0)
        printf("%s", longest);
*/







/*
#define MAXLINE 1000

int getline(char s[], int lim){
    int c,i;
    for(i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;
    if(c == '\n'){
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    return i;
}

void copy(char to[], char from[]){
    int i;

    i = 0;
    while((to[i] = from[i]) != '0')
        i++;
}
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while((len = getline(line, MAXLINE)) > 0)
        if(len > max){
            max = len;
            copy(longest, line);
        }
    if(max > 0)
        printf("%s", longest);
*/



/*
int power(int base, int n){
    int p;
    for(p = 1; n > 0; n--)
        p *= base;
    return p;
}

    int liczba, potega;
    printf("Podaj liczbe i potege:");
    scanf(" %d %d", &liczba, &potega);
    printf("Wynik: %d\n", power(liczba,potega));
*/




/*
#define LOWER -30
#define UPPER 300
#define STEP 5

float zmiana(int celcius){
    return (((9.0/5.0) * (float)(celcius + STEP)) + 32.0);
}


    int celcius;

    printf("Celsjusz \tFahrenheit\n");
    for(celcius = LOWER; celcius < UPPER; celcius + STEP)
        printf("%d\t\t%6.2f\n", celcius += STEP, zmiana(celcius));
*/



/*
    int i;

    for(i = 0; i < 10; i++)
        printf("%d %d %d\n", i, power(2,i), power(-3,i));
*/



/*    int c, i, j;
    int tab[20] = {0};
    i = 0;
    j = 0;
    //c = 0;
    //while((c = getchar()) == EOF) continue;
    while((c = getchar()) != EOF){
        if((c == ' ') || c == 10){
            ++tab[i];
            i = 0;
        }
        if(c != ' ') i++;
        j++;
    }

    printf("S這wa 1 literowe: %d\n", tab[1]);
    printf("S這wa 2 literowe: %d\n", tab[2]);
    printf("S這wa 3 literowe: %d\n", tab[3]);
    printf("S這wa 4 literowe: %d\n", tab[4]);
    printf("S這wa 5 literowe: %d\n", tab[5]);
    printf("S這wa 6 literowe: %d\n", tab[6]);
    printf("S這wa 7 literowe: %d\n", tab[7]);
    printf("S這wa 7 literowe: %d\n", tab[8]);
    printf("S這wa 7 literowe: %d\n", tab[9]);
    printf("S這wa 7 literowe: %d\n", tab[10]);
    printf("S這wa 7 literowe: %d\n", tab[11]);
    printf("S這wa 7 literowe: %d\n", tab[12]);
    printf("S這wa 7 literowe: %d\n", tab[13]);
    printf("S這wa 7 literowe: %d\n", tab[14]);
    printf("S這wa 7 literowe: %d\n", tab[15]);

    getchar();
*/





/*
    int i,c;
    int tab[10] = {0};

    while((c = getchar()) != EOF)
        if(c >= '0' && c <= '9')
            tab[c - '0'] = tab[c - '0'] + 1;


    for(i = 0; i < 10; i++){
        printf("i = %d     %d\n",i, tab[i]);
    }
*/



/*
FILE *fptr;
    int i, c, nl, nt, ns;
    nl = 0;
    ns = 0;
    nt = 0;
    fptr = fopen("d:\\text.txt", "w");

    while((c = getchar()) != EOF){
        if(c == '\t'){
            for(i = 0; i < 2; i++){
                    if(i == 0) {
                            c = 92;
                            putchar(c);
                            fputc(c,fptr);
                    }
                    if(i == 1) {
                            c = 't';
                            putchar(c);
                            fputc(c,fptr);
                    }

            }
        continue;
        }
        putchar(c);
        fputc(c,fptr);

    }
    printf("wierszy:%d\n", nl);
    printf("spacji:%d\n", ns);
    printf("tabulator闚:%d\n", nt);
    fclose(fptr);

    fptr = fopen("d:\\text.txt", "r");
    for(i = 0; i < 100; i++){
        c = fgetc(fptr);
        printf("z pliku %d    %c\n", c, c);
        //if(c < 0) i = 100;
    }
    fclose(fptr);
*/




/*

FILE *fptr;
    fptr = fopen("d:\\text.txt", "w");
    int c, i;
    //printf("Warto EOF: %d\n", EOF);

    for(i = 0; i < 10; i++){
        c = getchar();
        printf("getchar() != EOF:\t\t %d,\t\t c = %d\n", c != EOF, c);
        fputc(c,fptr);
    }
    fclose(fptr);


    fptr = fopen("d:\\text.txt", "r");
    for(i = 0; i < 100; i++){
        c = fgetc(fptr);
        printf("z pliku %d    %c\n", c, c);
        //if(c < 0) i = 100;
    }
    fclose(fptr);
*/

/*
#define LOWER 0
#define UPPER 300
#define STEP 10

    double a = -123456789.123456789;
    printf("%015.2f", a);

    int celcius;
    printf("Fahrenheit \tCelsjusz");
    for(celcius = UPPER; celcius > LOWER; celcius - STEP)
        printf("%d\t\t%6.2f\n", celcius -= STEP, (float)((float)5/9) * ((celcius + STEP) - 32));
*/


/*    int celcius;
    printf("Fahrenheit \tCelsjusz");
    for(celcius = LOWER; celcius < UPPER; celcius + STEP)
        printf("%d\t\t%6.2f\n", celcius += STEP, (float)((float)5/9) * ((celcius + STEP) - 32));





    printf("Celsjusz \tFahrenheit\n");
    for(celcius = LOWER; celcius < UPPER; celcius + STEP)
        printf("%d\t\t%6.2f\n", celcius += STEP, (((9.0/5.0) * (float)(celcius + STEP)) + 32.0) );
*/








return(0);
}
/*
==================================================================================================================================
=================================================================================================================================
*/


/*
int power(int base, int n){
    int i,p;
    p = 1;
    for(i = 1; i <= n; i++)
        p = p * base;
    return p;
}
*/
