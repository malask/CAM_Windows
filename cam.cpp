#include "hls_stream.h"
#include "ap_int.h"
#include "cam.h"

//#define NODE_MASK 0xF // ((1<<4)-1) Cada nodo ocupa 4 bits. Esto es una máscara que he creado para
//#define RELATION_MASK 0x3 // ((1<<2)-1 )Expresarlo en hexadecimal.
//#define TREE_SIZE 1024

static ap_uint<10> tree[TREE_SIZE];

// Declaracion de arbol estático
 void busqueda_cam (ap_uint<NODE_BITS> nodo, ap_uint<RELATION_BITS> relationship, bool order, hls::stream<ap_uint<WORD_BITS>> &result) {
	unsigned  position_hi, position_lo = 0;
	if (order) {  //Significa que buscamos nuestros hijos
		position_lo = (RELATION_BITS+NODE_BITS);
		position_hi = WORD_BITS - 1;
	} else {
		position_lo = RELATION_BITS;
		position_hi = (RELATION_BITS+NODE_BITS)-1;
	}  // Significa que buscamos nuestros padres
	ap_uint<WORD_BITS> valor = 0;
	ap_uint<RELATION_BITS> node_relation =0;
	ap_uint<NODE_BITS> compare_node=0;
	for (int i = 0; i < TREE_SIZE; i++) {
			  valor = tree[i];
			  if (valor == EOT)  break;
			  else {
				  node_relation = valor(1,0);
				  compare_node = valor(position_lo,position_hi);
				  if ((compare_node == nodo) && (relationship == node_relation))  result.write_nb(tree[i]);
			  	 //result->write_nb(
			  }
	}
}

 //BUSCAR SOFTWARE DE GENRACION DE ARBOLES
 // REPRESNTACION GRAFICA DEL ARBOL
 // SCRIPT PARA INCLUIRLO EN EL CPP
