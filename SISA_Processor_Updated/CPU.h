#ifndef CPU_H
#define CPU_H

/*******************************************************************************
* Module:       CPU
* Developer:    Michael Koepp
* Company:      WWU Computer Science Department
* Create Date:  
* Description:  
*******************************************************************************/

#include "MainMemory.h"
#include "MMU.h"
#include "ALU.h"
#include "Registers.h"
#include "Controller.h"
#include "ALUController.h"
#include "Adder.h"
#include "Multiplexer.h"


typedef struct
{

	uint16_t PC_Register;
	uint16_t IR_Register;

	ALU alu;
	ALU_Ptr aluPtr;
	Registers registers;
	RegistersPtr registersPtr;
	MMU mmu;
	MMU_Ptr mmuPtr;

	Controller controller;
	ControllerPtr controllerPtr;
	ALUController aluController;
	ALUControllerPtr aluControllerPtr;

	Adder pcNextAdder;
	AdderPtr pcNextAdderPtr;
	Adder pcBranchOffsetAdder;
	AdderPtr pcBranchOffsetAdderPtr;

	Multiplexer aluInputBSourceMultiplexer;
	MultiplexerPtr aluDataInputBSourceMultiplexerPtr;
	Multiplexer registerWriteDataSourceMultiplexer;
	MultiplexerPtr registerWriteDataSourceMultiplexerPtr;
	Multiplexer pcSourceMultiplexer;
	MultiplexerPtr pcSourceMultiplexerPtr;
	
}CPU, *CPU_Ptr;

void CPUInitialize(CPU_Ptr cpuPtr, MainMemoryPtr mainMemoryPtr);
int16_t CPUExecuteProgram(CPU_Ptr cpuPtr, uint16_t startingMainMemoryAddress, int programSize);
void CPUSetOptions(int argc, char* argv[]);

#endif // !CPU_H