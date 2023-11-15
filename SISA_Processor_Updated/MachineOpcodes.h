#pragma once

/*******************************************************************************
* Module:       MachineOpcodes
* Developer:    Michael Koepp
* Company:      WWU Computer Science Department
* Create Date:
* Description:
*******************************************************************************/

//Machine Opcodes as 8-bit Integer
#define OPCODE_MOVI_HEX							0x00
#define OPCODE_MOVI_BINARY						0b00000000

#define OPCODE_ADD_HEX							0x01
#define OPCODE_ADD_BINARY						0b00000001
#define OPCODE_SUB_HEX							0x02
#define OPCODE_SUB_BINARY						0b00000010
#define OPCODE_CMP_HEX							0x03
#define OPCODE_CMP_BINARY						0b00000011
#define OPCODE_MUL_HEX							0x04
#define OPCODE_MUL_BINARY						0b00000100
#define OPCODE_DIV_HEX							0x05
#define OPCODE_DIV_BINARY						0b00000101

#define OPCODE_LDR_HEX							0x06
#define OPCODE_LDR_BINARY						0b00000110
#define OPCODE_STR_HEX							0x07
#define OPCODE_STR_BINARY						0b00000111

#define OPCODE_BE_HEX							0x08
#define OPCODE_BE_BINARY						0b00001000
#define OPCODE_BNE_HEX							0x09
#define OPCODE_BNE_BINARY						0b00001001
#define OPCODE_BL_HEX							0x0A
#define OPCODE_BL_BINARY						0b00001010
#define OPCODE_BG_HEX							0x0B
#define OPCODE_BG_BINARY						0b00001011
#define OPCODE_BLE_HEX							0x0C
#define OPCODE_BLE_BINARY						0b00001100
#define OPCODE_BGE_HEX							0x0D
#define OPCODE_BGE_BINARY						0b00001101
#define OPCODE_B_HEX							0x0E
#define OPCODE_B_BINARY							0b00001110

#define OPCODE_HALT_HEX							0x0F
#define OPCODE_HALT_BINARY						0b00001111

//Instruction Bitmasks
#define OPCODE_BITMASK							0xF000
#define RD_Field_BITMASK						0x0F00
#define RT_Field_BITMASK						0x0F00
#define RM_Field_BITMASK						0x00F0
#define RN_Field_BITMASK						0x000F
#define IMM_FIELD_BITMASK						0x00FF
#define BASE_OFFSET_FIELD_BITMASK				0x000F
#define CBRANCH_PC_OFFSET_FIELD_BITMASK			0x00FF
#define UBRANCH_PC_OFFSET_FIELD_BITMASK			0x00FF

//Field Shift Bits
#define OPCODE_BIT_SHIFT						12
#define RD_FIELD_BIT_SHIFT						8
#define RT_FIELD_BIT_SHIFT						8
#define RM_FIELD_BIT_SHIFT						4
#define RN_FIELD_BIT_SHIFT						0
#define IMM_FIELD_BIT_SHIFT						0
#define BASE_OFFSET_FIELD_BIT_SHIFT				0
#define CBRANCH_PC_OFFSET_FIELD_BIT_SHIFT		0
#define UBRANCH_PC_OFFSET_FIELD_BIT_SHIFT		0


