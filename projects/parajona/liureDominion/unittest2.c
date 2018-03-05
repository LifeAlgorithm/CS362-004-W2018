#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main (int argc, char** argv)
{
    printf("\nUnit test 2: fullDeckCount\n");
    
    struct gameState G;

    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};

    initializeGame(2, k, 5, &G);
    
    int player1CopperCount = fullDeckCount(0, copper, &G);
    int player2CopperCount = fullDeckCount(1, copper, &G);
   
    int player1EstateCount = fullDeckCount(0, estate, &G);
    int player2EstateCount = fullDeckCount(1, estate, &G);

    if (player1CopperCount == 7){
        printf("Test - Player 1 starts with correct amount of copper: PASSED\n");
    }
    else
    {
        printf("Test - Player 1 starts with correct amount of copper: FAILED\n");
    }

    if (player2CopperCount == 7){
        printf("Test - Player 2 starts with correct amount of copper: PASSED\n");
    }
    else
    {
        printf("Test - Player 1 starts with correct amount of copper: FAILED\n");
    }


    if (player1EstateCount == 3){
        printf("Test - Player 1 starts with correct amount of estates: PASSED\n");
    }
    else
    {
        printf("Test - Player 1 starts with correct amount of estates: FAILED\n");
    }

    if (player2EstateCount == 3){
        printf("Test - Player 2 starts with correct amount of estates: PASSED\n");
    }
    else
    {
        printf("Test - Player 2 starts with correct amount of estates: FAILED\n");
    }

    printf("Tests for Unit test 2 complete.\n");
    return 0;
}

