#include "hls_stream.h"
#include "ap_int.h"
#include "cam.h"



static node_t dual_bucket[BUCKETS_NEEDED][4] = {EOT};


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
			dual_bucket[current_bucket_parents][2] = i;

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
	node_t compare_node;
	rel_t rel;
	if (!fatherSearch) {
	for (int i = dual_bucket[bucket][0];i<= dual_bucket[bucket][1];i++) {
#pragma HLS PIPELINE
		compare_node = SRC_NODE(tree[i]);
		rel = tree[i](1,0);
		if ((compare_node == nodo) && (rel == relationship)){
			result.write(DST_NODE(tree[i]));
			}
		}
	} else {
		for (int i= dual_bucket[bucket][2]; i<= dual_bucket[bucket][3];i++){
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
