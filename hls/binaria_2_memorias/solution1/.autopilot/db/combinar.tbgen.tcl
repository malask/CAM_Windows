set moduleName combinar
set isTopModule 0
set isTaskLevelControl 1
set isCombinational 0
set isDatapathOnly 0
set isFreeRunPipelineModule 0
set isPipelined 0
set pipeline_type none
set FunctionProtocol ap_ctrl_hs
set isOneStateSeq 0
set ProfileFlag 0
set StallSigGenFlag 0
set isEnableWaveformDebug 1
set C_modelName {combinar}
set C_modelType { void 0 }
set C_modelArgList {
	{ result_V_V int 11 regular {fifo 1 volatile }  }
	{ in1_V_V int 11 regular {fifo 0 volatile } {global 0}  }
	{ in2_V_V int 11 regular {fifo 0 volatile } {global 0}  }
	{ in1b_V_V int 11 regular {fifo 0 volatile } {global 0}  }
	{ in2b_V_V int 11 regular {fifo 0 volatile } {global 0}  }
}
set C_modelArgMapList {[ 
	{ "Name" : "result_V_V", "interface" : "fifo", "bitwidth" : 11, "direction" : "WRITEONLY"} , 
 	{ "Name" : "in1_V_V", "interface" : "fifo", "bitwidth" : 11, "direction" : "READONLY", "extern" : 0} , 
 	{ "Name" : "in2_V_V", "interface" : "fifo", "bitwidth" : 11, "direction" : "READONLY", "extern" : 0} , 
 	{ "Name" : "in1b_V_V", "interface" : "fifo", "bitwidth" : 11, "direction" : "READONLY", "extern" : 0} , 
 	{ "Name" : "in2b_V_V", "interface" : "fifo", "bitwidth" : 11, "direction" : "READONLY", "extern" : 0} ]}
# RTL Port declarations: 
set portNum 22
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_continue sc_in sc_logic 1 continue -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ result_V_V_din sc_out sc_lv 11 signal 0 } 
	{ result_V_V_full_n sc_in sc_logic 1 signal 0 } 
	{ result_V_V_write sc_out sc_logic 1 signal 0 } 
	{ in1_V_V_dout sc_in sc_lv 11 signal 1 } 
	{ in1_V_V_empty_n sc_in sc_logic 1 signal 1 } 
	{ in1_V_V_read sc_out sc_logic 1 signal 1 } 
	{ in2_V_V_dout sc_in sc_lv 11 signal 2 } 
	{ in2_V_V_empty_n sc_in sc_logic 1 signal 2 } 
	{ in2_V_V_read sc_out sc_logic 1 signal 2 } 
	{ in1b_V_V_dout sc_in sc_lv 11 signal 3 } 
	{ in1b_V_V_empty_n sc_in sc_logic 1 signal 3 } 
	{ in1b_V_V_read sc_out sc_logic 1 signal 3 } 
	{ in2b_V_V_dout sc_in sc_lv 11 signal 4 } 
	{ in2b_V_V_empty_n sc_in sc_logic 1 signal 4 } 
	{ in2b_V_V_read sc_out sc_logic 1 signal 4 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_continue", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "continue", "bundle":{"name": "ap_continue", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "result_V_V_din", "direction": "out", "datatype": "sc_lv", "bitwidth":11, "type": "signal", "bundle":{"name": "result_V_V", "role": "din" }} , 
 	{ "name": "result_V_V_full_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "result_V_V", "role": "full_n" }} , 
 	{ "name": "result_V_V_write", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "result_V_V", "role": "write" }} , 
 	{ "name": "in1_V_V_dout", "direction": "in", "datatype": "sc_lv", "bitwidth":11, "type": "signal", "bundle":{"name": "in1_V_V", "role": "dout" }} , 
 	{ "name": "in1_V_V_empty_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "in1_V_V", "role": "empty_n" }} , 
 	{ "name": "in1_V_V_read", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "in1_V_V", "role": "read" }} , 
 	{ "name": "in2_V_V_dout", "direction": "in", "datatype": "sc_lv", "bitwidth":11, "type": "signal", "bundle":{"name": "in2_V_V", "role": "dout" }} , 
 	{ "name": "in2_V_V_empty_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "in2_V_V", "role": "empty_n" }} , 
 	{ "name": "in2_V_V_read", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "in2_V_V", "role": "read" }} , 
 	{ "name": "in1b_V_V_dout", "direction": "in", "datatype": "sc_lv", "bitwidth":11, "type": "signal", "bundle":{"name": "in1b_V_V", "role": "dout" }} , 
 	{ "name": "in1b_V_V_empty_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "in1b_V_V", "role": "empty_n" }} , 
 	{ "name": "in1b_V_V_read", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "in1b_V_V", "role": "read" }} , 
 	{ "name": "in2b_V_V_dout", "direction": "in", "datatype": "sc_lv", "bitwidth":11, "type": "signal", "bundle":{"name": "in2b_V_V", "role": "dout" }} , 
 	{ "name": "in2b_V_V_empty_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "in2b_V_V", "role": "empty_n" }} , 
 	{ "name": "in2b_V_V_read", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "in2b_V_V", "role": "read" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "",
		"CDFG" : "combinar",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "1", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "-1", "EstimateLatencyMax" : "-1",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "1",
		"HasNonBlockingOperation" : "1",
		"Port" : [
			{"Name" : "result_V_V", "Type" : "Fifo", "Direction" : "O",
				"BlockSignal" : [
					{"Name" : "result_V_V_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "in1_V_V", "Type" : "Fifo", "Direction" : "I", "DependentProc" : "0", "DependentChan" : "0"},
			{"Name" : "in2_V_V", "Type" : "Fifo", "Direction" : "I", "DependentProc" : "0", "DependentChan" : "0"},
			{"Name" : "in1b_V_V", "Type" : "Fifo", "Direction" : "I", "DependentProc" : "0", "DependentChan" : "0"},
			{"Name" : "in2b_V_V", "Type" : "Fifo", "Direction" : "I", "DependentProc" : "0", "DependentChan" : "0"}]}]}


set ArgLastReadFirstWriteLatency {
	combinar {
		result_V_V {Type O LastRead -1 FirstWrite 2}
		in1_V_V {Type I LastRead 1 FirstWrite -1}
		in2_V_V {Type I LastRead 1 FirstWrite -1}
		in1b_V_V {Type I LastRead 1 FirstWrite -1}
		in2b_V_V {Type I LastRead 1 FirstWrite -1}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "-1", "Max" : "-1"}
	, {"Name" : "Interval", "Min" : "-1", "Max" : "-1"}
]}

set PipelineEnableSignalInfo {[
	{"Pipeline" : "0", "EnableSignal" : "ap_enable_pp0"}
]}

set Spec2ImplPortList { 
	result_V_V { ap_fifo {  { result_V_V_din fifo_data 1 11 }  { result_V_V_full_n fifo_status 0 1 }  { result_V_V_write fifo_update 1 1 } } }
	in1_V_V { ap_fifo {  { in1_V_V_dout fifo_data 0 11 }  { in1_V_V_empty_n fifo_status 0 1 }  { in1_V_V_read fifo_update 1 1 } } }
	in2_V_V { ap_fifo {  { in2_V_V_dout fifo_data 0 11 }  { in2_V_V_empty_n fifo_status 0 1 }  { in2_V_V_read fifo_update 1 1 } } }
	in1b_V_V { ap_fifo {  { in1b_V_V_dout fifo_data 0 11 }  { in1b_V_V_empty_n fifo_status 0 1 }  { in1b_V_V_read fifo_update 1 1 } } }
	in2b_V_V { ap_fifo {  { in2b_V_V_dout fifo_data 0 11 }  { in2b_V_V_empty_n fifo_status 0 1 }  { in2b_V_V_read fifo_update 1 1 } } }
}
