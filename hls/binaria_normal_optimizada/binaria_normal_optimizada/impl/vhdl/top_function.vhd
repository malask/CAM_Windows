-- ==============================================================
-- RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
-- Version: 2019.1
-- Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
-- 
-- ===========================================================

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity top_function is
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
    tree_V_address1 : OUT STD_LOGIC_VECTOR (9 downto 0);
    tree_V_ce1 : OUT STD_LOGIC;
    tree_V_q1 : IN STD_LOGIC_VECTOR (23 downto 0);
    nodo_V : IN STD_LOGIC_VECTOR (10 downto 0);
    relationship_V : IN STD_LOGIC_VECTOR (1 downto 0);
    fatherSearch : IN STD_LOGIC;
    result_V_V_din : OUT STD_LOGIC_VECTOR (10 downto 0);
    result_V_V_full_n : IN STD_LOGIC;
    result_V_V_write : OUT STD_LOGIC );
end;


architecture behav of top_function is 
    attribute CORE_GENERATION_INFO : STRING;
    attribute CORE_GENERATION_INFO of behav : architecture is
    "top_function,hls_ip_2019_1,{HLS_INPUT_TYPE=cxx,HLS_INPUT_FLOAT=0,HLS_INPUT_FIXED=1,HLS_INPUT_PART=xc7z020-clg484-1,HLS_INPUT_CLOCK=10.000000,HLS_INPUT_ARCH=others,HLS_SYN_CLOCK=7.090250,HLS_SYN_LAT=515,HLS_SYN_TPT=none,HLS_SYN_MEM=0,HLS_SYN_DSP=0,HLS_SYN_FF=109,HLS_SYN_LUT=341,HLS_VERSION=2019_1}";
    constant ap_const_logic_1 : STD_LOGIC := '1';
    constant ap_const_logic_0 : STD_LOGIC := '0';
    constant ap_ST_fsm_state1 : STD_LOGIC_VECTOR (1 downto 0) := "01";
    constant ap_ST_fsm_state2 : STD_LOGIC_VECTOR (1 downto 0) := "10";
    constant ap_const_lv32_0 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000000";
    constant ap_const_lv32_1 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000001";
    constant ap_const_boolean_1 : BOOLEAN := true;

    signal ap_CS_fsm : STD_LOGIC_VECTOR (1 downto 0) := "01";
    attribute fsm_encoding : string;
    attribute fsm_encoding of ap_CS_fsm : signal is "none";
    signal ap_CS_fsm_state1 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state1 : signal is "none";
    signal grp_busqueda_cam_fu_64_ap_start : STD_LOGIC;
    signal grp_busqueda_cam_fu_64_ap_done : STD_LOGIC;
    signal grp_busqueda_cam_fu_64_ap_idle : STD_LOGIC;
    signal grp_busqueda_cam_fu_64_ap_ready : STD_LOGIC;
    signal grp_busqueda_cam_fu_64_tree_V_address0 : STD_LOGIC_VECTOR (9 downto 0);
    signal grp_busqueda_cam_fu_64_tree_V_ce0 : STD_LOGIC;
    signal grp_busqueda_cam_fu_64_tree_V_address1 : STD_LOGIC_VECTOR (9 downto 0);
    signal grp_busqueda_cam_fu_64_tree_V_ce1 : STD_LOGIC;
    signal grp_busqueda_cam_fu_64_result_V_V_din : STD_LOGIC_VECTOR (10 downto 0);
    signal grp_busqueda_cam_fu_64_result_V_V_write : STD_LOGIC;
    signal grp_busqueda_cam_fu_64_ap_start_reg : STD_LOGIC := '0';
    signal ap_CS_fsm_state2 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state2 : signal is "none";
    signal ap_NS_fsm : STD_LOGIC_VECTOR (1 downto 0);

    component busqueda_cam IS
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
        tree_V_address1 : OUT STD_LOGIC_VECTOR (9 downto 0);
        tree_V_ce1 : OUT STD_LOGIC;
        tree_V_q1 : IN STD_LOGIC_VECTOR (23 downto 0);
        nodo_V : IN STD_LOGIC_VECTOR (10 downto 0);
        relationship_V : IN STD_LOGIC_VECTOR (1 downto 0);
        fatherSearch : IN STD_LOGIC;
        result_V_V_din : OUT STD_LOGIC_VECTOR (10 downto 0);
        result_V_V_full_n : IN STD_LOGIC;
        result_V_V_write : OUT STD_LOGIC );
    end component;



begin
    grp_busqueda_cam_fu_64 : component busqueda_cam
    port map (
        ap_clk => ap_clk,
        ap_rst => ap_rst,
        ap_start => grp_busqueda_cam_fu_64_ap_start,
        ap_done => grp_busqueda_cam_fu_64_ap_done,
        ap_idle => grp_busqueda_cam_fu_64_ap_idle,
        ap_ready => grp_busqueda_cam_fu_64_ap_ready,
        tree_V_address0 => grp_busqueda_cam_fu_64_tree_V_address0,
        tree_V_ce0 => grp_busqueda_cam_fu_64_tree_V_ce0,
        tree_V_q0 => tree_V_q0,
        tree_V_address1 => grp_busqueda_cam_fu_64_tree_V_address1,
        tree_V_ce1 => grp_busqueda_cam_fu_64_tree_V_ce1,
        tree_V_q1 => tree_V_q1,
        nodo_V => nodo_V,
        relationship_V => relationship_V,
        fatherSearch => fatherSearch,
        result_V_V_din => grp_busqueda_cam_fu_64_result_V_V_din,
        result_V_V_full_n => result_V_V_full_n,
        result_V_V_write => grp_busqueda_cam_fu_64_result_V_V_write);





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


    grp_busqueda_cam_fu_64_ap_start_reg_assign_proc : process(ap_clk)
    begin
        if (ap_clk'event and ap_clk =  '1') then
            if (ap_rst = '1') then
                grp_busqueda_cam_fu_64_ap_start_reg <= ap_const_logic_0;
            else
                if (((ap_start = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_state1))) then 
                    grp_busqueda_cam_fu_64_ap_start_reg <= ap_const_logic_1;
                elsif ((grp_busqueda_cam_fu_64_ap_ready = ap_const_logic_1)) then 
                    grp_busqueda_cam_fu_64_ap_start_reg <= ap_const_logic_0;
                end if; 
            end if;
        end if;
    end process;


    ap_NS_fsm_assign_proc : process (ap_start, ap_CS_fsm, ap_CS_fsm_state1, grp_busqueda_cam_fu_64_ap_done, ap_CS_fsm_state2)
    begin
        case ap_CS_fsm is
            when ap_ST_fsm_state1 => 
                if (((ap_start = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_state1))) then
                    ap_NS_fsm <= ap_ST_fsm_state2;
                else
                    ap_NS_fsm <= ap_ST_fsm_state1;
                end if;
            when ap_ST_fsm_state2 => 
                if (((grp_busqueda_cam_fu_64_ap_done = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_state2))) then
                    ap_NS_fsm <= ap_ST_fsm_state1;
                else
                    ap_NS_fsm <= ap_ST_fsm_state2;
                end if;
            when others =>  
                ap_NS_fsm <= "XX";
        end case;
    end process;
    ap_CS_fsm_state1 <= ap_CS_fsm(0);
    ap_CS_fsm_state2 <= ap_CS_fsm(1);

    ap_done_assign_proc : process(grp_busqueda_cam_fu_64_ap_done, ap_CS_fsm_state2)
    begin
        if (((grp_busqueda_cam_fu_64_ap_done = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_state2))) then 
            ap_done <= ap_const_logic_1;
        else 
            ap_done <= ap_const_logic_0;
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


    ap_ready_assign_proc : process(grp_busqueda_cam_fu_64_ap_done, ap_CS_fsm_state2)
    begin
        if (((grp_busqueda_cam_fu_64_ap_done = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_state2))) then 
            ap_ready <= ap_const_logic_1;
        else 
            ap_ready <= ap_const_logic_0;
        end if; 
    end process;

    grp_busqueda_cam_fu_64_ap_start <= grp_busqueda_cam_fu_64_ap_start_reg;
    result_V_V_din <= grp_busqueda_cam_fu_64_result_V_V_din;

    result_V_V_write_assign_proc : process(grp_busqueda_cam_fu_64_result_V_V_write, ap_CS_fsm_state2)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state2)) then 
            result_V_V_write <= grp_busqueda_cam_fu_64_result_V_V_write;
        else 
            result_V_V_write <= ap_const_logic_0;
        end if; 
    end process;

    tree_V_address0 <= grp_busqueda_cam_fu_64_tree_V_address0;
    tree_V_address1 <= grp_busqueda_cam_fu_64_tree_V_address1;
    tree_V_ce0 <= grp_busqueda_cam_fu_64_tree_V_ce0;
    tree_V_ce1 <= grp_busqueda_cam_fu_64_tree_V_ce1;
end behav;
