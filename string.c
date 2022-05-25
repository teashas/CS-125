/*******************************************************************************
*  Saima Teasha
*  CS125
*  program HW6
*
*  Implementation of 4 functions that operate on strings, plus two additional 
*  functions that replicate two of the original 4, withan additional feature 
*  to make the code safe. The four functions are: stringLength(), 
*  stringCountChar(), stringToUpper(), and stringCopy().The safe functions 
*  are safeStringLength() and safeStringCopy().
*******************************************************************************/


#include <stdio.h>

/* Function: stringLength
* Purpose: count the number of characters in a string up to null
* Argument: str - the string array
* Returns: the length of the string
* Precondition: the source is a valid string with null termination
* Postcondition: Nothing in str is changed
*/

int stringLength(char* str) {
    int i = 0;
    for (i = 0; str[i] != '\0'; i++) {
    }
    return i;
}

/* Function: stringCopy
* Purpose: Copy the string from source to destination (but unsafe)
* Argument: source - the string to be copied
* Argument: destination - the array into which to copy the string
* Returns: nothing
* Precondition: the source is a valid string with null termination
* Postcondition: the destination has the same string as the source
* Postcondition: the destination string is null terminated
* Postcondition: Nothing in source is changed
*/

void stringCopy(char* source, char* destination)
{
    int i = 0;
    for (i = 0; source[i] != '\0'; i++) {
       destination[i] = source[i];
    } 
    destination[i] = '\0';
}

/* Function: safeStringLength
* Purpose: count the number of characters in a string, but only
* up to a limited length
* Argument: str - the string array
* Argument: maxLength - the size of the array holding the string
* Returns: the length of the string
* Postcondition: Nothing in str is changed
*/

int safeStringLength(char* str, int maxLength)
{
    int i = 0;
    for (i = 0; i < maxLength && str[i] != '\0'; i++) {
    }        
 return i;
}

/* Function: safeStringCopy
* Purpose: Copy the string from source to destination
* Argument: source - the string to be copied
* Argument: destination - the array into which to copy the string
* Argument: destinationSize - the size available for destination
* Precondition: the source is a valid string with null termination
* Postcondition: the destination has the same string as the source
* up to one less than destinationSize
* Postcondition: in the destination string the last element is null
*/

void safeStringCopy(char* source, char* destination,
 int destinationSize)
{
    int i = 0;
    for (i = 0; i < destinationSize && source[i] != '\0'; i++) {
        destination[i] = source[i];
    }
   destination[i] = '\0';
}

/* Function: stringCountChar
* Purpose: count the number of times letter appears in the string
* Argument: letter - a single character with letter to be counted
* Argument: str - the string array
* Argument: maxLength - the size of the array holding the string
* Returns: the number of times letter appears in the string
* Postcondition: Nothing in str is changed
*/

int stringCountChar(char letter, char* str, int maxLength)
{
    int i = 0;
    int count = 0;
    for (i = 0; i < maxLength && str[i] != '\0'; i++) {
        if (letter == str[i]) {
            count++;
        }
    }
 return count;
}

/* Function: stringToUpper
* Purpose: change a possibly mixed case string to all upper case
* Argument: str - the string array
* Argument: maxLength - the size of the array holding the string
* Returns: nothing
* Precondition: str points to a string
* Postcondition: all lower case letters in str are replaced with
* upper case letters (of the same letter)
* Postcondition: except for changing case, there are no other changes
*/

void stringToUpper(char* str, int maxLength)
{
    int i = 0;
    for (i = 0; i < maxLength && str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 'a' - 'A';       
        }
    }

}

/* Function: replaceChar
* Purpose: Replace all instances of old character with new character
* Argument: old - the character to be replaced
* Argument: new - the new character to replace the old
* Argument: str - the string array
* Argument: maxLength - the size of the array holding the string
*/

void replaceChar(char old, char new, char* str, int maxLength)
{
    int i = 0;
    for (i = 0; i < maxLength && str[i] != '\0'; i++) {
        if (str[i] == old) {
           str[i] = new;
         }
     }
}


#define BUFFER_SIZE 128

int main(void)
{
 char buffer[BUFFER_SIZE] = "";
 char copy1[BUFFER_SIZE] = "";
 char copy2[BUFFER_SIZE] = "";
 char* result = NULL;
 int length = 0;
 int count = 0;
 int i = 0;
 printf("Enter a sentence or other string: ");
 result = fgets(buffer, BUFFER_SIZE, stdin);
 
 buffer[BUFFER_SIZE - 1] = '\0';
 
 replaceChar('\n', '\0', buffer, BUFFER_SIZE);

 printf("%s\n", buffer);

 length = stringLength(buffer);
 printf("The length of the string is %d.\n", length);
 length = safeStringLength(buffer, BUFFER_SIZE);
 for (i = 0; i < length; i++)
 printf("-");
 printf("\n");

 stringToUpper(buffer, BUFFER_SIZE);
 printf("%s\n", buffer);

 count = stringCountChar(buffer[0], buffer, BUFFER_SIZE);
 printf("The letter %c appears %d times.\n", buffer[0], count);
 
 stringCopy(buffer, copy1);
 printf("%s\n", copy1);
 safeStringCopy(buffer, copy2, length - 5);
 printf("%s\n", copy2);
 return 0;
}
