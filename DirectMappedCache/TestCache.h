#ifndef TESTCASE_TEST_CACHE_H
#define TESTCASE_TEST_CACHE_H

/*******************************************************************************
* Module:       TestCache
* Developer:    Michael Koepp
* Company:      WWU Computer Science Department
* Create Date:  
* Description:  Tests a direct-mapped cache.
*******************************************************************************/

#include "Computer.h"

void TestCache(ComputerPtr computerPtr);
void TestCacheSet(ComputerPtr Computer, int cacheSetTag, int cacheSetIndex);
uint8_t TestCacheRead(ComputerPtr computerPtr, uint8_t address);
bool TestCacheReadWrite(ComputerPtr computerPtr, uint8_t address, uint8_t word);

#endif