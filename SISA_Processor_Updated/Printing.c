#include <stdio.h>
#include "Printing.h"

void printBits(size_t const datatypeSize, void const* const voidPtr)
{
    unsigned char* bytesPtr = (unsigned char*)voidPtr;
       
    for (int byteIndex = datatypeSize - 1; byteIndex >= 0; byteIndex--) 
    {
        for (int bit = 7; bit >= 0; bit--) 
        {
            unsigned char byte = (bytesPtr[byteIndex] >> bit) & 1;

            printf("%u", byte);
        }
    }
    puts("");
}