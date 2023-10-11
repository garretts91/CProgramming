#include <stdio.h>

int add(int a, int b)
{
    int c = 0;

    _asm
    {
        mov eax, a
        add eax, b
        mov c, eax
    }

    return c;
}

int main()
{
    int x = 1;
    int y = 2;
    int sum = 0;

    sum = add(x, y);

    printf("The sum is %d\n", sum);

    char c = getchar();

    return 0;
}