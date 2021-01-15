#ifndef SCONE_H
#define SCONE_H

#include "hls_stream.h"
#include "ap_int.h"
#include <ctype.h>

#define TREE_SIZE 160
#define N_NODES 128
#define NODE_BITS 8
/*
#define TREE_SIZE 80
#define N_NODES 64
#define NODE_BITS 7 // Nodos = Bits para representar 64 = log2(64) +1
/*
#define TREE_SIZE 160 // El tama�o de la tabla de relaciones
#define NODE_BITS 8 // Numero de bits
#define N_NODES 128 // Numero de nodos que hay en el arbol

#define TREE_SIZE 320
#define NODE_BITS 9
#define N_NODES 256


#define TREE_SIZE 640
#define NODE_BITS 10
#define N_NODES 512


#define TREE_SIZE 1280
#define NODE_BITS 11
#define N_NODES 1024

*/
typedef enum {
	CLEAR = 0,
	UPSCAN = 1,
	DOWNSCAN = 2,
	PROPAGATE = 3,
	INTERSECTION = 4
} scone_ops;

	#define REL_BITS 2
	#define EDGE_BITS (NODE_BITS*2 + REL_BITS)
	#define SRC_NODE(e) ((e)(EDGE_BITS-1,EDGE_BITS-NODE_BITS))
	#define DST_NODE(e) ((e)(EDGE_BITS-NODE_BITS-1,REL_BITS))
	#define EOT 0


	#define WORD_SIZE (NODE_BITS+REL_BITS)
	#define WORD_NODE(e) ((e)(NODE_BITS+REL_BITS-1,REL_BITS))
	#define WORD_REL(e)  ((e)(REL_BITS,1))



	typedef ap_uint<EDGE_BITS> edge_t;
	typedef ap_uint<NODE_BITS> node_t;
	typedef ap_uint<REL_BITS> rel_t;
	typedef ap_uint<WORD_SIZE> cmd_scone_t;


	void busqueda_cam (node_t nodo, rel_t relationship, bool fatherSearch, hls::stream<node_t> &result);
	void scone_engine (cmd_scone_t nodo, scone_ops op, hls::stream<node_t> &path,ap_uint<8> marks[N_NODES]);
	//void scone_engine (cmd_scone_t nodo, scone_ops op, hls::stream<node_t> &path);
	void scan(cmd_scone_t word, bool propagate, bool upOrDown, unsigned short &count, ap_uint<8> marks[TREE_SIZE], hls::stream<node_t> &in1);

#endif


