// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2019.1
// Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

#include "combinar.h"
#include "AESL_pkg.h"

using namespace std;

namespace ap_rtl {

const sc_logic combinar::ap_const_logic_1 = sc_dt::Log_1;
const sc_logic combinar::ap_const_logic_0 = sc_dt::Log_0;
const sc_lv<4> combinar::ap_ST_fsm_state1 = "1";
const sc_lv<4> combinar::ap_ST_fsm_pp0_stage0 = "10";
const sc_lv<4> combinar::ap_ST_fsm_pp0_stage1 = "100";
const sc_lv<4> combinar::ap_ST_fsm_state5 = "1000";
const sc_lv<32> combinar::ap_const_lv32_0 = "00000000000000000000000000000000";
const bool combinar::ap_const_boolean_1 = true;
const sc_lv<32> combinar::ap_const_lv32_2 = "10";
const bool combinar::ap_const_boolean_0 = false;
const sc_lv<1> combinar::ap_const_lv1_1 = "1";
const sc_lv<1> combinar::ap_const_lv1_0 = "0";
const sc_lv<32> combinar::ap_const_lv32_1 = "1";
const sc_lv<32> combinar::ap_const_lv32_3 = "11";
const sc_lv<11> combinar::ap_const_lv11_0 = "00000000000";

combinar::combinar(sc_module_name name) : sc_module(name), mVcdFile(0) {

    SC_METHOD(thread_ap_clk_no_reset_);
    dont_initialize();
    sensitive << ( ap_clk.pos() );

    SC_METHOD(thread_and_ln109_fu_122_p2);
    sensitive << ( end_0_2_i_fu_40 );
    sensitive << ( end_1_2_i_fu_44 );

    SC_METHOD(thread_ap_CS_fsm_pp0_stage0);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_CS_fsm_pp0_stage1);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_CS_fsm_state1);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_CS_fsm_state5);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_block_pp0_stage0);

    SC_METHOD(thread_ap_block_pp0_stage0_01001);
    sensitive << ( result_V_V_full_n );
    sensitive << ( ap_enable_reg_pp0_iter1 );
    sensitive << ( ap_predicate_op38_write_state4 );

    SC_METHOD(thread_ap_block_pp0_stage0_11001);
    sensitive << ( result_V_V_full_n );
    sensitive << ( ap_enable_reg_pp0_iter1 );
    sensitive << ( ap_predicate_op38_write_state4 );

    SC_METHOD(thread_ap_block_pp0_stage0_subdone);
    sensitive << ( result_V_V_full_n );
    sensitive << ( ap_enable_reg_pp0_iter1 );
    sensitive << ( ap_predicate_op38_write_state4 );

    SC_METHOD(thread_ap_block_pp0_stage1);

    SC_METHOD(thread_ap_block_pp0_stage1_01001);
    sensitive << ( result_V_V_full_n );
    sensitive << ( ap_enable_reg_pp0_iter0 );
    sensitive << ( ap_predicate_op29_write_state3 );

    SC_METHOD(thread_ap_block_pp0_stage1_11001);
    sensitive << ( result_V_V_full_n );
    sensitive << ( ap_enable_reg_pp0_iter0 );
    sensitive << ( ap_predicate_op29_write_state3 );

    SC_METHOD(thread_ap_block_pp0_stage1_subdone);
    sensitive << ( result_V_V_full_n );
    sensitive << ( ap_enable_reg_pp0_iter0 );
    sensitive << ( ap_predicate_op29_write_state3 );

    SC_METHOD(thread_ap_block_state1);
    sensitive << ( ap_start );
    sensitive << ( ap_done_reg );

    SC_METHOD(thread_ap_block_state2_pp0_stage0_iter0);

    SC_METHOD(thread_ap_block_state3_pp0_stage1_iter0);
    sensitive << ( result_V_V_full_n );
    sensitive << ( ap_predicate_op29_write_state3 );

    SC_METHOD(thread_ap_block_state4_pp0_stage0_iter1);
    sensitive << ( result_V_V_full_n );
    sensitive << ( ap_predicate_op38_write_state4 );

    SC_METHOD(thread_ap_done);
    sensitive << ( ap_done_reg );
    sensitive << ( result_V_V_full_n );
    sensitive << ( ap_CS_fsm_state5 );

    SC_METHOD(thread_ap_enable_pp0);
    sensitive << ( ap_idle_pp0 );

    SC_METHOD(thread_ap_idle);
    sensitive << ( ap_start );
    sensitive << ( ap_CS_fsm_state1 );

    SC_METHOD(thread_ap_idle_pp0);
    sensitive << ( ap_enable_reg_pp0_iter0 );
    sensitive << ( ap_enable_reg_pp0_iter1 );

    SC_METHOD(thread_ap_predicate_op29_write_state3);
    sensitive << ( empty_n_reg_142 );
    sensitive << ( icmp_ln879_reg_160 );

    SC_METHOD(thread_ap_predicate_op38_write_state4);
    sensitive << ( empty_n_1_reg_151 );
    sensitive << ( icmp_ln879_1_reg_164 );

    SC_METHOD(thread_ap_ready);
    sensitive << ( result_V_V_full_n );
    sensitive << ( ap_CS_fsm_state5 );

    SC_METHOD(thread_empty_n_1_fu_86_p1);
    sensitive << ( in2_V_V_read_nbread_fu_54_p2_0 );

    SC_METHOD(thread_empty_n_fu_78_p1);
    sensitive << ( in1_V_V_read_nbread_fu_48_p2_0 );

    SC_METHOD(thread_icmp_ln879_1_fu_105_p2);
    sensitive << ( in2_V_V_dout );
    sensitive << ( ap_enable_reg_pp0_iter0 );
    sensitive << ( ap_CS_fsm_pp0_stage0 );
    sensitive << ( ap_block_pp0_stage0_11001 );
    sensitive << ( empty_n_1_fu_86_p1 );

    SC_METHOD(thread_icmp_ln879_fu_94_p2);
    sensitive << ( in1_V_V_dout );
    sensitive << ( ap_enable_reg_pp0_iter0 );
    sensitive << ( ap_CS_fsm_pp0_stage0 );
    sensitive << ( empty_n_fu_78_p1 );
    sensitive << ( ap_block_pp0_stage0_11001 );

    SC_METHOD(thread_in1_V_V_read);
    sensitive << ( in1_V_V_empty_n );
    sensitive << ( ap_enable_reg_pp0_iter0 );
    sensitive << ( ap_CS_fsm_pp0_stage0 );
    sensitive << ( ap_block_pp0_stage0_11001 );

    SC_METHOD(thread_in1_V_V_read_nbread_fu_48_p2_0);
    sensitive << ( in1_V_V_empty_n );

    SC_METHOD(thread_in2_V_V_read);
    sensitive << ( in2_V_V_empty_n );
    sensitive << ( ap_enable_reg_pp0_iter0 );
    sensitive << ( ap_CS_fsm_pp0_stage0 );
    sensitive << ( ap_block_pp0_stage0_11001 );

    SC_METHOD(thread_in2_V_V_read_nbread_fu_54_p2_0);
    sensitive << ( in2_V_V_empty_n );

    SC_METHOD(thread_result_V_V_blk_n);
    sensitive << ( result_V_V_full_n );
    sensitive << ( ap_CS_fsm_pp0_stage1 );
    sensitive << ( ap_enable_reg_pp0_iter0 );
    sensitive << ( ap_block_pp0_stage1 );
    sensitive << ( empty_n_reg_142 );
    sensitive << ( icmp_ln879_reg_160 );
    sensitive << ( ap_CS_fsm_pp0_stage0 );
    sensitive << ( ap_enable_reg_pp0_iter1 );
    sensitive << ( ap_block_pp0_stage0 );
    sensitive << ( empty_n_1_reg_151 );
    sensitive << ( icmp_ln879_1_reg_164 );
    sensitive << ( ap_CS_fsm_state5 );

    SC_METHOD(thread_result_V_V_din);
    sensitive << ( result_V_V_full_n );
    sensitive << ( ap_CS_fsm_pp0_stage1 );
    sensitive << ( ap_enable_reg_pp0_iter0 );
    sensitive << ( ap_CS_fsm_pp0_stage0 );
    sensitive << ( ap_enable_reg_pp0_iter1 );
    sensitive << ( ap_CS_fsm_state5 );
    sensitive << ( ap_predicate_op38_write_state4 );
    sensitive << ( tmp_V_reg_146 );
    sensitive << ( tmp_V_1_reg_155 );
    sensitive << ( ap_predicate_op29_write_state3 );
    sensitive << ( ap_block_pp0_stage1_01001 );
    sensitive << ( ap_block_pp0_stage0_01001 );

    SC_METHOD(thread_result_V_V_write);
    sensitive << ( result_V_V_full_n );
    sensitive << ( ap_CS_fsm_pp0_stage1 );
    sensitive << ( ap_enable_reg_pp0_iter0 );
    sensitive << ( ap_CS_fsm_pp0_stage0 );
    sensitive << ( ap_enable_reg_pp0_iter1 );
    sensitive << ( ap_CS_fsm_state5 );
    sensitive << ( ap_predicate_op38_write_state4 );
    sensitive << ( ap_block_pp0_stage0_11001 );
    sensitive << ( ap_predicate_op29_write_state3 );
    sensitive << ( ap_block_pp0_stage1_11001 );

    SC_METHOD(thread_ap_NS_fsm);
    sensitive << ( ap_start );
    sensitive << ( ap_done_reg );
    sensitive << ( ap_CS_fsm );
    sensitive << ( ap_CS_fsm_state1 );
    sensitive << ( result_V_V_full_n );
    sensitive << ( ap_enable_reg_pp0_iter0 );
    sensitive << ( ap_CS_fsm_pp0_stage0 );
    sensitive << ( ap_enable_reg_pp0_iter1 );
    sensitive << ( ap_CS_fsm_state5 );
    sensitive << ( ap_block_pp0_stage1_subdone );
    sensitive << ( ap_block_pp0_stage0_subdone );

    ap_done_reg = SC_LOGIC_0;
    ap_CS_fsm = "0001";
    ap_enable_reg_pp0_iter0 = SC_LOGIC_0;
    ap_enable_reg_pp0_iter1 = SC_LOGIC_0;
    static int apTFileNum = 0;
    stringstream apTFilenSS;
    apTFilenSS << "combinar_sc_trace_" << apTFileNum ++;
    string apTFn = apTFilenSS.str();
    mVcdFile = sc_create_vcd_trace_file(apTFn.c_str());
    mVcdFile->set_time_unit(1, SC_PS);
    if (1) {
#ifdef __HLS_TRACE_LEVEL_PORT_HIER__
    sc_trace(mVcdFile, ap_clk, "(port)ap_clk");
    sc_trace(mVcdFile, ap_rst, "(port)ap_rst");
    sc_trace(mVcdFile, ap_start, "(port)ap_start");
    sc_trace(mVcdFile, ap_done, "(port)ap_done");
    sc_trace(mVcdFile, ap_continue, "(port)ap_continue");
    sc_trace(mVcdFile, ap_idle, "(port)ap_idle");
    sc_trace(mVcdFile, ap_ready, "(port)ap_ready");
    sc_trace(mVcdFile, result_V_V_din, "(port)result_V_V_din");
    sc_trace(mVcdFile, result_V_V_full_n, "(port)result_V_V_full_n");
    sc_trace(mVcdFile, result_V_V_write, "(port)result_V_V_write");
    sc_trace(mVcdFile, in1_V_V_dout, "(port)in1_V_V_dout");
    sc_trace(mVcdFile, in1_V_V_empty_n, "(port)in1_V_V_empty_n");
    sc_trace(mVcdFile, in1_V_V_read, "(port)in1_V_V_read");
    sc_trace(mVcdFile, in2_V_V_dout, "(port)in2_V_V_dout");
    sc_trace(mVcdFile, in2_V_V_empty_n, "(port)in2_V_V_empty_n");
    sc_trace(mVcdFile, in2_V_V_read, "(port)in2_V_V_read");
#endif
#ifdef __HLS_TRACE_LEVEL_INT__
    sc_trace(mVcdFile, ap_done_reg, "ap_done_reg");
    sc_trace(mVcdFile, ap_CS_fsm, "ap_CS_fsm");
    sc_trace(mVcdFile, ap_CS_fsm_state1, "ap_CS_fsm_state1");
    sc_trace(mVcdFile, result_V_V_blk_n, "result_V_V_blk_n");
    sc_trace(mVcdFile, ap_CS_fsm_pp0_stage1, "ap_CS_fsm_pp0_stage1");
    sc_trace(mVcdFile, ap_enable_reg_pp0_iter0, "ap_enable_reg_pp0_iter0");
    sc_trace(mVcdFile, ap_block_pp0_stage1, "ap_block_pp0_stage1");
    sc_trace(mVcdFile, empty_n_reg_142, "empty_n_reg_142");
    sc_trace(mVcdFile, icmp_ln879_reg_160, "icmp_ln879_reg_160");
    sc_trace(mVcdFile, ap_CS_fsm_pp0_stage0, "ap_CS_fsm_pp0_stage0");
    sc_trace(mVcdFile, ap_enable_reg_pp0_iter1, "ap_enable_reg_pp0_iter1");
    sc_trace(mVcdFile, ap_block_pp0_stage0, "ap_block_pp0_stage0");
    sc_trace(mVcdFile, empty_n_1_reg_151, "empty_n_1_reg_151");
    sc_trace(mVcdFile, icmp_ln879_1_reg_164, "icmp_ln879_1_reg_164");
    sc_trace(mVcdFile, ap_CS_fsm_state5, "ap_CS_fsm_state5");
    sc_trace(mVcdFile, empty_n_fu_78_p1, "empty_n_fu_78_p1");
    sc_trace(mVcdFile, ap_block_state2_pp0_stage0_iter0, "ap_block_state2_pp0_stage0_iter0");
    sc_trace(mVcdFile, ap_predicate_op38_write_state4, "ap_predicate_op38_write_state4");
    sc_trace(mVcdFile, ap_block_state4_pp0_stage0_iter1, "ap_block_state4_pp0_stage0_iter1");
    sc_trace(mVcdFile, ap_block_pp0_stage0_11001, "ap_block_pp0_stage0_11001");
    sc_trace(mVcdFile, tmp_V_reg_146, "tmp_V_reg_146");
    sc_trace(mVcdFile, empty_n_1_fu_86_p1, "empty_n_1_fu_86_p1");
    sc_trace(mVcdFile, tmp_V_1_reg_155, "tmp_V_1_reg_155");
    sc_trace(mVcdFile, icmp_ln879_fu_94_p2, "icmp_ln879_fu_94_p2");
    sc_trace(mVcdFile, icmp_ln879_1_fu_105_p2, "icmp_ln879_1_fu_105_p2");
    sc_trace(mVcdFile, and_ln109_fu_122_p2, "and_ln109_fu_122_p2");
    sc_trace(mVcdFile, ap_predicate_op29_write_state3, "ap_predicate_op29_write_state3");
    sc_trace(mVcdFile, ap_block_state3_pp0_stage1_iter0, "ap_block_state3_pp0_stage1_iter0");
    sc_trace(mVcdFile, ap_block_pp0_stage1_11001, "ap_block_pp0_stage1_11001");
    sc_trace(mVcdFile, ap_block_state1, "ap_block_state1");
    sc_trace(mVcdFile, ap_block_pp0_stage1_subdone, "ap_block_pp0_stage1_subdone");
    sc_trace(mVcdFile, ap_block_pp0_stage0_subdone, "ap_block_pp0_stage0_subdone");
    sc_trace(mVcdFile, end_0_2_i_fu_40, "end_0_2_i_fu_40");
    sc_trace(mVcdFile, end_1_2_i_fu_44, "end_1_2_i_fu_44");
    sc_trace(mVcdFile, in1_V_V_read_nbread_fu_48_p2_0, "in1_V_V_read_nbread_fu_48_p2_0");
    sc_trace(mVcdFile, in2_V_V_read_nbread_fu_54_p2_0, "in2_V_V_read_nbread_fu_54_p2_0");
    sc_trace(mVcdFile, ap_block_pp0_stage1_01001, "ap_block_pp0_stage1_01001");
    sc_trace(mVcdFile, ap_block_pp0_stage0_01001, "ap_block_pp0_stage0_01001");
    sc_trace(mVcdFile, ap_NS_fsm, "ap_NS_fsm");
    sc_trace(mVcdFile, ap_idle_pp0, "ap_idle_pp0");
    sc_trace(mVcdFile, ap_enable_pp0, "ap_enable_pp0");
#endif

    }
}

combinar::~combinar() {
    if (mVcdFile) 
        sc_close_vcd_trace_file(mVcdFile);

}

void combinar::thread_ap_clk_no_reset_() {
    if ( ap_rst.read() == ap_const_logic_1) {
        ap_CS_fsm = ap_ST_fsm_state1;
    } else {
        ap_CS_fsm = ap_NS_fsm.read();
    }
    if ( ap_rst.read() == ap_const_logic_1) {
        ap_done_reg = ap_const_logic_0;
    } else {
        if (esl_seteq<1,1,1>(ap_const_logic_1, ap_continue.read())) {
            ap_done_reg = ap_const_logic_0;
        } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state5.read()) && 
                    esl_seteq<1,1,1>(result_V_V_full_n.read(), ap_const_logic_1))) {
            ap_done_reg = ap_const_logic_1;
        }
    }
    if ( ap_rst.read() == ap_const_logic_1) {
        ap_enable_reg_pp0_iter0 = ap_const_logic_0;
    } else {
        if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage1.read()) && 
             esl_seteq<1,1,1>(ap_block_pp0_stage1_subdone.read(), ap_const_boolean_0) && 
             esl_seteq<1,1,1>(ap_const_lv1_1, and_ln109_fu_122_p2.read()))) {
            ap_enable_reg_pp0_iter0 = ap_const_logic_0;
        } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()) && 
                    !(esl_seteq<1,1,1>(ap_const_logic_0, ap_start.read()) || esl_seteq<1,1,1>(ap_done_reg.read(), ap_const_logic_1)))) {
            ap_enable_reg_pp0_iter0 = ap_const_logic_1;
        }
    }
    if ( ap_rst.read() == ap_const_logic_1) {
        ap_enable_reg_pp0_iter1 = ap_const_logic_0;
    } else {
        if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage1.read()) && 
              esl_seteq<1,1,1>(ap_block_pp0_stage1_subdone.read(), ap_const_boolean_0)) || 
             (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
              esl_seteq<1,1,1>(ap_block_pp0_stage0_subdone.read(), ap_const_boolean_0)))) {
            ap_enable_reg_pp0_iter1 = ap_enable_reg_pp0_iter0.read();
        } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()) && 
                    !(esl_seteq<1,1,1>(ap_const_logic_0, ap_start.read()) || esl_seteq<1,1,1>(ap_done_reg.read(), ap_const_logic_1)))) {
            ap_enable_reg_pp0_iter1 = ap_const_logic_0;
        }
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter0.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, empty_n_fu_78_p1.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, icmp_ln879_fu_94_p2.read()))) {
        end_0_2_i_fu_40 = ap_const_lv1_1;
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()) && 
                !(esl_seteq<1,1,1>(ap_const_logic_0, ap_start.read()) || esl_seteq<1,1,1>(ap_done_reg.read(), ap_const_logic_1)))) {
        end_0_2_i_fu_40 = ap_const_lv1_0;
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter0.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, empty_n_1_fu_86_p1.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, icmp_ln879_1_fu_105_p2.read()))) {
        end_1_2_i_fu_44 = ap_const_lv1_1;
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()) && 
                !(esl_seteq<1,1,1>(ap_const_logic_0, ap_start.read()) || esl_seteq<1,1,1>(ap_done_reg.read(), ap_const_logic_1)))) {
        end_1_2_i_fu_44 = ap_const_lv1_0;
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && esl_seteq<1,1,1>(ap_block_pp0_stage0_11001.read(), ap_const_boolean_0))) {
        empty_n_1_reg_151 = in2_V_V_read_nbread_fu_54_p2_0.read();
        empty_n_reg_142 = in1_V_V_read_nbread_fu_48_p2_0.read();
        tmp_V_1_reg_155 = in2_V_V_dout.read();
        tmp_V_reg_146 = in1_V_V_dout.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && esl_seteq<1,1,1>(ap_block_pp0_stage0_11001.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(ap_const_lv1_1, empty_n_1_fu_86_p1.read()))) {
        icmp_ln879_1_reg_164 = icmp_ln879_1_fu_105_p2.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && esl_seteq<1,1,1>(ap_block_pp0_stage0_11001.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(ap_const_lv1_1, empty_n_fu_78_p1.read()))) {
        icmp_ln879_reg_160 = icmp_ln879_fu_94_p2.read();
    }
}

void combinar::thread_and_ln109_fu_122_p2() {
    and_ln109_fu_122_p2 = (end_0_2_i_fu_40.read() & end_1_2_i_fu_44.read());
}

void combinar::thread_ap_CS_fsm_pp0_stage0() {
    ap_CS_fsm_pp0_stage0 = ap_CS_fsm.read()[1];
}

void combinar::thread_ap_CS_fsm_pp0_stage1() {
    ap_CS_fsm_pp0_stage1 = ap_CS_fsm.read()[2];
}

void combinar::thread_ap_CS_fsm_state1() {
    ap_CS_fsm_state1 = ap_CS_fsm.read()[0];
}

void combinar::thread_ap_CS_fsm_state5() {
    ap_CS_fsm_state5 = ap_CS_fsm.read()[3];
}

void combinar::thread_ap_block_pp0_stage0() {
    ap_block_pp0_stage0 = !esl_seteq<1,1,1>(ap_const_boolean_1, ap_const_boolean_1);
}

void combinar::thread_ap_block_pp0_stage0_01001() {
    ap_block_pp0_stage0_01001 = (esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && esl_seteq<1,1,1>(ap_const_logic_0, result_V_V_full_n.read()) && esl_seteq<1,1,1>(ap_const_boolean_1, ap_predicate_op38_write_state4.read()));
}

void combinar::thread_ap_block_pp0_stage0_11001() {
    ap_block_pp0_stage0_11001 = (esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && esl_seteq<1,1,1>(ap_const_logic_0, result_V_V_full_n.read()) && esl_seteq<1,1,1>(ap_const_boolean_1, ap_predicate_op38_write_state4.read()));
}

void combinar::thread_ap_block_pp0_stage0_subdone() {
    ap_block_pp0_stage0_subdone = (esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && esl_seteq<1,1,1>(ap_const_logic_0, result_V_V_full_n.read()) && esl_seteq<1,1,1>(ap_const_boolean_1, ap_predicate_op38_write_state4.read()));
}

void combinar::thread_ap_block_pp0_stage1() {
    ap_block_pp0_stage1 = !esl_seteq<1,1,1>(ap_const_boolean_1, ap_const_boolean_1);
}

void combinar::thread_ap_block_pp0_stage1_01001() {
    ap_block_pp0_stage1_01001 = (esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter0.read()) && esl_seteq<1,1,1>(ap_const_logic_0, result_V_V_full_n.read()) && esl_seteq<1,1,1>(ap_const_boolean_1, ap_predicate_op29_write_state3.read()));
}

void combinar::thread_ap_block_pp0_stage1_11001() {
    ap_block_pp0_stage1_11001 = (esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter0.read()) && esl_seteq<1,1,1>(ap_const_logic_0, result_V_V_full_n.read()) && esl_seteq<1,1,1>(ap_const_boolean_1, ap_predicate_op29_write_state3.read()));
}

void combinar::thread_ap_block_pp0_stage1_subdone() {
    ap_block_pp0_stage1_subdone = (esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter0.read()) && esl_seteq<1,1,1>(ap_const_logic_0, result_V_V_full_n.read()) && esl_seteq<1,1,1>(ap_const_boolean_1, ap_predicate_op29_write_state3.read()));
}

void combinar::thread_ap_block_state1() {
    ap_block_state1 = (esl_seteq<1,1,1>(ap_const_logic_0, ap_start.read()) || esl_seteq<1,1,1>(ap_done_reg.read(), ap_const_logic_1));
}

void combinar::thread_ap_block_state2_pp0_stage0_iter0() {
    ap_block_state2_pp0_stage0_iter0 = !esl_seteq<1,1,1>(ap_const_boolean_1, ap_const_boolean_1);
}

void combinar::thread_ap_block_state3_pp0_stage1_iter0() {
    ap_block_state3_pp0_stage1_iter0 = (esl_seteq<1,1,1>(ap_const_logic_0, result_V_V_full_n.read()) && esl_seteq<1,1,1>(ap_const_boolean_1, ap_predicate_op29_write_state3.read()));
}

void combinar::thread_ap_block_state4_pp0_stage0_iter1() {
    ap_block_state4_pp0_stage0_iter1 = (esl_seteq<1,1,1>(ap_const_logic_0, result_V_V_full_n.read()) && esl_seteq<1,1,1>(ap_const_boolean_1, ap_predicate_op38_write_state4.read()));
}

void combinar::thread_ap_done() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state5.read()) && 
         esl_seteq<1,1,1>(result_V_V_full_n.read(), ap_const_logic_1))) {
        ap_done = ap_const_logic_1;
    } else {
        ap_done = ap_done_reg.read();
    }
}

void combinar::thread_ap_enable_pp0() {
    ap_enable_pp0 = (ap_idle_pp0.read() ^ ap_const_logic_1);
}

void combinar::thread_ap_idle() {
    if ((esl_seteq<1,1,1>(ap_const_logic_0, ap_start.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()))) {
        ap_idle = ap_const_logic_1;
    } else {
        ap_idle = ap_const_logic_0;
    }
}

void combinar::thread_ap_idle_pp0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_0, ap_enable_reg_pp0_iter0.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_0, ap_enable_reg_pp0_iter1.read()))) {
        ap_idle_pp0 = ap_const_logic_1;
    } else {
        ap_idle_pp0 = ap_const_logic_0;
    }
}

void combinar::thread_ap_predicate_op29_write_state3() {
    ap_predicate_op29_write_state3 = (esl_seteq<1,1,1>(empty_n_reg_142.read(), ap_const_lv1_1) && esl_seteq<1,1,1>(icmp_ln879_reg_160.read(), ap_const_lv1_0));
}

void combinar::thread_ap_predicate_op38_write_state4() {
    ap_predicate_op38_write_state4 = (esl_seteq<1,1,1>(ap_const_lv1_1, empty_n_1_reg_151.read()) && esl_seteq<1,1,1>(ap_const_lv1_0, icmp_ln879_1_reg_164.read()));
}

void combinar::thread_ap_ready() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state5.read()) && 
         esl_seteq<1,1,1>(result_V_V_full_n.read(), ap_const_logic_1))) {
        ap_ready = ap_const_logic_1;
    } else {
        ap_ready = ap_const_logic_0;
    }
}

void combinar::thread_empty_n_1_fu_86_p1() {
    empty_n_1_fu_86_p1 = in2_V_V_read_nbread_fu_54_p2_0.read();
}

void combinar::thread_empty_n_fu_78_p1() {
    empty_n_fu_78_p1 = in1_V_V_read_nbread_fu_48_p2_0.read();
}

void combinar::thread_icmp_ln879_1_fu_105_p2() {
    icmp_ln879_1_fu_105_p2 = (!in2_V_V_dout.read().is_01() || !ap_const_lv11_0.is_01())? sc_lv<1>(): sc_lv<1>(in2_V_V_dout.read() == ap_const_lv11_0);
}

void combinar::thread_icmp_ln879_fu_94_p2() {
    icmp_ln879_fu_94_p2 = (!in1_V_V_dout.read().is_01() || !ap_const_lv11_0.is_01())? sc_lv<1>(): sc_lv<1>(in1_V_V_dout.read() == ap_const_lv11_0);
}

void combinar::thread_in1_V_V_read() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter0.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, in1_V_V_empty_n.read()))) {
        in1_V_V_read = ap_const_logic_1;
    } else {
        in1_V_V_read = ap_const_logic_0;
    }
}

void combinar::thread_in1_V_V_read_nbread_fu_48_p2_0() {
    in1_V_V_read_nbread_fu_48_p2_0 =  (sc_lv<1>) ((in1_V_V_empty_n.read()));
}

void combinar::thread_in2_V_V_read() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter0.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, in2_V_V_empty_n.read()))) {
        in2_V_V_read = ap_const_logic_1;
    } else {
        in2_V_V_read = ap_const_logic_0;
    }
}

void combinar::thread_in2_V_V_read_nbread_fu_54_p2_0() {
    in2_V_V_read_nbread_fu_54_p2_0 =  (sc_lv<1>) ((in2_V_V_empty_n.read()));
}

void combinar::thread_result_V_V_blk_n() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage1.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter0.read()) && 
          esl_seteq<1,1,1>(ap_block_pp0_stage1.read(), ap_const_boolean_0) && 
          esl_seteq<1,1,1>(empty_n_reg_142.read(), ap_const_lv1_1) && 
          esl_seteq<1,1,1>(icmp_ln879_reg_160.read(), ap_const_lv1_0)) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
          esl_seteq<1,1,1>(ap_block_pp0_stage0.read(), ap_const_boolean_0) && 
          esl_seteq<1,1,1>(ap_const_lv1_1, empty_n_1_reg_151.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, icmp_ln879_1_reg_164.read())) || 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state5.read()))) {
        result_V_V_blk_n = result_V_V_full_n.read();
    } else {
        result_V_V_blk_n = ap_const_logic_1;
    }
}

void combinar::thread_result_V_V_din() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state5.read()) && 
         esl_seteq<1,1,1>(result_V_V_full_n.read(), ap_const_logic_1))) {
        result_V_V_din = ap_const_lv11_0;
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
                esl_seteq<1,1,1>(ap_const_boolean_1, ap_predicate_op38_write_state4.read()) && 
                esl_seteq<1,1,1>(ap_block_pp0_stage0_01001.read(), ap_const_boolean_0))) {
        result_V_V_din = tmp_V_1_reg_155.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage1.read()) && 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter0.read()) && 
                esl_seteq<1,1,1>(ap_const_boolean_1, ap_predicate_op29_write_state3.read()) && 
                esl_seteq<1,1,1>(ap_block_pp0_stage1_01001.read(), ap_const_boolean_0))) {
        result_V_V_din = tmp_V_reg_146.read();
    } else {
        result_V_V_din = "XXXXXXXXXXX";
    }
}

void combinar::thread_result_V_V_write() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state5.read()) && 
          esl_seteq<1,1,1>(result_V_V_full_n.read(), ap_const_logic_1)) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage1.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter0.read()) && 
          esl_seteq<1,1,1>(ap_const_boolean_1, ap_predicate_op29_write_state3.read()) && 
          esl_seteq<1,1,1>(ap_block_pp0_stage1_11001.read(), ap_const_boolean_0)) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
          esl_seteq<1,1,1>(ap_const_boolean_1, ap_predicate_op38_write_state4.read()) && 
          esl_seteq<1,1,1>(ap_block_pp0_stage0_11001.read(), ap_const_boolean_0)))) {
        result_V_V_write = ap_const_logic_1;
    } else {
        result_V_V_write = ap_const_logic_0;
    }
}

void combinar::thread_ap_NS_fsm() {
    switch (ap_CS_fsm.read().to_uint64()) {
        case 1 : 
            if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()) && !(esl_seteq<1,1,1>(ap_const_logic_0, ap_start.read()) || esl_seteq<1,1,1>(ap_done_reg.read(), ap_const_logic_1)))) {
                ap_NS_fsm = ap_ST_fsm_pp0_stage0;
            } else {
                ap_NS_fsm = ap_ST_fsm_state1;
            }
            break;
        case 2 : 
            if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_subdone.read(), ap_const_boolean_0) && !(esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && esl_seteq<1,1,1>(ap_block_pp0_stage0_subdone.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(ap_enable_reg_pp0_iter0.read(), ap_const_logic_0)))) {
                ap_NS_fsm = ap_ST_fsm_pp0_stage1;
            } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && esl_seteq<1,1,1>(ap_block_pp0_stage0_subdone.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(ap_enable_reg_pp0_iter0.read(), ap_const_logic_0))) {
                ap_NS_fsm = ap_ST_fsm_state5;
            } else {
                ap_NS_fsm = ap_ST_fsm_pp0_stage0;
            }
            break;
        case 4 : 
            if (esl_seteq<1,1,1>(ap_block_pp0_stage1_subdone.read(), ap_const_boolean_0)) {
                ap_NS_fsm = ap_ST_fsm_pp0_stage0;
            } else {
                ap_NS_fsm = ap_ST_fsm_pp0_stage1;
            }
            break;
        case 8 : 
            if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state5.read()) && esl_seteq<1,1,1>(result_V_V_full_n.read(), ap_const_logic_1))) {
                ap_NS_fsm = ap_ST_fsm_state1;
            } else {
                ap_NS_fsm = ap_ST_fsm_state5;
            }
            break;
        default : 
            ap_NS_fsm =  (sc_lv<4>) ("XXXX");
            break;
    }
}

}

