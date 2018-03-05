#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "stdio.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main (int argc, char** argv){
    printf("Random test: Adventurer\n");

    srand(time(NULL));

    struct gameState G;
    int k[10] = {adventurer, gardens, embargo, council_room, minion, mine, cutpurse, sea_hag, tribute, smithy};

    
    int roundIndex = 0;
    int passCounterCard1 = 0;
    int passCounterCard2 = 0;

    for (roundIndex = 0; roundIndex < 2000; roundIndex ++){
 
        initializeGame(2, k, 5, &G);

        // Add 10% chance of needing to shuffle
        
        int randNumShuffle = rand() % 10;

        if (randNumShuffle == 0){
             G.deckCount[0] = 0;
        }

        // Player 1 draws a random amount of cards between 1 and 5

        int randDrawNum = rand() % 5 + 1;        
        int i;
        for (i = 0; i < randDrawNum; i++){
            drawCard(0, &G);
        }


        // Player 1 plays adventurer
        G.hand[0][0] = adventurer;        
        cardEffect(adventurer, 0, 0, 0, &G, 0, 0);

        int card1 = G.hand[0][0];
        int card2 = G.hand[0][1];

        //Check for drawn treasure
        if (card1 == copper || card1 == silver || card1 == gold){
            passCounterCard1++;
        }
      
        if (card2 == copper || card2 == silver || card2 == gold){
            passCounterCard2++;
        }
    }

    printf("%d of 2000 tests passed (Card 1 is treasure)\n", passCounterCard1); 
    printf("%d of 2000 tests passed (Card 2 is treasure)\n", passCounterCard2);
    return 0;
}
