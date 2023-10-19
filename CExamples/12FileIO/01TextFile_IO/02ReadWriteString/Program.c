#pragma warning(disable : 4996)
//https://www.tutorialspoint.com/c_standard_library/c_function_fgets.htm

#include <stdio.h>
#include <stdlib.h>

#define FILE_LINE_BUFFER_SIZE 50

int main()
{
    char * message = "Hello file world!";

    FILE* fptr = fopen("Data.txt", "w");

    int result = fprintf(fptr, "%s\n", message);

    fclose(fptr);

    char buffer[FILE_LINE_BUFFER_SIZE] = { 0 };

    fptr = fopen("Data.txt", "r");

    //Reads up to the space character
    //result = fscanf(fptr, "%s", buffer);

    //Read up to the newline character
    //Replaces newline character with NULL (0) character
    char * fileline = fgets(buffer, FILE_LINE_BUFFER_SIZE, fptr);

    fclose(fptr);

    printf("Message: %s", buffer);

    int ch = getchar();

    return 0;
}
