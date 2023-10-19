#include <stdio.h>

int main()
{   
    //Variable Declarations
    int quantity = 0;
    int count = 0; 
    int total = 0;
    int number = 0;
    
    //Input
    printf("How many whole numbers do you want to average: ");
    int return_value = scanf("%d", &quantity);
    
    //Process
    while (count < quantity)
    {
        printf("Enter a number: ");
        int return_value = scanf("%d", &number);

        total = total + number;
        count = count + 1;
    }

    double average = (double)total / quantity;

    //Output
    printf("Total: %d\n", total);
    printf("Average: %lf\n", average);
}