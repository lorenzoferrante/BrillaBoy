//
// Created by Lorenzo Ferrante on 08/03/21.
//

#include "CPU.h"

void CPU::setUpTable() {
    for (auto & i : table) {
        i = &CPU::NO_OP;
    }
    for (auto & i : table_CB) {
        i = &CPU::NO_OP;
    }
    table[0x06] = &CPU::LD_nn_n;
    table[0x0E] = &CPU::LD_nn_n;
    table[0x16] = &CPU::LD_nn_n;
    table[0x1E] = &CPU::LD_nn_n;
    table[0x26] = &CPU::LD_nn_n;
    table[0x2E] = &CPU::LD_nn_n;

    table[0x7F] = &CPU::LD_r1_r2;
    table[0x78] = &CPU::LD_r1_r2;
    table[0x79] = &CPU::LD_r1_r2;
    table[0x7A] = &CPU::LD_r1_r2;
    table[0x7B] = &CPU::LD_r1_r2;
    table[0x7C] = &CPU::LD_r1_r2;
    table[0x7D] = &CPU::LD_r1_r2;
    table[0x7E] = &CPU::LD_r1_r2;
    table[0x40] = &CPU::LD_r1_r2;
    table[0x41] = &CPU::LD_r1_r2;
    table[0x42] = &CPU::LD_r1_r2;
    table[0x43] = &CPU::LD_r1_r2;
    table[0x44] = &CPU::LD_r1_r2;
    table[0x45] = &CPU::LD_r1_r2;
    table[0x46] = &CPU::LD_r1_r2;
    table[0x47] = &CPU::LD_r1_r2;
    table[0x48] = &CPU::LD_r1_r2;
    table[0x49] = &CPU::LD_r1_r2;
    table[0x4A] = &CPU::LD_r1_r2;
    table[0x4B] = &CPU::LD_r1_r2;
    table[0x4C] = &CPU::LD_r1_r2;
    table[0x4D] = &CPU::LD_r1_r2;
    table[0x4E] = &CPU::LD_r1_r2;
    table[0x50] = &CPU::LD_r1_r2;
    table[0x51] = &CPU::LD_r1_r2;
    table[0x52] = &CPU::LD_r1_r2;
    table[0x53] = &CPU::LD_r1_r2;
    table[0x54] = &CPU::LD_r1_r2;
    table[0x55] = &CPU::LD_r1_r2;
    table[0x56] = &CPU::LD_r1_r2;
    table[0x58] = &CPU::LD_r1_r2;
    table[0x59] = &CPU::LD_r1_r2;
    table[0x5A] = &CPU::LD_r1_r2;
    table[0x5B] = &CPU::LD_r1_r2;
    table[0x5C] = &CPU::LD_r1_r2;
    table[0x5D] = &CPU::LD_r1_r2;
    table[0x5E] = &CPU::LD_r1_r2;
    table[0x60] = &CPU::LD_r1_r2;
    table[0x61] = &CPU::LD_r1_r2;
    table[0x62] = &CPU::LD_r1_r2;
    table[0x63] = &CPU::LD_r1_r2;
    table[0x64] = &CPU::LD_r1_r2;
    table[0x65] = &CPU::LD_r1_r2;
    table[0x66] = &CPU::LD_r1_r2;
    table[0x68] = &CPU::LD_r1_r2;
    table[0x69] = &CPU::LD_r1_r2;
    table[0x6A] = &CPU::LD_r1_r2;
    table[0x6B] = &CPU::LD_r1_r2;
    table[0x6C] = &CPU::LD_r1_r2;
    table[0x6D] = &CPU::LD_r1_r2;
    table[0x6E] = &CPU::LD_r1_r2;
    table[0x70] = &CPU::LD_r1_r2;
    table[0x71] = &CPU::LD_r1_r2;
    table[0x72] = &CPU::LD_r1_r2;
    table[0x73] = &CPU::LD_r1_r2;
    table[0x74] = &CPU::LD_r1_r2;
    table[0x75] = &CPU::LD_r1_r2;
    table[0x36] = &CPU::LD_r1_r2;

    table[0x7F] = &CPU::LD_A_n;
    table[0x78] = &CPU::LD_A_n;
    table[0x79] = &CPU::LD_A_n;
    table[0x7A] = &CPU::LD_A_n;
    table[0x7B] = &CPU::LD_A_n;
    table[0x7C] = &CPU::LD_A_n;
    table[0x7D] = &CPU::LD_A_n;
    table[0x0A] = &CPU::LD_A_n;
    table[0x1A] = &CPU::LD_A_n;
    table[0x7E] = &CPU::LD_A_n;
    table[0xFA] = &CPU::LD_A_n;
    table[0x35] = &CPU::LD_A_n;

    table[0x7F] = &CPU::LD_n_A;
    table[0x47] = &CPU::LD_n_A;
    table[0x4F] = &CPU::LD_n_A;
    table[0x57] = &CPU::LD_n_A;
    table[0x5F] = &CPU::LD_n_A;
    table[0x67] = &CPU::LD_n_A;
    table[0x6F] = &CPU::LD_n_A;
    table[0x02] = &CPU::LD_n_A;
    table[0x12] = &CPU::LD_n_A;
    table[0x77] = &CPU::LD_n_A;
    table[0xEA] = &CPU::LD_n_A;

    table[0xF2] = &CPU::LD_A_addr_C;
    table[0xE2] = &CPU::LD_addr_C_A;
    table[0x3A] = &CPU::LD_A_HL_dec;
    table[0x32] = &CPU::LD_HL_dec_A;
    table[0x2A] = &CPU::LD_A_HL_inc;
    table[0x22] = &CPU::LD_HL_inc_A;
    table[0xE0] = &CPU::LDH_addr_n_A;
    table[0xF0] = &CPU::LDH_A_addr_n;

    table[0x01] = &CPU::LD_n_nn;
    table[0x11] = &CPU::LD_n_nn;
    table[0x21] = &CPU::LD_n_nn;
    table[0x31] = &CPU::LD_n_nn;

    table[0xF9] = &CPU::LD_SP_HL;
    table[0xF8] = &CPU::LDHL_SP_n;
    table[0x08] = &CPU::LD_addr_nn_SP;

    table[0xF5] = &CPU::PUSH_nn;
    table[0xC5] = &CPU::PUSH_nn;
    table[0xD5] = &CPU::PUSH_nn;
    table[0xE5] = &CPU::PUSH_nn;

    table[0xF1] = &CPU::POP_nn;
    table[0xC1] = &CPU::POP_nn;
    table[0xD1] = &CPU::POP_nn;
    table[0xE1] = &CPU::POP_nn;

    table[0x87] = &CPU::ADD_A_n;
    table[0x80] = &CPU::ADD_A_n;
    table[0x81] = &CPU::ADD_A_n;
    table[0x82] = &CPU::ADD_A_n;
    table[0x83] = &CPU::ADD_A_n;
    table[0x84] = &CPU::ADD_A_n;
    table[0x85] = &CPU::ADD_A_n;
    table[0x86] = &CPU::ADD_A_n;
    table[0xC6] = &CPU::ADD_A_n;

    table[0x8F] = &CPU::ADC_A_n;
    table[0x88] = &CPU::ADC_A_n;
    table[0x89] = &CPU::ADC_A_n;
    table[0x8A] = &CPU::ADC_A_n;
    table[0x8B] = &CPU::ADC_A_n;
    table[0x8C] = &CPU::ADC_A_n;
    table[0x8D] = &CPU::ADC_A_n;
    table[0x8E] = &CPU::ADC_A_n;
    table[0xCE] = &CPU::ADC_A_n;

    table[0x97] = &CPU::SUB_n;
    table[0x90] = &CPU::SUB_n;
    table[0x91] = &CPU::SUB_n;
    table[0x92] = &CPU::SUB_n;
    table[0x93] = &CPU::SUB_n;
    table[0x94] = &CPU::SUB_n;
    table[0x95] = &CPU::SUB_n;
    table[0x96] = &CPU::SUB_n;
    table[0xD6] = &CPU::SUB_n;

    table[0x9F] = &CPU::SBC_A_n;
    table[0x98] = &CPU::SBC_A_n;
    table[0x99] = &CPU::SBC_A_n;
    table[0x9A] = &CPU::SBC_A_n;
    table[0x9B] = &CPU::SBC_A_n;
    table[0x9C] = &CPU::SBC_A_n;
    table[0x9D] = &CPU::SBC_A_n;
    table[0x9E] = &CPU::SBC_A_n;

    table[0xA7] = &CPU::AND_n;
    table[0xA0] = &CPU::AND_n;
    table[0xA1] = &CPU::AND_n;
    table[0xA2] = &CPU::AND_n;
    table[0xA3] = &CPU::AND_n;
    table[0xA4] = &CPU::AND_n;
    table[0xA5] = &CPU::AND_n;
    table[0xA6] = &CPU::AND_n;
    table[0xE6] = &CPU::AND_n;

    table[0xB7] = &CPU::OR_n;
    table[0xB0] = &CPU::OR_n;
    table[0xB1] = &CPU::OR_n;
    table[0xB2] = &CPU::OR_n;
    table[0xB3] = &CPU::OR_n;
    table[0xB4] = &CPU::OR_n;
    table[0xB5] = &CPU::OR_n;
    table[0xB6] = &CPU::OR_n;
    table[0xF6] = &CPU::OR_n;

    table[0xAF] = &CPU::XOR_n;
    table[0xA8] = &CPU::XOR_n;
    table[0xA9] = &CPU::XOR_n;
    table[0xAA] = &CPU::XOR_n;
    table[0xAB] = &CPU::XOR_n;
    table[0xAC] = &CPU::XOR_n;
    table[0xAD] = &CPU::XOR_n;
    table[0xAE] = &CPU::XOR_n;
    table[0xEE] = &CPU::XOR_n;

    table[0xBF] = &CPU::CP_n;
    table[0xB8] = &CPU::CP_n;
    table[0xB9] = &CPU::CP_n;
    table[0xBA] = &CPU::CP_n;
    table[0xBB] = &CPU::CP_n;
    table[0xBC] = &CPU::CP_n;
    table[0xBD] = &CPU::CP_n;
    table[0xBE] = &CPU::CP_n;
    table[0xFE] = &CPU::CP_n;

    table[0x3C] = &CPU::INC_n;
    table[0x04] = &CPU::INC_n;
    table[0x0C] = &CPU::INC_n;
    table[0x14] = &CPU::INC_n;
    table[0x1C] = &CPU::INC_n;
    table[0x24] = &CPU::INC_n;
    table[0x2C] = &CPU::INC_n;
    table[0x34] = &CPU::INC_n;

    table[0x3D] = &CPU::DEC_n;
    table[0x05] = &CPU::DEC_n;
    table[0x0D] = &CPU::DEC_n;
    table[0x15] = &CPU::DEC_n;
    table[0x1D] = &CPU::DEC_n;
    table[0x25] = &CPU::DEC_n;
    table[0x2D] = &CPU::DEC_n;
    table[0x35] = &CPU::DEC_n;

    table[0x90] = &CPU::ADD_HL_n;
    table[0x19] = &CPU::ADD_HL_n;
    table[0x29] = &CPU::ADD_HL_n;
    table[0x39] = &CPU::ADD_HL_n;

    table[0xE8] = &CPU::ADD_SP_n;

    table[0x03] = &CPU::INC_nn;
    table[0x13] = &CPU::INC_nn;
    table[0x23] = &CPU::INC_nn;
    table[0x33] = &CPU::INC_nn;

    table[0x0B] = &CPU::DEC_nn;
    table[0x1B] = &CPU::DEC_nn;
    table[0x2B] = &CPU::DEC_nn;
    table[0x38] = &CPU::DEC_nn;

    table[0x27] = &CPU::DAA;
    table[0x2F] = &CPU::CPL;
    table[0x3F] = &CPU::CCF;
    table[0x37] = &CPU::SCF;
    table[0x00] = &CPU::NO_OP;
    table[0x76] = &CPU::HALT;
    // 0X1000 => &CPU::STOP; NOT IMPLEMENTED YET!
    table[0xF3] = &CPU::DI;
    table[0xFB] = &CPU::EI;

    table[0x07] = &CPU::RLCA;
    table[0x17] = &CPU::RLA;
    table[0x0F] = &CPU::RRCA;
    table[0x1F] = &CPU::RRA;

    // JUMPS
    table[0xC3] = &CPU::JP_nn;
    table[0x18] = &CPU::JR_n;

    table[0x20] = &CPU::JR_cc_n;
    table[0x28] = &CPU::JR_cc_n;
    table[0x30] = &CPU::JR_cc_n;
    table[0x28] = &CPU::JR_cc_n;

    table[0xC2] = &CPU::JP_cc_nn;
    table[0xCA] = &CPU::JP_cc_nn;
    table[0xD2] = &CPU::JP_cc_nn;
    table[0xDA] = &CPU::JP_cc_nn;

    // CALLS
    table[0xCD] = &CPU::CALL_nn;
    table[0xC4] = &CPU::CALL_cc_nn;
    table[0xCC] = &CPU::CALL_cc_nn;
    table[0xD4] = &CPU::CALL_cc_nn;
    table[0xDC] = &CPU::CALL_cc_nn;

    // RESTARTS
    table[0xC7] = &CPU::RST_n;
    table[0xCF] = &CPU::RST_n;
    table[0xD7] = &CPU::RST_n;
    table[0xDF] = &CPU::RST_n;
    table[0xE7] = &CPU::RST_n;
    table[0xEF] = &CPU::RST_n;
    table[0xF7] = &CPU::RST_n;
    table[0xFF] = &CPU::RST_n;

    // RETURNS
    table[0xC9] = &CPU::RET;
    table[0xD9] = &CPU::RETI;

    table[0xC0] = &CPU::RET_cc;
    table[0xC8] = &CPU::RET_cc;
    table[0xD0] = &CPU::RET_cc;
    table[0xD8] = &CPU::RET_cc;

    // CB Prefix
    table_CB[0x37] = &CPU::SWAP_n;
    table_CB[0x30] = &CPU::SWAP_n;
    table_CB[0x31] = &CPU::SWAP_n;
    table_CB[0x32] = &CPU::SWAP_n;
    table_CB[0x33] = &CPU::SWAP_n;
    table_CB[0x34] = &CPU::SWAP_n;
    table_CB[0x35] = &CPU::SWAP_n;
    table_CB[0x36] = &CPU::SWAP_n;

    table_CB[0x07] = &CPU::RLC_n;
    table_CB[0x00] = &CPU::RLC_n;
    table_CB[0x01] = &CPU::RLC_n;
    table_CB[0x02] = &CPU::RLC_n;
    table_CB[0x03] = &CPU::RLC_n;
    table_CB[0x04] = &CPU::RLC_n;
    table_CB[0x05] = &CPU::RLC_n;
    table_CB[0x06] = &CPU::RLC_n;

    table_CB[0x17] = &CPU::RL_n;
    table_CB[0x10] = &CPU::RL_n;
    table_CB[0x11] = &CPU::RL_n;
    table_CB[0x12] = &CPU::RL_n;
    table_CB[0x13] = &CPU::RL_n;
    table_CB[0x14] = &CPU::RL_n;
    table_CB[0x15] = &CPU::RL_n;
    table_CB[0x16] = &CPU::RL_n;

    table_CB[0x0F] = &CPU::RRC_n;
    table_CB[0x08] = &CPU::RRC_n;
    table_CB[0x09] = &CPU::RRC_n;
    table_CB[0x0A] = &CPU::RRC_n;
    table_CB[0x0B] = &CPU::RRC_n;
    table_CB[0x0C] = &CPU::RRC_n;
    table_CB[0x0D] = &CPU::RRC_n;
    table_CB[0x0E] = &CPU::RRC_n;

    table_CB[0x1F] = &CPU::RR_n;
    table_CB[0x18] = &CPU::RR_n;
    table_CB[0x19] = &CPU::RR_n;
    table_CB[0x1A] = &CPU::RR_n;
    table_CB[0x1B] = &CPU::RR_n;
    table_CB[0x1C] = &CPU::RR_n;
    table_CB[0x1D] = &CPU::RR_n;
    table_CB[0x1E] = &CPU::RR_n;

    table_CB[0x27] = &CPU::SLA_n;
    table_CB[0x20] = &CPU::SLA_n;
    table_CB[0x21] = &CPU::SLA_n;
    table_CB[0x22] = &CPU::SLA_n;
    table_CB[0x23] = &CPU::SLA_n;
    table_CB[0x24] = &CPU::SLA_n;
    table_CB[0x25] = &CPU::SLA_n;
    table_CB[0x26] = &CPU::SLA_n;

    table_CB[0x2F] = &CPU::SRA_n;
    table_CB[0x28] = &CPU::SRA_n;
    table_CB[0x29] = &CPU::SRA_n;
    table_CB[0x2A] = &CPU::SRA_n;
    table_CB[0x2B] = &CPU::SRA_n;
    table_CB[0x2C] = &CPU::SRA_n;
    table_CB[0x2D] = &CPU::SRA_n;
    table_CB[0x2E] = &CPU::SRA_n;

    table_CB[0x3F] = &CPU::SRL_n;
    table_CB[0x38] = &CPU::SRL_n;
    table_CB[0x39] = &CPU::SRL_n;
    table_CB[0x3A] = &CPU::SRL_n;
    table_CB[0x3B] = &CPU::SRL_n;
    table_CB[0x3C] = &CPU::SRL_n;
    table_CB[0x3D] = &CPU::SRL_n;
    table_CB[0X3E] = &CPU::SRL_n;

    table_CB[0x47] = &CPU::BIT_b_r;
    table_CB[0x40] = &CPU::BIT_b_r;
    table_CB[0x41] = &CPU::BIT_b_r;
    table_CB[0x42] = &CPU::BIT_b_r;
    table_CB[0x43] = &CPU::BIT_b_r;
    table_CB[0x44] = &CPU::BIT_b_r;
    table_CB[0x45] = &CPU::BIT_b_r;
    table_CB[0x46] = &CPU::BIT_b_r;

    table_CB[0xC7] = &CPU::SET_b_r;
    table_CB[0xC0] = &CPU::SET_b_r;
    table_CB[0xC1] = &CPU::SET_b_r;
    table_CB[0xC2] = &CPU::SET_b_r;
    table_CB[0xC3] = &CPU::SET_b_r;
    table_CB[0xC4] = &CPU::SET_b_r;
    table_CB[0xC5] = &CPU::SET_b_r;
    table_CB[0xC6] = &CPU::SET_b_r;

    table_CB[0x87] = &CPU::RES_b_r;
    table_CB[0x80] = &CPU::RES_b_r;
    table_CB[0x81] = &CPU::RES_b_r;
    table_CB[0x82] = &CPU::RES_b_r;
    table_CB[0x83] = &CPU::RES_b_r;
    table_CB[0x84] = &CPU::RES_b_r;
    table_CB[0x85] = &CPU::RES_b_r;
    table_CB[0x86] = &CPU::RES_b_r;
}


