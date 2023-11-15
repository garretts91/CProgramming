#pragma once

/*******************************************************************************
* Module:       ALUController
* Developer:    Michael Koepp
* Company:      WWU Computer Science Department
* Create Date:
* Description:
*******************************************************************************/

#include "Controller.h"
#include <stdint.h>

//Control Signal Flags
#define ALU_OP_SIG_OFF			0
#define ALU_OP_SIG_ON			1

typedef struct
{
	uint16_t controlRegister;

	uint8_t aluOpMovi;
	uint8_t aluOpAdd;
	uint8_t aluOpSub;
	uint8_t aluOpCmp;
	uint8_t aluOpMul;
	uint8_t aluOpDiv;

}ALUController, *ALUControllerPtr ;

void ALUControllerSetControlRegisters(ALUControllerPtr aluControllerPtr, ControllerPtr controllerPtr);
void ALUControllerPrintControlRegister(ALUControllerPtr aluControllerPtr);
void ALUControllerSetOptions(int argc, char* argv[]);