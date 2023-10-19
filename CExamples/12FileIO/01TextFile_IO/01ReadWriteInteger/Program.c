#pragma warning(disable : 4996)

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int value = 1;

    FILE* fptr = fopen("Data.txt", "w");

    int result = fprintf(fptr, "%d", value);

    fclose(fptr);

    value = 0;

    fptr = fopen("Data.txt", "r");

    result = fscanf(fptr, "%d", &value);

    fclose(fptr);

    printf("Value: %d", value);

    int ch = getchar();

    return 0;
}
