// Memory operations

#include <string.h>
#include <stdio.h>
#include "cpu.h"

// Initialization: Reset the CPU
void cpu_init(CPU *cpu) {
    memset(cpu->registers, 0, sizeof(cpu->registers));
    memset(cpu->memory, 0, sizeof(cpu->memory));
    cpu->pc     = 0x0000;
    cpu->sp     = 0xFFFF;
    cpu->flags  = 0;
    cpu->halted = false;
    cpu->cycles = 0;
}

// Go to memory, take two addresses and combine them into a 16-bit value (read)
uint16_t mem_read16(CPU *cpu, uint16_t address) {
    uint16_t low  = cpu->memory[address];
    uint16_t high = cpu->memory[address + 1];
    return (high << 8) | low;
}

// Go to memory, split a 16-bit value into an address (write)
uint16_t mem_write16(CPU *cpu, uint16_t address, uint16_t value) {
    cpu->memory[address]        = value & 0xFF;
    cpu->memory[address + 1]    = (value << 8) & 0xFF;
}