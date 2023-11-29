#include "Computer.h"

void ComputerInitialize(ComputerPtr computerPtr)
{
    computerPtr->cpuPtr = &computerPtr->cpu;
    computerPtr->mainMemoryPtr = &computerPtr->mainMemory;

    MainMemoryInitialize(computerPtr->mainMemoryPtr, true);
    CPUInitialize(computerPtr->cpuPtr, computerPtr->mainMemoryPtr);
}