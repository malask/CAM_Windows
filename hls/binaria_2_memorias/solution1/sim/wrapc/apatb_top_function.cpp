// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.1 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================

#define AP_INT_MAX_W 32678

#include <systemc>
#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <stdint.h>
#include "SysCFileHandler.h"
#include "ap_int.h"
#include "ap_fixed.h"
#include <complex>
#include <stdbool.h>
#include "autopilot_cbe.h"
#include "hls_stream.h"
#include "hls_half.h"
#include "hls_signal_handler.h"

using namespace std;
using namespace sc_core;
using namespace sc_dt;


// [dump_struct_tree [build_nameSpaceTree] dumpedStructList] ---------->


// [dump_enumeration [get_enumeration_list]] ---------->


// wrapc file define: "tree1_V"
#define AUTOTB_TVIN_tree1_V  "../tv/cdatafile/c.top_function.autotvin_tree1_V.dat"
// wrapc file define: "tree2_V"
#define AUTOTB_TVIN_tree2_V  "../tv/cdatafile/c.top_function.autotvin_tree2_V.dat"
// wrapc file define: "nodo_V"
#define AUTOTB_TVIN_nodo_V  "../tv/cdatafile/c.top_function.autotvin_nodo_V.dat"
// wrapc file define: "relationship_V"
#define AUTOTB_TVIN_relationship_V  "../tv/cdatafile/c.top_function.autotvin_relationship_V.dat"
// wrapc file define: "fatherSearch"
#define AUTOTB_TVIN_fatherSearch  "../tv/cdatafile/c.top_function.autotvin_fatherSearch.dat"
// wrapc file define: "result_V_V"
#define AUTOTB_TVOUT_result_V_V  "../tv/cdatafile/c.top_function.autotvout_result_V_V.dat"
#define AUTOTB_TVIN_result_V_V  "../tv/cdatafile/c.top_function.autotvin_result_V_V.dat"
#define WRAPC_STREAM_SIZE_OUT_result_V_V  "../tv/stream_size/stream_size_out_result_V_V.dat"
#define WRAPC_STREAM_EGRESS_STATUS_result_V_V  "../tv/stream_size/stream_egress_status_result_V_V.dat"

#define INTER_TCL  "../tv/cdatafile/ref.tcl"

// tvout file define: "result_V_V"
#define AUTOTB_TVOUT_PC_result_V_V  "../tv/rtldatafile/rtl.top_function.autotvout_result_V_V.dat"

class INTER_TCL_FILE {
	public:
		INTER_TCL_FILE(const char* name) {
			mName = name;
			tree1_V_depth = 0;
			tree2_V_depth = 0;
			nodo_V_depth = 0;
			relationship_V_depth = 0;
			fatherSearch_depth = 0;
			result_V_V_depth = 0;
			trans_num =0;
		}

		~INTER_TCL_FILE() {
			mFile.open(mName);
			if (!mFile.good()) {
				cout << "Failed to open file ref.tcl" << endl;
				exit (1);
			}
			string total_list = get_depth_list();
			mFile << "set depth_list {\n";
			mFile << total_list;
			mFile << "}\n";
			mFile << "set trans_num "<<trans_num<<endl;
			mFile.close();
		}

		string get_depth_list () {
			stringstream total_list;
			total_list << "{tree1_V " << tree1_V_depth << "}\n";
			total_list << "{tree2_V " << tree2_V_depth << "}\n";
			total_list << "{nodo_V " << nodo_V_depth << "}\n";
			total_list << "{relationship_V " << relationship_V_depth << "}\n";
			total_list << "{fatherSearch " << fatherSearch_depth << "}\n";
			total_list << "{result_V_V " << result_V_V_depth << "}\n";
			return total_list.str();
		}

		void set_num (int num , int* class_num) {
			(*class_num) = (*class_num) > num ? (*class_num) : num;
		}
	public:
		int tree1_V_depth;
		int tree2_V_depth;
		int nodo_V_depth;
		int relationship_V_depth;
		int fatherSearch_depth;
		int result_V_V_depth;
		int trans_num;

	private:
		ofstream mFile;
		const char* mName;
};

extern void top_function (
ap_uint<24> tree1[512],
ap_uint<24> tree2[1024],
ap_uint<11> nodo,
ap_uint<2> relationship,
bool fatherSearch,
hls::stream<ap_uint<11> > (&result));

void AESL_WRAP_top_function (
ap_uint<24> tree1[512],
ap_uint<24> tree2[1024],
ap_uint<11> nodo,
ap_uint<2> relationship,
bool fatherSearch,
hls::stream<ap_uint<11> > (&result))
{
	refine_signal_handler();
	fstream wrapc_switch_file_token;
	wrapc_switch_file_token.open(".hls_cosim_wrapc_switch.log");
	int AESL_i;
	if (wrapc_switch_file_token.good())
	{
		CodeState = ENTER_WRAPC_PC;
		static unsigned AESL_transaction_pc = 0;
		string AESL_token;
		string AESL_num;
		static AESL_FILE_HANDLER aesl_fh;

		// define output stream variables: "result"
		std::vector<ap_uint<11> > aesl_tmp_0;
		int aesl_tmp_1;
		int aesl_tmp_2 = 0;

		// read output stream size: "result"
		aesl_fh.read(WRAPC_STREAM_SIZE_OUT_result_V_V, AESL_token); // [[transaction]]
		aesl_fh.read(WRAPC_STREAM_SIZE_OUT_result_V_V, AESL_num); // transaction number

		if (atoi(AESL_num.c_str()) == AESL_transaction_pc)
		{
			aesl_fh.read(WRAPC_STREAM_SIZE_OUT_result_V_V, AESL_token); // pop_size
			aesl_tmp_1 = atoi(AESL_token.c_str());
			aesl_fh.read(WRAPC_STREAM_SIZE_OUT_result_V_V, AESL_token); // [[/transaction]]
		}

		// output port post check: "result_V_V"
		aesl_fh.read(AUTOTB_TVOUT_PC_result_V_V, AESL_token); // [[transaction]]
		if (AESL_token != "[[transaction]]")
		{
			exit(1);
		}
		aesl_fh.read(AUTOTB_TVOUT_PC_result_V_V, AESL_num); // transaction number

		if (atoi(AESL_num.c_str()) == AESL_transaction_pc)
		{
			aesl_fh.read(AUTOTB_TVOUT_PC_result_V_V, AESL_token); // data

			std::vector<sc_bv<11> > result_V_V_pc_buffer;
			int i = 0;

			while (AESL_token != "[[/transaction]]")
			{
				bool no_x = false;
				bool err = false;

				// search and replace 'X' with "0" from the 1st char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('X');
					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'result_V_V', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				no_x = false;

				// search and replace 'x' with "0" from the 3rd char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('x', 2);

					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'result_V_V', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				// push token into output port buffer
				if (AESL_token != "")
				{
					result_V_V_pc_buffer.push_back(AESL_token.c_str());
					i++;
				}

				aesl_fh.read(AUTOTB_TVOUT_PC_result_V_V, AESL_token); // data or [[/transaction]]

				if (AESL_token == "[[[/runtime]]]" || aesl_fh.eof(AUTOTB_TVOUT_PC_result_V_V))
				{
					exit(1);
				}
			}

			// correct the buffer size the current transaction
			if (i != aesl_tmp_1)
			{
				aesl_tmp_1 = i;
			}

			if (aesl_tmp_1 > 0 && aesl_tmp_0.size() < aesl_tmp_1)
			{
				int aesl_tmp_0_size = aesl_tmp_0.size();

				for (int tmp_aesl_tmp_0 = 0; tmp_aesl_tmp_0 < aesl_tmp_1 - aesl_tmp_0_size; tmp_aesl_tmp_0++)
				{
					ap_uint<11> tmp;
					aesl_tmp_0.push_back(tmp);
				}
			}

			// ***********************************
			if (i > 0)
			{
				// RTL Name: result_V_V
				{
					// bitslice(10, 0)
					// {
						// celement: result.V.V(10, 0)
						// {
							sc_lv<11>* result_V_V_lv0_0_0_1 = new sc_lv<11>[aesl_tmp_1 - aesl_tmp_2];
						// }
					// }

					// bitslice(10, 0)
					{
						int hls_map_index = 0;
						// celement: result.V.V(10, 0)
						{
							// carray: (aesl_tmp_2) => (aesl_tmp_1 - 1) @ (1)
							for (int i_0 = aesl_tmp_2; i_0 <= aesl_tmp_1 - 1; i_0 += 1)
							{
								if (&(aesl_tmp_0[0]) != NULL) // check the null address if the c port is array or others
								{
									result_V_V_lv0_0_0_1[hls_map_index].range(10, 0) = sc_bv<11>(result_V_V_pc_buffer[hls_map_index].range(10, 0));
									hls_map_index++;
								}
							}
						}
					}

					// bitslice(10, 0)
					{
						int hls_map_index = 0;
						// celement: result.V.V(10, 0)
						{
							// carray: (aesl_tmp_2) => (aesl_tmp_1 - 1) @ (1)
							for (int i_0 = aesl_tmp_2; i_0 <= aesl_tmp_1 - 1; i_0 += 1)
							{
								// sub                    : i_0
								// ori_name               : aesl_tmp_0[i_0]
								// sub_1st_elem           : 0
								// ori_name_1st_elem      : aesl_tmp_0[0]
								// output_left_conversion : aesl_tmp_0[i_0]
								// output_type_conversion : (result_V_V_lv0_0_0_1[hls_map_index]).to_string(SC_BIN).c_str()
								if (&(aesl_tmp_0[0]) != NULL) // check the null address if the c port is array or others
								{
									aesl_tmp_0[i_0] = (result_V_V_lv0_0_0_1[hls_map_index]).to_string(SC_BIN).c_str();
									hls_map_index++;
								}
							}
						}
					}
				}
			}
		}

		// push back output stream: "result"
		for (int i = 0; i < aesl_tmp_1; i++)
		{
			result.write(aesl_tmp_0[i]);
		}

		AESL_transaction_pc++;
	}
	else
	{
		CodeState = ENTER_WRAPC;
		static unsigned AESL_transaction;

		static AESL_FILE_HANDLER aesl_fh;

		// "tree1_V"
		char* tvin_tree1_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_tree1_V);

		// "tree2_V"
		char* tvin_tree2_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_tree2_V);

		// "nodo_V"
		char* tvin_nodo_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_nodo_V);

		// "relationship_V"
		char* tvin_relationship_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_relationship_V);

		// "fatherSearch"
		char* tvin_fatherSearch = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_fatherSearch);

		// "result_V_V"
		char* tvin_result_V_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_result_V_V);
		char* tvout_result_V_V = new char[50];
		aesl_fh.touch(AUTOTB_TVOUT_result_V_V);
		char* wrapc_stream_size_out_result_V_V = new char[50];
		aesl_fh.touch(WRAPC_STREAM_SIZE_OUT_result_V_V);
		char* wrapc_stream_egress_status_result_V_V = new char[50];
		aesl_fh.touch(WRAPC_STREAM_EGRESS_STATUS_result_V_V);

		CodeState = DUMP_INPUTS;
		static INTER_TCL_FILE tcl_file(INTER_TCL);
		int leading_zero;

		// dump stream tvin: "result"
		std::vector<ap_uint<11> > aesl_tmp_0;
		int aesl_tmp_1 = 0;
		while (!result.empty())
		{
			aesl_tmp_0.push_back(result.read());
			aesl_tmp_1++;
		}

		// [[transaction]]
		sprintf(tvin_tree1_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_tree1_V, tvin_tree1_V);

		sc_bv<24>* tree1_V_tvin_wrapc_buffer = new sc_bv<24>[512];

		// RTL Name: tree1_V
		{
			// bitslice(23, 0)
			{
				int hls_map_index = 0;
				// celement: tree1.V(23, 0)
				{
					// carray: (0) => (511) @ (1)
					for (int i_0 = 0; i_0 <= 511; i_0 += 1)
					{
						// sub                   : i_0
						// ori_name              : tree1[i_0]
						// sub_1st_elem          : 0
						// ori_name_1st_elem     : tree1[0]
						// regulate_c_name       : tree1_V
						// input_type_conversion : (tree1[i_0]).to_string(2).c_str()
						if (&(tree1[0]) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<24> tree1_V_tmp_mem;
							tree1_V_tmp_mem = (tree1[i_0]).to_string(2).c_str();
							tree1_V_tvin_wrapc_buffer[hls_map_index].range(23, 0) = tree1_V_tmp_mem.range(23, 0);
                                 	       hls_map_index++;
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 512; i++)
		{
			sprintf(tvin_tree1_V, "%s\n", (tree1_V_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_tree1_V, tvin_tree1_V);
		}

		tcl_file.set_num(512, &tcl_file.tree1_V_depth);
		sprintf(tvin_tree1_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_tree1_V, tvin_tree1_V);

		// release memory allocation
		delete [] tree1_V_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_tree2_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_tree2_V, tvin_tree2_V);

		sc_bv<24>* tree2_V_tvin_wrapc_buffer = new sc_bv<24>[1024];

		// RTL Name: tree2_V
		{
			// bitslice(23, 0)
			{
				int hls_map_index = 0;
				// celement: tree2.V(23, 0)
				{
					// carray: (0) => (1023) @ (1)
					for (int i_0 = 0; i_0 <= 1023; i_0 += 1)
					{
						// sub                   : i_0
						// ori_name              : tree2[i_0]
						// sub_1st_elem          : 0
						// ori_name_1st_elem     : tree2[0]
						// regulate_c_name       : tree2_V
						// input_type_conversion : (tree2[i_0]).to_string(2).c_str()
						if (&(tree2[0]) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<24> tree2_V_tmp_mem;
							tree2_V_tmp_mem = (tree2[i_0]).to_string(2).c_str();
							tree2_V_tvin_wrapc_buffer[hls_map_index].range(23, 0) = tree2_V_tmp_mem.range(23, 0);
                                 	       hls_map_index++;
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1024; i++)
		{
			sprintf(tvin_tree2_V, "%s\n", (tree2_V_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_tree2_V, tvin_tree2_V);
		}

		tcl_file.set_num(1024, &tcl_file.tree2_V_depth);
		sprintf(tvin_tree2_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_tree2_V, tvin_tree2_V);

		// release memory allocation
		delete [] tree2_V_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_nodo_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_nodo_V, tvin_nodo_V);

		sc_bv<11> nodo_V_tvin_wrapc_buffer;

		// RTL Name: nodo_V
		{
			// bitslice(10, 0)
			{
				// celement: nodo.V(10, 0)
				{
					// carray: (0) => (0) @ (0)
					{
						// sub                   : 
						// ori_name              : nodo
						// sub_1st_elem          : 
						// ori_name_1st_elem     : nodo
						// regulate_c_name       : nodo_V
						// input_type_conversion : (nodo).to_string(2).c_str()
						if (&(nodo) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<11> nodo_V_tmp_mem;
							nodo_V_tmp_mem = (nodo).to_string(2).c_str();
							nodo_V_tvin_wrapc_buffer.range(10, 0) = nodo_V_tmp_mem.range(10, 0);
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_nodo_V, "%s\n", (nodo_V_tvin_wrapc_buffer).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_nodo_V, tvin_nodo_V);
		}

		tcl_file.set_num(1, &tcl_file.nodo_V_depth);
		sprintf(tvin_nodo_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_nodo_V, tvin_nodo_V);

		// [[transaction]]
		sprintf(tvin_relationship_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_relationship_V, tvin_relationship_V);

		sc_bv<2> relationship_V_tvin_wrapc_buffer;

		// RTL Name: relationship_V
		{
			// bitslice(1, 0)
			{
				// celement: relationship.V(1, 0)
				{
					// carray: (0) => (0) @ (0)
					{
						// sub                   : 
						// ori_name              : relationship
						// sub_1st_elem          : 
						// ori_name_1st_elem     : relationship
						// regulate_c_name       : relationship_V
						// input_type_conversion : (relationship).to_string(2).c_str()
						if (&(relationship) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<2> relationship_V_tmp_mem;
							relationship_V_tmp_mem = (relationship).to_string(2).c_str();
							relationship_V_tvin_wrapc_buffer.range(1, 0) = relationship_V_tmp_mem.range(1, 0);
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_relationship_V, "%s\n", (relationship_V_tvin_wrapc_buffer).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_relationship_V, tvin_relationship_V);
		}

		tcl_file.set_num(1, &tcl_file.relationship_V_depth);
		sprintf(tvin_relationship_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_relationship_V, tvin_relationship_V);

		// [[transaction]]
		sprintf(tvin_fatherSearch, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_fatherSearch, tvin_fatherSearch);

		sc_bv<1> fatherSearch_tvin_wrapc_buffer;

		// RTL Name: fatherSearch
		{
			// bitslice(0, 0)
			{
				// celement: fatherSearch(0, 0)
				{
					// carray: (0) => (0) @ (0)
					{
						// sub                   : 
						// ori_name              : fatherSearch
						// sub_1st_elem          : 
						// ori_name_1st_elem     : fatherSearch
						// regulate_c_name       : fatherSearch
						// input_type_conversion : fatherSearch
						if (&(fatherSearch) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<1> fatherSearch_tmp_mem;
							fatherSearch_tmp_mem = fatherSearch;
							fatherSearch_tvin_wrapc_buffer.range(0, 0) = fatherSearch_tmp_mem.range(0, 0);
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_fatherSearch, "%s\n", (fatherSearch_tvin_wrapc_buffer).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_fatherSearch, tvin_fatherSearch);
		}

		tcl_file.set_num(1, &tcl_file.fatherSearch_depth);
		sprintf(tvin_fatherSearch, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_fatherSearch, tvin_fatherSearch);

		// push back input stream: "result"
		for (int i = 0; i < aesl_tmp_1; i++)
		{
			result.write(aesl_tmp_0[i]);
		}

// [call_c_dut] ---------->

		CodeState = CALL_C_DUT;
		top_function(tree1, tree2, nodo, relationship, fatherSearch, result);

		CodeState = DUMP_OUTPUTS;
		// pop output stream: "result"
		int aesl_tmp_2 = aesl_tmp_1;
		aesl_tmp_1 = 0;
     aesl_tmp_0.clear();
		while (!result.empty())
		{
			aesl_tmp_0.push_back(result.read());
			aesl_tmp_1++;
		}

		// [[transaction]]
		sprintf(tvout_result_V_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVOUT_result_V_V, tvout_result_V_V);

		sc_bv<11>* result_V_V_tvout_wrapc_buffer = new sc_bv<11>[aesl_tmp_1 - aesl_tmp_2];

		// RTL Name: result_V_V
		{
			// bitslice(10, 0)
			{
				int hls_map_index = 0;
				// celement: result.V.V(10, 0)
				{
					// carray: (aesl_tmp_2) => (aesl_tmp_1 - 1) @ (1)
					for (int i_0 = aesl_tmp_2; i_0 <= aesl_tmp_1 - 1; i_0 += 1)
					{
						// sub                   : i_0
						// ori_name              : aesl_tmp_0[i_0]
						// sub_1st_elem          : 0
						// ori_name_1st_elem     : aesl_tmp_0[0]
						// regulate_c_name       : result_V_V
						// input_type_conversion : (aesl_tmp_0[i_0]).to_string(2).c_str()
						if (&(aesl_tmp_0[0]) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<11> result_V_V_tmp_mem;
							result_V_V_tmp_mem = (aesl_tmp_0[i_0]).to_string(2).c_str();
							result_V_V_tvout_wrapc_buffer[hls_map_index].range(10, 0) = result_V_V_tmp_mem.range(10, 0);
                                 	       hls_map_index++;
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < aesl_tmp_1 - aesl_tmp_2; i++)
		{
			sprintf(tvout_result_V_V, "%s\n", (result_V_V_tvout_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVOUT_result_V_V, tvout_result_V_V);
		}

		tcl_file.set_num(aesl_tmp_1 - aesl_tmp_2, &tcl_file.result_V_V_depth);
		sprintf(tvout_result_V_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVOUT_result_V_V, tvout_result_V_V);

		// release memory allocation
		delete [] result_V_V_tvout_wrapc_buffer;

		// dump stream size
		sprintf(wrapc_stream_size_out_result_V_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(WRAPC_STREAM_SIZE_OUT_result_V_V, wrapc_stream_size_out_result_V_V);
		sprintf(wrapc_stream_size_out_result_V_V, "%d\n", aesl_tmp_1 - aesl_tmp_2);
		aesl_fh.write(WRAPC_STREAM_SIZE_OUT_result_V_V, wrapc_stream_size_out_result_V_V);
		sprintf(wrapc_stream_size_out_result_V_V, "[[/transaction]] \n");
		aesl_fh.write(WRAPC_STREAM_SIZE_OUT_result_V_V, wrapc_stream_size_out_result_V_V);

		// push back output stream: "result"
		for (int i = 0; i < aesl_tmp_1; i++)
		{
			result.write(aesl_tmp_0[i]);
		}

		CodeState = DELETE_CHAR_BUFFERS;
		// release memory allocation: "tree1_V"
		delete [] tvin_tree1_V;
		// release memory allocation: "tree2_V"
		delete [] tvin_tree2_V;
		// release memory allocation: "nodo_V"
		delete [] tvin_nodo_V;
		// release memory allocation: "relationship_V"
		delete [] tvin_relationship_V;
		// release memory allocation: "fatherSearch"
		delete [] tvin_fatherSearch;
		// release memory allocation: "result_V_V"
		delete [] tvout_result_V_V;
		delete [] tvin_result_V_V;
		delete [] wrapc_stream_size_out_result_V_V;

		AESL_transaction++;

		tcl_file.set_num(AESL_transaction , &tcl_file.trans_num);
	}
}

