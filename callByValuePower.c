#include <stdio.h>

int power(int x, int n);

int main() {
    int x, n;
    printf("Enter the value of x: ");
    scanf("%d", &x);
    printf("Enter the value of n: ");
    scanf("%d", &n);
    
    int result = power(x, n);
    
    printf("Result: %d\n", result);

    return 0;
}

int power(int x, int n) {
    int p = 1;

    for (; n > 0; --n) {
        p = p * x;
    }

    return p;
}