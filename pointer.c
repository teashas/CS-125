#include <stdio.h>
#include <stdlib.h>

void printXYZ(int x, int y, int z);
int enterXYZ(int *ptrX, int *ptrY, int *ptrZ);
void xyzAcending(int *px, int *py, int *pz);
void swap(int* valueOne, int* valueTwo); 

int main() {
    int x = 0;
    int y = 0;
    int z = 0;
    
    printXYZ(x, y, z);
    enterXYZ(&x, &y, &z);
    printXYZ(x, y, z);
    xyzAscending(&x, &y, &z);
    printXYZ(x, y, z);
    
    return 0;
}

void printXYZ(int x, int y, int z) {
    printf("%d, %d, %d\n", x, y, z);
}

int enterXYZ(int *ptrX, int *ptrY, int *ptrZ) {
    char c = 0;
    
    printf("Enter X, Y, Z values: ");
    if (scanf("%d, %d,%d", ptrX, ptrY, ptrZ) != 3) {
        printf("Can't read!");
        while ((c = getchar()) != '\n' && c != EOF) {}
        enterXYZ(ptrX, ptrY, ptrZ);
    } else {
        printXYZ(*ptrX, *ptrY, *ptrZ);
    }
    return 0;
}
    
void xyzAscending(int* px, int* py, int* pz) {
    if (*py > *pz) {
        swap(py, pz);
    }
    if (*px > *py) {
        swap(px, py);
    }
    if (*py > *pz) {
        swap(py, pz);
    }
    printXYZ(*px, *py, *pz);
}

void swap(int* valueOne, int* valueTwo) {
    int temp = *valueOne;

    *valueOne = *valueTwo;
    *valueTwo = temp;
}
