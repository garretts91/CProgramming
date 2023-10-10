#pragma warning(disable : 4996)
//https://www.tutorialspoint.com/c_standard_library/c_function_fwrite.htm

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int number = 1;

    FILE* fptr = fopen("Data.bin", "wb");

    int result = fwrite(&number, sizeof(int), 1, fptr);

    fclose(fptr);

    number = 0;

    fptr = fopen("Data.bin", "rb");

    result = fread(&number, sizeof(int), 1, fptr);

    fclose(fptr);

    printf("Number: %d", number);

    int ch = getchar();
}
