#include <stdio.h>

int main()
{
    int cpuType = 0;
    double cpuPrice = 0;

    //Input
    printf("Enter CPU type {1: 8-bit, 2: 16-bit, 3: 32-bit, 4: 64-bit}: ");
    int return_value = scanf("%d", &cpuType);

    //Process
    switch (cpuType)
    {
        case 1:
        {
            cpuPrice = 25.0;
            break;
        }
        case 2:
        {
            cpuPrice = 50.0;
            break;
        }
        case 3:
        {
            cpuPrice = 150.0;
            break;
        }
        case 4:
        {
            cpuPrice = 200.0;
            break;
        }
        default:
        {
            cpuPrice = 0.0;
            break;
        }
    }

    //Output
    printf("CPU Price: %lf\n", cpuPrice);
}