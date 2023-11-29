#include "MainMemory.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

#define VALUE_OFFSET 1
#define MULTIPLY_BY_EIGHT 3 //Eight bits per byte
#define MAX_VALUE_PLUS_ONE_TOO_MANY (1 << (sizeof(uint8_t) << MULTIPLY_BY_EIGHT)) //256
#define MAX_VALUE ((MAX_VALUE_PLUS_ONE_TOO_MANY) - 1) //255

#define SIX_BIT_BYTE_TO_BINARY_PATTERN "%c%c[%c%c%c%c]"

#define SIX_BIT_BYTE_TO_BINARY(byte)  \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0') 

void MainMemoryInitialize(MainMemoryPtr mainMemoryPtr, bool randomize)
{
    srand((unsigned int)time(NULL));

    for (int index = 0; index < MAIN_MEMORY_SIZE; index++)
    {
        uint8_t maxSize = MAX_VALUE;

        mainMemoryPtr->values[index] = VALUE_OFFSET + (rand() % (MAX_VALUE - VALUE_OFFSET));
    }
}

void MainMemoryViewMemory(MainMemoryPtr mainMemoryPtr, int blockSize)
{
    printf("*********************BEGIN VIEW MAIN MEMORY CONTENTS*********************\n\n");


    int blockQuantity = (MAIN_MEMORY_SIZE) / blockSize;

    for (int blockNumber = 0; blockNumber < blockQuantity; blockNumber++)
    {
        MainMemoryViewMemoryBlock(mainMemoryPtr, blockNumber, blockSize);
    }

    printf("**********************END VIEW MAIN MEMORY CONTENTS**********************\n\n");
}


void MainMemoryViewMemoryBlock(MainMemoryPtr mainMemoryPtr, int blockNumber, int blockSize)
{
    int startingAddress = blockNumber * blockSize;

    printf("******************BEGIN VIEW MAIN MEMORY BLOCK CONTENTS******************\n\n");

    printf("Main Memory Block Start Address: Decimal: %3d Hex: 0x%02hhx ", startingAddress, startingAddress);
    printf("Binary: ");
    printf(SIX_BIT_BYTE_TO_BINARY_PATTERN, SIX_BIT_BYTE_TO_BINARY(startingAddress));
    printf("\n");

    printf("Main Memory Block End Address:   Decimal: %3d Hex: 0x%02hhx ", startingAddress + blockSize - 1, startingAddress + blockSize - 1);
    printf("Binary: ");
    printf(SIX_BIT_BYTE_TO_BINARY_PATTERN, SIX_BIT_BYTE_TO_BINARY(startingAddress + blockSize - 1));
    printf("\n\n");

    for (int address = startingAddress; address < (startingAddress + blockSize); address++)
    {
        uint8_t value = mainMemoryPtr->values[address];

        printf("Word Address: Decimal: %3d Hex: 0x%02hhx ", address, address);
        printf("Binary: ");
        printf(SIX_BIT_BYTE_TO_BINARY_PATTERN, SIX_BIT_BYTE_TO_BINARY(address));
        printf(" Word Value: %3d", value);
        printf("\n");
    }

    printf("\n");
    printf("*******************END VIEW MAIN MEMORY BLOCK CONTENTS*******************\n\n");
}