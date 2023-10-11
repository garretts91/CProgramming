#include <stdio.h>
#include <limits.h>  //INT_MAX is defined in this header file.
                    //iostream includes climits, so the #include <climits> is optional

int main()
{   
    //Variable Declarations
    int quantity = 0;
    int count = 0;
    int total = 0;
    int number = 0;
    int highestSoFar = INT_MIN;
    int lowestSoFar = INT_MAX;
    //int highestSoFar = -101;
    //int lowestSoFar = 101;
    
    //Input
    printf("How many numbers do you want to process: ");
    int return_value = scanf("%d", &quantity);
    
    //Process
    while (count < quantity)
    {
        printf("Enter a number [-100..100]: ");
        return_value = scanf("%d", &number);

        total = total + number;
        count = count + 1;

        if (number > highestSoFar)
        {
            highestSoFar = number;
        }

        if (number < lowestSoFar)
        {
            lowestSoFar = number;
        }
    }

    double average = (double)total / quantity;

    //Output
    printf("Total: %d\n", total);
    printf("Average: %lf\n", average);
    printf("Highest: %d\n", highestSoFar);
    printf("Lowest: %d\n", lowestSoFar);
}