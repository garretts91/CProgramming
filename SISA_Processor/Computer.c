#include "Computer.h"

void ComputerInitialize(ComputerPtr computerPtr)
{
    computerPtr->cpuPtr = &computerPtr->cpu;
    computerPtr->mainMemoryPtr = &computerPtr->mainMemory;
    computerPtr->operatingSystemPtr = &computerPtr->operatingSystem;

    MainMemoryInitialize(computerPtr->mainMemoryPtr);
    CPUInitialize(computerPtr->cpuPtr, computerPtr->mainMemoryPtr);
    OperatingSystemInitialize(computerPtr->operatingSystemPtr, computerPtr->cpuPtr, computerPtr->mainMemoryPtr);
}

int16_t ComputerExecuteProgram(ComputerPtr computerPtr, char* executableFilename)
{
    int16_t returnValue = OperatingSystemExecuteProgram(computerPtr->operatingSystemPtr, executableFilename);

    return returnValue;
}
