#include "hls_stream.h"
#include "ap_int.h"
#include "cam.h"
#include <ctype.h>




void top_function(word_t nodo, char operation, hls::stream<node_t> &path) {
	static unsigned short count = 0;
#pragma HLS reset variable=count
	static ap_uint<8> marks[12];
#pragma HLS reset variable=marks

	switch (operation) {
	case 'u' :
	{
		busqueda_scone(nodo,true,false,path,count,marks);
		break;

	}

	case 'd':
	{
		busqueda_scone(nodo,false,false,path,count,marks);
		break;
	}
	case 'i':
	{
		for (int i = 0; i < N_NODES;i++) {
#pragma HLS PIPELINE
			if (marks[i].test(count-1)){
				word_t tmp = ((((i+1) & 0xFFFF) << 2) | (1 &  0xFF));
				busqueda_scone(tmp, false,true, path,count,marks);
			}
		}
		break;
	}
	case 'r':
	{
		ap_uint<8> max =0, pos = 0;
		for (int i = 0; i < N_NODES; i++) {
#pragma HLS PIPELINE
			ap_uint<8> current = marks[i];
			if (current > max) {
				pos = i;
				max=current;
			}
		}
		path.write(pos+1);
		break;
	}
	default:
	{
		return;
		break;
	}
	}
	count+=1;
	return;
}

void busqueda_scone(word_t word, bool upOrDown, bool intersection, hls::stream<node_t> &path, unsigned short &count, ap_uint<8> marks[TREE_SIZE] ) {
	static hls::stream<node_t> in1;
#pragma HLS STREAM variable=in1 depth=1024
	rel_t rel =  word(2,0);
	node_t nodo = WORD_NODE(word), salida;
	busqueda_cam(nodo, rel, upOrDown, in1);
if (!intersection) {
	while (!in1.empty()) {
	#pragma HLS PIPELINE
			salida = in1.read();
			if (salida != EOT) {
				busqueda_cam(salida, rel, upOrDown, in1);
				//path.write(salida);
				marks[salida-1][0+count] = 1;
			}
		}
		marks[nodo-1][0+count] = 1;
}
else {
	while (!in1.empty()) {
#pragma HLS PIPELINE
		salida = in1.read();
		if (salida != EOT)  marks[salida-1][0+count] = 1;
	}
}

	path.write(EOT);
	return;
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
	short min_limit = 0, parent_limit = 0;
	min_limit = FULL_CHILDREN_BUCKET_INDEX_BFS[nodo-1];
	parent_limit = FULL_PARENTS_BUCKET_INDEX_BFS[11];


	if (fatherSearch) {

		for (int i = parent_limit; i >= 0; i--){
#pragma HLS PIPELINE
			valor = bfstree[i];
			compare_node = DST_NODE(valor);
			node_relation = valor(1,0);
			if ((compare_node == nodo)&& (relationship == node_relation)) result.write(SRC_NODE(valor));

		}
	} else {
		if (min_limit == 0 && nodo != 1) {
			result.write(EOT);
			return;
		}else{
		for (int i = min_limit; i < TREE_SIZE; i++) {
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
