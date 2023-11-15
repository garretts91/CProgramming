#ifndef COMPUTER_H
#define COMPUTER_H

/*******************************************************************************
* Module:       Computer
* Developer:    Michael Koepp
* Company:      WWU Computer Science Department
* Create Date:  
* Description:  A Computer object contains a CPU object, a MainMemory object,
*               and an OperatingSystem object. 
*******************************************************************************/

#include "CPU.h"
#include "MainMemory.h"
#include "OperatingSystem.h"

typedef struct
{
    CPU cpu;
    MainMemory mainMemory;
    OperatingSystem operatingSystem;

    CPU_Ptr cpuPtr;
    MainMemoryPtr mainMemoryPtr;
    OperatingSystemPtr operatingSystemPtr;

}Computer, *ComputerPtr;

void ComputerInitialize(ComputerPtr computerPtr);
int16_t ComputerExecuteProgram(ComputerPtr computerPtr, char* executableFilename);

#endif