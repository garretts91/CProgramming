#include <stdio.h>

// Recursive function to calculate the factorial of a number
unsigned long long factorial(int n) {
    if (n == 0) {
        return 1; // Base case: 0! = 1
    } else {
        return n * factorial(n - 1); // Recursive case: n! = n * (n-1)!
    }
}

int main() {
    int num = 52;
    unsigned long long result = factorial(num);
    printf("Factorial of %d = %llu\n", num, result);
    return 0;
}