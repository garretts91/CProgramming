#ifndef OPERATING_SYSTEM_H
#define OPERATING_SYSTEM_H

/*******************************************************************************
* Module:       OperatingSystem
* Developer:    Michael Koepp
* Company:      WWU Computer Science Department
* Create Date:
* Description:  
*******************************************************************************/

#include "CPU.h"
#include "MainMemory.h"


#include <stdint.h>

typedef struct
{
	CPU_Ptr cpuPtr;
	MainMemoryPtr mainMemoryPtr;

}OperatingSystem, *OperatingSystemPtr;

void OperatingSystemInitialize(OperatingSystemPtr operatingSystemPtr, CPU_Ptr cpuPtr, MainMemoryPtr  mainMemoryPtr);
int16_t OperatingSystemExecuteProgram(OperatingSystemPtr operatingSystemPtr, char* executableFilename);

#endif

