#include "CPU.h"

void CPUInitialize(CPU_Ptr cpuPtr, MainMemoryPtr mainMemoryPtr)
{
    cpuPtr->cachePtr = &cpuPtr->cache;

    CacheInitialize(cpuPtr->cachePtr, mainMemoryPtr);
}

uint8_t CPUReadWord(CPU_Ptr cpuPtr, uint8_t address)
{
    uint8_t word = CacheReadWord(cpuPtr->cachePtr, address);

    return word;
}

void CPUWriteWord(CPU_Ptr cpuPtr, uint8_t address, uint8_t word)
{
    CacheWriteWord(cpuPtr->cachePtr, address, word);
}