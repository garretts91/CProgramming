#pragma once

//Assembly mnemonics 
#define MOVI "MOVI"
#define ADD  "ADD"
#define SUB  "SUB"
#define CMP  "CMP"
#define MUL  "MUL"
#define DIV  "DIV"
#define LDR  "LDR"
#define STR  "STR"
#define BE   "BE"
#define BNE  "BNE"
#define BL   "BL"
#define BG   "BG"
#define BLE  "BLE"
#define BGE  "BGE"
#define B    "B"
#define HALT "HALT"

//Machine Opcodes
#define OPCODE_MOVI 0x00
#define OPCODE_ADD  0x01
#define OPCODE_SUB  0x02
#define OPCODE_CMP  0x03
#define OPCODE_MUL  0x04
#define OPCODE_DIV  0x05
#define OPCODE_LDR  0x06
#define OPCODE_STR  0x07
#define OPCODE_BE   0x08
#define OPCODE_BNE  0x09
#define OPCODE_BL   0x0A
#define OPCODE_BG   0x0B
#define OPCODE_BLE  0x0C
#define OPCODE_BGE  0x0D
#define OPCODE_B    0x0E
#define OPCODE_HALT 0x0F
