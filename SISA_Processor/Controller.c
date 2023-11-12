#include <stdio.h>
#include <string.h>
#include "Controller.h"
#include "MachineOpcodes.h"
#include "PrintingFormats.h"

#define PRINT_MAIN_CONTROLLER_SIGNALS 1

//PRIVATE FUNCTION PROTOTYPES
void ControllerResetSignals(ControllerPtr controllerPtr);
void ControllerSetSignals(ControllerPtr controllerPtr);

//MODULE LEVEL VARIABLES
int printMainControllerSignals = 0;

void ControllerSetControlRegister(ControllerPtr controllerPtr, uint8_t opcode)
{
    controllerPtr->controlRegister = 0;

    ControllerResetSignals(controllerPtr);

    switch (opcode)
    {
        case OPCODE_MOVI_HEX:
        {
            controllerPtr->controlRegister |= ALU_OP_MOVI_BITMASK;
            controllerPtr->controlRegister |= ALU_INPUT_B_SOURCE_BITMASK;
            controllerPtr->controlRegister |= REG_WRITE_BITMASK;

            break;
        }
        case OPCODE_ADD_HEX:
        {
            controllerPtr->controlRegister |= ALU_OP_ADD_BITMASK;
            controllerPtr->controlRegister |= REG_WRITE_BITMASK;

            break;
        }
        case OPCODE_SUB_HEX:
        {
            controllerPtr->controlRegister |= ALU_OP_SUB_BITMASK;
            controllerPtr->controlRegister |= REG_WRITE_BITMASK;

            break;
        }
        case OPCODE_CMP_HEX:
        {
            controllerPtr->controlRegister |= ALU_OP_CMP_BITMASK;
            controllerPtr->controlRegister |= REG_WRITE_BITMASK;

            break;
        }
        case OPCODE_MUL_HEX:
        {
            controllerPtr->controlRegister |= ALU_OP_MUL_BITMASK;
            controllerPtr->controlRegister |= REG_WRITE_BITMASK;

            break;
        }
        case OPCODE_DIV_HEX:
        {
            controllerPtr->controlRegister |= ALU_OP_DIV_BITMASK;
            controllerPtr->controlRegister |= REG_WRITE_BITMASK;

            break;
        }
        case OPCODE_LDR_HEX:
        {
            controllerPtr->controlRegister |= ALU_OP_ADD_BITMASK;
            controllerPtr->controlRegister |= ALU_INPUT_B_SOURCE_BITMASK;
            controllerPtr->controlRegister |= REG_WRITE_BITMASK;
            controllerPtr->controlRegister |= MEM_READ_BITMASK;
            controllerPtr->controlRegister |= REG_WRITE_SOURCE_BITMASK;

            break;
        }
        case OPCODE_STR_HEX:
        {
            controllerPtr->controlRegister |= ALU_OP_ADD_BITMASK;
            controllerPtr->controlRegister |= ALU_INPUT_B_SOURCE_BITMASK;
            controllerPtr->controlRegister |= MEM_WRITE_BITMASK;

            break;
        }
        case OPCODE_BE_HEX:
        case OPCODE_BNE_HEX:
        case OPCODE_BL_HEX:
        case OPCODE_BG_HEX:
        case OPCODE_BLE_HEX:
        case OPCODE_BGE_HEX:
        {
            controllerPtr->controlRegister |= CONDITIONAL_BRANCH_BITMASK;

            break;
        }
        case OPCODE_B_HEX:
        {
            controllerPtr->controlRegister |= UNCONDITIONAL_BRANCH_BITMASK;

            break;
        }
        case OPCODE_HALT_HEX:
        {
            break;
        }
        default:
        {
            break;
        }
    }

    ControllerSetSignals(controllerPtr);
}

void ControllerResetSignals(ControllerPtr controllerPtr)
{
    controllerPtr->aluOpMovi = ALU_OP_SIG_OFF; 
    controllerPtr->aluOpAdd = ALU_OP_SIG_OFF;
    controllerPtr->aluOpSub = ALU_OP_SIG_OFF;
    controllerPtr->aluOpCmp = ALU_OP_SIG_OFF;
    controllerPtr->aluOpMul = ALU_OP_SIG_OFF;
    controllerPtr->aluOpDiv = ALU_OP_SIG_OFF;
    controllerPtr->regWrite = REG_WRITE_FLAG_OFF;
    controllerPtr->memRead = MEM_READ_FLAG_OFF;
    controllerPtr->memWrite = MEM_WRITE_FLAG_OFF;
    controllerPtr->condBranch = COND_BRANCH_FLAG_OFF;
    controllerPtr->uncondBranch = UNCOND_BRANCH_FLAG_OFF;
    controllerPtr->aluInputBSourceSelector = ALU_INPUT_B_SOURCE_SELECT_REG;
    controllerPtr->regWriteSourceSelector = REG_WRITE_SOURCE_SELECT_ALU;
    controllerPtr->pcSourceSelector = PC_SOURCE_SELECT_NORMAL;
}

void ControllerSetSignals(ControllerPtr controllerPtr)
{
    if ((controllerPtr->controlRegister & ALU_OP_MOVI_BITMASK) != 0) controllerPtr->aluOpMovi = ALU_OP_SIG_ON;
    if ((controllerPtr->controlRegister & ALU_OP_ADD_BITMASK) != 0) controllerPtr->aluOpAdd = ALU_OP_SIG_ON;
    if ((controllerPtr->controlRegister & ALU_OP_SUB_BITMASK) != 0) controllerPtr->aluOpSub = ALU_OP_SIG_ON;
    if ((controllerPtr->controlRegister & ALU_OP_CMP_BITMASK) != 0) controllerPtr->aluOpCmp = ALU_OP_SIG_ON;
    if ((controllerPtr->controlRegister & ALU_OP_MUL_BITMASK) != 0) controllerPtr->aluOpMul = ALU_OP_SIG_ON;
    if ((controllerPtr->controlRegister & ALU_OP_DIV_BITMASK) != 0) controllerPtr->aluOpDiv = ALU_OP_SIG_ON;
    if ((controllerPtr->controlRegister & REG_WRITE_BITMASK) != 0) controllerPtr->regWrite = REG_WRITE_FLAG_ON;
    if ((controllerPtr->controlRegister & MEM_READ_BITMASK) != 0) controllerPtr->memRead = MEM_READ_FLAG_ON;
    if ((controllerPtr->controlRegister & MEM_WRITE_BITMASK) != 0) controllerPtr->memWrite = MEM_WRITE_FLAG_ON;
    if ((controllerPtr->controlRegister & CONDITIONAL_BRANCH_BITMASK) != 0) controllerPtr->condBranch = COND_BRANCH_FLAG_ON;
    if ((controllerPtr->controlRegister & UNCONDITIONAL_BRANCH_BITMASK) != 0) controllerPtr->uncondBranch = UNCOND_BRANCH_FLAG_ON;
    if ((controllerPtr->controlRegister & ALU_INPUT_B_SOURCE_BITMASK) != 0) controllerPtr->aluInputBSourceSelector = ALU_INPUT_B_SOURCE_SELECT_IMM;
    if ((controllerPtr->controlRegister & REG_WRITE_SOURCE_BITMASK) != 0) controllerPtr->regWriteSourceSelector = REG_WRITE_SOURCE_SELECT_MEM;
    if ((controllerPtr->controlRegister & PC_SOURCE_BITMASK) != 0) controllerPtr->pcSourceSelector = PC_SOURCE_SELECT_BRANCH;
}

void ControllerPrintControlRegister(ControllerPtr controllerPtr)
{
    if (printMainControllerSignals == PRINT_MAIN_CONTROLLER_SIGNALS)
    {
        uint16_t controlRegisterSignal = 0;

        controlRegisterSignal = controllerPtr->controlRegister & ALU_OP_MOVI_BITMASK;
        controlRegisterSignal = controlRegisterSignal >> ALU_OP_MOVI_BIT_SHIFT;

        printf("Main Controller Output Signals\n\n");

        printf("ALU_OP_MOVI:                 ");
        printf(ONE_BIT_TO_BINARY_PATTERN, ONE_BIT_TO_BINARY(controlRegisterSignal));
        printf("\n");

        controlRegisterSignal = controllerPtr->controlRegister & ALU_OP_ADD_BITMASK;
        controlRegisterSignal = controlRegisterSignal >> ALU_OP_ADD_BIT_SHIFT;

        printf("ALU_OP_ADD:                  ");
        printf(ONE_BIT_TO_BINARY_PATTERN, ONE_BIT_TO_BINARY(controlRegisterSignal));
        printf("\n");

        controlRegisterSignal = controllerPtr->controlRegister & ALU_OP_SUB_BITMASK;
        controlRegisterSignal = controlRegisterSignal >> ALU_OP_SUB_BIT_SHIFT;

        printf("ALU_OP_SUB:                  ");
        printf(ONE_BIT_TO_BINARY_PATTERN, ONE_BIT_TO_BINARY(controlRegisterSignal));
        printf("\n");

        controlRegisterSignal = controllerPtr->controlRegister & ALU_OP_CMP_BITMASK;
        controlRegisterSignal = controlRegisterSignal >> ALU_OP_CMP_BIT_SHIFT;

        printf("ALU_OP_CMP:                  ");
        printf(ONE_BIT_TO_BINARY_PATTERN, ONE_BIT_TO_BINARY(controlRegisterSignal));
        printf("\n");

        controlRegisterSignal = controllerPtr->controlRegister & ALU_OP_MUL_BITMASK;
        controlRegisterSignal = controlRegisterSignal >> ALU_OP_MUL_BIT_SHIFT;

        printf("ALU_OP_MUL:                  ");
        printf(ONE_BIT_TO_BINARY_PATTERN, ONE_BIT_TO_BINARY(controlRegisterSignal));
        printf("\n");

        controlRegisterSignal = controllerPtr->controlRegister & ALU_OP_DIV_BITMASK;
        controlRegisterSignal = controlRegisterSignal >> ALU_OP_DIV_BIT_SHIFT;

        printf("ALU_OP_DIV:                  ");
        printf(ONE_BIT_TO_BINARY_PATTERN, ONE_BIT_TO_BINARY(controlRegisterSignal));
        printf("\n");

        controlRegisterSignal = controllerPtr->controlRegister & REG_WRITE_BITMASK;
        controlRegisterSignal = controlRegisterSignal >> REG_WRITE_BIT_SHIFT;

        printf("REG_WRITE:                   ");
        printf(ONE_BIT_TO_BINARY_PATTERN, ONE_BIT_TO_BINARY(controlRegisterSignal));
        printf("\n");

        controlRegisterSignal = controllerPtr->controlRegister & MEM_READ_BITMASK;
        controlRegisterSignal = controlRegisterSignal >> MEM_READ_BIT_SHIFT;

        printf("MEM_READ:                    ");
        printf(ONE_BIT_TO_BINARY_PATTERN, ONE_BIT_TO_BINARY(controlRegisterSignal));
        printf("\n");

        controlRegisterSignal = controllerPtr->controlRegister & MEM_WRITE_BITMASK;
        controlRegisterSignal = controlRegisterSignal >> MEM_WRITE_BIT_SHIFT;

        printf("MEM_WRITE:                   ");
        printf(ONE_BIT_TO_BINARY_PATTERN, ONE_BIT_TO_BINARY(controlRegisterSignal));
        printf("\n");

        controlRegisterSignal = controllerPtr->controlRegister & CONDITIONAL_BRANCH_BITMASK;
        controlRegisterSignal = controlRegisterSignal >> CONDITIONAL_BRANCH_BIT_SHIFT;

        printf("CONDITIONAL_BRANCH:          ");
        printf(ONE_BIT_TO_BINARY_PATTERN, ONE_BIT_TO_BINARY(controlRegisterSignal));
        printf("\n");

        controlRegisterSignal = controllerPtr->controlRegister & UNCONDITIONAL_BRANCH_BITMASK;
        controlRegisterSignal = controlRegisterSignal >> UNCONDITIONAL_BRANCH_BIT_SHIFT;

        printf("UNCONDITIONAL_BRANCH:        ");
        printf(ONE_BIT_TO_BINARY_PATTERN, ONE_BIT_TO_BINARY(controlRegisterSignal));
        printf("\n");

        controlRegisterSignal = controllerPtr->controlRegister & ALU_INPUT_B_SOURCE_BITMASK;
        controlRegisterSignal = controlRegisterSignal >> ALU_INPUT_B_SOURCE_BIT_SHIFT;

        printf("ALU_INPUT_B_SOURCE:          ");
        printf(ONE_BIT_TO_BINARY_PATTERN, ONE_BIT_TO_BINARY(controlRegisterSignal));
        printf("\n");

        controlRegisterSignal = controllerPtr->controlRegister & REG_WRITE_SOURCE_BITMASK;
        controlRegisterSignal = controlRegisterSignal >> REG_WRITE_SOURCE_BIT_SHIFT;

        printf("REG_WRITE_SOURCE:            ");
        printf(ONE_BIT_TO_BINARY_PATTERN, ONE_BIT_TO_BINARY(controlRegisterSignal));
        printf("\n");

        controlRegisterSignal = controllerPtr->controlRegister & PC_SOURCE_BITMASK;
        controlRegisterSignal = controlRegisterSignal >> PC_SOURCE_BIT_SHIFT;

        printf("PC_SOURCE:                   ");
        printf(ONE_BIT_TO_BINARY_PATTERN, ONE_BIT_TO_BINARY(controlRegisterSignal));
        printf("\n");

        printf("\n");
    }
}

void ControllerSetOptions(int argc, char* argv[])
{
    for (int commandLineParameter = 1; commandLineParameter < argc; commandLineParameter++)
    {
        int result = strcmp(argv[commandLineParameter], "-pmcs");

        if (result == 0) printMainControllerSignals = PRINT_MAIN_CONTROLLER_SIGNALS;
    }
}