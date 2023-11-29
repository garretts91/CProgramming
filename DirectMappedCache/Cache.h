#ifndef CACHE_H
#define CACHE_H

/*******************************************************************************
* Module:       Cache
* Developer:    Michael Koepp
* Company:      WWU Computer Science Department
* Create Date:  
* Description:  A Cache object contains a reference to a MainMemory object, and
*               an array of CacheSet objects. Each CacheSet object contains
*               a valid bit, a cache tag, and a cache block.
*******************************************************************************/

#include <stdint.h>
#include <stdbool.h>
#include "MainMemory.h"

//Quantity of bits reserved for the set index, which determines the quantity of cache sets.
//The higher this number is, the fewer the number of cache tags that are needed,
//and the less chance of a cache miss.
#define CACHE_SET_INDEX_BITS 2      //2 bits equates to 4 cache sets
//#define CACHE_SET_INDEX_BITS 3    //3 bits equates to 8 cache sets
#define CACHE_SETS 1 << CACHE_SET_INDEX_BITS // 2 ^ CACHE_SET_INDEX_BITS

//Quantity of bits reserved for the block-offset. Determines the size of a cache set block.
//The higher this number is, the fewer the number of cache sets that are needed.
#define CACHE_BLOCK_OFFSET_BITS 2 
#define CACHE_BLOCK_SIZE 1 << CACHE_BLOCK_OFFSET_BITS // 2 ^ CACHE_BLOCK_OFFSET_BITS

//Quanity of bits remaining for the cache tag. Determines the total quantity of memory blocks
//that must be mapped to cache sets. CACHE_TAGS / CACHE_SETS gives a count of number of memory
//blocks that are mapped to a particular cache set. The higher this number is, the greater the
//chance of a cache conflict miss.
#define CACHE_TAG_BITS (MAIN_MEMORY_ADDRESS_BITS - (CACHE_SET_INDEX_BITS + CACHE_BLOCK_OFFSET_BITS))
#define CACHE_TAGS 1 << CACHE_TAG_BITS // 2 ^ CACHE_TAG_BITS

//BIT MASKS

//Derived from the quantity and position of the CACHE_TAG_BITS. 
//The define below, masks 3 bits, located in the bit positions 4 and 5.
#define CACHE_SET_TAG_BITMASK 0x30 
//The define below, masks 1 bit, located in bit position 5.
//#define CACHE_SET_TAG_MASK 0x20

//Derived from the quantity and position of the CACHE_SET_INDEX_BITS.
//The define below, masks 2 bits, located in bit positions 2 and 3.
#define CACHE_SET_INDEX_BITMASK 0x0C   
//The define below, masks 3 bits, located in bit positions 2, 3 and 4.
//#define CACHE_SET_INDEX_MASK 0x1C

//Derived from the quantity and position of the CACHE_BLOCK_OFFSET_BITS.
//The define below, masks 2 bits, located in bit positions 0 and 1.
#define CACHE_BLOCK_OFFSET_BITMASK 0x03 

//Derived from the size of a main memory address.
#define MAIN_MEMORY_BLOCK_ADDDRESS_BITMASK 0x3C

typedef struct
{
    bool validBit;
    uint8_t tag;
    uint8_t blockValues[CACHE_BLOCK_SIZE];
}CacheSet, *CacheSetPtr;

typedef struct
{
    MainMemoryPtr mainMemoryPtr;
    CacheSet cacheSets[CACHE_SETS];
}Cache, *CachePtr;

void CacheInitialize(CachePtr cachePtr, MainMemoryPtr mainMemoryPtr);
uint8_t CacheReadWord(CachePtr cachePtr, uint8_t memoryAddress);
void CacheWriteWord(CachePtr cachePtr, uint8_t memoryAddress, uint8_t word);
void CacheViewCache(CachePtr cachePtr);

#endif