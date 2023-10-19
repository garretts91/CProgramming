#include <stdio.h>


int main()
{
    //Constant Variable Declarations
    const int QUARTS_PER_GALLON = 4;

    //Variable Declarations
    int quarts = 0;

    //Input
    printf("Enter quarts of milk: ");
    int return_value = scanf("%d", &quarts);

    //Process
    int gallons = quarts / QUARTS_PER_GALLON;
    int remainingQuarts = quarts % QUARTS_PER_GALLON;

    //Output
    printf("Gallons: %d\n", gallons);
    printf("Remaining quarts: %d\n", remainingQuarts);
}