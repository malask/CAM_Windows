#include "hls_stream.h"
#include "ap_int.h"
#include "cam.h"




void busqueda_cam (edge_t tree [TREE_SIZE], node_t nodo, rel_t relationship, bool fatherSearch, hls::stream<node_t> &result) {

//He decidido conservar la directiva para indicarle que use una BRAM de dos puertos, pero sigue sin usarlas.
#pragma HLS RESOURCE variable=tree  core=RAM_2P_BRAM

// Aqui creo los canales de entrada para combinar().
	hls::stream<node_t> in1;
	hls::stream<node_t> in2;

// Empiezo a utilizar el combinar(), pero no tengo claro si iría aquí o en el for.
	combinar(in1,in2,result);

#ifndef __SYNTHESIS__
	int accesos = 0;
#endif
	ap_uint<EDGE_BITS> valor_min, valor_max = 0;
	ap_uint<REL_BITS> node_relation =0;
	ap_uint<NODE_BITS> compare_node_min, compare_node_max=0;
	bool flag_min, flag_max= false;

	// Esto es algo que he incorporado para controlar casos absurdos como encontrar el padre del nodo raíz. Nos ahorra problemas
	//y estar haciendo lecturas innecesarias si se produce el caso. He utilizado no bloqueantes para perder el menor tiempo posible.
	// ¿Como lo ves?
	if (nodo == 1 && fatherSearch) {
		in1.write_nb(EOT);
		in2.write_nb(EOT);
		return;
	}

	/*Aqui es donde tengo muchas dudas. Entiendo que el DATAFLOW es para realizar tareas concurrentemente pero por ejemplo, como
	 * lo usaria aqui? Tendria que dividir el for en dos FOR distintos, uno qu vaya de 0 a N/2 -1 y otro que vaya de N/2 a N y
	 * utilizar el pramga DATAFLOW en cada uno de ellos? O estoy pasando algo por alto y no estoy viendo bien como utilizar
	 * el pragma?
	 */
	for (int i = 0, j=TREE_SIZE-1; i < j; i++,j--) {
	#pragma HLS DATAFLOW
		#ifndef __SYNTHESIS__
		accesos++;
		#endif
		valor_min = tree[i];
		valor_max = tree[j];
		node_relation = valor_min(1,0);
		if (fatherSearch){
			compare_node_min = DST_NODE(valor_min);
			compare_node_max = DST_NODE(valor_max);
		} else{
			compare_node_min = SRC_NODE(valor_min);
			compare_node_max = SRC_NODE(valor_max);
		}

		// IF para encontrar padres/nodos del for de N/2
		if ((compare_node_min == nodo) && (relationship == node_relation) && fatherSearch) {
			in1.write(SRC_NODE(valor_min));
			break;
				  }

		if ((compare_node_min == nodo) && (relationship == node_relation) && !fatherSearch) {
			in1.write(DST_NODE(valor_min));
			flag_min = true;
		} else if (flag_min == true) break;
		// IF para encontrar padres/nodos del for de N/2
		if ((compare_node_max == nodo) && (relationship == node_relation) && fatherSearch) {
			in2.write(SRC_NODE(valor_max));
			break;
		}
		if ((compare_node_max==nodo) && (relationship == node_relation) && !fatherSearch)  {
			in2.write(DST_NODE(valor_max));
			flag_max=true;
		} else if (flag_max == true) break;
	}
	#ifndef __SYNTHESIS__
		std::cout << "El numero de lecturas del arbol han sido " << accesos << std::endl;
	#endif
	return;
}

/* Aqui te dejo el metodo del MUX, el combinar. Creo que la lógica está bien, faltaria probarlo pero hasta que no
 * me quede claro lo de DATAFLOW no creo que pueda avanzar.
 */
void combinar(hls::stream<node_t> &in1, hls::stream<node_t> &in2, hls::stream<node_t> &out) {
	bool end_1, end_2 = false;
	bool isData_1, isData_2 = false;
	node_t val1,val2;
	do {
		isData_1 = in1.read_nb(val1);
		isData_2 = in2.read_nb(val2);
	if (isData_1) {
		if (val1 == EOT) end_1=true;
		else out.write(val1);
	}
	if (isData_2) {
		if (val2 == EOT)end_2=true;
	}	else out.write(val2);

	} while ((!end_1) || (!end_2));
}


