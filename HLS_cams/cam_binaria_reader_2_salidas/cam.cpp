#include "hls_stream.h"
#include "ap_int.h"
#include "cam.h"


void top_function(node_t nodo, rel_t relationship, bool fatherSearch, hls::stream<node_t> &result_1, hls::stream<node_t> &result_2){
	static hls::stream<edge_t> in1("ENTRADA_FOR1");
	#pragma HLS STREAM variable=in1 depth=8 dim=1
	static hls::stream<edge_t> in2("ENTRADA_FOR2");
	#pragma HLS STREAM variable=in2 depth=8 dim=1
#pragma HLS DATAFLOW
	preprocessor_cam(nodo,fatherSearch,in1,in2);
	busqueda_cam(nodo, relationship, fatherSearch, in1,result_1);
	busqueda_cam(nodo, relationship, fatherSearch, in2,result_2);
}

void preprocessor_cam(node_t nodo, bool fatherSearch,hls::stream<edge_t> &send1, hls::stream<edge_t> &send2) {
	extern edge_t bfstree[];
	ap_uint<EDGE_BITS> nodo1,nodo2 =0;
	if (nodo==1 && fatherSearch) {
		send1.write(EOT);
		send2.write(EOT);
		return;
	}else{
		nodo1 = bfstree[0];
		nodo2 = bfstree[1];

	for (int i=2;i<TREE_SIZE-1;i+=2){
#pragma HLS PIPELINE
		send1.write(nodo1);
		nodo1 = bfstree[i];
		send2.write(nodo2);
		nodo2 = bfstree[i+1];
		}
	send1.write(nodo1);
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

