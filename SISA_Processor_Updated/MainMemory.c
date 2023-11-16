#include <stdio.h>
#include<string.h>
#include "MainMemory.h"

#define PRINT_MEMORY_VALUES 1
#define PRINT_DATA_SEGMENT_MEMORY_VALUES 1
#define PRINT_CODE_SEGMENT_MEMORY_VALUES 1

//MODULE LEVEL VARIABLES
int printMemoryValues = 0;
int printDataSegmentMemoryValues = 0;
int printCodeSegmentMemoryValues = 0;

void MainMemoryInitialize(MainMemoryPtr mainMemoryPtr)
{
    for (int index = 0; index < MAIN_MEMORY_SIZE; index++)
    {
        mainMemoryPtr->values[index] = 0;
    }
}

void MainMemoryPrintValues(MainMemoryPtr mainMemoryPtr, int16_t startAddress, int16_t endAddress, char* title)
{
	if (printMemoryValues == PRINT_MEMORY_VALUES)
	{
		int memoryValueCounter = 0;

		printf("%s:\n", title);

		for (int address = startAddress; address < endAddress; address++)
		{
			printf("%02d: 0x%04hX ", address, mainMemoryPtr->values[address]);

			if ((memoryValueCounter + 1) % 4 == 0) printf("\n");

			memoryValueCounter++;
		}

		printf("\n");
	}
}

void MainMemoryPrintDataSegmentValues(MainMemoryPtr mainMemoryPtr, int16_t startAddress, int16_t endAddress)
{
	if (printDataSegmentMemoryValues == PRINT_DATA_SEGMENT_MEMORY_VALUES)
	{
		int memoryValueCounter = 0;

		printf("Data Segment Memory:\n");

		for (int address = startAddress; address < endAddress; address++)
		{
			printf("%02d: 0x%04hX ", address, mainMemoryPtr->values[address]);

			if ((memoryValueCounter + 1) % 4 == 0) printf("\n");

			memoryValueCounter++;
		}

		printf("\n\n");
	}
}

void MainMemoryPrintCodeSegmentValues(MainMemoryPtr mainMemoryPtr, int16_t startAddress, int16_t endAddress)
{
	if (printCodeSegmentMemoryValues == PRINT_CODE_SEGMENT_MEMORY_VALUES)
	{
		int memoryValueCounter = 0;

		printf("Code Segment Memory:\n");

		for (int address = startAddress; address < endAddress; address++)
		{
			printf("%02d: 0x%04hX ", address, mainMemoryPtr->values[address]);

			if ((memoryValueCounter + 1) % 4 == 0) printf("\n");

			memoryValueCounter++;
		}

		printf("\n\n");
	}
}

void MainMemorySetOptions(int argc, char* argv[])
{
	for (int commandLineParameter = 1; commandLineParameter < argc; commandLineParameter++)
	{
		int result = strcmp(argv[commandLineParameter], "-mem");

		if (result == 0)
		{
			printMemoryValues = PRINT_MEMORY_VALUES;
			printDataSegmentMemoryValues = PRINT_DATA_SEGMENT_MEMORY_VALUES;
			printCodeSegmentMemoryValues = PRINT_CODE_SEGMENT_MEMORY_VALUES;
		}

		result = strcmp(argv[commandLineParameter], "-dmem");

		if (result == 0) printDataSegmentMemoryValues = PRINT_DATA_SEGMENT_MEMORY_VALUES;

		result = strcmp(argv[commandLineParameter], "-cmem");

		if (result == 0) printCodeSegmentMemoryValues = PRINT_CODE_SEGMENT_MEMORY_VALUES;
	}
}