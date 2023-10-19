#include <stdio.h>
#include <stdbool.h>

int main()
{
    //Constant Declarations
    const int FREEZING_POINT = 32;
    const int CRITICAL_WIND_SPEED = 20;

    //Variable Declarations
    double temperature = 0;
    double windspeed = 0;

    //Input
    printf("What is the temperature today (F): ");
    int return_value = scanf("%lf", &temperature);

    printf("What is the wind speed today (MPH) ");
    return_value = scanf("%lf", &windspeed);
    //Process
    bool isCold = temperature <= FREEZING_POINT;
    bool isWindy = windspeed >= CRITICAL_WIND_SPEED;
    bool isCoatDay = isCold || isWindy;

    //Output
    if (isCoatDay)
        printf("You will need your coat today!\n");
    else
        printf("It will be a pleasant day!\n");
}