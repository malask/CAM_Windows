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
	 extern short BUCKET_INDEX_BFS[];
	short min_limit=0;
	short bucket = (nodo/(TREE_SIZE/NUM_BUCKETS));
	if (bucket == NUM_BUCKETS) bucket -=1;
	min_limit = BUCKET_INDEX_BFS[bucket];

	extern edge_t bfstree[];

	ap_uint<EDGE_BITS> valor = 0;
	ap_uint<EDGE_BITS> valor2 = 0;
	ap_uint<REL_BITS> node_relation_1 = 0, node_relation_2 =0;
	bool flag = false;
	ap_uint<NODE_BITS> compare_node_min=0;
	ap_uint<NODE_BITS> compare_node_max=0;
	short max_limit = 0;
	if (bucket >= NUM_BUCKETS-1) max_limit = TREE_SIZE;
	else max_limit = BUCKET_INDEX_BFS[bucket+1];




	if (fatherSearch) {

		bucket = ((nodo-1)/(TREE_SIZE/NUM_BUCKETS));
		if (bucket>= NUM_BUCKETS-1) max_limit = TREE_SIZE-1;
		else max_limit = BUCKET_INDEX_BFS[bucket+1];
		valor = bfstree[max_limit];
		valor2 = bfstree[max_limit-1];
		if (max_limit % 2!=0) max_limit+=1;
		for (int i = max_limit-2; i >= 0; i-=2) {
#pragma HLS PIPELINE

					  node_relation_1 = valor(1,0);
					  compare_node_min= DST_NODE(valor);
					if ((compare_node_min == nodo) && (relationship == node_relation_1)) result.write(SRC_NODE(valor));
					valor = bfstree[i];
					node_relation_2 = valor2(1, 0);
					compare_node_max = DST_NODE(valor2);
					if ((compare_node_max == nodo) && (relationship == node_relation_2)) result.write(SRC_NODE(valor2));
					valor2 = bfstree[i-1];

		}
			node_relation_1 = valor(1,0);
			compare_node_min = DST_NODE(valor);
			 if ((compare_node_min == nodo) && (relationship == node_relation_1)) result.write(SRC_NODE(valor));
			 node_relation_2 = valor2(1, 0);
			compare_node_max = DST_NODE(valor2);
			 if ((compare_node_max == nodo) && (relationship == node_relation_2)) result.write(SRC_NODE(valor2));
		

	} else {
		valor = bfstree[min_limit];
		valor2 = bfstree[min_limit+1];
		min_limit+=2;
		for (; min_limit < max_limit; min_limit+=2) {
#pragma HLS PIPELINE


			node_relation_1 = valor(1,0);
			compare_node_min = SRC_NODE(valor);
		  if (flag && (compare_node_min != nodo)) break;
		  if ((compare_node_min == nodo) && (relationship == node_relation_1)) {
			  flag=true;
			  result.write(DST_NODE(valor));
		}
		valor = bfstree[min_limit];
		node_relation_2 = valor2(1, 0);
		compare_node_max = SRC_NODE(valor2);
		if (flag && (compare_node_max != nodo)) break;
		if ((compare_node_max == nodo) && (relationship == node_relation_2)) {
			flag = true;
			result.write(DST_NODE(valor2));
		}
		valor2 = bfstree[min_limit+1];
	}
		compare_node_min = SRC_NODE(valor);
		node_relation_1 = valor(1, 0);
		if ((compare_node_min == nodo) && (relationship == node_relation_1)) result.write(DST_NODE(valor));
		node_relation_2 = valor2(1, 0);
		compare_node_max = SRC_NODE(valor2);
		if ((compare_node_max == nodo) && (relationship == node_relation_2)) result.write(DST_NODE(valor2));
}
	result.write(EOT);
}

