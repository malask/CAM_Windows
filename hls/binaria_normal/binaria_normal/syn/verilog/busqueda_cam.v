// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2019.1
// Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

`timescale 1 ns / 1 ps 

module busqueda_cam (
        ap_clk,
        ap_rst,
        ap_start,
        ap_done,
        ap_idle,
        ap_ready,
        tree_V_address0,
        tree_V_ce0,
        tree_V_q0,
        tree_V_address1,
        tree_V_ce1,
        tree_V_q1,
        nodo_V,
        relationship_V,
        fatherSearch,
        result_V_V_din,
        result_V_V_full_n,
        result_V_V_write
);

parameter    ap_ST_fsm_state1 = 6'd1;
parameter    ap_ST_fsm_state2 = 6'd2;
parameter    ap_ST_fsm_state3 = 6'd4;
parameter    ap_ST_fsm_state4 = 6'd8;
parameter    ap_ST_fsm_state5 = 6'd16;
parameter    ap_ST_fsm_state6 = 6'd32;

input   ap_clk;
input   ap_rst;
input   ap_start;
output   ap_done;
output   ap_idle;
output   ap_ready;
output  [9:0] tree_V_address0;
output   tree_V_ce0;
input  [23:0] tree_V_q0;
output  [9:0] tree_V_address1;
output   tree_V_ce1;
input  [23:0] tree_V_q1;
input  [10:0] nodo_V;
input  [1:0] relationship_V;
input   fatherSearch;
output  [10:0] result_V_V_din;
input   result_V_V_full_n;
output   result_V_V_write;

reg ap_done;
reg ap_idle;
reg ap_ready;
reg[9:0] tree_V_address0;
reg tree_V_ce0;
reg[9:0] tree_V_address1;
reg tree_V_ce1;
reg[10:0] result_V_V_din;
reg result_V_V_write;

(* fsm_encoding = "none" *) reg   [5:0] ap_CS_fsm;
wire    ap_CS_fsm_state1;
reg    result_V_V_blk_n;
wire   [0:0] and_ln25_fu_219_p2;
wire    ap_CS_fsm_state5;
wire   [0:0] or_ln35_fu_318_p2;
wire    ap_CS_fsm_state6;
reg   [0:0] or_ln36_reg_409;
wire    ap_CS_fsm_state3;
wire   [0:0] or_ln45_fu_292_p2;
wire    ap_CS_fsm_state4;
reg   [0:0] or_ln46_reg_392;
wire    ap_CS_fsm_state2;
reg   [0:0] and_ln25_reg_351;
wire   [0:0] fatherSearch_read_read_fu_60_p2;
wire   [0:0] tmp_fu_259_p3;
wire   [0:0] tmp_1_fu_231_p3;
reg    ap_block_state1;
wire   [0:0] icmp_ln35_1_fu_225_p2;
reg   [0:0] icmp_ln35_1_reg_355;
reg    ap_predicate_op46_write_state2;
reg    ap_block_state2;
wire   [0:0] or_ln46_fu_302_p2;
reg    ap_block_state3;
reg   [10:0] tmp_V_3_reg_396;
wire   [9:0] i_1_fu_307_p2;
reg    ap_block_state4;
wire   [0:0] or_ln36_fu_328_p2;
reg    ap_block_state5;
wire   [10:0] grp_fu_162_p4;
reg   [10:0] tmp_V_2_reg_413;
wire   [9:0] i_fu_333_p2;
reg    ap_block_state6;
reg   [9:0] i1_0_reg_127;
reg   [9:0] i_0_reg_139;
wire   [63:0] zext_ln41_fu_239_p1;
wire   [63:0] zext_ln42_fu_254_p1;
wire   [63:0] zext_ln31_fu_267_p1;
wire   [63:0] zext_ln32_fu_282_p1;
wire   [10:0] grp_fu_151_p4;
wire   [0:0] icmp_ln25_fu_213_p2;
wire   [0:0] and_ln25_fu_219_p1;
wire   [8:0] trunc_ln39_fu_244_p1;
wire   [8:0] or_ln42_fu_248_p2;
wire   [8:0] trunc_ln30_fu_272_p1;
wire   [8:0] or_ln32_fu_276_p2;
wire   [0:0] icmp_ln45_fu_287_p2;
wire   [0:0] icmp_ln46_fu_297_p2;
wire   [10:0] compare_node_min_V_fu_183_p4;
wire   [0:0] icmp_ln35_fu_313_p2;
wire   [10:0] compare_node_max_V_fu_203_p4;
wire   [0:0] icmp_ln36_fu_323_p2;
reg   [5:0] ap_NS_fsm;

// power-on initialization
initial begin
#0 ap_CS_fsm = 6'd1;
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_CS_fsm <= ap_ST_fsm_state1;
    end else begin
        ap_CS_fsm <= ap_NS_fsm;
    end
end

always @ (posedge ap_clk) begin
    if ((~((ap_start == 1'b0) | ((1'd1 == and_ln25_fu_219_p2) & (result_V_V_full_n == 1'b0))) & (fatherSearch_read_read_fu_60_p2 == 1'd0) & (1'd0 == and_ln25_fu_219_p2) & (1'b1 == ap_CS_fsm_state1))) begin
        i1_0_reg_127 <= 10'd0;
    end else if ((~((or_ln46_reg_392 == 1'd0) & (result_V_V_full_n == 1'b0)) & (1'b1 == ap_CS_fsm_state4))) begin
        i1_0_reg_127 <= i_1_fu_307_p2;
    end
end

always @ (posedge ap_clk) begin
    if ((~((ap_start == 1'b0) | ((1'd1 == and_ln25_fu_219_p2) & (result_V_V_full_n == 1'b0))) & (fatherSearch_read_read_fu_60_p2 == 1'd1) & (1'd0 == and_ln25_fu_219_p2) & (1'b1 == ap_CS_fsm_state1))) begin
        i_0_reg_139 <= 10'd0;
    end else if ((~((or_ln36_reg_409 == 1'd0) & (result_V_V_full_n == 1'b0)) & (1'b1 == ap_CS_fsm_state6))) begin
        i_0_reg_139 <= i_fu_333_p2;
    end
end

always @ (posedge ap_clk) begin
    if ((~((ap_start == 1'b0) | ((1'd1 == and_ln25_fu_219_p2) & (result_V_V_full_n == 1'b0))) & (1'b1 == ap_CS_fsm_state1))) begin
        and_ln25_reg_351 <= and_ln25_fu_219_p2;
    end
end

always @ (posedge ap_clk) begin
    if ((~((ap_start == 1'b0) | ((1'd1 == and_ln25_fu_219_p2) & (result_V_V_full_n == 1'b0))) & (1'd0 == and_ln25_fu_219_p2) & (1'b1 == ap_CS_fsm_state1))) begin
        icmp_ln35_1_reg_355 <= icmp_ln35_1_fu_225_p2;
    end
end

always @ (posedge ap_clk) begin
    if ((~((or_ln35_fu_318_p2 == 1'd0) & (result_V_V_full_n == 1'b0)) & (1'b1 == ap_CS_fsm_state5))) begin
        or_ln36_reg_409 <= or_ln36_fu_328_p2;
    end
end

always @ (posedge ap_clk) begin
    if ((~((or_ln45_fu_292_p2 == 1'd0) & (result_V_V_full_n == 1'b0)) & (1'b1 == ap_CS_fsm_state3))) begin
        or_ln46_reg_392 <= or_ln46_fu_302_p2;
    end
end

always @ (posedge ap_clk) begin
    if ((~((or_ln35_fu_318_p2 == 1'd0) & (result_V_V_full_n == 1'b0)) & (or_ln36_fu_328_p2 == 1'd0) & (1'b1 == ap_CS_fsm_state5))) begin
        tmp_V_2_reg_413 <= {{tree_V_q1[23:13]}};
    end
end

always @ (posedge ap_clk) begin
    if ((~((or_ln45_fu_292_p2 == 1'd0) & (result_V_V_full_n == 1'b0)) & (or_ln46_fu_302_p2 == 1'd0) & (1'b1 == ap_CS_fsm_state3))) begin
        tmp_V_3_reg_396 <= {{tree_V_q1[12:2]}};
    end
end

always @ (*) begin
    if (((~((result_V_V_full_n == 1'b0) & (ap_predicate_op46_write_state2 == 1'b1)) & (1'b1 == ap_CS_fsm_state2) & ((1'd1 == and_ln25_reg_351) | (((fatherSearch_read_read_fu_60_p2 == 1'd0) & (tmp_1_fu_231_p3 == 1'd1)) | ((tmp_fu_259_p3 == 1'd1) & (fatherSearch_read_read_fu_60_p2 == 1'd1))))) | ((ap_start == 1'b0) & (1'b1 == ap_CS_fsm_state1)))) begin
        ap_done = 1'b1;
    end else begin
        ap_done = 1'b0;
    end
end

always @ (*) begin
    if (((ap_start == 1'b0) & (1'b1 == ap_CS_fsm_state1))) begin
        ap_idle = 1'b1;
    end else begin
        ap_idle = 1'b0;
    end
end

always @ (*) begin
    if ((~((result_V_V_full_n == 1'b0) & (ap_predicate_op46_write_state2 == 1'b1)) & (1'b1 == ap_CS_fsm_state2) & ((1'd1 == and_ln25_reg_351) | (((fatherSearch_read_read_fu_60_p2 == 1'd0) & (tmp_1_fu_231_p3 == 1'd1)) | ((tmp_fu_259_p3 == 1'd1) & (fatherSearch_read_read_fu_60_p2 == 1'd1)))))) begin
        ap_ready = 1'b1;
    end else begin
        ap_ready = 1'b0;
    end
end

always @ (*) begin
    if ((((1'b1 == ap_CS_fsm_state2) & (((fatherSearch_read_read_fu_60_p2 == 1'd0) & (1'd0 == and_ln25_reg_351) & (tmp_1_fu_231_p3 == 1'd1)) | ((1'd0 == and_ln25_reg_351) & (tmp_fu_259_p3 == 1'd1) & (fatherSearch_read_read_fu_60_p2 == 1'd1)))) | ((or_ln46_reg_392 == 1'd0) & (1'b1 == ap_CS_fsm_state4)) | ((or_ln45_fu_292_p2 == 1'd0) & (1'b1 == ap_CS_fsm_state3)) | ((or_ln36_reg_409 == 1'd0) & (1'b1 == ap_CS_fsm_state6)) | ((or_ln35_fu_318_p2 == 1'd0) & (1'b1 == ap_CS_fsm_state5)) | ((1'd1 == and_ln25_fu_219_p2) & (1'b1 == ap_CS_fsm_state1) & (ap_start == 1'b1)))) begin
        result_V_V_blk_n = result_V_V_full_n;
    end else begin
        result_V_V_blk_n = 1'b1;
    end
end

always @ (*) begin
    if ((~((or_ln36_reg_409 == 1'd0) & (result_V_V_full_n == 1'b0)) & (or_ln36_reg_409 == 1'd0) & (1'b1 == ap_CS_fsm_state6))) begin
        result_V_V_din = tmp_V_2_reg_413;
    end else if ((~((or_ln35_fu_318_p2 == 1'd0) & (result_V_V_full_n == 1'b0)) & (or_ln35_fu_318_p2 == 1'd0) & (1'b1 == ap_CS_fsm_state5))) begin
        result_V_V_din = {{tree_V_q0[23:13]}};
    end else if ((~((or_ln46_reg_392 == 1'd0) & (result_V_V_full_n == 1'b0)) & (or_ln46_reg_392 == 1'd0) & (1'b1 == ap_CS_fsm_state4))) begin
        result_V_V_din = tmp_V_3_reg_396;
    end else if ((~((or_ln45_fu_292_p2 == 1'd0) & (result_V_V_full_n == 1'b0)) & (or_ln45_fu_292_p2 == 1'd0) & (1'b1 == ap_CS_fsm_state3))) begin
        result_V_V_din = {{tree_V_q0[12:2]}};
    end else if (((~((result_V_V_full_n == 1'b0) & (ap_predicate_op46_write_state2 == 1'b1)) & (1'b1 == ap_CS_fsm_state2) & (ap_predicate_op46_write_state2 == 1'b1)) | (~((ap_start == 1'b0) | ((1'd1 == and_ln25_fu_219_p2) & (result_V_V_full_n == 1'b0))) & (1'd1 == and_ln25_fu_219_p2) & (1'b1 == ap_CS_fsm_state1)))) begin
        result_V_V_din = 11'd0;
    end else begin
        result_V_V_din = 'bx;
    end
end

always @ (*) begin
    if (((~((result_V_V_full_n == 1'b0) & (ap_predicate_op46_write_state2 == 1'b1)) & (1'b1 == ap_CS_fsm_state2) & (ap_predicate_op46_write_state2 == 1'b1)) | (~((or_ln46_reg_392 == 1'd0) & (result_V_V_full_n == 1'b0)) & (or_ln46_reg_392 == 1'd0) & (1'b1 == ap_CS_fsm_state4)) | (~((or_ln45_fu_292_p2 == 1'd0) & (result_V_V_full_n == 1'b0)) & (or_ln45_fu_292_p2 == 1'd0) & (1'b1 == ap_CS_fsm_state3)) | (~((or_ln36_reg_409 == 1'd0) & (result_V_V_full_n == 1'b0)) & (or_ln36_reg_409 == 1'd0) & (1'b1 == ap_CS_fsm_state6)) | (~((or_ln35_fu_318_p2 == 1'd0) & (result_V_V_full_n == 1'b0)) & (or_ln35_fu_318_p2 == 1'd0) & (1'b1 == ap_CS_fsm_state5)) | (~((ap_start == 1'b0) | ((1'd1 == and_ln25_fu_219_p2) & (result_V_V_full_n == 1'b0))) & (1'd1 == and_ln25_fu_219_p2) & (1'b1 == ap_CS_fsm_state1)))) begin
        result_V_V_write = 1'b1;
    end else begin
        result_V_V_write = 1'b0;
    end
end

always @ (*) begin
    if (((1'd0 == and_ln25_reg_351) & (1'b1 == ap_CS_fsm_state2))) begin
        if (((tmp_fu_259_p3 == 1'd0) & (fatherSearch_read_read_fu_60_p2 == 1'd1))) begin
            tree_V_address0 = zext_ln31_fu_267_p1;
        end else if (((fatherSearch_read_read_fu_60_p2 == 1'd0) & (tmp_1_fu_231_p3 == 1'd0))) begin
            tree_V_address0 = zext_ln41_fu_239_p1;
        end else begin
            tree_V_address0 = 'bx;
        end
    end else begin
        tree_V_address0 = 'bx;
    end
end

always @ (*) begin
    if (((1'd0 == and_ln25_reg_351) & (1'b1 == ap_CS_fsm_state2))) begin
        if (((tmp_fu_259_p3 == 1'd0) & (fatherSearch_read_read_fu_60_p2 == 1'd1))) begin
            tree_V_address1 = zext_ln32_fu_282_p1;
        end else if (((fatherSearch_read_read_fu_60_p2 == 1'd0) & (tmp_1_fu_231_p3 == 1'd0))) begin
            tree_V_address1 = zext_ln42_fu_254_p1;
        end else begin
            tree_V_address1 = 'bx;
        end
    end else begin
        tree_V_address1 = 'bx;
    end
end

always @ (*) begin
    if (((~((result_V_V_full_n == 1'b0) & (ap_predicate_op46_write_state2 == 1'b1)) & (fatherSearch_read_read_fu_60_p2 == 1'd0) & (1'd0 == and_ln25_reg_351) & (tmp_1_fu_231_p3 == 1'd0) & (1'b1 == ap_CS_fsm_state2)) | (~((result_V_V_full_n == 1'b0) & (ap_predicate_op46_write_state2 == 1'b1)) & (tmp_fu_259_p3 == 1'd0) & (1'd0 == and_ln25_reg_351) & (fatherSearch_read_read_fu_60_p2 == 1'd1) & (1'b1 == ap_CS_fsm_state2)))) begin
        tree_V_ce0 = 1'b1;
    end else begin
        tree_V_ce0 = 1'b0;
    end
end

always @ (*) begin
    if (((~((result_V_V_full_n == 1'b0) & (ap_predicate_op46_write_state2 == 1'b1)) & (fatherSearch_read_read_fu_60_p2 == 1'd0) & (1'd0 == and_ln25_reg_351) & (tmp_1_fu_231_p3 == 1'd0) & (1'b1 == ap_CS_fsm_state2)) | (~((result_V_V_full_n == 1'b0) & (ap_predicate_op46_write_state2 == 1'b1)) & (tmp_fu_259_p3 == 1'd0) & (1'd0 == and_ln25_reg_351) & (fatherSearch_read_read_fu_60_p2 == 1'd1) & (1'b1 == ap_CS_fsm_state2)))) begin
        tree_V_ce1 = 1'b1;
    end else begin
        tree_V_ce1 = 1'b0;
    end
end

always @ (*) begin
    case (ap_CS_fsm)
        ap_ST_fsm_state1 : begin
            if ((~((ap_start == 1'b0) | ((1'd1 == and_ln25_fu_219_p2) & (result_V_V_full_n == 1'b0))) & (1'b1 == ap_CS_fsm_state1))) begin
                ap_NS_fsm = ap_ST_fsm_state2;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state1;
            end
        end
        ap_ST_fsm_state2 : begin
            if ((~((result_V_V_full_n == 1'b0) & (ap_predicate_op46_write_state2 == 1'b1)) & (1'b1 == ap_CS_fsm_state2) & ((1'd1 == and_ln25_reg_351) | (((fatherSearch_read_read_fu_60_p2 == 1'd0) & (tmp_1_fu_231_p3 == 1'd1)) | ((tmp_fu_259_p3 == 1'd1) & (fatherSearch_read_read_fu_60_p2 == 1'd1)))))) begin
                ap_NS_fsm = ap_ST_fsm_state1;
            end else if ((~((result_V_V_full_n == 1'b0) & (ap_predicate_op46_write_state2 == 1'b1)) & (tmp_fu_259_p3 == 1'd0) & (1'd0 == and_ln25_reg_351) & (fatherSearch_read_read_fu_60_p2 == 1'd1) & (1'b1 == ap_CS_fsm_state2))) begin
                ap_NS_fsm = ap_ST_fsm_state5;
            end else if ((~((result_V_V_full_n == 1'b0) & (ap_predicate_op46_write_state2 == 1'b1)) & (fatherSearch_read_read_fu_60_p2 == 1'd0) & (1'd0 == and_ln25_reg_351) & (tmp_1_fu_231_p3 == 1'd0) & (1'b1 == ap_CS_fsm_state2))) begin
                ap_NS_fsm = ap_ST_fsm_state3;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state2;
            end
        end
        ap_ST_fsm_state3 : begin
            if ((~((or_ln45_fu_292_p2 == 1'd0) & (result_V_V_full_n == 1'b0)) & (1'b1 == ap_CS_fsm_state3))) begin
                ap_NS_fsm = ap_ST_fsm_state4;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state3;
            end
        end
        ap_ST_fsm_state4 : begin
            if ((~((or_ln46_reg_392 == 1'd0) & (result_V_V_full_n == 1'b0)) & (1'b1 == ap_CS_fsm_state4))) begin
                ap_NS_fsm = ap_ST_fsm_state2;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state4;
            end
        end
        ap_ST_fsm_state5 : begin
            if ((~((or_ln35_fu_318_p2 == 1'd0) & (result_V_V_full_n == 1'b0)) & (1'b1 == ap_CS_fsm_state5))) begin
                ap_NS_fsm = ap_ST_fsm_state6;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state5;
            end
        end
        ap_ST_fsm_state6 : begin
            if ((~((or_ln36_reg_409 == 1'd0) & (result_V_V_full_n == 1'b0)) & (1'b1 == ap_CS_fsm_state6))) begin
                ap_NS_fsm = ap_ST_fsm_state2;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state6;
            end
        end
        default : begin
            ap_NS_fsm = 'bx;
        end
    endcase
end

assign and_ln25_fu_219_p1 = fatherSearch;

assign and_ln25_fu_219_p2 = (icmp_ln25_fu_213_p2 & and_ln25_fu_219_p1);

assign ap_CS_fsm_state1 = ap_CS_fsm[32'd0];

assign ap_CS_fsm_state2 = ap_CS_fsm[32'd1];

assign ap_CS_fsm_state3 = ap_CS_fsm[32'd2];

assign ap_CS_fsm_state4 = ap_CS_fsm[32'd3];

assign ap_CS_fsm_state5 = ap_CS_fsm[32'd4];

assign ap_CS_fsm_state6 = ap_CS_fsm[32'd5];

always @ (*) begin
    ap_block_state1 = ((ap_start == 1'b0) | ((1'd1 == and_ln25_fu_219_p2) & (result_V_V_full_n == 1'b0)));
end

always @ (*) begin
    ap_block_state2 = ((result_V_V_full_n == 1'b0) & (ap_predicate_op46_write_state2 == 1'b1));
end

always @ (*) begin
    ap_block_state3 = ((or_ln45_fu_292_p2 == 1'd0) & (result_V_V_full_n == 1'b0));
end

always @ (*) begin
    ap_block_state4 = ((or_ln46_reg_392 == 1'd0) & (result_V_V_full_n == 1'b0));
end

always @ (*) begin
    ap_block_state5 = ((or_ln35_fu_318_p2 == 1'd0) & (result_V_V_full_n == 1'b0));
end

always @ (*) begin
    ap_block_state6 = ((or_ln36_reg_409 == 1'd0) & (result_V_V_full_n == 1'b0));
end

always @ (*) begin
    ap_predicate_op46_write_state2 = (((fatherSearch_read_read_fu_60_p2 == 1'd0) & (1'd0 == and_ln25_reg_351) & (tmp_1_fu_231_p3 == 1'd1)) | ((1'd0 == and_ln25_reg_351) & (tmp_fu_259_p3 == 1'd1) & (fatherSearch_read_read_fu_60_p2 == 1'd1)));
end

assign compare_node_max_V_fu_203_p4 = {{tree_V_q1[12:2]}};

assign compare_node_min_V_fu_183_p4 = {{tree_V_q0[12:2]}};

assign fatherSearch_read_read_fu_60_p2 = fatherSearch;

assign grp_fu_151_p4 = {{tree_V_q0[23:13]}};

assign grp_fu_162_p4 = {{tree_V_q1[23:13]}};

assign i_1_fu_307_p2 = (i1_0_reg_127 + 10'd2);

assign i_fu_333_p2 = (i_0_reg_139 + 10'd2);

assign icmp_ln25_fu_213_p2 = ((nodo_V == 11'd1) ? 1'b1 : 1'b0);

assign icmp_ln35_1_fu_225_p2 = ((relationship_V != 2'd0) ? 1'b1 : 1'b0);

assign icmp_ln35_fu_313_p2 = ((compare_node_min_V_fu_183_p4 != nodo_V) ? 1'b1 : 1'b0);

assign icmp_ln36_fu_323_p2 = ((compare_node_max_V_fu_203_p4 != nodo_V) ? 1'b1 : 1'b0);

assign icmp_ln45_fu_287_p2 = ((grp_fu_151_p4 != nodo_V) ? 1'b1 : 1'b0);

assign icmp_ln46_fu_297_p2 = ((grp_fu_162_p4 != nodo_V) ? 1'b1 : 1'b0);

assign or_ln32_fu_276_p2 = (trunc_ln30_fu_272_p1 | 9'd1);

assign or_ln35_fu_318_p2 = (icmp_ln35_fu_313_p2 | icmp_ln35_1_reg_355);

assign or_ln36_fu_328_p2 = (icmp_ln36_fu_323_p2 | icmp_ln35_1_reg_355);

assign or_ln42_fu_248_p2 = (trunc_ln39_fu_244_p1 | 9'd1);

assign or_ln45_fu_292_p2 = (icmp_ln45_fu_287_p2 | icmp_ln35_1_reg_355);

assign or_ln46_fu_302_p2 = (icmp_ln46_fu_297_p2 | icmp_ln35_1_reg_355);

assign tmp_1_fu_231_p3 = i1_0_reg_127[32'd9];

assign tmp_fu_259_p3 = i_0_reg_139[32'd9];

assign trunc_ln30_fu_272_p1 = i_0_reg_139[8:0];

assign trunc_ln39_fu_244_p1 = i1_0_reg_127[8:0];

assign zext_ln31_fu_267_p1 = i_0_reg_139;

assign zext_ln32_fu_282_p1 = or_ln32_fu_276_p2;

assign zext_ln41_fu_239_p1 = i1_0_reg_127;

assign zext_ln42_fu_254_p1 = or_ln42_fu_248_p2;

endmodule //busqueda_cam
