#include <stdio.h>
#include "Functions.h"

int main()
{
    double radius = 0;

    //Input
    printf("Enter radius: ");
    int return_value = scanf("%lf", &radius);

    //Process
    double area = computeArea(radius);

    //Output
    printf("Area: %lf\n", area);
}