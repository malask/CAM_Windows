set moduleName top_function_entry43
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
set C_modelName {top_function.entry43}
set C_modelType { void 0 }
set C_modelArgList {
	{ nodo_V int 11 regular {fifo 0}  }
	{ relationship_V int 2 regular {fifo 0}  }
	{ fatherSearch int 1 regular {fifo 0}  }
	{ nodo_V_out int 11 regular {fifo 1}  }
	{ nodo_V_out1 int 11 regular {fifo 1}  }
	{ relationship_V_out int 2 regular {fifo 1}  }
	{ relationship_V_out2 int 2 regular {fifo 1}  }
	{ fatherSearch_out int 1 regular {fifo 1}  }
	{ fatherSearch_out3 int 1 regular {fifo 1}  }
}
set C_modelArgMapList {[ 
	{ "Name" : "nodo_V", "interface" : "fifo", "bitwidth" : 11, "direction" : "READONLY"} , 
 	{ "Name" : "relationship_V", "interface" : "fifo", "bitwidth" : 2, "direction" : "READONLY"} , 
 	{ "Name" : "fatherSearch", "interface" : "fifo", "bitwidth" : 1, "direction" : "READONLY"} , 
 	{ "Name" : "nodo_V_out", "interface" : "fifo", "bitwidth" : 11, "direction" : "WRITEONLY"} , 
 	{ "Name" : "nodo_V_out1", "interface" : "fifo", "bitwidth" : 11, "direction" : "WRITEONLY"} , 
 	{ "Name" : "relationship_V_out", "interface" : "fifo", "bitwidth" : 2, "direction" : "WRITEONLY"} , 
 	{ "Name" : "relationship_V_out2", "interface" : "fifo", "bitwidth" : 2, "direction" : "WRITEONLY"} , 
 	{ "Name" : "fatherSearch_out", "interface" : "fifo", "bitwidth" : 1, "direction" : "WRITEONLY"} , 
 	{ "Name" : "fatherSearch_out3", "interface" : "fifo", "bitwidth" : 1, "direction" : "WRITEONLY"} ]}
# RTL Port declarations: 
set portNum 34
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_continue sc_in sc_logic 1 continue -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ nodo_V_dout sc_in sc_lv 11 signal 0 } 
	{ nodo_V_empty_n sc_in sc_logic 1 signal 0 } 
	{ nodo_V_read sc_out sc_logic 1 signal 0 } 
	{ relationship_V_dout sc_in sc_lv 2 signal 1 } 
	{ relationship_V_empty_n sc_in sc_logic 1 signal 1 } 
	{ relationship_V_read sc_out sc_logic 1 signal 1 } 
	{ fatherSearch_dout sc_in sc_lv 1 signal 2 } 
	{ fatherSearch_empty_n sc_in sc_logic 1 signal 2 } 
	{ fatherSearch_read sc_out sc_logic 1 signal 2 } 
	{ nodo_V_out_din sc_out sc_lv 11 signal 3 } 
	{ nodo_V_out_full_n sc_in sc_logic 1 signal 3 } 
	{ nodo_V_out_write sc_out sc_logic 1 signal 3 } 
	{ nodo_V_out1_din sc_out sc_lv 11 signal 4 } 
	{ nodo_V_out1_full_n sc_in sc_logic 1 signal 4 } 
	{ nodo_V_out1_write sc_out sc_logic 1 signal 4 } 
	{ relationship_V_out_din sc_out sc_lv 2 signal 5 } 
	{ relationship_V_out_full_n sc_in sc_logic 1 signal 5 } 
	{ relationship_V_out_write sc_out sc_logic 1 signal 5 } 
	{ relationship_V_out2_din sc_out sc_lv 2 signal 6 } 
	{ relationship_V_out2_full_n sc_in sc_logic 1 signal 6 } 
	{ relationship_V_out2_write sc_out sc_logic 1 signal 6 } 
	{ fatherSearch_out_din sc_out sc_lv 1 signal 7 } 
	{ fatherSearch_out_full_n sc_in sc_logic 1 signal 7 } 
	{ fatherSearch_out_write sc_out sc_logic 1 signal 7 } 
	{ fatherSearch_out3_din sc_out sc_lv 1 signal 8 } 
	{ fatherSearch_out3_full_n sc_in sc_logic 1 signal 8 } 
	{ fatherSearch_out3_write sc_out sc_logic 1 signal 8 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_continue", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "continue", "bundle":{"name": "ap_continue", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "nodo_V_dout", "direction": "in", "datatype": "sc_lv", "bitwidth":11, "type": "signal", "bundle":{"name": "nodo_V", "role": "dout" }} , 
 	{ "name": "nodo_V_empty_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "nodo_V", "role": "empty_n" }} , 
 	{ "name": "nodo_V_read", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "nodo_V", "role": "read" }} , 
 	{ "name": "relationship_V_dout", "direction": "in", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "relationship_V", "role": "dout" }} , 
 	{ "name": "relationship_V_empty_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "relationship_V", "role": "empty_n" }} , 
 	{ "name": "relationship_V_read", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "relationship_V", "role": "read" }} , 
 	{ "name": "fatherSearch_dout", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "fatherSearch", "role": "dout" }} , 
 	{ "name": "fatherSearch_empty_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "fatherSearch", "role": "empty_n" }} , 
 	{ "name": "fatherSearch_read", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "fatherSearch", "role": "read" }} , 
 	{ "name": "nodo_V_out_din", "direction": "out", "datatype": "sc_lv", "bitwidth":11, "type": "signal", "bundle":{"name": "nodo_V_out", "role": "din" }} , 
 	{ "name": "nodo_V_out_full_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "nodo_V_out", "role": "full_n" }} , 
 	{ "name": "nodo_V_out_write", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "nodo_V_out", "role": "write" }} , 
 	{ "name": "nodo_V_out1_din", "direction": "out", "datatype": "sc_lv", "bitwidth":11, "type": "signal", "bundle":{"name": "nodo_V_out1", "role": "din" }} , 
 	{ "name": "nodo_V_out1_full_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "nodo_V_out1", "role": "full_n" }} , 
 	{ "name": "nodo_V_out1_write", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "nodo_V_out1", "role": "write" }} , 
 	{ "name": "relationship_V_out_din", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "relationship_V_out", "role": "din" }} , 
 	{ "name": "relationship_V_out_full_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "relationship_V_out", "role": "full_n" }} , 
 	{ "name": "relationship_V_out_write", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "relationship_V_out", "role": "write" }} , 
 	{ "name": "relationship_V_out2_din", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "relationship_V_out2", "role": "din" }} , 
 	{ "name": "relationship_V_out2_full_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "relationship_V_out2", "role": "full_n" }} , 
 	{ "name": "relationship_V_out2_write", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "relationship_V_out2", "role": "write" }} , 
 	{ "name": "fatherSearch_out_din", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "fatherSearch_out", "role": "din" }} , 
 	{ "name": "fatherSearch_out_full_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "fatherSearch_out", "role": "full_n" }} , 
 	{ "name": "fatherSearch_out_write", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "fatherSearch_out", "role": "write" }} , 
 	{ "name": "fatherSearch_out3_din", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "fatherSearch_out3", "role": "din" }} , 
 	{ "name": "fatherSearch_out3_full_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "fatherSearch_out3", "role": "full_n" }} , 
 	{ "name": "fatherSearch_out3_write", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "fatherSearch_out3", "role": "write" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "",
		"CDFG" : "top_function_entry43",
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
			{"Name" : "nodo_V", "Type" : "Fifo", "Direction" : "I", "DependentProc" : "0", "DependentChan" : "0",
				"BlockSignal" : [
					{"Name" : "nodo_V_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "relationship_V", "Type" : "Fifo", "Direction" : "I", "DependentProc" : "0", "DependentChan" : "0",
				"BlockSignal" : [
					{"Name" : "relationship_V_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "fatherSearch", "Type" : "Fifo", "Direction" : "I", "DependentProc" : "0", "DependentChan" : "0",
				"BlockSignal" : [
					{"Name" : "fatherSearch_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "nodo_V_out", "Type" : "Fifo", "Direction" : "O", "DependentProc" : "0", "DependentChan" : "0",
				"BlockSignal" : [
					{"Name" : "nodo_V_out_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "nodo_V_out1", "Type" : "Fifo", "Direction" : "O", "DependentProc" : "0", "DependentChan" : "0",
				"BlockSignal" : [
					{"Name" : "nodo_V_out1_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "relationship_V_out", "Type" : "Fifo", "Direction" : "O", "DependentProc" : "0", "DependentChan" : "0",
				"BlockSignal" : [
					{"Name" : "relationship_V_out_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "relationship_V_out2", "Type" : "Fifo", "Direction" : "O", "DependentProc" : "0", "DependentChan" : "0",
				"BlockSignal" : [
					{"Name" : "relationship_V_out2_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "fatherSearch_out", "Type" : "Fifo", "Direction" : "O", "DependentProc" : "0", "DependentChan" : "0",
				"BlockSignal" : [
					{"Name" : "fatherSearch_out_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "fatherSearch_out3", "Type" : "Fifo", "Direction" : "O", "DependentProc" : "0", "DependentChan" : "0",
				"BlockSignal" : [
					{"Name" : "fatherSearch_out3_blk_n", "Type" : "RtlSignal"}]}]}]}


set ArgLastReadFirstWriteLatency {
	top_function_entry43 {
		nodo_V {Type I LastRead 0 FirstWrite -1}
		relationship_V {Type I LastRead 0 FirstWrite -1}
		fatherSearch {Type I LastRead 0 FirstWrite -1}
		nodo_V_out {Type O LastRead -1 FirstWrite 0}
		nodo_V_out1 {Type O LastRead -1 FirstWrite 0}
		relationship_V_out {Type O LastRead -1 FirstWrite 0}
		relationship_V_out2 {Type O LastRead -1 FirstWrite 0}
		fatherSearch_out {Type O LastRead -1 FirstWrite 0}
		fatherSearch_out3 {Type O LastRead -1 FirstWrite 0}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "0", "Max" : "0"}
	, {"Name" : "Interval", "Min" : "0", "Max" : "0"}
]}

set PipelineEnableSignalInfo {[
]}

set Spec2ImplPortList { 
	nodo_V { ap_fifo {  { nodo_V_dout fifo_data 0 11 }  { nodo_V_empty_n fifo_status 0 1 }  { nodo_V_read fifo_update 1 1 } } }
	relationship_V { ap_fifo {  { relationship_V_dout fifo_data 0 2 }  { relationship_V_empty_n fifo_status 0 1 }  { relationship_V_read fifo_update 1 1 } } }
	fatherSearch { ap_fifo {  { fatherSearch_dout fifo_data 0 1 }  { fatherSearch_empty_n fifo_status 0 1 }  { fatherSearch_read fifo_update 1 1 } } }
	nodo_V_out { ap_fifo {  { nodo_V_out_din fifo_data 1 11 }  { nodo_V_out_full_n fifo_status 0 1 }  { nodo_V_out_write fifo_update 1 1 } } }
	nodo_V_out1 { ap_fifo {  { nodo_V_out1_din fifo_data 1 11 }  { nodo_V_out1_full_n fifo_status 0 1 }  { nodo_V_out1_write fifo_update 1 1 } } }
	relationship_V_out { ap_fifo {  { relationship_V_out_din fifo_data 1 2 }  { relationship_V_out_full_n fifo_status 0 1 }  { relationship_V_out_write fifo_update 1 1 } } }
	relationship_V_out2 { ap_fifo {  { relationship_V_out2_din fifo_data 1 2 }  { relationship_V_out2_full_n fifo_status 0 1 }  { relationship_V_out2_write fifo_update 1 1 } } }
	fatherSearch_out { ap_fifo {  { fatherSearch_out_din fifo_data 1 1 }  { fatherSearch_out_full_n fifo_status 0 1 }  { fatherSearch_out_write fifo_update 1 1 } } }
	fatherSearch_out3 { ap_fifo {  { fatherSearch_out3_din fifo_data 1 1 }  { fatherSearch_out3_full_n fifo_status 0 1 }  { fatherSearch_out3_write fifo_update 1 1 } } }
}
