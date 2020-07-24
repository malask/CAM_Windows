set moduleName top_function
set isTopModule 1
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
set C_modelName {top_function}
set C_modelType { void 0 }
set C_modelArgList {
	{ tree_V int 24 regular {array 1024 { 1 1 } 1 1 }  }
	{ nodo_V int 11 regular  }
	{ relationship_V int 2 regular  }
	{ fatherSearch uint 1 regular  }
	{ result_V_V int 11 regular {fifo 1 volatile }  }
}
set C_modelArgMapList {[ 
	{ "Name" : "tree_V", "interface" : "memory", "bitwidth" : 24, "direction" : "READONLY", "bitSlice":[{"low":0,"up":23,"cElement": [{"cName": "tree.V","cData": "uint24","bit_use": { "low": 0,"up": 23},"cArray": [{"low" : 0,"up" : 1023,"step" : 1}]}]}]} , 
 	{ "Name" : "nodo_V", "interface" : "wire", "bitwidth" : 11, "direction" : "READONLY", "bitSlice":[{"low":0,"up":10,"cElement": [{"cName": "nodo.V","cData": "uint11","bit_use": { "low": 0,"up": 10},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}]} , 
 	{ "Name" : "relationship_V", "interface" : "wire", "bitwidth" : 2, "direction" : "READONLY", "bitSlice":[{"low":0,"up":1,"cElement": [{"cName": "relationship.V","cData": "uint2","bit_use": { "low": 0,"up": 1},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}]} , 
 	{ "Name" : "fatherSearch", "interface" : "wire", "bitwidth" : 1, "direction" : "READONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "fatherSearch","cData": "bool","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}]} , 
 	{ "Name" : "result_V_V", "interface" : "fifo", "bitwidth" : 11, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":10,"cElement": [{"cName": "result.V.V","cData": "uint11","bit_use": { "low": 0,"up": 10},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} ]}
# RTL Port declarations: 
set portNum 18
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ tree_V_address0 sc_out sc_lv 10 signal 0 } 
	{ tree_V_ce0 sc_out sc_logic 1 signal 0 } 
	{ tree_V_q0 sc_in sc_lv 24 signal 0 } 
	{ tree_V_address1 sc_out sc_lv 10 signal 0 } 
	{ tree_V_ce1 sc_out sc_logic 1 signal 0 } 
	{ tree_V_q1 sc_in sc_lv 24 signal 0 } 
	{ nodo_V sc_in sc_lv 11 signal 1 } 
	{ relationship_V sc_in sc_lv 2 signal 2 } 
	{ fatherSearch sc_in sc_logic 1 signal 3 } 
	{ result_V_V_din sc_out sc_lv 11 signal 4 } 
	{ result_V_V_full_n sc_in sc_logic 1 signal 4 } 
	{ result_V_V_write sc_out sc_logic 1 signal 4 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "tree_V_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":10, "type": "signal", "bundle":{"name": "tree_V", "role": "address0" }} , 
 	{ "name": "tree_V_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "tree_V", "role": "ce0" }} , 
 	{ "name": "tree_V_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":24, "type": "signal", "bundle":{"name": "tree_V", "role": "q0" }} , 
 	{ "name": "tree_V_address1", "direction": "out", "datatype": "sc_lv", "bitwidth":10, "type": "signal", "bundle":{"name": "tree_V", "role": "address1" }} , 
 	{ "name": "tree_V_ce1", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "tree_V", "role": "ce1" }} , 
 	{ "name": "tree_V_q1", "direction": "in", "datatype": "sc_lv", "bitwidth":24, "type": "signal", "bundle":{"name": "tree_V", "role": "q1" }} , 
 	{ "name": "nodo_V", "direction": "in", "datatype": "sc_lv", "bitwidth":11, "type": "signal", "bundle":{"name": "nodo_V", "role": "default" }} , 
 	{ "name": "relationship_V", "direction": "in", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "relationship_V", "role": "default" }} , 
 	{ "name": "fatherSearch", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "fatherSearch", "role": "default" }} , 
 	{ "name": "result_V_V_din", "direction": "out", "datatype": "sc_lv", "bitwidth":11, "type": "signal", "bundle":{"name": "result_V_V", "role": "din" }} , 
 	{ "name": "result_V_V_full_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "result_V_V", "role": "full_n" }} , 
 	{ "name": "result_V_V_write", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "result_V_V", "role": "write" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1"],
		"CDFG" : "top_function",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "2", "EstimateLatencyMax" : "1028",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"WaitState" : [
			{"State" : "ap_ST_fsm_state2", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_busqueda_cam_fu_64"}],
		"Port" : [
			{"Name" : "tree_V", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "1", "SubInstance" : "grp_busqueda_cam_fu_64", "Port" : "tree_V"}]},
			{"Name" : "nodo_V", "Type" : "None", "Direction" : "I"},
			{"Name" : "relationship_V", "Type" : "None", "Direction" : "I"},
			{"Name" : "fatherSearch", "Type" : "None", "Direction" : "I"},
			{"Name" : "result_V_V", "Type" : "Fifo", "Direction" : "O",
				"SubConnect" : [
					{"ID" : "1", "SubInstance" : "grp_busqueda_cam_fu_64", "Port" : "result_V_V"}]}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_busqueda_cam_fu_64", "Parent" : "0",
		"CDFG" : "busqueda_cam",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "1", "EstimateLatencyMax" : "1027",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "tree_V", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "nodo_V", "Type" : "None", "Direction" : "I"},
			{"Name" : "relationship_V", "Type" : "None", "Direction" : "I"},
			{"Name" : "fatherSearch", "Type" : "None", "Direction" : "I"},
			{"Name" : "result_V_V", "Type" : "Fifo", "Direction" : "O",
				"BlockSignal" : [
					{"Name" : "result_V_V_blk_n", "Type" : "RtlSignal"}]}]}]}


set ArgLastReadFirstWriteLatency {
	top_function {
		tree_V {Type I LastRead 2 FirstWrite -1}
		nodo_V {Type I LastRead 0 FirstWrite -1}
		relationship_V {Type I LastRead 0 FirstWrite -1}
		fatherSearch {Type I LastRead 0 FirstWrite -1}
		result_V_V {Type O LastRead -1 FirstWrite 0}}
	busqueda_cam {
		tree_V {Type I LastRead 2 FirstWrite -1}
		nodo_V {Type I LastRead 0 FirstWrite -1}
		relationship_V {Type I LastRead 0 FirstWrite -1}
		fatherSearch {Type I LastRead 0 FirstWrite -1}
		result_V_V {Type O LastRead -1 FirstWrite 0}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "2", "Max" : "1028"}
	, {"Name" : "Interval", "Min" : "3", "Max" : "1029"}
]}

set PipelineEnableSignalInfo {[
]}

set Spec2ImplPortList { 
	tree_V { ap_memory {  { tree_V_address0 mem_address 1 10 }  { tree_V_ce0 mem_ce 1 1 }  { tree_V_q0 mem_dout 0 24 }  { tree_V_address1 MemPortADDR2 1 10 }  { tree_V_ce1 MemPortCE2 1 1 }  { tree_V_q1 MemPortDOUT2 0 24 } } }
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
