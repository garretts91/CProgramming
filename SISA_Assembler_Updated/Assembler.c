#pragma warning(disable : 4996)
//https://www.tutorialspoint.com/c_standard_library/c_function_fgets.htm

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Assembler.h"
#include "RegisterSet.h"
#include "InstructionOpcodes.h"

//Private Functions
void assemble(char* assemblyFilename, char* objectCodeFilename);
void write_register_code(char* reg_num, FILE* fptr_write);

void executeAssembler(char* assemblyFilename, char* objectCodeFilename)
{
    int test_case_result = 0;

    printf("************************BEGIN ASSEMBLY PROCESS************************\n\n");

    printf("Running assembler...\n\n");

    printf("Assembly code instruction file: %s\n", assemblyFilename);
    printf("Machine code instruction file:  %s\n\n", objectCodeFilename);

    assemble(assemblyFilename, objectCodeFilename);

    printf("\n");

    printf("Assembly complete...\n\n");

    printf("Generated machine code instructions...\n\n");

    char generatedMachineCodeInstruction[ASSEMBLY_STATEMENT_BUFFER_SIZE];
    
    FILE* fptr_generated_object_code;
    
    fptr_generated_object_code = fopen(objectCodeFilename, "r");
    
    char* result = fgets(generatedMachineCodeInstruction, ASSEMBLY_STATEMENT_BUFFER_SIZE, fptr_generated_object_code);

    while (result != 0)
    {
        printf("%s", generatedMachineCodeInstruction);

        result = fgets(generatedMachineCodeInstruction, ASSEMBLY_STATEMENT_BUFFER_SIZE, fptr_generated_object_code);
    }

    fclose(fptr_generated_object_code);
    
    printf("\n");

    printf("*************************END ASSEMBLY PROCESS*************************\n\n");
}

void assemble(char* assemblyFilename, char* objectCodeFilename)
{
    char file_line[ASSEMBLY_STATEMENT_BUFFER_SIZE];

    FILE* fptr_read;
    FILE* fptr_write;

    fptr_read = fopen(assemblyFilename, "r");
    fptr_write = fopen(objectCodeFilename, "w");

    char* result = fgets(file_line, ASSEMBLY_STATEMENT_BUFFER_SIZE, fptr_read);

    while (result != 0)
    {
        int cmp_result = 0;

        file_line[strcspn(file_line, "\r")] = 0; //Linux
        file_line[strcspn(file_line, "\n")] = 0; //Windows

        printf("Translating assembly statement: %s\n", file_line);

        char* mnemonic = strtok(file_line, " \r\n");

        cmp_result = strcmp(mnemonic, DSS);

        if (cmp_result == 0)
        {
            //DSS b0000000000000011

            char* dataDirective = strtok(NULL, "b");

            fprintf(fptr_write, dataDirective);
            fprintf(fptr_write, "\n");
        }

        cmp_result = strcmp(mnemonic, DWORD);

        if (cmp_result == 0)
        {
            //DWORD b0000000000000001

            char* dataDirective = strtok(NULL, "b");

            fprintf(fptr_write, dataDirective);
            fprintf(fptr_write, "\n");
        }

        cmp_result = strcmp(mnemonic, MOVI);

        if (cmp_result == 0)
        {
            //MOVI R0, b00000001

            char* reg_num = strtok(NULL, ",");
            char* prefix_removal = strtok(NULL, "b");
            char* immediate = strtok(NULL, " \0");

            fprintf(fptr_write, OPCODE_MOVI);
            write_register_code(reg_num, fptr_write);
            fprintf(fptr_write, "%s", immediate);
            fprintf(fptr_write, "\n");
        }

        cmp_result = strcmp(mnemonic, ADD);

        if (cmp_result == 0)
        {
            //ADD R2, R0, R1

            char* reg_num_dest = strtok(NULL, ", ");
            char* reg_num_src1 = strtok(NULL, ", ");
            char* reg_num_src2 = strtok(NULL, " \0");

            fprintf(fptr_write, OPCODE_ADD);

            write_register_code(reg_num_dest, fptr_write);
            write_register_code(reg_num_src1, fptr_write);
            write_register_code(reg_num_src2, fptr_write);

            fprintf(fptr_write, "\n");
        }

        cmp_result = strcmp(mnemonic, SUB);

        if (cmp_result == 0)
        {
            //SUB R2, R0, R1

            char* reg_num_dest = strtok(NULL, ", ");
            char* reg_num_src1 = strtok(NULL, ", ");
            char* reg_num_src2 = strtok(NULL, " \0");

            fprintf(fptr_write, OPCODE_SUB);

            write_register_code(reg_num_dest, fptr_write);
            write_register_code(reg_num_src1, fptr_write);
            write_register_code(reg_num_src2, fptr_write);

            fprintf(fptr_write, "\n");
        }

        cmp_result = strcmp(mnemonic, CMP);

        if (cmp_result == 0)
        {
            //CMP R3, R1, R2

            char* reg_num_dest = strtok(NULL, ", ");
            char* reg_num_src1 = strtok(NULL, ", ");
            char* reg_num_src2 = strtok(NULL, " \0");

            fprintf(fptr_write, OPCODE_CMP);

            write_register_code(reg_num_dest, fptr_write);
            write_register_code(reg_num_src1, fptr_write);
            write_register_code(reg_num_src2, fptr_write);

            fprintf(fptr_write, "\n");
        }

        cmp_result = strcmp(mnemonic, MUL);

        if (cmp_result == 0)
        {
            //MUL R2, R0, R1

            char* reg_num_dest = strtok(NULL, ", ");
            char* reg_num_src1 = strtok(NULL, ", ");
            char* reg_num_src2 = strtok(NULL, " \0");

            fprintf(fptr_write, OPCODE_MUL);

            write_register_code(reg_num_dest, fptr_write);
            write_register_code(reg_num_src1, fptr_write);
            write_register_code(reg_num_src2, fptr_write);

            fprintf(fptr_write, "\n");
        }

        cmp_result = strcmp(mnemonic, DIV);

        if (cmp_result == 0)
        {
            //DIV R2, R0, R1

            char* reg_num_dest = strtok(NULL, ", ");
            char* reg_num_src1 = strtok(NULL, ", ");
            char* reg_num_src2 = strtok(NULL, " \0");

            fprintf(fptr_write, OPCODE_DIV);

            write_register_code(reg_num_dest, fptr_write);
            write_register_code(reg_num_src1, fptr_write);
            write_register_code(reg_num_src2, fptr_write);

            fprintf(fptr_write, "\n");
        }

        cmp_result = strcmp(mnemonic, LDR);

        if (cmp_result == 0)
        {
            //LDR R1, [R0 + b0000]

            char* dest_reg = strtok(NULL, ",");
            char* bracket_removal = strtok(NULL, "[");
            char* memory_address_reg = strtok(NULL, " ");
            char* binary_sign_removal = strtok(NULL, "b");
            char* memory_address_offset = strtok(NULL, "]");

            fprintf(fptr_write, OPCODE_LDR);
            write_register_code(dest_reg, fptr_write);
            write_register_code(memory_address_reg, fptr_write);
            fprintf(fptr_write, "%s", memory_address_offset);

            fprintf(fptr_write, "\n");
        }

        cmp_result = strcmp(mnemonic, STR);

        if (cmp_result == 0)
        {
            //STR R3, [R0 + b0000]

            char* src_reg = strtok(NULL, ",");
            char* bracket_removal = strtok(NULL, "[");
            char* memory_address_reg = strtok(NULL, " ");
            char* binary_sign_removal = strtok(NULL, "b");
            char* memory_address_offset = strtok(NULL, "]");
            
            fprintf(fptr_write, OPCODE_STR);
            write_register_code(src_reg, fptr_write);
            write_register_code(memory_address_reg, fptr_write);
            fprintf(fptr_write, "%s", memory_address_offset);

            fprintf(fptr_write, "\n");
        }

        cmp_result = strcmp(mnemonic, BE);

        if (cmp_result == 0)
        {
            //BE R3, b00011100

            char* cmp_reg = strtok(NULL, ",");
            char* binary_sign_removal = strtok(NULL, "b");
            char* memory_address_offset = strtok(NULL, " \0");

            fprintf(fptr_write, OPCODE_BE);
            write_register_code(cmp_reg, fptr_write);
            fprintf(fptr_write, "%s", memory_address_offset);

            fprintf(fptr_write, "\n");
        }

        cmp_result = strcmp(mnemonic, BNE);

        if (cmp_result == 0)
        {
            //BNE R3, b00011100

            char* cmp_reg = strtok(NULL, ",");
            char* binary_sign_removal = strtok(NULL, "b");
            char* memory_address_offset = strtok(NULL, " \0");

            fprintf(fptr_write, OPCODE_BNE);
            write_register_code(cmp_reg, fptr_write);
            fprintf(fptr_write, "%s", memory_address_offset);

            fprintf(fptr_write, "\n");
        }

        cmp_result = strcmp(mnemonic, BL);

        if (cmp_result == 0)
        {
            //BL R3, b00011100

            char* cmp_reg = strtok(NULL, ",");
            char* binary_sign_removal = strtok(NULL, "b");
            char* memory_address_offset = strtok(NULL, " \0");

            fprintf(fptr_write, OPCODE_BL);
            write_register_code(cmp_reg, fptr_write);
            fprintf(fptr_write, "%s", memory_address_offset);
            
            fprintf(fptr_write, "\n");
        }

        cmp_result = strcmp(mnemonic, BG);

        if (cmp_result == 0)
        {
            //BG R3, b00011100

            char* cmp_reg = strtok(NULL, ",");
            char* binary_sign_removal = strtok(NULL, "b");
            char* memory_address_offset = strtok(NULL, " \0");

            fprintf(fptr_write, OPCODE_BG);
            write_register_code(cmp_reg, fptr_write);
            fprintf(fptr_write, "%s", memory_address_offset);

            fprintf(fptr_write, "\n");
        }

        cmp_result = strcmp(mnemonic, BLE);

        if (cmp_result == 0)
        {
            //BLE R3, b00011100

            char* cmp_reg = strtok(NULL, ",");
            char* binary_sign_removal = strtok(NULL, "b");
            char* memory_address_offset = strtok(NULL, " \0");

            fprintf(fptr_write, OPCODE_BLE);
            write_register_code(cmp_reg, fptr_write);
            fprintf(fptr_write, "%s", memory_address_offset);

            fprintf(fptr_write, "\n");
        }

        cmp_result = strcmp(mnemonic, BGE);

        if (cmp_result == 0)
        {
            //BGE R3, b00011100

            char* cmp_reg = strtok(NULL, ",");
            char* binary_sign_removal = strtok(NULL, "b");
            char* memory_address_offset = strtok(NULL, " \0");

            fprintf(fptr_write, OPCODE_BGE);
            write_register_code(cmp_reg, fptr_write);
            fprintf(fptr_write, "%s", memory_address_offset);

            fprintf(fptr_write, "\n");
        }

        cmp_result = strcmp(mnemonic, B);

        if (cmp_result == 0)
        {
            //B  b00100000

            char* binary_sign_removal = strtok(NULL, "b");
            char* memory_address_offset = strtok(NULL, " \0");

            fprintf(fptr_write, OPCODE_B);
            fprintf(fptr_write, MCIA_PADDING);
            fprintf(fptr_write, "%s", memory_address_offset);

            fprintf(fptr_write, "\n");
        }

        cmp_result = strcmp(mnemonic, HALT);

        if (cmp_result == 0)
        {
            fprintf(fptr_write, OPCODE_HALT);
            fprintf(fptr_write, MCIA_PADDING);
            fprintf(fptr_write, MCIA_PADDING);
            fprintf(fptr_write, MCIA_PADDING);
            fprintf(fptr_write, "\n");
        }

        result = fgets(file_line, ASSEMBLY_STATEMENT_BUFFER_SIZE, fptr_read);
    }

    fclose(fptr_read);
    fclose(fptr_write);
}

void write_register_code(char* reg_num, FILE* fptr_write)
{
    int cmp_result = strcmp(reg_num, ACRO_R0);
    if (cmp_result == 0) fprintf(fptr_write, MCRO_R0);
    cmp_result = strcmp(reg_num, ACRO_R1);
    if (cmp_result == 0) fprintf(fptr_write, MCRO_R1);
    cmp_result = strcmp(reg_num, ACRO_R2);
    if (cmp_result == 0) fprintf(fptr_write, MCRO_R2);
    cmp_result = strcmp(reg_num, ACRO_R3);
    if (cmp_result == 0) fprintf(fptr_write, MCRO_R3);
    cmp_result = strcmp(reg_num, ACRO_R4);
    if (cmp_result == 0) fprintf(fptr_write, MCRO_R4);
    cmp_result = strcmp(reg_num, ACRO_R5);
    if (cmp_result == 0) fprintf(fptr_write, MCRO_R5);
    cmp_result = strcmp(reg_num, ACRO_R6);
    if (cmp_result == 0) fprintf(fptr_write, MCRO_R6);
    cmp_result = strcmp(reg_num, ACRO_R7);
    if (cmp_result == 0) fprintf(fptr_write, MCRO_R7);
    cmp_result = strcmp(reg_num, ACRO_R8);
    if (cmp_result == 0) fprintf(fptr_write, MCRO_R8);
    cmp_result = strcmp(reg_num, ACRO_R9);
    if (cmp_result == 0) fprintf(fptr_write, MCRO_R9);
    cmp_result = strcmp(reg_num, ACRO_R10);
    if (cmp_result == 0) fprintf(fptr_write, MCRO_R10);
    cmp_result = strcmp(reg_num, ACRO_R11);
    if (cmp_result == 0) fprintf(fptr_write, MCRO_R11);
    cmp_result = strcmp(reg_num, ACRO_R12);
    if (cmp_result == 0) fprintf(fptr_write, MCRO_R12);
    cmp_result = strcmp(reg_num, ACRO_R13);
    if (cmp_result == 0) fprintf(fptr_write, MCRO_R13);
    cmp_result = strcmp(reg_num, ACRO_R14);
    if (cmp_result == 0) fprintf(fptr_write, MCRO_R14);
    cmp_result = strcmp(reg_num, ACRO_R15);
    if (cmp_result == 0) fprintf(fptr_write, MCRO_R15);
}

