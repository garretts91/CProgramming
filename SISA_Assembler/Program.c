#include <stdio.h>
#include "Testcases.h"

void main()
{
    TestAssemblerInstruction("Assembly Instruction: MOVI", "AssemblyCodeInstructions_01.aci", "MachineCodeInstructions_01.mci", "MachineCodeInstructions_01_Valid.mci");
    TestAssemblerInstruction("Assembly Instruction: LDR_STR", "AssemblyCodeInstructions_02.aci", "MachineCodeInstructions_02.mci", "MachineCodeInstructions_02_Valid.mci");
    TestAssemblerInstruction("Assembly Instruction: LDR_STR", "AssemblyCodeInstructions_03.aci", "MachineCodeInstructions_03.mci", "MachineCodeInstructions_03_Valid.mci");
    TestAssemblerInstruction("Assembly Instruction: CMP_BL_B", "AssemblyCodeInstructions_04.aci", "MachineCodeInstructions_04.mci", "MachineCodeInstructions_04_Valid.mci");
    TestAssemblerInstruction("Assembly Instruction: totalArray", "totalArray.aci", "totalArray.mci", "totalArray.bin");

    printf("Press the enter key to continue...");

	int c = getchar();
}