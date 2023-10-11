#include "Mapper.h"
#include <stdio.h>

void OutputAsHexCharacters(unsigned int value)
{
    const int NIBBLES_PER_BYTE = 2;
    const int NIBBLE_COUNT = sizeof(unsigned int) * NIBBLES_PER_BYTE;
    const int BITS_PER_NIBBLE = 4;

    unsigned int mask = 0xF0000000;
    unsigned int fullMask = 0; // Initialize to 0 to accumulate the nibbles

    printf("\n");

    for (int count = 0; count < NIBBLE_COUNT; count++) {
        int shiftAmount = (NIBBLE_COUNT - 1 - count) * BITS_PER_NIBBLE;
        unsigned int nibble = (value & mask) >> shiftAmount;
        printf("The value of nibble is: 0x%02X\n", nibble);
        char hexChar = MapNibbleToHexCharacter(nibble);
        printf("Hexadecimal Character: %c\n", hexChar);
        fullMask |= (nibble << shiftAmount); // Accumulate the nibbles into the fullMask
        mask >>= BITS_PER_NIBBLE;
    }

    // Print the full mask after the loop completes
    printf("Full Mask: 0x%08X\n", fullMask);

    printf("\n");
}

unsigned char MapNibbleToHexCharacter(unsigned int value)
{
    unsigned char lookUpTable[] = {'0', '1', '2', '3', '4', '5', '6', '7',
                                    '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

    return lookUpTable[value];
}