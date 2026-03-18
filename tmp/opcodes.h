// The 23 tasks that the CPU understands

#ifndef OPCODES_H
#define OPCODES_H

typedef enum {
    OP_NOP  = 0x00, // Do nothing
    OP_LOAD = 0x01, // Write a number on a Register (2-bits, next bit is a number)
    OP_MOV  = 0x02, // Copy one Register to another
    OP_ADD  = 0x03, // Add two Registers
    OP_SUB  = 0x04, // Substract two Registers
    OP_AND  = 0x05, // Bitwise AND
    OP_OR   = 0x06, // Bitwise OR
    OP_XOR  = 0x07, // Bitwise XOR
    OP_NOT  = 0x08, // Bitwise NOT (flip all bits)
    OP_SHL  = 0x09, // Shift bits left
    OP_SHR  = 0x0A, // Shift bits right
    OP_CMP  = 0x0B, // Compare (substract but only update status board)
    OP_JMP  = 0x0C, // Jump to task #N
    OP_JZ   = 0x0D, // Jump IF Zero light is on
    OP_JNZ  = 0x0E, // Jump IF Zero light is off
    OP_JN   = 0x0F, // Jump IF Negative light is on
    OP_LDR  = 0x10, // Load from Memory into Register
    OP_STR  = 0x11, // Store Register into Memory
    OP_PUSH = 0x12, // Push onto Stack (SP)
    OP_POP  = 0x13, // Pop from Stack (SP)
    OP_CALL = 0x14, // Bookmark and jump to subroutine (2-bits)
    OP_RET  = 0x15, // Return from subroutine (pop bookmark)
    OP_HALT = 0x16, // Stop CPU
} Opcode;

#endif