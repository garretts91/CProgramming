#include <stdio.h>

//Function Prototype
double computeCurrent(double voltage, double resistance);

int main()
{
    double voltage = 0;
    double resistance = 0;

    //Input
    printf("Enter voltage: ");
    int return_value = scanf("%lf", &voltage);

    printf("Enter resistance: ");
    return_value = scanf("%lf", &resistance);

    //Process
    double current = computeCurrent(voltage, resistance);

    //Output
    printf("Current: %lf\n", current);
}

//Function Definition
double computeCurrent(double voltage, double resistance)
{
    double current = voltage / resistance;

    return current;
}