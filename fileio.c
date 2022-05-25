/*******************************************************************************
*  Saima Teasha
*  CS125
*  program HW8
*
*  An array of 100 doubles with values between 10 and 75. Write all 100 values 
*  to a file called “data1.txt”, in tabular form, ten values across in each 
*  row.
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

/* Functions needed for part 1 of assignment 8 - writing to a file */
int fillRandom(double array[], int length,
               double lowerLimit, double upperLimit);
void writeArray(FILE* fp, const double array[], int length);
void writeToFile(const char* fileName, const double array[], int length);
void part1(void);
/* Additional functions for part 2 of assignment 8 - reading from a file */
int readArray(FILE* fp, double array[], int maxCount);
int readFromFile(const char* filename, double array[], int size);
void part2(void);

int main(void) {
    part1();
    /* %% ONLY UNCOMMENT part2() AFTER YOU HAVE PART1 WORKING %% */  
    part2();

    return EXIT_SUCCESS;
}

#define ARRAY_SIZE 100
void part1(void) {
    double array[ARRAY_SIZE];
    int arrayLength = 0;
    arrayLength = fillRandom(array, ARRAY_SIZE, 10, 75);
    writeToFile( "data1.txt", array, arrayLength);
    arrayLength = fillRandom(array, 13, 130.2, 130.7);
    writeToFile( "data2.txt", array, arrayLength);
} 


#define BIG_BUFFER_SZ 1024
#define SMALL_BUFFER_SZ 48
void part2(void) {
    double buffer1[BIG_BUFFER_SZ];
    double buffer2[BIG_BUFFER_SZ];
    double buffer3[SMALL_BUFFER_SZ];
    int buffer1Len = 0;
    int buffer2Len = 0;
    int buffer3Len = 0;
    fputs("data1.txt\n", stdout);
    buffer1Len = readFromFile("data1.txt", buffer1, BIG_BUFFER_SZ);
    writeArray(stdout, buffer1, buffer1Len);
    fputs("data2.txt\n", stdout);
    buffer2Len = readFromFile("data2.txt", buffer2, BIG_BUFFER_SZ);
    writeArray(stdout, buffer2, buffer2Len);
    fputs("data3.txt\n", stdout);
    buffer3Len = readFromFile("data3.txt", buffer3, SMALL_BUFFER_SZ);
    writeArray(stdout, buffer3, buffer3Len);
    fputs("data1.txt\n", stdout);
    buffer3Len = readFromFile("data1.txt", buffer3, SMALL_BUFFER_SZ);
    writeArray(stdout, buffer3, buffer3Len);
}

double getRandomDouble(double lowerLimit, double upperLimit) {
    double range = upperLimit - lowerLimit;
    double normalRand = rand() / (RAND_MAX +1.0);
    return normalRand * range + lowerLimit;
}

int fillRandom(double array[], int length,
               double lowerLimit, double upperLimit) {
    int i = 0;
    for (i = 0; i < length; i++) {
        array[i] = getRandomDouble(lowerLimit, upperLimit);
    }
    return i; 
}

void writeArray(FILE* fp, const double array[], int length) {
    int i = 0; 
    for (i = 0; i < length; i++) {
        if (i % 10 == 0 && i > 0) {
            fputc('\n', fp);
        }
        fprintf(fp, "%7.2lf", array[i]);
    }
    fputc('\n', fp);
}

void writeToFile(const char* fileName, const double array[], int length) {
    FILE* fp = fopen(fileName, "w");
    fputs("Start of data\n", fp);
    writeArray(fp, array, length);
    fputs("End of data\n", fp);
    fclose(fp);
}

int readArray(FILE* fp, double array[], int maxCount) {
    int i = 0;
    fscanf(fp, "%*[^0-9]");
    for (i = 0; i < maxCount && fscanf(fp, "%lf", &array[i]) > 0; i++) {
    }
    return i;
}

int readFromFile(const char* filename, double array[], int size) { 
    FILE* fp = fopen(filename, "r");
    int read = 0;
    if (fp == NULL) {
        perror(filename);
        return 0;
    } else {
        read = readArray(fp, array, size);
        fclose(fp);
        return read;
    }
}
