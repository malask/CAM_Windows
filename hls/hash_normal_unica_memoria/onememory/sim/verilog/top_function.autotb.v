// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.1 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================
 `timescale 1ns/1ps


`define AUTOTB_DUT      top_function
`define AUTOTB_DUT_INST AESL_inst_top_function
`define AUTOTB_TOP      apatb_top_function_top
`define AUTOTB_LAT_RESULT_FILE "top_function.result.lat.rb"
`define AUTOTB_PER_RESULT_TRANS_FILE "top_function.performance.result.transaction.xml"
`define AUTOTB_TOP_INST AESL_inst_apatb_top_function_top
`define AUTOTB_MAX_ALLOW_LATENCY  15000000
`define AUTOTB_CLOCK_PERIOD_DIV2 5.00

`define AESL_MEM_tree_V AESL_automem_tree_V
`define AESL_MEM_INST_tree_V mem_inst_tree_V
`define AESL_DEPTH_nodo_V 1
`define AESL_DEPTH_relationship_V 1
`define AESL_DEPTH_fatherSearch 1
`define AESL_FIFO_result_V_V AESL_autofifo_result_V_V
`define AESL_FIFO_INST_result_V_V AESL_autofifo_inst_result_V_V
`define AUTOTB_TVIN_tree_V  "../tv/cdatafile/c.top_function.autotvin_tree_V.dat"
`define AUTOTB_TVIN_nodo_V  "../tv/cdatafile/c.top_function.autotvin_nodo_V.dat"
`define AUTOTB_TVIN_relationship_V  "../tv/cdatafile/c.top_function.autotvin_relationship_V.dat"
`define AUTOTB_TVIN_fatherSearch  "../tv/cdatafile/c.top_function.autotvin_fatherSearch.dat"
`define AUTOTB_TVIN_result_V_V  "../tv/cdatafile/c.top_function.autotvin_result_V_V.dat"
`define AUTOTB_TVIN_tree_V_out_wrapc  "../tv/rtldatafile/rtl.top_function.autotvin_tree_V.dat"
`define AUTOTB_TVIN_nodo_V_out_wrapc  "../tv/rtldatafile/rtl.top_function.autotvin_nodo_V.dat"
`define AUTOTB_TVIN_relationship_V_out_wrapc  "../tv/rtldatafile/rtl.top_function.autotvin_relationship_V.dat"
`define AUTOTB_TVIN_fatherSearch_out_wrapc  "../tv/rtldatafile/rtl.top_function.autotvin_fatherSearch.dat"
`define AUTOTB_TVIN_result_V_V_out_wrapc  "../tv/rtldatafile/rtl.top_function.autotvin_result_V_V.dat"
`define AUTOTB_TVOUT_result_V_V  "../tv/cdatafile/c.top_function.autotvout_result_V_V.dat"
`define AUTOTB_TVOUT_result_V_V_out_wrapc  "../tv/rtldatafile/rtl.top_function.autotvout_result_V_V.dat"
module `AUTOTB_TOP;

parameter AUTOTB_TRANSACTION_NUM = 6;
parameter PROGRESS_TIMEOUT = 10000000;
parameter LATENCY_ESTIMATION = 2;
parameter LENGTH_tree_V = 1024;
parameter LENGTH_nodo_V = 1;
parameter LENGTH_relationship_V = 1;
parameter LENGTH_fatherSearch = 1;
parameter LENGTH_result_V_V = 2;

task read_token;
    input integer fp;
    output reg [159 : 0] token;
    integer ret;
    begin
        token = "";
        ret = 0;
        ret = $fscanf(fp,"%s",token);
    end
endtask

reg AESL_clock;
reg rst;
reg start;
reg ce;
reg tb_continue;
wire AESL_start;
wire AESL_reset;
wire AESL_ce;
wire AESL_ready;
wire AESL_idle;
wire AESL_continue;
wire AESL_done;
reg AESL_done_delay = 0;
reg AESL_done_delay2 = 0;
reg AESL_ready_delay = 0;
wire ready;
wire ready_wire;
wire [9 : 0] tree_V_address0;
wire  tree_V_ce0;
wire [23 : 0] tree_V_d0;
wire [23 : 0] tree_V_q0;
wire  tree_V_we0;
wire [9 : 0] tree_V_address1;
wire  tree_V_ce1;
wire [23 : 0] tree_V_d1;
wire [23 : 0] tree_V_q1;
wire  tree_V_we1;
wire [10 : 0] nodo_V;
wire [1 : 0] relationship_V;
wire  fatherSearch;
wire [10 : 0] result_V_V_din;
wire  result_V_V_full_n;
wire  result_V_V_write;
wire ap_start;
wire ap_done;
wire ap_ready;
wire ap_idle;
integer done_cnt = 0;
integer AESL_ready_cnt = 0;
integer ready_cnt = 0;
reg ready_initial;
reg ready_initial_n;
reg ready_last_n;
reg ready_delay_last_n;
reg done_delay_last_n;
reg interface_done = 0;

wire ap_clk;
wire ap_rst;
wire ap_rst_n;

`AUTOTB_DUT `AUTOTB_DUT_INST(
    .tree_V_address0(tree_V_address0),
    .tree_V_ce0(tree_V_ce0),
    .tree_V_d0(tree_V_d0),
    .tree_V_q0(tree_V_q0),
    .tree_V_we0(tree_V_we0),
    .tree_V_address1(tree_V_address1),
    .tree_V_ce1(tree_V_ce1),
    .tree_V_d1(tree_V_d1),
    .tree_V_q1(tree_V_q1),
    .tree_V_we1(tree_V_we1),
    .nodo_V(nodo_V),
    .relationship_V(relationship_V),
    .fatherSearch(fatherSearch),
    .result_V_V_din(result_V_V_din),
    .result_V_V_full_n(result_V_V_full_n),
    .result_V_V_write(result_V_V_write),
    .ap_clk(ap_clk),
    .ap_rst(ap_rst),
    .ap_start(ap_start),
    .ap_done(ap_done),
    .ap_ready(ap_ready),
    .ap_idle(ap_idle));

// Assignment for control signal
assign ap_clk = AESL_clock;
assign ap_rst = AESL_reset;
assign ap_rst_n = ~AESL_reset;
assign AESL_reset = rst;
assign ap_start = AESL_start;
assign AESL_start = start;
assign AESL_done = ap_done;
assign AESL_ready = ap_ready;
assign AESL_idle = ap_idle;
assign AESL_ce = ce;
assign AESL_continue = tb_continue;
    always @(posedge AESL_clock) begin
        if (AESL_reset) begin
        end else begin
            if (AESL_done !== 1 && AESL_done !== 0) begin
                $display("ERROR: Control signal AESL_done is invalid!");
                $finish;
            end
        end
    end
    always @(posedge AESL_clock) begin
        if (AESL_reset) begin
        end else begin
            if (AESL_ready !== 1 && AESL_ready !== 0) begin
                $display("ERROR: Control signal AESL_ready is invalid!");
                $finish;
            end
        end
    end
//------------------------arraytree_V Instantiation--------------

// The input and output of arraytree_V
wire    arraytree_V_ce0, arraytree_V_ce1;
wire    arraytree_V_we0, arraytree_V_we1;
wire    [9 : 0]    arraytree_V_address0, arraytree_V_address1;
wire    [23 : 0]    arraytree_V_din0, arraytree_V_din1;
wire    [23 : 0]    arraytree_V_dout0, arraytree_V_dout1;
wire    arraytree_V_ready;
wire    arraytree_V_done;

`AESL_MEM_tree_V `AESL_MEM_INST_tree_V(
    .clk        (AESL_clock),
    .rst        (AESL_reset),
    .ce0        (arraytree_V_ce0),
    .we0        (arraytree_V_we0),
    .address0   (arraytree_V_address0),
    .din0       (arraytree_V_din0),
    .dout0      (arraytree_V_dout0),
    .ce1        (arraytree_V_ce1),
    .we1        (arraytree_V_we1),
    .address1   (arraytree_V_address1),
    .din1       (arraytree_V_din1),
    .dout1      (arraytree_V_dout1),
    .ready      (arraytree_V_ready),
    .done    (arraytree_V_done)
);

// Assignment between dut and arraytree_V
assign arraytree_V_address0 = tree_V_address0;
assign arraytree_V_ce0 = tree_V_ce0;
assign tree_V_q0 = arraytree_V_dout0;
assign arraytree_V_we0 = 0;
assign arraytree_V_din0 = 0;
assign arraytree_V_we1 = 0;
assign arraytree_V_din1 = 0;
assign arraytree_V_ready=    ready;
assign arraytree_V_done = 0;


// The signal of port nodo_V
reg [10: 0] AESL_REG_nodo_V = 0;
assign nodo_V = AESL_REG_nodo_V;
initial begin : read_file_process_nodo_V
    integer fp;
    integer err;
    integer ret;
    integer proc_rand;
    reg [159  : 0] token;
    integer i;
    reg transaction_finish;
    integer transaction_idx;
    transaction_idx = 0;
    wait(AESL_reset === 0);
    fp = $fopen(`AUTOTB_TVIN_nodo_V,"r");
    if(fp == 0) begin       // Failed to open file
        $display("Failed to open file \"%s\"!", `AUTOTB_TVIN_nodo_V);
        $display("ERROR: Simulation using HLS TB failed.");
        $finish;
    end
    read_token(fp, token);
    if (token != "[[[runtime]]]") begin
        $display("ERROR: Simulation using HLS TB failed.");
        $finish;
    end
    read_token(fp, token);
    while (token != "[[[/runtime]]]") begin
        if (token != "[[transaction]]") begin
            $display("ERROR: Simulation using HLS TB failed.");
              $finish;
        end
        read_token(fp, token);  // skip transaction number
          read_token(fp, token);
            # 0.2;
            while(ready_wire !== 1) begin
                @(posedge AESL_clock);
                # 0.2;
            end
        if(token != "[[/transaction]]") begin
            ret = $sscanf(token, "0x%x", AESL_REG_nodo_V);
              if (ret != 1) begin
                  $display("Failed to parse token!");
                $display("ERROR: Simulation using HLS TB failed.");
                  $finish;
              end
            @(posedge AESL_clock);
              read_token(fp, token);
        end
          read_token(fp, token);
    end
    $fclose(fp);
end


// The signal of port relationship_V
reg [1: 0] AESL_REG_relationship_V = 0;
assign relationship_V = AESL_REG_relationship_V;
initial begin : read_file_process_relationship_V
    integer fp;
    integer err;
    integer ret;
    integer proc_rand;
    reg [159  : 0] token;
    integer i;
    reg transaction_finish;
    integer transaction_idx;
    transaction_idx = 0;
    wait(AESL_reset === 0);
    fp = $fopen(`AUTOTB_TVIN_relationship_V,"r");
    if(fp == 0) begin       // Failed to open file
        $display("Failed to open file \"%s\"!", `AUTOTB_TVIN_relationship_V);
        $display("ERROR: Simulation using HLS TB failed.");
        $finish;
    end
    read_token(fp, token);
    if (token != "[[[runtime]]]") begin
        $display("ERROR: Simulation using HLS TB failed.");
        $finish;
    end
    read_token(fp, token);
    while (token != "[[[/runtime]]]") begin
        if (token != "[[transaction]]") begin
            $display("ERROR: Simulation using HLS TB failed.");
              $finish;
        end
        read_token(fp, token);  // skip transaction number
          read_token(fp, token);
            # 0.2;
            while(ready_wire !== 1) begin
                @(posedge AESL_clock);
                # 0.2;
            end
        if(token != "[[/transaction]]") begin
            ret = $sscanf(token, "0x%x", AESL_REG_relationship_V);
              if (ret != 1) begin
                  $display("Failed to parse token!");
                $display("ERROR: Simulation using HLS TB failed.");
                  $finish;
              end
            @(posedge AESL_clock);
              read_token(fp, token);
        end
          read_token(fp, token);
    end
    $fclose(fp);
end


// The signal of port fatherSearch
reg [0: 0] AESL_REG_fatherSearch = 0;
assign fatherSearch = AESL_REG_fatherSearch;
initial begin : read_file_process_fatherSearch
    integer fp;
    integer err;
    integer ret;
    integer proc_rand;
    reg [159  : 0] token;
    integer i;
    reg transaction_finish;
    integer transaction_idx;
    transaction_idx = 0;
    wait(AESL_reset === 0);
    fp = $fopen(`AUTOTB_TVIN_fatherSearch,"r");
    if(fp == 0) begin       // Failed to open file
        $display("Failed to open file \"%s\"!", `AUTOTB_TVIN_fatherSearch);
        $display("ERROR: Simulation using HLS TB failed.");
        $finish;
    end
    read_token(fp, token);
    if (token != "[[[runtime]]]") begin
        $display("ERROR: Simulation using HLS TB failed.");
        $finish;
    end
    read_token(fp, token);
    while (token != "[[[/runtime]]]") begin
        if (token != "[[transaction]]") begin
            $display("ERROR: Simulation using HLS TB failed.");
              $finish;
        end
        read_token(fp, token);  // skip transaction number
          read_token(fp, token);
            # 0.2;
            while(ready_wire !== 1) begin
                @(posedge AESL_clock);
                # 0.2;
            end
        if(token != "[[/transaction]]") begin
            ret = $sscanf(token, "0x%x", AESL_REG_fatherSearch);
              if (ret != 1) begin
                  $display("Failed to parse token!");
                $display("ERROR: Simulation using HLS TB failed.");
                  $finish;
              end
            @(posedge AESL_clock);
              read_token(fp, token);
        end
          read_token(fp, token);
    end
    $fclose(fp);
end


//------------------------Fiforesult_V_V Instantiation--------------

// The input and output of fiforesult_V_V
wire  fiforesult_V_V_wr;
wire  [10 : 0] fiforesult_V_V_din;
wire  fiforesult_V_V_full_n;
wire  fiforesult_V_V_ready;
wire  fiforesult_V_V_done;

`AESL_FIFO_result_V_V `AESL_FIFO_INST_result_V_V(
    .clk          (AESL_clock),
    .reset        (AESL_reset),
    .if_write     (fiforesult_V_V_wr),
    .if_din       (fiforesult_V_V_din),
    .if_full_n    (fiforesult_V_V_full_n),
    .if_read      (),
    .if_dout      (),
    .if_empty_n   (),
    .ready        (fiforesult_V_V_ready),
    .done         (fiforesult_V_V_done)
);

// Assignment between dut and fiforesult_V_V

// Assign input of fiforesult_V_V
assign      fiforesult_V_V_wr        =   result_V_V_write & result_V_V_full_n;
assign      fiforesult_V_V_din        =   result_V_V_din;
assign    fiforesult_V_V_ready   =  0;   //ready_initial | AESL_done_delay;
assign    fiforesult_V_V_done    =   AESL_done_delay;
// Assign input of dut
reg   reg_fiforesult_V_V_full_n;
initial begin : gen_reg_fiforesult_V_V_full_n_process
    integer proc_rand;
    reg_fiforesult_V_V_full_n = fiforesult_V_V_full_n;
    while (1) begin
        @ (fiforesult_V_V_full_n);
        reg_fiforesult_V_V_full_n = fiforesult_V_V_full_n;
    end
end

assign      result_V_V_full_n    =   reg_fiforesult_V_V_full_n;


initial begin : generate_AESL_ready_cnt_proc
    AESL_ready_cnt = 0;
    wait(AESL_reset === 0);
    while(AESL_ready_cnt != AUTOTB_TRANSACTION_NUM) begin
        while(AESL_ready !== 1) begin
            @(posedge AESL_clock);
            # 0.4;
        end
        @(negedge AESL_clock);
        AESL_ready_cnt = AESL_ready_cnt + 1;
        @(posedge AESL_clock);
        # 0.4;
    end
end

    event next_trigger_ready_cnt;
    
    initial begin : gen_ready_cnt
        ready_cnt = 0;
        wait (AESL_reset === 0);
        forever begin
            @ (posedge AESL_clock);
            if (ready == 1) begin
                if (ready_cnt < AUTOTB_TRANSACTION_NUM) begin
                    ready_cnt = ready_cnt + 1;
                end
            end
            -> next_trigger_ready_cnt;
        end
    end
    
    wire all_finish = (done_cnt == AUTOTB_TRANSACTION_NUM);
    
    // done_cnt
    always @ (posedge AESL_clock) begin
        if (AESL_reset) begin
            done_cnt <= 0;
        end else begin
            if (AESL_done == 1) begin
                if (done_cnt < AUTOTB_TRANSACTION_NUM) begin
                    done_cnt <= done_cnt + 1;
                end
            end
        end
    end
    
    initial begin : finish_simulation
        wait (all_finish == 1);
        // last transaction is saved at negedge right after last done
        @ (posedge AESL_clock);
        @ (posedge AESL_clock);
        @ (posedge AESL_clock);
        @ (posedge AESL_clock);
        $finish;
    end
    
initial begin
    AESL_clock = 0;
    forever #`AUTOTB_CLOCK_PERIOD_DIV2 AESL_clock = ~AESL_clock;
end


reg end_tree_V;
reg [31:0] size_tree_V;
reg [31:0] size_tree_V_backup;
reg end_nodo_V;
reg [31:0] size_nodo_V;
reg [31:0] size_nodo_V_backup;
reg end_relationship_V;
reg [31:0] size_relationship_V;
reg [31:0] size_relationship_V_backup;
reg end_fatherSearch;
reg [31:0] size_fatherSearch;
reg [31:0] size_fatherSearch_backup;
reg end_result_V_V;
reg [31:0] size_result_V_V;
reg [31:0] size_result_V_V_backup;

initial begin : initial_process
    integer proc_rand;
    rst = 1;
    # 100;
    repeat(3) @ (posedge AESL_clock);
    rst = 0;
end
initial begin : start_process
    integer proc_rand;
    reg [31:0] start_cnt;
    ce = 1;
    start = 0;
    start_cnt = 0;
    wait (AESL_reset === 0);
    @ (posedge AESL_clock);
    #0 start = 1;
    start_cnt = start_cnt + 1;
    forever begin
        @ (posedge AESL_clock);
        if (start_cnt >= AUTOTB_TRANSACTION_NUM) begin
            // keep pushing garbage in
            #0 start = 1;
        end
        if (AESL_ready) begin
            start_cnt = start_cnt + 1;
        end
    end
end

always @(AESL_done)
begin
    tb_continue = AESL_done;
end

initial begin : ready_initial_process
    ready_initial = 0;
    wait (AESL_start === 1);
    ready_initial = 1;
    @(posedge AESL_clock);
    ready_initial = 0;
end

always @(posedge AESL_clock)
begin
    if(AESL_reset)
      AESL_ready_delay = 0;
  else
      AESL_ready_delay = AESL_ready;
end
initial begin : ready_last_n_process
  ready_last_n = 1;
  wait(ready_cnt == AUTOTB_TRANSACTION_NUM)
  @(posedge AESL_clock);
  ready_last_n <= 0;
end

always @(posedge AESL_clock)
begin
    if(AESL_reset)
      ready_delay_last_n = 0;
  else
      ready_delay_last_n <= ready_last_n;
end
assign ready = (ready_initial | AESL_ready_delay);
assign ready_wire = ready_initial | AESL_ready_delay;
initial begin : done_delay_last_n_process
  done_delay_last_n = 1;
  while(done_cnt < AUTOTB_TRANSACTION_NUM)
      @(posedge AESL_clock);
  # 0.1;
  done_delay_last_n = 0;
end

always @(posedge AESL_clock)
begin
    if(AESL_reset)
  begin
      AESL_done_delay <= 0;
      AESL_done_delay2 <= 0;
  end
  else begin
      AESL_done_delay <= AESL_done & done_delay_last_n;
      AESL_done_delay2 <= AESL_done_delay;
  end
end
always @(posedge AESL_clock)
begin
    if(AESL_reset)
      interface_done = 0;
  else begin
      # 0.01;
      if(ready === 1 && ready_cnt > 0 && ready_cnt < AUTOTB_TRANSACTION_NUM)
          interface_done = 1;
      else if(AESL_done_delay === 1 && done_cnt == AUTOTB_TRANSACTION_NUM)
          interface_done = 1;
      else
          interface_done = 0;
  end
end

reg dump_tvout_finish_result_V_V;

initial begin : dump_tvout_runtime_sign_result_V_V
    integer fp;
    dump_tvout_finish_result_V_V = 0;
    fp = $fopen(`AUTOTB_TVOUT_result_V_V_out_wrapc, "w");
    if (fp == 0) begin
        $display("Failed to open file \"%s\"!", `AUTOTB_TVOUT_result_V_V_out_wrapc);
        $display("ERROR: Simulation using HLS TB failed.");
        $finish;
    end
    $fdisplay(fp,"[[[runtime]]]");
    $fclose(fp);
    wait (done_cnt == AUTOTB_TRANSACTION_NUM);
    // last transaction is saved at negedge right after last done
    @ (posedge AESL_clock);
    @ (posedge AESL_clock);
    @ (posedge AESL_clock);
    fp = $fopen(`AUTOTB_TVOUT_result_V_V_out_wrapc, "a");
    if (fp == 0) begin
        $display("Failed to open file \"%s\"!", `AUTOTB_TVOUT_result_V_V_out_wrapc);
        $display("ERROR: Simulation using HLS TB failed.");
        $finish;
    end
    $fdisplay(fp,"[[[/runtime]]]");
    $fclose(fp);
    dump_tvout_finish_result_V_V = 1;
end


////////////////////////////////////////////
// progress and performance
////////////////////////////////////////////

task wait_start();
    while (~AESL_start) begin
        @ (posedge AESL_clock);
    end
endtask

reg [31:0] clk_cnt = 0;
reg AESL_ready_p1;
reg AESL_start_p1;

always @ (posedge AESL_clock) begin
    clk_cnt <= clk_cnt + 1;
    AESL_ready_p1 <= AESL_ready;
    AESL_start_p1 <= AESL_start;
end

reg [31:0] start_timestamp [0:AUTOTB_TRANSACTION_NUM - 1];
reg [31:0] start_cnt;
reg [31:0] ready_timestamp [0:AUTOTB_TRANSACTION_NUM - 1];
reg [31:0] ap_ready_cnt;
reg [31:0] finish_timestamp [0:AUTOTB_TRANSACTION_NUM - 1];
reg [31:0] finish_cnt;
event report_progress;

initial begin
    start_cnt = 0;
    finish_cnt = 0;
    ap_ready_cnt = 0;
    wait (AESL_reset == 0);
    wait_start();
    start_timestamp[start_cnt] = clk_cnt;
    start_cnt = start_cnt + 1;
    if (AESL_done) begin
        finish_timestamp[finish_cnt] = clk_cnt;
        finish_cnt = finish_cnt + 1;
    end
    -> report_progress;
    forever begin
        @ (posedge AESL_clock);
        if (start_cnt < AUTOTB_TRANSACTION_NUM) begin
            if ((AESL_start && AESL_ready_p1)||(AESL_start && ~AESL_start_p1)) begin
                start_timestamp[start_cnt] = clk_cnt;
                start_cnt = start_cnt + 1;
            end
        end
        if (ap_ready_cnt < AUTOTB_TRANSACTION_NUM) begin
            if (AESL_start_p1 && AESL_ready_p1) begin
                ready_timestamp[ap_ready_cnt] = clk_cnt;
                ap_ready_cnt = ap_ready_cnt + 1;
            end
        end
        if (finish_cnt < AUTOTB_TRANSACTION_NUM) begin
            if (AESL_done) begin
                finish_timestamp[finish_cnt] = clk_cnt;
                finish_cnt = finish_cnt + 1;
            end
        end
        -> report_progress;
    end
end

reg [31:0] progress_timeout;

initial begin : simulation_progress
    real intra_progress;
    wait (AESL_reset == 0);
    progress_timeout = PROGRESS_TIMEOUT;
    $display("////////////////////////////////////////////////////////////////////////////////////");
    $display("// Inter-Transaction Progress: Completed Transaction / Total Transaction");
    $display("// Intra-Transaction Progress: Measured Latency / Latency Estimation * 100%%");
    $display("//");
    $display("// RTL Simulation : \"Inter-Transaction Progress\" [\"Intra-Transaction Progress\"] @ \"Simulation Time\"");
    $display("////////////////////////////////////////////////////////////////////////////////////");
    print_progress();
    while (finish_cnt < AUTOTB_TRANSACTION_NUM) begin
        @ (report_progress);
        if (finish_cnt < AUTOTB_TRANSACTION_NUM) begin
            if (AESL_done) begin
                print_progress();
                progress_timeout = PROGRESS_TIMEOUT;
            end else begin
                if (progress_timeout == 0) begin
                    print_progress();
                    progress_timeout = PROGRESS_TIMEOUT;
                end else begin
                    progress_timeout = progress_timeout - 1;
                end
            end
        end
    end
    print_progress();
    $display("////////////////////////////////////////////////////////////////////////////////////");
    calculate_performance();
end

task get_intra_progress(output real intra_progress);
    begin
        if (start_cnt > finish_cnt) begin
            intra_progress = clk_cnt - start_timestamp[finish_cnt];
        end else if(finish_cnt > 0) begin
            intra_progress = LATENCY_ESTIMATION;
        end else begin
            intra_progress = 0;
        end
        intra_progress = intra_progress / LATENCY_ESTIMATION;
    end
endtask

task print_progress();
    real intra_progress;
    begin
        if (LATENCY_ESTIMATION > 0) begin
            get_intra_progress(intra_progress);
            $display("// RTL Simulation : %0d / %0d [%2.2f%%] @ \"%0t\"", finish_cnt, AUTOTB_TRANSACTION_NUM, intra_progress * 100, $time);
        end else begin
            $display("// RTL Simulation : %0d / %0d [n/a] @ \"%0t\"", finish_cnt, AUTOTB_TRANSACTION_NUM, $time);
        end
    end
endtask

task calculate_performance();
    integer i;
    integer fp;
    reg [31:0] latency [0:AUTOTB_TRANSACTION_NUM - 1];
    reg [31:0] latency_min;
    reg [31:0] latency_max;
    reg [31:0] latency_total;
    reg [31:0] latency_average;
    reg [31:0] interval [0:AUTOTB_TRANSACTION_NUM - 2];
    reg [31:0] interval_min;
    reg [31:0] interval_max;
    reg [31:0] interval_total;
    reg [31:0] interval_average;
    begin
        latency_min = -1;
        latency_max = 0;
        latency_total = 0;
        interval_min = -1;
        interval_max = 0;
        interval_total = 0;

        for (i = 0; i < AUTOTB_TRANSACTION_NUM; i = i + 1) begin
            // calculate latency
            latency[i] = finish_timestamp[i] - start_timestamp[i];
            if (latency[i] > latency_max) latency_max = latency[i];
            if (latency[i] < latency_min) latency_min = latency[i];
            latency_total = latency_total + latency[i];
            // calculate interval
            if (AUTOTB_TRANSACTION_NUM == 1) begin
                interval[i] = 0;
                interval_max = 0;
                interval_min = 0;
                interval_total = 0;
            end else if (i < AUTOTB_TRANSACTION_NUM - 1) begin
                interval[i] = start_timestamp[i + 1] - start_timestamp[i];
                if (interval[i] > interval_max) interval_max = interval[i];
                if (interval[i] < interval_min) interval_min = interval[i];
                interval_total = interval_total + interval[i];
            end
        end

        latency_average = latency_total / AUTOTB_TRANSACTION_NUM;
        if (AUTOTB_TRANSACTION_NUM == 1) begin
            interval_average = 0;
        end else begin
            interval_average = interval_total / (AUTOTB_TRANSACTION_NUM - 1);
        end

        fp = $fopen(`AUTOTB_LAT_RESULT_FILE, "w");

        $fdisplay(fp, "$MAX_LATENCY = \"%0d\"", latency_max);
        $fdisplay(fp, "$MIN_LATENCY = \"%0d\"", latency_min);
        $fdisplay(fp, "$AVER_LATENCY = \"%0d\"", latency_average);
        $fdisplay(fp, "$MAX_THROUGHPUT = \"%0d\"", interval_max);
        $fdisplay(fp, "$MIN_THROUGHPUT = \"%0d\"", interval_min);
        $fdisplay(fp, "$AVER_THROUGHPUT = \"%0d\"", interval_average);

        $fclose(fp);

        fp = $fopen(`AUTOTB_PER_RESULT_TRANS_FILE, "w");

        $fdisplay(fp, "%20s%16s%16s", "", "latency", "interval");
        if (AUTOTB_TRANSACTION_NUM == 1) begin
            i = 0;
            $fdisplay(fp, "transaction%8d:%16d%16d", i, latency[i], interval[i]);
        end else begin
            for (i = 0; i < AUTOTB_TRANSACTION_NUM; i = i + 1) begin
                if (i < AUTOTB_TRANSACTION_NUM - 1) begin
                    $fdisplay(fp, "transaction%8d:%16d%16d", i, latency[i], interval[i]);
                end else begin
                    $fdisplay(fp, "transaction%8d:%16d               x", i, latency[i]);
                end
            end
        end

        $fclose(fp);
    end
endtask


////////////////////////////////////////////
// Dependence Check
////////////////////////////////////////////

`ifndef POST_SYN

`endif

endmodule
