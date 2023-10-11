#include <stdio.h>
//https://sites.google.com/site/matlabstyleguidelines/naming-conventions/constants

//#define PI 3.14159

int main()
{
    //Constant Variable Declarations
    const double PI = 3.14159;
    
    //Variable Declarations
    double radius = 0;

    //Input
    printf("Enter radius: ");
    int return_value = scanf("%lf", &radius);
   
    //Process
    double area = PI * radius * radius; 

    //Output
    printf("Area: %lf\n", area);
}