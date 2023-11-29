#ifndef CPU_H
#define CPU_H

/*******************************************************************************
* Module:       CPU
* Developer:    Michael Koepp
* Company:      WWU Computer Science Department
* Create Date:  
* Description:  A CPU object contains a Cache object.
*               The Cache object implements the behavior of a direct-mapped 
*               cache.
*******************************************************************************/

#include "Cache.h"

typedef struct
{
    Cache cache;
    CachePtr cachePtr;

}CPU, * CPU_Ptr;

void CPUInitialize(CPU_Ptr cpuPtr, MainMemoryPtr mainMemoryPtr);
uint8_t CPUReadWord(CPU_Ptr cpuPtr, uint8_t address);
void CPUWriteWord(CPU_Ptr cpuPtr, uint8_t address, uint8_t word);

#endif // !CPU_H