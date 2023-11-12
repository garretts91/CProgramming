#pragma once

/*******************************************************************************
* Module:       Adder
* Developer:    Michael Koepp
* Company:      WWU Computer Science Department
* Create Date:
* Description:  
*******************************************************************************/

#include <stdint.h>

typedef struct
{
	uint16_t dataInputA;
	uint16_t dataInputB;
	uint16_t dataOutput;

}Adder, *AdderPtr;