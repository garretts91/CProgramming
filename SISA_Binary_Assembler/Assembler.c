//Name: Garrett Solomon and Colson Swope
//Date: October 25, 2023
//Description: In this program, the code reads from an assembly instruction file,
// then translates that assembly code instruction into machine code instructions (written in binary)
// it reads and writes to a new file, then tries to validate if the given machine code instructions are correct.
// If they are correct, we get a "Pass" 

#pragma warning(disable : 4996)
//https://www.tutorialspoint.com/c_standard_library/c_function_fgets.htm

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Assembler.h"
#include "RegisterSet.h"
#include "InstructionOpcodes.h"

void write_opcode(char* reg_num, unsigned short* machineInstruction, unsigned short leftShift);
void write_register_code(char* reg_num, unsigned short* machineInstruction, unsigned short leftShift);
void write_immediate(char* immediate, unsigned short* machineInstruction, unsigned short leftShift);
void write_machine_instruction(FILE* fptr_write, unsigned short machineInstruction);

void assemble(char* assemblyFilename, char* objectCodeFilename)
{
    char file_line[ASSEMBLY_STATEMENT_BUFFER_SIZE];
    
    FILE* fptr_read;
    FILE* fptr_write;

    fptr_read = fopen(assemblyFilename, "r");
    fptr_write = fopen(objectCodeFilename, "wb");

    char* result = fgets(file_line, ASSEMBLY_STATEMENT_BUFFER_SIZE, fptr_read);

    while (result != 0)
    {
        unsigned short machineInstruction = 0;
        int cmp_result = 0;

        file_line[strcspn(file_line, "\r")] = 0; //Linux
        file_line[strcspn(file_line, "\n")] = 0; //Windows

        printf("Translating assembly statement: %s\n", file_line);

        char* mnemonic = strtok(file_line, " \r\n");

        cmp_result = strcmp(mnemonic, MOVI);

        if (cmp_result == 0)
        {
            //MOVI R0, b00000001

            char* dest_reg = strtok(NULL, ",");
            char* prefix_removal = strtok(NULL, "b");
            char* immediate = strtok(NULL, " \0");

            write_opcode(mnemonic, &machineInstruction, OPCODE_SHIFT);
            write_register_code(dest_reg, &machineInstruction, RT_REG_SHIFT);
            write_immediate(immediate, &machineInstruction, IMM_8_BIT_SHIFT);

            write_machine_instruction(fptr_write, machineInstruction);
        }

        cmp_result = strcmp(mnemonic, ADD);

        if (cmp_result == 0)
        {
            //ADD R2, R0, R1
            char* r2tok = strtok(NULL, " ,");
            char* r0tok = strtok(NULL, " ,");
            char* r1tok = strtok(NULL, " \0");

            write_opcode(mnemonic, &machineInstruction, OPCODE_SHIFT);
            write_register_code(r2tok, &machineInstruction, RT_REG_SHIFT);
            write_register_code(r0tok, &machineInstruction, RM_REG_SHIFT);
            write_register_code(r1tok, &machineInstruction, RN_REG_SHIFT);

            write_machine_instruction(fptr_write, machineInstruction);    
        }

        cmp_result = strcmp(mnemonic, SUB);

        if (cmp_result == 0)
        {
            //SUB R2, R0, R1
            char* r2tok = strtok(NULL, " ,");
            char* r0tok = strtok(NULL, " ,");
            char* r1tok = strtok(NULL, " ,");

            write_opcode(mnemonic, &machineInstruction, OPCODE_SHIFT);
            write_register_code(r2tok, &machineInstruction, RT_REG_SHIFT);
            write_register_code(r1tok, &machineInstruction, RM_REG_SHIFT);
            write_register_code(r0tok, &machineInstruction, RN_REG_SHIFT);

            write_machine_instruction(fptr_write, machineInstruction); 
            
        }

        cmp_result = strcmp(mnemonic, CMP);

        if (cmp_result == 0)
        {
            //CMP R3, R1, R2
            char* r3tok = strtok(NULL, " ,");
            char* r1tok = strtok(NULL, " ,");
            char* r2tok = strtok(NULL, " ,");

            write_opcode(mnemonic, &machineInstruction, OPCODE_SHIFT);
            write_register_code(r3tok, &machineInstruction, RT_REG_SHIFT);
            write_register_code(r1tok, &machineInstruction, RM_REG_SHIFT);
            write_register_code(r2tok, &machineInstruction, RN_REG_SHIFT);

            write_machine_instruction(fptr_write, machineInstruction); 
            
        }

        cmp_result = strcmp(mnemonic, MUL);

        if (cmp_result == 0)
        {
            //MUL R2, R0, R1
            char* r2tok = strtok(NULL, " ,");
            char* r0tok = strtok(NULL, " ,");
            char* r1tok = strtok(NULL, " ,");

            write_opcode(mnemonic, &machineInstruction, OPCODE_SHIFT);
            write_register_code(r2tok, &machineInstruction, RT_REG_SHIFT);
            write_register_code(r1tok, &machineInstruction, RM_REG_SHIFT);
            write_register_code(r0tok, &machineInstruction, RN_REG_SHIFT);

            write_machine_instruction(fptr_write, machineInstruction); 
            
        }

        cmp_result = strcmp(mnemonic, DIV);

        if (cmp_result == 0)
        {
            //DIV R2, R0, R1
            char* r2tok = strtok(NULL, " ,");
            char* r0tok = strtok(NULL, " ,");
            char* r1tok = strtok(NULL, " ,");

            write_opcode(mnemonic, &machineInstruction, OPCODE_SHIFT);
            write_register_code(r2tok, &machineInstruction, RT_REG_SHIFT);
            write_register_code(r1tok, &machineInstruction, RM_REG_SHIFT);
            write_register_code(r0tok, &machineInstruction, RN_REG_SHIFT);

            write_machine_instruction(fptr_write, machineInstruction); 
            
        }

        cmp_result = strcmp(mnemonic, LDR);

        if (cmp_result == 0)
        {
            //LDR R1, [R0 + b0000]
            char* r1tok = strtok(NULL, ",");
            char* removeBracket = strtok(NULL, "[]");
            char* r0tok = strtok(NULL, " ");
            char* removePrefix = strtok(NULL, "b");
            char* immediate = strtok(NULL, " ]");

            write_opcode(mnemonic, &machineInstruction, OPCODE_SHIFT);
            write_register_code(r1tok, &machineInstruction, RT_REG_SHIFT);
            write_register_code(r0tok, &machineInstruction, RN_REG_SHIFT);
            write_immediate(immediate, &machineInstruction, IMM_8_BIT_SHIFT);            
        
            write_machine_instruction(fptr_write, machineInstruction); 
        }

        cmp_result = strcmp(mnemonic, STR);

        if (cmp_result == 0)
        {
            //STR R3, [R0 + b0000]
            char* r3tok = strtok(NULL, ",");
            char* removeBracket = strtok(NULL, "[]");
            char* r0tok = strtok(NULL, " ");
            char* removePrefix = strtok(NULL, "b");
            char* immediate = strtok(NULL, " ]");

            write_opcode(mnemonic, &machineInstruction, OPCODE_SHIFT);
            write_register_code(r3tok, &machineInstruction, RT_REG_SHIFT);
            write_register_code(r0tok, &machineInstruction, RN_REG_SHIFT);
            write_immediate(immediate, &machineInstruction, IMM_8_BIT_SHIFT);            
        
            write_machine_instruction(fptr_write, machineInstruction);             
        }

        cmp_result = strcmp(mnemonic, BE);

        if (cmp_result == 0)
        {
            //BE R3, b00011100
            char* r3tok = strtok(NULL, ",");
            char* prefixRemoval = strtok(NULL," b");
            char* immediate = strtok(NULL, " \0");

            write_opcode(mnemonic, &machineInstruction, OPCODE_SHIFT);
            write_register_code(r3tok, &machineInstruction, RT_REG_SHIFT);
            write_immediate(immediate, &machineInstruction, IMM_8_BIT_SHIFT);

            write_machine_instruction(fptr_write, machineInstruction);             
        }

        cmp_result = strcmp(mnemonic, BNE);

        if (cmp_result == 0)
        {
            //BNE R3, b00011100
            char* r3tok = strtok(NULL, ",");
            char* prefixRemoval = strtok(NULL," b");
            char* immediate = strtok(NULL, " \0");

            write_opcode(mnemonic, &machineInstruction, OPCODE_SHIFT);
            write_register_code(r3tok, &machineInstruction,RT_REG_SHIFT);
            write_immediate(immediate, &machineInstruction, IMM_8_BIT_SHIFT);

            write_machine_instruction(fptr_write, machineInstruction);    
            
        }

        cmp_result = strcmp(mnemonic, BL);

        if (cmp_result == 0)
        {
            //BL R3, b00011100
            char* r3tok = strtok(NULL, ",");
            char* prefixRemoval = strtok(NULL,"b");
            char* immediate = strtok(NULL, " \0");

            write_opcode(mnemonic, &machineInstruction, OPCODE_SHIFT);
            write_register_code(r3tok, &machineInstruction,RT_REG_SHIFT);
            write_immediate(immediate, &machineInstruction, IMM_8_BIT_SHIFT);

            write_machine_instruction(fptr_write, machineInstruction);    
            
        }

        cmp_result = strcmp(mnemonic, BG);

        if (cmp_result == 0)
        {
            //BG R3, b00011100
            char* r3tok = strtok(NULL, ",");
            char* prefixRemoval = strtok(NULL," b");
            char* immediate = strtok(NULL, " \0");

            write_opcode(mnemonic, &machineInstruction, OPCODE_SHIFT);
            write_register_code(r3tok, &machineInstruction,RT_REG_SHIFT);
            write_immediate(immediate, &machineInstruction, IMM_8_BIT_SHIFT);

            write_machine_instruction(fptr_write, machineInstruction);    
            
        }

        cmp_result = strcmp(mnemonic, BLE);

        if (cmp_result == 0)
        {
            //BLE R3, b00011100
            char* r3tok = strtok(NULL, ",");
            char* prefixRemoval = strtok(NULL," b");
            char* immediate = strtok(NULL, " \0");

            write_opcode(mnemonic, &machineInstruction, OPCODE_SHIFT);
            write_register_code(r3tok, &machineInstruction,RT_REG_SHIFT);
            write_immediate(immediate, &machineInstruction, IMM_8_BIT_SHIFT);

            write_machine_instruction(fptr_write, machineInstruction);    
            
        }

        cmp_result = strcmp(mnemonic, BGE);

        if (cmp_result == 0)
        {
            //BGE R3, b00011100
            char* r3tok = strtok(NULL, ",");
            char* prefixRemoval = strtok(NULL," b");
            char* immediate = strtok(NULL, " \0");

            write_opcode(mnemonic, &machineInstruction, OPCODE_SHIFT);
            write_register_code(r3tok, &machineInstruction,RT_REG_SHIFT);
            write_immediate(immediate, &machineInstruction, IMM_8_BIT_SHIFT);

            write_machine_instruction(fptr_write, machineInstruction);    
            
        }

        cmp_result = strcmp(mnemonic, B);

        if (cmp_result == 0)
        {
            //B  b00100000
            char* prefixRemoval = strtok(NULL,"b");
            char* immediate = strtok(NULL, " \0");

            write_opcode(mnemonic, &machineInstruction, OPCODE_SHIFT);
            write_immediate(immediate, &machineInstruction, IMM_8_BIT_SHIFT);

            write_machine_instruction(fptr_write, machineInstruction);    
            
        }

        cmp_result = strcmp(mnemonic, HALT);

        if (cmp_result == 0)
        {
            write_opcode(mnemonic, &machineInstruction, OPCODE_SHIFT);
            
            write_machine_instruction(fptr_write, machineInstruction);
        }

        result = fgets(file_line, ASSEMBLY_STATEMENT_BUFFER_SIZE, fptr_read);
    }

    fclose(fptr_read);
    fclose(fptr_write);
}

void write_opcode(char* opcode, unsigned short* machineInstruction, unsigned short leftShift)
{
    unsigned short machineOpcode = 0;
    int cmp_result = 0;

    cmp_result = strcmp(opcode, MOVI);
    if (cmp_result == 0) machineOpcode = OPCODE_MOVI;

    cmp_result = strcmp(opcode, ADD);
    if (cmp_result == 0) machineOpcode = OPCODE_ADD;

    cmp_result = strcmp(opcode, SUB);
    if (cmp_result == 0) machineOpcode = OPCODE_SUB;

    cmp_result = strcmp(opcode, CMP);
    if (cmp_result == 0) machineOpcode = OPCODE_CMP;

    cmp_result = strcmp(opcode, MUL);
    if (cmp_result == 0) machineOpcode = OPCODE_MUL;

    cmp_result = strcmp(opcode, DIV);
    if (cmp_result == 0) machineOpcode = OPCODE_DIV;

    cmp_result = strcmp(opcode, LDR);
    if (cmp_result == 0) machineOpcode = OPCODE_LDR;

    cmp_result = strcmp(opcode, STR);
    if (cmp_result == 0) machineOpcode = OPCODE_STR;

    cmp_result = strcmp(opcode, BE);
    if (cmp_result == 0) machineOpcode = OPCODE_BE;

    cmp_result = strcmp(opcode, BNE);
    if (cmp_result == 0) machineOpcode = OPCODE_BNE;

    cmp_result = strcmp(opcode, BL);
    if (cmp_result == 0) machineOpcode = OPCODE_BL;

    cmp_result = strcmp(opcode, BG);
    if (cmp_result == 0) machineOpcode = OPCODE_BG;

    cmp_result = strcmp(opcode, BLE);
    if (cmp_result == 0) machineOpcode = OPCODE_BLE;

    cmp_result = strcmp(opcode, BGE);
    if (cmp_result == 0) machineOpcode = OPCODE_BGE;

    cmp_result = strcmp(opcode, B);
    if (cmp_result == 0) machineOpcode = OPCODE_B;

    cmp_result = strcmp(opcode, HALT);
    if (cmp_result == 0) machineOpcode = OPCODE_HALT;   

    machineOpcode = machineOpcode << leftShift;
    *machineInstruction = *machineInstruction | machineOpcode;
}

void write_register_code(char* reg_num, unsigned short* machineInstruction, unsigned short leftShift)
{
    unsigned short machineRegister = 0;
    int cmp_result = 0;

    cmp_result = strcmp(reg_num, ACRO_R0);
    if (cmp_result == 0) machineRegister = MCRO_R0;
	
    cmp_result = strcmp(reg_num, ACRO_R1);
    if (cmp_result == 0) machineRegister = MCRO_R1;

    cmp_result = strcmp(reg_num, ACRO_R2);
    if (cmp_result == 0) machineRegister = MCRO_R2;

    cmp_result = strcmp(reg_num, ACRO_R3);
    if (cmp_result == 0) machineRegister = MCRO_R3;

    cmp_result = strcmp(reg_num, ACRO_R4);
    if (cmp_result == 0) machineRegister = MCRO_R4;

    cmp_result = strcmp(reg_num, ACRO_R5);
    if (cmp_result == 0) machineRegister = MCRO_R5;

    cmp_result = strcmp(reg_num, ACRO_R6);
    if (cmp_result == 0) machineRegister = MCRO_R6;

    cmp_result = strcmp(reg_num, ACRO_R7);
    if (cmp_result == 0) machineRegister = MCRO_R7;

    cmp_result = strcmp(reg_num, ACRO_R8);
    if (cmp_result == 0) machineRegister = MCRO_R8;

    cmp_result = strcmp(reg_num, ACRO_R9);
    if (cmp_result == 0) machineRegister = MCRO_R9;

    cmp_result = strcmp(reg_num, ACRO_R10);
    if (cmp_result == 0) machineRegister = MCRO_R10;

    cmp_result = strcmp(reg_num, ACRO_R11);
    if (cmp_result == 0) machineRegister = MCRO_R11;

    cmp_result = strcmp(reg_num, ACRO_R12);
    if (cmp_result == 0) machineRegister = MCRO_R12;

    cmp_result = strcmp(reg_num, ACRO_R13);
    if (cmp_result == 0) machineRegister = MCRO_R13;

    cmp_result = strcmp(reg_num, ACRO_R14);
    if (cmp_result == 0) machineRegister = MCRO_R14;

    cmp_result = strcmp(reg_num, ACRO_R15);
    if (cmp_result == 0) machineRegister = MCRO_R15;

    machineRegister = machineRegister << leftShift;
    *machineInstruction = *machineInstruction | machineRegister;
}

void write_immediate(char* immediate, unsigned short* machineInstruction, unsigned short leftShift)
{
   unsigned short machineImmediate = (unsigned short)strtol(immediate, NULL, 2);
   
   machineImmediate = machineImmediate << leftShift;
   *machineInstruction = *machineInstruction | machineImmediate;
}

void write_machine_instruction(FILE* fptr_write, unsigned short machineInstruction)
{
    int result = fwrite(&machineInstruction, sizeof(unsigned short), 1, fptr_write);
}
