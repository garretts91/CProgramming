#pragma once

/*******************************************************************************
* Module:       Multiplexer
* Developer:    Michael Koepp
* Company:      WWU Computer Science Department
* Create Date:
* Description:
*******************************************************************************/

#include <stdint.h>

typedef struct
{
	uint8_t dataSelector;
	uint16_t dataInputA;
	uint16_t dataInputB;

}Multiplexer, *MultiplexerPtr;