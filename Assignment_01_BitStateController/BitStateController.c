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
// | operator can set bits
// & operator resets bits 
// bit should be the bit position
// bitState should be the bit state

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
				bitStateControllerPtr->bitStates |= BIT_TWO_BIT_MASK;
			} else {
				bitStateControllerPtr->bitStates &= ~BIT_TWO_BIT_MASK;
			} 
			break;
		case Bit_3:
			if (bitState == On) {
				bitStateControllerPtr->bitStates |= BIT_THREE_BIT_MASK;
			} else {
				bitStateControllerPtr->bitStates &= ~BIT_THREE_BIT_MASK;
			} 
			break;
		case Bit_4:
			if (bitState == On) {
				bitStateControllerPtr->bitStates |= BIT_FOUR_BIT_MASK;
			} else {
				bitStateControllerPtr->bitStates &= ~BIT_FOUR_BIT_MASK;
			} 
			break;
		case Bit_5:
			if (bitState == On) {
				bitStateControllerPtr->bitStates |= BIT_FIVE_BIT_MASK;
			} else {
				bitStateControllerPtr->bitStates &= ~BIT_FIVE_BIT_MASK;
			} 
			break;
		case Bit_6:
			if (bitState == On) {
				bitStateControllerPtr->bitStates |= BIT_SIX_BIT_MASK;
			} else {
				bitStateControllerPtr->bitStates &= ~BIT_SIX_BIT_MASK;
			} 
			break;
		case Bit_7:
			if (bitState == On) {
				bitStateControllerPtr->bitStates |= BIT_SEVEN_BIT_MASK;
			} else {
				bitStateControllerPtr->bitStates &= ~BIT_SEVEN_BIT_MASK;
			} 
			break;	
		case Bit_8:
			if (bitState == On) {
				bitStateControllerPtr->bitStates |= BIT_EIGHT_BIT_MASK;
			} else {
				bitStateControllerPtr->bitStates &= ~BIT_EIGHT_BIT_MASK;
			} 
			break;											
		default:
			printf("Please enter a valid argument");
			break;
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
            } else {
				switchState = Off;
			}
            break;
		case Bit_2:
			if ((bitStateControllerPtr->bitStates & BIT_TWO_BIT_MASK) != 0) {
				switchState = On;
			} else {
				switchState = Off;
			}
			break;
		case Bit_3:
			if ((bitStateControllerPtr->bitStates & BIT_THREE_BIT_MASK) != 0) {
				switchState = On;
			} else {
				switchState = Off;
			}
			break;
		case Bit_4:
			if ((bitStateControllerPtr->bitStates & BIT_FOUR_BIT_MASK) != 0) {
				switchState = On;
			} else {
				switchState = Off;
			}
			break;
		case Bit_5:
			if ((bitStateControllerPtr->bitStates & BIT_FIVE_BIT_MASK) != 0) {
				switchState = On;
			} else {
				switchState = Off;
			}
			break;
		case Bit_6:
			if ((bitStateControllerPtr->bitStates & BIT_SIX_BIT_MASK) != 0) {
				switchState = On;
			} else {
				switchState = Off;
			}
			break;
		case Bit_7:
			if ((bitStateControllerPtr->bitStates & BIT_SEVEN_BIT_MASK) != 0) {
				switchState = On;
			} else {
				switchState = Off;
			}
			break;
		case Bit_8:
			if ((bitStateControllerPtr->bitStates & BIT_EIGHT_BIT_MASK) != 0) {
				switchState = On;
			} else {
				switchState = Off;
			}
			break;									
		default:
			printf("Please enter a valid argument");
			break;
	}
	return switchState;
}