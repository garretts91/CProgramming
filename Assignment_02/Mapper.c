// Write a program that prompts the user for an unsigned integer number.
//  An unsigned integer is allocated 4 bytes. With 8 bits per byte, and 4 bits per
// nibble, an unsigned integer has 8 nibbles.
//  Create a function named OutputAsHexCharacters. This function receives an
// unsigned integer and returns void. The prototype is shown below. The
// function should:
// o Bitwise-mask each 4-bit nibble in the unsigned integer parameter.
// o Pass each 4-bit nibble to a function named MapNibbleToHexCharacter.
//  MapNibbleToHexCharacter receives the 4-bit nibble as an unsigned integer
// and returns an unsigned char. The prototype is shown below. The function
// should:
// o Determine the equivalent hexadecimal character and return the
// hexadecimal character.
// o Hint: Try using the 4-bit nibble as an index into an array of characters,
// where each character is the hexadecimal representation of the 4-bit
// nibble. This isn’t strictly necessary, but fun to try!
// we want the output to look like:
// Enter an unsigned integer value: 15
// Hexadecimal Character: 0
// Hexadecimal Character: 0
// Hexadecimal Character: 0
// Hexadecimal Character: 0
// Hexadecimal Character: 0
// Hexadecimal Character: 0
// Hexadecimal Character: 0
// Hexadecimal Character: F
// Function Prototypes:
// void OutputAsHexCharacters(unsigned int value);
// unsigned char MapNibbleToHexCharacter(unsigned int value);

#include "Mapper.h"
#include <stdio.h>

void OutputAsHexCharacters(unsigned int value)
{
	const int NIBBLES_PER_BYTE = 2;
	const int NIBBLE_COUNT = sizeof(unsigned int) * NIBBLES_PER_BYTE;
	const int BITS_PER_NIBBLE = 4;

	unsigned int mask = 0xF0000000;

	printf("\n");

	// loop through the 8 nibbles 
    for (int count = 0; count < NIBBLE_COUNT; count++) {
		// printf("Current Mask: 0x%08X\n", mask); // Print the current mask

		// extract a nibble from the input value using a bit mask
		// shift that nibble from the most significant to least significant position
        unsigned int nibble = (value & mask) >> (BITS_PER_NIBBLE * (NIBBLE_COUNT - 1 - count));
		// printf("The value of nibble is: 0x%02X\n", nibble);

		// map and print the nibble to its hex character
        char hexChar = MapNibbleToHexCharacter(nibble);
        printf("Hexadecimal Character: %c\n", hexChar);
		
		// move the mask to the next nibble position
        mask >>= BITS_PER_NIBBLE;
    }

	printf("\n");
}

unsigned char MapNibbleToHexCharacter(unsigned int value)
{
	unsigned char lookUpTable[] = {'0', '1', '2', '3', '4', '5', '6', '7', 
							 '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

	return lookUpTable[value];
}
