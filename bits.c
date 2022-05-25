/*******************************************************************************
*  Saima Teasha
*  CS125
*  program HW4
*
*  Ask the user to enter a line of text and then read it in one character at 
*  a time. For each character, print the character as a character, its hex 
*  value, its decimal value, and its binary value. 
*******************************************************************************/

#include <stdio.h>

void printLetter(char c);
void printHex(char c);
void printDecimal(char c);
int printBinary(char c);
void printParity(int bits);
void analyzeChar(char c);

    /* Takes in a line of text from the user and assigns each letter
       to a hex, decimal, binary, bit, and parity. */

int main() {
    char c = 0;   
    printf("Enter a line of text: ");
    do {
        scanf("%c", &c);
        analyzeChar(c);
    } while ( c !=  '\n');
    return 0;
}

    /* Just displays each character (or new line). */

void printLetter(char c) {
    if (c != '\n') {
    printf("The ACSII code for '%c' is ", c);
    } else {
    printf("The ACSII code for'\\n' is ");
    }
}

    /* Displays the hex that represents each letter. %02x is used for 
       spacing. */

void printHex(char c) {
    printf("%02x hex, ", c);
}   

    /* Prints a decimal. Built-in function. */

void printDecimal(char c) {
    printf("%3d decimal, ", c);
} 

    /* Creates an 8-bit binary number. */

int printBinary(char c) {
  int bitCounter=0, i=0, mask = 0x80;
  for(i = 1; i <= 8; i++) { 
      if (c & mask)
      {
        printf("1");
        bitCounter++;
      }
      else
        printf("0");
        c <<= 1;
  }
  printf(", in binary, %d bits were set, ",bitCounter);
  /*bitCounter = 0;*/
  return bitCounter;
}

    /* Counts the number of ones to determine wether the parity is odd 
       or even. Also prints the number of ones in each binary nmber. */ 

void printParity(int bits) {
  if (bits % 2 == 1) {
    printf("parity is odd.\n ");
  } else {
    printf("parity is even.\n ");
  }
}

    /* Calls on all the functions. */
void analyzeChar(char c) {
    int bits = 0;
    printLetter(c);
    printHex(c);
    printDecimal(c);
    bits = printBinary(c);
    printParity(bits);
}

