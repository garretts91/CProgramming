#pragma once

/*******************************************************************************
* Module:       MMU
* Developer:    Michael Koepp
* Company:      WWU Computer Science Department
* Create Date:  
* Description:  
*******************************************************************************/

#include <stdbool.h>
#include "MainMemory.h"

typedef struct
{
    MainMemoryPtr mainMemoryPtr;

}MMU, *MMU_Ptr;

void MMUInitialize(MMU_Ptr mmuPtr, MainMemoryPtr mainMemoryPtr);
int16_t MMULoadWord(MMU_Ptr mmuPtr, int16_t memoryAddress);