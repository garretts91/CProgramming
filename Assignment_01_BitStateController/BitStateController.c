#include "BitStateController.h"
/*
1 = 0000 0001
2 = 0000 0010
3 = 0000 0011
4 = 0000 0100
5 = 0000 0101
6 = 0000 0110
7 = 0000 0111
8 = 0000 1000
*/
void BitStateControllerSetBitState(BitStateControllerPtr bitStateControllerPtr, enum Bit bit, enum BitState bitState)
{
	switch (bit)
	{
		case None:
			break;
		case Bit_1:
			if (bitState == On) {
				bitStateControllerPtr->bitStates |= BIT_ONE_BIT_MASK;
			} else { 
				bitStateControllerPtr->bitStates &= ~BIT_ONE_BIT_MASK;
			}
			break;
		case Bit_2:
			if (bitState == On) {
				bitStateControllerPtr->bitStates |= BIT_ONE_BIT_MASK;
			} else {
				bitStateControllerPtr->bitStates &= BIT_ONE_BIT_MASK;
			} break;
		case Bit_3:
			if (bitState == On) {
				bitStateControllerPtr->bitStates |= BIT_ONE_BIT_MASK;
			} else {
				bitStateControllerPtr->bitStates &= BIT_ONE_BIT_MASK;
			} break;
		case Bit_4:
			if (bitState == On) {
				bitStateControllerPtr->bitStates |= BIT_ONE_BIT_MASK;
			} else {
				bitStateControllerPtr->bitStates &= BIT_ONE_BIT_MASK;
			} break;
		case Bit_5:
			if (bitState == On) {
				bitStateControllerPtr->bitStates |= BIT_ONE_BIT_MASK;
			} else {
				bitStateControllerPtr->bitStates &= BIT_ONE_BIT_MASK;
			} break;
		case Bit_6:
			if (bitState == On) {
				bitStateControllerPtr->bitStates |= BIT_ONE_BIT_MASK;
			} else {
				bitStateControllerPtr->bitStates &= BIT_ONE_BIT_MASK;
			} break;
		case Bit_7:
			if (bitState == On) {
				bitStateControllerPtr->bitStates |= BIT_ONE_BIT_MASK;
			} else {
				bitStateControllerPtr->bitStates &= BIT_ONE_BIT_MASK;
			} break;	
		case Bit_8:
			if (bitState == On) {
				bitStateControllerPtr->bitStates |= BIT_ONE_BIT_MASK;
			} else {
				bitStateControllerPtr->bitStates &= BIT_ONE_BIT_MASK;
			} break;											
	}
}

enum BitState BitStateControllerGetBitState(BitStateControllerPtr bitStateControllerPtr, enum Bit bit)
{
	enum BitState switchState = Off;
	switch (bit)
    {
        case Bit_1:
            if ((bitStateControllerPtr->bitStates & BIT_ONE_BIT_MASK) != 0) {
                switchState = On;
            }
            break;
	
		return switchState;
	}
}