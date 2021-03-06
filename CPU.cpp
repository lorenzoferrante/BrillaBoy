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

void CPU::setUpTable() {
    for (auto & i : table) {
        i = &CPU::NO_OP;
    }
    table[0x06] = &CPU::LD_nn_n;
    table[0x0E] = &CPU::LD_nn_n;
    table[0x16] = &CPU::LD_nn_n;
    table[0x1E] = &CPU::LD_nn_n;
    table[0x26] = &CPU::LD_nn_n;
    table[0x2E] = &CPU::LD_nn_n;
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
    memset(video, 0x0, sizeof(video));
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
        case ZERO_FLAG:
            F |= 1UL << 7;
        case SUBTRACT_FLAG:
            F |= 1UL << 6;
        case HALF_CARRY_FLAG:
            F |= 1UL << 5;
        case CARRY_FLAG:
            F |= 1UL << 4;
    }
}

void CPU::execute() {
    opcode = memory[PC];
    printf("CODE: %X\n", opcode);

    // Decode and execute instruction
    ((*this).*(table[opcode]))();
}

// Opcodes
void CPU::NO_OP() {
    PC += 1;
}

void CPU::LD_nn_n() {
    switch (opcode) {
        case 0x06:
            PC += 0x2;
            B = memory[PC++];
        case 0x0E:
            PC += 0x2;
            C = memory[PC++];
        case 0x16:
            PC += 0x2;
            D = memory[PC++];
        case 0x1E:
            PC += 0x2;
            E = memory[PC++];
        case 0x26:
            PC += 0x2;
            H = memory[PC++];
        case 0x2E:
            PC += 0x2;
            L = memory[PC++];
    }
}

void CPU::LD_r1_r2() {

}

void CPU::LD_A_n() {

}

void CPU::LD_n_A() {

}

void CPU::LD_A_addr_C() {

}

void CPU::LD_addr_C_A() {

}

void CPU::LD_A_addr_HLD() {

}

void CPU::LD_A_addr_HL_minus() {

}

void CPU::LDD_A_addr_HL() {

}

void CPU::LD_addr_HLD_A() {

}
