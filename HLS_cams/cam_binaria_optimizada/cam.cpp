#include "hls_stream.h"
#include "ap_int.h"
#include "cam.h"



void top_function (node_t nodo, rel_t relationship, bool fatherSearch, hls::stream<node_t> &result) {
		busqueda_cam(nodo,relationship,fatherSearch,result);
}

#include "hls_stream.h"
#include "ap_int.h"
#include "cam.h"

//#define NODE_MASK 0xF // ((1<<4)-1) Cada nodo ocupa 4 bits. Esto es una máscara que he creado para
//#define RELATION_MASK 0x3 // ((1<<2)-1 )Expresarlo en hexadecimal.
//#define TREE_SIZE 1024

// Declaracion de arbol estático
 void busqueda_cam (node_t nodo, rel_t relationship, bool fatherSearch, hls::stream<node_t> &result) {
	extern edge_t bfstree[];
	ap_uint<EDGE_BITS> valor, valor2;
	ap_uint<REL_BITS> node_relation =0;
	ap_uint<NODE_BITS> compare_node_min, compare_node_max, founded_node=0;
	bool flag_min, flag_max= false;
	if (nodo == 1 && fatherSearch) {
		result.write(EOT);
		return;
	}
	if (fatherSearch){
		for (int i = 0;i<TREE_SIZE;i+=2){
#pragma HLS PIPELINE
			valor = bfstree[i];
			compare_node_min = DST_NODE(valor);
			if ((compare_node_min == nodo) && (relationship == node_relation)) result.write(SRC_NODE(valor));
			valor2 = bfstree[i+1];
			compare_node_max = DST_NODE(valor2);
			if ((compare_node_max == nodo) && (relationship == node_relation)) result.write(SRC_NODE(valor2));
		}
	}else {
		for (int i = 0;i<TREE_SIZE;i+=2){
#pragma HLS PIPELINE
					valor = bfstree[i];
					compare_node_min = SRC_NODE(valor);
					if ((compare_node_min == nodo) && (relationship == node_relation)) result.write(DST_NODE(valor));

					valor2 = bfstree[i+1];
					compare_node_max = SRC_NODE(valor2);

					if ((compare_node_max == nodo) && (relationship == node_relation)) result.write(DST_NODE(valor2));
				}
		}
	result.write(EOT);
	}
