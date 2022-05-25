/*******************************************************************************
*  Saima Teasha
*  CS125
*  program HW4
*
*  The project in this assignmentis to build a text-only(pseudo-video)
*  slot machine. Each wheel has a set of pictures painted on the outside. 
*  During play, each wheel spins independently and comes to stop with one 
*  of its pictures showing in a window. The player wins if all three images 
*  are the same.
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int getRandomInteger(int smallestInteger, int largestInteger) {

    /* This function is used to generate a random integer. */

    int rangeOfInteger = 1 + largestInteger - smallestInteger;
    double normalizedRand = rand() / (RAND_MAX + 1.0);
    return (int)(normalizedRand * rangeOfInteger + smallestInteger);
}

void printWheelImage(int rand) {

    /* This function takes a random integer and changes it into a
       string, depending on what the random number is.             */

    if (rand == 1) {
        printf("   cherries    ");
    } else if(rand == 2) {
        printf("    lemon      ");
    } else if (rand == 3) {
        printf("    peach      ");
    } else if (rand == 4) {
        printf("    seven      ");
    } else {
        printf("     bell      ");
    }
}

int printLosingGame(int randOne, int randTwo, int randThree) {

    /* Takes in three arguments into the function  and calls on the printWheelImage.
       printWheelImage take the three integer arguments and changes it into strings
       before plotting the slot. printWheelimage is called three times to print three 
       columns. */
    
    printWheelImage(randOne);
    printWheelImage(randTwo);
    printWheelImage(randThree);
    printf("\n");
    return 0;
} 

int printWinningGame(int randOne) {

    /* The same function as printLosingGame, but takes in only one argument. This is
       because all three images will be the same when a game is won. */

    printWheelImage(randOne);
    printWheelImage(randOne);
    printWheelImage(randOne);
    printf("You Win\n");
    return 0;
}

void playGame() {
    int randomOne = getRandomInteger(1,4); 
    int randomTwo = getRandomInteger(1,4); 
    int randomThree = getRandomInteger(1,4); 
    /* Slot will print printWinningGame if all three random integers are equal,
       otherwise the slot will print printLosingGame. */ 

    if ((randomOne == randomTwo) && (randomTwo == randomThree)) {
        printWinningGame(randomOne);
    } else {
        printLosingGame(randomOne, randomTwo, randomThree);
    }
}

int main() {
    char userInput;
    printf("Hit enter to play a game (or q to quit): ");
    scanf("%c", &userInput);

    /* Play a game everytime userInput reads a new line. Close the code if the user 
       types any integer or letter. */ 

    while (userInput == '\n') {   
        playGame();  
        scanf("%c", &userInput);
   }
    return 0;
}

