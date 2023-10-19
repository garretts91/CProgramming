#include <stdio.h>

//Function Prototype
double computeArea(double radius);

int main()
{
    double radius = 0;

    //Input
    printf("Enter radius: ");
    int return_value = scanf("%lf", &radius);

    double area = computeArea(radius); 

    //Output
    printf("Area: %lf\n", area);
}

//Function Definition
double computeArea(double radius)       
{
    const double PI = 3.14159;

    double area = PI * radius * radius;

    return area;
}