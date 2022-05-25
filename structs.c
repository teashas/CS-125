/*******************************************************************************
*  Saima Teasha
*  CS125
*  program HW9
*
*  Define two structured types,one for a two-dimensional Point, the other for 
*  a Triangle consisting of 3 Points. Havemaindeclare a Triangleand then fill 
*  in its vertex Points with random floating point numbers between 0 and 1. 
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>


/* Define a point struct with x and y values */ 

typedef struct {
    double x;
    double y;
} Point;
 
/* Define a triangle struct with three point value */ 

typedef struct {
    Point one;
    Point two;
    Point three;
} Triangle;

Point getRandomPoint();
Point getCentroid(Triangle triangle);


Point getRandomPoint() {
    Point normalRandom;
    normalRandom.x = rand() / (RAND_MAX + 1.0);
    normalRandom.y = rand() / (RAND_MAX + 1.0);
    return normalRandom;
}

Point getCentroid(Triangle triangle) {
    Point getCent;
    getCent.x = (triangle.one.x + triangle.two.x + triangle.three.x) / 3; 
    getCent.y = (triangle.one.y + triangle.two.y + triangle.three.y) / 3; 
    return getCent;
}


int main() {
    Triangle triangle;
    Point centroidValue;
    
    triangle.one = getRandomPoint();
    triangle.two = getRandomPoint();    
    triangle.three = getRandomPoint();
    centroidValue = getCentroid(triangle);
    printf("The triangle vertices are [%.2lf, %.2lf], ", triangle.one.x, triangle.one.y);
    printf("[%.2lf, %.2lf], ", triangle.two.x, triangle.two.y);
    printf("and [%.2lf, %.2lf].\n", triangle.three.x, triangle.three.y);
    printf("The centroid is [%.2lf, %.2lf].\n", centroidValue.x, centroidValue.y);
    return 0;
}



