#include <stdio.h>

int main() 
{
    int number = 0;

    //Input
    printf("Enter an integer value: ");
    int return_value = scanf("%d", &number);
    
    //Process
    number++;

    //Output
    printf("Value incremented: %d \n", number);
    printf("scanf returned: %d \n", return_value);

    //Reads newline character.
    int c = getchar();

    //Suspends program execution.
    c = getchar();

    return 0;
}
