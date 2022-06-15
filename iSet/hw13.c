/*
 * File:    hw11.c
 * Project: Homework 11
 * Purpose: test driver for student homework
 * Author:  Michael Van Hilst
 * Version: 1.0 November 11, 2017 (in the 11th hour of the 11th day ...)
 *          2.0 March 29, 2019 updated with different behavior
 *          2.1 August 8, 2019 updated for clarity
 *
 * Copyright 2017,2019 (c) Michael Van Hilst All rights reserverd.
 */
#include <stdio.h>         /* for printf() */
#include "IntegerSet.h" /* homework project header file */

void fillRandom(int array[], int arrLen, int lowerBound, int upperBound);
int myrand(void);
#define MYRAND_MAX 32768

/* TEST_SZ is set to exceed size of array in the IntegerBuffer */
#define TEST_SZ 64
#define DATA_SZ 32
int main(void) {
    int i = 0;
    int index = 0;
    int testLength = 0;
    IntegerSet iset;
    int testValues[TEST_SZ];
#ifdef EXTRA
    IntegerSet* extra = NULL;
#endif
    /* test that isetInit is working correctly */
    printf("Phase 1:\n");
    isetInit(&iset, DATA_SZ);
    printf("capacity: %d, length: %d\n", iset.dataCapacity, iset.dataLength);
    /* test that isetAdd is working correctly */
    printf("Phase 2:\n");
    isetAdd(&iset, 5);
    isetAdd(&iset, 17);
    isetPrint(&iset, 10);
    /* test that isetAddArray is working correctly */
    printf("Phase 3:\n");
    fillRandom(testValues, TEST_SZ, 20, 75);
    testLength = isetAddArray(&iset, testValues, TEST_SZ);
    printf("reported adding %d of %d\n", testLength, TEST_SZ);
    printf("capacity: %d, length: %d\n", iset.dataCapacity, iset.dataLength);
    isetPrint(&iset, 9);
    /* test that isetClear is working correctly */
    printf("Phase 4:\n");
    isetClear(&iset);
    for (i = 0; i < 5; i++)
        isetAdd(&iset, i);
    for (i = 5; i > 0; i--)
        isetAdd(&iset, i);
    isetPrint(&iset, 10);
    /* test that isetIndex, isetRemoveFast and isetRemoveStable work */
    printf("Phase 5:\n");
    index = isetIndex(&iset, 2);
    printf("capacity: %d, length: %d\n", iset.dataCapacity, iset.dataLength);
    isetRemoveFast(&iset, index);
    printf("capacity: %d, length: %d\n", iset.dataCapacity, iset.dataLength);
    isetRemoveFast(&iset, -1);
    printf("capacity: %d, length: %d\n", iset.dataCapacity, iset.dataLength);
    isetPrint(&iset, 10);
    isetRemoveStable(&iset, isetIndex(&iset, 1));
    printf("capacity: %d, length: %d\n", iset.dataCapacity, iset.dataLength);
    isetRemoveStable(&iset, DATA_SZ);
    printf("capacity: %d, length: %d\n", iset.dataCapacity, iset.dataLength);
    isetPrint(&iset, 10);
/* use the #ifdef NOTYET line to hide parts you haven't yet done */
#ifdef NOTYET
#endif
/* to compile this section, include the switch -DEXTRA in your gcc line */
#ifdef EXTRA
    printf("Extra Credit:\n");
    extra = isetCreate(50);
    fillRandom(testValues, TEST_SZ, 20, 225);
    isetAddArray(extra, testValues, TEST_SZ);
    isetPrint(extra, 10);
    extra = isetDestroy(extra);
#endif
    return 0;
}

/* Function: fillRandom
 * Purpose:  fill an integer array with random values in a given range
 * Argument: array      - an array of integers
 * Argument: arrLen     - the number of integers to generate
 * Argument: lowerBound - the lowest value that could be generated
 * Argument: upperBound - the highest value that could be generated
 * Returns:  nothing
 * Precondition: array points to a valid array of ints
 * Precondition: arrLen is not greater than the available space in array
 */
void fillRandom(int array[], int arrLen, int lowerBound, int upperBound) {
    int i;
    /* static makes this a persistent variable
       that is initialized only once */
    static int notSeeded = 1;
    double range = 1.0 + upperBound - lowerBound;
    if (notSeeded) {
        /* if we want it seeded, the srand goes here */
        notSeeded = 0;
    }
    for (i = 0; i < arrLen; i++) {
        /* refactored the order to force doubles to be used w/o cast */
        /* a good optimizer will also recognize that (range / RAND_MAX)
                     * can be done outside the loop */
        array[i] = (int)(myrand() * (range / MYRAND_MAX) + lowerBound);
    }
}

/* POSIX.1-2001 gives the following example of an implementation of rand(),
 * useful when one needs the same sequence on different machines.
 */
int myrand(void) {
    static unsigned long next = 1;
    next = next * 1103515245 + 12345;
    return((unsigned)(next/65536) % MYRAND_MAX);
}
