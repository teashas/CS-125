#include <stdio.h>
#include <stdlib.h>
#include "IntegerSet.h"

int isetInit(IntegerSet* iset, int dataCapacity) {
    iset->dataLength = 0;
    iset->data = malloc(dataCapacity*sizeof(int));
    iset->dataCapacity = dataCapacity;
    if(iset->data == NULL) {
        iset->dataCapacity = 0;
        return 0;
    } else {
        return 1;
    }
}

void isetFree(IntegerSet* iset) {
    if((iset->data != NULL) && (iset != NULL)) {
        free(iset->data);
        iset->data = NULL;
    }
}
    
int isetIndex(const IntegerSet* iset, int value) {
    int i = 0;
    for(i= 0; i < (iset->dataLength); i++) {
        if (value == iset->data[i]) {
            return i;
        }
    }
    return -1;
}

int isetAdd(IntegerSet* iset, int value) {
    if ((iset->dataLength >= iset->dataCapacity) || (isetIndex(iset, value) != -1)) {
        return 0;    
    } else {
        iset->data[iset->dataLength] = value;
        iset->dataLength++;
        return 1;
    }
}

int isetAddArray(IntegerSet* iset, const int array[], int arrayLength) {
    int i = 0;
    int count = 0;
    for(i = 0; i < arrayLength; i++) {
        if(isetAdd(iset, array[i]) == 1){
            count++;
        }
    }
    return count;
}
        
void isetClear(IntegerSet* iset) {
    iset->dataLength = 0;
} 

int isetRemoveFast(IntegerSet* iset, int index) {
    int lastArray = 0;
    if((index >= 0) && (index < iset->dataLength)) {
        lastArray = iset->data[iset->dataLength--];
        iset->data[index] = lastArray;
        return 1;
    }
    return 0;
}

int isetRemoveStable(IntegerSet* iset, int index) {
    int i = 0;
    if((index >= 0) && (index < iset->dataLength)) {
        iset->dataLength--;
        for(i = index; i < iset->dataLength; i++) {
            iset->data[index] = iset->data[index+1];
        }
        return 1;
    } 
    return 0;
}

void isetPrint(const IntegerSet* iset, int numberOfColumns) {
    int i = 0;
    for(i = 0; i < iset->dataLength; i++) {
        if(i % numberOfColumns == 0 && i > 0){
            printf("\n");
        }
        printf("%3d", iset->data[i]);
    }
    printf("\n");
}
