#include <stdio.h>          // np. printf()
#include <string.h>         // np strcpy ()
#include <stdint-gcc.h>     //zmienne uint8_t itp.
#include <inttypes.h>

uint16_t swap_bytes_uint8_t (uint16_t temp){
    printf("zmienna dec:    %#d\n", temp);
    printf("zmienna hex:    %#0.4x\n", temp);
    printf("MSB na LSB dec: %#d\n", (temp<<8) | (temp>>8));
    printf("MSB na LSB hex: %#0.4x\n\n", (temp<<8) | (temp>>8));
return (temp<<8) | (temp>>8);
}


uint16_t zamiana_bitow_uint8_t (uint16_t a){
    static uint16_t wynik;
    static uint16_t maska_a = 0x0001;
    static uint16_t maska_b = 0x8000;
    static int i;
    for (i=0;i<16;i++){
        if(a & maska_a) wynik |= maska_b;
        maska_a<<=1;
        maska_b>>=1;
    }
printf("zmienna dec:                   %d\n", a);
printf("zmienna hex:                   %#0.4x\n", a);
printf("zmiana kolejności bitów a dec: %d\n", wynik);
printf("zmiana kolejności bitów a hex: %#0.4x\n\n", wynik);
return wynik;
}

uint16_t dd_rol(uint16_t a){
    printf("zmienna dec:                   %d\n", a);
    printf("zmienna hex:                   %#0.4x\n", a);
    if(a & 0x8000){
        printf("rolowane w lewo a dec:         %d\n", ((a<<1) | 0x0001));
        printf("rolowane w lewo a hex:         %#0.4x\n\n", (uint16_t)((a<<1) | 0x0001));
        return ((a<<1) | 0x0001);
    }
    printf("rolowane w lewo a dec:         %d\n", (a<<1));
    printf("rolowane w lewo a hex:         %#4.4x\n\n", (a<<1));
    return (a<<1);
}









int main()
{
// system("chcp");
//system("chcp 852");  // Latin-2
//system("chcp 1200"); // UTF-16LE
system("chcp 65001"); // UTF-8


        uint16_t a=0b0000000000000011;
        //  uint8_t b=0b01000100;
        //  int8_t c=0;
        //  int8_t d=0;


        // zamiana_bitow_uint8_t(a);
        // swap_bytes_uint8_t(a);
        uint8_t x;
        for(x=0;x<17;x++){
           a=dd_rol(a);
        }




















printf("Ściemniacz");
printf("\a");
return 0;
}

/*





uint16_t swap_bytes_uint8_t (uint16_t temp){
    printf("zmienna dec:    %#d\n", temp);
    printf("zmienna hex:    %#0.4x\n", temp);
    printf("MSB na LSB dec: %#d\n", (temp<<8) | (temp>>8));
    printf("MSB na LSB hex: %#0.4x\n\n", (temp<<8) | (temp>>8));
return (temp<<8) | (temp>>8);
}


uint16_t zamiana_bitow_uint8_t (uint16_t a){
    static uint16_t wynik;
    static uint16_t maska_a = 0x0001;
    static uint16_t maska_b = 0x8000;
    static int i;
    for (i=0;i<16;i++){
        if(a & maska_a) wynik |= maska_b;
        maska_a<<=1;
        maska_b>>=1;
    }
printf("zmienna dec:                   %d\n", a);
printf("zmienna hex:                   %#0.4x\n", a);
printf("zmiana kolejności bitów a dec: %d\n", wynik);
printf("zmiana kolejności bitów a hex: %#0.4x\n\n", wynik);
return wynik;
}
*/





/*

    char Kid1[12];
    char Kid2[] = "Krysia";
    char Kid3[7] = "Bartek";
    char Hero1[] = "Batman";
    char Hero2[34] = "Spiderman";
    char Hero3[25];

    Kid1[0] = 'B';
    Kid1[1] = 'e';
    Kid1[2] = 'a';
    Kid1[3] = 't';
    Kid1[4] = 'a';
    Kid1[5] = '\0';

   // strcpy(Hero3, "The incredible Hulk");

    printf("%s\ - %s.\n", Kid1, Hero1);
    printf("%s\ - %s.\n", Kid2, Hero2);
    printf("%s\ - %s.\n", Kid3, Hero3);
    */




    /*
    char firstInitial, middleInitial;
    int number_of_pencils;
    int number_of_notebooks;
    float pencils = 0.23;
    float notebooks = 2.89;
    float lunchbox = 4.99;

    firstInitial = 'J';
    middleInitial = 'R';
    number_of_pencils = 7;
    number_of_notebooks = 5;
    printf("%c%c potrzebne %d ołówków, %d zeszytów i jednego pudełka na śniadanie \n",firstInitial,middleInitial,number_of_pencils,number_of_notebooks);
    printf("Cena tych wszystkich rzeczy to %.2f zł\n\n", number_of_pencils*pencils+number_of_notebooks*notebooks+lunchbox);


    firstInitial = 'A';
    middleInitial = 'J';
    number_of_pencils = 10;
    number_of_notebooks = 8;
    printf("%c%c potrzebne %d ołówków, %d zeszytów i jednego pudełka na śniadanie \n",firstInitial,middleInitial,number_of_pencils,number_of_notebooks);
    printf("Cena tych wszystkich rzeczy to %.2f zł\n\n", number_of_pencils*pencils+number_of_notebooks*notebooks+lunchbox);


    firstInitial = 'M';
    middleInitial = 'T';
    number_of_pencils = 9;
    number_of_notebooks = 6;
    printf("%c%c potrzebne %d ołówków, %d zeszytów i jednego pudełka na śniadanie \n",firstInitial,middleInitial,number_of_pencils,number_of_notebooks);
    printf("Cena tych wszystkich rzeczy to %.2f zł\n\n", number_of_pencils*pencils+number_of_notebooks*notebooks+lunchbox);


    */

  /*  printf("ilość towaru\tCena\tSuma\n");
    printf("%d\t\t%.2f zł\t%.2f zł\n", 3, 9.99, 29.97);
    printf("Nie potrzebnych spacji     \b\b\b\b\b można się pozbyć za pomocą ");
    printf("znacznika cytatu \\%c.\n", 'b');
    printf("\n\a\n\n\n\n\nPrzeskakujemy o kilka wierszy i wydajemy ");
    printf("kilka odgłosów. \n\n\n");
    printf("%s %c", "Dobrze Ci idzie nauka.", 'C');
    printf("\nWłaśnie skończyłeś rozdział %d.\nSkończyłeś ", 4);
    printf("%.1f%c książki. \n", 10.500,'%');
    printf("\n\nJedna trzecia do %.2f lub ", 0.333333);
    printf("%.3f lub %.4f lub ", 0.333333, 0.333333);
    printf("%.5f lub % .6f\n\n\n", 0.333333, 0.3333333); */

    /* printf("char %d\n",sizeof(char));
    printf("int %d\n",sizeof(int));
    printf("float %d\n",sizeof(float));
    printf("double %d\n",sizeof(double));
    printf("\a"); */
