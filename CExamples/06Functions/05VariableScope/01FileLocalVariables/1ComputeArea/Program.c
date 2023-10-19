#include <stdio.h>

//File-local variable
double radius = 0;

//Function Prototype
double computeArea();

int main()
{
    //Input
    printf("Enter radius: ");
    int return_value = scanf("%lf", &radius);

    double area = computeArea(); 

    //Output
    printf("Area: %lf\n", area);
}

//Function Definition
double computeArea()       
{
    const double PI = 3.14159;

    double area = PI * radius * radius;

    return area;
}
