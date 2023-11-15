/*******************************************************************************
* Module:       Program
* Developer:    Michael Koepp
* Company:      WWU Computer Science Department
* Create Date:  
* Description:  This program tests an instruction processor implementation. 
*******************************************************************************/

#include <stdio.h>
#include "Computer.h"
#define MINIMUM_COMMAND_LINE_PARAMETERS 2

Computer computer;

void main(int argc, char* argv[])
{
    printf("Starting computer system...\n\n");

	if (argc < MINIMUM_COMMAND_LINE_PARAMETERS) 
	{
		printf("Usage: sisaprocessor machineCodeFileName.mci [options]\n\n");
		printf("Option: -step 	  Step through execution. Pauses execution after each instruction is processed\n");
		printf("Option: -cusigs   View Main Controller Unit Signals\n");
		printf("Option: -alusigs  View ALU Controller Signals\n");
		printf("Option: -mem 	  View memory of both the data and code segments\n");
		printf("Option: -dmem 	  View the data segment memory\n");
		printf("Option: -cmem 	  View the code segment memory\n");
		printf("\n");
	}
	else
	{
		Computer* computerPtr = &computer;

		ComputerInitialize(computerPtr);

		CPUSetOptions(argc, argv);
		ControllerSetOptions(argc, argv);
		ALUControllerSetOptions(argc, argv);
		MainMemorySetOptions(argc, argv);

		int16_t programReturnValue = ComputerExecuteProgram(computerPtr, argv[1]); 
	
		//int16_t programReturnValue = ComputerExecuteProgram(computerPtr, "TestProgram.mci");

		printf("Program return value: %d\n", programReturnValue);
	}

	printf("Press the enter key to continue...");

	int c = getchar();
}
