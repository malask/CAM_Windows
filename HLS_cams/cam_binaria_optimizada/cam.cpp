#include "hls_stream.h"
#include "ap_int.h"
#include "cam.h"


void top_function (node_t nodo, rel_t relationship, bool fatherSearch, hls::stream<node_t> &result) {
		busqueda_cam(nodo,relationship,fatherSearch,result);
}

 void busqueda_cam (node_t nodo, rel_t relationship, bool fatherSearch, hls::stream<node_t> &result) {
	extern edge_t bfstree[];
	ap_uint<EDGE_BITS> valor,valor2 = 0;
	valor = bfstree[0];
	ap_uint<REL_BITS> node_relation =0;
	valor2 = bfstree[1];
	ap_uint<NODE_BITS> compare_node_min, compare_node_max=0;
	bool flag = false;
	if (fatherSearch) {
		for (int i = 2; i < TREE_SIZE; i+=2) {
 #pragma HLS PIPELINE
					node_relation = valor(1,0);
					  compare_node_min = DST_NODE(valor);
					  compare_node_max = DST_NODE(valor2);
					  if ((compare_node_min == nodo) && (relationship == node_relation)) result.write(SRC_NODE(valor));
			
					  valor = bfstree[i];
					  if ((compare_node_max == nodo) && (relationship == node_relation)) result.write(SRC_NODE(valor2));

					  

					  valor2 = bfstree[i+1];
		}
		compare_node_min = DST_NODE(valor);
		 if ((compare_node_min == nodo) && (relationship == node_relation)) {
			 result.write(SRC_NODE(valor));
		 }
		compare_node_max = DST_NODE(valor2);

		 if ((compare_node_max == nodo) && (relationship == node_relation)) {
			 result.write(SRC_NODE(valor2));
			 }
	} else {
		for (int i = 2; i < TREE_SIZE; i+=2) {
#pragma HLS PIPELINE
			node_relation = valor(1,0);
			compare_node_min = SRC_NODE(valor);
			if ((compare_node_min == nodo) && (relationship == node_relation)) result.write(DST_NODE(valor));
			valor = bfstree[i];
			compare_node_max = SRC_NODE(valor2);
			if ((compare_node_max == nodo) && (relationship == node_relation)) result.write(DST_NODE(valor2));
			valor2 = bfstree[i+1];
	}
		compare_node_min = SRC_NODE(valor);
		if ((compare_node_min == nodo) && (relationship == node_relation)) result.write(DST_NODE(valor));
		compare_node_max = SRC_NODE(valor2);
		if ((compare_node_max == nodo) && (relationship == node_relation)) result.write(DST_NODE(valor2));

}
	result.write(EOT);
	}

