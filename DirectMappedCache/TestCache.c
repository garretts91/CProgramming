#include "TestCache.h"
#include "PrintingFormats.h"
#include <stdio.h>

void TestCache(ComputerPtr computerPtr)
{
    CacheViewCache(computerPtr->cpuPtr->cachePtr);

    for (int cacheSetTag = 0; cacheSetTag < CACHE_TAGS; cacheSetTag++)
    {
        for (int cacheSetIndex = 0; cacheSetIndex < CACHE_SETS; cacheSetIndex++)
        {
            TestCacheSet(computerPtr, cacheSetTag, cacheSetIndex);
            
            CacheViewCache(computerPtr->cpuPtr->cachePtr);
        }
    }
}
void TestCacheSet(ComputerPtr computerPtr, int cacheSetTag, int cacheSetIndex)
{
    uint8_t cacheSetTagShifted = (uint8_t)(cacheSetTag << (CACHE_SET_INDEX_BITS + CACHE_BLOCK_OFFSET_BITS));
    uint8_t cacheSetIndexShifted = (uint8_t)(cacheSetIndex << CACHE_BLOCK_OFFSET_BITS);

    printf("*************************** BEGIN TEST CACHE SET **************************\n\n");
    
    printf("Cache Set Tag:   %d ", cacheSetTag);
    printf("Binary: ");
    printf(CACHE_SET_TAG_BYTE_TO_BINARY_PATTERN, SIX_BIT_BYTE_TO_BINARY(cacheSetTagShifted));
    printf("\n");

    printf("Cache Set Index: %d ", cacheSetIndex);
    printf("Binary: ");
    printf(CACHE_SET_INDEX_BYTE_TO_BINARY_PATTERN, SIX_BIT_BYTE_TO_BINARY(cacheSetIndexShifted));
    printf("\n\n");

    uint8_t address = (uint8_t)(cacheSetTagShifted | cacheSetIndexShifted | 0b000000);
    uint8_t word = CPUReadWord(computerPtr->cpuPtr, address);
    printf("Decimal Address: %d Hex Address: 0x%02hhx ", address, address);
    printf("Binary Address: ");
    printf(CACHE_SET_BLOCK_OFFSET_BYTE_TO_BINARY_PATTERN, SIX_BIT_BYTE_TO_BINARY(address));
    printf("\tWord: %d", word);
    printf("\n");

    address = (uint8_t)(cacheSetTagShifted | cacheSetIndexShifted | 0b000001);
    word = CPUReadWord(computerPtr->cpuPtr, address);
    printf("Decimal Address: %d Hex Address: 0x%02hhx ", address, address);
    printf("Binary Address: ");
    printf(CACHE_SET_BLOCK_OFFSET_BYTE_TO_BINARY_PATTERN, SIX_BIT_BYTE_TO_BINARY(address));
    printf("\tWord: %d", word);
    printf("\n");

    address = (uint8_t)(cacheSetTagShifted | cacheSetIndexShifted | 0b000010);
    word = CPUReadWord(computerPtr->cpuPtr, address);
    printf("Decimal Address: %d Hex Address: 0x%02hhx ", address, address);
    printf("Binary Address: ");
    printf(CACHE_SET_BLOCK_OFFSET_BYTE_TO_BINARY_PATTERN, SIX_BIT_BYTE_TO_BINARY(address));
    printf("\tWord: %d", word);
    printf("\n");

    address = (uint8_t)(cacheSetTagShifted | cacheSetIndexShifted | 0b000011);
    word = CPUReadWord(computerPtr->cpuPtr, address);
    printf("Decimal Address: %d Hex Address: 0x%02hhx ", address, address);
    printf("Binary Address: ");
    printf(CACHE_SET_BLOCK_OFFSET_BYTE_TO_BINARY_PATTERN, SIX_BIT_BYTE_TO_BINARY(address));
    printf("\tWord: %d", word);
    printf("\n");
    printf("\n");
    printf("**************************** END TEST CACHE SET ***************************\n\n");
}

uint8_t TestCacheRead(ComputerPtr computerPtr, uint8_t address)
{
    uint8_t cacheWordRead = 0;

    printf("***************************** TEST CACHE READ *****************************\n\n");

    CacheViewCache(computerPtr->cpuPtr->cachePtr);

    printf("[Binary Address: ");
    printf(SIX_BIT_BYTE_TO_BINARY_PATTERN, SIX_BIT_BYTE_TO_BINARY(address));
    printf("] ");
    printf("[Hex Address: 0x%02hhx] [Decimal Address: %d]  ", address, address);
    printf("\n");

    cacheWordRead = CPUReadWord(computerPtr->cpuPtr, address);
    printf("Cache word read:  %d \n\n", cacheWordRead);

    CacheViewCache(computerPtr->cpuPtr->cachePtr);

    printf("*************************** END TEST CACHE READ ***************************\n\n");

    return cacheWordRead;
}

bool TestCacheReadWrite(ComputerPtr computerPtr, uint8_t address, uint8_t word)
{
    bool testCasePass = true;

    printf("************************* TEST CACHE READ AND WRITE ************************\n\n");

    CacheViewCache(computerPtr->cpuPtr->cachePtr);

    printf("[Decimal Address: %d] [Hex Address: 0x%02hhx] ", address, address);
    printf("[Binary Address: ");
    printf(SIX_BIT_BYTE_TO_BINARY_PATTERN, SIX_BIT_BYTE_TO_BINARY(address));
    printf("]\n");

    uint8_t loadedWord = CPUReadWord(computerPtr->cpuPtr, address);
    printf("Step 1: Read cache word:  %d \n", loadedWord);

    printf("Step 2: Write word to cache: %d \n", word);
    CPUWriteWord(computerPtr->cpuPtr, address, word);

    loadedWord = CPUReadWord(computerPtr->cpuPtr, address);
    printf("Step 3: Read cache word:  %d \n\n", loadedWord);

    if (loadedWord != word) testCasePass = false;

    CacheViewCache(computerPtr->cpuPtr->cachePtr);

    printf("*********************** END TEST CACHE READ AND WRITE **********************\n\n");

    return testCasePass;
}

