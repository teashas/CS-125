/*******************************************************************************
*  Saima Teasha
*  CS125
*  HW3
*
*  Compound and Nested If Statements: This  assignment  is  more  exercise  
*  with  conditional  statements  and  code.  It focuses on the use of else 
*  conditions and conditional blocks. This exercise is designed to show you how
*  you should write large programs by adding a little bit at a time.
*  Note that in going from one step to the next, you may have to rearrange the
*  order of statements in your code from the previous step to make the new part
*  work correctly.You must do these steps one at a time, creating separate copies 
*  of each incrementof progress.
*******************************************************************************/


#include <stdio.h>

int step1() {
    int userInput = 0;

    printf("Enter an integer between 1 and 20: ");
    scanf("%d", &userInput);
    printf("You entered a %d.\n", userInput);
    return 0;
}

int step2() {
    int userInput = 0;

    printf("Enter an integer between 1 and 20: ");
    scanf("%d", &userInput);

    /* If the value is not between 1 and 20, print "The value you entered is not 
       an integer between 1 and 20", otherwise print the userInput. */

    if ((userInput < 1) || (userInput > 20)) { 
        printf("The value you entered is not an integer between 1 and 20.\n");
    } else {
        printf("You entered a %d.\n", userInput);
    }  
    return 0;
}

int step3() {
    int userInput = 0;

    printf("Enter an integer between 1 and 20: ");
    scanf("%d", &userInput);

    /* If userInput is an 8, 11, or 18, then display "You entered an %d" instead of
       "You entered a %d." */

    if ((userInput < 1) || (userInput > 20)) { 
        printf("The value you entered is not an integer between 1 and 20.\n");
    } else if ((userInput == 8) || (userInput == 11) || (userInput == 18)) {
        printf("You entered an %d.\n", userInput);
    } else {
        printf("You entered a %d.\n", userInput);
    }  
    return 0;
}

int step4() {
    int userInput = 0;

    printf("Enter an integer between 1 and 20: ");
    scanf("%d", &userInput);
 
    /* If user inputs a letter, then display the message "Idiot! The number you entered could not 
       be read as an integer. Get a life!" */

    if (userInput < 1) {
        printf("Idiot! The number you entered could not be read as an integer. Get a life!\n");
    } else if ((userInput < 1) || (userInput > 20)) { 
        printf("The value you entered is not an integer between 1 and 20.\n");
    } else if ((userInput == 8) || (userInput == 11) || (userInput == 18)) {
        printf("You entered an %d.\n", userInput);
    } else {
        printf("You entered a %d.\n", userInput);
    }  
    return 0;
}
 
int main() {
    step1();
    step2();
    step3();
    step4();
    return 0;
}
