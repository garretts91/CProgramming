#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

int main()
{
    double radius = 0;

    //Input
    printf("Enter radius: ");
    int return_value = scanf("%lf", &radius);

    //Process
    double area = M_PI * radius * radius;

    //Output
    printf("Area: %lf\n", area);
}