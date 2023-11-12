#include <stdio.h>
#include <string.h>
#include "CPU.h"
#include "MachineOpcodes.h"
#include "InstructionFields.h"
#include "PrintingFormats.h"

#define PAUSE_AFTER_INSTRUCTION_PROCESSED 1

//PRIVATE FUNCTION PROTOTYPES
void CPUFetchInstruction(CPU_Ptr cpuPtr);
void CPUDecodeInstruction(CPU_Ptr cpuPtr, InstructionFieldsPtr instructionFieldsPtr);
void CPUExecuteInstruction(CPU_Ptr cpuPtr, InstructionFieldsPtr instructionFieldsPtr);
void CPUParseInstruction(CPU_Ptr cpuPtr, InstructionFieldsPtr instructionFieldsPtr);
void CPUSetMultiplexers(CPU_Ptr cpuPtr, ControllerPtr controllerPtr);
void CPUReadALUSourceRegisters(CPU_Ptr cpuPtr, InstructionFieldsPtr instructionFieldsPtr);
void CPUExecuteALU(CPU_Ptr cpuPtr, InstructionFieldsPtr instructionFieldsPtr);
void CPUWriteToDestinationRegister(CPU_Ptr cpuPtr, InstructionFieldsPtr instructionFieldsPtr);
void CPUWriteRegisterToMemory(CPU_Ptr cpuPtr, InstructionFieldsPtr instructionFieldsPtr);
void CPUPrintDecodedInformation(CPU_Ptr cpuPtr, uint16_t instructionCounter, InstructionFieldsPtr instructionFieldsPtr);
void CPUPrintExecutionStateInformation(CPU_Ptr cpuPtr, InstructionFieldsPtr instructionFieldsPtr, uint16_t startingMainMemoryAddress, int programSize);
void CPUPrintInstruction(CPU_Ptr cpuPtr, uint16_t instructionCounter, InstructionFieldsPtr instructionFieldsPtr);

//MODULE LEVEL VARIABLES
int pauseAfterInstructionProcessed = 0;

void CPUInitialize(CPU_Ptr cpuPtr, MainMemoryPtr mainMemoryPtr)
{
    cpuPtr->aluPtr = &cpuPtr->alu;
    cpuPtr->registersPtr = &cpuPtr->registers;
    cpuPtr->mmuPtr = &cpuPtr->mmu;
    cpuPtr->controllerPtr = &cpuPtr->controller;
    cpuPtr->aluControllerPtr = &cpuPtr->aluController;
    cpuPtr->pcNextAdderPtr = &cpuPtr->pcNextAdder;
    cpuPtr->pcBranchOffsetAdderPtr = &cpuPtr->pcBranchOffsetAdder;
    cpuPtr->registerWriteDataSourceMultiplexerPtr = &cpuPtr->registerWriteDataSourceMultiplexer;
    cpuPtr->aluDataInputBSourceMultiplexerPtr = &cpuPtr->aluInputBSourceMultiplexer;
    cpuPtr->pcSourceMultiplexerPtr = &cpuPtr->pcSourceMultiplexer;
    
    MMUInitialize(cpuPtr->mmuPtr, mainMemoryPtr);
}

int16_t CPUExecuteProgram(CPU_Ptr cpuPtr, uint16_t startingMainMemoryAddress, int programSize)
{
    uint16_t instructionCounter = 0;

    InstructionFields instructionFields;
    InstructionFieldsPtr instructionFieldsPtr;
    instructionFieldsPtr = &instructionFields;

    cpuPtr->PC_Register = startingMainMemoryAddress;
    
    do
    {
        instructionCounter++;

        //Fetch
        CPUFetchInstruction(cpuPtr);
        CPUPrintInstruction(cpuPtr, instructionCounter, instructionFieldsPtr);

        //Decode
        CPUDecodeInstruction(cpuPtr, instructionFieldsPtr);
        CPUPrintDecodedInformation(cpuPtr, instructionCounter, instructionFieldsPtr);
        
        //Execute
        CPUExecuteInstruction(cpuPtr, instructionFieldsPtr);
        
        //Print state information
        CPUPrintExecutionStateInformation(cpuPtr, instructionFieldsPtr, startingMainMemoryAddress, programSize);
        
        printf("*************************END PROCESSING INSTRUCTION*************************\n\n");

        if (pauseAfterInstructionProcessed == PAUSE_AFTER_INSTRUCTION_PROCESSED)
        {
            printf("Press enter key to execute next instruction...\n");
            int c = getchar();
        }

    } while (instructionFields.opcode != OPCODE_HALT_HEX);

    return cpuPtr->registers.values[R0];
}

void CPUFetchInstruction(CPU_Ptr cpuPtr)
{
    uint16_t instruction = cpuPtr->mmuPtr->mainMemoryPtr->values[cpuPtr->PC_Register];

    cpuPtr->IR_Register = instruction;
}

//Determine the opcode, register addresses, and constant value.
//The constant values could be an 8-bit immediate for a MOVI instruction, 
//a 4-bit offset value for a LDR/STR instruction, an 8-bit immediate for a conditional instruction
//or a 12-bit offset for an unconditional instruction.
void CPUDecodeInstruction(CPU_Ptr cpuPtr, InstructionFieldsPtr instructionFieldsPtr)
{
    CPUParseInstruction(cpuPtr, instructionFieldsPtr);

    ControllerSetControlRegister(cpuPtr->controllerPtr, instructionFieldsPtr->opcode);

    ALUControllerSetControlRegisters(cpuPtr->aluControllerPtr, cpuPtr->controllerPtr);

    CPUSetMultiplexers(cpuPtr, cpuPtr->controllerPtr);
}

void CPUExecuteInstruction(CPU_Ptr cpuPtr, InstructionFieldsPtr instructionFieldsPtr)
{
    if (cpuPtr->controller.uncondBranch == UNCOND_BRANCH_FLAG_OFF)
    {
        CPUReadALUSourceRegisters(cpuPtr, instructionFieldsPtr);

        CPUExecuteALU(cpuPtr, instructionFieldsPtr);

        if (cpuPtr->controller.memWrite == MEM_WRITE_FLAG_OFF)
            CPUWriteToDestinationRegister(cpuPtr, instructionFieldsPtr);

        if (cpuPtr->controller.memWrite == MEM_WRITE_FLAG_ON)
            CPUWriteRegisterToMemory(cpuPtr, instructionFieldsPtr);

        if (cpuPtr->controller.condBranch == COND_BRANCH_FLAG_ON)
        {
            if (instructionFieldsPtr->opcode == OPCODE_BE_HEX)
            {
                if (cpuPtr->alu.zeroFlag == ALU_FLAG_ON)
                {
                    int8_t byteToWordAdjustment = instructionFieldsPtr->immediate >> 1;

                    cpuPtr->PC_Register = cpuPtr->PC_Register + byteToWordAdjustment;
                }
                else (cpuPtr->PC_Register)++;
            }

            if (instructionFieldsPtr->opcode == OPCODE_BNE_HEX)
            {
                if (cpuPtr->alu.zeroFlag == ALU_FLAG_OFF)
                {
                    int8_t byteToWordAdjustment = instructionFieldsPtr->immediate >> 1;

                    cpuPtr->PC_Register = cpuPtr->PC_Register + byteToWordAdjustment;
                }
                else (cpuPtr->PC_Register)++;
            }

            if (instructionFieldsPtr->opcode == OPCODE_BL_HEX)
            {
                if (cpuPtr->alu.lessZeroFlag == ALU_FLAG_ON)
                {
                    int8_t byteToWordAdjustment = instructionFieldsPtr->immediate >> 1;

                    cpuPtr->PC_Register = cpuPtr->PC_Register + byteToWordAdjustment;
                }
                else (cpuPtr->PC_Register)++;
            }

            if (instructionFieldsPtr->opcode == OPCODE_BG_HEX)
            {
                if (cpuPtr->alu.greaterZeroFlag == ALU_FLAG_ON)
                {
                    int8_t byteToWordAdjustment = instructionFieldsPtr->immediate >> 1;

                    cpuPtr->PC_Register = cpuPtr->PC_Register + byteToWordAdjustment;
                }
                else (cpuPtr->PC_Register)++;
            }

            if (instructionFieldsPtr->opcode == OPCODE_BLE_HEX)
            {
                if ((cpuPtr->alu.zeroFlag == ALU_FLAG_ON) || (cpuPtr->alu.lessZeroFlag == ALU_FLAG_ON))
                {
                    int8_t byteToWordAdjustment = instructionFieldsPtr->immediate >> 1;

                    cpuPtr->PC_Register = cpuPtr->PC_Register + byteToWordAdjustment;
                }
                else (cpuPtr->PC_Register)++;
            }

            if (instructionFieldsPtr->opcode == OPCODE_BGE_HEX)
            {
                if ((cpuPtr->alu.zeroFlag == ALU_FLAG_ON) || (cpuPtr->alu.greaterZeroFlag == ALU_FLAG_ON))
                {
                    int8_t byteToWordAdjustment = instructionFieldsPtr->immediate >> 1;

                    cpuPtr->PC_Register = cpuPtr->PC_Register + byteToWordAdjustment;
                }
                else (cpuPtr->PC_Register)++;
            }
        }
        else (cpuPtr->PC_Register)++;
    }
    else
    {
        int16_t byteToWordAdjustment = instructionFieldsPtr->immediate >> 1;

        cpuPtr->PC_Register = cpuPtr->PC_Register + byteToWordAdjustment;
    }
}

void CPUParseInstruction(CPU_Ptr cpuPtr, InstructionFieldsPtr instructionFieldsPtr)
{
    uint16_t result = cpuPtr->IR_Register & OPCODE_BITMASK;
    instructionFieldsPtr->opcode = (uint8_t)(result >> OPCODE_BIT_SHIFT);

    switch (instructionFieldsPtr->opcode)
    {
        case OPCODE_MOVI_HEX:
        {
            result = cpuPtr->IR_Register & RD_Field_BITMASK;
            instructionFieldsPtr->RD_RT = (uint8_t)(result >> RD_FIELD_BIT_SHIFT);

            instructionFieldsPtr->RM = 0;

            instructionFieldsPtr->RN = 0;

            result = cpuPtr->IR_Register & IMM_FIELD_BITMASK;
            instructionFieldsPtr->immediate = (int8_t)(result >> IMM_FIELD_BIT_SHIFT);

            break;
        }
        case OPCODE_ADD_HEX:
        case OPCODE_SUB_HEX:
        case OPCODE_CMP_HEX:
        case OPCODE_MUL_HEX:
        case OPCODE_DIV_HEX:
        {
            result = cpuPtr->IR_Register & RD_Field_BITMASK;
            instructionFieldsPtr->RD_RT = (uint8_t)(result >> RD_FIELD_BIT_SHIFT);

            result = cpuPtr->IR_Register & RM_Field_BITMASK;
            instructionFieldsPtr->RM = (uint8_t)(result >> RM_FIELD_BIT_SHIFT);

            result = cpuPtr->IR_Register & RN_Field_BITMASK;
            instructionFieldsPtr->RN = (uint8_t)(result >> RN_FIELD_BIT_SHIFT);

            instructionFieldsPtr->immediate = 0;

            break;
        }
        case OPCODE_LDR_HEX:
        case OPCODE_STR_HEX:
        {
            result = cpuPtr->IR_Register & RT_Field_BITMASK;
            instructionFieldsPtr->RD_RT = (uint8_t)(result >> RT_FIELD_BIT_SHIFT);

            result = cpuPtr->IR_Register & RM_Field_BITMASK;
            instructionFieldsPtr->RM = (uint8_t)(result >> RM_FIELD_BIT_SHIFT);

            instructionFieldsPtr->RN = 0;

            result = cpuPtr->IR_Register & BASE_OFFSET_FIELD_BITMASK;
            instructionFieldsPtr->immediate = (int8_t)(result >> BASE_OFFSET_FIELD_BIT_SHIFT);

            break;
        }
        case OPCODE_BE_HEX:
        case OPCODE_BNE_HEX:
        case OPCODE_BL_HEX:
        case OPCODE_BG_HEX:
        case OPCODE_BLE_HEX:
        case OPCODE_BGE_HEX:
        {
            result = cpuPtr->IR_Register & RT_Field_BITMASK;
            instructionFieldsPtr->RD_RT = (uint8_t)(result >> RT_FIELD_BIT_SHIFT);

            instructionFieldsPtr->RM = 0;

            instructionFieldsPtr->RN = 0;

            result = cpuPtr->IR_Register & CBRANCH_PC_OFFSET_FIELD_BITMASK;
            instructionFieldsPtr->immediate = (int8_t)(result >> CBRANCH_PC_OFFSET_FIELD_BIT_SHIFT);

            break;
        }
        case OPCODE_B_HEX:
        {
            instructionFieldsPtr->RD_RT = 0;

            instructionFieldsPtr->RM = 0;

            instructionFieldsPtr->RN = 0;

            result = cpuPtr->IR_Register & UBRANCH_PC_OFFSET_FIELD_BITMASK;

            instructionFieldsPtr->immediate = (int8_t)(result >> UBRANCH_PC_OFFSET_FIELD_BIT_SHIFT);

            break;
        }
        case OPCODE_HALT_HEX:
        {
            instructionFieldsPtr->RD_RT = 0;
            instructionFieldsPtr->RM = 0;
            instructionFieldsPtr->RN = 0;
            instructionFieldsPtr->immediate = 0;

            break;
        }
        default:
        {
            instructionFieldsPtr->RD_RT = 0;
            instructionFieldsPtr->RM = 0;
            instructionFieldsPtr->RN = 0;
            instructionFieldsPtr->immediate = 0;

            break;
        }
    }
}

void CPUSetMultiplexers(CPU_Ptr cpuPtr, ControllerPtr controllerPtr)
{
    cpuPtr->aluDataInputBSourceMultiplexerPtr->dataSelector = controllerPtr->aluInputBSourceSelector;
    cpuPtr->registerWriteDataSourceMultiplexerPtr->dataSelector = controllerPtr->regWriteSourceSelector;
    cpuPtr->pcSourceMultiplexerPtr->dataSelector = controllerPtr->pcSourceSelector;
}

void CPUReadALUSourceRegisters(CPU_Ptr cpuPtr, InstructionFieldsPtr instructionFieldsPtr)
{
    if (cpuPtr->aluDataInputBSourceMultiplexerPtr->dataSelector == ALU_INPUT_B_SOURCE_SELECT_REG)
    {
        cpuPtr->alu.dataInputA = cpuPtr->registersPtr->values[instructionFieldsPtr->RM];
        cpuPtr->alu.dataInputB = cpuPtr->registersPtr->values[instructionFieldsPtr->RN];
    }
    else if (cpuPtr->aluDataInputBSourceMultiplexerPtr->dataSelector == ALU_INPUT_B_SOURCE_SELECT_IMM)
    {
        //Determine if the immediate is a 8-bit MOVI immediate or a 4-bit LDR/STR offset.
        //If the MEM_READ_FLAG_ON flag or the MEM_WRITE_FLAG_ON flag is on, it's a 4-bit memory data offset
        //otherwise, it's an 8-bit MOVI immediate.

        if ((cpuPtr->controller.memRead == MEM_READ_FLAG_ON) || (cpuPtr->controller.memWrite == MEM_WRITE_FLAG_ON))
        {
            cpuPtr->alu.dataInputA = cpuPtr->registersPtr->values[instructionFieldsPtr->RM];
            cpuPtr->alu.dataInputB = instructionFieldsPtr->immediate;
        }
        else
        {
            cpuPtr->alu.dataInputA = 0;
            cpuPtr->alu.dataInputB = instructionFieldsPtr->immediate;
        }
    }
}

void CPUExecuteALU(CPU_Ptr cpuPtr, InstructionFieldsPtr instructionFieldsPtr)
{
    if (cpuPtr->aluController.aluOpMovi == ALU_OP_SIG_ON)
        cpuPtr->alu.dataOutput = cpuPtr->alu.dataInputA + cpuPtr->alu.dataInputB;

    if (cpuPtr->aluController.aluOpAdd == ALU_OP_SIG_ON)
        cpuPtr->alu.dataOutput = cpuPtr->alu.dataInputA + cpuPtr->alu.dataInputB;

    if (cpuPtr->aluController.aluOpSub == ALU_OP_SIG_ON)
        cpuPtr->alu.dataOutput = cpuPtr->alu.dataInputA - cpuPtr->alu.dataInputB;

    if (cpuPtr->aluController.aluOpCmp == ALU_OP_SIG_ON)
    {
        cpuPtr->alu.zeroFlag = ALU_FLAG_OFF;
        cpuPtr->alu.lessZeroFlag = ALU_FLAG_OFF;
        cpuPtr->alu.greaterZeroFlag = ALU_FLAG_OFF;

        int16_t aluResult = cpuPtr->alu.dataInputA - cpuPtr->alu.dataInputB;

        cpuPtr->alu.dataOutput = aluResult;

        if (aluResult == 0) cpuPtr->alu.zeroFlag = ALU_FLAG_ON;
        if (aluResult < 0) cpuPtr->alu.lessZeroFlag = ALU_FLAG_ON;
        if (aluResult > 0) cpuPtr->alu.greaterZeroFlag = ALU_FLAG_ON;
    }

    if (cpuPtr->aluController.aluOpMul == ALU_OP_SIG_ON)
        cpuPtr->alu.dataOutput = cpuPtr->alu.dataInputA * cpuPtr->alu.dataInputB;

    if (cpuPtr->aluController.aluOpDiv == ALU_OP_SIG_ON)
        cpuPtr->alu.dataOutput = cpuPtr->alu.dataInputA / cpuPtr->alu.dataInputB;
}

void CPUWriteToDestinationRegister(CPU_Ptr cpuPtr, InstructionFieldsPtr instructionFieldsPtr)
{
    if (cpuPtr->controller.regWrite == REG_WRITE_FLAG_ON)
    {
        if (cpuPtr->registerWriteDataSourceMultiplexerPtr->dataSelector == REG_WRITE_SOURCE_SELECT_ALU)
        {
            cpuPtr->registersPtr->values[instructionFieldsPtr->RD_RT] = cpuPtr->alu.dataOutput;
        }

        if (cpuPtr->registerWriteDataSourceMultiplexerPtr->dataSelector == REG_WRITE_SOURCE_SELECT_MEM)
        {
            uint16_t mainMemoryValue = cpuPtr->mmu.mainMemoryPtr->values[cpuPtr->alu.dataOutput];
            cpuPtr->registersPtr->values[instructionFieldsPtr->RD_RT] = mainMemoryValue;
        }
    }
}

void CPUWriteRegisterToMemory(CPU_Ptr cpuPtr, InstructionFieldsPtr instructionFieldsPtr)
{
    cpuPtr->mmu.mainMemoryPtr->values[cpuPtr->alu.dataOutput] = cpuPtr->registersPtr->values[instructionFieldsPtr->RD_RT];
}

void CPUPrintInstruction(CPU_Ptr cpuPtr, uint16_t instructionCounter, InstructionFieldsPtr instructionFieldsPtr)
{
    printf("********************** BEGIN PROCESSING INSTRUCTION: %2d ********************\n\n", instructionCounter);

    printf("Address (PC):      Hex: 0x%04X Decimal: %d \n", cpuPtr->PC_Register, cpuPtr->PC_Register);
    printf("Instruction (IR):  Hex: 0x%04X ", cpuPtr->IR_Register);
    printf("Binary: ");
    printf(SIXTEEN_BIT_BYTE_TO_BINARY_PATTERN, SIXTEEN_BIT_BYTE_TO_BINARY(cpuPtr->IR_Register));
    printf("\n\n");
}

void CPUPrintDecodedInformation(CPU_Ptr cpuPtr, uint16_t instructionCounter, InstructionFieldsPtr instructionFieldsPtr)
{
    InstructionFieldsPrintState(instructionFieldsPtr);
}

void CPUPrintExecutionStateInformation(CPU_Ptr cpuPtr, InstructionFieldsPtr instructionFieldsPtr, 
    uint16_t startingMainMemoryAddress, int programSize)
{
    ControllerPrintControlRegister(cpuPtr->controllerPtr);
    ALUControllerPrintControlRegister(cpuPtr->aluControllerPtr);
    RegistersPrintRegisterValues(cpuPtr->registersPtr);
    MainMemoryPrintValues(cpuPtr->mmu.mainMemoryPtr, 0, programSize, "Program Memory");
    MainMemoryPrintDataSegmentValues(cpuPtr->mmu.mainMemoryPtr, 0, startingMainMemoryAddress);
    MainMemoryPrintCodeSegmentValues(cpuPtr->mmu.mainMemoryPtr, startingMainMemoryAddress, programSize);
}

void CPUSetOptions(int argc, char* argv[])
{
    for (int commandLineParameter = 1; commandLineParameter < argc; commandLineParameter++)
    {
        int result = strcmp(argv[commandLineParameter], "-pe");

        if (result == 0) pauseAfterInstructionProcessed = PAUSE_AFTER_INSTRUCTION_PROCESSED;
    }
}

