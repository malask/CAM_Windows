#include "hls_stream.h"
#include "ap_int.h"
#include "cam.h"

//#define NODE_MASK 0xF // ((1<<4)-1) Cada nodo ocupa 4 bits. Esto es una máscara que he creado para
//#define RELATION_MASK 0x3 // ((1<<2)-1 )Expresarlo en hexadecimal.
//#define TREE_SIZE 1024

// Declaracion de arbol estático


void top_function(edge_t tree1[TREE_SIZE/2], edge_t tree2[TREE_SIZE], node_t nodo, rel_t relationship, bool fatherSearch, hls::stream<node_t> &result){
	static hls::stream<node_t> in1("ENTRADA_FOR1");
	#pragma HLS STREAM variable=in1 depth=8 dim=1
	static hls::stream<node_t> in2("ENTRADA_FOR2");
	#pragma HLS STREAM variable=in2 depth=8 dim=1
	static hls::stream<node_t> in1b;
	#pragma HLS STREAM variable=in1b depth=8 dim=1
	static hls::stream<node_t> in2b;
	#pragma HLS STREAM variable=in2b depth=8 dim=1
#pragma HLS DATAFLOW
	busqueda_cam(tree1, nodo, relationship, fatherSearch, in1,in1b);
	busqueda_cam(tree2, nodo, relationship, fatherSearch, in2,in2b);
	combinar(in1,in2,in1b,in2b,result);
}
void busqueda_cam (edge_t tree [TREE_SIZE/2], node_t nodo, rel_t relationship,
		bool fatherSearch, hls::stream<node_t> &result1,hls::stream<node_t> &result2) {
#ifndef __SYNTHESIS__
	int accesos = 0;
#endif
	ap_uint<EDGE_BITS> valor_min, valor_max = 0;
	ap_uint<REL_BITS> node_relation_min, node_relation_max =0;
	ap_uint<NODE_BITS> compare_node_min, compare_node_max, founded_node=0;
	bool flag_min, flag_max= false;
	if (nodo == 1 && fatherSearch) {
		result1.write(EOT);
		result2.write(EOT);
		return;
	}
if (fatherSearch) {
	for (int i = 0;i<TREE_SIZE/2; i+=2) {
#pragma HLS PIPELINE
#ifndef __SYNTHESIS__
		accesos++;
#endif
			  valor_min = tree[i];
			  node_relation_min = valor_min(1,0);
			  compare_node_min = DST_NODE(valor_min);

			  valor_max = tree[i+1];
			  node_relation_max = valor_max(1,0);
			  compare_node_max = DST_NODE(valor_max);


// Este if es para buscar al padre del nodo proporcionado a la CAM
				  if ((compare_node_min == nodo) && (relationship == node_relation_min)) {
					  result1.write(SRC_NODE(valor_min));
				  }
				  if ((compare_node_max == nodo) && (relationship == node_relation_max)) {
					  result2.write(SRC_NODE(valor_max));
				  }
// Este if es para buscar los hijos del nodo proporcionado
}
}
	result1.write(EOT);
	result2.write(EOT);
#ifndef __SYNTHESIS__
	std::cout << "El numero de lecturas del arbol han sido " << accesos << std::endl;
#endif
	return;
}

void combinar(hls::stream<node_t> &in1, hls::stream<node_t> &in2, hls::stream<node_t> &in3, hls::stream<node_t> &in4, hls::stream<node_t> &result) {
	bool end_1 = false, end_2 = false, end_3 = false, end_4 = false;
		bool isData_1 = false, isData_2 = false, isData_3 = false, isData_4 = false;
		node_t val1,val2,val3,val4;
		do {
#pragma HLS PIPELINE
			isData_1 = in1.read_nb(val1);
			isData_2 = in2.read_nb(val2);
			isData_3 = in3.read_nb(val3);
			isData_4 = in4.read_nb(val4);
			if (isData_1) {
				if (val1 == EOT) end_1=true;
				else result.write(val1);
			}
			//Aquí
			if (isData_2) {
				if (val2 == EOT)end_2=true;
				else result.write(val2);
			}
			if (isData_3) {
				if (val2 == EOT) end_3=true;
				else result.write(val3);
			}
			if (isData_4) {
				if (val3 == EOT) end_4=true;
				else result.write(val4);
			}
		} while ((!end_1) || (!end_2) || (!end_3) || (!end_4));

		result.write(EOT);
}

 //BUSCAR SOFTWARE DE GENRACION DE ARBOLES
 // REPRESNTACION GRAFICA DEL ARBOL
 // SCRIPT PARA INCLUIRLO EN EL CPP
