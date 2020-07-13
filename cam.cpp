#include "hls_stream.h"
#include "ap_int.h"
#include "cam.h"

//#define NODE_MASK 0xF // ((1<<4)-1) Cada nodo ocupa 4 bits. Esto es una máscara que he creado para
//#define RELATION_MASK 0x3 // ((1<<2)-1 )Expresarlo en hexadecimal.
//#define TREE_SIZE 1024

// Declaracion de arbol estático
 void busqueda_cam (edge_t tree[TREE_SIZE], node_t nodo, rel_t relationship, bool fatherSearch, hls::stream<node_t> *result) {
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
	ap_uint<EDGE_BITS> valor_min, valor_max = 0;
	ap_uint<REL_BITS> node_relation =0;
	ap_uint<NODE_BITS> compare_node_min, compare_node_max, founded_node=0;
	bool flag_min, flag_max= false;
	if (nodo == 1 && fatherSearch) {
		result->write(-1);
		return;
	}
	for (int i = 0, j=TREE_SIZE-1; i < j; i++,j--) {
#pragma HLS PIPELINE
#ifndef __SYNTHESIS__
		accesos++;
#endif
			  valor_min = tree[i];
			  valor_max = tree[j];

				  node_relation = valor_min(1,0);
				  if (fatherSearch){
					  compare_node_min = DST_NODE(valor_min);
					  compare_node_max = DST_NODE(valor_max);
				  }
				  else{
					  compare_node_min = SRC_NODE(valor_min);
					  compare_node_max = SRC_NODE(valor_max);
				  }

// Este if es para buscar al padre del nodo proporcionado a la CAM
				  if ((compare_node_min == nodo) && (relationship == node_relation) && fatherSearch) {
					  result->write(SRC_NODE(valor_min));
					  break;
				  }
// Este if es para buscar los hijos del nodo proporcionado
				  if ((compare_node_min == nodo) && (relationship == node_relation) && !fatherSearch) {
					  result->write(DST_NODE(valor_min));
					  flag_min = true;
// ------------- Para el hijo aún no hay condición de parada establecida. Estudiaremos cuál es la condicion de parada en funcion del tipo de búsqueda recorrido.
				  } else if (flag_min == true) break;
//				  if (flag && (compare_node !=nodo )) break;
// ------------- Modificar el anterior if si queremos hacer una busqueda secuencial sin condición de parada para el padre
				  	 if ((compare_node_max == nodo) && (relationship == node_relation) && fatherSearch) {
				  		 result->write(SRC_NODE(valor_max));
				  		 break;
				  	 }
				  	 if ((compare_node_max==nodo) && (relationship == node_relation) && !fatherSearch)  {
				  		 result->write(DST_NODE(valor_max));
				  		 flag_max=true;
				  	 } else if (flag_max == true) break;
	}
	result->write(TREE_SIZE+1);
#ifndef __SYNTHESIS__
	std::cout << "El numero de lecturas del arbol han sido " << accesos << std::endl;
#endif
	return;
}

 //BUSCAR SOFTWARE DE GENRACION DE ARBOLES
 // REPRESNTACION GRAFICA DEL ARBOL
 // SCRIPT PARA INCLUIRLO EN EL CPP
