#include "hls_stream.h"
#include "ap_int.h"
#include "cam.h"

//#define NODE_MASK 0xF // ((1<<4)-1) Cada nodo ocupa 4 bits. Esto es una máscara que he creado para
//#define RELATION_MASK 0x3 // ((1<<2)-1 )Expresarlo en hexadecimal.
//#define TREE_SIZE 1024
#define SEARCH_MODE 0

// Declaracion de arbol estático
 void busqueda_cam (edge_t tree[TREE_SIZE], node_t nodo, rel_t relationship, bool order, hls::stream<node_t> *result) {
	/*unsigned  position_hi, position_lo = 0;
	if (order) {  //Significa que buscamos nuestros hijos
		position_lo = ;
		position_hi = WORD_BITS - 1;
	} else {
		position_lo = RELATION_BITS;
		position_hi = (RELATION_BITS+NODE_BITS)-1;
	}  // Significa que buscamos nuestros padres */
#ifndef __SYNTHESIS__

	int accesos = 0;
#endif
	ap_uint<EDGE_BITS> valor = 0;
	ap_uint<REL_BITS> node_relation =0;
	ap_uint<NODE_BITS> compare_node=0;
	for (int i = 0; i < TREE_SIZE; i++) {
#ifndef __SYNTHESIS__
	accesos++;
#endif
			  valor = tree[i];

				  node_relation = valor(1,0);
				  if (order) compare_node = SRC_NODE(valor);
				  else compare_node = DST_NODE(valor);
				  if ((compare_node == nodo) && (relationship == node_relation))  result->write_nb(compare_node);
			  	 //result->write_nb(

	}
#ifndef __SYNTHESIS__
	std::cout << "El numero de lecturas del arbol han sido " << accesos << std::endl;
#endif
}

 //BUSCAR SOFTWARE DE GENRACION DE ARBOLES
 // REPRESNTACION GRAFICA DEL ARBOL
 // SCRIPT PARA INCLUIRLO EN EL CPP
