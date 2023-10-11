#include <stdio.h>

int main()
{
    double income = 0;

    //Input
    printf("Enter income: ");
    int return_value = scanf("%lf", &income);

    //Process
    double taxRate = 0;

    if (income <= 10000)
    {
        taxRate = .1;
    }
    else if (income <= 20000)
    {
        taxRate = .2;
    }
    else if (income <= 30000)
    {
        taxRate = .3;
    }
    else
    {
        taxRate = .4;
    }

    double incomeTax = income * taxRate;

    //Output
    printf("Income tax: %lf\n", incomeTax);
}