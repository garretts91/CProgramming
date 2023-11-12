#include <stdio.h>
#include "InstructionFields.h"
#include "PrintingFormats.h"
#include "MachineOpcodes.h"
#include "InstructionOpcodes.h"
#include "RegisterSet.h"

//PRIVATE FUNCTION PROTOTYPES
void PrintDecodedMachineInstruction(InstructionFieldsPtr instructionFieldsPtr);
char* MapMachineOpcodeToAssemblyMnemonic(uint8_t machineOpcode);
char* MapMachineRegisterToAssemblyRegister(uint8_t machineRegister);

void InstructionFieldsPrintState(InstructionFieldsPtr instructionFieldsPtr)
{
    PrintDecodedMachineInstruction(instructionFieldsPtr);
    
    printf("Opcode:            Hex: 0x%1X          ", instructionFieldsPtr->opcode);
    printf("Binary: ");
    printf(FOUR_BIT_NIBBLE_TO_BINARY_PATTERN, FOUR_BIT_NIBBLE_TO_BINARY(instructionFieldsPtr->opcode));
    printf("\n");

    printf("RD/RT Register:    Hex: 0x%1X          ", instructionFieldsPtr->RD_RT);
    printf("Binary: ");
    printf(FOUR_BIT_NIBBLE_TO_BINARY_PATTERN, FOUR_BIT_NIBBLE_TO_BINARY(instructionFieldsPtr->RD_RT));
    printf("\n");

    printf("RM Register:       Hex: 0x%1X          ", instructionFieldsPtr->RM);
    printf("Binary: ");
    printf(FOUR_BIT_NIBBLE_TO_BINARY_PATTERN, FOUR_BIT_NIBBLE_TO_BINARY(instructionFieldsPtr->RM));
    printf("\n");

    printf("RN Register:       Hex: 0x%1X          ", instructionFieldsPtr->RN);
    printf("Binary: ");
    printf(FOUR_BIT_NIBBLE_TO_BINARY_PATTERN, FOUR_BIT_NIBBLE_TO_BINARY(instructionFieldsPtr->RN));
    printf("\n");

    printf("Immediate Value:   Hex: 0x%03hhX        ", instructionFieldsPtr->immediate);
    printf("Binary: ");
    printf(EIGHT_BIT_BYTE_TO_BINARY_PATTERN, EIGHT_BIT_BYTE_TO_BINARY(instructionFieldsPtr->immediate));
    printf("\n");

    printf("\n");
}

void PrintDecodedMachineInstruction(InstructionFieldsPtr instructionFieldsPtr)
{
    printf("Assembly Instruction: ");

    char* assemblyMnemonic = MapMachineOpcodeToAssemblyMnemonic(instructionFieldsPtr->opcode);
    printf("%s ", assemblyMnemonic);

    if (assemblyMnemonic == MOVI)
    {
        char* assemblyRegisterRT_RD = MapMachineRegisterToAssemblyRegister(instructionFieldsPtr->RD_RT);
        printf("%s, ", assemblyRegisterRT_RD);
        printf("%d", instructionFieldsPtr->immediate);
    }

    if (assemblyMnemonic == ADD || assemblyMnemonic == SUB || assemblyMnemonic == CMP
        || assemblyMnemonic == MUL || assemblyMnemonic == DIV)
    {
        char* assemblyRegisterRT_RD = MapMachineRegisterToAssemblyRegister(instructionFieldsPtr->RD_RT);
        char* assemblyRegisterRM = MapMachineRegisterToAssemblyRegister(instructionFieldsPtr->RM);
        char* assemblyRegisterRN = MapMachineRegisterToAssemblyRegister(instructionFieldsPtr->RN);

        printf("%s, ", assemblyRegisterRT_RD);
        printf("%s, ", assemblyRegisterRM);
        printf("%s", assemblyRegisterRN);
    }
    
    if (assemblyMnemonic == LDR || assemblyMnemonic == STR)
    {
        char* assemblyRegisterRT_RD = MapMachineRegisterToAssemblyRegister(instructionFieldsPtr->RD_RT);
        char* assemblyRegisterRM = MapMachineRegisterToAssemblyRegister(instructionFieldsPtr->RM);
        
        printf("%s, ", assemblyRegisterRT_RD);
        printf("[%s + ", assemblyRegisterRM);
        printf("%d]", instructionFieldsPtr->immediate);
    }

    if (assemblyMnemonic == BE || assemblyMnemonic == BNE || assemblyMnemonic == BL
        || assemblyMnemonic == BG || assemblyMnemonic == BLE || assemblyMnemonic == BGE)
    {
        char* assemblyRegisterRT_RD = MapMachineRegisterToAssemblyRegister(instructionFieldsPtr->RD_RT);
        
        printf("%s, ", assemblyRegisterRT_RD);
        printf("%d", instructionFieldsPtr->immediate);
    }

    if (assemblyMnemonic == B)
    {
        char* assemblyRegisterRT_RD = MapMachineRegisterToAssemblyRegister(instructionFieldsPtr->RD_RT);

        printf("%d", instructionFieldsPtr->immediate);
    }

    
    printf("\n\n");

}
char* MapMachineOpcodeToAssemblyMnemonic(uint8_t machineOpcode)
{
    char* assemblyMnemonic = NULL;

    if (machineOpcode == OPCODE_MOVI_HEX) assemblyMnemonic = MOVI;
    if (machineOpcode == OPCODE_ADD_HEX) assemblyMnemonic = ADD;
    if (machineOpcode == OPCODE_SUB_HEX) assemblyMnemonic = SUB;
    if (machineOpcode == OPCODE_CMP_HEX) assemblyMnemonic = CMP;
    if (machineOpcode == OPCODE_MUL_HEX) assemblyMnemonic = MUL;
    if (machineOpcode == OPCODE_DIV_HEX) assemblyMnemonic = DIV;
    if (machineOpcode == OPCODE_LDR_HEX) assemblyMnemonic = LDR;
    if (machineOpcode == OPCODE_STR_HEX) assemblyMnemonic = STR;
    if (machineOpcode == OPCODE_BE_HEX) assemblyMnemonic = BE;
    if (machineOpcode == OPCODE_BNE_HEX) assemblyMnemonic = BNE;
    if (machineOpcode == OPCODE_BL_HEX) assemblyMnemonic = BL;
    if (machineOpcode == OPCODE_BG_HEX) assemblyMnemonic = BG;
    if (machineOpcode == OPCODE_BLE_HEX) assemblyMnemonic = BLE;
    if (machineOpcode == OPCODE_BGE_HEX) assemblyMnemonic = BGE;
    if (machineOpcode == OPCODE_B_HEX) assemblyMnemonic = B;
    if (machineOpcode == OPCODE_HALT_HEX) assemblyMnemonic = HALT;

    return assemblyMnemonic;
}

char* MapMachineRegisterToAssemblyRegister(uint8_t machineRegister)
{
    char* assemblyRegister = NULL;

    if (machineRegister == 0) assemblyRegister = ACRO_R0;
    if (machineRegister == 1) assemblyRegister = ACRO_R1;
    if (machineRegister == 2) assemblyRegister = ACRO_R2;
    if (machineRegister == 3) assemblyRegister = ACRO_R3;
    if (machineRegister == 4) assemblyRegister = ACRO_R4;
    if (machineRegister == 5) assemblyRegister = ACRO_R5;
    if (machineRegister == 6) assemblyRegister = ACRO_R6;
    if (machineRegister == 7) assemblyRegister = ACRO_R7;
    if (machineRegister == 8) assemblyRegister = ACRO_R8;
    if (machineRegister == 9) assemblyRegister = ACRO_R9;
    if (machineRegister == 10) assemblyRegister = ACRO_R10;
    if (machineRegister == 11) assemblyRegister = ACRO_R11;
    if (machineRegister == 12) assemblyRegister = ACRO_R12;
    if (machineRegister == 13) assemblyRegister = ACRO_R13;
    if (machineRegister == 14) assemblyRegister = ACRO_R14;
    if (machineRegister == 15) assemblyRegister = ACRO_R15;

    return assemblyRegister;

}

