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
		printf("Usage: sisaprocessor machine_code_file_name.mci [options]\n\n");
		printf("Option: -pe     Pause Execution after each instruction\n");
		printf("Option: -pmcs   Print Main Controller Signals\n");
		printf("Option: -palucs Print ALU Controller Signals\n");
		printf("Option: -pma 	Prints both the data and code segments\n");
		printf("Option: -pmd 	Prints the data segment\n");
		printf("Option: -pmc 	Prints the code segment\n");
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

		int16_t programReturnValue = 0;

		//programReturnValue = ComputerExecuteProgram(computerPtr, "TestProgram.mci");
		programReturnValue = ComputerExecuteProgram(computerPtr, argv[1]);

		printf("Program return value: %d\n", programReturnValue);
	}

	printf("Press the enter key to continue...");

	int c = getchar();
}
