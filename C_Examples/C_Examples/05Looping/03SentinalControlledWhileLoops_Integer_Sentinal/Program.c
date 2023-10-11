#include <stdio.h>

int main()
{   
    //Constant Declarations
    const int SENTINEL_VALUE = -1;

    //Variable Declarations
    int count = 0;
    int total = 0;
    int number = 0;
    
    //Input and Process
    printf("Enter a number or %d to quit: ", SENTINEL_VALUE);
    int return_value = scanf("%d", &number);

    while (number != SENTINEL_VALUE)
    {
        total = total + number;
        count = count + 1;

        printf("Enter a number or %d to quit: ", SENTINEL_VALUE);
        return_value = scanf("%d", &number);
    }

    double average = (double)total / count;

    //Output
    printf("Total: %d\n", total);
    printf("Average: %lf\n", average);
}