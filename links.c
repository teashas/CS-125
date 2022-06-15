#include <stdio.h>
#include <stdlib.h>
#include "Link.h" 

Link* getNewLink(int value, Link* next);
void printLinkedList(Link* head);
int sumOfLinkedList(Link* head);

int main() {
    Link* head = NULL;
    int array[6] = {7, 1, -4, 16, 0, 3};
    int arrLen = 6;
    int i = 0;
    
    head = getNewLink(-2, NULL);
    printLinkedList(head);
    printf("\n");
    for(i = 0; i < arrLen; i++) {
        head = getNewLink(array[i], head);
    }
    printLinkedList(head);
    printf("\n");
    printf("The sum is: %d\n", sumOfLinkedList(head)); 
    return 0;
}

Link* getNewLink(int value, Link* next) {
    Link* newLink = (Link*)malloc(sizeof(Link));
    newLink->value = value;
    newLink->next = next; 
    return newLink;
}

void printLinkedList(Link* head) {
    while (head != NULL) {
    printf("%5d ", head->value);
    head = head->next;
    }
}

int sumOfLinkedList(Link* head) {
    int sum = 0;
    
    while (head != NULL) {
        sum += head->value;
        head = head->next;
    } 
    return sum;
}
