#include <stdio.h>
#include "Functions.h"

//Variable declaraton for externally defined variable.
extern double radius;

int main()
{
    //Input
    printf("Enter radius: ");
    int return_value = scanf("%lf", &radius);

    //Process
    double area = computeArea();

    //Output
    printf("Area: %lf\n", area);
}