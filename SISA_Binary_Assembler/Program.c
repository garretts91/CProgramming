#include <stdio.h>
#include "Testcases.h"

void main()
{
    TestAssemblerInstruction("Assembly Instruction: MOVI", "AssemblyCodeInstructions_01.aci", "MachineCodeInstructions_01.bin", "MachineCodeInstructions_01_Valid.bin");
    TestAssemblerInstruction("Assembly Instruction: LDR_STR", "AssemblyCodeInstructions_02.aci", "MachineCodeInstructions_02.bin", "MachineCodeInstructions_02_Valid.bin");
    TestAssemblerInstruction("Assembly Instruction: LDR_STR", "AssemblyCodeInstructions_03.aci", "MachineCodeInstructions_03.bin", "MachineCodeInstructions_03_Valid.bin");
    TestAssemblerInstruction("Assembly Instruction: CMP_BL_B", "AssemblyCodeInstructions_04.aci", "MachineCodeInstructions_04.bin", "MachineCodeInstructions_04_Valid.bin");
    TestAssemblerInstruction("Assembly Instruction: totalArray", "totalArray.aci", "totalArray.mci", "totalArray.bin");
    
    printf("Press the enter key to continue...");

	int c = getchar();
}