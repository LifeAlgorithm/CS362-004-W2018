#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "stdio.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main (int argc, char** argv){
    printf("Random test 1: Smithy\n");

    srand(time(NULL));

    struct gameState G;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

    
    int roundIndex = 0;
    int passCounter = 0;

    for (roundIndex = 0; roundIndex < 2000; roundIndex ++){

        initializeGame(2, k, 5, &G);


         // Make player 1 draw a random amount of cards between 1 and 10
         int randNum = rand() % 10 + 1;
         int j;
         for (j = 0; j < randNum; j++);{
             drawCard(0, &G);
         }
         G.hand[0][0] = smithy;
         int initialHandCount = G.handCount[0];
         int expectedNewHandCount = initialHandCount + 2;
        
         cardEffect(smithy, 0, 0, 0, &G, 0, 0);
        
         //Check if actual matches expected
         if (G.handCount[0] == expectedNewHandCount){
             passCounter++;
             
         }
    }

    printf("%d of 2000 tests passed\n", passCounter);
    return 0;
}



