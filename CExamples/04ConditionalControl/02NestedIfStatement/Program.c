#include <stdio.h>

int main()
{
    double income = 0;
    char dependents = 0;
    char CR = 0;

    //Input
    printf("Enter income: ");
    int return_value = scanf("%lf", &income);

    printf("Do you have dependents (Y/N): ");
    return_value = scanf("%c%c", &CR, &dependents);

    dependents = toupper(dependents);

    //Process
    double taxRate = 0;

    if (income <= 10000)
    {
        if (dependents == 'Y')
            taxRate = .1;
        else
            taxRate = .15;
    }
    else if (income <= 20000)
    {
        if (dependents == 'Y')
            taxRate = .2;
        else taxRate = .25;
    }
    else if (income <= 30000)
    {
        if (dependents == 'Y')
            taxRate = .3;
        else taxRate = .35;
    }
    else
    {
        if (dependents == 'Y')
            taxRate = .4;
        else taxRate = .45;
    }

    double incomeTax = income * taxRate;

    //Output
    printf("Income tax: %lf\n", incomeTax);
}