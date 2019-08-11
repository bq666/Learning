#include <stdio.h>
#include <stdlib.h>
#include <stdint-gcc.h>

#include "JCPDP_1.h"







void jcpdp(void){

















/*
#define TYPE uint8_t
  TYPE i;
  TYPE a = 0;
  int j;
  for(i = 1; i > a; i++){
    a = i;
  }
  printf("Największa wartość: %d\n", a);
    for(i = 0; i < a; i--){
    a = i;
  }
  printf("Najmniejsza wartość: %d\n", a);




  j = getchar();


  //  if(a > i)
  //  printf("%ld", i);
*/



/*
float gradeAve(float test1, float test2, float test3);

    float grade1, grade2, grade3;
    float average;

    printf("Podaj ocene z 1 testu. ");
    scanf(" %f", &grade1);

    printf("Podaj ocene z 2 testu. ");
    scanf(" %f", &grade2);

    printf("Podaj ocene z 3 testu. ");
    scanf(" %f", &grade3);

    average = gradeAve(grade1, grade2, grade3);

    printf("\nSrednia podanych ocen wynosi %.2f\n", average);
*/




/*    char letter;
    unsigned int i;
    i = 666666666;
    printf("jeszcze raz");
    letter = getchar();
    i = 666;

    fptr = fopen("d:\\text.txt", "w");

    //fputc("Ala ma kotka\n a kotek ma ale\n i hu z tego?\n", fptr);
    for(i = 0; i <= 30000; i++)
        fprintf(fptr, "%c", i );
    fprintf(fptr,"\n\n\nAla ma kotka\n\n\n\n a kotek ma ale\n i hu z tego?\n");
    fprintf(fptr,"ĄĆŹŃąćź\n");
    fclose(fptr);
*/



/*
    int i = 10;
    int ctr;
    float x = 20.5;
    int iAray[] = {10, 20, 30, 40, 50};

    puts("Początkowe wartosci zmiennych z funkcji main():");
    printf("Wartosc i wynosi %d\n", i);
    printf("Wartosc x wynosi %.1f\n", x);

    for(ctr = 0; ctr < 5; ctr++)
        printf("Wartosc iAray[%d] wynosi %d\n", ctr, iAray[ctr]);

    changeSome(i, &x, iAray);

    puts("\n\nWartosci zmiennych z funkcji main() za funkcja zmieniajaca:");
    printf("Wartosc i wynosi %d\n", i);
    printf("Wartosc x wynosi %.1f\n", x);

    for(ctr = 0; ctr < 5; ctr++)
        printf("Wartosc iAray[%d] wynosi %d\n", ctr, iAray[ctr]);
*/


/*
    int i;
    printf("Wpisz liczbe zalkowita...");
    scanf(" %d", &i);
    half(&i);
    printf("W funkcji main() zmienna i ma teraz wartosc %d\n", i);
*/


/*
void change(char name[]){
    strcpy(name,"XXXXXXXXXXXX");
    return;
}

    char name[] = "Michael Hatton";
    printf("%s\n", name);
    change(name);
    printf("%s\n", name);
*/



/*
void half(int);
    int i;
    printf("Wpisz liczbe zalkowita ...");
    scanf(" %d", &i);
    half(i);

    printf("W funkcji main() zmienna i nadal ma wartosc %d.\n", i);
*/

/*
int g1 = 10; // globalnie !!!
void prAgain(int l2);

    float l1 = 9.0;
    printf("%d %.2f\n", l1, g1);
    prAgain(1); <--- na dole
*/



/*
    FILE *fptr;


    char letter;
    int i;

    fptr = fopen("d:\\text.txt", "r+");
    if(fptr == 0){
        printf("Wystapil blad podczas otwierania pliku.\n");
        exit(1);
    }
    printf("podaj numer litery, ktora chcesz zmienic (1-26).");
    scanf(" %d", &i);

    fseek(fptr, (i - 1), SEEK_SET);
    fputc('*', fptr);

    fseek(fptr, 0, SEEK_SET);
    printf("Aktualna:\n");
    for(i = 0; i < 26; i++){
        letter = fgetc(fptr);
        printf("Nastepna litera to %c.\n", letter);
    }
    fclose(fptr);
*/


/*    char letter;
    int i;
    fptr = fopen("d:\\text.txt", "w+");
    if(fptr == 0){
        printf("Wystąpił błąd otwarcia pliku\n");
        exit(1);
    }
    for(letter = 'A'; letter <= 'Z'; letter++){
        fputc(letter,fptr);
    }

    puts("Zapisano alfabet");

    fseek(fptr, -1, SEEK_END);
    printf("Zawartość pliku wydrukowana wspak:\n");
    for(i = 26; i > 0; i--){
        letter = fgetc(fptr);
        fseek(fptr, -2, SEEK_CUR);
        printf("Nastepna litera to %c.\n", letter);
    }
    fclose(fptr);
*/


/*
    char fileLine[100];
    fptr = fopen("d:\\test.txt", "r");

    if(fptr != 0){
        while(!feof(fptr)){
            fgets(fileLine, 100, fptr);
            if(!feof(fptr)){
                puts(fileLine);
            }
        }
    }else printf("\nBlad otwarcia pliku\n");
    fclose(fptr);
    fptr = fopen("d:\\test.txt", "a");
    //fprintf(fptr,"Dodam nowe pozycje\n");
    fclose(fptr);
*/






/*
#define ILOSC_B 1

        int ctr;
    struct bookInfo books[ILOSC_B];//81.54 KB

    for(ctr = 0; ctr < ILOSC_B; ctr++){
        printf("Podaj tytuł ksiazki nr %d.",(ctr + 1));
        gets(books[ctr].title);
        puts("Kto jest autorem? ");
        gets(books[ctr].author);
        puts("Ile zlotych kosztowala ta ksiazka? ");
        scanf(" %f", &books[ctr].price);
        puts("Ile stron ma ta ksiazka? ");
        scanf(" %d", &books[ctr].pages);
        getchar();
    }

    printf("\n\nOto Twoja kolekcja ksiazek: \n");
    for(ctr = 0; ctr < ILOSC_B; ctr++){
        printf("Nr: %d. Tytul: %s. Autor: %s.", (ctr + 1), books[ctr].title, books[ctr].author);
        printf("\nLiczba stron: %d. Cena %.2f.\n\n", books[ctr].pages, books[ctr].price);

    }

    fptr = fopen("d:\\test.txt", "w");
    if(fptr == 0){
        printf("Błąd - nie udalo sie owtorzyc pliku.\n");
        exit(1);
    }

    fprintf(fptr, "\n\nOto Twoja kolekcja książek.\n");
    for(ctr = 0; ctr < ILOSC_B; ctr++){
        fprintf(fptr,"Nr: %d. Tytuł: %s. Autor: %s.",(ctr + 1), books[ctr].title, books[ctr].author);
        fprintf(fptr,"\nLiczba stron: %d. Cena: %.2f", books[ctr].pages, books[ctr].price);
        fprintf(fptr,"\n\n");
    }

    fclose(fptr);
    printf("TEST TEST");
*/

/*
    int ctr;
    struct bookInfo *books[3];

    for(ctr = 0; ctr < 3; ctr++){
        books[ctr] = (struct bookInfo*)malloc(sizeof(struct bookInfo));
        printf("Podaj tytuł ksiazki nr %d.",(ctr + 1));
        gets(books[ctr]->title);
        puts("Kto jest autorem? ");
        gets(books[ctr]->author);
        puts("Ile zlotych kosztowala ta ksiazka? ");
        scanf(" %f", &books[ctr]->price);
        puts("Ile stron ma ta ksiazka? ");
        scanf(" %d", &books[ctr]->pages);
        getchar();
    }

    printf("\n\nOto Twoja kolekcja ksiazek: \n");
    for(ctr = 0; ctr < 3; ctr++){
        printf("Nr: %d. Tytul: %s. Autor: %s.", (ctr + 1), books[ctr]->title, books[ctr]->author);
        printf("\nLiczba stron: %d. Cena %.2f.\n\n", books[ctr]->pages, books[ctr]->price);

    }
*/


/*
void jcpdp(void){

    int ctr;
    struct bookInfo books[3];//81.54 KB

    for(ctr = 0; ctr < 3; ctr++){
        printf("Podaj tytuł ksiazki nr %d.",(ctr + 1));
        gets(books[ctr].title);
        puts("Kto jest autorem? ");
        gets(books[ctr].author);
        puts("Ile zlotych kosztowala ta ksiazka? ");
        scanf(" %f", &books[ctr].price);
        puts("Ile stron ma ta ksiazka? ");
        scanf(" %d", &books[ctr].pages);
        getchar();
    }

    printf("\n\nOto Twoja kolekcja ksiazek: \n");
    for(ctr = 0; ctr < 3; ctr++){
        printf("Nr: %d. Tytul: %s. Autor: %s.", (ctr + 1), books[ctr].title, books[ctr].author);
        printf("\nLiczba stron: %d. Cena %.2f.\n\n", books[ctr].pages, books[ctr].price);

    }
*/



//printf ("\nZażółć gęślą jaźń\n");
return;
}



/*
=================================================================================================================================
changeSome(int i,float *newX,int iAray[5]);
changeSome(int i,float *newX,int iAray[5]){
    int j;
    i = 47;
    *newX = 97.6;
    for(j = 0; j < 5; j++)
        iAray[j] = 100 + 100*j;
    return;
}

*/




/*
float gradeAve(float test1, float test2, float test3){
    return ((test1 + test2 + test3) / 3);
}
*/

/*
void half(int *i){
    *i /= 2;
    printf("Polowa podnej wartosci to %d\n", *i);

}
*/

/*
float g2 = 19.0;

void prAgain(int l2){
    l2 = 5;
    printf("%d %.2f %d\n", l2, g2, g1);
}
*/
