#include "hls_stream.h"
#include "ap_int.h"
#include "cam.h"

//#define NODE_MASK 0xF // ((1<<4)-1) Cada nodo ocupa 4 bits. Esto es una m�scara que he creado para
//#define RELATION_MASK 0x3 // ((1<<2)-1 )Expresarlo en hexadecimal.
//#define TREE_SIZE 1024

// Declaracion de arbol est�tico


void top_function(edge_t tree[TREE_SIZE], node_t nodo, rel_t relationship, bool fatherSearch, hls::stream<node_t> &result){
	static hls::stream<edge_t> in1("ENTRADA_FOR1");
	#pragma HLS STREAM variable=in1 depth=8 dim=1
	static hls::stream<edge_t> in2("ENTRADA_FOR2");
	#pragma HLS STREAM variable=in2 depth=8 dim=1
	static hls::stream<node_t> in1b;
	#pragma HLS STREAM variable=in1b depth=8 dim=1
	static hls::stream<node_t> in2b;
	#pragma HLS STREAM variable=in2b depth=8 dim=1
#pragma HLS DATAFLOW
	preprocessor_cam(tree,nodo,fatherSearch,in1,in2);
	busqueda_cam(nodo, relationship, fatherSearch, in1,in1b);
	busqueda_cam(nodo, relationship, fatherSearch, in2,in2b);
	combinar(in1b,in2b,result);
}

void preprocessor_cam(edge_t tree[TREE_SIZE], node_t nodo, bool fatherSearch,hls::stream<edge_t> &send1, hls::stream<edge_t> &send2) {
	ap_uint<EDGE_BITS> nodo1,nodo2 =0;
	if (nodo==1 && fatherSearch) {
		send1.write(EOT);
		send2.write(EOT);
	}else{
	for (int i=0;i<TREE_SIZE;i+=2){
#pragma HLS PIPELINE
		nodo1 = tree[i];
		nodo2 = tree[i+1];
		send1.write(nodo1);
		send2.write(nodo2);
		}
	send1.write(EOT);
	send2.write(EOT);
	}

}
void busqueda_cam(node_t nodo, rel_t relationship, bool fatherSearch, hls::stream<edge_t> &receive, hls::stream<node_t> &result){
	ap_uint<EDGE_BITS> readData;
	ap_uint<REL_BITS> node_relation;
	ap_uint<NODE_BITS> compare_node;
	bool end=false;
	bool isData;
	if (fatherSearch) {
		while (!end) {
#pragma HLS PIPELINE
			isData = receive.read_nb(readData);
			if (isData){
				if (readData == EOT) end = true;
				else {
				node_relation = readData(1,0);
				compare_node = DST_NODE(readData);
				if (compare_node==nodo && relationship == node_relation) {
					result.write(SRC_NODE(readData));

				}
			}
		}
		}
	} else {
		while (!end) {
		#pragma HLS PIPELINE
					isData = receive.read_nb(readData);
					if (isData){
						if (readData == EOT) end = true;
						else {
						node_relation = readData(1,0);
						compare_node = SRC_NODE(readData);
						if (compare_node==nodo && relationship == node_relation) result.write(DST_NODE(readData));

						}
					}
				}
		}
	result.write(EOT);
}
/*void busqueda_cam (node_t nodo, rel_t relationship,
		bool fatherSearch, hls::stream<node_t> &send1,hls::stream<node_t> &send2) {
#ifndef __SYNTHESIS__
	int accesos = 0;
#endif
	ap_uint<EDGE_BITS> valor_min, valor_max = 0;
	ap_uint<REL_BITS> node_relation_min, node_relation_max =0;
	ap_uint<NODE_BITS> compare_node_min, compare_node_max, founded_node=0;
	bool flag_min, flag_max= false;
	if (nodo == 1 && fatherSearch) {
		send1.write(EOT);
		send2.write(EOT);
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
} else {
	for (int i = 0;i<TREE_SIZE/2; i+=2) {
#pragma HLS PIPELINE
#ifndef __SYNTHESIS__
		accesos++;
#endif
			  valor_min = tree[i];
			  node_relation_min = valor_min(1,0);
			  compare_node_min = SRC_NODE(valor_min);

			  valor_max = tree[i+1];
			  node_relation_max = valor_max(1,0);
			  compare_node_max = SRC_NODE(valor_max);


// Este if es para buscar al padre del nodo proporcionado a la CAM
				  if ((compare_node_min == nodo) && (relationship == node_relation_min)) {
					  result1.write(DST_NODE(valor_min));
				  }
				  if ((compare_node_max == nodo) && (relationship == node_relation_max)) {
					  result2.write(DST_NODE(valor_max));
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
*/
void combinar(hls::stream<node_t> &in1, hls::stream<node_t> &in2,hls::stream<node_t> &result) {
		bool end[2] = {false,false};
#pragma HLS ARRAY_PARTITION variable=end complete dim=1
		bool isData_1 = false, isData_2 = false;
		node_t val1,val2;
		do {
#pragma HLS PIPELINE
			isData_1 = in1.read_nb(val1);
			isData_2 = in2.read_nb(val2);

			if (isData_1) {
				if (val1 == EOT) end[0]=true;
				else result.write(val1);
			}
			//Aqu�
			if (isData_2) {
				if (val2 == EOT) end[1]=true;
				else result.write(val2);
			}

		} while ((!end[0]) || (!end[1]));

		result.write(EOT);
}

 //BUSCAR SOFTWARE DE GENRACION DE ARBOLES
 // REPRESNTACION GRAFICA DEL ARBOL
 // SCRIPT PARA INCLUIRLO EN EL CPP
