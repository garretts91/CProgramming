#pragma warning(disable : 4996)
//https://www.tutorialspoint.com/c_standard_library/c_function_fgets.htm

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Assembler.h"
#include "RegisterSet.h"
#include "InstructionOpcodes.h"

void write_register_code(char* reg_num, FILE* fptr_write);

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
        }

        cmp_result = strcmp(mnemonic, ADD);

        if (cmp_result == 0)
        {
            //ADD R2, R0, R1
            char* reg2 = strtok(NULL, " ,");
            char* reg0 = strtok(NULL, " ,");
            char* reg1 = strtok(NULL, " ,");

            fprintf(fptr_write, OPCODE_ADD);
            write_register_code(reg2, fptr_write);
            write_register_code(reg0, fptr_write);
            write_register_code(reg1, fptr_write);

        }

        cmp_result = strcmp(mnemonic, SUB);

        if (cmp_result == 0)
        {
            //SUB R2, R0, R1
        char* reg2 = strtok (NULL, " ,");
        char* reg0 = strtok (NULL, " ,");
        char* reg1 = strtok (NULL, " ,");
        

        fprintf(fptr_write, OPCODE_SUB);
        write_register_code(reg2, fptr_write);
        write_register_code(reg0, fptr_write);
        write_register_code(reg1, fptr_write);

        }

        cmp_result = strcmp(mnemonic, CMP);

        if (cmp_result == 0)
        {
            //CMP R3, R1, R2
        char* reg2 = strtok (NULL, " ,");
        char* reg0 = strtok (NULL, " ,");
        char* reg1 = strtok (NULL, " ,");
        

        fprintf(fptr_write, OPCODE_CMP);
        write_register_code(reg2, fptr_write);
        write_register_code(reg0, fptr_write);
        write_register_code(reg1, fptr_write);
           
        }

        cmp_result = strcmp(mnemonic, MUL);

        if (cmp_result == 0)
        {
            //MUL R2, R0, R1
            char* reg2 = strtok (NULL, " ,");
            char* reg0 = strtok (NULL, " ,");
            char* reg1 = strtok (NULL, " ,");
            

            fprintf(fptr_write, OPCODE_MUL);
            write_register_code(reg2, fptr_write);
            write_register_code(reg0, fptr_write);
            write_register_code(reg1, fptr_write);
        }

        cmp_result = strcmp(mnemonic, DIV);

        if (cmp_result == 0)
        {
            //DIV R2, R0, R1
            char* reg2 = strtok (NULL, " ,");
            char* reg0 = strtok (NULL, " ,");
            char* reg1 = strtok (NULL, " ,");
            

            fprintf(fptr_write, OPCODE_DIV);
            write_register_code(reg2, fptr_write);
            write_register_code(reg0, fptr_write);
            write_register_code(reg1, fptr_write);
            
        }

        cmp_result = strcmp(mnemonic, LDR);

        if (cmp_result == 0)
        {
            //LDR R1, [R0 + b000]
            char* reg1 = strtok(NULL, ",");
            char* remove_bracket = strtok(NULL, "[]");
            char* reg2 = strtok(NULL, " ");
            char* prefix_removal = strtok (NULL, "b");
            char* immediate = strtok(NULL, " ]");

            fprintf(fptr_write, OPCODE_LDR);
            write_register_code(reg1, fptr_write);
            write_register_code(reg2, fptr_write);
            fprintf(fptr_write, "%s", immediate);
                
        }

        cmp_result = strcmp(mnemonic, STR);

        if (cmp_result == 0)
        {
            //STR R3, [R0 + b000]
            char* reg1 = strtok(NULL, ",");
            char* remove_bracket = strtok(NULL, "[]");
            char* reg2 = strtok(NULL, " ");
            char* prefix_removal = strtok (NULL, "b");
            char* immediate = strtok(NULL, " ]");

            fprintf(fptr_write, OPCODE_STR);
            write_register_code(reg1, fptr_write);
            write_register_code(reg2, fptr_write);
            fprintf(fptr_write, "%s", immediate);
                   
        }

        cmp_result = strcmp(mnemonic, BE);

        if (cmp_result == 0)
        {
            //BE R3, b00011100
        char* reg_output = strtok (NULL, " ,");
        char* Prefix_removal = strtok (NULL, " b");
        //char* immediate = strtok (NULL, "\0");

        fprintf(fptr_write, OPCODE_BE);
        write_register_code(reg_output, fptr_write);
        //fprintf(fptr_write, "%s", immediate);
            
        }

        cmp_result = strcmp(mnemonic, BNE);

        if (cmp_result == 0)
        {
            //BNE R3, b00011100
        char* reg_output = strtok (NULL, " ,");
        char* Prefix_removal = strtok (NULL, " b");
        //char* immediate = strtok (NULL, "\0");

        fprintf(fptr_write, OPCODE_BNE);
        write_register_code(reg_output, fptr_write);
        //fprintf(fptr_write, "%s", immediate);
            
        }

        cmp_result = strcmp(mnemonic, BL);

        if (cmp_result == 0)
        {
            //BL R3, b00011100
        char* reg_output = strtok (NULL, ",");
        char* Prefix_removal = strtok (NULL, "b");
        char* immediate = strtok (NULL, "\0");

        fprintf(fptr_write, OPCODE_BL);
        write_register_code(reg_output, fptr_write);
        fprintf(fptr_write, "%s", immediate);
            
        }

        cmp_result = strcmp(mnemonic, BG);

        if (cmp_result == 0)
        {
            //BG R3, b00011100
        char* reg_output = strtok (NULL, ",");
        char* Prefix_removal = strtok (NULL, "b");
        char* immediate = strtok (NULL, "\0");

        fprintf(fptr_write, OPCODE_BG);
        write_register_code(reg_output, fptr_write);
        fprintf(fptr_write, "%s", immediate);
            
        }

        cmp_result = strcmp(mnemonic, BLE);

        if (cmp_result == 0)
        {
            //BLE R3, b00011100
        char* reg_output = strtok (NULL, ",");
        char* Prefix_removal = strtok (NULL, "b");
        char* immediate = strtok (NULL, "\0");

        fprintf(fptr_write, OPCODE_BLE);
        write_register_code(reg_output, fptr_write);
        fprintf(fptr_write, "%s", immediate);
            
        }

        cmp_result = strcmp(mnemonic, BGE);

        if (cmp_result == 0)
        {
            //BGE R3, b00011100
        char* reg_output = strtok (NULL, ",");
        char* Prefix_removal = strtok (NULL, "b");
        char* immediate = strtok (NULL, "\0");

        fprintf(fptr_write, OPCODE_BGE);
        write_register_code(reg_output, fptr_write);
        fprintf(fptr_write, "%s", immediate);
            
        }

        cmp_result = strcmp(mnemonic, B);

        if (cmp_result == 0)
        {
            //B  b00100000
        char* Prefix_removal = strtok (NULL, "b");
        char* immediate = strtok (NULL, "\0");

        fprintf(fptr_write, OPCODE_B);
        fprintf(fptr_write, MCIA_PADDING);
        fprintf(fptr_write, "%s", immediate);
           
        }

        cmp_result = strcmp(mnemonic, HALT);

        if (cmp_result == 0)
        {
            fprintf(fptr_write, OPCODE_HALT);
            fprintf(fptr_write, MCIA_PADDING);
            fprintf(fptr_write, MCIA_PADDING);
            fprintf(fptr_write, MCIA_PADDING);
            
        }

        fprintf(fptr_write, "\n");
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
}