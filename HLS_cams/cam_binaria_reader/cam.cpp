
#include "hls_stream.h"
#include "ap_int.h"
#include "cam.h"


void top_function(node_t nodo, rel_t relationship, bool fatherSearch, hls::stream<node_t> &result){
	static hls::stream<edge_t> in1("ENTRADA_FOR1");
	#pragma HLS STREAM variable=in1 depth=8 dim=1
	static hls::stream<edge_t> in2("ENTRADA_FOR2");
	#pragma HLS STREAM variable=in2 depth=8 dim=1
	static hls::stream<node_t> in1b;
	#pragma HLS STREAM variable=in1b depth=8 dim=1
	static hls::stream<node_t> in2b;
	#pragma HLS STREAM variable=in2b depth=8 dim=1
#pragma HLS DATAFLOW
	preprocessor_cam(nodo,fatherSearch,in1,in2);
	busqueda_cam(nodo, relationship, fatherSearch, in1,in1b);
	busqueda_cam(nodo, relationship, fatherSearch, in2,in2b);
	combinar(in1b,in2b,result);
}

void preprocessor_cam(node_t nodo, bool fatherSearch,hls::stream<edge_t> &send1, hls::stream<edge_t> &send2) {
	extern edge_t bfstree[];
	ap_uint<EDGE_BITS> nodo1,nodo2 =0;
	if (nodo==1 && fatherSearch) {
		send1.write(EOT);
		send2.write(EOT);
		return;
	}else{
	for (int i=0;i<TREE_SIZE-2;i+=2){
#pragma HLS PIPELINE
		nodo1 = bfstree[i];
		send1.write(nodo1);
		nodo2 = bfstree[i+1];
		send2.write(nodo2);
		}
	send1.write(bfstree[TREE_SIZE-2]);
	send2.write(EOT);
	send1.write(EOT);
	}
	return;
}
void busqueda_cam(node_t nodo, rel_t relationship, bool fatherSearch, hls::stream<edge_t> &receive, hls::stream<node_t> &result){
	ap_uint<EDGE_BITS> readData;
	ap_uint<REL_BITS> node_relation;
	ap_uint<NODE_BITS> compare_node;
	bool end=false;
	bool isData;
	if (fatherSearch) {
		while (!end) {
#pragma HLS PIPELINE
			isData = receive.read_nb(readData);
			if (isData){
				if (readData == EOT) end = true;
				else {
				node_relation = readData(1,0);
				compare_node = DST_NODE(readData);
				if (compare_node==nodo && relationship == node_relation) {
					result.write(SRC_NODE(readData));
				}
			}
		}
		}
	} else {
		while (!end) {
		#pragma HLS PIPELINE
					isData = receive.read_nb(readData);
					if (isData){
						if (readData == EOT) end = true;
						else {
						node_relation = readData(1,0);
						compare_node = SRC_NODE(readData);
						if (compare_node==nodo && relationship == node_relation) result.write(DST_NODE(readData));

						}
					}
				}
		}
	result.write(EOT);
}

void combinar(hls::stream<node_t> &in1, hls::stream<node_t> &in2,hls::stream<node_t> &result) {
		bool end[2] = {false,false};
#pragma HLS ARRAY_PARTITION variable=end complete dim=1
		bool isData_1 = false, isData_2 = false;
		node_t val1,val2;
		do {
#pragma HLS PIPELINE
			isData_1 = in1.read_nb(val1);
			isData_2 = in2.read_nb(val2);

			if (isData_1) {
				if (val1 == EOT){
					end[0]=true;
				}
				else{
					 result.write(val1);
				}
			}
			//Aquí
			if (isData_2) {
				if (val2 == EOT) end[1]=true;
				else{
				 result.write(val2);
				}
			}

		} while ((!end[0]) || (!end[1]));

		result.write(EOT);
}
