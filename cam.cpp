#include "hls_stream.h"
#include "ap_int.h"
#include "cam.h"

//#define NODE_MASK 0xF // ((1<<4)-1) Cada nodo ocupa 4 bits. Esto es una máscara que he creado para
//#define RELATION_MASK 0x3 // ((1<<2)-1 )Expresarlo en hexadecimal.
//#define TREE_SIZE 1024

// Declaracion de arbol estático


void top_function(edge_t tree1[TREE_SIZE/2], edge_t tree2[TREE_SIZE], node_t nodo, rel_t relationship, bool fatherSearch, hls::stream<node_t> &result){
	hls::stream<node_t> in1("ENTRADA_FOR1");
	#pragma HLS STREAM variable=in1 depth=8 dim=1
	hls::stream<node_t> in2("ENTRADA_FOR2");
	#pragma HLS STREAM variable=in2 depth=8 dim=1
	busqueda_cam(tree1,nodo,relationship,fatherSearch,in1);
	busqueda_cam(tree2,nodo,relationship,fatherSearch,in2);
	combinar(in1,in2,result);
}
void busqueda_cam (edge_t tree[TREE_SIZE/2], node_t nodo, rel_t relationship, bool fatherSearch, hls::stream<node_t> &result) {
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
		result.write(EOT);
		return;
	}
if (fatherSearch) {
	for (int i = 0;i<TREE_SIZE/2; i++) {
#pragma HLS PIPELINE
#ifndef __SYNTHESIS__
		accesos++;
#endif
			  valor_min = tree[i];
			  node_relation = valor_min(1,0);
				compare_node_min = DST_NODE(valor_min);

// Este if es para buscar al padre del nodo proporcionado a la CAM
				  if ((compare_node_min == nodo) && (relationship == node_relation) && fatherSearch) {
					  result.write(SRC_NODE(valor_min));
				  }
// Este if es para buscar los hijos del nodo proporcionado

}
}
	result.write(EOT);
#ifndef __SYNTHESIS__
	std::cout << "El numero de lecturas del arbol han sido " << accesos << std::endl;
#endif
	return;
}

void combinar(hls::stream<node_t> &in1, hls::stream<node_t> &in2, hls::stream<node_t> &result) {
	node_t valor1=0,valor2=0;
	while(!in1.empty()){
		valor1=in1.read();
#ifndef __SYNTHESIS__
		std::cout << "Leido valor " << valor1 << std::endl;
#endif
		if (valor1 != EOT) result.write(valor1);

	}
	while(!in2.empty()){
		valor2=in2.read();
#ifndef __SYNTHESIS__
		std::cout << "Leido valor " << valor2 << std::endl;
#endif
		if (valor2 != EOT) result.write(valor2);
	}

	result.write(EOT);
}

 //BUSCAR SOFTWARE DE GENRACION DE ARBOLES
 // REPRESNTACION GRAFICA DEL ARBOL
 // SCRIPT PARA INCLUIRLO EN EL CPP
