#include "hls_stream.h"
#include "ap_int.h"
#include "cam.h"

//#define NODE_MASK 0xF // ((1<<4)-1) Cada nodo ocupa 4 bits. Esto es una máscara que he creado para
//#define RELATION_MASK 0x3 // ((1<<2)-1 )Expresarlo en hexadecimal.
//#define TREE_SIZE 1024

// Declaracion de arbol estático
static node_t buckets_children[BUCKETS_NEEDED][2] = {EOT};
static node_t buckets_fathers[BUCKETS_NEEDED][2] = {EOT};


void fillHashTables(edge_t tree[TREE_SIZE]) {
	node_t father,children = 0;
	short current_bucket_children = 0;
	short current_bucket_parents = 0;
	short formula_children =1, formula_parents= 1;
	buckets_children[current_bucket_children][0] = 0;
	buckets_fathers[current_bucket_parents][0] = 0;
	for (int i = 0; i< TREE_SIZE;i++) {
		father = SRC_NODE(tree[i]);
		children = DST_NODE(tree[i]);
		if ((father >= (BUCKET_SIZE*formula_children)) && (tree[i]!= 0)) {
			//std::cout << "Se rellena el bucket de hijos" << current_bucket_children << "con el nodo " << father << " en posicion " << i << std::endl;
				buckets_children[current_bucket_children][1] = i-1;
				current_bucket_children+=1;
				formula_children++;
				buckets_children[current_bucket_children][0] = i;
		}
		if (DST_NODE(tree[i])%BUCKET_SIZE ==0 && tree[i] != 0){
			buckets_fathers[current_bucket_parents][1] = i-1;
			current_bucket_parents +=1;
			buckets_fathers[current_bucket_parents][0] = i;
			//std::cout << "Se rellena el bucket de padres" << current_bucket_parents << "con el nodo " << children << " en posicion " << i << std::endl;

		}
		formula_parents++;
	}
	buckets_children[current_bucket_children][1] = TREE_SIZE-1;
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
	node_t compare_node;
	rel_t rel;
	if (!fatherSearch) {
	for (int i = buckets_children[bucket][0];i<= buckets_children[bucket][1];i++) {
#pragma HLS PIPELINE
		compare_node = SRC_NODE(tree[i]);
		rel = tree[i](1,0);
		if ((compare_node == nodo) && (rel == relationship)){
			result.write(DST_NODE(tree[i]));
			}
		}
	} else {
		for (int i= buckets_fathers[bucket][0]; i<= buckets_fathers[bucket][1];i++){
#pragma HLS PIPELINE
			compare_node = DST_NODE(tree[i]);
			rel = tree[i](1,0);
			if ((compare_node==nodo) && (rel == relationship)) {
				result.write(SRC_NODE(tree[i]));
			}
		}
	}
	result.write(EOT);
	return;
}

