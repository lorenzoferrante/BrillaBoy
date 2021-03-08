//
// Created by Lorenzo Ferrante on 08/03/21.
//

#include "CPU.h"

// Utils functions
void load_r2_into_r1(CPU* cpu, uint8_t* r1, const uint8_t r2) {
    cpu->PC += 0x3;
    *r1 = r2;
}

void load_mem_into_r1(CPU* cpu, uint8_t* r1) {
    cpu->PC += 0x3;
    *r1 = cpu->memory[cpu->getHL()];
}

void load_r1_into_mem(CPU* cpu, const uint8_t r1) {
    cpu->PC += 0x3;
    cpu->memory[cpu->getHL()] = r1;
}

void load_nn_into_16reg(CPU* cpu, uint8_t* r1, uint8_t* r2) {
    cpu->PC += 0x2;
    uint16_t nn = cpu->memory[cpu->PC];
    *r1 = nn >> 8;
    *r2 = ((nn << 8) >> 8);
    cpu->PC += 0x1;
}

uint16_t swap_bytes(const uint8_t byte) {
    uint8_t hibyte = (byte & 0xFF00) >> 8;
    uint8_t lobyte = (byte & 0xFF);
    return ((lobyte << 8) | hibyte);
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
    switch (opcode) {
        case 0x7F:
            load_r2_into_r1(this, &A, A);
        case 0x78:
            load_r2_into_r1(this, &A, B);
        case 0x79:
            load_r2_into_r1(this, &A, C);
        case 0x7A:
            load_r2_into_r1(this, &A, D);
        case 0x7B:
            load_r2_into_r1(this, &A, E);
        case 0x7C:
            load_r2_into_r1(this, &A, H);
        case 0x7D:
            load_r2_into_r1(this, &A, L);
        case 0x7E:
            load_mem_into_r1(this, &A);
        case 0x40:
            load_r2_into_r1(this, &B, B);
        case 0x41:
            load_r2_into_r1(this, &B, C);
        case 0x42:
            load_r2_into_r1(this, &B, D);
        case 0x43:
            load_r2_into_r1(this, &B, E);
        case 0x44:
            load_r2_into_r1(this, &B, H);
        case 0x45:
            load_r2_into_r1(this, &B, L);
        case 0x46:
            load_mem_into_r1(this, &B);
        case 0x48:
            load_r2_into_r1(this, &C, B);
        case 0x49:
            load_r2_into_r1(this, &C, C);
        case 0x4A:
            load_r2_into_r1(this, &C, D);
        case 0x4B:
            load_r2_into_r1(this, &C, E);
        case 0x4C:
            load_r2_into_r1(this, &C, H);
        case 0x4D:
            load_r2_into_r1(this, &C, L);
        case 0x4E:
            load_mem_into_r1(this, &C);
        case 0x50:
            load_r2_into_r1(this, &D, B);
        case 0x51:
            load_r2_into_r1(this, &D, C);
        case 0x52:
            load_r2_into_r1(this, &D, D);
        case 0x53:
            load_r2_into_r1(this, &D, E);
        case 0x54:
            load_r2_into_r1(this, &D, H);
        case 0x55:
            load_r2_into_r1(this, &D, L);
        case 0x56:
            load_mem_into_r1(this, &D);
        case 0x58:
            load_r2_into_r1(this, &E, B);
        case 0x59:
            load_r2_into_r1(this, &E, C);
        case 0x5A:
            load_r2_into_r1(this, &E, D);
        case 0x5B:
            load_r2_into_r1(this, &E, E);
        case 0x5C:
            load_r2_into_r1(this, &E, H);
        case 0x5D:
            load_r2_into_r1(this, &E, L);
        case 0x5E:
            load_mem_into_r1(this, &E);
        case 0x60:
            load_r2_into_r1(this, &H, B);
        case 0x61:
            load_r2_into_r1(this, &H, C);
        case 0x62:
            load_r2_into_r1(this, &H, D);
        case 0x63:
            load_r2_into_r1(this, &H, E);
        case 0x64:
            load_r2_into_r1(this, &H, H);
        case 0x65:
            load_r2_into_r1(this, &H, L);
        case 0x66:
            load_mem_into_r1(this, &H);
        case 0x68:
            load_r2_into_r1(this, &L, B);
        case 0x69:
            load_r2_into_r1(this, &L, C);
        case 0x6A:
            load_r2_into_r1(this, &L, D);
        case 0x6B:
            load_r2_into_r1(this, &L, E);
        case 0x6C:
            load_r2_into_r1(this, &L, H);
        case 0x6D:
            load_r2_into_r1(this, &L, L);
        case 0x6E:
            load_mem_into_r1(this, &L);
        case 0x70:
            load_r1_into_mem(this, B);
        case 0x71:
            load_r1_into_mem(this, C);
        case 0x72:
            load_r1_into_mem(this, D);
        case 0x73:
            load_r1_into_mem(this, E);
        case 0x74:
            load_r1_into_mem(this, H);
        case 0x75:
            load_r1_into_mem(this, L);
        case 0x36:
            PC += 0x2;
            memory[getHL()] = memory[PC];
            PC += 0x1;
    }
}

void CPU::LD_A_n() {
    switch (opcode) {
        case 0x7F:
            load_r2_into_r1(this, &A, A);
        case 0x78:
            load_r2_into_r1(this, &A, B);
        case 0x79:
            load_r2_into_r1(this, &A, C);
        case 0x7A:
            load_r2_into_r1(this, &A, D);
        case 0x7B:
            load_r2_into_r1(this, &A, E);
        case 0x7C:
            load_r2_into_r1(this, &A, H);
        case 0x7D:
            load_r2_into_r1(this, &A, L);
        case 0x0A:
            load_r2_into_r1(this, &A, memory[getBC()]);
        case 0x1A:
            load_r2_into_r1(this, &A, memory[getDE()]);
        case 0x7E:
            load_r2_into_r1(this, &A, memory[getHL()]);
        case 0xFA:
            PC += 0x2;
            A = swap_bytes(memory[PC]);
            PC += 0x1;
        case 0x35:
            NO_OP();    // NOT IMPLEMENTED
    }
}

void CPU::LD_n_A() {
    switch (opcode) {
        case 0x7F:
            load_r2_into_r1(this, &A, A);
        case 0x47:
            load_r2_into_r1(this, &B, A);
        case 0x4F:
            load_r2_into_r1(this, &C, A);
        case 0x57:
            load_r2_into_r1(this, &D, A);
        case 0x5F:
            load_r2_into_r1(this, &E, A);
        case 0x67:
            load_r2_into_r1(this, &H, A);
        case 0x6F:
            load_r2_into_r1(this, &L, A);
        case 0x02:
            PC += 0x3;
            memory[getBC()] = A;
        case 0x12:
            PC += 0x3;
            memory[getDE()] = A;
        case 0x77:
            PC += 0x3;
            memory[getHL()] = A;
        case 0xEA:
            PC += 0x2;
            memory[swap_bytes(memory[PC])] = A;
            PC += 0x1;
    }
}

void CPU::LD_A_addr_C() {
    PC += 0x3;
    A = 0xFF00 + C;
}

void CPU::LD_addr_C_A() {
    PC += 0x3;
    memory[0xFF00 + C] = A;
}

void CPU::LD_A_HL_dec() {
    PC += 0x3;
    A = memory[getHL()];
    L -= 0x1;
}

void CPU::LD_HL_dec_A() {
    PC += 0x3;
    memory[getHL()] = A;
    L -= 0x1;
}

void CPU::LD_A_HL_inc() {
    PC += 0x3;
    A = memory[getHL()];
    L += 0x1;
}

void CPU::LD_HL_inc_A() {
    PC += 0x3;
    memory[getHL()]  = A;
    L += 0x1;
}

void CPU::LDH_addr_n_A() {
    PC += 0x2;
    memory[0xFF00 + memory[PC]] = A;
    PC += 0x1;
}

void CPU::LDH_A_addr_n() {
    PC += 0x2;
    A = memory[0xFF00 + memory[PC]];
    PC += 0x1;
}

void CPU::LD_n_nn() {
    switch (opcode) {
        case 0x01:
            load_nn_into_16reg(this, &B, &C);
        case 0x11:
            load_nn_into_16reg(this, &D, &E);
        case 0x21:
            load_nn_into_16reg(this, &H, &L);
        case 0x31:
            PC += 0x2;
            SP = memory[PC];
            PC += 0x1;
    }
}

void CPU::LD_SP_HL() {
    PC += 0x3;
    SP = getHL();
}

void CPU::LD_HL_SP_inc_n() {

}

void CPU::LDHL_SP_n() {
    LD_HL_SP_inc_n();
}

void CPU::LD_addr_nn_SP() {

}

void CPU::PUSH_nn() {

}

void CPU::POP_nn() {

}

void CPU::ADD_A_n() {

}

void CPU::ADC_A_n() {

}

void CPU::SUB_n() {

}

void CPU::SBC_A_n() {

}

void CPU::AND_n() {

}

void CPU::OR_n() {

}

void CPU::XOR_n() {

}

void CPU::CP_n() {

}

void CPU::INC_n() {

}

void CPU::DEC_n() {

}

void CPU::ADD_HL_n() {

}

void CPU::ADD_SP_n() {

}

void CPU::INC_nn() {

}

void CPU::DEC_nn() {

}

void CPU::SWAP_n() {

}

void CPU::DAA() {

}

void CPU::CPL() {

}

void CPU::CCF() {

}

void CPU::SCF() {

}

void CPU::HALT() {

}

void CPU::STOP() {

}

void CPU::DI() {

}

void CPU::EI() {

}

void CPU::RLCA() {

}

void CPU::RLA() {

}

void CPU::RRCA() {

}

void CPU::RRA() {

}

void CPU::RLC_n() {

}

void CPU::RL_n() {

}

void CPU::RRC_n() {

}

void CPU::RR_n() {

}

void CPU::SLA_n() {

}

void CPU::SRA_n() {

}

void CPU::SRL_n() {

}

void CPU::BIT_b_r() {

}

void CPU::SET_b_r() {

}

void CPU::RES_b_r() {

}

void CPU::JP_nn() {

}

void CPU::JP_cc_nn() {

}

void CPU::JP_addr_HL() {

}

void CPU::JR_n() {

}

void CPU::JR_cc_n() {

}

void CPU::CALL_nn() {

}

void CPU::CALL_cc_nn() {

}

void CPU::RST_n() {

}

void CPU::RET() {

}

void CPU::RET_cc() {

}

void CPU::RETI() {

}

