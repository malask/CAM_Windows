
//Incluir cabecera parae evitar recursividades.

#include "hls_stream.h"
#include "ap_int.h"

#ifndef SEARCH_MODE
#define  SEARCH_MODE 1 // Si no definimos la busqueda, por defecto será BFS
#endif

#ifndef TREE_SIZE
#define TREE_SIZE 128
#endif

#if TREE_SIZE == 128
	#define NODE_BITS 8
		#if SEARCH_MODE == 1
			#define TREE_FILE "hls_tree_bfs_128.txt"
		#else
			#define TREE_FILE "hls_tree_dfs_128.txt"
		#endif
#endif

#if TREE_SIZE == 256
	#define NODE_BITS 9
		#if SEARCH_MODE == 1
			#define TREE_FILE "hls_bfs_tree_256.txt"
		#else
			#define TREE_FILE "hls_dfs_tree_256.txt"
		#endif
#endif

#if TREE_SIZE == 512
	#define NODE_BITS 10
		#if SEARCH_MODE == 1
			#define TREE_FILE "hls_bfs_tree_512.txt"
		#else
			#define TREE_FILE "hls_dfs_tree_512.txt"
		#endif
#endif

#if TREE_SIZE == 1024
	#define NODE_BITS 11
		#if SEARCH_MODE == 1
			#define TREE_FILE "hls_bfs_tree_1024.txt"
		#else
			#define TREE_FILE "hls_dfs_tree_1024.txt"
		#endif
#endif

#if TREE_SIZE == 2048
	#define NODE_BITS 12
		#if SEARCH_MODE == 1
			#define TREE_FILE "hls_bfs_tree_2048.txt"
		#else
			#define TREE_FILE "hls_dfs_tree_2048.txt"
		#endif
#endif

#if TREE_SIZE == 4096
	#define NODE_BITS 13
		#if SEARCH_MODE == 1
			#define TREE_FILE "hls_bfs_tree_4096.txt"
		#else
			#define TREE_FILE "hls_dfs_tree_4096.txt"
		#endif
#endif

#if TREE_SIZE == 8192
	#define NODE_BITS 14
		#if SEARCH_MODE == 1
			#define TREE_FILE "hls_bfs_tree_8192.txt"
		#else
			#define TREE_FILE "hls_dfs_tree_8192.txt"
		#endif
#endif

#if TREE_SIZE == 16384
	#define NODE_BITS 15
		#if SEARCH_MODE == 1
			#define TREE_FILE "hls_bfs_tree_16384.txt"
		#else
			#define TREE_FILE "hls_dfs_tree_16384.txt"
		#endif
#endif

#if TREE_SIZE == 32768
	#define NODE_BITS 16
		#if SEARCH_MODE == 1
			#define TREE_FILE "hls_bfs_tree_32768.txt"
		#else
			#define TREE_FILE "hls_dfs_tree_32768.txt"
		#endif
#endif


#define REL_BITS 2
#define EDGE_BITS (NODE_BITS*2 + REL_BITS)
#define SRC_NODE(e) ((e)(EDGE_BITS-1,EDGE_BITS-NODE_BITS))
#define DST_NODE(e) ((e)(EDGE_BITS-NODE_BITS-1,REL_BITS))

typedef ap_uint<EDGE_BITS> edge_t;
typedef ap_uint<NODE_BITS> node_t;
typedef ap_uint<REL_BITS> rel_t;

void busqueda_cam (edge_t tree[TREE_SIZE], node_t nodo, rel_t relationship, bool order, hls::stream<node_t> *result);



