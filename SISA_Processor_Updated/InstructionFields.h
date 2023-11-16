#pragma once

/*******************************************************************************
* Module:       InstructionFields
* Developer:    Michael Koepp
* Company:      WWU Computer Science Department
* Create Date:
* Description:
*******************************************************************************/

#include<stdint.h>

typedef struct
{
    uint8_t opcode;
    uint8_t RD_RT;
    uint8_t RM;
    uint8_t RN;
    int8_t immediate;

}InstructionFields, * InstructionFieldsPtr;

void InstructionFieldsPrintState(InstructionFieldsPtr instructionFieldsPtr);