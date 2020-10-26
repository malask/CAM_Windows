#include "hls_stream.h"
#include "ap_int.h"
#include "cam.h"


void top_function (node_t nodo, rel_t relationship, bool fatherSearch, hls::stream<node_t> &result) {

		busqueda_cam(nodo,relationship,fatherSearch,result);
}

 void busqueda_cam (node_t nodo, rel_t relationship, bool fatherSearch, hls::stream<node_t> &result) {
	short bucket = (nodo/(TREE_SIZE/NUM_BUCKETS));
	if (bucket == NUM_BUCKETS) bucket -=1;
	extern edge_t bfstree[];
	extern short BUCKET_INDEX_BFS[];
	ap_uint<EDGE_BITS> valor = 0;
	ap_uint<REL_BITS> node_relation =0;
	ap_uint<NODE_BITS> compare_node=0;
	short min_limit = 0, max_limit = 0;
	if (bucket >= NUM_BUCKETS-1) max_limit = TREE_SIZE;
	else max_limit = BUCKET_INDEX_BFS[bucket+1];
	if (fatherSearch) {

		for (int i = min_limit; i < max_limit; i++) {
#pragma HLS PIPELINE
					  node_relation = valor(1,0);
					  compare_node = DST_NODE(valor);
					  if ((compare_node == nodo) && (relationship == node_relation)) {
						  result.write(SRC_NODE(valor));
					  }
					  valor = bfstree[i];

		}
	} else {
		min_limit = BUCKET_INDEX_BFS[bucket];

		for (; min_limit < max_limit; min_limit++) {
#pragma HLS PIPELINE
			  valor = bfstree[min_limit];

		  node_relation = valor(1,0);
		  compare_node = SRC_NODE(valor);
		if ((compare_node == nodo) && (relationship == node_relation)) result.write(DST_NODE(valor));

	}
}
	result.write(EOT);
	}
