/*******************************************************************************
*  Saima Teasha
*  CS125
*  program HW10
*
*  Tier 1 is a complete solution for a Triangle with 3 vertexes, and is worth 
*  10 points.  Tier 2 is a complete solution for a Polygon with an arbitrary 
*  number of vertices up to 32
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point v[31];
} Triangle;

Point enterPoint();

void printVertices(const Triangle* tr, int sides);    

double distanceBetweenPoints(const Point *p1, const Point *p2);

double getPerimeter(const Triangle *tr, int sides);

int main() {
    Triangle triangle;
    int i = 0;
    int sides = 0;
    char c = 0;

    printf("Enter number of points on your polygon: ");

    while (scanf("%d", &sides) != 1 || sides <= 2 || sides > 32) {
        while ((c = getchar()) != '\n' && c != EOF) 
        {}
        printf("Your number of points could not be read!\n");
        printf("Enter number of points on your polygon: ");
    }
    for(i = 0; i < sides; i++) {
        triangle.v[i] = enterPoint();
    }

    printVertices(&triangle, sides);
    printf("The perimeter of the polygon is %3.2lf\n", getPerimeter(&triangle, sides));  
    return 0;
}

Point enterPoint() {
    Point userInput;
    char c = 0;

    printf("Enter the x and y coordinates separated by a comma: ");
    while (scanf("%lf, %lf", &userInput.x, &userInput.y) != 2) {
        while ((c = getchar()) != '\n' && c != EOF) 
        {}
        printf("Your point could not be read!\n");
        printf("Enter the x and y coordinates separated by a comma: ");
    }
    return userInput;
}

void printVertices(const Triangle* tr, int sides) {
    int i = 0;
    
    printf("The polygon vertices are ");
    for (i = 0; i < sides; i++) {
        printf("[%3.2lf, %3.2lf] ", tr->v[i].x, tr->v[i].y);
    }
    printf("\n");
}

double distanceBetweenPoints(const Point *p1, const Point *p2) {
    double distance = 0.0;

    distance = sqrt(((p2->x - p1->x) * (p2->x - p1->x)) + 
               ((p2->y - p1->y) * (p2->y - p1->y)));
    return distance;
}

double getPerimeter(const Triangle *tr, int sides) {
    int i;
    double perimeter = 0.0;

    for (i = 0; i < sides; i++) {
        perimeter += distanceBetweenPoints(&tr->v[i], &tr->v[(i + 1) % sides]);
    }
    return perimeter;
} 
