#include <stdio.h>

int main()
{   
    int quantity = 0;
    int total = 0;
    
    //Input
    printf("How many whole numbers do you want to average: ");
    int return_value = scanf("%d", &quantity);
    
    //Process
    for (int count = 0; count < quantity; count++)
    {
        int number = 0;

        printf("Enter a number: ");
        int return_value = scanf("%d", &number);

        total = total + number;
    }

    double average = (double)total / quantity;

    //Output
    printf("Total: %d\n", total);
    printf("Average: %lf\n", average);
}