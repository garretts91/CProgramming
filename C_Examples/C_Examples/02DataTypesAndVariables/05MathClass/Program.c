#include <stdio.h>
#include <math.h>

int main()
{
    int sideA = 0;
    int sideB = 0;

    //Input
    printf("Enter side A: ");
    int return_value = scanf("%d", &sideA);

    printf("Enter side B: ");
    return_value = scanf("%d", &sideB);

    //Process
    double sideASquared = pow(sideA, 2);
    double sideBSquared = pow(sideB, 2);
    double hypotenuse = sqrt(sideASquared + sideBSquared);
    //double hypotenuse = sqrt((pow(sideA, 2)) + (pow(sideB, 2)));

    //Output
    printf("Hypotenuse: %lf\n", hypotenuse);
}