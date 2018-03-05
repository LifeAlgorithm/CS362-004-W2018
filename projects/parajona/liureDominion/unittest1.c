#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main (int argc, char** argv)
{
    printf("Unit test 1: isGameOver\n");
    
    struct gameState G;

    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};

    initializeGame(2, k, 5, &G);
    
    if (isGameOver(&G)){
        printf("Test - Game isn't over after initialization: FAILED\n");
    }
    else
    {
        printf("Test - Game isn't over on set up: PASSED\n");
    }

    G.supplyCount[province] = 0;


    if (isGameOver(&G)){
        printf("Test - Game is over after no provinces left: PASSED\n");
    }
    else
    {
        printf("Test - Game is over after no provinces left: FAILED\n");
    }

    printf("Tests for Unit test 1 complete.\n");
    return 0;
}

