#include "hls_stream.h"
#include "ap_int.h"
#include "cam.h"

 void busqueda_cam (edge_t tree[TREE_SIZE], node_t nodo, rel_t relationship, bool fatherSearch, hls::stream<node_t> *result) {

#ifndef __SYNTHESIS__
	int accesos = 0;
#endif
	ap_uint<EDGE_BITS> valor = 0;
	ap_uint<REL_BITS> node_relation =0;
	ap_uint<NODE_BITS> compare_node=0;
	bool flag = false;
	for (int i = 0; i < TREE_SIZE; i++) {
#ifndef __SYNTHESIS__
	accesos++;
#endif
			  valor = tree[i];

				  node_relation = valor(1,0);
				  if (fatherSearch) compare_node = DST_NODE(valor);
				  else compare_node = SRC_NODE(valor);

// Este if es para buscar al padre del nodo proporcionado a la CAM
				  if ((compare_node == nodo) && (relationship == node_relation) && fatherSearch) {
					  result->write(SRC_NODE(valor));
					  break;
				  }
// Este if es para buscar los hijos del nodo proporcionado
				  if ((compare_node == nodo) && (relationship == node_relation) && !fatherSearch) {
					  result->write(DST_NODE(valor));
					  flag=true;
// ------------- Para el hijo aún no hay condición de parada establecida. Estudiaremos cuál es la condicion de parada en funcion del tipo de búsqueda recorrido.
				  }
//				  if (flag && (compare_node !=nodo )) break;
// ------------- Modificar el anterior if si queremos hacer una busqueda secuencial sin condición de parada para el padre


	}
#ifndef __SYNTHESIS__
	std::cout << "El numero de lecturas del arbol han sido " << accesos << std::endl;
#endif
}

 //BUSCAR SOFTWARE DE GENRACION DE ARBOLES
 // REPRESNTACION GRAFICA DEL ARBOL
 // SCRIPT PARA INCLUIRLO EN EL CPP
