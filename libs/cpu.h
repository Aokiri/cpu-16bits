// Principal blueprint

#ifndef CPU_H
#define CPU_H

#include <stdint.h>
#include <stdbool.h>

#define NUM_REGISTERS   8           // 8 bits
#define MEMORY_SIZE     65536       // 64 KB of memory

// Status board lights
#define FLAG_ZERO       (1 << 0)    // 'The answer was 0'
#define FLAG_NEGATIVE   (1 << 1)    // 'The answer was negative'
#define FLAG_OVERFLOW   (1 << 2)    // 'The numbers wrapped around'

typedef struct {
    uint16_t registers[NUM_REGISTERS];  // The 8 bits (R0-R7)
    uint16_t pc;                        // Task checklist position (starts at task #0 - PC = 0x0000)
    uint16_t sp;                        // Inbox tray position (stack pointer, start at top - SP = 0xFFFF)
    uint16_t flags;                     // Status board (Z, N, O lights)
    uint8_t  memory[MEMORY_SIZE];       // The "filling cabinet"
    bool     halted;                    // Is the CPU halted?
    uint64_t cycles;                    // How many tasks completed
} CPU;

#endif