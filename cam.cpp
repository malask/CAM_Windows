#include "hls_stream.h"
#include "ap_int.h"
#include "cam.h"

//#define NODE_MASK 0xF // ((1<<4)-1) Cada nodo ocupa 4 bits. Esto es una máscara que he creado para
//#define RELATION_MASK 0x3 // ((1<<2)-1 )Expresarlo en hexadecimal.
//#define TREE_SIZE 1024

// Declaracion de arbol estático
static node_t dual_bucket[BUCKETS_NEEDED][4] = {EOT};

/* node_t father, children = 0;
	short current_bucket_childrens, current_bucket_fathers = 0;
	short formula_childrens, formula_parents = 1;
	buckets_children[current_bucket_childrens][0] = 0;
	buckets_fathers[current_bucket_fathers][0] = 0;
	for (int i = 0; i< TREE_SIZE;i++) {
		father = SRC_NODE(tree[i]);
		children = DST_NODE(tree[i]);
		if ((father >= (BUCKET_SIZE*formula_childrens)) && (tree[i]!= 0)) {
				buckets_children[current_bucket_childrens][1] = i-1;
				current_bucket_childrens+=1;
				formula_childrens++;
				buckets_children[current_bucket_childrens][0] = i;
		}
		if ((tree[i] != 0) && (formula_parents%BUCKET_SIZE ==0) && (i != 0)) {
			buckets_fathers[current_bucket_fathers][1] = i-1;
			current_bucket_fathers+=1;
			buckets_fathers[current_bucket_fathers][1] = i;
			std::cout << "Se rellena el bucket " << current_bucket_fathers << "con el nodo " << children << " en posicion " << i << std::endl;

		}
		formula_parents++;
	}
	buckets_children[current_bucket_childrens][1] = TREE_SIZE-1;
	for (int i=0;i<=current_bucket_childrens;i++) {
		std::cout << "Bucket numero: " << i << "empieza en " << buckets_children[i][0] << " y termina en " << buckets_children[i][1] << std::endl;
	}
} */
void fillHashTables(edge_t tree[TREE_SIZE]) {
	node_t father,children = 0;
	short current_bucket_children = 0;
	short current_bucket_parents = 0;
	short formula_children =1, formula_parents= 1;
	dual_bucket[current_bucket_children][0] = 0;
	dual_bucket[current_bucket_parents][2] = 0;
	for (int i = 0; i< TREE_SIZE;i++) {
		father = SRC_NODE(tree[i]);
		children = DST_NODE(tree[i]);
		if ((father >= (BUCKET_SIZE*formula_children)) && (tree[i]!= 0)) {
				dual_bucket[current_bucket_children][1] = i-1;
				current_bucket_children+=1;
				formula_children++;
				dual_bucket[current_bucket_children][0] = i;
		}
		if (DST_NODE(tree[i])%BUCKET_SIZE ==0 && tree[i] != 0){
			dual_bucket[current_bucket_parents][3] = i-1;
			current_bucket_parents +=1;
			dual_bucket[current_bucket_parents][0] = i;

		}
		formula_parents++;
	}
	dual_bucket[current_bucket_children][1] = TREE_SIZE-1;
	/*for (int i=0;i<=current_bucket_children;i++) {
		std::cout << "Bucket numero: " << i << "empieza en " << buckets_children[i][0] << " y termina en " << buckets_children[i][1] << std::endl;
	} */
}
void top_function(edge_t tree[TREE_SIZE], node_t nodo, rel_t relationship, bool fatherSearch, hls::stream<node_t> &result){
#pragma HLS DATAFLOW
	busqueda_cam(tree, nodo, relationship, fatherSearch, result);
}
void busqueda_cam(edge_t tree[TREE_SIZE],node_t nodo, rel_t relationship, bool fatherSearch, hls::stream<node_t> &result) {
	unsigned short bucket = nodo/128;
	node_t compare_node, compare_node_2;
	rel_t rel,rel2;
	if (!fatherSearch) {
	for (int i = dual_bucket[bucket][0];i<= dual_bucket[bucket][1];i+=2) {
#pragma HLS PIPELINE
		compare_node = SRC_NODE(tree[i]);
		compare_node_2 = SRC_NODE(tree[i+1]);
		rel = tree[i](1,0);
		rel2 = tree[i+1](1,0);
		if ((compare_node == nodo) && (rel == relationship)){
			result.write(DST_NODE(tree[i]));
			}
		if ((compare_node_2 == nodo) && (rel2==relationship)) {
			result.write(DST_NODE(tree[i+1]));
			}
		}
	} else {
		for (int i= dual_bucket[bucket][2]; i<= dual_bucket[bucket][3];i+=2){
#pragma HLS PIPELINE
			compare_node = DST_NODE(tree[i]);
			compare_node_2 = DST_NODE(tree[i+1]);

			rel = tree[i](1,0);
			rel2 = tree[i+1](1,0);
			if ((compare_node == nodo) && (rel == relationship)){
						result.write(SRC_NODE(tree[i]));
						}
			if ((compare_node_2 == nodo) && (rel2==relationship)) {
						result.write(SRC_NODE(tree[i+1]));
						}
					}
	}
	result.write(EOT);
	return;
}

