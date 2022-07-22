#ifndef STALE_H_INCLUDED
#define STALE_H_INCLUDED

#define KIDS 3
#define FAMILY "Nowakowie"
#define MORTGAGE_RATE 5.15



#endif // STALE_H_INCLUDED





/*

        int ctr;
        int idSearch;
        int found = 0;

        int custID[10] = {313, 453, 502, 101, 892, 475, 792, 912, 343, 633};
        float custBal[10] = {0.00, 45.43, 71.23, 301.56, 9.08, 192.41, 389.00, 229.67, 18.31, 59.54};

        int tempID, inner, outer, didSwap, i;
        float tempBal;

        for(outer = 0; outer < 9; outer++){
            didSwap = 0;
            for (inner = outer; inner < 10; inner++){
                if(custID[inner] < custID[outer]){
                    tempID = custID[inner];
                    tempBal = custBal[inner];
                    custID[inner] = custID[outer];
                    custBal[inner] = custBal[outer];
                    custID[outer] = tempID;
                    custBal[outer] = tempBal;
                    didSwap = 1;
                }
            }
            if(didSwap == 0) break;
        }

        printf("\n\n *** Sprawdzanie salda klienta ***\n");
        printf("Podaj numer klienta do sprawdzenia: ");
        scanf(" %d",&idSearch);

        for(ctr=0; ctr<10; ctr++){
            if(idSearch == custID[ctr]){
                found = 1;
                break;
            }
            if(custID[ctr] > idSearch) break;
            }

        if(found){
            if(custBal[ctr] > 100){
                printf("\n ** Przekroczone saldo");
            }else printf("\n ** Można udzielić kredytu");
        }else printf("\n ** Nie ma takiego klienta");
*/









/*
int ctr, inner, outer, didSwap, temp;
     int nums[wielkoscTab];
     time_t t;

     srand(time(&t));

     for(ctr=0; ctr<wielkoscTab; ctr++){
        nums[ctr] = (rand() % 99) + 1;
     }

     puts("\nLista przed sortowaniem:");
     for(ctr=0; ctr<wielkoscTab; ctr++){
        printf("%d\n", nums[ctr]);
     }

     for(outer=0; outer<(wielkoscTab-1);outer++){
        didSwap = 0;
        for(inner = outer; inner < wielkoscTab; inner++){
            if(nums[inner] > nums[outer]){
                temp = nums[inner];
                nums[inner] = nums[outer];
                nums[outer] = temp;
                didSwap = 1;
            }
        }
        if(didSwap == 0) break;
     }

     puts("\nPosortowane:");
     for(ctr=0; ctr<wielkoscTab; ctr++){
        printf("%d\n", nums[ctr]);
     }
*/




/*
int gameScores[10] = {12, 5, 21, 15, 32, 10, 6, 31, 11, 10};
     int gameRebounds[10] = {5, 7, 1, 5, 10, 3, 0, 7, 6, 4};
     int gameAssists[10] = {2, 9, 4, 3, 6, 1, 11, 6, 9, 10};
     int bestGame = 0;
     int gmMark = 0;
     int i;

     for (i=0; i<10; i++){
        if(gameScores[i] > bestGame){
            bestGame = gameScores[i];
            gmMark = i;
        }
     }

     printf("\n\nStatystyki z najlepszego meczu gracza:\n");
     printf("Najlepszy był mecz #%d\n", gmMark+1);
     printf("\n\n\n Test !!! gmMark = %d (powinien być -1 od meczu)\n\n\n", gmMark);
     printf("Liczba punktów: %d\nLiczba zbiórek: %d\nLiczka asyst %d\n",gameScores[gmMark], gameRebounds[gmMark], gameAssists[gmMark]);
*/




/*
   int ctr;
        int idSearch;
        int found = 0;

        int custID[10] = {313, 453, 502, 101, 892, 475, 792, 912, 343, 633};
        float custBal[10] = {0.00, 45.43, 71.23, 301.56, 9.08, 192.41, 389.00, 229.67, 18.31, 59.54};

        printf("\n\n ***Sprawdzanie salda klienta***\n");
        printf("Podaj numer klienta, którego chcesz sprawdzić: ");
        scanf(" %d", &idSearch);

        for (ctr=0; ctr<10; ctr++){
            if(idSearch == custID[ctr]){
                found = 1;
                break;
            }
        }
        if (found){
            if(custBal[ctr] > 100.00){
                printf("\n Saldo tego klienta wynosi %.2f zł.\nNie można udzielić dodatkowego kredytu\n", custBal[ctr]);
            }else{
                printf("**Można udzielić kredytu!\n");
            }
        }else{
            printf("**Nie ma klienta o takim ID. Szukane ID = %d\n", idSearch);
        }
*/





/*
  int gameScores[10] = {12, 12, 12, 12, 12, 12};
        int totalPoints = 0;
        int i;
        float avg;

        for (i=0; i <= 9; i++){
            printf("b[%d] = %d\n", i, gameScores[i]);
        }

        for (i=6; i < 10; i++){
            printf("Ile punktów gracz zdobył w meczu nr %d? ", i+1);
            scanf(" %d", &gameScores[i]);
        }

        for (i=0; i<10; i++){
            totalPoints += gameScores[i];
        }
        for (i=0; i <= 9; i++){
            printf("b[%d] = %d\n", i, gameScores[i]);
        }
        printf("totalPoints = %d\n", totalPoints);

        avg = ((float)totalPoints/10);
        printf("\n\nŚrednia liczba punktów wynosi %.1f.\n", avg);
*/











/*
       int dice1, dice2;
       int total1, total2;
       time_t t;
       char ans;
       char dalsza_gra;

       srand(time(&t));

       dice1 = (rand() % 5) + 1;
       dice2 = (rand() % 5) + 1;
       total1 = dice1 + dice2;


       do{
       printf("\n\nW pierwszym rzucie wylosowano liczby %d i %d, ", dice1, dice2);
       printf("których suma wynosi %d.\n\n\n", total1);

       do{
            puts("Czy twoim zdaniem suma punktów w następnym rzucie będzie ");
            puts("(W)yższa, (N)iższa, (T)aka sama?\n");
            puts("Wpisz W, N lub T.");
            scanf(" %c", &ans);
            ans = toupper(ans);
       }while (( ans != 'W') && (ans != 'N') && (ans != "T"));

       dice1 = (rand() % 5) + 1;
       dice2 = (rand() % 5) + 1;
       total2 = dice1 + dice2;
       printf("Druga wylosowana liczba to: %d\n", total2);

       if (ans == 'N'){
            if(total2 < total1){
                printf("Wygrałeś, jest mniejsza");
            } else{
                printf("Przegrałeś, jest większa");
            }
       }else if (ans == 'W'){
            if(total2 > total1){
                printf("Wygrałeś, jest większa");
            } else {
                printf("Przegrałeś, jest mniejsza");
            }
       }else if (ans == 'T'){
            if(total1 == total2){
                printf("Wygrałeś, takie same");
            }else{
                printf("Przegrałeś, są inne");
            }
       }
       printf("\nGrasz dalej? (T/N)\n");
       getchar();
       dalsza_gra = getchar();
       dalsza_gra = toupper(dalsza_gra);
       }while (dalsza_gra == 'T');
*/






















/*
 printf("Czas na odrobienie lekcji z matematyki!\n");

       // printf("Sekcja 1.: pierwiastek kwadratowy\n");
        printf("Pierwiastek kwadratowy z 49.66 wynosi %.4f\n", sqrt(49.66));

        printf("34 podniesione do potęgi 6 wynosi %.4f\n", pow(34,6));

        printf("cos kąta 60 stopni wynosi %.4f\n", cos((60*(3.114159/180))));

        printf("e do potęgi 2 wynosi %.4f\n", exp(2));

*/


/*
char city[15];
       char st[3];
       char fullLocation[18] ="";

       puts("Gdzie mieszkasz? ");
       gets(city);
       puts("W jakim województwie leży ta miejscowość (podaj 2 literowy skrót) ?");
       gets(st);

       strcat(fullLocation, city);
       strcat(fullLocation, ", ");
       strcat(fullLocation, st);

       puts("\nMieszkasz w: ");
       puts(fullLocation);
*/



/*
 int i;
        int hasUpper, hasLower, hasDigit;
        char user[25], password[25];

        hasUpper = hasLower = hasDigit = 0;

        printf("Podaj swoją nazwę użytkownika.");
        scanf(" %s", user);
        printf("Wpisz hasło: ");
        scanf(" %s", password);

        for (i =0; i < strlen(password); i++){
            if(isdigit(password[i])){
                hasDigit = 1;
                continue;
            }
            if(isupper(password[i])){
                hasUpper = 1;
                continue;
            }
            if(islower(password[i])){
                hasLower = 1;
            }
        }

        if ((hasDigit) && (hasUpper) && (hasLower)){
            printf("\n\nŚwietnie, %s,\n", user);
            printf("Twoje hasło zawiera wielkie litery, małe litery i cyfry");
        }else{
            printf("Popraw hasło");
        }
*/



/*
 char firstInit;
        char lastInit;

        printf("Podaj swoje inicjały: ");
        firstInit = getch();
        putch(firstInit);
        lastInit = getch();
        putch(lastInit);

        printf("\nTwoje inicjały: %c.%c.\n",firstInit, lastInit);
*/


/*
            int i;
            char msg[25];

            printf("Wpisz maksymalnie 25 znaków i naciśnij Enter...\n");
            for (i = 0; i < 25; i++){
                    msg[i] = getchar();
                    if (msg[i] == '\n'){
                           i--;
                           break;
                    }
            }
            putchar('\n');
            for (;i >= 0; i--){
                putchar(msg[i]);
            }
            putchar('\n');
*/



/*       int i;
        char msg[] = "Język C jest fajny.";

        for(i = 0; i < strlen(msg); i++){
            putchar(msg[i]);
        }
        putchar('\n');
*/






/*
 int choice1;
        int choice2;

        printf("Wybierz dekadę.\n");
        printf("1. Lata 1980\n");
        printf("2. Lata 1990\n");
        printf("3. Lata 2000 (BRAK) \n");
        printf("4. Zakończ\n");

        do{
            printf("Wpisz swój wybór: ");
            scanf(" %d", &choice1);
            switch (choice1){
            case (1):{
                printf("\n\nJaki temat Cie interesuje?\n");
                printf("1. Baseball\n");
                printf("2. Filmy\n");
                printf("3. Prezydenci USA\n");
                printf("4. Zakończ\n");
                printf("Wpisz swój wybór: ");
                scanf(" %d", &choice2);
                if (choice2 == 1){
                    printf("Mistrzowie World Series 1980: Philadelphia Phillies\n");
                    break;
                }else if (choice2 == 2){
                    printf("Filmy nagrodzone oscarami 1980: Zwyczajni ludzie ");
                    break;
                }else if (choice2 == 3){
                    printf("Prezydenci USA z lat 1980 Jimmy Carter\n");
                    break;
                }else if (choice2 == 4){
                    exit(1);
                }else {
                    printf("Pocipiłeś wybór");
                    break;
                }
             }
            case (2):{
                printf("\n\nJaki temat Cie interesuje?\n");
                printf("1. Baseball\n");
                printf("2. Filmy\n");
                printf("3. Prezydenci USA\n");
                printf("4. Zakończ\n");
                printf("Wpisz swój wybór: ");
                scanf(" %d", &choice2);
                if (choice2 == 1){
                    printf("Mistrzowie World Series 1990: Cincinnati Reds\n");
                    break;
                }else if (choice2 == 2){
                    printf("Filmy nagrodzone oscarami 1990: Taśczący z Wilkami ");
                    break;
                }else if (choice2 == 3){
                    printf("Prezydenci USA z lat 1990 George Bush\n");
                    break;
                }else if (choice2 == 4){
                    exit(1);
                }else {
                    printf("Pocipiłeś wybór");
                    break;
                }
            }
            case (3): break;
            case (4): exit(1);
            default:    printf("Nie ma takiej opcji, spróbuj jeszcze raz");
                        break;
            }
        }while ((choice1 < 1) || (choice1 > 4));
*/





/*
    int choice;

    printf("Co chcesz zrobić?\n");
    printf("1. Dodać nowy kontakt \n");
    printf("2. Edytować istniejący kontakt\n");
    printf("3. Zadzwonić\n");
    printf("4. Wysłać SMS\n");
    printf("5. Zamknąć program\n");

    do{
        printf("Wpisz wybraną opcję: ");
        scanf(" %d", &choice);
        switch (choice){
            case (1):   printf("Kontakt dodany\n");
                        break;
            case (2):   printf("Edytowany\n");
                        break;
            case (3):   printf("Zadzwoniłeś\n");
                        break;
            case (4):   printf("SMS wysłany\n");
                        break;
            case (5):   printf("Good Bay\n");
                        exit(1);
            default:    printf("Porypało CI się coś\n");
                        break;
        }
    }while (( choice <1 ) || (choice > 5 ));
*/


/*
int i;

    for(i = 1; i <= 10; i++){
        if((i%2) == 1){
            printf("%d Jestem nieparzysta...\n", i);
            continue;
        }
        printf("%d Jestem parzysta!\n", i);
    }
*/


/*
int numTest;
    float stTest, avg, total = 0.0;

    for (numTest = 0; numTest < 25; numTest++){
        printf("\nPodaj kolejną ocenę.");
        scanf(" %f", &stTest);
        if (stTest < 0.0){
            break;
        }
        total += stTest;
    }
    avg = total / numTest;
    printf("\nŚrednia ocena wynosi %.1f%%.\n", avg);
*/




/*   int ctr, numMovies, rating, favRating, leastRating;
       char movieName[40], favorite[40], least[40];

       favRating = 0;
       leastRating = 10;

       do{
        printf("Ile filmów obejrzałaś w tym roku? ");
        scanf(" %d", &numMovies);
        if (numMovies < 1){
                printf("Nie oglądasz filmów! Jakim cudem możesz je oceniać?\n");
                printf("Spróbuj jeszcze raz!\n\n");
                }
       } while (numMovies < 1);

       for (ctr = 1; ctr <= numMovies; ctr++){
        printf("\nPodaj tytuł filmu ");
        scanf(" %s", movieName);
        printf("\nOcena ");
        scanf(" %d", &rating);

        if (rating > favRating){
            strcpy(favorite, movieName);
            favRating = rating;
        }
        if (rating < leastRating){
            strcpy(least, movieName);
            leastRating = rating;
        }
       }
       printf("\nNajbardziej podobał Ci się Film: %s.\n", favorite);
       printf("\nNajbardziej nie podobał Ci się Film: %s.\n", least);
*/





/*
 float num1, num2, result;
        char choise;

        do{
            printf("Wpisz pierwszą liczbę do pomnożenia: ");
            scanf(" %f", &num1);
            printf("Wpisz drugą liczbę do pomnożenia: ");
            scanf(" %f", &num2);

            result = num1 * num2;
            printf("%.2f * %.2f = %.2f\n\n", num1, num2, result);
            printf("Koniec ? (T/N)");
            scanf(" %c", &choise);
            if (choise == 't'){
                choise = 'T';
            }

        }while (choise != 'T');
*/







/*
int ctr = 0;
        while (ctr < 5){
            printf("Wartość licznika wynosi %d.\n", ++ctr);
        }

        while (ctr > 1){
            printf("Wartość licznika wynosi %d.\n", -- ctr);
        }
*/


/*
int tablica[10];
    int a=1;
    tablica[0] = "Pizdu mać bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb\n";
    tablica[1] = "drugi wpis\n";
    printf(tablica[0]);
    printf(tablica[1]);
    printf("int %d bajtów \n",sizeof(a));
    printf("Rozmiar łańcucha %d\n", sizeof(tablica));
    printf("Długość łańcucha %d\n", strlen(tablica));
*/


/*
int a = 1,b = 2,c = 3;
    printf("a = %d\n",a);
    printf("(++a) = %d\n",a++);
    printf("a = %d\n",a);
*/

/*
  int numPick;
    printf("Podaj liczbę z przedziału 1 do 100\n");
    scanf(" %d", &numPick);

    printf("\n%d %s bez reszty przez 2.", numPick, (numPick % 2 == 0) ? ("dzieli się") : ("nie dzieli się"));
    printf("\n%d %s bez reszty przez 3.", numPick, (numPick % 3 == 0) ? ("dzieli się") : ("nie dzieli się"));
*/

/*
    unsigned char ans;
    printf("tak czy nie T/N:\n");
    scanf(" %c", &ans);
    if((ans == 'N') || (ans == 'T')){
        if(ans == 'N'){
            printf("Skoro Nie to włącz");
        }
    }else{
        printf("naucz się czytać i pisać");
    }
*/




/*
    int planets = 8;
        int friends = 6;
        int potterBooks = 7;
        int starWars = 6;
        int months = 12;
        int beatles = 4;
        int avengers = 6;
        int baseball = 9;
        int basketball = 5;
        int football = 11;

        if ((friends + beatles >= baseball) && (friends + avengers >= baseball)){
            printf("Z fri i bea oraz z fri i ave można zbudować drużynę baseball");
        }else {
            printf("Ni huja");
        }
        if ((starWars <= months) || (potterBooks <= months)){
            printf("starwars albo potter masz na 1 rok");
        }else{
            printf("ni ciula braknie filmu albo książki");
        }
        if (!(baseball + basketball > football)){
            printf("łącznie jest mniej graczy");
        }else{
            printf("łącznie jest więcej graczy");
        }
*/





/*
     int yearBorn, age;
     printf("Podaj rok urodzenia\n");
     scanf(" %d", &yearBorn);
     age = CURRENTYEAR - yearBorn;

     if(age >= 60){
         printf("Jesteś stary, masz %d\n", age);
     }else if (age >= 40){
         printf("Będzie Ci biło, masz %d\n", age);
     }else if (age >= 30){
         printf("Twój czas ! masz %d\n", age);
     }else printf("Szczyl !");
*/


/*
   int grade1, grade2, grade3, grade4;
        float averageGrade, gradeDelta, percentDiff;

        grade1 = grade3 = 88;
        grade2 = 79;

        printf("Ile procent zdobyłeś na ostatnim teście?\n");
        printf("Liczba całkowita z przedziału od 0 do 100 ");
        scanf(" %d", &grade4);

        averageGrade = (grade1+grade2+grade3+grade4)/4;
        printf("Twoja średnia wynosi %.1f.\n", averageGrade);

        gradeDelta = 95 - averageGrade;
        percentDiff = 100 * ((95-averageGrade)/95);
        printf("Twoja ocena jest o %.1f punktów niższa od", gradeDelta);
        printf("najwyrzszejoceny w klasie (95)\n");
        printf("Twój wynik jest o %.1f procent gorszy ", percentDiff);
        printf("od tamtego wyniku!\n\n\n\n");
*/




/*
#include "Stale.h"


int main()
{
system("chcp 65001");
#define SALESTAX .07
        int numTires;
        float tirePrice, beforeTax, netSales;

        printf("Ile opon kupiłeś? ");
        scanf(" %d", &numTires);
        printf("Ile kosztowała jedna opona (Wpisz dane w formacie $xx.xx)?");
        scanf(" %f", &tirePrice);

        beforeTax = tirePrice * numTires;
        netSales = beforeTax + (beforeTax * SALESTAX);
        printf("Na opony wydałeś $%.2f\n\n\n\n", netSales);
*/









/*
 float a = 19.0;
        float b = 5.0;
        float floatAnswer;

        int x = 19;
        int y = 5;
        int intAnswer;

        floatAnswer = a/b;
        printf("zmiennoprzecinkowe %.2f\n", floatAnswer);

        floatAnswer = (float) x/y;
        printf("drugi wynik %.2f\n", floatAnswer);

        intAnswer = a / b;
        printf("trzeci %.2f\n", intAnswer);

        intAnswer = x % y;
        printf("modulo %d\n", intAnswer);
*/


/*
char topping[24];
      int slices;
      int month, day, year;
      float cost;

      printf("Ile kosztuje pizza w Twojej okolicy? ");
      printf("Wpisz wartość w formacie $XX.XX. \n");
      scanf(" $%f", &cost);

      printf("Jaki jest Twój ulubiony rodzaj pizzy? Wpisz tylko jedno słowo.\n");
      scanf(" %s", topping);
      printf("Ile kawałków pizzy %s ", topping);
      printf("dasz rady zjeść naraz ?\n");
      scanf(" %d", &slices);

      printf("Podaj dzisiejsza datę w formacie XX.XX.XX. \n");
      scanf(" %d.%d.%d", &day, &month, &year);

      printf("\n\nMoże zjesz obiad dnia %d.%d.%d", month, day, year);
      printf("\n i pochłoniesz %d kawałków pizzy %s!\n", slices, topping);
      printf("Będzie Cię to kosztować $%.2f!\n\n\n", cost);
*/

/*
 char firstInitial;
        char lastInitial;
        int age;
        int favorite_number = 0;

        printf("Jaka jest pierwsza litera Twojego imienia?\n");
        scanf(" %c", &firstInitial);

        printf("Jaka jest pierwsza litera Twojego nazwiska?\n");
        scanf(" %c", &lastInitial);

        printf("Ile masz lat?\n");
        scanf(" %d", &age);

        printf("Jaka jest Twoja ulubiona liczba? \n");
        scanf(" %d", &favorite_number);

        printf("\nTwoje inicjały to %c.%c i masz %d lat.", firstInitial, lastInitial, age);
        printf("\nTwoja ulubiona liczba to %d. \n\n", favorite_number);
*/

/*
  uint8_t age;
        char childname[14] = "Tomasz";

        printf("\n%s mają %d dzieci.\n", FAMILY, KIDS);
        age = 11;
        printf("Najstarszy jest %s, który ma %d lat. \n", childname, age);
        strcpy(childname, "Krzysztof");
        //childname = "Krzysztof";
        age = 6;
        printf("Drugi jest %s, który ma %d lat.\n",childname, age);

        age = 5;
        strcpy(childname, "Bartłomiej");
        printf("Najmłodszy jest %s, który ma %d lat. \n", childname, age);
*/
