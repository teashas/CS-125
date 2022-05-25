/*******************************************************************************
*  Saima Teasha
*  CS125
*  program HW7
*
*  a program that declares an array of 100 doubles and then fills it with 75 
*  random doubles between 40.0 and 60.0(from 40.0 up to butnot including 60.0)
*  in value. Print out the values in the array then printout the largest 
*  value, the smallest value, the average value and the standard deviation 
*  of the set of 75 values.
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* use rand() to get a random double in given range */
double getRandomDouble(double lowerLimit, double upperLimit);

/* assign random doubles to array elements */
int fillArrayWithRandomValues(double *array, int numberToFill,	                       
                              double lowerLimit, double upperLimit);

/* print the array values one above the other */
void listArrayValues(double* array, int arrayLength);

/* return the minimum value found in the array */
double getMinimumArrayValue(double* array, int arrayLength);

/* return the maximum value found in the array */
double getMaximumArrayValue(double* array, int arrayLength);

/* return the sum of the values in the array */
double getSumOfArrayValues(double* array, int arrayLength);

/* return the mean of the array, using sumOfArrayValues() to get the sum */
double getMeanOfArrayValues(double* array, int arrayLength);

/* return variance of the array, use meanOfArrayValues() to get the mean */
double getPopulationVariance(double* array, int arrayLength);

/* return standard deviation, using sqrt() and varianceOfArrayValues */
double getPopulationStandardDeviation(double* array, int arrayLength);

#define ARRAY_SIZE 100
#define DATA_LENGTH 75
int main(void) {
    double myArray[ARRAY_SIZE];
    int length = fillArrayWithRandomValues(myArray, DATA_LENGTH, 40.0, 60.0);
    listArrayValues(myArray, length);
    printf("The sum of the %d values was %.3f\n", length,
           getSumOfArrayValues(myArray, length));
    printf("The smallest was %.3f, and the largest was %.3f\n",
           getMinimumArrayValue(myArray, length), 
           getMaximumArrayValue(myArray, length));
    printf("The average of the values was %.3f\n", 
           getMeanOfArrayValues(myArray, length));
    printf("The population standard deviation was %.3f\n",
           getPopulationStandardDeviation(myArray, length));
    return 0;
}

double getRandomDouble(double lowerLimit, double upperLimit) {
    double range = upperLimit - lowerLimit;
    double normalRand = rand() / (RAND_MAX + 1.0);
    return normalRand * range + lowerLimit;
}

int fillArrayWithRandomValues(double *array, int numberToFill,	                       
                              double lowerLimit, double upperLimit){
    int i = 0;
    for (i = 0; i < numberToFill; i++) {
        array[i] = getRandomDouble(lowerLimit, upperLimit);
    }
    return i;
}

void listArrayValues(double* array, int arrayLength){
    int i = 0;
    for (i = 0; i < arrayLength; i++) {
        printf("number[%d] is %.3lf\n", i, array[i]);
    }
}

double getMinimumArrayValue(double* array, int arrayLength) {
    double minValueSeenSoFar  = 0;
    int i = 0;
    for (i = 0; i < arrayLength; i++) {
        if (i == 0 || array[i] < minValueSeenSoFar) {
            minValueSeenSoFar = array[i];
        }
    }
    return minValueSeenSoFar;
}

double getMaximumArrayValue(double* array, int arrayLength) {
    double maxValueSeenSoFar  = 0;
    int i = 0;
    for (i = 0; i < arrayLength; i++) {
        if (i == 0 || array[i] > maxValueSeenSoFar) {
            maxValueSeenSoFar = array[i];
        }
    }
    return maxValueSeenSoFar;
}

double getSumOfArrayValues(double* array, int arrayLength) { 
    double sum = 0.0;
    int i = 0;
    for (i = 0; i < arrayLength; i++) {
    sum += array[i];
    }
    return sum;
}

double getMeanOfArrayValues(double* array, int arrayLength) {
    return getSumOfArrayValues(array, arrayLength) / arrayLength;
}

double getPopulationVariance(double* array, int arrayLength) {
    int i = 0;
    double variance = 0.0;
    double deviation = 0.0;
    double devSquared = 0.0;
    double sum = 0.0;
    for (i = 0; i < arrayLength; i++) { 
        deviation  = (array[i] - getMeanOfArrayValues(array, arrayLength));
        devSquared = deviation * deviation;
        sum += devSquared;
    }
    variance = sum / arrayLength;
    return variance;
}


double getPopulationStandardDeviation(double* array, int arrayLength) {
    double square = 0.0;
        square =  sqrt(getPopulationVariance(array, arrayLength));
    return square;
} 
