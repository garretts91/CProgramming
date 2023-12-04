/*******************************************************************************
* Module: Program
* Developer: Michael Koepp
* Company: WWU Computer Science Department
* Create Date:
* Description: This program tests a direct-mapped cache implementation.
*******************************************************************************/
#include <stdio.h>
#include "Computer.h"
#include "TestCache.h"
Computer computer;
void main()
{
uint8_t mainMemoryAddress = 0;
uint8_t cacheWord = 0;
uint8_t value = 0;
printf("Starting cache system test...\n\n");
Computer * computerPtr = &computer;
ComputerInitialize(computerPtr);
//TestCache(computerPtr);
////Read word from cache, decrement word, write decremented word to cache
//mainMemoryAddress = (uint8_t)0b000000;
//cacheWord = TestCacheRead(computerPtr, mainMemoryAddress);
//value = cacheWord - (uint8_t)1;
//TestCacheReadWrite(computerPtr, mainMemoryAddress, value);
////Read word from cache, decrement word, write decremented word to cache
//mainMemoryAddress = (uint8_t)0b000100;
//cacheWord = TestCacheRead(computerPtr, mainMemoryAddress);
//value = cacheWord - (uint8_t)1;
//TestCacheReadWrite(computerPtr, mainMemoryAddress, value);
////Read word from cache, decrement word, write decremented word to cache
//mainMemoryAddress = (uint8_t)0b001000;
//cacheWord = TestCacheRead(computerPtr, mainMemoryAddress);
//value = cacheWord - (uint8_t)1;
//TestCacheReadWrite(computerPtr, mainMemoryAddress, value);
////Read word from cache, decrement word, write decremented word to cache
//mainMemoryAddress = (uint8_t)0b001100;
//cacheWord = TestCacheRead(computerPtr, mainMemoryAddress);
//value = cacheWord - (uint8_t)1;
//TestCacheReadWrite(computerPtr, mainMemoryAddress, value);
////Read word from cache, decrement word, write decremented word to cache
//mainMemoryAddress = (uint8_t)0b010000;
//cacheWord = TestCacheRead(computerPtr, mainMemoryAddress);
//value = cacheWord - (uint8_t)1;
//TestCacheReadWrite(computerPtr, mainMemoryAddress, value);
unsigned char userResponse = 0;
unsigned int userAddressInput = 0;
printf("Read a word from physical memory (y/n): ");
int returnValue = scanf("%c", &userResponse);
printf("\n");
while (userResponse == 'y')
{
printf("Enter physical address in hexidecimal: ");
returnValue = scanf("%x", &userAddressInput);
returnValue = getchar();
mainMemoryAddress = (uint8_t)userAddressInput;
uint8_t loadedWord = CPUReadWord(computerPtr->cpuPtr,
mainMemoryAddress);
printf("Word read from cache: %hu \n", loadedWord);
printf("\n");
CacheViewCache(computerPtr->cpuPtr->cachePtr);
printf("Read a word from physical memory (y/n): ");
returnValue = scanf("%c", &userResponse);
printf("\n");
}
printf("Press the enter key to continue...");
int c = getchar();
}