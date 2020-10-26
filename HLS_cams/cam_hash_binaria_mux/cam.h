#ifndef CAM_H_
#define CAM_H_
	#include "hls_stream.h"
	#include "ap_int.h"

	#ifndef SEARCH_MODE
	#define SEARCH_MODE 1
	#endif

	#ifndef TREE_SIZE
	#define TREE_SIZE 128
	#endif


	#if TREE_SIZE == 128
		#define NODE_BITS 8
	#endif

	#if TREE_SIZE == 256
		#define NODE_BITS 9
	#endif

	#if TREE_SIZE == 512
		#define NODE_BITS 10
	#endif

	#if TREE_SIZE == 1024
		#define NODE_BITS 11
	#endif

	#if TREE_SIZE == 2048
		#define NODE_BITS 12
	#endif

	#if TREE_SIZE == 4096
		#define NODE_BITS 13

	#endif

	#if TREE_SIZE == 8192
		#define NODE_BITS 14
	#endif

	#if TREE_SIZE == 16384
		#define NODE_BITS 15
	#endif

	#if TREE_SIZE == 32768
		#define NODE_BITS 16
	#endif

	#define REL_BITS 2
	#define EDGE_BITS (NODE_BITS*2 + REL_BITS)
	#define SRC_NODE(e) ((e)(EDGE_BITS-1,EDGE_BITS-NODE_BITS))
	#define DST_NODE(e) ((e)(EDGE_BITS-NODE_BITS-1,REL_BITS))
	#define EOT 0
	#define NUM_BUCKETS 8

	typedef ap_uint<EDGE_BITS> edge_t;
	typedef ap_uint<NODE_BITS> node_t;
	typedef ap_uint<REL_BITS> rel_t;


	void busqueda_cam (node_t nodo, rel_t relationship, bool fatherSearch, hls::stream<node_t> &in1,hls::stream<node_t> &in2);
	void top_function (node_t nodo, rel_t relationship, bool fatherSearch, hls::stream<node_t> &result );
	void combinar(hls::stream<node_t> &in1, hls::stream<node_t> &in2, hls::stream<node_t> &result);

#endif


