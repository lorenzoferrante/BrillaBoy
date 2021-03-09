//
// Created by Lorenzo Ferrante on 06/03/21.
//

#include "CPU.h"
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>

CPU::CPU(char *filename) {
    setUpTable();
    reset();
    //loadBootLoader();
    loadROM(filename);
}

void CPU::loadBootLoader() {
    // Absolute path???
    char* bootloader_path = "/Users/lorenzoferrante/CLionProjects/BrillaBoy/DMG_ROM.bin";
    FILE *fp = fopen(bootloader_path, "rb");
    fread(bootloader, sizeof(uint8_t), 256, fp);
    fclose(fp);

    for (long i = 0; i < 256; ++i) {
        memory[i] = bootloader[i];
    }
}

void CPU::reset() {
    memset(video, 0x00, sizeof(video));
    memset(video_buffer, 0x00, sizeof(video_buffer));
    memset(memory, 0, sizeof(memory));
    A = 0x0;
    B = 0x0;
    C = 0x0;
    D = 0x0;
    E = 0x0;
    F = 0x0;
    H = 0x0;
    L = 0x0;
}

void CPU::loadROM(char* filename) {
    std::ifstream file(filename, std::ios::binary | std::ios::ate);

    if (file.is_open()) {
        std::streampos size = file.tellg();
        char* buffer = new char[size];

        // Go back to the beginning of file and fill the buffer
        file.seekg(0, std::ios::beg);
        file.read(buffer, size);
        file.close();

        for (long i = 0; i < size; ++i) {
            memory[RAM_START_ADDRESS + i] = buffer[i];
        }

        delete[] buffer;
    }

    // Initialize PC and SP
    PC = RAM_START_ADDRESS;
    SP = SP_START_ADDRESS;
}

void CPU::cycle() {

}

// 16-bit REGISTERS
uint16_t CPU::getAF() const {
    return (A << 8) + F;
}

uint16_t CPU::getBC() const {
    return (B << 8) + C;
}

uint16_t CPU::getDE() const {
    return (D << 8) + E;
}

uint16_t CPU::getHL() const {
    return (H << 8) + L;
}

void CPU::set_F_Register(CPU::F_REGISTER_BITS flag) {
    switch (flag) {
        case ZERO_FLAG_SET:
            F |= 1UL << 7;
        case ZERO_FLAG_RESET:
            F &= 0UL << 7;
        case SUBTRACT_FLAG_SET:
            F |= 1UL << 6;
        case SUBTRACT_FLAG_RESET:
            F &= 0UL << 6;
        case HALF_CARRY_FLAG_SET:
            F |= 1UL << 5;
        case HALF_CARRY_FLAG_RESET:
            F &= 0UL << 5;
        case CARRY_FLAG_SET:
            F |= 1UL << 4;
        case CARRY_FLAG_RESET:
            F &= 0UL << 4;
    }
}

void CPU::execute() {
    opcode = memory[PC];
    printf("Code: 0x%X - Addr: 0x%X\n", opcode, PC);

    if (opcode == 0xCB) {
        PC += 0x1;
        opcode = memory[PC];
        // Decode and execute instruction
        ((*this).*(table_CB[opcode]))();
        PC += 0x1;
    } else {
        // Decode and execute instruction
        uint16_t oldPC = PC;
        ((*this).*(table[opcode]))();
        if (PC == oldPC) {
            PC += 0x2;
        }
    }
}