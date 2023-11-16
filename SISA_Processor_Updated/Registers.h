#pragma once

/*******************************************************************************
* Module:       Registers
* Developer:    Michael Koepp
* Company:      WWU Computer Science Department
* Create Date:
* Description:
*******************************************************************************/

#include <stdint.h>

#define REGISTER_SET_SIZE 16

#define R0 0
#define R1 1
#define R2 2
#define R3 3
#define R4 4
#define R5 5
#define R6 6
#define R7 7
#define R8 8
#define R9 9
#define R10 10
#define R11 11
#define R12 12
#define R13 13
#define R14 14
#define R15 15

typedef struct
{
	int16_t values[REGISTER_SET_SIZE];

}Registers, *RegistersPtr;

void RegistersPrintRegisterValues(RegistersPtr registerPtr);
