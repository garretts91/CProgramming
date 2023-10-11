#pragma warning(disable : 4996)
//https://www.tutorialspoint.com/c_standard_library/c_function_fwrite.htm

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMBER_OF_ELEMENTS 1

int main()
{
    int number = 1;

    FILE* fptr = fopen("Data.bin", "wb");

    int result = fwrite(&number, sizeof(int), NUMBER_OF_ELEMENTS, fptr);

    fclose(fptr);

    number = 2;

    fptr = fopen("Data.bin", "ab");

    result = fwrite(&number, sizeof(int), NUMBER_OF_ELEMENTS, fptr);

    fclose(fptr);

    number = 0;

    fptr = fopen("Data.bin", "rb");

    result = fread(&number, sizeof(int), 1, fptr);

    while (result != 0)
    {
        printf("Number: %d\n", number);

        result = fread(&number, sizeof(int), 1, fptr);
    }

    fclose(fptr);

    int ch = getchar();
}
