#include "hls_stream.h"
#include "ap_int.h"
#include "cam.h"


 void top_function(node_t nodo, rel_t relationship, bool fatherSearch, hls::stream<node_t> &result){
 	static hls::stream<node_t> in1("ENTRADA_FOR1");
 	#pragma HLS STREAM variable=in1 depth=8 dim=1
 	static hls::stream<node_t> in2("ENTRADA_FOR2");
 	#pragma HLS STREAM variable=in2 depth=8 dim=1

 #pragma HLS DATAFLOW
 	busqueda_cam(nodo, relationship, fatherSearch, in1,in2);
 	combinar(in1,in2,result);
 }
 void busqueda_cam (node_t nodo, rel_t relationship, bool fatherSearch, hls::stream<node_t> &result1,hls::stream<node_t> &result2) {
 	ap_uint<EDGE_BITS> valor_min, valor_max = 0;
 	ap_uint<REL_BITS> node_relation_min, node_relation_max =0;
 	ap_uint<NODE_BITS> compare_node_min, compare_node_max, founded_node=0;
 	extern edge_t bfstree[];
 	bool flag_min, flag_max= false;
 	if (nodo == 1 && fatherSearch) {
 		result1.write(EOT);
 		result2.write(EOT);
 		return;
 	}
 if (fatherSearch) {
 	for (int i = 0;i<TREE_SIZE/2; i++) {
 #pragma HLS PIPELINE
 			  valor_min = bfstree[i];
 			  node_relation_min = valor_min(1,0);
 			  compare_node_min = DST_NODE(valor_min);

 			  valor_max = bfstree[i+TREE_SIZE/2];
 			  node_relation_max = valor_max(1,0);
 			  compare_node_max = DST_NODE(valor_max);

 				  if ((compare_node_min == nodo) && (relationship == node_relation_min)) {
 					  result1.write(SRC_NODE(valor_min));
 				  }
 				  if ((compare_node_max == nodo) && (relationship == node_relation_max)) {
 					  result2.write(SRC_NODE(valor_max));
                 
 				  }
 // Este if es para buscar los hijos del nodo proporcionado
 }
 } else {
 	for (int i = 0;i<TREE_SIZE/2; i++) {
 #pragma HLS PIPELINE
 			  valor_min = bfstree[i];
 			  node_relation_min = valor_min(1,0);
 			  compare_node_min = SRC_NODE(valor_min);

 			  valor_max = bfstree[i+TREE_SIZE/2];
 			  node_relation_max = valor_max(1,0);
 			  compare_node_max = SRC_NODE(valor_max);


 // Este if es para buscar al padre del nodo proporcionado a la CAM
 				  if ((compare_node_min == nodo) && (relationship == node_relation_min)) {
 					  result1.write(DST_NODE(valor_min));
 				  }
 				  if ((compare_node_max == nodo) && (relationship == node_relation_max)) {
 					  result2.write(DST_NODE(valor_max));
 				  }
 // Este if es para buscar los hijos del nodo proporcionado
 }
 }
 	result1.write(EOT);
 	result2.write(EOT);
 	return;
 }

 void combinar(hls::stream<node_t> &in1, hls::stream<node_t> &in2,hls::stream<node_t> &result) {
 	bool end_1 = false, end_2 = false;
 		bool isData_1 = false, isData_2 = false;
 		node_t val1,val2;
 		do {
 #pragma HLS PIPELINE
 			isData_1 = in1.read_nb(val1);
 			isData_2 = in2.read_nb(val2);

 			if (isData_1) {
 				if (val1 == EOT) end_1=true;
 				else result.write(val1);
 			}
 			if (isData_2) {
 				if (val2 == EOT)end_2=true;
 				else result.write(val2);
 			}

 		} while ((!end_1) || (!end_2));

 		result.write(EOT);
 }

