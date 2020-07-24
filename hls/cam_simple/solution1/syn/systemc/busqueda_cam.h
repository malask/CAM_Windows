// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2019.1
// Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

#ifndef _busqueda_cam_HH_
#define _busqueda_cam_HH_

#include "systemc.h"
#include "AESL_pkg.h"


namespace ap_rtl {

struct busqueda_cam : public sc_module {
    // Port declarations 15
    sc_in_clk ap_clk;
    sc_in< sc_logic > ap_rst;
    sc_in< sc_logic > ap_start;
    sc_out< sc_logic > ap_done;
    sc_out< sc_logic > ap_idle;
    sc_out< sc_logic > ap_ready;
    sc_out< sc_lv<10> > tree_V_address0;
    sc_out< sc_logic > tree_V_ce0;
    sc_in< sc_lv<24> > tree_V_q0;
    sc_in< sc_lv<11> > nodo_V;
    sc_in< sc_lv<2> > relationship_V;
    sc_in< sc_logic > fatherSearch;
    sc_out< sc_lv<11> > result_V_V_din;
    sc_in< sc_logic > result_V_V_full_n;
    sc_out< sc_logic > result_V_V_write;


    // Module declarations
    busqueda_cam(sc_module_name name);
    SC_HAS_PROCESS(busqueda_cam);

    ~busqueda_cam();

    sc_trace_file* mVcdFile;

    sc_signal< sc_lv<4> > ap_CS_fsm;
    sc_signal< sc_logic > ap_CS_fsm_state1;
    sc_signal< sc_logic > result_V_V_blk_n;
    sc_signal< sc_logic > ap_CS_fsm_state4;
    sc_signal< sc_lv<1> > and_ln21_fu_219_p2;
    sc_signal< sc_logic > ap_CS_fsm_state3;
    sc_signal< sc_lv<1> > and_ln28_fu_199_p2;
    sc_signal< sc_logic > ap_CS_fsm_state2;
    sc_signal< sc_lv<1> > fatherSearch_read_read_fu_50_p2;
    sc_signal< sc_lv<1> > icmp_ln17_fu_168_p2;
    sc_signal< sc_lv<1> > icmp_ln24_fu_151_p2;
    sc_signal< sc_lv<11> > i_1_fu_157_p2;
    sc_signal< sc_lv<11> > i_1_reg_244;
    sc_signal< bool > ap_predicate_op30_write_state2;
    sc_signal< bool > ap_block_state2;
    sc_signal< sc_lv<11> > i_fu_174_p2;
    sc_signal< sc_lv<11> > i_reg_257;
    sc_signal< sc_lv<11> > i1_0_reg_97;
    sc_signal< bool > ap_block_state3;
    sc_signal< sc_lv<11> > i_0_reg_108;
    sc_signal< bool > ap_block_state4;
    sc_signal< sc_lv<64> > zext_ln25_fu_163_p1;
    sc_signal< sc_lv<64> > zext_ln18_fu_180_p1;
    sc_signal< sc_lv<11> > grp_fu_119_p4;
    sc_signal< sc_lv<2> > node_relation_V_1_fu_185_p1;
    sc_signal< sc_lv<1> > icmp_ln879_1_fu_189_p2;
    sc_signal< sc_lv<1> > icmp_ln879_3_fu_194_p2;
    sc_signal< sc_lv<11> > compare_node_V_fu_141_p4;
    sc_signal< sc_lv<2> > node_relation_V_fu_205_p1;
    sc_signal< sc_lv<1> > icmp_ln879_fu_209_p2;
    sc_signal< sc_lv<1> > icmp_ln879_2_fu_214_p2;
    sc_signal< sc_lv<4> > ap_NS_fsm;
    static const sc_logic ap_const_logic_1;
    static const sc_logic ap_const_logic_0;
    static const sc_lv<4> ap_ST_fsm_state1;
    static const sc_lv<4> ap_ST_fsm_state2;
    static const sc_lv<4> ap_ST_fsm_state3;
    static const sc_lv<4> ap_ST_fsm_state4;
    static const bool ap_const_boolean_1;
    static const sc_lv<32> ap_const_lv32_0;
    static const sc_lv<32> ap_const_lv32_3;
    static const sc_lv<1> ap_const_lv1_1;
    static const sc_lv<32> ap_const_lv32_2;
    static const sc_lv<32> ap_const_lv32_1;
    static const sc_lv<1> ap_const_lv1_0;
    static const sc_lv<11> ap_const_lv11_0;
    static const sc_lv<32> ap_const_lv32_D;
    static const sc_lv<32> ap_const_lv32_17;
    static const sc_lv<32> ap_const_lv32_C;
    static const sc_lv<11> ap_const_lv11_400;
    static const sc_lv<11> ap_const_lv11_1;
    // Thread declarations
    void thread_ap_clk_no_reset_();
    void thread_and_ln21_fu_219_p2();
    void thread_and_ln28_fu_199_p2();
    void thread_ap_CS_fsm_state1();
    void thread_ap_CS_fsm_state2();
    void thread_ap_CS_fsm_state3();
    void thread_ap_CS_fsm_state4();
    void thread_ap_block_state2();
    void thread_ap_block_state3();
    void thread_ap_block_state4();
    void thread_ap_done();
    void thread_ap_idle();
    void thread_ap_predicate_op30_write_state2();
    void thread_ap_ready();
    void thread_compare_node_V_fu_141_p4();
    void thread_fatherSearch_read_read_fu_50_p2();
    void thread_grp_fu_119_p4();
    void thread_i_1_fu_157_p2();
    void thread_i_fu_174_p2();
    void thread_icmp_ln17_fu_168_p2();
    void thread_icmp_ln24_fu_151_p2();
    void thread_icmp_ln879_1_fu_189_p2();
    void thread_icmp_ln879_2_fu_214_p2();
    void thread_icmp_ln879_3_fu_194_p2();
    void thread_icmp_ln879_fu_209_p2();
    void thread_node_relation_V_1_fu_185_p1();
    void thread_node_relation_V_fu_205_p1();
    void thread_result_V_V_blk_n();
    void thread_result_V_V_din();
    void thread_result_V_V_write();
    void thread_tree_V_address0();
    void thread_tree_V_ce0();
    void thread_zext_ln18_fu_180_p1();
    void thread_zext_ln25_fu_163_p1();
    void thread_ap_NS_fsm();
};

}

using namespace ap_rtl;

#endif
