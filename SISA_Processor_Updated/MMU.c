#include "MMU.h"

void MMUInitialize(MMU_Ptr mmuPtr, MainMemoryPtr mainMemoryPtr)
{
    mmuPtr->mainMemoryPtr = mainMemoryPtr;
}

int16_t MMULoadWord(MMU_Ptr mmuPtr, int16_t memoryAddress)
{
    int16_t word = 0;

    word = mmuPtr->mainMemoryPtr->values[memoryAddress];

    return word;
}
