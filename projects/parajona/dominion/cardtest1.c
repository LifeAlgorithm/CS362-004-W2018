#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main (int argc, char** argv)
{
    printf("\nCard test 1: Smithy\n");
    
    struct gameState G;

    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};

    initializeGame(2, k, 5, &G);
    int expectedHandCountPlayer1 = 7;
    int expectedHandCountPlayer2 = 7;
    G.hand[0][0] = smithy;
    G.hand[1][0] = smithy;

    cardEffect(smithy, 0, 0, 0, &G, 0, 0);

    if (G.handCount[0] == 7){
        printf("Test - Player 1 has correct hand count after playing smithy: PASSED\n");
    }
    else
    {
        printf("Test - Player 1 has correct hand count after playing smithy: FAILED\n");
    }

    cardEffect(smithy, 0, 0, 0, &G, 0, 0);

    if (G.handCount[1] == 7){
        printf("Test - Player 1 has correct hand count after playing smithy: PASSED\n");
    }
    else
    {
        printf("Test - Player 2 has correct hand count after playing smithy: FAILED\n");
    }

    printf("Tests for Card test 1 complete.\n");
}

