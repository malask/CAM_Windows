-- ==============================================================
-- RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
-- Version: 2019.1
-- Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
-- 
-- ===========================================================

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity busqueda_cam is
port (
    ap_clk : IN STD_LOGIC;
    ap_rst : IN STD_LOGIC;
    ap_start : IN STD_LOGIC;
    ap_done : OUT STD_LOGIC;
    ap_continue : IN STD_LOGIC;
    ap_idle : OUT STD_LOGIC;
    ap_ready : OUT STD_LOGIC;
    tree_V_address0 : OUT STD_LOGIC_VECTOR (9 downto 0);
    tree_V_ce0 : OUT STD_LOGIC;
    tree_V_q0 : IN STD_LOGIC_VECTOR (23 downto 0);
    nodo_V : IN STD_LOGIC_VECTOR (10 downto 0);
    relationship_V : IN STD_LOGIC_VECTOR (1 downto 0);
    fatherSearch : IN STD_LOGIC;
    result_V_V_din : OUT STD_LOGIC_VECTOR (10 downto 0);
    result_V_V_full_n : IN STD_LOGIC;
    result_V_V_write : OUT STD_LOGIC );
end;


architecture behav of busqueda_cam is 
    constant ap_const_logic_1 : STD_LOGIC := '1';
    constant ap_const_logic_0 : STD_LOGIC := '0';
    constant ap_ST_fsm_state1 : STD_LOGIC_VECTOR (2 downto 0) := "001";
    constant ap_ST_fsm_state2 : STD_LOGIC_VECTOR (2 downto 0) := "010";
    constant ap_ST_fsm_state3 : STD_LOGIC_VECTOR (2 downto 0) := "100";
    constant ap_const_lv32_0 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000000";
    constant ap_const_boolean_1 : BOOLEAN := true;
    constant ap_const_lv32_1 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000001";
    constant ap_const_lv1_1 : STD_LOGIC_VECTOR (0 downto 0) := "1";
    constant ap_const_lv1_0 : STD_LOGIC_VECTOR (0 downto 0) := "0";
    constant ap_const_lv32_2 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000010";
    constant ap_const_lv64_0 : STD_LOGIC_VECTOR (63 downto 0) := "0000000000000000000000000000000000000000000000000000000000000000";
    constant ap_const_lv11_0 : STD_LOGIC_VECTOR (10 downto 0) := "00000000000";
    constant ap_const_lv32_D : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000001101";
    constant ap_const_lv32_17 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000010111";
    constant ap_const_lv32_C : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000001100";

    signal ap_done_reg : STD_LOGIC := '0';
    signal ap_CS_fsm : STD_LOGIC_VECTOR (2 downto 0) := "001";
    attribute fsm_encoding : string;
    attribute fsm_encoding of ap_CS_fsm : signal is "none";
    signal ap_CS_fsm_state1 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state1 : signal is "none";
    signal result_V_V_blk_n : STD_LOGIC;
    signal ap_CS_fsm_state2 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state2 : signal is "none";
    signal fatherSearch_read_read_fu_42_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal and_ln61_fu_152_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal and_ln52_fu_130_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal ap_CS_fsm_state3 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state3 : signal is "none";
    signal ap_block_state1 : BOOLEAN;
    signal ap_predicate_op19_write_state2 : BOOLEAN;
    signal ap_predicate_op29_write_state2 : BOOLEAN;
    signal ap_block_state2 : BOOLEAN;
    signal grp_fu_82_p4 : STD_LOGIC_VECTOR (10 downto 0);
    signal trunc_ln647_1_fu_114_p1 : STD_LOGIC_VECTOR (1 downto 0);
    signal icmp_ln879_2_fu_118_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal icmp_ln879_3_fu_124_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal p_Result_7_fu_104_p4 : STD_LOGIC_VECTOR (10 downto 0);
    signal trunc_ln647_fu_136_p1 : STD_LOGIC_VECTOR (1 downto 0);
    signal icmp_ln879_fu_140_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal icmp_ln879_1_fu_146_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal ap_NS_fsm : STD_LOGIC_VECTOR (2 downto 0);


begin




    ap_CS_fsm_assign_proc : process(ap_clk)
    begin
        if (ap_clk'event and ap_clk =  '1') then
            if (ap_rst = '1') then
                ap_CS_fsm <= ap_ST_fsm_state1;
            else
                ap_CS_fsm <= ap_NS_fsm;
            end if;
        end if;
    end process;


    ap_done_reg_assign_proc : process(ap_clk)
    begin
        if (ap_clk'event and ap_clk =  '1') then
            if (ap_rst = '1') then
                ap_done_reg <= ap_const_logic_0;
            else
                if ((ap_continue = ap_const_logic_1)) then 
                    ap_done_reg <= ap_const_logic_0;
                elsif (((result_V_V_full_n = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_state3))) then 
                    ap_done_reg <= ap_const_logic_1;
                end if; 
            end if;
        end if;
    end process;


    ap_NS_fsm_assign_proc : process (ap_start, ap_done_reg, ap_CS_fsm, ap_CS_fsm_state1, result_V_V_full_n, ap_CS_fsm_state2, ap_CS_fsm_state3, ap_predicate_op19_write_state2, ap_predicate_op29_write_state2)
    begin
        case ap_CS_fsm is
            when ap_ST_fsm_state1 => 
                if ((not(((ap_start = ap_const_logic_0) or (ap_done_reg = ap_const_logic_1))) and (ap_const_logic_1 = ap_CS_fsm_state1))) then
                    ap_NS_fsm <= ap_ST_fsm_state2;
                else
                    ap_NS_fsm <= ap_ST_fsm_state1;
                end if;
            when ap_ST_fsm_state2 => 
                if ((not((((result_V_V_full_n = ap_const_logic_0) and (ap_predicate_op29_write_state2 = ap_const_boolean_1)) or ((result_V_V_full_n = ap_const_logic_0) and (ap_predicate_op19_write_state2 = ap_const_boolean_1)))) and (ap_const_logic_1 = ap_CS_fsm_state2))) then
                    ap_NS_fsm <= ap_ST_fsm_state3;
                else
                    ap_NS_fsm <= ap_ST_fsm_state2;
                end if;
            when ap_ST_fsm_state3 => 
                if (((result_V_V_full_n = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_state3))) then
                    ap_NS_fsm <= ap_ST_fsm_state1;
                else
                    ap_NS_fsm <= ap_ST_fsm_state3;
                end if;
            when others =>  
                ap_NS_fsm <= "XXX";
        end case;
    end process;
    and_ln52_fu_130_p2 <= (icmp_ln879_3_fu_124_p2 and icmp_ln879_2_fu_118_p2);
    and_ln61_fu_152_p2 <= (icmp_ln879_fu_140_p2 and icmp_ln879_1_fu_146_p2);
    ap_CS_fsm_state1 <= ap_CS_fsm(0);
    ap_CS_fsm_state2 <= ap_CS_fsm(1);
    ap_CS_fsm_state3 <= ap_CS_fsm(2);

    ap_block_state1_assign_proc : process(ap_start, ap_done_reg)
    begin
                ap_block_state1 <= ((ap_start = ap_const_logic_0) or (ap_done_reg = ap_const_logic_1));
    end process;


    ap_block_state2_assign_proc : process(result_V_V_full_n, ap_predicate_op19_write_state2, ap_predicate_op29_write_state2)
    begin
                ap_block_state2 <= (((result_V_V_full_n = ap_const_logic_0) and (ap_predicate_op29_write_state2 = ap_const_boolean_1)) or ((result_V_V_full_n = ap_const_logic_0) and (ap_predicate_op19_write_state2 = ap_const_boolean_1)));
    end process;


    ap_done_assign_proc : process(ap_done_reg, result_V_V_full_n, ap_CS_fsm_state3)
    begin
        if (((result_V_V_full_n = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_state3))) then 
            ap_done <= ap_const_logic_1;
        else 
            ap_done <= ap_done_reg;
        end if; 
    end process;


    ap_idle_assign_proc : process(ap_start, ap_CS_fsm_state1)
    begin
        if (((ap_start = ap_const_logic_0) and (ap_const_logic_1 = ap_CS_fsm_state1))) then 
            ap_idle <= ap_const_logic_1;
        else 
            ap_idle <= ap_const_logic_0;
        end if; 
    end process;


    ap_predicate_op19_write_state2_assign_proc : process(fatherSearch_read_read_fu_42_p2, and_ln52_fu_130_p2)
    begin
                ap_predicate_op19_write_state2 <= ((ap_const_lv1_1 = and_ln52_fu_130_p2) and (fatherSearch_read_read_fu_42_p2 = ap_const_lv1_0));
    end process;


    ap_predicate_op29_write_state2_assign_proc : process(fatherSearch_read_read_fu_42_p2, and_ln61_fu_152_p2)
    begin
                ap_predicate_op29_write_state2 <= ((ap_const_lv1_1 = and_ln61_fu_152_p2) and (fatherSearch_read_read_fu_42_p2 = ap_const_lv1_1));
    end process;


    ap_ready_assign_proc : process(result_V_V_full_n, ap_CS_fsm_state3)
    begin
        if (((result_V_V_full_n = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_state3))) then 
            ap_ready <= ap_const_logic_1;
        else 
            ap_ready <= ap_const_logic_0;
        end if; 
    end process;

    fatherSearch_read_read_fu_42_p2 <= (0=>fatherSearch, others=>'-');
    grp_fu_82_p4 <= tree_V_q0(23 downto 13);
    icmp_ln879_1_fu_146_p2 <= "1" when (trunc_ln647_fu_136_p1 = relationship_V) else "0";
    icmp_ln879_2_fu_118_p2 <= "1" when (grp_fu_82_p4 = nodo_V) else "0";
    icmp_ln879_3_fu_124_p2 <= "1" when (trunc_ln647_1_fu_114_p1 = relationship_V) else "0";
    icmp_ln879_fu_140_p2 <= "1" when (p_Result_7_fu_104_p4 = nodo_V) else "0";
    p_Result_7_fu_104_p4 <= tree_V_q0(12 downto 2);

    result_V_V_blk_n_assign_proc : process(result_V_V_full_n, ap_CS_fsm_state2, fatherSearch_read_read_fu_42_p2, and_ln61_fu_152_p2, and_ln52_fu_130_p2, ap_CS_fsm_state3)
    begin
        if (((ap_const_logic_1 = ap_CS_fsm_state3) or ((ap_const_lv1_1 = and_ln52_fu_130_p2) and (fatherSearch_read_read_fu_42_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state2)) or ((ap_const_lv1_1 = and_ln61_fu_152_p2) and (fatherSearch_read_read_fu_42_p2 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_state2)))) then 
            result_V_V_blk_n <= result_V_V_full_n;
        else 
            result_V_V_blk_n <= ap_const_logic_1;
        end if; 
    end process;


    result_V_V_din_assign_proc : process(tree_V_q0, result_V_V_full_n, ap_CS_fsm_state2, ap_CS_fsm_state3, ap_predicate_op19_write_state2, ap_predicate_op29_write_state2)
    begin
        if (((result_V_V_full_n = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_state3))) then 
            result_V_V_din <= ap_const_lv11_0;
        elsif ((not((((result_V_V_full_n = ap_const_logic_0) and (ap_predicate_op29_write_state2 = ap_const_boolean_1)) or ((result_V_V_full_n = ap_const_logic_0) and (ap_predicate_op19_write_state2 = ap_const_boolean_1)))) and (ap_predicate_op29_write_state2 = ap_const_boolean_1) and (ap_const_logic_1 = ap_CS_fsm_state2))) then 
            result_V_V_din <= tree_V_q0(23 downto 13);
        elsif ((not((((result_V_V_full_n = ap_const_logic_0) and (ap_predicate_op29_write_state2 = ap_const_boolean_1)) or ((result_V_V_full_n = ap_const_logic_0) and (ap_predicate_op19_write_state2 = ap_const_boolean_1)))) and (ap_predicate_op19_write_state2 = ap_const_boolean_1) and (ap_const_logic_1 = ap_CS_fsm_state2))) then 
            result_V_V_din <= tree_V_q0(12 downto 2);
        else 
            result_V_V_din <= "XXXXXXXXXXX";
        end if; 
    end process;


    result_V_V_write_assign_proc : process(result_V_V_full_n, ap_CS_fsm_state2, ap_CS_fsm_state3, ap_predicate_op19_write_state2, ap_predicate_op29_write_state2)
    begin
        if ((((result_V_V_full_n = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_state3)) or (not((((result_V_V_full_n = ap_const_logic_0) and (ap_predicate_op29_write_state2 = ap_const_boolean_1)) or ((result_V_V_full_n = ap_const_logic_0) and (ap_predicate_op19_write_state2 = ap_const_boolean_1)))) and (ap_predicate_op29_write_state2 = ap_const_boolean_1) and (ap_const_logic_1 = ap_CS_fsm_state2)) or (not((((result_V_V_full_n = ap_const_logic_0) and (ap_predicate_op29_write_state2 = ap_const_boolean_1)) or ((result_V_V_full_n = ap_const_logic_0) and (ap_predicate_op19_write_state2 = ap_const_boolean_1)))) and (ap_predicate_op19_write_state2 = ap_const_boolean_1) and (ap_const_logic_1 = ap_CS_fsm_state2)))) then 
            result_V_V_write <= ap_const_logic_1;
        else 
            result_V_V_write <= ap_const_logic_0;
        end if; 
    end process;

    tree_V_address0 <= ap_const_lv64_0(10 - 1 downto 0);

    tree_V_ce0_assign_proc : process(ap_start, ap_done_reg, ap_CS_fsm_state1)
    begin
        if ((not(((ap_start = ap_const_logic_0) or (ap_done_reg = ap_const_logic_1))) and (ap_const_logic_1 = ap_CS_fsm_state1))) then 
            tree_V_ce0 <= ap_const_logic_1;
        else 
            tree_V_ce0 <= ap_const_logic_0;
        end if; 
    end process;

    trunc_ln647_1_fu_114_p1 <= tree_V_q0(2 - 1 downto 0);
    trunc_ln647_fu_136_p1 <= tree_V_q0(2 - 1 downto 0);
end behav;
