#include "hls_stream.h"
#include "ap_int.h"
#include "cam.h"

void top_function(word_t nodo, bool fatherSearch, hls::stream<node_t> &path) {
	static hls::stream<node_t> in1;
#pragma HLS STREAM variable=in1 depth=1024
#pragma HLS DATAFLOW
	busqueda_scone(nodo, fatherSearch,in1,path);
}

void busqueda_scone(word_t word, bool fatherSearch, hls::stream<node_t> &in1, hls::stream<node_t> &path) {
	rel_t rel =  word(2,0);
	node_t nodo = WORD_NODE(word), salida;
	busqueda_cam(nodo, rel, fatherSearch, in1);
	while (!in1.empty()) {
#pragma HLS PIPELINE
		salida = in1.read();
		if (salida != EOT) {
			busqueda_cam(salida, rel, fatherSearch, in1);
			path.write(salida);
		}
	}
	path.write(EOT);
}
 void busqueda_cam (node_t nodo, rel_t relationship, bool fatherSearch, hls::stream<node_t> &result) {
	 if (fatherSearch && nodo == 1) {
	 		result.write(EOT);
	 		return;
	 	}

	extern edge_t bfstree[];
	extern short FULL_CHILDREN_BUCKET_INDEX_BFS[];
	extern short FULL_PARENTS_BUCKET_INDEX_BFS[];
	ap_uint<EDGE_BITS> valor = 0;
	ap_uint<REL_BITS> node_relation =0;
	ap_uint<NODE_BITS> compare_node=0;
	short min_limit = 0, max_limit = 0;
	min_limit = FULL_CHILDREN_BUCKET_INDEX_BFS[nodo-1];


	if (fatherSearch) {
		result.write(SRC_NODE(bfstree[FULL_PARENTS_BUCKET_INDEX_BFS[nodo-1]]));

	} else {
		if (min_limit!=0) {
		for (int i = min_limit; i < TREE_SIZE; i++) {

			valor = bfstree[i];
			compare_node = SRC_NODE(valor);
			if (compare_node != nodo) break;
			else result.write(DST_NODE(valor));

			}
		}
	}
result.write(EOT);
	}
