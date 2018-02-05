#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    int randNum = rand() % 9 + 1;
    switch(randNum){
        case 1:
            return '[';
        case 2:
            return '(';
        case 3:
            return '{';
        case 4:
            return ' ';
        case 5:
            return 'a';
        case 6:
            return 'x';
        case 7:
            return '}';
        case 8:
            return ')';
        case 9:
            return ']';
        default:
            return 'b';
    }
}

char *inputString()
{
   char* returnArray = malloc(6 * sizeof(char));
   int* randArray = malloc(5 * sizeof(int));
   int i = 0;
   for (i = 0; i < 5; i++){
       randArray[i] = rand() % 4 + 1;
   }

   for (i = 0; i < 5; i++){
        int randNum = randArray[i];
        
        if (randNum == 1){
            returnArray[i] = 'r';
        }
        else if (randNum == 2){
            returnArray[i] = 'e';
        }
        else if (randNum == 3){
            returnArray[i] = 's';
        }
        else
        {
            returnArray[i] = 't';
        }
   }

    returnArray[5] = '\0';
    return returnArray;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
