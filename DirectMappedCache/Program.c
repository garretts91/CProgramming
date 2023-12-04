// /*******************************************************************************
// * Module:       Program
// * Developer:    Michael Koepp
// * Company:      WWU Computer Science Department
// * Create Date:  
// * Description:  This program tests a direct-mapped cache implementation. 
// *******************************************************************************/
// #include <stdio.h>
// #include "Computer.h"
// #include "TestCache.h"

// Computer computer;

// void main()
// {
// 	uint8_t mainMemoryAddress = 0;
// 	uint8_t cacheWord = 0;
// 	uint8_t value = 0;

//     printf("Starting cache system test...\n\n");

// 	Computer * computerPtr = &computer;

// 	ComputerInitialize(computerPtr);

// 	TestCache(computerPtr);

// 	////Read word from cache, decrement word, write incremented word to cache
// 	//mainMemoryAddress = (uint8_t)0b000000;
// 	//cacheWord = TestCacheRead(computerPtr, mainMemoryAddress);
// 	//value = cacheWord - (uint8_t)1;
// 	//TestCacheReadWrite(computerPtr, mainMemoryAddress, value);

// 	////Read word from cache, decrement word, write incremented word to cache
// 	//mainMemoryAddress = (uint8_t)0b000100;
// 	//cacheWord = TestCacheRead(computerPtr, mainMemoryAddress);
// 	//value = cacheWord - (uint8_t)1;
// 	//TestCacheReadWrite(computerPtr, mainMemoryAddress, value);

// 	////Read word from cache, decrement word, write incremented word to cache
// 	//mainMemoryAddress = (uint8_t)0b001000;
// 	//cacheWord = TestCacheRead(computerPtr, mainMemoryAddress);
// 	//value = cacheWord - (uint8_t)1;
// 	//TestCacheReadWrite(computerPtr, mainMemoryAddress, value);

// 	////Read word from cache, decrement word, write incremented word to cache
// 	//mainMemoryAddress = (uint8_t)0b001100;
// 	//cacheWord = TestCacheRead(computerPtr, mainMemoryAddress);
// 	//value = cacheWord - (uint8_t)1;
// 	//TestCacheReadWrite(computerPtr, mainMemoryAddress, value);

// 	printf("Press the enter key to continue...");
// 	int c = getchar();
// }
