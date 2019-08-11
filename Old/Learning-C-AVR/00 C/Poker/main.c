#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

void printGreeting();
int getBet();
char getSuit(int suit);
char getRank(int rank);
void getFirstHand(int cardRank[],int cardSuit[]);
void getFinalHand(int cardRank[], int cardSuit[], int finalRank[], int finalSuit[], int ranksinHand[], int suitsinHand[]);
int analyzeHand(int ranksinHand[], int suitsinHand[]);

int main(){
system("chcp 65001");

    int bet;
    int bank = 100;
    int i;
    int cardRank[5];
    int cardSuit[5];
    int finalRank[5];
    int finalSuit[5];
    int ranksinHand[13];
    int suitsinHand[4];
    int winnings;
    time_t t;
    char suit, rank, stillPlay;

    printGreeting();

    do{
        bet = getBet();
        srand(time(&t));
        getFirstHand(cardRank,cardSuit);
        printf("Twoje piêæ kart: \n");
        for(i = 0; i < 5; i++){
            suit = getSuit(cardSuit[i]);
            rank = getRank(cardRank[i]);
            printf("Karta nr %d: %c%c\n", i + 1, rank, suit);
        }
        for(i = 0; i < 4; i++){
            suitsinHand[i] = 0;
        }
        for(i = 0; i < 13; i++){
            ranksinHand[i] = 0;
        }
        getFinalHand(cardRank, cardSuit, finalRank, finalSuit, ranksinHand, suitsinHand);
        printf("Ostateczny zestaw kart: \n");
        for(i = 0; i < 5; i++){
            suit = getSuit(finalSuit[i]);
            rank = getRank(finalRank[i]);
            printf("Karta nr: %d: %c%c\n", i+1, rank, suit);
        }
        winnings = analyzeHand(ranksinHand, suitsinHand);
        printf("Wygra³eœ %d!\n", bet * winnings);
        bank = bank - bet + (bet * winnings);
        printf("\nKwota na koncie: %d.\n", bank);
        printf("\nKolejne rozdanie ? (T/N): ");
        scanf(" %c", &stillPlay);
    }while(toupper(stillPlay) == 'T');
    return 0;
}
