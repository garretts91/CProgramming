#include <stdio.h>
#include <stdbool.h>

int main()
{
    //Constant Declarations
    const int AGE_LIMIT = 12;
    
    //Variable Declarations
    int age = 0;

    //Input
    printf("Enter your age: ");
    int return_value = scanf("%d", &age);
    
    //Process
    bool overAgeLimit = age >= AGE_LIMIT;

    //Output
    if (!overAgeLimit)
        printf("You are too young to ride the roller coaster.\n");
    else
        printf("Step this way for the ride of your life!\n");

    //Or, a better way is to NOT use the Logical NOT
    if (overAgeLimit)
        printf("Step this way for the ride of your life!\n");
    else
        printf("You are too young to ride the roller coaster.\n");
}