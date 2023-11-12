#pragma once

/*******************************************************************************
* Module:       Controller
* Developer:    Michael Koepp
* Company:      WWU Computer Science Department
* Create Date:
* Description:
*******************************************************************************/

#include <stdint.h>

//BIT MASKS
#define ALU_OP_MOVI_BITMASK									0x0001
#define ALU_OP_MOVI_BITMASK_BINARY							0b0000000000000001
#define ALU_OP_ADD_BITMASK									0x0002
#define ALU_OP_ADD_BITMASK_BINARY							0b0000000000000010
#define ALU_OP_SUB_BITMASK									0x0004
#define ALU_OP_SUB_BITMASK_BINARY							0b0000000000000100
#define ALU_OP_CMP_BITMASK									0x0008
#define ALU_OP_CMP_BITMASK_BINARY							0b0000000000001000
#define ALU_OP_MUL_BITMASK									0x0010
#define ALU_OP_MUL_BITMASK_BINARY							0b0000000000010000
#define ALU_OP_DIV_BITMASK									0x0020
#define ALU_OP_DIV_BITMASK_BINARY							0b0000000000100000

#define REG_WRITE_BITMASK									0x0040
#define REG_WRITE_BITMASK_BINARY							0b0000000001000000

#define MEM_READ_BITMASK									0x0080
#define MEM_READ_BITMASK_BINARY								0b0000000010000000
#define MEM_WRITE_BITMASK									0x0100
#define MEM_WRITE_BITMASK_BINARY							0b0000000100000000

#define CONDITIONAL_BRANCH_BITMASK							0x0200
#define CONDITIONAL_BRANCH_BITMASK_BINARY					0b0000001000000000
#define UNCONDITIONAL_BRANCH_BITMASK						0x0400
#define UNCONDITIONAL_BRANCH_BITMASK_BINARY					0b0000010000000000

#define ALU_INPUT_B_SOURCE_BITMASK					        0x0800
#define ALU_INPUT_B_SOURCE_BITMASK_BINARY			        0b0000100000000000
#define REG_WRITE_SOURCE_BITMASK					        0x1000
#define REG_WRITE_SOURCE_BITMASK_BINARY			            0b0001000000000000
#define PC_SOURCE_BITMASK							0x2000
#define PC_SOURCE_BITMASK_BINARY					0b0010000000000000

#define ALU_OP_MOVI_BIT_SHIFT								0
#define ALU_OP_ADD_BIT_SHIFT								1
#define ALU_OP_SUB_BIT_SHIFT								2
#define ALU_OP_CMP_BIT_SHIFT								3
#define ALU_OP_MUL_BIT_SHIFT								4
#define ALU_OP_DIV_BIT_SHIFT								5
#define REG_WRITE_BIT_SHIFT									6
#define MEM_READ_BIT_SHIFT									7
#define MEM_WRITE_BIT_SHIFT									8
#define CONDITIONAL_BRANCH_BIT_SHIFT						9
#define UNCONDITIONAL_BRANCH_BIT_SHIFT						10
#define ALU_INPUT_B_SOURCE_BIT_SHIFT				11
#define REG_WRITE_SOURCE_BIT_SHIFT					12
#define PC_SOURCE_BIT_SHIFT						13

//Control Signal Flags
#define ALU_OP_SIG_OFF										0
#define ALU_OP_SIG_ON										1

//Control Signal Flags
#define REG_WRITE_FLAG_OFF									0
#define REG_WRITE_FLAG_ON									1

#define MEM_READ_FLAG_OFF									0
#define MEM_READ_FLAG_ON									1

#define MEM_WRITE_FLAG_OFF									0
#define MEM_WRITE_FLAG_ON									1

#define COND_BRANCH_FLAG_OFF								0
#define COND_BRANCH_FLAG_ON									1

#define UNCOND_BRANCH_FLAG_OFF								0
#define UNCOND_BRANCH_FLAG_ON								1

//Multiplexor Data Input Source
#define ALU_INPUT_B_SOURCE_SELECT_REG						0
#define ALU_INPUT_B_SOURCE_SELECT_IMM						1

#define REG_WRITE_SOURCE_SELECT_ALU							0
#define REG_WRITE_SOURCE_SELECT_MEM							1

#define PC_SOURCE_SELECT_NORMAL								0
#define PC_SOURCE_SELECT_BRANCH								1

typedef struct
{
	uint16_t controlRegister;

	uint8_t aluOpAdd;
	uint8_t aluOpSub;
	uint8_t aluOpCmp;
	uint8_t aluOpMul;
	uint8_t aluOpDiv;
	uint8_t aluOpMovi;
	uint8_t regWrite;
	uint8_t memRead;
	uint8_t memWrite;
	uint8_t condBranch;
	uint8_t uncondBranch;
	uint8_t aluInputBSourceSelector;
	uint8_t regWriteSourceSelector;
	uint8_t pcSourceSelector;

}Controller, *ControllerPtr ;

void ControllerSetControlRegister(ControllerPtr controllerPtr, uint8_t opcode);
void ControllerPrintControlRegister(ControllerPtr controllerPtr);
void ControllerSetOptions(int argc, char* argv[]);