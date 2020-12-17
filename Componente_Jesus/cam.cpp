#include "scone.h"


void busqueda_cam (node_t nodo, rel_t relationship, bool fatherSearch, hls::stream<node_t> &result) {
	 if (fatherSearch && nodo == 1) {
	 		result.write(EOT);
	 		return;
	 	}

	extern edge_t bfstree[];
	extern short FULL_CHILDREN_BUCKET_INDEX_BFS[];
	ap_uint<EDGE_BITS> valor = 0, valor_2=0;
	ap_uint<REL_BITS> node_relation, node_relation_2 =0;
	ap_uint<NODE_BITS> compare_node=0, compare_node_2;
	short min_limit = 0, parent_limit = 0;
	min_limit = FULL_CHILDREN_BUCKET_INDEX_BFS[nodo-1];

		if (fatherSearch) {
				valor = bfstree[0];
				valor_2 = bfstree[1];
			father_search_loop:	for (int i = 2; i < TREE_SIZE;i+=2) {
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
		if (min_limit == 0 && nodo != 1) {
			result.write(EOT);
			return;
		}else{
		children_search_loop:	for (int i = min_limit; i < TREE_SIZE; i++) {
#pragma HLS PIPELINE
			valor = bfstree[i];
			compare_node = SRC_NODE(valor);
			node_relation = valor(1,0);
			if (compare_node != nodo) break;
			else{
				if (relationship == node_relation) result.write(DST_NODE(valor));
			}

			}
		}
	}
result.write(EOT);
return;
	}
