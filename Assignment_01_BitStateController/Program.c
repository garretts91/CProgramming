#include <stdio.h>
#include <stdint.h>
#include "BitStateController.h"
// #include "BitStateController.c"

int main() 
{
	BitStateController bitStateController = {.bitStates = 0};
	BitStateControllerPtr bitStateControllerPtr = &bitStateController;

	//Input
	enum Bit bit = None;
	enum BitState bitState = Off;

	printf("Enter a bit number OR -1 to exit [1..8]: ");
	int returnValue = scanf("%d", (int*)(&bit));

	while (bit != -1)
	{
		printf("Enter a bit state (0-Off,1-On): ");
		returnValue = scanf("%d", (int*)(&bitState));
		
		BitStateControllerSetBitState(bitStateControllerPtr, bit, bitState);

		printf("\n");

		for (int bitCounter = 1; bitCounter <= BIT_COUNT; bitCounter++)
		{
			enum BitState state = BitStateControllerGetBitState(bitStateControllerPtr, bitCounter);

			printf("Bit State %d: %d\n", bitCounter, state);
		}

		printf("\n");
		printf("Enter a bit number OR -1 to exit [1..8]: ");
		returnValue = scanf("%d", (int*)(&bit));
	}

	printf("\n");
	printf("Press the enter key to continue...");

	int c = getchar();
	c = getchar();

	return 0;
}