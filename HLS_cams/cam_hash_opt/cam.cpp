#include "hls_stream.h"
#include "ap_int.h"
#include "cam.h"


void top_function (node_t nodo, rel_t relationship, bool fatherSearch, hls::stream<node_t> &result) {
#pragma HLS DATAFLOW
		busqueda_cam(nodo,relationship,fatherSearch,result);
}

 void busqueda_cam (node_t nodo, rel_t relationship, bool fatherSearch, hls::stream<node_t> &result) {
	 if (fatherSearch && nodo == 1) {
	 		result.write(EOT);
	 		return;
	 	}
	short bucket = (nodo/(TREE_SIZE/NUM_BUCKETS));
	if (bucket == NUM_BUCKETS) bucket -=1;
	extern edge_t bfstree[];
	extern short BUCKET_INDEX_BFS[];
	ap_uint<EDGE_BITS> valor = 0;
	ap_uint<REL_BITS> node_relation =0;
	bool flag = false;
	ap_uint<NODE_BITS> compare_node=0;
	short min_limit = 0, max_limit = 0;
	if (bucket >= NUM_BUCKETS-1) max_limit = TREE_SIZE;
	else max_limit = BUCKET_INDEX_BFS[bucket+1];


	if (fatherSearch) {

		bucket = ((nodo-1)/(TREE_SIZE/NUM_BUCKETS));
		if (bucket>= NUM_BUCKETS-1) max_limit = TREE_SIZE-1;
		else max_limit = BUCKET_INDEX_BFS[bucket+1];
		valor = bfstree[max_limit];
		for (int i = max_limit-1; i >= 0; i--) {
#pragma HLS PIPELINE

					  node_relation = valor(1,0);
					  compare_node = DST_NODE(valor);
					  if ((compare_node == nodo) && (relationship == node_relation)) {
						  flag = true;
						  result.write(SRC_NODE(valor));
						  break;
					  }
						valor = bfstree[i];
		}
		if (!flag) {
			node_relation = valor(1,0);
			compare_node = DST_NODE(valor);
			 if ((compare_node == nodo) && (relationship == node_relation)) result.write(SRC_NODE(valor));
		}

	} else {
		min_limit = BUCKET_INDEX_BFS[bucket];
		valor = bfstree[min_limit];
		min_limit+=1;
		for (; min_limit <= max_limit; min_limit++) {
#pragma HLS PIPELINE


			node_relation = valor(1,0);
			compare_node = SRC_NODE(valor);
		  if (flag && (compare_node != nodo)) break;
		  if ((compare_node == nodo) && (relationship == node_relation)) {
			  flag=true;
			  result.write(DST_NODE(valor));
		}
		valor = bfstree[min_limit];

	}
}
	result.write(EOT);
	}
