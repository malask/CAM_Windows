set moduleName top_function
set isTopModule 1
set isTaskLevelControl 1
set isCombinational 0
set isDatapathOnly 0
set isFreeRunPipelineModule 0
set isPipelined 1
set pipeline_type dataflow
set FunctionProtocol ap_ctrl_hs
set isOneStateSeq 0
set ProfileFlag 0
set StallSigGenFlag 0
set isEnableWaveformDebug 1
set C_modelName {top_function}
set C_modelType { void 0 }
set C_modelArgList {
	{ tree1_V int 24 regular {array 512 { 1 1 } 1 1 }  }
	{ tree2_V int 24 regular {array 1024 { 1 1 } 1 1 }  }
	{ nodo_V int 11 regular  }
	{ relationship_V int 2 regular  }
	{ fatherSearch uint 1 regular  }
	{ result_V_V int 11 regular {fifo 1 volatile }  }
}
set C_modelArgMapList {[ 
	{ "Name" : "tree1_V", "interface" : "memory", "bitwidth" : 24, "direction" : "READONLY", "bitSlice":[{"low":0,"up":23,"cElement": [{"cName": "tree1.V","cData": "uint24","bit_use": { "low": 0,"up": 23},"cArray": [{"low" : 0,"up" : 511,"step" : 1}]}]}]} , 
 	{ "Name" : "tree2_V", "interface" : "memory", "bitwidth" : 24, "direction" : "READONLY", "bitSlice":[{"low":0,"up":23,"cElement": [{"cName": "tree2.V","cData": "uint24","bit_use": { "low": 0,"up": 23},"cArray": [{"low" : 0,"up" : 1023,"step" : 1}]}]}]} , 
 	{ "Name" : "nodo_V", "interface" : "wire", "bitwidth" : 11, "direction" : "READONLY", "bitSlice":[{"low":0,"up":10,"cElement": [{"cName": "nodo.V","cData": "uint11","bit_use": { "low": 0,"up": 10},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}]} , 
 	{ "Name" : "relationship_V", "interface" : "wire", "bitwidth" : 2, "direction" : "READONLY", "bitSlice":[{"low":0,"up":1,"cElement": [{"cName": "relationship.V","cData": "uint2","bit_use": { "low": 0,"up": 1},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}]} , 
 	{ "Name" : "fatherSearch", "interface" : "wire", "bitwidth" : 1, "direction" : "READONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "fatherSearch","cData": "bool","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}]} , 
 	{ "Name" : "result_V_V", "interface" : "fifo", "bitwidth" : 11, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":10,"cElement": [{"cName": "result.V.V","cData": "uint11","bit_use": { "low": 0,"up": 10},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} ]}
# RTL Port declarations: 
set portNum 32
set portList { 
	{ tree1_V_address0 sc_out sc_lv 9 signal 0 } 
	{ tree1_V_ce0 sc_out sc_logic 1 signal 0 } 
	{ tree1_V_d0 sc_out sc_lv 24 signal 0 } 
	{ tree1_V_q0 sc_in sc_lv 24 signal 0 } 
	{ tree1_V_we0 sc_out sc_logic 1 signal 0 } 
	{ tree1_V_address1 sc_out sc_lv 9 signal 0 } 
	{ tree1_V_ce1 sc_out sc_logic 1 signal 0 } 
	{ tree1_V_d1 sc_out sc_lv 24 signal 0 } 
	{ tree1_V_q1 sc_in sc_lv 24 signal 0 } 
	{ tree1_V_we1 sc_out sc_logic 1 signal 0 } 
	{ tree2_V_address0 sc_out sc_lv 10 signal 1 } 
	{ tree2_V_ce0 sc_out sc_logic 1 signal 1 } 
	{ tree2_V_d0 sc_out sc_lv 24 signal 1 } 
	{ tree2_V_q0 sc_in sc_lv 24 signal 1 } 
	{ tree2_V_we0 sc_out sc_logic 1 signal 1 } 
	{ tree2_V_address1 sc_out sc_lv 10 signal 1 } 
	{ tree2_V_ce1 sc_out sc_logic 1 signal 1 } 
	{ tree2_V_d1 sc_out sc_lv 24 signal 1 } 
	{ tree2_V_q1 sc_in sc_lv 24 signal 1 } 
	{ tree2_V_we1 sc_out sc_logic 1 signal 1 } 
	{ nodo_V sc_in sc_lv 11 signal 2 } 
	{ relationship_V sc_in sc_lv 2 signal 3 } 
	{ fatherSearch sc_in sc_logic 1 signal 4 } 
	{ result_V_V_din sc_out sc_lv 11 signal 5 } 
	{ result_V_V_full_n sc_in sc_logic 1 signal 5 } 
	{ result_V_V_write sc_out sc_logic 1 signal 5 } 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
}
set NewPortList {[ 
	{ "name": "tree1_V_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":9, "type": "signal", "bundle":{"name": "tree1_V", "role": "address0" }} , 
 	{ "name": "tree1_V_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "tree1_V", "role": "ce0" }} , 
 	{ "name": "tree1_V_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":24, "type": "signal", "bundle":{"name": "tree1_V", "role": "d0" }} , 
 	{ "name": "tree1_V_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":24, "type": "signal", "bundle":{"name": "tree1_V", "role": "q0" }} , 
 	{ "name": "tree1_V_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "tree1_V", "role": "we0" }} , 
 	{ "name": "tree1_V_address1", "direction": "out", "datatype": "sc_lv", "bitwidth":9, "type": "signal", "bundle":{"name": "tree1_V", "role": "address1" }} , 
 	{ "name": "tree1_V_ce1", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "tree1_V", "role": "ce1" }} , 
 	{ "name": "tree1_V_d1", "direction": "out", "datatype": "sc_lv", "bitwidth":24, "type": "signal", "bundle":{"name": "tree1_V", "role": "d1" }} , 
 	{ "name": "tree1_V_q1", "direction": "in", "datatype": "sc_lv", "bitwidth":24, "type": "signal", "bundle":{"name": "tree1_V", "role": "q1" }} , 
 	{ "name": "tree1_V_we1", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "tree1_V", "role": "we1" }} , 
 	{ "name": "tree2_V_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":10, "type": "signal", "bundle":{"name": "tree2_V", "role": "address0" }} , 
 	{ "name": "tree2_V_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "tree2_V", "role": "ce0" }} , 
 	{ "name": "tree2_V_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":24, "type": "signal", "bundle":{"name": "tree2_V", "role": "d0" }} , 
 	{ "name": "tree2_V_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":24, "type": "signal", "bundle":{"name": "tree2_V", "role": "q0" }} , 
 	{ "name": "tree2_V_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "tree2_V", "role": "we0" }} , 
 	{ "name": "tree2_V_address1", "direction": "out", "datatype": "sc_lv", "bitwidth":10, "type": "signal", "bundle":{"name": "tree2_V", "role": "address1" }} , 
 	{ "name": "tree2_V_ce1", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "tree2_V", "role": "ce1" }} , 
 	{ "name": "tree2_V_d1", "direction": "out", "datatype": "sc_lv", "bitwidth":24, "type": "signal", "bundle":{"name": "tree2_V", "role": "d1" }} , 
 	{ "name": "tree2_V_q1", "direction": "in", "datatype": "sc_lv", "bitwidth":24, "type": "signal", "bundle":{"name": "tree2_V", "role": "q1" }} , 
 	{ "name": "tree2_V_we1", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "tree2_V", "role": "we1" }} , 
 	{ "name": "nodo_V", "direction": "in", "datatype": "sc_lv", "bitwidth":11, "type": "signal", "bundle":{"name": "nodo_V", "role": "default" }} , 
 	{ "name": "relationship_V", "direction": "in", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "relationship_V", "role": "default" }} , 
 	{ "name": "fatherSearch", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "fatherSearch", "role": "default" }} , 
 	{ "name": "result_V_V_din", "direction": "out", "datatype": "sc_lv", "bitwidth":11, "type": "signal", "bundle":{"name": "result_V_V", "role": "din" }} , 
 	{ "name": "result_V_V_full_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "result_V_V", "role": "full_n" }} , 
 	{ "name": "result_V_V_write", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "result_V_V", "role": "write" }} , 
 	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20"],
		"CDFG" : "top_function",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "Dataflow", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "1",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "-1", "EstimateLatencyMax" : "-1",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "1",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"InputProcess" : [
			{"ID" : "1", "Name" : "top_function_entry3_U0", "ReadyCount" : "top_function_entry3_U0_ap_ready_count"},
			{"ID" : "3", "Name" : "busqueda_cam_1_U0", "ReadyCount" : "busqueda_cam_1_U0_ap_ready_count"},
			{"ID" : "4", "Name" : "busqueda_cam_U0", "ReadyCount" : "busqueda_cam_U0_ap_ready_count"}],
		"OutputProcess" : [
			{"ID" : "5", "Name" : "combinar_U0"}],
		"Port" : [
			{"Name" : "tree1_V", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "3", "SubInstance" : "busqueda_cam_1_U0", "Port" : "tree_V"}]},
			{"Name" : "tree2_V", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "4", "SubInstance" : "busqueda_cam_U0", "Port" : "tree_V"}]},
			{"Name" : "nodo_V", "Type" : "None", "Direction" : "I"},
			{"Name" : "relationship_V", "Type" : "None", "Direction" : "I"},
			{"Name" : "fatherSearch", "Type" : "None", "Direction" : "I"},
			{"Name" : "result_V_V", "Type" : "Fifo", "Direction" : "O",
				"SubConnect" : [
					{"ID" : "5", "SubInstance" : "combinar_U0", "Port" : "result_V_V"}]},
			{"Name" : "in1_V_V", "Type" : "Fifo", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "3", "SubInstance" : "busqueda_cam_1_U0", "Port" : "in1_V_V"},
					{"ID" : "5", "SubInstance" : "combinar_U0", "Port" : "in1_V_V"}]},
			{"Name" : "in1b_V_V", "Type" : "Fifo", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "3", "SubInstance" : "busqueda_cam_1_U0", "Port" : "in1b_V_V"},
					{"ID" : "5", "SubInstance" : "combinar_U0", "Port" : "in1b_V_V"}]},
			{"Name" : "in2_V_V", "Type" : "Fifo", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "4", "SubInstance" : "busqueda_cam_U0", "Port" : "in2_V_V"},
					{"ID" : "5", "SubInstance" : "combinar_U0", "Port" : "in2_V_V"}]},
			{"Name" : "in2b_V_V", "Type" : "Fifo", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "4", "SubInstance" : "busqueda_cam_U0", "Port" : "in2b_V_V"},
					{"ID" : "5", "SubInstance" : "combinar_U0", "Port" : "in2b_V_V"}]}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.top_function_entry3_U0", "Parent" : "0",
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
			{"Name" : "nodo_V_out", "Type" : "Fifo", "Direction" : "O", "DependentProc" : "2", "DependentChan" : "6",
				"BlockSignal" : [
					{"Name" : "nodo_V_out_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "relationship_V_out", "Type" : "Fifo", "Direction" : "O", "DependentProc" : "2", "DependentChan" : "7",
				"BlockSignal" : [
					{"Name" : "relationship_V_out_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "fatherSearch_out", "Type" : "Fifo", "Direction" : "O", "DependentProc" : "2", "DependentChan" : "8",
				"BlockSignal" : [
					{"Name" : "fatherSearch_out_blk_n", "Type" : "RtlSignal"}]}]},
	{"ID" : "2", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.top_function_entry43_U0", "Parent" : "0",
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
		"StartSource" : "1",
		"StartFifo" : "start_for_top_funbkb_U",
		"Port" : [
			{"Name" : "nodo_V", "Type" : "Fifo", "Direction" : "I", "DependentProc" : "1", "DependentChan" : "6",
				"BlockSignal" : [
					{"Name" : "nodo_V_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "relationship_V", "Type" : "Fifo", "Direction" : "I", "DependentProc" : "1", "DependentChan" : "7",
				"BlockSignal" : [
					{"Name" : "relationship_V_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "fatherSearch", "Type" : "Fifo", "Direction" : "I", "DependentProc" : "1", "DependentChan" : "8",
				"BlockSignal" : [
					{"Name" : "fatherSearch_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "nodo_V_out", "Type" : "Fifo", "Direction" : "O", "DependentProc" : "3", "DependentChan" : "9",
				"BlockSignal" : [
					{"Name" : "nodo_V_out_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "nodo_V_out1", "Type" : "Fifo", "Direction" : "O", "DependentProc" : "4", "DependentChan" : "10",
				"BlockSignal" : [
					{"Name" : "nodo_V_out1_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "relationship_V_out", "Type" : "Fifo", "Direction" : "O", "DependentProc" : "3", "DependentChan" : "11",
				"BlockSignal" : [
					{"Name" : "relationship_V_out_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "relationship_V_out2", "Type" : "Fifo", "Direction" : "O", "DependentProc" : "4", "DependentChan" : "12",
				"BlockSignal" : [
					{"Name" : "relationship_V_out2_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "fatherSearch_out", "Type" : "Fifo", "Direction" : "O", "DependentProc" : "3", "DependentChan" : "13",
				"BlockSignal" : [
					{"Name" : "fatherSearch_out_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "fatherSearch_out3", "Type" : "Fifo", "Direction" : "O", "DependentProc" : "4", "DependentChan" : "14",
				"BlockSignal" : [
					{"Name" : "fatherSearch_out3_blk_n", "Type" : "RtlSignal"}]}]},
	{"ID" : "3", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.busqueda_cam_1_U0", "Parent" : "0",
		"CDFG" : "busqueda_cam_1",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "1", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "1", "EstimateLatencyMax" : "259",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "1",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "tree_V", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "nodo_V", "Type" : "Fifo", "Direction" : "I", "DependentProc" : "2", "DependentChan" : "9",
				"BlockSignal" : [
					{"Name" : "nodo_V_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "relationship_V", "Type" : "Fifo", "Direction" : "I", "DependentProc" : "2", "DependentChan" : "11",
				"BlockSignal" : [
					{"Name" : "relationship_V_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "fatherSearch", "Type" : "Fifo", "Direction" : "I", "DependentProc" : "2", "DependentChan" : "13",
				"BlockSignal" : [
					{"Name" : "fatherSearch_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "in1_V_V", "Type" : "Fifo", "Direction" : "O", "DependentProc" : "5", "DependentChan" : "15",
				"BlockSignal" : [
					{"Name" : "in1_V_V_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "in1b_V_V", "Type" : "Fifo", "Direction" : "O", "DependentProc" : "5", "DependentChan" : "16",
				"BlockSignal" : [
					{"Name" : "in1b_V_V_blk_n", "Type" : "RtlSignal"}]}]},
	{"ID" : "4", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.busqueda_cam_U0", "Parent" : "0",
		"CDFG" : "busqueda_cam",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "1", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "1", "EstimateLatencyMax" : "259",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "1",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "tree_V", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "nodo_V", "Type" : "Fifo", "Direction" : "I", "DependentProc" : "2", "DependentChan" : "10",
				"BlockSignal" : [
					{"Name" : "nodo_V_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "relationship_V", "Type" : "Fifo", "Direction" : "I", "DependentProc" : "2", "DependentChan" : "12",
				"BlockSignal" : [
					{"Name" : "relationship_V_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "fatherSearch", "Type" : "Fifo", "Direction" : "I", "DependentProc" : "2", "DependentChan" : "14",
				"BlockSignal" : [
					{"Name" : "fatherSearch_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "in2_V_V", "Type" : "Fifo", "Direction" : "O", "DependentProc" : "5", "DependentChan" : "17",
				"BlockSignal" : [
					{"Name" : "in2_V_V_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "in2b_V_V", "Type" : "Fifo", "Direction" : "O", "DependentProc" : "5", "DependentChan" : "18",
				"BlockSignal" : [
					{"Name" : "in2b_V_V_blk_n", "Type" : "RtlSignal"}]}]},
	{"ID" : "5", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.combinar_U0", "Parent" : "0",
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
		"StartSource" : "3",
		"StartFifo" : "start_for_combinacud_U",
		"Port" : [
			{"Name" : "result_V_V", "Type" : "Fifo", "Direction" : "O",
				"BlockSignal" : [
					{"Name" : "result_V_V_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "in1_V_V", "Type" : "Fifo", "Direction" : "I", "DependentProc" : "3", "DependentChan" : "15"},
			{"Name" : "in2_V_V", "Type" : "Fifo", "Direction" : "I", "DependentProc" : "4", "DependentChan" : "17"},
			{"Name" : "in1b_V_V", "Type" : "Fifo", "Direction" : "I", "DependentProc" : "3", "DependentChan" : "16"},
			{"Name" : "in2b_V_V", "Type" : "Fifo", "Direction" : "I", "DependentProc" : "4", "DependentChan" : "18"}]},
	{"ID" : "6", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.nodo_V_c1_U", "Parent" : "0"},
	{"ID" : "7", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.relationship_V_c2_U", "Parent" : "0"},
	{"ID" : "8", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fatherSearch_c3_U", "Parent" : "0"},
	{"ID" : "9", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.nodo_V_c_U", "Parent" : "0"},
	{"ID" : "10", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.nodo_V_c7_U", "Parent" : "0"},
	{"ID" : "11", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.relationship_V_c_U", "Parent" : "0"},
	{"ID" : "12", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.relationship_V_c8_U", "Parent" : "0"},
	{"ID" : "13", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fatherSearch_c_U", "Parent" : "0"},
	{"ID" : "14", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fatherSearch_c9_U", "Parent" : "0"},
	{"ID" : "15", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.in1_V_V_U", "Parent" : "0"},
	{"ID" : "16", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.in1b_V_V_U", "Parent" : "0"},
	{"ID" : "17", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.in2_V_V_U", "Parent" : "0"},
	{"ID" : "18", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.in2b_V_V_U", "Parent" : "0"},
	{"ID" : "19", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.start_for_top_funbkb_U", "Parent" : "0"},
	{"ID" : "20", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.start_for_combinacud_U", "Parent" : "0"}]}


set ArgLastReadFirstWriteLatency {
	top_function {
		tree1_V {Type I LastRead 2 FirstWrite -1}
		tree2_V {Type I LastRead 2 FirstWrite -1}
		nodo_V {Type I LastRead 0 FirstWrite -1}
		relationship_V {Type I LastRead 0 FirstWrite -1}
		fatherSearch {Type I LastRead 0 FirstWrite -1}
		result_V_V {Type O LastRead -1 FirstWrite 2}
		in1_V_V {Type IO LastRead -1 FirstWrite -1}
		in1b_V_V {Type IO LastRead -1 FirstWrite -1}
		in2_V_V {Type IO LastRead -1 FirstWrite -1}
		in2b_V_V {Type IO LastRead -1 FirstWrite -1}}
	top_function_entry3 {
		nodo_V {Type I LastRead 0 FirstWrite -1}
		relationship_V {Type I LastRead 0 FirstWrite -1}
		fatherSearch {Type I LastRead 0 FirstWrite -1}
		nodo_V_out {Type O LastRead -1 FirstWrite 0}
		relationship_V_out {Type O LastRead -1 FirstWrite 0}
		fatherSearch_out {Type O LastRead -1 FirstWrite 0}}
	top_function_entry43 {
		nodo_V {Type I LastRead 0 FirstWrite -1}
		relationship_V {Type I LastRead 0 FirstWrite -1}
		fatherSearch {Type I LastRead 0 FirstWrite -1}
		nodo_V_out {Type O LastRead -1 FirstWrite 0}
		nodo_V_out1 {Type O LastRead -1 FirstWrite 0}
		relationship_V_out {Type O LastRead -1 FirstWrite 0}
		relationship_V_out2 {Type O LastRead -1 FirstWrite 0}
		fatherSearch_out {Type O LastRead -1 FirstWrite 0}
		fatherSearch_out3 {Type O LastRead -1 FirstWrite 0}}
	busqueda_cam_1 {
		tree_V {Type I LastRead 2 FirstWrite -1}
		nodo_V {Type I LastRead 0 FirstWrite -1}
		relationship_V {Type I LastRead 0 FirstWrite -1}
		fatherSearch {Type I LastRead 0 FirstWrite -1}
		in1_V_V {Type O LastRead -1 FirstWrite 0}
		in1b_V_V {Type O LastRead -1 FirstWrite 0}}
	busqueda_cam {
		tree_V {Type I LastRead 2 FirstWrite -1}
		nodo_V {Type I LastRead 0 FirstWrite -1}
		relationship_V {Type I LastRead 0 FirstWrite -1}
		fatherSearch {Type I LastRead 0 FirstWrite -1}
		in2_V_V {Type O LastRead -1 FirstWrite 0}
		in2b_V_V {Type O LastRead -1 FirstWrite 0}}
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
]}

set Spec2ImplPortList { 
	tree1_V { ap_memory {  { tree1_V_address0 mem_address 1 9 }  { tree1_V_ce0 mem_ce 1 1 }  { tree1_V_d0 mem_din 1 24 }  { tree1_V_q0 mem_dout 0 24 }  { tree1_V_we0 mem_we 1 1 }  { tree1_V_address1 MemPortADDR2 1 9 }  { tree1_V_ce1 MemPortCE2 1 1 }  { tree1_V_d1 mem_din 1 24 }  { tree1_V_q1 MemPortDOUT2 0 24 }  { tree1_V_we1 mem_we 1 1 } } }
	tree2_V { ap_memory {  { tree2_V_address0 mem_address 1 10 }  { tree2_V_ce0 mem_ce 1 1 }  { tree2_V_d0 mem_din 1 24 }  { tree2_V_q0 mem_dout 0 24 }  { tree2_V_we0 mem_we 1 1 }  { tree2_V_address1 MemPortADDR2 1 10 }  { tree2_V_ce1 MemPortCE2 1 1 }  { tree2_V_d1 mem_din 1 24 }  { tree2_V_q1 MemPortDOUT2 0 24 }  { tree2_V_we1 mem_we 1 1 } } }
	nodo_V { ap_none {  { nodo_V in_data 0 11 } } }
	relationship_V { ap_none {  { relationship_V in_data 0 2 } } }
	fatherSearch { ap_none {  { fatherSearch in_data 0 1 } } }
	result_V_V { ap_fifo {  { result_V_V_din fifo_data 1 11 }  { result_V_V_full_n fifo_status 0 1 }  { result_V_V_write fifo_update 1 1 } } }
}

set busDeadlockParameterList { 
}

# RTL port scheduling information:
set fifoSchedulingInfoList { 
	result_V_V { fifo_write 1 no_conditional }
}

# RTL bus port read request latency information:
set busReadReqLatencyList { 
}

# RTL bus port write response latency information:
set busWriteResLatencyList { 
}

# RTL array port load latency information:
set memoryLoadLatencyList { 
}
