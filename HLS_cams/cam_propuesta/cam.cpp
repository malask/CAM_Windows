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
#pragma HLS RESOURCE variable=bfstree core=RAM_2P_BRAM latency=1

	extern short FULL_CHILDREN_BUCKET_INDEX_BFS[];
	ap_uint<EDGE_BITS> valor =0, valor_2= 0;
	ap_uint<REL_BITS> node_relation =0, node_relation_2=0;
	ap_uint<NODE_BITS> compare_node=0, compare_node_2=0;
	short min_limit = 0, parent_limit = 0;
	bool flag = false;
	min_limit = FULL_CHILDREN_BUCKET_INDEX_BFS[nodo-1];

	


	if (fatherSearch) {
		valor = bfstree[0];
		valor_2 = bfstree[1];
		for (int i = 2; i < TREE_SIZE;i+=2) {
#pragma HLS PIPELINE
			compare_node = DST_NODE(valor);
			node_relation = valor(1, 0);
			if ((compare_node == nodo) && (node_relation == relationship)){
				result.write(SRC_NODE(valor));
			}
			valor = bfstree[i];
			compare_node_2 = DST_NODE(valor_2);
			node_relation_2=valor_2(1,0);
			if ((compare_node_2 == nodo) && (node_relation_2 == relationship)){
				result.write(SRC_NODE(valor_2));
			}
			valor_2 = bfstree[i+1];
		}
			compare_node = DST_NODE(valor);
			node_relation = valor(1,0);
			if ((compare_node == nodo) && (node_relation == relationship)){
				result.write(SRC_NODE(valor));
			}
			compare_node_2 = DST_NODE(valor_2);
			node_relation_2 = valor_2(1,0);
			if ((compare_node_2 == nodo) && (node_relation_2 == relationship)){
				result.write(SRC_NODE(valor_2));
			}
	} else {
		if (min_limit==0 && nodo != 1) {
			result.write(EOT);
			return;
		} else {
			valor = bfstree[min_limit];
			min_limit+=1;
		for (; min_limit<TREE_SIZE; min_limit++) {
#pragma HLS PIPELINE
			compare_node = SRC_NODE(valor);
			node_relation = valor(1,0);
			if (compare_node != nodo) {
				flag = true;
				break;
			}
			else if (relationship == node_relation)result.write(DST_NODE(valor));
			valor = bfstree[min_limit];
			}
			if (!flag) {
				compare_node = SRC_NODE(valor);
				node_relation = valor(1,0);
				if (compare_node == nodo && (relationship == node_relation)) result.write(DST_NODE(valor));
			}

		}
	}
result.write(EOT);
	}
