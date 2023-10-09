#include "BitStateController.h"

/*
# Date: October 8, 2023
# Description: This is bitStateContoller.c, 
	- the intent is to have 8 bits, of which can be set to off or on (BitStateControllerSetBitState)
	- the next part of the program (BitStateControllerGetBitState) is supposed to check which bits are on,
		- and which ones are off and then output that information to the terminal
	- the files used for this program are: Program.c BitStateController.h and BitStateController.c (this file)
*/

// | operator can set bits
// & operator resets bits 
// bit should be the bit position
// bitState should be the bit state

//  Sets the state of a specific bit in the given BitStateController.
//  bitStateControllerPtr Pointer to the BitStateController structure.
//  bit The bit position to set or reset.
//  bitState The state to set (On) or reset (Off) for the specified bit.
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

// Gets the state of a specific bit in the given BitStateController.
// bitStateControllerPtr Pointer to the BitStateController structure.
// bit gets the bit position that was set or reset.
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