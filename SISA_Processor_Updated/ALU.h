#pragma once

/*******************************************************************************
* Module:       ALU
* Developer:    Michael Koepp
* Company:      WWU Computer Science Department
* Create Date:
* Description:
*******************************************************************************/

#include <stdint.h>

#define ALU_FLAG_OFF	0
#define ALU_FLAG_ON		1

typedef struct
{
	int16_t dataInputA;
	int16_t dataInputB;
	int16_t dataOutput;

	bool zeroFlag;
	bool lessZeroFlag;
	bool greaterZeroFlag;
	
}ALU, *ALU_Ptr;