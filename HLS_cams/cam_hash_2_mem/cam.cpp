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
	 extern short BUCKET_INDEX_BFS[];
	short min_1 = 0, min_2 = 0, max_1 = 0, max_2 = 0;
	short check_1 = 0, check_2 = 0;
	short bucket = (nodo/(TREE_SIZE/NUM_BUCKETS));
	if (bucket == NUM_BUCKETS) bucket -=1;
	min_1 = BUCKET_INDEX_BFS[bucket];

	extern edge_t bfstree_2_1[];
	extern edge_t bfstree_2_2[];
	if (bucket >= NUM_BUCKETS-1) max_2 = TREE_SIZE/2;
	else max_1 = BUCKET_INDEX_BFS[bucket+1];

	ap_uint<EDGE_BITS> valor = 0;
	ap_uint<EDGE_BITS> valor2 = 0;
	ap_uint<REL_BITS> node_relation =0;
	bool flag = false;
	ap_uint<NODE_BITS> compare_node=0;

	check_1 = min_1/(TREE_SIZE/2);
	check_2 = max_1/(TREE_SIZE/2);
	if ((check_1 != check_2) && (check_1 == 0)) {
		max_2 = (max_1%(TREE_SIZE/2))+1;
		max_1 = (TREE_SIZE/2);
	}
	else if (check_1 == 1 ) {
		min_2 = min_1%(TREE_SIZE/2);
		if (max_2 != TREE_SIZE/2) max_2 = max_1%(TREE_SIZE/2);
		min_1 = 0;
		if (!fatherSearch) max_1 = 0;
	}


	if (fatherSearch) {
		valor = bfstree_2_1[0];
		for (int i = 1; i < max_1; i++) {
#pragma HLS PIPELINE
			node_relation = valor(1,0);
			compare_node = DST_NODE(valor);
			if ((compare_node == nodo) && (relationship == node_relation)) {
				flag = true;
				result.write(SRC_NODE(valor));
				break;
			}
			valor = bfstree_2_1[i];

		}
	if (!flag) {
		valor2 = bfstree_2_2[0];
		compare_node = DST_NODE(valor);
		if ((compare_node == nodo) && (relationship == node_relation)) result.write(SRC_NODE(valor));
		for (int i = 1; i < max_2; i++) {
#pragma HLS PIPELINE
			node_relation = valor2(1,0);
			compare_node = DST_NODE(valor2);
			if ((compare_node == nodo) && (relationship == node_relation)){
				flag = true;
				result.write(SRC_NODE(valor2));
				break;
			}
			valor2 = bfstree_2_2[i];

		}
		if (!flag) {
			compare_node = DST_NODE(valor2);
			if ((compare_node == nodo) && (relationship == node_relation)) result.write(SRC_NODE(valor2));
		}
	}

	} else {
		valor = bfstree_2_1[min_1];
		for (int i = min_1; i < max_1-1; i++) {
#pragma HLS PIPELINE
			node_relation = valor(1,0);
			compare_node = SRC_NODE(valor);
		  if (flag && (compare_node != nodo)) break;
		  if ((compare_node == nodo) && (relationship == node_relation)) {
			  flag=true;
			  result.write(DST_NODE(valor));
		  }
			valor = bfstree_2_1[i+1];
}
		compare_node = SRC_NODE(valor);
		  if ((compare_node == nodo) && (relationship == node_relation)){
			 flag = true;
				result.write(DST_NODE(valor));
		  }
		for (int i = min_2; i < max_2-1; i++) {
			node_relation = valor(1,0);
			compare_node = SRC_NODE(valor2);
			if (flag && (compare_node != nodo)) break;
			if ((compare_node == nodo) && (relationship == node_relation)) {
				flag=true;
				result.write(DST_NODE(valor2));
			}
			valor2 = bfstree_2_2[i+1];
		}
		compare_node = SRC_NODE(valor2);
		if ((compare_node == nodo) && (relationship == node_relation)) result.write(DST_NODE(valor2));


	}
	result.write(EOT);
}

