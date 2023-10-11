#include <stdio.h>

//File-local Variables
double voltage = 0;
double resistance = 0;

//Function Prototype -- Function's Header
double computeCurrent();

int main()
{
    //Input
    printf("Enter voltage: ");
    int return_value = scanf("%lf", &voltage);

    printf("Enter resistance: ");
    return_value = scanf("%lf", &resistance);

    //Process
    double current = computeCurrent();

    //Output
    printf("Current: %lf\n", current);
}

//Function Definition
//Parameter List: # of parameters, and the Parameter Data Types
//Return Type: double
double computeCurrent() //Function Header
{
    double current = voltage / resistance;

    return current;
}