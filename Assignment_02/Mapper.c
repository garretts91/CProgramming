#include "Mapper.h"
#include <stdio.h>

void OutputAsHexCharacters(unsigned int value)
{
	const int NIBBLES_PER_BYTE = 2;
	const int NIBBLE_COUNT = sizeof(unsigned int) * NIBBLES_PER_BYTE;
	const int BITS_PER_NIBBLE = 4;

	unsigned int mask = 0xF0000000;

	printf("\n");

	for (int count = 0; count < NIBBLE_COUNT; count++)
	{
		




	}
	
	printf("\n");
}

unsigned char MapNibbleToHexCharacter(unsigned int value)
{
	unsigned char lookUpTable[] = {'0', '1', '2', '3', '4', '5', '6', '7', 
							 '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

	return lookUpTable[value];
}
