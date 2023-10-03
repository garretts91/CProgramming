#include <stdio.h>
/*
looking at how bitwise operators work
1 = 0000 0001
2 = 0000 0010
3 = 0000 0011
4 = 0000 0100
5 = 0000 0101
6 = 0000 0110
7 = 0000 0111
8 = 0000 1000
9 = 0000 1001
18 = 0001 0010
*/

int main ()
{
    unsigned int x = 9;
    unsigned int y = 24;
    unsigned int r;
    r = x << 1;

    printf("x << 1: %d\n", r);

}