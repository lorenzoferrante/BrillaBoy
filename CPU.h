//
// Created by Lorenzo Ferrante on 06/03/21.
//

#ifndef BRILLABOY_CPU_H
#define BRILLABOY_CPU_H

#include <cstdint>

class CPU {
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
    /*
     *  F Register Bits:
     *  |- - - - - - - - - - - - - - - -|
     *  | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
     *  | - | - | - | - | - | - | - | - |
     *  | Z | N | H | C | 0 | 0 | 0 | 0 |
     *  |- - - - - - - - - - - - - - - -|
     */
    enum F_REGISTER_BITS: int {
        ZERO_FLAG_SET,
        ZERO_FLAG_RESET,
        SUBTRACT_FLAG_SET,
        SUBTRACT_FLAG_RESET,
        HALF_CARRY_FLAG_SET,
        HALF_CARRY_FLAG_RESET,
        CARRY_FLAG_SET,
        CARRY_FLAG_RESET
    };

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
    uint16_t memory[CPU_MEM_SIZE]{};

    // Video
    uint8_t video[SCREEN_WIDTH * SCREEN_HEIGHT]{};
    uint8_t video_buffer[SCREEN_BUFFER * SCREEN_BUFFER]{};

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
    CPUFunc table_CB[256];

    // Opcodes
    void NO_OP();
    void LD_nn_n();
    void LD_r1_r2();
    void LD_A_n();
    void LD_n_A();
    void LD_A_addr_C();
    void LD_addr_C_A();
    void LD_A_HL_dec();
    void LD_HL_dec_A();
    void LD_A_HL_inc();
    void LD_HL_inc_A();
    void LDH_addr_n_A();
    void LDH_A_addr_n();
    void LD_n_nn();
    void LD_SP_HL();
    void LD_HL_SP_inc_n();
    void LDHL_SP_n();
    void LD_addr_nn_SP();
    void PUSH_nn();
    void POP_nn();
    void ADD_A_n();
    void ADC_A_n();
    void SUB_n();
    void SBC_A_n();
    void AND_n();
    void OR_n();
    void XOR_n();
    void CP_n();
    void INC_n();
    void DEC_n();
    void ADD_HL_n();
    void ADD_SP_n();
    void INC_nn();
    void DEC_nn();
    void SWAP_n();
    void DAA();
    void CPL();
    void CCF();
    void SCF();
    void HALT();
    void STOP();
    void DI();
    void EI();
    void RLCA();
    void RLA();
    void RRCA();
    void RRA();

    // Prefix CB
    void RLC_n();
    void RL_n();
    void RRC_n();
    void RR_n();
    void SLA_n();
    void SRA_n();
    void SRL_n();
    void BIT_b_r();
    void SET_b_r();
    void RES_b_r();

    // Jumps
    void JP_nn();
    void JP_cc_nn();
    void JP_addr_HL();
    void JR_n();
    void JR_cc_n();

    // Calls
    void CALL_nn();
    void CALL_cc_nn();

    // Restarts
    void RST_n();

    // Returns
    void RET();
    void RET_cc();
    void RETI();

};

extern void load_r2_into_r1(CPU* cpu, uint8_t* r1, const uint8_t r2);
extern void load_r2_into_r1(CPU* cpu, uint8_t* r1, const uint8_t r2);
extern void load_mem_into_r1(CPU* cpu, uint8_t* r1);
extern void load_r1_into_mem(CPU* cpu, const uint8_t r1);
extern void load_nn_into_16reg(CPU* cpu, uint8_t* r1, uint8_t* r2);
extern void push_nn_onto_sp(CPU* cpu, const uint8_t* r1, const uint8_t* r2);
extern void pop_from_sp_to_reg(CPU* cpu, uint8_t* r1, uint8_t* r2);
extern uint16_t swap_bytes(const uint8_t byte);
extern void add_reg_to_A(CPU *cpu, const uint8_t* r);
extern void add_carry_to_a(CPU* cpu, const uint8_t* r);
extern void sub_reg_to_A(CPU* cpu, const uint8_t* r);
extern void sub_carry_to_A(CPU* cpu, const uint8_t* r);
extern void and_A(CPU* cpu, const uint8_t* r);
extern void or_A(CPU* cpu, const uint8_t* r);
extern void xor_A(CPU* cpu, const uint8_t* r);
extern void cp_A_n(CPU* cpu, const uint8_t* r);
extern void inc_reg(CPU* cpu, uint8_t* r);
extern void dec_reg(CPU* cpu, uint8_t* r);
extern void add_r2_to_r1_16(CPU* cpu, uint8_t r1, uint8_t r2);
extern void add_sp_to_hl(CPU* cpu);
extern void add_n_to_SP(CPU *cpu);
extern void inc_reg_16(CPU* cpu, uint8_t* r1, uint8_t* r2, uint16_t r16);
extern void dec_reg_16(CPU* cpu, uint8_t* r1, uint8_t* r2, uint16_t r16);
extern void swap_reg_n(CPU* cpu, uint8_t* r);

#endif //BRILLABOY_CPU_H
