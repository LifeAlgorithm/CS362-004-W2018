#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main (int argc, char** argv)
{
    printf("\nUnit test 3: supplyCount \n");
    
    struct gameState G;

    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};

    initializeGame(2, k, 5, &G);
    
    int expectedCopperCount = 60 - (7 * 2);
    int expectedSilverCount = 40;
    int expectedGoldCount = 30;

    int expectedCurseCount = 10;

    int expectedProvinceCount = 8;
    int expectedEstateCount = 8;
    int expectedDuchyCount = 8; 


    if (supplyCount(copper, &G) == expectedCopperCount){
        printf("Test - Game initialized with correct amount of copper: PASSED\n");
    }
    else
    {
        printf("Test - Game initialized with correct amount of copper: FAILED\n");
    }
 
    if (supplyCount(silver, &G) == expectedSilverCount){
        printf("Test - Game initialized with correct amount of silver: PASSED\n");
    }
    else
    {
        printf("Test - Game initialized with correct amount of silver: FAILED\n");
    }

    if (supplyCount(gold, &G) == expectedGoldCount){
        printf("Test - Game initialized with correct amount of gold: PASSED\n");
    }
    else
    {
        printf("Test - Game initialized with correct amount of gold: FAILED\n");
    }

    if (supplyCount(curse, &G) == expectedCurseCount){
        printf("Test - Game initialized with correct amount of curses: PASSED\n");
    }
    else
    {
        printf("Test - Game initialized with correct amount of curses: FAILED\n");
    }

    if (supplyCount(province, &G) == expectedProvinceCount){
        printf("Test - Game initialized with correct amount of provinces: PASSED\n");
    }
    else
    {
        printf("Test - Game initialized with correct amount of provinces: FAILED\n");
    }

    if (supplyCount(estate, &G) == expectedEstateCount){
        printf("Test - Game initialized with correct amount of estates: PASSED\n");
    }
    else
    {
        printf("Test - Game initialized with correct amount of estates: FAILED\n");
    }

    if (supplyCount(duchy, &G) == expectedDuchyCount){
        printf("Test - Game initialized with correct amount of duchies: PASSED\n");
    }
    else
    {
        printf("Test - Game initialized with correct amount of duchies: FAILED\n");
    }
    printf("Tests for Unit test 3 complete.\n");
}

