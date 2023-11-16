#include <stdio.h>
#include <string.h>
#include "ALUController.h"
#include "PrintingFormats.h"

#define PRINT_ALU_CONTROLLER_SIGNALS 1

//PRIVATE FUNCTION PROTOTYPES
void ALUControllerResetSignals(ALUControllerPtr aluControllerPtr);
void ALUControllerSetSignals(ALUControllerPtr aluControllerPtr);

//MODULE LEVEL VARIABLES
int printAluControllerSignals = 0;

void ALUControllerSetControlRegisters(ALUControllerPtr aluControllerPtr, ControllerPtr controllerPtr)
{
    aluControllerPtr->controlRegister = 0;

    ALUControllerResetSignals(aluControllerPtr);

    uint16_t controlRegisterSignal = 0;

    controlRegisterSignal = controllerPtr->controlRegister & ALU_OP_MOVI_BITMASK;
    aluControllerPtr->controlRegister |= controlRegisterSignal;

    controlRegisterSignal = controllerPtr->controlRegister & ALU_OP_ADD_BITMASK;
    aluControllerPtr->controlRegister |= controlRegisterSignal;
   
    controlRegisterSignal = controllerPtr->controlRegister & ALU_OP_SUB_BITMASK;
    aluControllerPtr->controlRegister |= controlRegisterSignal;
   
    controlRegisterSignal = controllerPtr->controlRegister & ALU_OP_CMP_BITMASK;
    aluControllerPtr->controlRegister |= controlRegisterSignal;
    
    controlRegisterSignal = controllerPtr->controlRegister & ALU_OP_MUL_BITMASK;
    aluControllerPtr->controlRegister |= controlRegisterSignal;
    
    controlRegisterSignal = controllerPtr->controlRegister & ALU_OP_DIV_BITMASK;
    aluControllerPtr->controlRegister |= controlRegisterSignal;

    ALUControllerSetSignals(aluControllerPtr);
}

void ALUControllerResetSignals(ALUControllerPtr aluControllerPtr)
{
    aluControllerPtr->aluOpMovi = ALU_OP_SIG_OFF;
    aluControllerPtr->aluOpAdd = ALU_OP_SIG_OFF;
    aluControllerPtr->aluOpSub = ALU_OP_SIG_OFF;
    aluControllerPtr->aluOpCmp = ALU_OP_SIG_OFF;
    aluControllerPtr->aluOpMul = ALU_OP_SIG_OFF;
    aluControllerPtr->aluOpDiv = ALU_OP_SIG_OFF;
}

void ALUControllerSetSignals(ALUControllerPtr aluControllerPtr)
{
    if ((aluControllerPtr->controlRegister & ALU_OP_MOVI_BITMASK) != 0) aluControllerPtr->aluOpMovi = ALU_OP_SIG_ON;
    if ((aluControllerPtr->controlRegister & ALU_OP_ADD_BITMASK) != 0) aluControllerPtr->aluOpAdd = ALU_OP_SIG_ON;
    if ((aluControllerPtr->controlRegister & ALU_OP_SUB_BITMASK) != 0) aluControllerPtr->aluOpSub = ALU_OP_SIG_ON;
    if ((aluControllerPtr->controlRegister & ALU_OP_CMP_BITMASK) != 0) aluControllerPtr->aluOpCmp = ALU_OP_SIG_ON;
    if ((aluControllerPtr->controlRegister & ALU_OP_MUL_BITMASK) != 0) aluControllerPtr->aluOpMul = ALU_OP_SIG_ON;
    if ((aluControllerPtr->controlRegister & ALU_OP_DIV_BITMASK) != 0) aluControllerPtr->aluOpDiv = ALU_OP_SIG_ON;
}

void ALUControllerPrintControlRegister(ALUControllerPtr aluControllerPtr)
{
    if (printAluControllerSignals == PRINT_ALU_CONTROLLER_SIGNALS)
    {
        uint16_t controlRegisterSignal = 0;

        controlRegisterSignal = aluControllerPtr->controlRegister & ALU_OP_MOVI_BITMASK;
        controlRegisterSignal = controlRegisterSignal >> ALU_OP_MOVI_BIT_SHIFT;

        printf("ALU Controller Output Signals\n\n");

        printf("ALU_OP_MOVI:                 ");
        printf(ONE_BIT_TO_BINARY_PATTERN, ONE_BIT_TO_BINARY(controlRegisterSignal));
        printf("\n");

        controlRegisterSignal = aluControllerPtr->controlRegister & ALU_OP_ADD_BITMASK;
        controlRegisterSignal = controlRegisterSignal >> ALU_OP_ADD_BIT_SHIFT;

        printf("ALU_OP_ADD:                  ");
        printf(ONE_BIT_TO_BINARY_PATTERN, ONE_BIT_TO_BINARY(controlRegisterSignal));
        printf("\n");

        controlRegisterSignal = aluControllerPtr->controlRegister & ALU_OP_SUB_BITMASK;
        controlRegisterSignal = controlRegisterSignal >> ALU_OP_SUB_BIT_SHIFT;

        printf("ALU_OP_SUB:                  ");
        printf(ONE_BIT_TO_BINARY_PATTERN, ONE_BIT_TO_BINARY(controlRegisterSignal));
        printf("\n");

        controlRegisterSignal = aluControllerPtr->controlRegister & ALU_OP_CMP_BITMASK;
        controlRegisterSignal = controlRegisterSignal >> ALU_OP_CMP_BIT_SHIFT;

        printf("ALU_OP_CMP:                  ");
        printf(ONE_BIT_TO_BINARY_PATTERN, ONE_BIT_TO_BINARY(controlRegisterSignal));
        printf("\n");

        controlRegisterSignal = aluControllerPtr->controlRegister & ALU_OP_MUL_BITMASK;
        controlRegisterSignal = controlRegisterSignal >> ALU_OP_MUL_BIT_SHIFT;

        printf("ALU_OP_MUL:                  ");
        printf(ONE_BIT_TO_BINARY_PATTERN, ONE_BIT_TO_BINARY(controlRegisterSignal));
        printf("\n");

        controlRegisterSignal = aluControllerPtr->controlRegister & ALU_OP_DIV_BITMASK;
        controlRegisterSignal = controlRegisterSignal >> ALU_OP_DIV_BIT_SHIFT;

        printf("ALU_OP_DIV:                  ");
        printf(ONE_BIT_TO_BINARY_PATTERN, ONE_BIT_TO_BINARY(controlRegisterSignal));
        printf("\n");

        printf("\n");
    }
}

void ALUControllerSetOptions(int argc, char* argv[])
{
    for (int commandLineParameter = 1; commandLineParameter < argc; commandLineParameter++)
    {
        int result = strcmp(argv[commandLineParameter], "-alusigs");

        if (result == 0) printAluControllerSignals = PRINT_ALU_CONTROLLER_SIGNALS;
    }
}