//
// Created by Lorenzo Ferrante on 08/03/21.
//
#include "CPU.h"

// Utils functions
void load_r2_into_r1(CPU* cpu, uint8_t* r1, const uint8_t r2) {
    cpu->PC += 0x1;
    *r1 = r2;
}

void load_mem_into_r1(CPU* cpu, uint8_t* r1) {
    cpu->PC += 0x1;
    *r1 = cpu->memory[cpu->getHL()];
}

void load_r1_into_mem(CPU* cpu, const uint8_t r1) {
    cpu->PC += 0x1;
    cpu->memory[cpu->getHL()] = r1;
}

void load_nn_into_16reg(CPU* cpu, uint8_t* r1, uint8_t* r2) {
    cpu->PC += 0x1;
    uint16_t nn = cpu->memory[cpu->PC];
    *r1 = nn >> 8;
    *r2 = ((nn << 8) >> 8);
    cpu->PC += 0x1;
}

void push_nn_onto_sp(CPU* cpu, const uint8_t* r1, const uint8_t* r2) {
    cpu->SP -= 0x1;
    cpu->memory[cpu->SP] = *r1;
    cpu->SP -= 0x1;
    cpu->memory[cpu->SP] = *r2;
}

void pop_from_sp_to_reg(CPU* cpu, uint8_t* r1, uint8_t* r2) {
    uint8_t lobyte = cpu->memory[cpu->SP];
    cpu->SP += 0x1;
    uint8_t hibyte = cpu->memory[cpu->SP];
    *r1 = lobyte;
    *r2 = hibyte;
}

uint16_t swap_bytes(const uint8_t byte) {
    uint8_t hibyte = (byte & 0xFF00) >> 8;
    uint8_t lobyte = (byte & 0xFF);
    return ((lobyte << 8) | hibyte);
}

void add_reg_to_A(CPU *cpu, const uint8_t* r) {
    uint8_t val = cpu->A;
    cpu->A += *r;
    uint8_t res = cpu->A;

    if (res == 0) cpu->set_F_Register(CPU::ZERO_FLAG_SET);
    cpu->set_F_Register(CPU::SUBTRACT_FLAG_RESET);

    // Set H if Carry is from bit 3
    bool bit3_A = ((val << 4) >> 7);
    bool bit3_R = ((*r << 4) >> 7);
    if (bit3_A and bit3_R) cpu->set_F_Register(CPU::HALF_CARRY_FLAG_SET);

    // Set H if Carry is from bit 7
    bool bit7_A = (val >> 7);
    bool bit7_R = (*r >> 7);
    if (bit7_A and bit7_R) cpu->set_F_Register(CPU::CARRY_FLAG_SET);
}

void add_carry_to_a(CPU* cpu, const uint8_t* r) {
    cpu->A += ((cpu->F << 3) >> 7);
    add_reg_to_A(cpu, r);
}

void sub_reg_to_A(CPU* cpu, const uint8_t* r) {
    uint8_t val = cpu->A;
    cpu->A -= *r;
    uint8_t res = cpu->A;

    if (res == 0) cpu->set_F_Register(CPU::ZERO_FLAG_SET);
    cpu->set_F_Register(CPU::SUBTRACT_FLAG_SET);

    if ((*r & 0xf) - (val & 0xf) < 0) cpu->set_F_Register(CPU::HALF_CARRY_FLAG_SET);

    if (*r < val) cpu->set_F_Register(CPU::CARRY_FLAG_SET);
}

void sub_carry_to_A(CPU* cpu, const uint8_t* r) {
    cpu->A -= ((cpu->F << 3) >> 7);
    sub_reg_to_A(cpu, r);
}

void and_A(CPU* cpu, const uint8_t* r) {
    cpu->A &= *r;
    uint8_t res = cpu->A;

    if (res == 0) cpu->set_F_Register(CPU::ZERO_FLAG_SET);
    cpu->set_F_Register(CPU::SUBTRACT_FLAG_RESET);
    cpu->set_F_Register(CPU::HALF_CARRY_FLAG_SET);
    cpu->set_F_Register(CPU::CARRY_FLAG_RESET);
}

void or_A(CPU* cpu, const uint8_t* r) {
    cpu->A |= *r;
    uint8_t res = cpu->A;

    if (res == 0) cpu->set_F_Register(CPU::ZERO_FLAG_SET);
    cpu->set_F_Register(CPU::SUBTRACT_FLAG_RESET);
    cpu->set_F_Register(CPU::HALF_CARRY_FLAG_RESET);
    cpu->set_F_Register(CPU::CARRY_FLAG_RESET);
}

void xor_A(CPU* cpu, const uint8_t* r) {
    cpu->A ^= *r;
    uint8_t res = cpu->A;

    if (res == 0) cpu->set_F_Register(CPU::ZERO_FLAG_SET);
    cpu->set_F_Register(CPU::SUBTRACT_FLAG_RESET);
    cpu->set_F_Register(CPU::HALF_CARRY_FLAG_RESET);
    cpu->set_F_Register(CPU::CARRY_FLAG_RESET);
}

void cp_A_n(CPU* cpu, const uint8_t* r) {
    uint8_t res = cpu->A - *r;

    if (res == 0) cpu->set_F_Register(CPU::ZERO_FLAG_SET);
    cpu->set_F_Register(CPU::SUBTRACT_FLAG_SET);
    if ((*r & 0xf) - (res & 0xf) < 0) cpu->set_F_Register(CPU::HALF_CARRY_FLAG_SET);
    if (cpu->A < *r) cpu->set_F_Register(CPU::CARRY_FLAG_RESET);
}

void inc_reg(CPU* cpu, uint8_t* r) {
    *r += 0x1;

    if (*r == 0) cpu->set_F_Register(CPU::ZERO_FLAG_SET);
    cpu->set_F_Register(CPU::SUBTRACT_FLAG_RESET);
    // Set if carry from bit 3
    if ((*r & 0x0F) == 0x00) cpu->set_F_Register(CPU::HALF_CARRY_FLAG_SET);
}

void dec_reg(CPU* cpu, uint8_t* r) {
    *r -= 0x1;

    if (*r == 0) cpu->set_F_Register(CPU::ZERO_FLAG_SET);
    cpu->set_F_Register(CPU::SUBTRACT_FLAG_SET);
    // Set if no borrow from bit 4
    if ((*r & 0x0F) == 0x0F) cpu->set_F_Register(CPU::HALF_CARRY_FLAG_SET);
}

void add_r2_to_r1_16(CPU* cpu, uint8_t r1, uint8_t r2) {
    uint16_t reg = cpu->getHL();
    uint16_t val = (r1 << 4) | r2;
    uint16_t res = reg + val;
    cpu->H = (res >> 8);
    cpu->L = (res << 8) >> 8;

    cpu->set_F_Register(CPU::SUBTRACT_FLAG_SET);
    if ((reg & 0xfff) + (val & 0xfff) > 0xfff) cpu->set_F_Register(CPU::HALF_CARRY_FLAG_SET);
    if ((res & 0x10000) != 0) cpu->set_F_Register(CPU::CARRY_FLAG_SET);
}

void add_sp_to_hl(CPU* cpu) {
    uint16_t val = cpu->getHL();
    uint16_t reg = cpu->SP;
    uint16_t res = val + reg;
    cpu->H = (res >> 8);
    cpu->L = (res << 8) >> 8;

    cpu->set_F_Register(CPU::SUBTRACT_FLAG_SET);
    if ((reg & 0xfff) + (val & 0xfff) > 0xfff) cpu->set_F_Register(CPU::HALF_CARRY_FLAG_SET);
    if ((res & 0x10000) != 0) cpu->set_F_Register(CPU::CARRY_FLAG_SET);
}

void add_n_to_SP(CPU *cpu) {
    cpu->PC += 0x1;
    uint8_t n = cpu->memory[cpu->PC];
    int res = cpu->SP + n;
    cpu->SP = res;

    cpu->set_F_Register(CPU::ZERO_FLAG_RESET);
    cpu->set_F_Register(CPU::SUBTRACT_FLAG_RESET);
    if (((cpu->SP ^ n ^ (res & 0xFFFF)) & 0x10) == 0x10) cpu->set_F_Register(CPU::HALF_CARRY_FLAG_SET);
    else cpu->set_F_Register(CPU::HALF_CARRY_FLAG_RESET);
    if (((cpu->SP ^ n ^ (res & 0xFFFF)) & 0x100) == 0x100) cpu->set_F_Register(CPU::CARRY_FLAG_SET);
    else cpu->set_F_Register(CPU::CARRY_FLAG_RESET);
    cpu->PC += 0x1;
}

void inc_reg_16(CPU* cpu, uint8_t* r1, uint8_t* r2, uint16_t r16) {
    uint16_t res = r16 + 0x1;
    uint8_t hibyte = (res >> 8);
    uint8_t lobyte = (res << 8) >> 8;
    *r1 = hibyte;
    *r2 = lobyte;
}

void dec_reg_16(CPU* cpu, uint8_t* r1, uint8_t* r2, uint16_t r16) {
    uint16_t res = r16 - 0x1;
    uint8_t hibyte = (res >> 8);
    uint8_t lobyte = (res << 8) >> 8;
    *r1 = hibyte;
    *r2 = lobyte;
}

void swap_reg_n(CPU* cpu, uint8_t* r) {
    uint8_t lobits = (*r & 0x0F);
    uint8_t hibits = (*r & 0xF0);
    *r = (lobits << 4) | hibits;

    if (*r == 0x0) cpu->set_F_Register(CPU::ZERO_FLAG_SET);
    cpu->set_F_Register(CPU::SUBTRACT_FLAG_RESET);
    cpu->set_F_Register(CPU::HALF_CARRY_FLAG_RESET);
    cpu->set_F_Register(CPU::CARRY_FLAG_RESET);
}