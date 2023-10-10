#pragma warning(disable : 4996)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_LINE_BUFFER_SIZE 50

int main()
{
    char* message = "Hello";

    FILE* fptr = fopen("Data.txt", "w");

    int result = fprintf(fptr, "%s\n", "Mickey Mouse");
    result = fprintf(fptr, "%s\n", "Captain");
    result = fprintf(fptr, "%s\n", "111");

    fclose(fptr);

    fptr = fopen("Data.txt", "a");

    result = fprintf(fptr, "%s\n", "Donald Duck");
    result = fprintf(fptr, "%s\n", "General");
    result = fprintf(fptr, "%s\n", "222");

    result = fprintf(fptr, "%s\n", "Daffy Duck");
    result = fprintf(fptr, "%s\n", "Private");
    result = fprintf(fptr, "%s\n", "333");

    fclose(fptr);

    char buffer[FILE_LINE_BUFFER_SIZE];

    fptr = fopen("Data.txt", "r");

    char* fileline = fgets(buffer, FILE_LINE_BUFFER_SIZE, fptr);

    while (fileline != 0)
    {
        printf("%s", buffer);

        fileline = fgets(buffer, FILE_LINE_BUFFER_SIZE, fptr);
    }

    fclose(fptr);

    int ch = getchar();
}
