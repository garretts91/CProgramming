#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Assembler.h"


void TestAssemblerInstruction(char* testCaseName, char* assemblyFilename, char* objectCodeFilename, char* validObjectCodeFilename)
{
    int test_case_result = 0;

    printf("************************BEGIN ASSEMBLY PROCESS************************\n\n");

    printf("Test case name: %s\n\n", testCaseName);

    printf("Running assembler...\n\n");

    printf("Assembly code instruction file: %s\n", assemblyFilename);
    printf("Machine code instruction file:  %s\n\n", objectCodeFilename);

	assemble(assemblyFilename, objectCodeFilename);

    printf("\nAssembly complete...\n\n");

    char generatedObjectCodeFileLine[ASSEMBLY_STATEMENT_BUFFER_SIZE];
    char validObjectCodeFileLine[ASSEMBLY_STATEMENT_BUFFER_SIZE];

    FILE* fptr_generated_object_code;
    FILE* fptr_valid_object_code;

    fptr_generated_object_code = fopen(objectCodeFilename, "r");
    fptr_valid_object_code = fopen(validObjectCodeFilename, "r");

    char* result = fgets(generatedObjectCodeFileLine, ASSEMBLY_STATEMENT_BUFFER_SIZE, fptr_generated_object_code);

    while (result != 0)
    {
        result = fgets(validObjectCodeFileLine, ASSEMBLY_STATEMENT_BUFFER_SIZE, fptr_valid_object_code);

        int compare_result = strcmp(generatedObjectCodeFileLine, validObjectCodeFileLine);

        if (compare_result != 0)
        {
            test_case_result = 1;

            printf("Test case failed...\n\n");

            break;
        }

        result = fgets(generatedObjectCodeFileLine, ASSEMBLY_STATEMENT_BUFFER_SIZE, fptr_generated_object_code);
    }
 
    fclose(fptr_generated_object_code);
    fclose(fptr_valid_object_code);

    if (test_case_result == 0)
    {
        printf("Test case result: PASSED\n\n");
    }
    else
    {
        printf("Test case result: FAILED\n\n");
    }

    printf("*************************END ASSEMBLY PROCESS*************************\n\n");
}