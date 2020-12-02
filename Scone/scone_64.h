#ifndef CAM_H_
#define CAM_H_

#include "hls_stream.h"
#include "ap_int.h"
#include <bitset>
#include <ctype.h>

/*
#define TREE_SIZE 160
#define NODE_BITS 8
*/
#define TREE_SIZE 80
#define NODE_BITS 7



	#define REL_BITS 2
	#define EDGE_BITS (NODE_BITS*2 + REL_BITS)
	#define SRC_NODE(e) ((e)(EDGE_BITS-1,EDGE_BITS-NODE_BITS))
	#define DST_NODE(e) ((e)(EDGE_BITS-NODE_BITS-1,REL_BITS))
	#define EOT 0
	#define N_NODES 64


	#define WORD_SIZE (NODE_BITS+REL_BITS)
	#define WORD_NODE(e) ((e)(NODE_BITS+REL_BITS-1,REL_BITS))
	#define WORD_REL(e)  ((e)(REL_BITS,1))



	typedef ap_uint<EDGE_BITS> edge_t;
	typedef ap_uint<NODE_BITS> node_t;
	typedef ap_uint<REL_BITS> rel_t;
	typedef ap_uint<WORD_SIZE> cmd_scone_t;


	void busqueda_cam (node_t nodo, rel_t relationship, bool fatherSearch, hls::stream<node_t> &result);
	void top_function (cmd_scone_t nodo, ap_uint<3> op, hls::stream<node_t> &path);
	void propagate(cmd_scone_t word, unsigned short &count, ap_uint<8> marks[TREE_SIZE]);
	void scan(cmd_scone_t word, bool upOrDown, unsigned short &count, ap_uint<8> marks[TREE_SIZE]);
#endif


