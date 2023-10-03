#pragma once
#include <stdint.h>

#define BIT_COUNT 8

#define BIT_ONE_BIT_MASK 0X01
#define BIT_TWO_BIT_MASK 0X02
#define BIT_THREE_BIT_MASK 0X04
#define BIT_FOUR_BIT_MASK 0X08
#define BIT_FIVE_BIT_MASK 0X10
#define BIT_SIX_BIT_MASK 0X20
#define BIT_SEVEN_BIT_MASK 0X40
#define BIT_EIGHT_BIT_MASK 0X80

enum  Bit
{
	None,
	Bit_1, 
	Bit_2, 
	Bit_3, 
	Bit_4, 
	Bit_5, 
	Bit_6, 
	Bit_7, 
	Bit_8
};

enum  BitState
{
	Off,
	On
};

typedef struct
{
	uint8_t bitStates;

}BitStateController, *BitStateControllerPtr;

void BitStateControllerSetBitState(BitStateControllerPtr bitStaterPtr, enum Bit bit, enum BitState bitState);
enum BitState BitStateControllerGetBitState(BitStateControllerPtr bitStaterPtr, enum Bit bit);

