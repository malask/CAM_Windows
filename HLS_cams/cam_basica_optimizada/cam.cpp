#include "hls_stream.h"
#include "ap_int.h"
#include "cam.h"


void top_function (node_t nodo, rel_t relationship, bool fatherSearch, hls::stream<node_t> &result) {
		busqueda_cam(nodo,relationship,fatherSearch,result);
}

 void busqueda_cam (node_t nodo, rel_t relationship, bool fatherSearch, hls::stream<node_t> &result) {
	extern edge_t bfstree[];
	ap_uint<EDGE_BITS> valor = 0;
	ap_uint<REL_BITS> node_relation =0;
	ap_uint<NODE_BITS> compare_node=0;
	if (fatherSearch) {
		for (int i = 0; i < TREE_SIZE; i++) {
#pragma HLS PIPELINE
					  valor = bfstree[i];
					  node_relation = valor(1,0);
					  compare_node = DST_NODE(valor);
					  if ((compare_node == nodo) && (relationship == node_relation)) {

						  result.write(SRC_NODE(valor));
					  }
		}
	} else {
		for (int i = 0; i < TREE_SIZE; i++) {
#pragma HLS PIPELINE
		  valor = bfstree[i];
		  node_relation = valor(1,0);
		  compare_node = SRC_NODE(valor);
				  if ((compare_node == nodo) && (relationship == node_relation)) result.write(DST_NODE(valor));
	}
}
	result.write(EOT);
	}
