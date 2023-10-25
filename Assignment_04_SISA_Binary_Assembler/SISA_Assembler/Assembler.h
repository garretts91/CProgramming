#pragma once

#define ASSEMBLY_STATEMENT_BUFFER_SIZE 25

#define OPCODE_SHIFT 12
#define RT_REG_SHIFT 8
#define RM_REG_SHIFT 4
#define RN_REG_SHIFT 0
#define IMM_4_BIT_SHIFT 4
#define IMM_8_BIT_SHIFT 0
#define DATA_MEMORY_OFFSET_BIT_SHIFT 0
#define COND_BR_PC_OFFSET_BIT_SHIFT 0
#define UCOND_BR_PC_OFFSET_BIT_SHIFT 0

void assemble(char* assemblyFilename, char* objectCodeFilename);

