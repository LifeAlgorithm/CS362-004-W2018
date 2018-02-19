#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "stdio.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main (int argc, char** argv){
    printf("Random test 2: Council room\n");

    srand(time(NULL));

    struct gameState G;
    int k[10] = {adventurer, gardens, embargo, council_room, minion, mine, cutpurse, sea_hag, tribute, smithy};

    
    int roundIndex = 0;
    int passCounterPlayer = 0;
    int passCounterOthers = 0;

    for (roundIndex = 0; roundIndex < 2000; roundIndex ++){

        // Choose random number of players between 2 and 4
        
        int randPlayerCount = rand() % 3 + 2;
        
        
        initializeGame(randPlayerCount, k, 5, &G);

        // Player 1 plays council_room
        G.hand[0][0] = council_room;

        int initialHandCount = G.handCount[0];
        int expectedNewHandCount = initialHandCount + 3;
        int expectedNewHandCountOthers = G.handCount[1] + 1;
        
        cardEffect(council_room, 0, 0, 0, &G, 0, 0);


        if (G.handCount[0] == expectedNewHandCount){
             passCounterPlayer++;
        }

        int otherPlayersPass = 1;
        int i;
        for (i = 1; i < randPlayerCount; i++){
            if (G.handCount[i] != expectedNewHandCountOthers){
                otherPlayersPass = 0;
                break;
            }
        }

        if (otherPlayersPass){
            passCounterOthers++;
        }
    }

    printf("%d of 2000 tests passed (Single player card count)\n", passCounterPlayer); 
    printf("%d of 2000 tests passed (Other players card count)\n", passCounterOthers);
}
