#include <stdio.h>

// This is a small program intended to convert Farenheit to Celsius 

int main() {

    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 200;
    step = 10;

    printf("Fahr\tCelsius\n");
    printf("---------------\n");

    fahr = lower;
    while (fahr <= upper){
        celsius = (5.0/9.0) * (fahr - 32.0);
        printf("%3.0f \t %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}