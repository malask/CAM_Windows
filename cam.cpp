#include "hls_stream.h"
#include "ap_int.h"
#include "cam.h"

//#define NODE_MASK 0xF // ((1<<4)-1) Cada nodo ocupa 4 bits. Esto es una máscara que he creado para
//#define RELATION_MASK 0x3 // ((1<<2)-1 )Expresarlo en hexadecimal.
//#define TREE_SIZE 1024

// Declaracion de arbol estático
static index_t parents[TREE_SIZE]={EOT};
static index_t childrens[TREE_SIZE]={EOT};


void fillHashTables(edge_t tree[TREE_SIZE]) {
	bool firstChildrenFound[TREE_SIZE]={0};
	edge_t read;
	node_t parent;
	node_t children;
	for (int i = 0; i < TREE_SIZE;i++){
#pragma HLS PIPELINE
		read = tree[i];
		parent=SRC_NODE(read);
		children=DST_NODE(read);
		if (!firstChildrenFound[parent-1]) {
			firstChildrenFound[parent-1] = true;
			childrens[parent-1] = i;
		}
		parents[children-1] = parent;
	}
/*#ifndef __SYNTHESIS__
	for (int i=0;i<TREE_SIZE && tree[i]!=0;i++){
		std::cout << "El primer hijo de " << i+1 << " esta en la posicion de memoria: " << childrens[i] << std::endl;
		if (i!=0) std::cout << "El padre de " << i+1 << " esta en la posicion de memoria: " << parents[i] << std::endl;
	}
#endif */
	return;
}
void top_function(edge_t tree[TREE_SIZE], node_t nodo, rel_t relationship, bool fatherSearch, hls::stream<node_t> &result){
#pragma HLS DATAFLOW
	busqueda_cam(tree, nodo, relationship, fatherSearch, result);
}
void busqueda_cam(edge_t tree[TREE_SIZE],node_t nodo, rel_t relationship, bool fatherSearch, hls::stream<node_t> &result) {
	if (fatherSearch) {
		if (tree[parents[nodo-1]](1,0) == relationship) result.write(parents[nodo-1]);
	} else {
		index_t firstChild = childrens[nodo-1];
		bool end = false;
		node_t children;
		while(!end) {
#pragma HLS PIPELINE
			if (SRC_NODE(tree[firstChild]) != nodo) end=true;
			else{
				children=DST_NODE(tree[firstChild]);
				result.write(children);
			}
			firstChild++;
		}
	}
	result.write(EOT);
	return;
}

