#pragma warning(disable : 4996)
//https://www.tutorialspoint.com/c_standard_library/c_function_fwrite.htm

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_LINE_BUFFER_SIZE 10

int main()
{
    char* string = "Mickey Mouse";
    char newline = '\n';

    FILE* fptr = fopen("Data.bin", "wb");

    //Write just the string characters, not the NULL termination character.
    //int result = fwrite(string, sizeof(char), strlen(string), fptr);

    //Write NULL
    //int result = fwrite(string, sizeof(char), strlen(string) + 1, fptr);

    //Write NEWLINE
    int result = fwrite(string, sizeof(char), strlen(string), fptr);
    result = fwrite(&newline, sizeof(char), 1, fptr);

    fclose(fptr);

    string = "Donald Duck";

    fptr = fopen("Data.bin", "ab");

    //Write just the string characters, not the NULL termination character.
    //result = fwrite(string, sizeof(char), strlen(string), fptr);

    //Write NULL
    //result = fwrite(string, sizeof(char), strlen(string) + 1, fptr);

    //Write NEWLINE
    result = fwrite(string, sizeof(char), strlen(string), fptr);
    result = fwrite(&newline, sizeof(char), 1, fptr);

    fclose(fptr);

    char buffer[FILE_LINE_BUFFER_SIZE];

    fptr = fopen("Data.bin", "rb");

    result = fread(buffer, sizeof(char), FILE_LINE_BUFFER_SIZE, fptr);

    while (result != 0)
    {
        for (int index = 0; index < result; index++)
        {
            putchar(buffer[index]);
        }
   
        result = fread(buffer, sizeof(char), FILE_LINE_BUFFER_SIZE, fptr);
    }

    fclose(fptr);

    int ch = getchar();
}
