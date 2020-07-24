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
    constant ap_ST_fsm_state1 : STD_LOGIC_VECTOR (3 downto 0) := "0001";
    constant ap_ST_fsm_pp0_stage0 : STD_LOGIC_VECTOR (3 downto 0) := "0010";
    constant ap_ST_fsm_state5 : STD_LOGIC_VECTOR (3 downto 0) := "0100";
    constant ap_ST_fsm_pp1_stage0 : STD_LOGIC_VECTOR (3 downto 0) := "1000";
    constant ap_const_boolean_1 : BOOLEAN := true;
    constant ap_const_lv32_0 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000000";
    constant ap_const_boolean_0 : BOOLEAN := false;
    constant ap_const_lv1_1 : STD_LOGIC_VECTOR (0 downto 0) := "1";
    constant ap_const_lv32_2 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000010";
    constant ap_const_lv32_1 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000001";
    constant ap_const_lv1_0 : STD_LOGIC_VECTOR (0 downto 0) := "0";
    constant ap_const_lv32_3 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000011";
    constant ap_const_lv11_0 : STD_LOGIC_VECTOR (10 downto 0) := "00000000000";
    constant ap_const_lv32_D : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000001101";
    constant ap_const_lv32_17 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000010111";
    constant ap_const_lv32_C : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000001100";
    constant ap_const_lv11_400 : STD_LOGIC_VECTOR (10 downto 0) := "10000000000";
    constant ap_const_lv11_1 : STD_LOGIC_VECTOR (10 downto 0) := "00000000001";

    signal ap_CS_fsm : STD_LOGIC_VECTOR (3 downto 0) := "0001";
    attribute fsm_encoding : string;
    attribute fsm_encoding of ap_CS_fsm : signal is "none";
    signal ap_CS_fsm_state1 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state1 : signal is "none";
    signal result_V_V_blk_n : STD_LOGIC;
    signal ap_enable_reg_pp1_iter2 : STD_LOGIC := '0';
    signal ap_block_pp1_stage0 : BOOLEAN;
    signal and_ln22_reg_302 : STD_LOGIC_VECTOR (0 downto 0);
    signal ap_enable_reg_pp0_iter2 : STD_LOGIC := '0';
    signal ap_block_pp0_stage0 : BOOLEAN;
    signal and_ln30_reg_279 : STD_LOGIC_VECTOR (0 downto 0);
    signal ap_CS_fsm_state5 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state5 : signal is "none";
    signal i1_0_reg_123 : STD_LOGIC_VECTOR (10 downto 0);
    signal i_0_reg_134 : STD_LOGIC_VECTOR (10 downto 0);
    signal fatherSearch_read_read_fu_76_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal icmp_ln25_fu_175_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal ap_CS_fsm_pp0_stage0 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_pp0_stage0 : signal is "none";
    signal ap_block_state2_pp0_stage0_iter0 : BOOLEAN;
    signal ap_block_state3_pp0_stage0_iter1 : BOOLEAN;
    signal ap_block_state4_pp0_stage0_iter2 : BOOLEAN;
    signal ap_block_pp0_stage0_11001 : BOOLEAN;
    signal i_1_fu_181_p2 : STD_LOGIC_VECTOR (10 downto 0);
    signal ap_enable_reg_pp0_iter0 : STD_LOGIC := '0';
    signal and_ln30_fu_206_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal tmp_V_1_reg_283 : STD_LOGIC_VECTOR (10 downto 0);
    signal icmp_ln17_fu_212_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal ap_CS_fsm_pp1_stage0 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_pp1_stage0 : signal is "none";
    signal ap_block_state6_pp1_stage0_iter0 : BOOLEAN;
    signal ap_block_state7_pp1_stage0_iter1 : BOOLEAN;
    signal ap_block_state8_pp1_stage0_iter2 : BOOLEAN;
    signal ap_block_pp1_stage0_11001 : BOOLEAN;
    signal i_fu_218_p2 : STD_LOGIC_VECTOR (10 downto 0);
    signal ap_enable_reg_pp1_iter0 : STD_LOGIC := '0';
    signal and_ln22_fu_243_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal grp_fu_145_p4 : STD_LOGIC_VECTOR (10 downto 0);
    signal tmp_V_reg_306 : STD_LOGIC_VECTOR (10 downto 0);
    signal ap_enable_reg_pp1_iter1 : STD_LOGIC := '0';
    signal ap_block_pp0_stage0_subdone : BOOLEAN;
    signal ap_condition_pp0_exit_iter0_state2 : STD_LOGIC;
    signal ap_enable_reg_pp0_iter1 : STD_LOGIC := '0';
    signal ap_block_pp1_stage0_subdone : BOOLEAN;
    signal ap_condition_pp1_exit_iter0_state6 : STD_LOGIC;
    signal zext_ln27_fu_187_p1 : STD_LOGIC_VECTOR (63 downto 0);
    signal zext_ln19_fu_224_p1 : STD_LOGIC_VECTOR (63 downto 0);
    signal ap_block_pp0_stage0_01001 : BOOLEAN;
    signal ap_block_pp1_stage0_01001 : BOOLEAN;
    signal node_relation_V_1_fu_192_p1 : STD_LOGIC_VECTOR (1 downto 0);
    signal icmp_ln879_1_fu_196_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal icmp_ln879_3_fu_201_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal compare_node_V_fu_165_p4 : STD_LOGIC_VECTOR (10 downto 0);
    signal node_relation_V_fu_229_p1 : STD_LOGIC_VECTOR (1 downto 0);
    signal icmp_ln879_fu_233_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal icmp_ln879_2_fu_238_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal ap_NS_fsm : STD_LOGIC_VECTOR (3 downto 0);
    signal ap_idle_pp0 : STD_LOGIC;
    signal ap_enable_pp0 : STD_LOGIC;
    signal ap_idle_pp1 : STD_LOGIC;
    signal ap_enable_pp1 : STD_LOGIC;


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


    ap_enable_reg_pp0_iter0_assign_proc : process(ap_clk)
    begin
        if (ap_clk'event and ap_clk =  '1') then
            if (ap_rst = '1') then
                ap_enable_reg_pp0_iter0 <= ap_const_logic_0;
            else
                if (((ap_const_logic_1 = ap_CS_fsm_pp0_stage0) and (ap_const_logic_1 = ap_condition_pp0_exit_iter0_state2) and (ap_const_boolean_0 = ap_block_pp0_stage0_subdone))) then 
                    ap_enable_reg_pp0_iter0 <= ap_const_logic_0;
                elsif (((ap_start = ap_const_logic_1) and (fatherSearch_read_read_fu_76_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state1))) then 
                    ap_enable_reg_pp0_iter0 <= ap_const_logic_1;
                end if; 
            end if;
        end if;
    end process;


    ap_enable_reg_pp0_iter1_assign_proc : process(ap_clk)
    begin
        if (ap_clk'event and ap_clk =  '1') then
            if (ap_rst = '1') then
                ap_enable_reg_pp0_iter1 <= ap_const_logic_0;
            else
                if ((ap_const_boolean_0 = ap_block_pp0_stage0_subdone)) then
                    if ((ap_const_logic_1 = ap_condition_pp0_exit_iter0_state2)) then 
                        ap_enable_reg_pp0_iter1 <= (ap_const_logic_1 xor ap_condition_pp0_exit_iter0_state2);
                    elsif ((ap_const_boolean_1 = ap_const_boolean_1)) then 
                        ap_enable_reg_pp0_iter1 <= ap_enable_reg_pp0_iter0;
                    end if;
                end if; 
            end if;
        end if;
    end process;


    ap_enable_reg_pp0_iter2_assign_proc : process(ap_clk)
    begin
        if (ap_clk'event and ap_clk =  '1') then
            if (ap_rst = '1') then
                ap_enable_reg_pp0_iter2 <= ap_const_logic_0;
            else
                if ((ap_const_boolean_0 = ap_block_pp0_stage0_subdone)) then 
                    ap_enable_reg_pp0_iter2 <= ap_enable_reg_pp0_iter1;
                elsif (((ap_start = ap_const_logic_1) and (fatherSearch_read_read_fu_76_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state1))) then 
                    ap_enable_reg_pp0_iter2 <= ap_const_logic_0;
                end if; 
            end if;
        end if;
    end process;


    ap_enable_reg_pp1_iter0_assign_proc : process(ap_clk)
    begin
        if (ap_clk'event and ap_clk =  '1') then
            if (ap_rst = '1') then
                ap_enable_reg_pp1_iter0 <= ap_const_logic_0;
            else
                if (((ap_const_logic_1 = ap_condition_pp1_exit_iter0_state6) and (ap_const_logic_1 = ap_CS_fsm_pp1_stage0) and (ap_const_boolean_0 = ap_block_pp1_stage0_subdone))) then 
                    ap_enable_reg_pp1_iter0 <= ap_const_logic_0;
                elsif (((ap_start = ap_const_logic_1) and (fatherSearch_read_read_fu_76_p2 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_state1))) then 
                    ap_enable_reg_pp1_iter0 <= ap_const_logic_1;
                end if; 
            end if;
        end if;
    end process;


    ap_enable_reg_pp1_iter1_assign_proc : process(ap_clk)
    begin
        if (ap_clk'event and ap_clk =  '1') then
            if (ap_rst = '1') then
                ap_enable_reg_pp1_iter1 <= ap_const_logic_0;
            else
                if ((ap_const_boolean_0 = ap_block_pp1_stage0_subdone)) then
                    if ((ap_const_logic_1 = ap_condition_pp1_exit_iter0_state6)) then 
                        ap_enable_reg_pp1_iter1 <= (ap_const_logic_1 xor ap_condition_pp1_exit_iter0_state6);
                    elsif ((ap_const_boolean_1 = ap_const_boolean_1)) then 
                        ap_enable_reg_pp1_iter1 <= ap_enable_reg_pp1_iter0;
                    end if;
                end if; 
            end if;
        end if;
    end process;


    ap_enable_reg_pp1_iter2_assign_proc : process(ap_clk)
    begin
        if (ap_clk'event and ap_clk =  '1') then
            if (ap_rst = '1') then
                ap_enable_reg_pp1_iter2 <= ap_const_logic_0;
            else
                if ((ap_const_boolean_0 = ap_block_pp1_stage0_subdone)) then 
                    ap_enable_reg_pp1_iter2 <= ap_enable_reg_pp1_iter1;
                elsif (((ap_start = ap_const_logic_1) and (fatherSearch_read_read_fu_76_p2 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_state1))) then 
                    ap_enable_reg_pp1_iter2 <= ap_const_logic_0;
                end if; 
            end if;
        end if;
    end process;


    i1_0_reg_123_assign_proc : process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((ap_start = ap_const_logic_1) and (fatherSearch_read_read_fu_76_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state1))) then 
                i1_0_reg_123 <= ap_const_lv11_0;
            elsif (((ap_const_boolean_0 = ap_block_pp0_stage0_11001) and (icmp_ln25_fu_175_p2 = ap_const_lv1_0) and (ap_enable_reg_pp0_iter0 = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0))) then 
                i1_0_reg_123 <= i_1_fu_181_p2;
            end if; 
        end if;
    end process;

    i_0_reg_134_assign_proc : process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((ap_start = ap_const_logic_1) and (fatherSearch_read_read_fu_76_p2 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_state1))) then 
                i_0_reg_134 <= ap_const_lv11_0;
            elsif (((ap_enable_reg_pp1_iter0 = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_pp1_stage0) and (ap_const_boolean_0 = ap_block_pp1_stage0_11001) and (icmp_ln17_fu_212_p2 = ap_const_lv1_0))) then 
                i_0_reg_134 <= i_fu_218_p2;
            end if; 
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((ap_const_logic_1 = ap_CS_fsm_pp1_stage0) and (ap_const_boolean_0 = ap_block_pp1_stage0_11001))) then
                and_ln22_reg_302 <= and_ln22_fu_243_p2;
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((ap_const_boolean_0 = ap_block_pp0_stage0_11001) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0))) then
                and_ln30_reg_279 <= and_ln30_fu_206_p2;
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((ap_const_boolean_0 = ap_block_pp0_stage0_11001) and (ap_const_lv1_1 = and_ln30_fu_206_p2) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0))) then
                tmp_V_1_reg_283 <= tree_V_q0(12 downto 2);
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((ap_const_lv1_1 = and_ln22_fu_243_p2) and (ap_enable_reg_pp1_iter1 = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_pp1_stage0) and (ap_const_boolean_0 = ap_block_pp1_stage0_11001))) then
                tmp_V_reg_306 <= tree_V_q0(23 downto 13);
            end if;
        end if;
    end process;

    ap_NS_fsm_assign_proc : process (ap_start, ap_CS_fsm, ap_CS_fsm_state1, result_V_V_full_n, ap_enable_reg_pp1_iter2, ap_enable_reg_pp0_iter2, ap_CS_fsm_state5, fatherSearch_read_read_fu_76_p2, icmp_ln25_fu_175_p2, ap_enable_reg_pp0_iter0, icmp_ln17_fu_212_p2, ap_enable_reg_pp1_iter0, ap_enable_reg_pp1_iter1, ap_block_pp0_stage0_subdone, ap_enable_reg_pp0_iter1, ap_block_pp1_stage0_subdone)
    begin
        case ap_CS_fsm is
            when ap_ST_fsm_state1 => 
                if (((ap_start = ap_const_logic_1) and (fatherSearch_read_read_fu_76_p2 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_state1))) then
                    ap_NS_fsm <= ap_ST_fsm_pp1_stage0;
                elsif (((ap_start = ap_const_logic_1) and (fatherSearch_read_read_fu_76_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state1))) then
                    ap_NS_fsm <= ap_ST_fsm_pp0_stage0;
                else
                    ap_NS_fsm <= ap_ST_fsm_state1;
                end if;
            when ap_ST_fsm_pp0_stage0 => 
                if ((not(((icmp_ln25_fu_175_p2 = ap_const_lv1_1) and (ap_enable_reg_pp0_iter0 = ap_const_logic_1) and (ap_enable_reg_pp0_iter1 = ap_const_logic_0) and (ap_const_boolean_0 = ap_block_pp0_stage0_subdone))) and not(((ap_enable_reg_pp0_iter2 = ap_const_logic_1) and (ap_enable_reg_pp0_iter1 = ap_const_logic_0) and (ap_const_boolean_0 = ap_block_pp0_stage0_subdone))))) then
                    ap_NS_fsm <= ap_ST_fsm_pp0_stage0;
                elsif ((((icmp_ln25_fu_175_p2 = ap_const_lv1_1) and (ap_enable_reg_pp0_iter0 = ap_const_logic_1) and (ap_enable_reg_pp0_iter1 = ap_const_logic_0) and (ap_const_boolean_0 = ap_block_pp0_stage0_subdone)) or ((ap_enable_reg_pp0_iter2 = ap_const_logic_1) and (ap_enable_reg_pp0_iter1 = ap_const_logic_0) and (ap_const_boolean_0 = ap_block_pp0_stage0_subdone)))) then
                    ap_NS_fsm <= ap_ST_fsm_state5;
                else
                    ap_NS_fsm <= ap_ST_fsm_pp0_stage0;
                end if;
            when ap_ST_fsm_state5 => 
                if (((result_V_V_full_n = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_state5))) then
                    ap_NS_fsm <= ap_ST_fsm_state1;
                else
                    ap_NS_fsm <= ap_ST_fsm_state5;
                end if;
            when ap_ST_fsm_pp1_stage0 => 
                if ((not(((icmp_ln17_fu_212_p2 = ap_const_lv1_1) and (ap_enable_reg_pp1_iter0 = ap_const_logic_1) and (ap_const_boolean_0 = ap_block_pp1_stage0_subdone) and (ap_enable_reg_pp1_iter1 = ap_const_logic_0))) and not(((ap_enable_reg_pp1_iter2 = ap_const_logic_1) and (ap_const_boolean_0 = ap_block_pp1_stage0_subdone) and (ap_enable_reg_pp1_iter1 = ap_const_logic_0))))) then
                    ap_NS_fsm <= ap_ST_fsm_pp1_stage0;
                elsif ((((ap_enable_reg_pp1_iter2 = ap_const_logic_1) and (ap_const_boolean_0 = ap_block_pp1_stage0_subdone) and (ap_enable_reg_pp1_iter1 = ap_const_logic_0)) or ((icmp_ln17_fu_212_p2 = ap_const_lv1_1) and (ap_enable_reg_pp1_iter0 = ap_const_logic_1) and (ap_const_boolean_0 = ap_block_pp1_stage0_subdone) and (ap_enable_reg_pp1_iter1 = ap_const_logic_0)))) then
                    ap_NS_fsm <= ap_ST_fsm_state5;
                else
                    ap_NS_fsm <= ap_ST_fsm_pp1_stage0;
                end if;
            when others =>  
                ap_NS_fsm <= "XXXX";
        end case;
    end process;
    and_ln22_fu_243_p2 <= (icmp_ln879_fu_233_p2 and icmp_ln879_2_fu_238_p2);
    and_ln30_fu_206_p2 <= (icmp_ln879_3_fu_201_p2 and icmp_ln879_1_fu_196_p2);
    ap_CS_fsm_pp0_stage0 <= ap_CS_fsm(1);
    ap_CS_fsm_pp1_stage0 <= ap_CS_fsm(3);
    ap_CS_fsm_state1 <= ap_CS_fsm(0);
    ap_CS_fsm_state5 <= ap_CS_fsm(2);
        ap_block_pp0_stage0 <= not((ap_const_boolean_1 = ap_const_boolean_1));

    ap_block_pp0_stage0_01001_assign_proc : process(result_V_V_full_n, ap_enable_reg_pp0_iter2, and_ln30_reg_279)
    begin
                ap_block_pp0_stage0_01001 <= ((ap_const_lv1_1 = and_ln30_reg_279) and (result_V_V_full_n = ap_const_logic_0) and (ap_enable_reg_pp0_iter2 = ap_const_logic_1));
    end process;


    ap_block_pp0_stage0_11001_assign_proc : process(result_V_V_full_n, ap_enable_reg_pp0_iter2, and_ln30_reg_279)
    begin
                ap_block_pp0_stage0_11001 <= ((ap_const_lv1_1 = and_ln30_reg_279) and (result_V_V_full_n = ap_const_logic_0) and (ap_enable_reg_pp0_iter2 = ap_const_logic_1));
    end process;


    ap_block_pp0_stage0_subdone_assign_proc : process(result_V_V_full_n, ap_enable_reg_pp0_iter2, and_ln30_reg_279)
    begin
                ap_block_pp0_stage0_subdone <= ((ap_const_lv1_1 = and_ln30_reg_279) and (result_V_V_full_n = ap_const_logic_0) and (ap_enable_reg_pp0_iter2 = ap_const_logic_1));
    end process;

        ap_block_pp1_stage0 <= not((ap_const_boolean_1 = ap_const_boolean_1));

    ap_block_pp1_stage0_01001_assign_proc : process(result_V_V_full_n, ap_enable_reg_pp1_iter2, and_ln22_reg_302)
    begin
                ap_block_pp1_stage0_01001 <= ((ap_const_lv1_1 = and_ln22_reg_302) and (result_V_V_full_n = ap_const_logic_0) and (ap_enable_reg_pp1_iter2 = ap_const_logic_1));
    end process;


    ap_block_pp1_stage0_11001_assign_proc : process(result_V_V_full_n, ap_enable_reg_pp1_iter2, and_ln22_reg_302)
    begin
                ap_block_pp1_stage0_11001 <= ((ap_const_lv1_1 = and_ln22_reg_302) and (result_V_V_full_n = ap_const_logic_0) and (ap_enable_reg_pp1_iter2 = ap_const_logic_1));
    end process;


    ap_block_pp1_stage0_subdone_assign_proc : process(result_V_V_full_n, ap_enable_reg_pp1_iter2, and_ln22_reg_302)
    begin
                ap_block_pp1_stage0_subdone <= ((ap_const_lv1_1 = and_ln22_reg_302) and (result_V_V_full_n = ap_const_logic_0) and (ap_enable_reg_pp1_iter2 = ap_const_logic_1));
    end process;

        ap_block_state2_pp0_stage0_iter0 <= not((ap_const_boolean_1 = ap_const_boolean_1));
        ap_block_state3_pp0_stage0_iter1 <= not((ap_const_boolean_1 = ap_const_boolean_1));

    ap_block_state4_pp0_stage0_iter2_assign_proc : process(result_V_V_full_n, and_ln30_reg_279)
    begin
                ap_block_state4_pp0_stage0_iter2 <= ((ap_const_lv1_1 = and_ln30_reg_279) and (result_V_V_full_n = ap_const_logic_0));
    end process;

        ap_block_state6_pp1_stage0_iter0 <= not((ap_const_boolean_1 = ap_const_boolean_1));
        ap_block_state7_pp1_stage0_iter1 <= not((ap_const_boolean_1 = ap_const_boolean_1));

    ap_block_state8_pp1_stage0_iter2_assign_proc : process(result_V_V_full_n, and_ln22_reg_302)
    begin
                ap_block_state8_pp1_stage0_iter2 <= ((ap_const_lv1_1 = and_ln22_reg_302) and (result_V_V_full_n = ap_const_logic_0));
    end process;


    ap_condition_pp0_exit_iter0_state2_assign_proc : process(icmp_ln25_fu_175_p2)
    begin
        if ((icmp_ln25_fu_175_p2 = ap_const_lv1_1)) then 
            ap_condition_pp0_exit_iter0_state2 <= ap_const_logic_1;
        else 
            ap_condition_pp0_exit_iter0_state2 <= ap_const_logic_0;
        end if; 
    end process;


    ap_condition_pp1_exit_iter0_state6_assign_proc : process(icmp_ln17_fu_212_p2)
    begin
        if ((icmp_ln17_fu_212_p2 = ap_const_lv1_1)) then 
            ap_condition_pp1_exit_iter0_state6 <= ap_const_logic_1;
        else 
            ap_condition_pp1_exit_iter0_state6 <= ap_const_logic_0;
        end if; 
    end process;


    ap_done_assign_proc : process(ap_start, ap_CS_fsm_state1, result_V_V_full_n, ap_CS_fsm_state5)
    begin
        if ((((result_V_V_full_n = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_state5)) or ((ap_start = ap_const_logic_0) and (ap_const_logic_1 = ap_CS_fsm_state1)))) then 
            ap_done <= ap_const_logic_1;
        else 
            ap_done <= ap_const_logic_0;
        end if; 
    end process;

    ap_enable_pp0 <= (ap_idle_pp0 xor ap_const_logic_1);
    ap_enable_pp1 <= (ap_idle_pp1 xor ap_const_logic_1);

    ap_idle_assign_proc : process(ap_start, ap_CS_fsm_state1)
    begin
        if (((ap_start = ap_const_logic_0) and (ap_const_logic_1 = ap_CS_fsm_state1))) then 
            ap_idle <= ap_const_logic_1;
        else 
            ap_idle <= ap_const_logic_0;
        end if; 
    end process;


    ap_idle_pp0_assign_proc : process(ap_enable_reg_pp0_iter2, ap_enable_reg_pp0_iter0, ap_enable_reg_pp0_iter1)
    begin
        if (((ap_enable_reg_pp0_iter0 = ap_const_logic_0) and (ap_enable_reg_pp0_iter2 = ap_const_logic_0) and (ap_enable_reg_pp0_iter1 = ap_const_logic_0))) then 
            ap_idle_pp0 <= ap_const_logic_1;
        else 
            ap_idle_pp0 <= ap_const_logic_0;
        end if; 
    end process;


    ap_idle_pp1_assign_proc : process(ap_enable_reg_pp1_iter2, ap_enable_reg_pp1_iter0, ap_enable_reg_pp1_iter1)
    begin
        if (((ap_enable_reg_pp1_iter2 = ap_const_logic_0) and (ap_enable_reg_pp1_iter1 = ap_const_logic_0) and (ap_enable_reg_pp1_iter0 = ap_const_logic_0))) then 
            ap_idle_pp1 <= ap_const_logic_1;
        else 
            ap_idle_pp1 <= ap_const_logic_0;
        end if; 
    end process;


    ap_ready_assign_proc : process(result_V_V_full_n, ap_CS_fsm_state5)
    begin
        if (((result_V_V_full_n = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_state5))) then 
            ap_ready <= ap_const_logic_1;
        else 
            ap_ready <= ap_const_logic_0;
        end if; 
    end process;

    compare_node_V_fu_165_p4 <= tree_V_q0(12 downto 2);
    fatherSearch_read_read_fu_76_p2 <= (0=>fatherSearch, others=>'-');
    grp_fu_145_p4 <= tree_V_q0(23 downto 13);
    i_1_fu_181_p2 <= std_logic_vector(unsigned(i1_0_reg_123) + unsigned(ap_const_lv11_1));
    i_fu_218_p2 <= std_logic_vector(unsigned(i_0_reg_134) + unsigned(ap_const_lv11_1));
    icmp_ln17_fu_212_p2 <= "1" when (i_0_reg_134 = ap_const_lv11_400) else "0";
    icmp_ln25_fu_175_p2 <= "1" when (i1_0_reg_123 = ap_const_lv11_400) else "0";
    icmp_ln879_1_fu_196_p2 <= "1" when (grp_fu_145_p4 = nodo_V) else "0";
    icmp_ln879_2_fu_238_p2 <= "1" when (node_relation_V_fu_229_p1 = relationship_V) else "0";
    icmp_ln879_3_fu_201_p2 <= "1" when (node_relation_V_1_fu_192_p1 = relationship_V) else "0";
    icmp_ln879_fu_233_p2 <= "1" when (compare_node_V_fu_165_p4 = nodo_V) else "0";
    node_relation_V_1_fu_192_p1 <= tree_V_q0(2 - 1 downto 0);
    node_relation_V_fu_229_p1 <= tree_V_q0(2 - 1 downto 0);

    result_V_V_blk_n_assign_proc : process(result_V_V_full_n, ap_enable_reg_pp1_iter2, ap_block_pp1_stage0, and_ln22_reg_302, ap_enable_reg_pp0_iter2, ap_block_pp0_stage0, and_ln30_reg_279, ap_CS_fsm_state5)
    begin
        if (((ap_const_logic_1 = ap_CS_fsm_state5) or ((ap_const_boolean_0 = ap_block_pp0_stage0) and (ap_const_lv1_1 = and_ln30_reg_279) and (ap_enable_reg_pp0_iter2 = ap_const_logic_1)) or ((ap_const_lv1_1 = and_ln22_reg_302) and (ap_const_boolean_0 = ap_block_pp1_stage0) and (ap_enable_reg_pp1_iter2 = ap_const_logic_1)))) then 
            result_V_V_blk_n <= result_V_V_full_n;
        else 
            result_V_V_blk_n <= ap_const_logic_1;
        end if; 
    end process;


    result_V_V_din_assign_proc : process(result_V_V_full_n, ap_enable_reg_pp1_iter2, and_ln22_reg_302, ap_enable_reg_pp0_iter2, and_ln30_reg_279, ap_CS_fsm_state5, tmp_V_1_reg_283, tmp_V_reg_306, ap_block_pp0_stage0_01001, ap_block_pp1_stage0_01001)
    begin
        if (((ap_const_lv1_1 = and_ln22_reg_302) and (ap_enable_reg_pp1_iter2 = ap_const_logic_1) and (ap_const_boolean_0 = ap_block_pp1_stage0_01001))) then 
            result_V_V_din <= tmp_V_reg_306;
        elsif (((result_V_V_full_n = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_state5))) then 
            result_V_V_din <= ap_const_lv11_0;
        elsif (((ap_const_lv1_1 = and_ln30_reg_279) and (ap_enable_reg_pp0_iter2 = ap_const_logic_1) and (ap_const_boolean_0 = ap_block_pp0_stage0_01001))) then 
            result_V_V_din <= tmp_V_1_reg_283;
        else 
            result_V_V_din <= "XXXXXXXXXXX";
        end if; 
    end process;


    result_V_V_write_assign_proc : process(result_V_V_full_n, ap_enable_reg_pp1_iter2, and_ln22_reg_302, ap_enable_reg_pp0_iter2, and_ln30_reg_279, ap_CS_fsm_state5, ap_block_pp0_stage0_11001, ap_block_pp1_stage0_11001)
    begin
        if ((((result_V_V_full_n = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_state5)) or ((ap_const_boolean_0 = ap_block_pp0_stage0_11001) and (ap_const_lv1_1 = and_ln30_reg_279) and (ap_enable_reg_pp0_iter2 = ap_const_logic_1)) or ((ap_const_lv1_1 = and_ln22_reg_302) and (ap_enable_reg_pp1_iter2 = ap_const_logic_1) and (ap_const_boolean_0 = ap_block_pp1_stage0_11001)))) then 
            result_V_V_write <= ap_const_logic_1;
        else 
            result_V_V_write <= ap_const_logic_0;
        end if; 
    end process;


    tree_V_address0_assign_proc : process(ap_block_pp1_stage0, ap_block_pp0_stage0, ap_CS_fsm_pp0_stage0, ap_enable_reg_pp0_iter0, ap_CS_fsm_pp1_stage0, ap_enable_reg_pp1_iter0, zext_ln27_fu_187_p1, zext_ln19_fu_224_p1)
    begin
        if (((ap_const_boolean_0 = ap_block_pp1_stage0) and (ap_enable_reg_pp1_iter0 = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_pp1_stage0))) then 
            tree_V_address0 <= zext_ln19_fu_224_p1(10 - 1 downto 0);
        elsif (((ap_const_boolean_0 = ap_block_pp0_stage0) and (ap_enable_reg_pp0_iter0 = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0))) then 
            tree_V_address0 <= zext_ln27_fu_187_p1(10 - 1 downto 0);
        else 
            tree_V_address0 <= "XXXXXXXXXX";
        end if; 
    end process;


    tree_V_ce0_assign_proc : process(ap_CS_fsm_pp0_stage0, ap_block_pp0_stage0_11001, ap_enable_reg_pp0_iter0, ap_CS_fsm_pp1_stage0, ap_block_pp1_stage0_11001, ap_enable_reg_pp1_iter0)
    begin
        if ((((ap_const_boolean_0 = ap_block_pp0_stage0_11001) and (ap_enable_reg_pp0_iter0 = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0)) or ((ap_enable_reg_pp1_iter0 = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_pp1_stage0) and (ap_const_boolean_0 = ap_block_pp1_stage0_11001)))) then 
            tree_V_ce0 <= ap_const_logic_1;
        else 
            tree_V_ce0 <= ap_const_logic_0;
        end if; 
    end process;

    zext_ln19_fu_224_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(i_0_reg_134),64));
    zext_ln27_fu_187_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(i1_0_reg_123),64));
end behav;
