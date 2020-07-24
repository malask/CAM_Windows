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
        start_full_n,
        ap_done,
        ap_continue,
        ap_idle,
        ap_ready,
        start_out,
        start_write,
        tree_V_address0,
        tree_V_ce0,
        tree_V_q0,
        nodo_V_dout,
        nodo_V_empty_n,
        nodo_V_read,
        relationship_V_dout,
        relationship_V_empty_n,
        relationship_V_read,
        fatherSearch_dout,
        fatherSearch_empty_n,
        fatherSearch_read,
        in1_V_V_din,
        in1_V_V_full_n,
        in1_V_V_write,
        in2_V_V_din,
        in2_V_V_full_n,
        in2_V_V_write
);

parameter    ap_ST_fsm_state1 = 5'd1;
parameter    ap_ST_fsm_state2 = 5'd2;
parameter    ap_ST_fsm_state3 = 5'd4;
parameter    ap_ST_fsm_state4 = 5'd8;
parameter    ap_ST_fsm_state5 = 5'd16;

input   ap_clk;
input   ap_rst;
input   ap_start;
input   start_full_n;
output   ap_done;
input   ap_continue;
output   ap_idle;
output   ap_ready;
output   start_out;
output   start_write;
output  [9:0] tree_V_address0;
output   tree_V_ce0;
input  [23:0] tree_V_q0;
input  [10:0] nodo_V_dout;
input   nodo_V_empty_n;
output   nodo_V_read;
input  [1:0] relationship_V_dout;
input   relationship_V_empty_n;
output   relationship_V_read;
input  [0:0] fatherSearch_dout;
input   fatherSearch_empty_n;
output   fatherSearch_read;
output  [10:0] in1_V_V_din;
input   in1_V_V_full_n;
output   in1_V_V_write;
output  [10:0] in2_V_V_din;
input   in2_V_V_full_n;
output   in2_V_V_write;

reg ap_done;
reg ap_idle;
reg start_write;
reg[9:0] tree_V_address0;
reg tree_V_ce0;
reg nodo_V_read;
reg relationship_V_read;
reg fatherSearch_read;
reg[10:0] in1_V_V_din;
reg in1_V_V_write;
reg[10:0] in2_V_V_din;
reg in2_V_V_write;

reg    real_start;
reg    start_once_reg;
reg    ap_done_reg;
(* fsm_encoding = "none" *) reg   [4:0] ap_CS_fsm;
wire    ap_CS_fsm_state1;
reg    internal_ap_ready;
reg    nodo_V_blk_n;
wire    ap_CS_fsm_state2;
reg    relationship_V_blk_n;
reg    fatherSearch_blk_n;
reg    in1_V_V_blk_n;
wire    ap_CS_fsm_state4;
wire   [0:0] and_ln77_fu_231_p2;
wire    ap_CS_fsm_state3;
wire   [0:0] and_ln62_fu_192_p2;
wire    ap_CS_fsm_state5;
reg    in2_V_V_blk_n;
wire   [0:0] and_ln80_fu_247_p2;
wire   [0:0] and_ln65_fu_208_p2;
reg    ap_block_state1;
reg   [10:0] nodo_V_read_reg_258;
reg    ap_block_state2;
reg   [1:0] relationship_V_read_reg_266;
reg   [23:0] tree_V_load_reg_277;
wire   [0:0] fatherSearch_read_read_fu_60_p2;
wire   [9:0] tree_V_addr_1_gep_fu_105_p3;
reg    ap_block_state3;
wire   [10:0] grp_fu_114_p4;
reg    ap_block_state4;
reg    ap_block_state5;
wire   [10:0] grp_fu_124_p4;
wire   [1:0] trunc_ln647_2_fu_175_p1;
wire   [0:0] icmp_ln879_3_fu_182_p2;
wire   [0:0] icmp_ln879_4_fu_187_p2;
wire   [1:0] trunc_ln647_3_fu_178_p1;
wire   [0:0] icmp_ln879_7_fu_198_p2;
wire   [0:0] icmp_ln879_8_fu_203_p2;
wire   [10:0] p_Result_15_i_i_fu_145_p4;
wire   [1:0] trunc_ln647_fu_214_p1;
wire   [0:0] icmp_ln879_fu_221_p2;
wire   [0:0] icmp_ln879_2_fu_226_p2;
wire   [10:0] p_Result_16_i_i_fu_165_p4;
wire   [1:0] trunc_ln647_1_fu_217_p1;
wire   [0:0] icmp_ln879_5_fu_237_p2;
wire   [0:0] icmp_ln879_6_fu_242_p2;
reg   [4:0] ap_NS_fsm;

// power-on initialization
initial begin
#0 start_once_reg = 1'b0;
#0 ap_done_reg = 1'b0;
#0 ap_CS_fsm = 5'd1;
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_CS_fsm <= ap_ST_fsm_state1;
    end else begin
        ap_CS_fsm <= ap_NS_fsm;
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_done_reg <= 1'b0;
    end else begin
        if ((ap_continue == 1'b1)) begin
            ap_done_reg <= 1'b0;
        end else if ((~((in2_V_V_full_n == 1'b0) | (in1_V_V_full_n == 1'b0)) & (1'b1 == ap_CS_fsm_state5))) begin
            ap_done_reg <= 1'b1;
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        start_once_reg <= 1'b0;
    end else begin
        if (((internal_ap_ready == 1'b0) & (real_start == 1'b1))) begin
            start_once_reg <= 1'b1;
        end else if ((internal_ap_ready == 1'b1)) begin
            start_once_reg <= 1'b0;
        end
    end
end

always @ (posedge ap_clk) begin
    if ((~((fatherSearch_empty_n == 1'b0) | (relationship_V_empty_n == 1'b0) | (nodo_V_empty_n == 1'b0)) & (1'b1 == ap_CS_fsm_state2))) begin
        nodo_V_read_reg_258 <= nodo_V_dout;
        relationship_V_read_reg_266 <= relationship_V_dout;
        tree_V_load_reg_277 <= tree_V_q0;
    end
end

always @ (*) begin
    if ((~((in2_V_V_full_n == 1'b0) | (in1_V_V_full_n == 1'b0)) & (1'b1 == ap_CS_fsm_state5))) begin
        ap_done = 1'b1;
    end else begin
        ap_done = ap_done_reg;
    end
end

always @ (*) begin
    if (((real_start == 1'b0) & (1'b1 == ap_CS_fsm_state1))) begin
        ap_idle = 1'b1;
    end else begin
        ap_idle = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state2)) begin
        fatherSearch_blk_n = fatherSearch_empty_n;
    end else begin
        fatherSearch_blk_n = 1'b1;
    end
end

always @ (*) begin
    if ((~((fatherSearch_empty_n == 1'b0) | (relationship_V_empty_n == 1'b0) | (nodo_V_empty_n == 1'b0)) & (1'b1 == ap_CS_fsm_state2))) begin
        fatherSearch_read = 1'b1;
    end else begin
        fatherSearch_read = 1'b0;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state5) | ((1'd1 == and_ln62_fu_192_p2) & (1'b1 == ap_CS_fsm_state3)) | ((1'd1 == and_ln77_fu_231_p2) & (1'b1 == ap_CS_fsm_state4)))) begin
        in1_V_V_blk_n = in1_V_V_full_n;
    end else begin
        in1_V_V_blk_n = 1'b1;
    end
end

always @ (*) begin
    if ((~((in2_V_V_full_n == 1'b0) | (in1_V_V_full_n == 1'b0)) & (1'b1 == ap_CS_fsm_state5))) begin
        in1_V_V_din = 11'd0;
    end else if ((~(((1'd1 == and_ln77_fu_231_p2) & (in1_V_V_full_n == 1'b0)) | ((1'd1 == and_ln80_fu_247_p2) & (in2_V_V_full_n == 1'b0))) & (1'd1 == and_ln77_fu_231_p2) & (1'b1 == ap_CS_fsm_state4))) begin
        in1_V_V_din = {{tree_V_load_reg_277[23:13]}};
    end else if ((~(((1'd1 == and_ln62_fu_192_p2) & (in1_V_V_full_n == 1'b0)) | ((1'd1 == and_ln65_fu_208_p2) & (in2_V_V_full_n == 1'b0))) & (1'd1 == and_ln62_fu_192_p2) & (1'b1 == ap_CS_fsm_state3))) begin
        in1_V_V_din = {{tree_V_load_reg_277[12:2]}};
    end else begin
        in1_V_V_din = 'bx;
    end
end

always @ (*) begin
    if (((~((in2_V_V_full_n == 1'b0) | (in1_V_V_full_n == 1'b0)) & (1'b1 == ap_CS_fsm_state5)) | (~(((1'd1 == and_ln62_fu_192_p2) & (in1_V_V_full_n == 1'b0)) | ((1'd1 == and_ln65_fu_208_p2) & (in2_V_V_full_n == 1'b0))) & (1'd1 == and_ln62_fu_192_p2) & (1'b1 == ap_CS_fsm_state3)) | (~(((1'd1 == and_ln77_fu_231_p2) & (in1_V_V_full_n == 1'b0)) | ((1'd1 == and_ln80_fu_247_p2) & (in2_V_V_full_n == 1'b0))) & (1'd1 == and_ln77_fu_231_p2) & (1'b1 == ap_CS_fsm_state4)))) begin
        in1_V_V_write = 1'b1;
    end else begin
        in1_V_V_write = 1'b0;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state5) | ((1'd1 == and_ln65_fu_208_p2) & (1'b1 == ap_CS_fsm_state3)) | ((1'd1 == and_ln80_fu_247_p2) & (1'b1 == ap_CS_fsm_state4)))) begin
        in2_V_V_blk_n = in2_V_V_full_n;
    end else begin
        in2_V_V_blk_n = 1'b1;
    end
end

always @ (*) begin
    if ((~((in2_V_V_full_n == 1'b0) | (in1_V_V_full_n == 1'b0)) & (1'b1 == ap_CS_fsm_state5))) begin
        in2_V_V_din = 11'd0;
    end else if ((~(((1'd1 == and_ln77_fu_231_p2) & (in1_V_V_full_n == 1'b0)) | ((1'd1 == and_ln80_fu_247_p2) & (in2_V_V_full_n == 1'b0))) & (1'd1 == and_ln80_fu_247_p2) & (1'b1 == ap_CS_fsm_state4))) begin
        in2_V_V_din = {{tree_V_q0[23:13]}};
    end else if ((~(((1'd1 == and_ln62_fu_192_p2) & (in1_V_V_full_n == 1'b0)) | ((1'd1 == and_ln65_fu_208_p2) & (in2_V_V_full_n == 1'b0))) & (1'd1 == and_ln65_fu_208_p2) & (1'b1 == ap_CS_fsm_state3))) begin
        in2_V_V_din = {{tree_V_q0[12:2]}};
    end else begin
        in2_V_V_din = 'bx;
    end
end

always @ (*) begin
    if (((~((in2_V_V_full_n == 1'b0) | (in1_V_V_full_n == 1'b0)) & (1'b1 == ap_CS_fsm_state5)) | (~(((1'd1 == and_ln62_fu_192_p2) & (in1_V_V_full_n == 1'b0)) | ((1'd1 == and_ln65_fu_208_p2) & (in2_V_V_full_n == 1'b0))) & (1'd1 == and_ln65_fu_208_p2) & (1'b1 == ap_CS_fsm_state3)) | (~(((1'd1 == and_ln77_fu_231_p2) & (in1_V_V_full_n == 1'b0)) | ((1'd1 == and_ln80_fu_247_p2) & (in2_V_V_full_n == 1'b0))) & (1'd1 == and_ln80_fu_247_p2) & (1'b1 == ap_CS_fsm_state4)))) begin
        in2_V_V_write = 1'b1;
    end else begin
        in2_V_V_write = 1'b0;
    end
end

always @ (*) begin
    if ((~((in2_V_V_full_n == 1'b0) | (in1_V_V_full_n == 1'b0)) & (1'b1 == ap_CS_fsm_state5))) begin
        internal_ap_ready = 1'b1;
    end else begin
        internal_ap_ready = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state2)) begin
        nodo_V_blk_n = nodo_V_empty_n;
    end else begin
        nodo_V_blk_n = 1'b1;
    end
end

always @ (*) begin
    if ((~((fatherSearch_empty_n == 1'b0) | (relationship_V_empty_n == 1'b0) | (nodo_V_empty_n == 1'b0)) & (1'b1 == ap_CS_fsm_state2))) begin
        nodo_V_read = 1'b1;
    end else begin
        nodo_V_read = 1'b0;
    end
end

always @ (*) begin
    if (((start_once_reg == 1'b0) & (start_full_n == 1'b0))) begin
        real_start = 1'b0;
    end else begin
        real_start = ap_start;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state2)) begin
        relationship_V_blk_n = relationship_V_empty_n;
    end else begin
        relationship_V_blk_n = 1'b1;
    end
end

always @ (*) begin
    if ((~((fatherSearch_empty_n == 1'b0) | (relationship_V_empty_n == 1'b0) | (nodo_V_empty_n == 1'b0)) & (1'b1 == ap_CS_fsm_state2))) begin
        relationship_V_read = 1'b1;
    end else begin
        relationship_V_read = 1'b0;
    end
end

always @ (*) begin
    if (((start_once_reg == 1'b0) & (real_start == 1'b1))) begin
        start_write = 1'b1;
    end else begin
        start_write = 1'b0;
    end
end

always @ (*) begin
    if (((fatherSearch_read_read_fu_60_p2 == 1'd1) & (1'b1 == ap_CS_fsm_state2))) begin
        tree_V_address0 = tree_V_addr_1_gep_fu_105_p3;
    end else if (((1'b1 == ap_CS_fsm_state2) & (fatherSearch_read_read_fu_60_p2 == 1'd0))) begin
        tree_V_address0 = 64'd1;
    end else if ((1'b1 == ap_CS_fsm_state1)) begin
        tree_V_address0 = 64'd0;
    end else begin
        tree_V_address0 = 'bx;
    end
end

always @ (*) begin
    if (((~((fatherSearch_empty_n == 1'b0) | (relationship_V_empty_n == 1'b0) | (nodo_V_empty_n == 1'b0)) & (fatherSearch_read_read_fu_60_p2 == 1'd1) & (1'b1 == ap_CS_fsm_state2)) | (~((fatherSearch_empty_n == 1'b0) | (relationship_V_empty_n == 1'b0) | (nodo_V_empty_n == 1'b0)) & (1'b1 == ap_CS_fsm_state2) & (fatherSearch_read_read_fu_60_p2 == 1'd0)) | (~((real_start == 1'b0) | (ap_done_reg == 1'b1)) & (1'b1 == ap_CS_fsm_state1)))) begin
        tree_V_ce0 = 1'b1;
    end else begin
        tree_V_ce0 = 1'b0;
    end
end

always @ (*) begin
    case (ap_CS_fsm)
        ap_ST_fsm_state1 : begin
            if ((~((real_start == 1'b0) | (ap_done_reg == 1'b1)) & (1'b1 == ap_CS_fsm_state1))) begin
                ap_NS_fsm = ap_ST_fsm_state2;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state1;
            end
        end
        ap_ST_fsm_state2 : begin
            if ((~((fatherSearch_empty_n == 1'b0) | (relationship_V_empty_n == 1'b0) | (nodo_V_empty_n == 1'b0)) & (fatherSearch_read_read_fu_60_p2 == 1'd1) & (1'b1 == ap_CS_fsm_state2))) begin
                ap_NS_fsm = ap_ST_fsm_state4;
            end else if ((~((fatherSearch_empty_n == 1'b0) | (relationship_V_empty_n == 1'b0) | (nodo_V_empty_n == 1'b0)) & (1'b1 == ap_CS_fsm_state2) & (fatherSearch_read_read_fu_60_p2 == 1'd0))) begin
                ap_NS_fsm = ap_ST_fsm_state3;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state2;
            end
        end
        ap_ST_fsm_state3 : begin
            if ((~(((1'd1 == and_ln62_fu_192_p2) & (in1_V_V_full_n == 1'b0)) | ((1'd1 == and_ln65_fu_208_p2) & (in2_V_V_full_n == 1'b0))) & (1'b1 == ap_CS_fsm_state3))) begin
                ap_NS_fsm = ap_ST_fsm_state5;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state3;
            end
        end
        ap_ST_fsm_state4 : begin
            if ((~(((1'd1 == and_ln77_fu_231_p2) & (in1_V_V_full_n == 1'b0)) | ((1'd1 == and_ln80_fu_247_p2) & (in2_V_V_full_n == 1'b0))) & (1'b1 == ap_CS_fsm_state4))) begin
                ap_NS_fsm = ap_ST_fsm_state5;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state4;
            end
        end
        ap_ST_fsm_state5 : begin
            if ((~((in2_V_V_full_n == 1'b0) | (in1_V_V_full_n == 1'b0)) & (1'b1 == ap_CS_fsm_state5))) begin
                ap_NS_fsm = ap_ST_fsm_state1;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state5;
            end
        end
        default : begin
            ap_NS_fsm = 'bx;
        end
    endcase
end

assign and_ln62_fu_192_p2 = (icmp_ln879_4_fu_187_p2 & icmp_ln879_3_fu_182_p2);

assign and_ln65_fu_208_p2 = (icmp_ln879_8_fu_203_p2 & icmp_ln879_7_fu_198_p2);

assign and_ln77_fu_231_p2 = (icmp_ln879_fu_221_p2 & icmp_ln879_2_fu_226_p2);

assign and_ln80_fu_247_p2 = (icmp_ln879_6_fu_242_p2 & icmp_ln879_5_fu_237_p2);

assign ap_CS_fsm_state1 = ap_CS_fsm[32'd0];

assign ap_CS_fsm_state2 = ap_CS_fsm[32'd1];

assign ap_CS_fsm_state3 = ap_CS_fsm[32'd2];

assign ap_CS_fsm_state4 = ap_CS_fsm[32'd3];

assign ap_CS_fsm_state5 = ap_CS_fsm[32'd4];

always @ (*) begin
    ap_block_state1 = ((real_start == 1'b0) | (ap_done_reg == 1'b1));
end

always @ (*) begin
    ap_block_state2 = ((fatherSearch_empty_n == 1'b0) | (relationship_V_empty_n == 1'b0) | (nodo_V_empty_n == 1'b0));
end

always @ (*) begin
    ap_block_state3 = (((1'd1 == and_ln62_fu_192_p2) & (in1_V_V_full_n == 1'b0)) | ((1'd1 == and_ln65_fu_208_p2) & (in2_V_V_full_n == 1'b0)));
end

always @ (*) begin
    ap_block_state4 = (((1'd1 == and_ln77_fu_231_p2) & (in1_V_V_full_n == 1'b0)) | ((1'd1 == and_ln80_fu_247_p2) & (in2_V_V_full_n == 1'b0)));
end

always @ (*) begin
    ap_block_state5 = ((in2_V_V_full_n == 1'b0) | (in1_V_V_full_n == 1'b0));
end

assign ap_ready = internal_ap_ready;

assign fatherSearch_read_read_fu_60_p2 = fatherSearch_dout;

assign grp_fu_114_p4 = {{tree_V_load_reg_277[23:13]}};

assign grp_fu_124_p4 = {{tree_V_q0[23:13]}};

assign icmp_ln879_2_fu_226_p2 = ((trunc_ln647_fu_214_p1 == relationship_V_read_reg_266) ? 1'b1 : 1'b0);

assign icmp_ln879_3_fu_182_p2 = ((grp_fu_114_p4 == nodo_V_read_reg_258) ? 1'b1 : 1'b0);

assign icmp_ln879_4_fu_187_p2 = ((trunc_ln647_2_fu_175_p1 == relationship_V_read_reg_266) ? 1'b1 : 1'b0);

assign icmp_ln879_5_fu_237_p2 = ((p_Result_16_i_i_fu_165_p4 == nodo_V_read_reg_258) ? 1'b1 : 1'b0);

assign icmp_ln879_6_fu_242_p2 = ((trunc_ln647_1_fu_217_p1 == relationship_V_read_reg_266) ? 1'b1 : 1'b0);

assign icmp_ln879_7_fu_198_p2 = ((grp_fu_124_p4 == nodo_V_read_reg_258) ? 1'b1 : 1'b0);

assign icmp_ln879_8_fu_203_p2 = ((trunc_ln647_3_fu_178_p1 == relationship_V_read_reg_266) ? 1'b1 : 1'b0);

assign icmp_ln879_fu_221_p2 = ((p_Result_15_i_i_fu_145_p4 == nodo_V_read_reg_258) ? 1'b1 : 1'b0);

assign p_Result_15_i_i_fu_145_p4 = {{tree_V_load_reg_277[12:2]}};

assign p_Result_16_i_i_fu_165_p4 = {{tree_V_q0[12:2]}};

assign start_out = real_start;

assign tree_V_addr_1_gep_fu_105_p3 = 64'd1;

assign trunc_ln647_1_fu_217_p1 = tree_V_q0[1:0];

assign trunc_ln647_2_fu_175_p1 = tree_V_load_reg_277[1:0];

assign trunc_ln647_3_fu_178_p1 = tree_V_q0[1:0];

assign trunc_ln647_fu_214_p1 = tree_V_load_reg_277[1:0];

endmodule //busqueda_cam
