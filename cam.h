
//Incluir cabecera parae evitar recursividades.

#include "hls_stream.h"
#include "ap_int.h"

#ifndef NODE_MASK
#define NODE_MASK ((1<<4)-1)
#endif

#ifndef RELATION_MASK
#define RELATION_MASK ((((1<<2)-1)))
#endif

#ifndef EOT
#define EOT 0
#endif

#ifndef TREE_SIZE
#define TREE_SIZE 1024
#endif

#ifndef NODE_BITS
#define NODE_BITS 4
#endif

#ifndef RELATION_BITS
#define RELATION_BITS 2
#endif

#ifndef WORD_BITS
#define WORD_BITS ((NODE_BITS)*2 + RELATION_BITS)
#endif


 void busqueda_cam (ap_uint<10> tree[1024], ap_uint<4> nodo, ap_uint<2> relationship, bool order, hls::stream<ap_uint<10>> *result);
