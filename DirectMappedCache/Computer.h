#ifndef COMPUTER_H
#define COMPUTER_H

/*******************************************************************************
* Module:       Computer
* Developer:    Michael Koepp
* Company:      WWU Computer Science Department
* Create Date:  
* Description:  A Computer object contains a CPU object and a MainMemory object. 
*               The CPU object contains a Cache object that implements the 
*               behavior of a direct-mapped cache.
*******************************************************************************/

#include "CPU.h"
#include "MainMemory.h"

typedef struct
{
    CPU cpu;
    MainMemory mainMemory;

    CPU_Ptr cpuPtr;
    MainMemoryPtr mainMemoryPtr;

}Computer, *ComputerPtr;

void ComputerInitialize(ComputerPtr computerPtr);

#endif