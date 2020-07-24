// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2019.1
// Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

#include "busqueda_cam.h"
#include "AESL_pkg.h"

using namespace std;

namespace ap_rtl {

const sc_logic busqueda_cam::ap_const_logic_1 = sc_dt::Log_1;
const sc_logic busqueda_cam::ap_const_logic_0 = sc_dt::Log_0;
const sc_lv<3> busqueda_cam::ap_ST_fsm_state1 = "1";
const sc_lv<3> busqueda_cam::ap_ST_fsm_state2 = "10";
const sc_lv<3> busqueda_cam::ap_ST_fsm_state3 = "100";
const sc_lv<32> busqueda_cam::ap_const_lv32_0 = "00000000000000000000000000000000";
const bool busqueda_cam::ap_const_boolean_1 = true;
const sc_lv<32> busqueda_cam::ap_const_lv32_1 = "1";
const sc_lv<1> busqueda_cam::ap_const_lv1_1 = "1";
const sc_lv<1> busqueda_cam::ap_const_lv1_0 = "0";
const sc_lv<32> busqueda_cam::ap_const_lv32_2 = "10";
const sc_lv<64> busqueda_cam::ap_const_lv64_0 = "0000000000000000000000000000000000000000000000000000000000000000";
const sc_lv<11> busqueda_cam::ap_const_lv11_0 = "00000000000";
const sc_lv<32> busqueda_cam::ap_const_lv32_D = "1101";
const sc_lv<32> busqueda_cam::ap_const_lv32_17 = "10111";
const sc_lv<32> busqueda_cam::ap_const_lv32_C = "1100";

busqueda_cam::busqueda_cam(sc_module_name name) : sc_module(name), mVcdFile(0) {

    SC_METHOD(thread_ap_clk_no_reset_);
    dont_initialize();
    sensitive << ( ap_clk.pos() );

    SC_METHOD(thread_and_ln58_fu_130_p2);
    sensitive << ( icmp_ln879_2_fu_118_p2 );
    sensitive << ( icmp_ln879_3_fu_124_p2 );

    SC_METHOD(thread_and_ln67_fu_152_p2);
    sensitive << ( icmp_ln879_fu_140_p2 );
    sensitive << ( icmp_ln879_1_fu_146_p2 );

    SC_METHOD(thread_ap_CS_fsm_state1);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_CS_fsm_state2);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_CS_fsm_state3);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_block_state1);
    sensitive << ( ap_start );
    sensitive << ( ap_done_reg );

    SC_METHOD(thread_ap_block_state2);
    sensitive << ( result_V_V_full_n );
    sensitive << ( ap_predicate_op19_write_state2 );
    sensitive << ( ap_predicate_op29_write_state2 );

    SC_METHOD(thread_ap_done);
    sensitive << ( ap_done_reg );
    sensitive << ( result_V_V_full_n );
    sensitive << ( ap_CS_fsm_state3 );

    SC_METHOD(thread_ap_idle);
    sensitive << ( ap_start );
    sensitive << ( ap_CS_fsm_state1 );

    SC_METHOD(thread_ap_predicate_op19_write_state2);
    sensitive << ( fatherSearch_read_read_fu_42_p2 );
    sensitive << ( and_ln58_fu_130_p2 );

    SC_METHOD(thread_ap_predicate_op29_write_state2);
    sensitive << ( fatherSearch_read_read_fu_42_p2 );
    sensitive << ( and_ln67_fu_152_p2 );

    SC_METHOD(thread_ap_ready);
    sensitive << ( result_V_V_full_n );
    sensitive << ( ap_CS_fsm_state3 );

    SC_METHOD(thread_fatherSearch_read_read_fu_42_p2);
    sensitive << ( fatherSearch );
    sensitive << ( result_V_V_full_n );
    sensitive << ( ap_CS_fsm_state2 );
    sensitive << ( ap_predicate_op19_write_state2 );
    sensitive << ( ap_predicate_op29_write_state2 );

    SC_METHOD(thread_grp_fu_82_p4);
    sensitive << ( tree_V_q0 );

    SC_METHOD(thread_icmp_ln879_1_fu_146_p2);
    sensitive << ( relationship_V );
    sensitive << ( result_V_V_full_n );
    sensitive << ( ap_CS_fsm_state2 );
    sensitive << ( fatherSearch_read_read_fu_42_p2 );
    sensitive << ( ap_predicate_op19_write_state2 );
    sensitive << ( ap_predicate_op29_write_state2 );
    sensitive << ( trunc_ln647_fu_136_p1 );

    SC_METHOD(thread_icmp_ln879_2_fu_118_p2);
    sensitive << ( nodo_V );
    sensitive << ( result_V_V_full_n );
    sensitive << ( ap_CS_fsm_state2 );
    sensitive << ( fatherSearch_read_read_fu_42_p2 );
    sensitive << ( ap_predicate_op19_write_state2 );
    sensitive << ( ap_predicate_op29_write_state2 );
    sensitive << ( grp_fu_82_p4 );

    SC_METHOD(thread_icmp_ln879_3_fu_124_p2);
    sensitive << ( relationship_V );
    sensitive << ( result_V_V_full_n );
    sensitive << ( ap_CS_fsm_state2 );
    sensitive << ( fatherSearch_read_read_fu_42_p2 );
    sensitive << ( ap_predicate_op19_write_state2 );
    sensitive << ( ap_predicate_op29_write_state2 );
    sensitive << ( trunc_ln647_1_fu_114_p1 );

    SC_METHOD(thread_icmp_ln879_fu_140_p2);
    sensitive << ( nodo_V );
    sensitive << ( result_V_V_full_n );
    sensitive << ( ap_CS_fsm_state2 );
    sensitive << ( fatherSearch_read_read_fu_42_p2 );
    sensitive << ( ap_predicate_op19_write_state2 );
    sensitive << ( ap_predicate_op29_write_state2 );
    sensitive << ( p_Result_7_fu_104_p4 );

    SC_METHOD(thread_p_Result_7_fu_104_p4);
    sensitive << ( tree_V_q0 );

    SC_METHOD(thread_result_V_V_blk_n);
    sensitive << ( result_V_V_full_n );
    sensitive << ( ap_CS_fsm_state2 );
    sensitive << ( fatherSearch_read_read_fu_42_p2 );
    sensitive << ( and_ln67_fu_152_p2 );
    sensitive << ( and_ln58_fu_130_p2 );
    sensitive << ( ap_CS_fsm_state3 );

    SC_METHOD(thread_result_V_V_din);
    sensitive << ( tree_V_q0 );
    sensitive << ( result_V_V_full_n );
    sensitive << ( ap_CS_fsm_state2 );
    sensitive << ( ap_CS_fsm_state3 );
    sensitive << ( ap_predicate_op19_write_state2 );
    sensitive << ( ap_predicate_op29_write_state2 );

    SC_METHOD(thread_result_V_V_write);
    sensitive << ( result_V_V_full_n );
    sensitive << ( ap_CS_fsm_state2 );
    sensitive << ( ap_CS_fsm_state3 );
    sensitive << ( ap_predicate_op19_write_state2 );
    sensitive << ( ap_predicate_op29_write_state2 );

    SC_METHOD(thread_tree_V_address0);
    sensitive << ( ap_CS_fsm_state1 );

    SC_METHOD(thread_tree_V_ce0);
    sensitive << ( ap_start );
    sensitive << ( ap_done_reg );
    sensitive << ( ap_CS_fsm_state1 );

    SC_METHOD(thread_trunc_ln647_1_fu_114_p1);
    sensitive << ( tree_V_q0 );

    SC_METHOD(thread_trunc_ln647_fu_136_p1);
    sensitive << ( tree_V_q0 );

    SC_METHOD(thread_ap_NS_fsm);
    sensitive << ( ap_start );
    sensitive << ( ap_done_reg );
    sensitive << ( ap_CS_fsm );
    sensitive << ( ap_CS_fsm_state1 );
    sensitive << ( result_V_V_full_n );
    sensitive << ( ap_CS_fsm_state2 );
    sensitive << ( ap_CS_fsm_state3 );
    sensitive << ( ap_predicate_op19_write_state2 );
    sensitive << ( ap_predicate_op29_write_state2 );

    ap_done_reg = SC_LOGIC_0;
    ap_CS_fsm = "001";
    static int apTFileNum = 0;
    stringstream apTFilenSS;
    apTFilenSS << "busqueda_cam_sc_trace_" << apTFileNum ++;
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
    sc_trace(mVcdFile, tree_V_address0, "(port)tree_V_address0");
    sc_trace(mVcdFile, tree_V_ce0, "(port)tree_V_ce0");
    sc_trace(mVcdFile, tree_V_q0, "(port)tree_V_q0");
    sc_trace(mVcdFile, nodo_V, "(port)nodo_V");
    sc_trace(mVcdFile, relationship_V, "(port)relationship_V");
    sc_trace(mVcdFile, fatherSearch, "(port)fatherSearch");
    sc_trace(mVcdFile, result_V_V_din, "(port)result_V_V_din");
    sc_trace(mVcdFile, result_V_V_full_n, "(port)result_V_V_full_n");
    sc_trace(mVcdFile, result_V_V_write, "(port)result_V_V_write");
#endif
#ifdef __HLS_TRACE_LEVEL_INT__
    sc_trace(mVcdFile, ap_done_reg, "ap_done_reg");
    sc_trace(mVcdFile, ap_CS_fsm, "ap_CS_fsm");
    sc_trace(mVcdFile, ap_CS_fsm_state1, "ap_CS_fsm_state1");
    sc_trace(mVcdFile, result_V_V_blk_n, "result_V_V_blk_n");
    sc_trace(mVcdFile, ap_CS_fsm_state2, "ap_CS_fsm_state2");
    sc_trace(mVcdFile, fatherSearch_read_read_fu_42_p2, "fatherSearch_read_read_fu_42_p2");
    sc_trace(mVcdFile, and_ln67_fu_152_p2, "and_ln67_fu_152_p2");
    sc_trace(mVcdFile, and_ln58_fu_130_p2, "and_ln58_fu_130_p2");
    sc_trace(mVcdFile, ap_CS_fsm_state3, "ap_CS_fsm_state3");
    sc_trace(mVcdFile, ap_block_state1, "ap_block_state1");
    sc_trace(mVcdFile, ap_predicate_op19_write_state2, "ap_predicate_op19_write_state2");
    sc_trace(mVcdFile, ap_predicate_op29_write_state2, "ap_predicate_op29_write_state2");
    sc_trace(mVcdFile, ap_block_state2, "ap_block_state2");
    sc_trace(mVcdFile, grp_fu_82_p4, "grp_fu_82_p4");
    sc_trace(mVcdFile, trunc_ln647_1_fu_114_p1, "trunc_ln647_1_fu_114_p1");
    sc_trace(mVcdFile, icmp_ln879_2_fu_118_p2, "icmp_ln879_2_fu_118_p2");
    sc_trace(mVcdFile, icmp_ln879_3_fu_124_p2, "icmp_ln879_3_fu_124_p2");
    sc_trace(mVcdFile, p_Result_7_fu_104_p4, "p_Result_7_fu_104_p4");
    sc_trace(mVcdFile, trunc_ln647_fu_136_p1, "trunc_ln647_fu_136_p1");
    sc_trace(mVcdFile, icmp_ln879_fu_140_p2, "icmp_ln879_fu_140_p2");
    sc_trace(mVcdFile, icmp_ln879_1_fu_146_p2, "icmp_ln879_1_fu_146_p2");
    sc_trace(mVcdFile, ap_NS_fsm, "ap_NS_fsm");
#endif

    }
}

busqueda_cam::~busqueda_cam() {
    if (mVcdFile) 
        sc_close_vcd_trace_file(mVcdFile);

}

void busqueda_cam::thread_ap_clk_no_reset_() {
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
        } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state3.read()) && 
                    esl_seteq<1,1,1>(result_V_V_full_n.read(), ap_const_logic_1))) {
            ap_done_reg = ap_const_logic_1;
        }
    }
}

void busqueda_cam::thread_and_ln58_fu_130_p2() {
    and_ln58_fu_130_p2 = (icmp_ln879_2_fu_118_p2.read() & icmp_ln879_3_fu_124_p2.read());
}

void busqueda_cam::thread_and_ln67_fu_152_p2() {
    and_ln67_fu_152_p2 = (icmp_ln879_fu_140_p2.read() & icmp_ln879_1_fu_146_p2.read());
}

void busqueda_cam::thread_ap_CS_fsm_state1() {
    ap_CS_fsm_state1 = ap_CS_fsm.read()[0];
}

void busqueda_cam::thread_ap_CS_fsm_state2() {
    ap_CS_fsm_state2 = ap_CS_fsm.read()[1];
}

void busqueda_cam::thread_ap_CS_fsm_state3() {
    ap_CS_fsm_state3 = ap_CS_fsm.read()[2];
}

void busqueda_cam::thread_ap_block_state1() {
    ap_block_state1 = (esl_seteq<1,1,1>(ap_const_logic_0, ap_start.read()) || esl_seteq<1,1,1>(ap_done_reg.read(), ap_const_logic_1));
}

void busqueda_cam::thread_ap_block_state2() {
    ap_block_state2 = ((esl_seteq<1,1,1>(ap_const_logic_0, result_V_V_full_n.read()) && 
  esl_seteq<1,1,1>(ap_const_boolean_1, ap_predicate_op19_write_state2.read())) || (esl_seteq<1,1,1>(ap_const_logic_0, result_V_V_full_n.read()) && 
  esl_seteq<1,1,1>(ap_const_boolean_1, ap_predicate_op29_write_state2.read())));
}

void busqueda_cam::thread_ap_done() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state3.read()) && 
         esl_seteq<1,1,1>(result_V_V_full_n.read(), ap_const_logic_1))) {
        ap_done = ap_const_logic_1;
    } else {
        ap_done = ap_done_reg.read();
    }
}

void busqueda_cam::thread_ap_idle() {
    if ((esl_seteq<1,1,1>(ap_const_logic_0, ap_start.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()))) {
        ap_idle = ap_const_logic_1;
    } else {
        ap_idle = ap_const_logic_0;
    }
}

void busqueda_cam::thread_ap_predicate_op19_write_state2() {
    ap_predicate_op19_write_state2 = (esl_seteq<1,1,1>(fatherSearch_read_read_fu_42_p2.read(), ap_const_lv1_0) && esl_seteq<1,1,1>(ap_const_lv1_1, and_ln58_fu_130_p2.read()));
}

void busqueda_cam::thread_ap_predicate_op29_write_state2() {
    ap_predicate_op29_write_state2 = (esl_seteq<1,1,1>(fatherSearch_read_read_fu_42_p2.read(), ap_const_lv1_1) && esl_seteq<1,1,1>(ap_const_lv1_1, and_ln67_fu_152_p2.read()));
}

void busqueda_cam::thread_ap_ready() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state3.read()) && 
         esl_seteq<1,1,1>(result_V_V_full_n.read(), ap_const_logic_1))) {
        ap_ready = ap_const_logic_1;
    } else {
        ap_ready = ap_const_logic_0;
    }
}

void busqueda_cam::thread_fatherSearch_read_read_fu_42_p2() {
    fatherSearch_read_read_fu_42_p2 =  (sc_lv<1>) (fatherSearch.read());
}

void busqueda_cam::thread_grp_fu_82_p4() {
    grp_fu_82_p4 = tree_V_q0.read().range(23, 13);
}

void busqueda_cam::thread_icmp_ln879_1_fu_146_p2() {
    icmp_ln879_1_fu_146_p2 = (!trunc_ln647_fu_136_p1.read().is_01() || !relationship_V.read().is_01())? sc_lv<1>(): sc_lv<1>(trunc_ln647_fu_136_p1.read() == relationship_V.read());
}

void busqueda_cam::thread_icmp_ln879_2_fu_118_p2() {
    icmp_ln879_2_fu_118_p2 = (!grp_fu_82_p4.read().is_01() || !nodo_V.read().is_01())? sc_lv<1>(): sc_lv<1>(grp_fu_82_p4.read() == nodo_V.read());
}

void busqueda_cam::thread_icmp_ln879_3_fu_124_p2() {
    icmp_ln879_3_fu_124_p2 = (!trunc_ln647_1_fu_114_p1.read().is_01() || !relationship_V.read().is_01())? sc_lv<1>(): sc_lv<1>(trunc_ln647_1_fu_114_p1.read() == relationship_V.read());
}

void busqueda_cam::thread_icmp_ln879_fu_140_p2() {
    icmp_ln879_fu_140_p2 = (!p_Result_7_fu_104_p4.read().is_01() || !nodo_V.read().is_01())? sc_lv<1>(): sc_lv<1>(p_Result_7_fu_104_p4.read() == nodo_V.read());
}

void busqueda_cam::thread_p_Result_7_fu_104_p4() {
    p_Result_7_fu_104_p4 = tree_V_q0.read().range(12, 2);
}

void busqueda_cam::thread_result_V_V_blk_n() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state2.read()) && 
          esl_seteq<1,1,1>(fatherSearch_read_read_fu_42_p2.read(), ap_const_lv1_1) && 
          esl_seteq<1,1,1>(ap_const_lv1_1, and_ln67_fu_152_p2.read())) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state2.read()) && 
          esl_seteq<1,1,1>(fatherSearch_read_read_fu_42_p2.read(), ap_const_lv1_0) && 
          esl_seteq<1,1,1>(ap_const_lv1_1, and_ln58_fu_130_p2.read())) || 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state3.read()))) {
        result_V_V_blk_n = result_V_V_full_n.read();
    } else {
        result_V_V_blk_n = ap_const_logic_1;
    }
}

void busqueda_cam::thread_result_V_V_din() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state3.read()) && 
         esl_seteq<1,1,1>(result_V_V_full_n.read(), ap_const_logic_1))) {
        result_V_V_din = ap_const_lv11_0;
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state2.read()) && 
                esl_seteq<1,1,1>(ap_const_boolean_1, ap_predicate_op29_write_state2.read()) && 
                !((esl_seteq<1,1,1>(ap_const_logic_0, result_V_V_full_n.read()) && 
  esl_seteq<1,1,1>(ap_const_boolean_1, ap_predicate_op19_write_state2.read())) || (esl_seteq<1,1,1>(ap_const_logic_0, result_V_V_full_n.read()) && 
  esl_seteq<1,1,1>(ap_const_boolean_1, ap_predicate_op29_write_state2.read()))))) {
        result_V_V_din = tree_V_q0.read().range(23, 13);
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state2.read()) && 
                esl_seteq<1,1,1>(ap_const_boolean_1, ap_predicate_op19_write_state2.read()) && 
                !((esl_seteq<1,1,1>(ap_const_logic_0, result_V_V_full_n.read()) && 
  esl_seteq<1,1,1>(ap_const_boolean_1, ap_predicate_op19_write_state2.read())) || (esl_seteq<1,1,1>(ap_const_logic_0, result_V_V_full_n.read()) && 
  esl_seteq<1,1,1>(ap_const_boolean_1, ap_predicate_op29_write_state2.read()))))) {
        result_V_V_din = tree_V_q0.read().range(12, 2);
    } else {
        result_V_V_din = "XXXXXXXXXXX";
    }
}

void busqueda_cam::thread_result_V_V_write() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state2.read()) && 
          esl_seteq<1,1,1>(ap_const_boolean_1, ap_predicate_op19_write_state2.read()) && 
          !((esl_seteq<1,1,1>(ap_const_logic_0, result_V_V_full_n.read()) && 
  esl_seteq<1,1,1>(ap_const_boolean_1, ap_predicate_op19_write_state2.read())) || (esl_seteq<1,1,1>(ap_const_logic_0, result_V_V_full_n.read()) && 
  esl_seteq<1,1,1>(ap_const_boolean_1, ap_predicate_op29_write_state2.read())))) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state2.read()) && 
          esl_seteq<1,1,1>(ap_const_boolean_1, ap_predicate_op29_write_state2.read()) && 
          !((esl_seteq<1,1,1>(ap_const_logic_0, result_V_V_full_n.read()) && 
  esl_seteq<1,1,1>(ap_const_boolean_1, ap_predicate_op19_write_state2.read())) || (esl_seteq<1,1,1>(ap_const_logic_0, result_V_V_full_n.read()) && 
  esl_seteq<1,1,1>(ap_const_boolean_1, ap_predicate_op29_write_state2.read())))) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state3.read()) && 
          esl_seteq<1,1,1>(result_V_V_full_n.read(), ap_const_logic_1)))) {
        result_V_V_write = ap_const_logic_1;
    } else {
        result_V_V_write = ap_const_logic_0;
    }
}

void busqueda_cam::thread_tree_V_address0() {
    tree_V_address0 =  (sc_lv<10>) (ap_const_lv64_0);
}

void busqueda_cam::thread_tree_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()) && 
         !(esl_seteq<1,1,1>(ap_const_logic_0, ap_start.read()) || esl_seteq<1,1,1>(ap_done_reg.read(), ap_const_logic_1)))) {
        tree_V_ce0 = ap_const_logic_1;
    } else {
        tree_V_ce0 = ap_const_logic_0;
    }
}

void busqueda_cam::thread_trunc_ln647_1_fu_114_p1() {
    trunc_ln647_1_fu_114_p1 = tree_V_q0.read().range(2-1, 0);
}

void busqueda_cam::thread_trunc_ln647_fu_136_p1() {
    trunc_ln647_fu_136_p1 = tree_V_q0.read().range(2-1, 0);
}

void busqueda_cam::thread_ap_NS_fsm() {
    switch (ap_CS_fsm.read().to_uint64()) {
        case 1 : 
            if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()) && !(esl_seteq<1,1,1>(ap_const_logic_0, ap_start.read()) || esl_seteq<1,1,1>(ap_done_reg.read(), ap_const_logic_1)))) {
                ap_NS_fsm = ap_ST_fsm_state2;
            } else {
                ap_NS_fsm = ap_ST_fsm_state1;
            }
            break;
        case 2 : 
            if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state2.read()) && !((esl_seteq<1,1,1>(ap_const_logic_0, result_V_V_full_n.read()) && 
  esl_seteq<1,1,1>(ap_const_boolean_1, ap_predicate_op19_write_state2.read())) || (esl_seteq<1,1,1>(ap_const_logic_0, result_V_V_full_n.read()) && 
  esl_seteq<1,1,1>(ap_const_boolean_1, ap_predicate_op29_write_state2.read()))))) {
                ap_NS_fsm = ap_ST_fsm_state3;
            } else {
                ap_NS_fsm = ap_ST_fsm_state2;
            }
            break;
        case 4 : 
            if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state3.read()) && esl_seteq<1,1,1>(result_V_V_full_n.read(), ap_const_logic_1))) {
                ap_NS_fsm = ap_ST_fsm_state1;
            } else {
                ap_NS_fsm = ap_ST_fsm_state3;
            }
            break;
        default : 
            ap_NS_fsm =  (sc_lv<3>) ("XXX");
            break;
    }
}

}

