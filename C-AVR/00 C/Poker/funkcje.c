#define FALSE 0
#define TRUE 1

void printGreeting(){
    system("chcp 65001");
    printf("**************************************************************************\n");
    printf("\n\n\tWitaj w kasynie dla programistów - \n\n");
    printf("\t domu elektronicznego pokera dobieranego\n\n");
    printf("**************************************************************************\n");
    printf("Oto zasady gry:\n");
    printf("Na pocz¹tek otrzymujesz 100 kredytów i stawiasz od 1 do 5 kredytów\n");
    printf("Dostajesz 5 kart i wybierasz, które z nich chcesz zatrzymaæ, ");
    printf("a które chcesz wymieniæ.\n");
    printf("D¹¿ysz do otrzymania jak najlepszego uk³adu.\n");
    printf("Oto tabela wygranych, przy za³o¿eniu ¿e postawiono 1 kredyt:");
    printf("\nPara\t\t\t\t1 kredyt");
    printf("\nDwie pary\t\t\t2 kredyty");
    printf("\nTrójka\t\t\t\t3 kredyty");
    printf("\nStrit\t\t\t\t4 kredyty");
    printf("\nKolor\t\t\t\t5 kredytów");
    printf("\nFull\t\t\t\t8 kredytów");
    printf("\nKareta\t\t\t\t10 kredytów");
    printf("\nPoker\t\t\t\t20 kredytów");
    printf("Mi³ej zabawy !!! \n\n");
}


int getBet(){
    int bet;
    do{
        printf("Ile chcesz postawiæ ? (wpisz od 1 do 5 lub 0 koñczy grê): ");
        scanf(" %d", &bet);

        if(bet >= 1 && bet <= 5)
            return(bet);
        else if(bet == 0)
            exit(1);
        else{
            printf("\n\nwpisz od 1 do 5 lub 0 koñczy grê:");
        }
    }while((bet < 0) || (bet > 5));
}

char getSuit(int suit){
    switch(suit){
        case 0:
            return('t');
        case 1:
            return('c');
        case 2:
            return('k');
        case 3:
            return('p');
    }
}

char getRank(int rank){
    switch(rank){
        case 0:
            return('A');
        case 1:
            return('2');
        case 2:
            return('3');
        case 3:
            return('4');
        case 4:
            return('5');
        case 5:
            return('6');
        case 6:
            return('7');
        case 7:
            return('8');
        case 8:
            return('9');
        case 9:
            return('T');
        case 10:
            return('J');
        case 11:
            return('Q');
        case 12:
            return('K');
    }
}

void getFirstHand(int cardRank[],int cardSuit[]){
    int i,j;
    int cardDup;

    for(i = 0; i < 5; i++){
        cardDup = 0;
        do{
            cardRank[i] = (rand() % 13);
            cardSuit[i] = (rand() % 4);
            for(j = 0; j < i; j++){
                if((cardRank[i] == cardRank[j]) && (cardSuit[i] == cardSuit[j])){
                    cardDup = 1;
                }
            }
        }while(cardDup == 1);
    }
}

void getFinalHand(int cardRank[], int cardSuit[], int finalRank[], int finalSuit[], int ranksinHand[], int suitsinHand[]){
    int i, j, cardDup;
    char suit, rank, ans;
    for(i = 0; i < 5; i++){
        suit = getSuit(cardSuit[i]);
        rank = getRank(cardRank[i]);
        printf("Czy chcesz zatrzymaæ kartê nr: %d: %c%c?",i + 1, rank, suit);
        printf("\nWpisz T lub N: ");
        scanf(" %c",&ans);
        if(toupper(ans) == 'T'){
            finalRank[i] = cardRank[i];
            finalSuit[i] = cardSuit[i];
            ranksinHand[finalRank[i]]++;
            suitsinHand[finalSuit[i]]++;
            continue;
        }else if(toupper(ans) == 'N'){
            cardDup = 0;
            do{
                cardDup = 0;
                finalRank[i] = (rand() % 13);
                finalSuit[i] = (rand() % 4);

                for(j = 0; j < 5; j++){
                    if((finalRank[i] == cardRank[j]) && (finalSuit[i] == cardSuit[j]))
                        cardDup = 1;
                }
                for(j = 0; j < i; j++){
                    if((finalRank[i] == finalRank[j]) && (finalSuit[i] == finalSuit[j]))
                        cardDup = 1;
                }
            }while(cardDup == 1);
            ranksinHand[finalRank[i]]++;
            suitsinHand[finalSuit[i]]++;
        }
    }
}

int analyzeHand(int ranksinHand[], int suitsinHand[]){
    int num_consec = 0;
    int i, rank, suit;
    int straight = FALSE;
    int flush = FALSE;
    int four = FALSE;
    int three = FALSE;
    int pairs = 0;

    for(suit = 0; suit < 4; suit++)
        if(suitsinHand[suit] == 5)
            flush = TRUE;
        rank = 0;
        while(ranksinHand[rank] == 0)
            rank++;
        for(;rank < 13 && ranksinHand[rank]; rank++)
            num_consec++;
        if(num_consec == 5){
            straight = TRUE;
        }
        for(rank = 0; rank < 13; rank++){
            if(ranksinHand[rank] == 4)
                four = TRUE;
            if(ranksinHand[rank] == 3)
                three = TRUE;
            if(ranksinHand[rank] == 2)
                pairs++;
        }
        if(straight && flush){
            printf("Poker\n\n");
            return(20);
        }else if(four){
            printf("Kareta\n\n");
            return(10);
        }else if(three && pairs == 1){
            printf("Full\n\n");
            return(8);
        }else if(flush){
            printf("Kolor\n\n");
            return(5);
        }else if(straight){
            printf("Strit\n\n");
            return(4);
        }else if(three){
            printf("Trójka\n\n");
            return(3);
        }else if(pairs == 2){
            printf("Dwie pary\n\n");
            return(2);
        }else if(pairs == 1){
            printf("Para\n\n");
            return(1);
        }else{
            printf("Wysoka karta\n\n");
            return(0);
        }
}
