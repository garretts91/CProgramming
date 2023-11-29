#ifndef MEMORY_H
#define MEMORY_H

/*******************************************************************************
* Module:       Memory
* Developer:    Michael Koepp
* Company:      WWU Computer Science Department
* Create Date:
* Description:  A MainMemory object contains an array of uint8_t values.
*               The Memory size is determined by the memory address size.
*******************************************************************************/

#include <stdint.h>
#include <stdbool.h>

#define MAIN_MEMORY_ADDRESS_BITS  6
#define MAIN_MEMORY_SIZE 1 << MAIN_MEMORY_ADDRESS_BITS //2 ^ MEMORY_ADDRESS_BIT_SIZE

typedef struct
{
    uint8_t values[MAIN_MEMORY_SIZE];

}MainMemory, * MainMemoryPtr;

void MainMemoryInitialize(MainMemoryPtr mainMemoryPtr, bool randomize);
void MainMemoryViewMemory(MainMemoryPtr mainMemoryPtr, int blockSize);
void MainMemoryViewMemoryBlock(MainMemoryPtr mainMemoryPtr, int blockNumber, int blockSize);

#endif

