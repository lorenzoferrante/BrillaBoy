//
// Created by Lorenzo Ferrante on 06/03/21.
//

#include "CPU.h"
#include <fstream>
#include <sstream>
#include <string>

CPU::CPU(char *filename) {
    reset();
    //NintendoLogo();
    //loadBootLoader();
    loadROM(filename);
}


void CPU::NintendoLogo() {
    uint8_t buffer[256] = {
            0xCE, 0xED, 0x66, 0x66, 0xCC, 0x0D, 0x00, 0x0B, 0x03, 0x73, 0x00, 0x83,  0x00, 0x0C, 0x00, 0x0D,
            0x00, 0x08, 0x11, 0x1F, 0x88, 0x89, 0x00, 0x0E, 0xDC, 0xCC, 0x6E, 0xE6, 0xDD, 0xDD, 0xD9, 0x99,
            0xBB, 0xBB, 0x67, 0x63, 0x6E, 0x0E, 0xEC, 0xCC, 0xDD, 0xDC, 0x99, 0x9F, 0xBB, 0xB9, 0x33, 0x3E
    };

    for (long i = 0; i < 256; ++i) {
        video[i] = buffer[i];
    }
}

void CPU::loadBootLoader() {
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
