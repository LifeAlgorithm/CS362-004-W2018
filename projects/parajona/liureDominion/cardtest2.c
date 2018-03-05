#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main (int argc, char** argv)
{
    printf("\nCard test 2: Adventurer\n");
    
    struct gameState G;

    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};

    initializeGame(2, k, 5, &G);

    G.hand[0][0] = adventurer;

    cardEffect(adventurer, 0, 0, 0, &G, 0, 0);


    //Top 2 cards should be treasure cards

    int card1 = G.hand[0][0];
    int card2 = G.hand[0][1];

    //printf("Card1 : %d, Card2: %d\n", card1, card2);

    if (card1 == copper || card1 == silver || card1 == gold){
        printf("Test - First card correctly draws treasure: PASSED\n");
    }
    else
    {
        printf("Test - First card correctly draws treasure: FAILED\n");
    }
 
    if (card2 == copper || card2 == silver || card2 == gold){
        printf("Test - Second card correctly draws treasure: PASSED\n");
    }
    else
    {
        printf("Test - Second card correctly draws treasure: FAILED\n");
    }

    printf("Tests for Card test 2 complete.\n");
    return 0;
}

