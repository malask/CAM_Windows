set moduleName top_function_entry3
set isTopModule 0
set isTaskLevelControl 1
set isCombinational 0
set isDatapathOnly 0
set isFreeRunPipelineModule 0
set isPipelined 0
set pipeline_type none
set FunctionProtocol ap_ctrl_hs
set isOneStateSeq 1
set ProfileFlag 0
set StallSigGenFlag 0
set isEnableWaveformDebug 1
set C_modelName {top_function.entry3}
set C_modelType { void 0 }
set C_modelArgList {
	{ nodo_V int 11 regular  }
	{ relationship_V int 2 regular  }
	{ fatherSearch int 1 regular  }
	{ nodo_V_out int 11 regular {fifo 1}  }
	{ relationship_V_out int 2 regular {fifo 1}  }
	{ fatherSearch_out int 1 regular {fifo 1}  }
}
set C_modelArgMapList {[ 
	{ "Name" : "nodo_V", "interface" : "wire", "bitwidth" : 11, "direction" : "READONLY"} , 
 	{ "Name" : "relationship_V", "interface" : "wire", "bitwidth" : 2, "direction" : "READONLY"} , 
 	{ "Name" : "fatherSearch", "interface" : "wire", "bitwidth" : 1, "direction" : "READONLY"} , 
 	{ "Name" : "nodo_V_out", "interface" : "fifo", "bitwidth" : 11, "direction" : "WRITEONLY"} , 
 	{ "Name" : "relationship_V_out", "interface" : "fifo", "bitwidth" : 2, "direction" : "WRITEONLY"} , 
 	{ "Name" : "fatherSearch_out", "interface" : "fifo", "bitwidth" : 1, "direction" : "WRITEONLY"} ]}
# RTL Port declarations: 
set portNum 19
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_continue sc_in sc_logic 1 continue -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ nodo_V sc_in sc_lv 11 signal 0 } 
	{ relationship_V sc_in sc_lv 2 signal 1 } 
	{ fatherSearch sc_in sc_lv 1 signal 2 } 
	{ nodo_V_out_din sc_out sc_lv 11 signal 3 } 
	{ nodo_V_out_full_n sc_in sc_logic 1 signal 3 } 
	{ nodo_V_out_write sc_out sc_logic 1 signal 3 } 
	{ relationship_V_out_din sc_out sc_lv 2 signal 4 } 
	{ relationship_V_out_full_n sc_in sc_logic 1 signal 4 } 
	{ relationship_V_out_write sc_out sc_logic 1 signal 4 } 
	{ fatherSearch_out_din sc_out sc_lv 1 signal 5 } 
	{ fatherSearch_out_full_n sc_in sc_logic 1 signal 5 } 
	{ fatherSearch_out_write sc_out sc_logic 1 signal 5 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_continue", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "continue", "bundle":{"name": "ap_continue", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "nodo_V", "direction": "in", "datatype": "sc_lv", "bitwidth":11, "type": "signal", "bundle":{"name": "nodo_V", "role": "default" }} , 
 	{ "name": "relationship_V", "direction": "in", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "relationship_V", "role": "default" }} , 
 	{ "name": "fatherSearch", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "fatherSearch", "role": "default" }} , 
 	{ "name": "nodo_V_out_din", "direction": "out", "datatype": "sc_lv", "bitwidth":11, "type": "signal", "bundle":{"name": "nodo_V_out", "role": "din" }} , 
 	{ "name": "nodo_V_out_full_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "nodo_V_out", "role": "full_n" }} , 
 	{ "name": "nodo_V_out_write", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "nodo_V_out", "role": "write" }} , 
 	{ "name": "relationship_V_out_din", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "relationship_V_out", "role": "din" }} , 
 	{ "name": "relationship_V_out_full_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "relationship_V_out", "role": "full_n" }} , 
 	{ "name": "relationship_V_out_write", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "relationship_V_out", "role": "write" }} , 
 	{ "name": "fatherSearch_out_din", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "fatherSearch_out", "role": "din" }} , 
 	{ "name": "fatherSearch_out_full_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "fatherSearch_out", "role": "full_n" }} , 
 	{ "name": "fatherSearch_out_write", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "fatherSearch_out", "role": "write" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "",
		"CDFG" : "top_function_entry3",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "1", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "1",
		"VariableLatency" : "0", "ExactLatency" : "0", "EstimateLatencyMin" : "0", "EstimateLatencyMax" : "0",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "1",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "nodo_V", "Type" : "None", "Direction" : "I"},
			{"Name" : "relationship_V", "Type" : "None", "Direction" : "I"},
			{"Name" : "fatherSearch", "Type" : "None", "Direction" : "I"},
			{"Name" : "nodo_V_out", "Type" : "Fifo", "Direction" : "O", "DependentProc" : "0", "DependentChan" : "0",
				"BlockSignal" : [
					{"Name" : "nodo_V_out_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "relationship_V_out", "Type" : "Fifo", "Direction" : "O", "DependentProc" : "0", "DependentChan" : "0",
				"BlockSignal" : [
					{"Name" : "relationship_V_out_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "fatherSearch_out", "Type" : "Fifo", "Direction" : "O", "DependentProc" : "0", "DependentChan" : "0",
				"BlockSignal" : [
					{"Name" : "fatherSearch_out_blk_n", "Type" : "RtlSignal"}]}]}]}


set ArgLastReadFirstWriteLatency {
	top_function_entry3 {
		nodo_V {Type I LastRead 0 FirstWrite -1}
		relationship_V {Type I LastRead 0 FirstWrite -1}
		fatherSearch {Type I LastRead 0 FirstWrite -1}
		nodo_V_out {Type O LastRead -1 FirstWrite 0}
		relationship_V_out {Type O LastRead -1 FirstWrite 0}
		fatherSearch_out {Type O LastRead -1 FirstWrite 0}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "0", "Max" : "0"}
	, {"Name" : "Interval", "Min" : "0", "Max" : "0"}
]}

set PipelineEnableSignalInfo {[
]}

set Spec2ImplPortList { 
	nodo_V { ap_none {  { nodo_V in_data 0 11 } } }
	relationship_V { ap_none {  { relationship_V in_data 0 2 } } }
	fatherSearch { ap_none {  { fatherSearch in_data 0 1 } } }
	nodo_V_out { ap_fifo {  { nodo_V_out_din fifo_data 1 11 }  { nodo_V_out_full_n fifo_status 0 1 }  { nodo_V_out_write fifo_update 1 1 } } }
	relationship_V_out { ap_fifo {  { relationship_V_out_din fifo_data 1 2 }  { relationship_V_out_full_n fifo_status 0 1 }  { relationship_V_out_write fifo_update 1 1 } } }
	fatherSearch_out { ap_fifo {  { fatherSearch_out_din fifo_data 1 1 }  { fatherSearch_out_full_n fifo_status 0 1 }  { fatherSearch_out_write fifo_update 1 1 } } }
}
