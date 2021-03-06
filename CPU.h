//
// Created by Lorenzo Ferrante on 06/03/21.
//

#ifndef BRILLABOY_CPU_H
#define BRILLABOY_CPU_H

#include <cstdint>

class CPU {

    /*
     *  F Register Bits:
     *  |- - - - - - - - - - - - - - - -|
     *  | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
     *  | - | - | - | - | - | - | - | - |
     *  | Z | N | H | C | 0 | 0 | 0 | 0 |
     *  |- - - - - - - - - - - - - - - -|
     */
    enum F_REGISTER_BITS: int {
        ZERO_FLAG,
        SUBTRACT_FLAG,
        HALF_CARRY_FLAG,
        CARRY_FLAG
    };

    static const int CPU_MEM_SIZE       =   65535;
    static const int RAM_START_ADDRESS  =   0x100;
    static const int SP_START_ADDRESS   =   0xFFFE;
    static const int SCREEN_WIDTH       =   160;
    static const int SCREEN_HEIGHT      =   144;
    static const int SCREEN_BUFFER      =   256;

    // Special I/O registers
    static const unsigned int P1 =   0xFF00;     // Register for reading joy pad info and determining system type
    static const unsigned int SB =   0xFF01;     // Serial transfer data (R/W)
    static const unsigned int SC =   0xFF02;     // SIO control (R/W)
    static const unsigned int DIV =  0xFF04;     // Divider Register (R/W)
    static const unsigned int TIMA = 0xFF05;     // Timer counter (R/W)
    static const unsigned int TMA =  0xFF06;     // Timer Modulo (R/W)
    static const unsigned int TAC =  0xFF07;     // Timer Control (R/W)
    static const unsigned int IF =   0xFF0F;     // Interrupt Flag (R/W)
    static const unsigned int LCDC = 0xFF40;     // LCD Control (R/W)
    static const unsigned int STAT = 0xFF41;     // LCDC Status (R/W)
    static const unsigned int SCY =  0xFF42;     // Scroll Y (R/W)
    static const unsigned int SCX =  0xFF43;     // Scroll X
    static const unsigned int LY =   0xFF44;     // LDCD Y-coordinate (R)
    static const unsigned int LYC =  0xFF45;     // LY Compare (R/W)
    static const unsigned int DMA =  0xFF46;     // DMA transfer and start address (W)
    static const unsigned int BGP =  0xFF47;     // BG and Window palette data (R/W)
    static const unsigned int OBPO = 0xFF48;     // Object palette 0 data (R/W)
    static const unsigned int OBP1 = 0xFF49;     // Object palette 1 data (R/W)
    static const unsigned int WY =   0xFF4A;     // Window Y position (R/W)
    static const unsigned int WX =   0xFF4B;     // Window X position (R/W)
    static const unsigned int IE =   0xFFFF;     // Interrupt Enable (R/W)

public:
    CPU(char* filename);
    void reset();
    void setUpTable();
    void loadBootLoader();
    void loadROM(char* filename);
    void cycle();
    void set_F_Register(F_REGISTER_BITS flag);
    void execute();

    // Opcode
    uint8_t opcode{};

    // Memory
    uint8_t bootloader[256]{};
    uint8_t memory[CPU_MEM_SIZE]{};

    // Video
    uint32_t video[SCREEN_WIDTH * SCREEN_HEIGHT]{};
    uint32_t video_buffer[SCREEN_BUFFER * SCREEN_BUFFER]{};

    // 8-bit Registers
    uint8_t A;
    uint8_t F;
    uint8_t B;
    uint8_t C;
    uint8_t D;
    uint8_t E;
    uint8_t H;
    uint8_t L;

    // SP & PC Registers
    uint16_t SP;
    uint16_t PC;

    // Get 16-bit registers
    uint16_t getAF() const;
    uint16_t getBC() const;
    uint16_t getDE() const;
    uint16_t getHL() const;

    typedef void (CPU::*CPUFunc)();
    CPUFunc table[256];

    // Opcodes
    void NO_OP();
    void LD_nn_n();
    void LD_r1_r2();
    void LD_A_n();
    void LD_n_A();
    void LD_A_addr_C();
    void LD_addr_C_A();
    void LD_A_addr_HLD();
    void LD_A_addr_HL_minus();
    void LDD_A_addr_HL();
    void LD_addr_HLD_A();
    // Page 72
};


#endif //BRILLABOY_CPU_H
