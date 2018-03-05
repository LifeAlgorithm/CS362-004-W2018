#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main (int argc, char** argv)
{
    printf("\nCard test 3: Village\n");
    
    struct gameState G;

    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};

    initializeGame(2, k, 5, &G);

    G.hand[0][0] = village;

    cardEffect(village, 0, 0, 0, &G, 0, 0);


    if (G.handCount[0] == 5){
        printf("Test - Village results in correct number of cards: PASSED\n");
    }
    else
    {
        printf("Test - Village results in correct number of cards: FAILED\n");
    }
 
    printf("Tests for Card test 3 complete.\n");
    return 0;
}

