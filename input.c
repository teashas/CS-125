/*******************************************************************************
*  Saima Teasha
*  CS125
*  HW2
*
*  Write a program that keeps asking the user to supply an integer as input 
*  until the user tells the program to stop by entering a value of q (or any
*  non digitcharacter). After the user enters a q, print out the number of
*  positive integers entered, the number of negative integers entered, and 
*  the sum of all the integers entered.
*******************************************************************************/

#include <stdio.h>

int main() {
    int userInput = 0;
    int numNegative = 0;
    int numPositive = 0;
    int numValue = 0;
    int loop = 0;
    int sum = 0;

    printf("Enter an integer (or  q to quit): ");
    while(scanf("%d", &userInput)) {
        printf("Enter an integer (or  q to quit): ");  
        loop++;
        sum += userInput;
        if(userInput > 0) {
            numPositive++;
        } else if(userInput < 0) {
            numNegative++;
        } else {
            numValue++;
        }
    }
    printf("%d of the integers are positive.\n", numPositive);
    printf("%d of the integers are negative\n", numNegative);
    printf("You entered %d integers.\n", loop);  
    printf("The sum of the %d integers was %d\n", loop, sum);
    return 0;
} 
