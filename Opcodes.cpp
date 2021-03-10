//
// Created by Lorenzo Ferrante on 08/03/21.
//
#include "CPU.h"

// Opcodes
void CPU::NO_OP() {
    PC += 1;
}

void CPU::LD_nn_n() {
    switch (opcode) {
        case 0x06:
            PC += 0x1;
            B = memory[PC++];
        case 0x0E:
            PC += 0x1;
            C = memory[PC++];
        case 0x16:
            PC += 0x1;
            D = memory[PC++];
        case 0x1E:
            PC += 0x1;
            E = memory[PC++];
        case 0x26:
            PC += 0x1;
            H = memory[PC++];
        case 0x2E:
            PC += 0x1;
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
            load_r2_into_r1(this, &L, memory[getHL()]);
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
            PC += 0x1;
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
            PC += 0x1;
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
            PC += 0x1;
            memory[getBC()] = A;
        case 0x12:
            PC += 0x1;
            memory[getDE()] = A;
        case 0x77:
            PC += 0x1;
            memory[getHL()] = A;
        case 0xEA:
            PC += 0x1;
            memory[swap_bytes(memory[PC])] = A;
            PC += 0x1;
    }
}

void CPU::LD_A_addr_C() {
    PC += 0x1;
    A = 0xFF00 + C;
}

void CPU::LD_addr_C_A() {
    PC += 0x1;
    memory[0xFF00 + C] = A;
}

void CPU::LD_A_HL_dec() {
    PC += 0x1;
    A = memory[getHL()];
    L -= 0x1;
}

void CPU::LD_HL_dec_A() {
    PC += 0x1;
    memory[getHL()] = A;
    L -= 0x1;
}

void CPU::LD_A_HL_inc() {
    PC += 0x1;
    A = memory[getHL()];
    L += 0x1;
}

void CPU::LD_HL_inc_A() {
    PC += 0x1;
    memory[getHL()]  = A;
    L += 0x1;
}

void CPU::LDH_addr_n_A() {
    PC += 0x1;
    memory[0xFF00 + memory[PC]] = A;
    PC += 0x1;
}

void CPU::LDH_A_addr_n() {
    PC += 0x1;
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
            PC += 0x1;
            SP = memory[PC];
            PC += 0x1;
    }
}

void CPU::LD_SP_HL() {
    PC += 0x1;
    SP = getHL();
}

void CPU::LD_HL_SP_inc_n() {
    PC += 0x1;
    uint16_t nn = SP + memory[PC];
    H = nn >> 8;
    L = ((nn << 8) >> 8);
    PC += 0x1;
}

void CPU::LDHL_SP_n() {
    LD_HL_SP_inc_n();
}

void CPU::LD_addr_nn_SP() {
    PC += 0x1;
    memory[PC] = SP;
    PC += 0x1;
}

void CPU::PUSH_nn() {
    PC += 0x1;
    switch (opcode) {
        case 0xF5:
            push_nn_onto_sp(this, &A, &F);
        case 0xC5:
            push_nn_onto_sp(this, &B, &C);
        case 0xD5:
            push_nn_onto_sp(this, &D, &E);
        case 0xE5:
            push_nn_onto_sp(this, &H, &L);
    }
}

void CPU::POP_nn() {
    PC += 0x1;
    switch (opcode) {
        case 0xF1:
            pop_from_sp_to_reg(this, &A, &F);
        case 0xC1:
            pop_from_sp_to_reg(this, &B, &C);
        case 0xD1:
            pop_from_sp_to_reg(this, &D, &E);
        case 0xE1:
            pop_from_sp_to_reg(this, &H, &L);
    }
}

void CPU::ADD_A_n() {
    PC += 01;
    switch (opcode) {
        case 0x87:
            add_reg_to_A(this, &A);
        case 0x80:
            add_reg_to_A(this, &B);
        case 0x81:
            add_reg_to_A(this, &C);
        case 0x82:
            add_reg_to_A(this, &D);
        case 0x83:
            add_reg_to_A(this, &E);
        case 0x84:
            add_reg_to_A(this, &H);
        case 0x85:
            add_reg_to_A(this, &L);
        case 0x86:
            add_reg_to_A(this, reinterpret_cast<const uint8_t *>(&memory[getHL()]));
        case 0xC6:
            NO_OP();
    }
}

void CPU::ADC_A_n() {
    PC += 01;
    switch (opcode) {
        case 0x8F:
            add_carry_to_a(this, &A);
        case 0x88:
            add_carry_to_a(this, &B);
        case 0x89:
            add_carry_to_a(this, &C);
        case 0x8A:
            add_carry_to_a(this, &D);
        case 0x8B:
            add_carry_to_a(this, &E);
        case 0x8C:
            add_carry_to_a(this, &H);
        case 0x8D:
            add_carry_to_a(this, &L);
        case 0x8E:
            add_carry_to_a(this, reinterpret_cast<const uint8_t *>(&memory[getHL()]));
        case 0xCE:
            NO_OP();
    }
}

void CPU::SUB_n() {
    PC += 0x1;
    switch (opcode) {
        case 0x97:
            sub_reg_to_A(this, &A);
        case 0x90:
            sub_reg_to_A(this, &B);
        case 0x91:
            sub_reg_to_A(this, &C);
        case 0x92:
            sub_reg_to_A(this, &D);
        case 0x93:
            sub_reg_to_A(this, &E);
        case 0x94:
            sub_reg_to_A(this, &H);
        case 0x95:
            sub_reg_to_A(this, &L);
        case 0x96:
            sub_reg_to_A(this, reinterpret_cast<const uint8_t *>(&memory[getHL()]));
        case 0xD6:
            NO_OP();
    }
}

void CPU::SBC_A_n() {
    PC += 0x1;
    switch (opcode) {
        case 0x9F:
            sub_carry_to_A(this, &A);
        case 0x98:
            sub_carry_to_A(this, &B);
        case 0x99:
            sub_carry_to_A(this, &C);
        case 0x9A:
            sub_carry_to_A(this, &D);
        case 0x9B:
            sub_carry_to_A(this, &E);
        case 0x9C:
            sub_carry_to_A(this, &H);
        case 0x9D:
            sub_carry_to_A(this, &L);
        case 0x9E:
            sub_carry_to_A(this, reinterpret_cast<const uint8_t *>(&memory[getHL()]));
    }
}

void CPU::AND_n() {
    PC += 0x1;
    switch (opcode) {
        case 0xA7:
            and_A(this, &A);
        case 0xA0:
            and_A(this, &B);
        case 0xA1:
            and_A(this, &C);
        case 0xA2:
            and_A(this, &D);
        case 0xA3:
            and_A(this, &E);
        case 0xA4:
            and_A(this, &H);
        case 0xA5:
            and_A(this, &L);
        case 0xA6:
            and_A(this, reinterpret_cast<const uint8_t *>(&memory[getHL()]));
        case 0xE6:
            NO_OP();
    }
}

void CPU::OR_n() {
    PC += 0x1;
    switch (opcode) {
        case 0xB7:
            or_A(this, &A);
        case 0xB0:
            or_A(this, &B);
        case 0xB1:
            or_A(this, &C);
        case 0xB2:
            or_A(this, &D);
        case 0xB3:
            or_A(this, &E);
        case 0xB4:
            or_A(this, &H);
        case 0xB5:
            or_A(this, &L);
        case 0xB6:
            or_A(this, reinterpret_cast<const uint8_t *>(&memory[getHL()]));
        case 0xF6:
            NO_OP();
    }
}

void CPU::XOR_n() {
    PC += 0x1;
    switch (opcode) {
        case 0xAF:
            xor_A(this, &A);
        case 0xA8:
            xor_A(this, &B);
        case 0xA9:
            xor_A(this, &C);
        case 0xAA:
            xor_A(this, &D);
        case 0xAB:
            xor_A(this, &E);
        case 0xAC:
            xor_A(this, &H);
        case 0xAD:
            xor_A(this, &L);
        case 0xAE:
            xor_A(this, reinterpret_cast<const uint8_t *>(&memory[getHL()]));
        case 0xEE:
            NO_OP();
    }
}

void CPU::CP_n() {
    PC += 0x1;
    switch (opcode) {
        case 0xBF:
            cp_A_n(this, &A);
        case 0xB8:
            cp_A_n(this, &B);
        case 0xB9:
            cp_A_n(this, &C);
        case 0xBA:
            cp_A_n(this, &D);
        case 0xBB:
            cp_A_n(this, &E);
        case 0xBC:
            cp_A_n(this, &H);
        case 0xBD:
            cp_A_n(this, &L);
        case 0xBE:
            cp_A_n(this, reinterpret_cast<const uint8_t *>(&memory[getHL()]));
        case 0xFE:
            NO_OP();
    }
}

void CPU::INC_n() {
    PC += 0x1;
    switch (opcode) {
        case 0x3C:
            inc_reg(this, &A);
        case 0x04:
            inc_reg(this, &B);
        case 0x0C:
            inc_reg(this, &C);
        case 0x14:
            inc_reg(this, &D);
        case 0x1C:
            inc_reg(this, &E);
        case 0x24:
            inc_reg(this, &H);
        case 0x2C:
            inc_reg(this, &L);
        case 0x34:
            memory[getHL()] += 0x1;
            if (memory[getHL()] == 0) set_F_Register(CPU::ZERO_FLAG_SET);
            set_F_Register(CPU::SUBTRACT_FLAG_RESET);
            // Set if carry from bit 3
            if ((memory[getHL()] & 0x0F) == 0x00) set_F_Register(CPU::HALF_CARRY_FLAG_SET);
    }
}

void CPU::DEC_n() {
    PC += 0x1;
    switch (opcode) {
        case 0x3D:
            dec_reg(this, &A);
        case 0x05:
            dec_reg(this, &B);
        case 0x0D:
            dec_reg(this, &C);
        case 0x15:
            dec_reg(this, &D);
        case 0x1D:
            dec_reg(this, &E);
        case 0x25:
            dec_reg(this, &H);
        case 0x2D:
            dec_reg(this, &L);
        case 0x35:
            memory[getHL()] -= 0x1;
            if (memory[getHL()] == 0) set_F_Register(CPU::ZERO_FLAG_SET);
            set_F_Register(CPU::SUBTRACT_FLAG_SET);
            // Set if carry from bit 3
            if ((memory[getHL()] & 0x0F) == 0x0F) set_F_Register(CPU::HALF_CARRY_FLAG_SET);
    }
}

void CPU::ADD_HL_n() {
    PC += 0x1;
    switch (opcode) {
        case 0x09:
            add_r2_to_r1_16(this, B, C);
        case 0x19:
            add_r2_to_r1_16(this, D, E);
        case 0x29:
            add_r2_to_r1_16(this, H, L);
        case 0x39:
            add_sp_to_hl(this);
    }
}

void CPU::ADD_SP_n() {
    add_n_to_SP(this);
}

void CPU::INC_nn() {
    PC += 0x1;
    switch (opcode) {
        case 0x03:
            inc_reg_16(this, &B, &C, getBC());
        case 0x13:
            inc_reg_16(this, &D, &E, getDE());
        case 0x23:
            inc_reg_16(this, &H, &L, getHL());
        case 0x33:
            SP += 0x1;
    }

}

void CPU::DEC_nn() {
    PC += 0x1;
    switch (opcode) {
        case 0x0B:
            dec_reg_16(this, &B, &C, getBC());
        case 0x1B:
            dec_reg_16(this, &D, &E, getDE());
        case 0x2B:
            dec_reg_16(this, &H, &L, getHL());
        case 0x3B:
            SP -= 0x1;
    }
}

void CPU::SWAP_n() {
    PC += 0x1;
    switch (opcode) {
        case 0x37:
            swap_reg_n(this, &A);
        case 0x30:
            swap_reg_n(this, &B);
        case 0x31:
            swap_reg_n(this, &C);
        case 0x32:
            swap_reg_n(this, &D);
        case 0x33:
            swap_reg_n(this, &E);
        case 0x34:
            swap_reg_n(this, &H);
        case 0x35:
            swap_reg_n(this, &L);
        case 0x36:
            uint8_t val = memory[getHL()];
            uint8_t lobits = (val & 0x0F);
            uint8_t hibits = (val & 0xF0);
            memory[getHL()] = (lobits << 4) | hibits;

            if (memory[getHL()] == 0x0) set_F_Register(CPU::ZERO_FLAG_SET);
            set_F_Register(CPU::SUBTRACT_FLAG_RESET);
            set_F_Register(CPU::HALF_CARRY_FLAG_RESET);
            set_F_Register(CPU::CARRY_FLAG_RESET);
    }
}

void CPU::DAA() {
    // Page 95
}

void CPU::CPL() {
    PC += 0x1;
    uint8_t reg = A;
    uint8_t res = ~reg;
    A = res;

    set_F_Register(SUBTRACT_FLAG_SET);
    set_F_Register(HALF_CARRY_FLAG_SET);
}

void CPU::CCF() {
    PC += 0x1;

    set_F_Register(SUBTRACT_FLAG_RESET);
    set_F_Register(HALF_CARRY_FLAG_RESET);

    int C_FLAG = (F << 3) >> 7;
    if (C_FLAG == 0) set_F_Register(CARRY_FLAG_SET);
    else set_F_Register(CARRY_FLAG_RESET);
}

void CPU::SCF() {
    PC += 0x1;

    set_F_Register(SUBTRACT_FLAG_RESET);
    set_F_Register(HALF_CARRY_FLAG_RESET);
    set_F_Register(CARRY_FLAG_SET);
}

void CPU::HALT() {
    PC += 0x1;
    halted = true;
}

void CPU::STOP() {
    NO_OP();
}

void CPU::DI() {
    PC += 0x1;
    interrupts_enabled = false;
}

void CPU::EI() {
    PC += 0x1;
    interrupts_enabled = true;
}

void CPU::RLCA() {
    PC += 0x1;

    bool last_bit_A = A >> 7;
    uint8_t res = (A << 1) | (A >> 7);
    A = res;

    if (res == 0x0) set_F_Register(ZERO_FLAG_SET);
    set_F_Register(SUBTRACT_FLAG_SET);
    set_F_Register(HALF_CARRY_FLAG_SET);
    if (last_bit_A) set_F_Register(CARRY_FLAG_SET);
    else set_F_Register(CARRY_FLAG_RESET);
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

