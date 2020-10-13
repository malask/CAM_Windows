#include "hls_stream.h"
#include "ap_int.h"
#include "cam.h"

// DARLE A EXPORT RTL; CON PLACE Y ROUTE

// Declaracion de arbol estático
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
		// current_bucket_children = father/BUCKET_SIZE;
	}
	dual_bucket[current_bucket_children][1] = TREE_SIZE-1;
	/*for (int i=0;i<=current_bucket_children;i++) {
		std::cout << "Bucket numero: " << i << "empieza en " << buckets_children[i][0] << " y termina en " << buckets_children[i][1] << std::endl;
	} */
}
void top_function(edge_t tree[TREE_SIZE], node_t nodo, rel_t relationship, bool fatherSearch, hls::stream<node_t> &result){
#pragma HLS DATAFLOW
		static hls::stream<node_t> in1("ENTRADA_1");
		#pragma HLS STREAM variable=in1 depth=8 dim=1
		static hls::stream<node_t> in2("ENTRADA_2");
		#pragma HLS STREAM variable=in2 depth=8 dim=1
	busqueda_cam(tree, nodo, relationship, fatherSearch, in1,in2);
	combinar(in1,in2,result);
}
void busqueda_cam(edge_t tree[TREE_SIZE],node_t nodo, rel_t relationship, bool fatherSearch, hls::stream<node_t> &in1, hls::stream<node_t> &in2) {
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
			in1.write(DST_NODE(tree[i]));
			}
		if ((compare_node_2 == nodo) && (rel2==relationship)) {
			in2.write(DST_NODE(tree[i+1]));
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
						in1.write(SRC_NODE(tree[i]));
						}
			if ((compare_node_2 == nodo) && (rel2==relationship)) {
						in2.write(SRC_NODE(tree[i+1]));
						}
					}
	}
	in1.write(EOT);
	in2.write(EOT);
	return;
}
void combinar(hls::stream<node_t> &in1, hls::stream<node_t> &in2,hls::stream<node_t> &result) {
		bool end[2] = {false,false};
#pragma HLS ARRAY_PARTITION variable=end complete dim=1
		bool isData_1 = false, isData_2 = false;
		node_t val1,val2;
		do {
#pragma HLS PIPELINE
			isData_1 = in1.read_nb(val1);
			isData_2 = in2.read_nb(val2);

			if (isData_1) {
				if (val1 == EOT) end[0]=true;
				else result.write(val1);
			}
			//Aquí
			if (isData_2) {
				if (val2 == EOT) end[1]=true;
				else result.write(val2);
			}

		} while ((!end[0]) || (!end[1]));

		result.write(EOT);
}
