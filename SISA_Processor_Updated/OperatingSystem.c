#include "OperatingSystem.h"
#include "MainMemory.h"
#include <stdio.h>
#include <stdlib.h>

//PRIVATE FUNCTION PROTOTYPES
int OperatingSystemLoadExecutableFile(OperatingSystemPtr operatingSystemPtr, char* executableFilename, int* programSize);

#define DATA_SEGMENT_START_ADDRESS 0x0000
#define DATA_WORD_SIZE 16
#define DATA_WORD_BUFFER_SIZE (DATA_WORD_SIZE + 4)

#define INSTRUCTION_SIZE 16
#define INSTRUCTION_BUFFER_SIZE (INSTRUCTION_SIZE + 4)

void OperatingSystemInitialize(OperatingSystemPtr operatingSystemPtr, CPU_Ptr cpuPtr, MainMemoryPtr  mainMemoryPtr)
{
    operatingSystemPtr->cpuPtr = cpuPtr;
    operatingSystemPtr->mainMemoryPtr = mainMemoryPtr;
}

int16_t OperatingSystemExecuteProgram(OperatingSystemPtr operatingSystemPtr, char* executableFilename)
{
    int programSize = 0;

    int startingMainMemoryAddress = OperatingSystemLoadExecutableFile(operatingSystemPtr, executableFilename, &programSize);
    
    int16_t returnValue = CPUExecuteProgram(operatingSystemPtr->cpuPtr, startingMainMemoryAddress, programSize);

    return returnValue;
}

int OperatingSystemLoadExecutableFile(OperatingSystemPtr operatingSystemPtr, char* executableFilename, int* programSize)
{
    int codeSegmentStartAddress = 0;
    char dataWordBuffer[DATA_WORD_BUFFER_SIZE];
    char instructionBuffer[INSTRUCTION_BUFFER_SIZE];

    //Open executable file
    FILE* executableFilenameFilePtr = fopen(executableFilename, "r");

    //LOAD DATA SEMENT

    //Read size of data segment
    char* result = fgets(dataWordBuffer, DATA_WORD_BUFFER_SIZE, executableFilenameFilePtr);
    uint16_t dataSegmentSize = (uint16_t)strtol(dataWordBuffer, NULL, 2);

    //Read data segment values
    int mainMemoryAddress = DATA_SEGMENT_START_ADDRESS;

    for (int index = 0; index < dataSegmentSize; index++)
    {
        result = fgets(dataWordBuffer, DATA_WORD_BUFFER_SIZE, executableFilenameFilePtr);
        uint16_t dataSegmentWord = (uint16_t)strtol(dataWordBuffer, NULL, 2);

        operatingSystemPtr->mainMemoryPtr->values[mainMemoryAddress] = dataSegmentWord;

        mainMemoryAddress++;
    }

    //LOAD CODE SEGMENT

    codeSegmentStartAddress = mainMemoryAddress;

    result = fgets(instructionBuffer, INSTRUCTION_BUFFER_SIZE, executableFilenameFilePtr);

    while (result != 0)
    {
        uint16_t instruction = (uint16_t)strtol(instructionBuffer, NULL, 2);
        
        operatingSystemPtr->mainMemoryPtr->values[mainMemoryAddress] = instruction;
        mainMemoryAddress++;

        result = result = fgets(instructionBuffer, INSTRUCTION_BUFFER_SIZE, executableFilenameFilePtr);
    }

    fclose(executableFilenameFilePtr);

    *programSize = mainMemoryAddress;

    return codeSegmentStartAddress;
}