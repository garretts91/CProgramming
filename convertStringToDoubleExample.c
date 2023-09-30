#include <stdio.h>
#include <stdlib.h>

int main() {
    const char *str = "12.345"; // Replace with the string you want to convert
    double result = atof(str);

    printf("String: %s\n", str);
    printf("Converted Double: %lf\n", result);

    return 0;
}