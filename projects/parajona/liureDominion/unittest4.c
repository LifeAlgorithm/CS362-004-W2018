#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main (int argc, char** argv)
{
    printf("\nUnit test 4: updateCoins\n");
    
    struct gameState G;

    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};

    initializeGame(2, k, 5, &G);
    

    //Check copper coin count
    
    G.handCount[0] = 3;
    int i = 0;
    for (i = 0; i < 3; i++){
        G.hand[0][i] = copper;
    }

    updateCoins(0, &G, 0);
    if (G.coins == 3){
        printf("Test - Correct coins updated for copper: PASSED\n");
    }
    else {
        printf("Test - Correct coins updated for copper: FAILED\n");
    }

    
    for (i = 0; i < 3; i++){
        G.hand[0][i] = silver;
    }

    updateCoins(0, &G, 0);
    if (G.coins == 6){
        printf("Test - Correct coins updated for silver: PASSED\n");
    }
    else {
        printf("Test - Correct coins updated for silver: FAILED\n");
    }

    
    for (i = 0; i < 3; i++){
        G.hand[0][i] = gold;
    }

    updateCoins(0, &G, 0);
    if (G.coins == 9){
        printf("Test - Correct coins updated for gold: PASSED\n");
    }
    else {
        printf("Test - Correct coins updated for gold: FAILED\n");
    }


    printf("Tests for Unit test 4 complete.\n");
    return 0;
}

