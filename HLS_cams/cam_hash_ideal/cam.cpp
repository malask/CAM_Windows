#include "hls_stream.h"
#include "ap_int.h"
#include "cam.h"


void top_function (node_t nodo, rel_t relationship, bool fatherSearch, hls::stream<node_t> &result) {

		busqueda_cam(nodo,relationship,fatherSearch,result);
}

 void busqueda_cam (node_t nodo, rel_t relationship, bool fatherSearch, hls::stream<node_t> &result) {
	 if (fatherSearch && nodo == 1) {
	 		result.write(EOT);
	 		return;
	 	}

	extern edge_t bfstree[];
	extern short FULL_CHILDREN_BUCKET_INDEX_BFS[];
	ap_uint<EDGE_BITS> valor = 0;
	ap_uint<REL_BITS> node_relation =0;
	ap_uint<NODE_BITS> compare_node=0;
	short min_limit = 0, max_limit = 0;
	min_limit = FULL_CHILDREN_BUCKET_INDEX_BFS[nodo-1];


	if (fatherSearch) {
		result.write(SRC_NODE(bfstree[nodo-2]));

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
