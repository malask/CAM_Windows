#include "hls_stream.h"
#include "ap_int.h"
#include "cam.h"

static bool found = false;
void cam_top (edge_t tree1 [TREE_SIZE/2], edge_t tree2[TREE_SIZE/2],
		node_t nodo, rel_t relationship, bool fatherSearch,
		hls::stream<node_t> &result) {
#pragma HLS DATAFLOW

	// Aqui creo los canales de entrada para combinar().
	hls::stream<node_t> in1;
#pragma HLS STREAM variable=in1 depth=8 dim=1
	hls::stream<node_t> in2;
#pragma HLS STREAM variable=in2 depth=8 dim=1
	hls::stream<node_t> in1b;
#pragma HLS STREAM variable=in1b depth=8 dim=1
	hls::stream<node_t> in2b;
#pragma HLS STREAM variable=in2b depth=8 dim=1

	busqueda_cam2(tree1, nodo, relationship, fatherSearch, in1,in1b);
	busqueda_cam2(tree2, nodo, relationship, fatherSearch, in2,in2b);
	combinar2(in1,in2,in2b,in1b,result);

	return;
}


/*void busqueda_cam (edge_t tree [TREE_SIZE/2], node_t nodo, rel_t relationship, bool fatherSearch, hls::stream<node_t> &result) {

#ifndef __SYNTHESIS__
	int accesos = 0;
#endif
	edge_t valor = 0;
	rel_t node_relation =0;
	node_t compare_node=0;
	bool found = false;
#ifndef __SYNTHESIS__
	std::cout << "Comienzo" << std::endl;
#endif

	if (fatherSearch) {
		for (int i = 0, found = false; (i < TREE_SIZE/2) && (found == false); i++) {
#pragma HLS PIPELINE
#ifndef __SYNTHESIS__
			accesos++;
#endif
			valor = tree[i];
			node_relation = valor(1,0);
			compare_node = DST_NODE(valor);

			if ((compare_node == nodo) && (relationship == node_relation)) {
#ifndef __SYNTHESIS__
				std::cout << "Encontrado padre" << valor.to_uint() << std::endl;
#endif
				result.write(SRC_NODE(valor));
				//break; //Este break es el que hace que el II=2
				found = true;
			}
		}
	} else {
		for (int i = 0; i < TREE_SIZE/2; i++) {
#pragma HLS PIPELINE
#ifndef __SYNTHESIS__
			accesos++;
#endif
			valor = tree[i];
			node_relation = valor(1,0);
			compare_node = SRC_NODE(valor);



			if ((compare_node == nodo) && (relationship == node_relation)) {
				result.write(DST_NODE(valor));

#ifndef __SYNTHESIS__
				std::cout << "Encontrado hijo en " << accesos << " " << valor.to_uint() << std::endl;
#endif
			}
		}
	}


	result.write(EOT);

#ifndef __SYNTHESIS__
	std::cout << "El numero de lecturas del arbol han sido " << accesos << std::endl;
#endif
	return;
}
 */
void busqueda_cam2 (edge_t tree [TREE_SIZE/2], node_t nodo, rel_t relationship,
		bool fatherSearch, hls::stream<node_t> &result,hls::stream<node_t> &result2) {

#ifndef __SYNTHESIS__
	int accesos = 0;
#endif
	edge_t valor = 0;
	rel_t node_relation =0;
	node_t compare_node=0;
	edge_t valor2 = 0;
	rel_t node_relation2 =0;
	node_t compare_node2=0;
	bool found = false;
#ifndef __SYNTHESIS__
	std::cout << "Comienzo" << std::endl;
#endif

	if (fatherSearch && (found==false)) {
		for (int i = 0; i < TREE_SIZE/2; i+=2) {
#pragma HLS PIPELINE
#ifndef __SYNTHESIS__
			accesos+=2;
#endif
			valor = tree[i];
			node_relation = valor(1,0);
			compare_node = DST_NODE(valor);

			valor2 = tree[i+1];
			node_relation2 = valor2(1,0);
			compare_node2 = DST_NODE(valor2);
			if ((compare_node == nodo) && (relationship == node_relation)) {
#ifndef __SYNTHESIS__
				std::cout << "Encontrado padre" << valor.to_uint() << std::endl;
#endif
				result.write(SRC_NODE(valor));
				//break; //Este break es el que hace que el II=2
				found = true;
			}
			if ((compare_node2 == nodo) && (relationship == node_relation2)) {
			#ifndef __SYNTHESIS__
							std::cout << "Encontrado padre2 " << valor2.to_uint() << std::endl;
			#endif
				result2.write(SRC_NODE(valor2));
				found = true;
						}
		}
	} else {


		for (int i = 0; i < TREE_SIZE/2; i+=2) {
#pragma HLS PIPELINE

#ifndef __SYNTHESIS__
			accesos+=2;
#endif
			valor = tree[i];
			node_relation = valor(1,0);
			compare_node = SRC_NODE(valor);

			valor2 = tree[i+1];
			node_relation2 = valor2(1,0);
			compare_node2 = SRC_NODE(valor2);

			if ((compare_node == nodo) && (relationship == node_relation)) {
				result.write(DST_NODE(valor));

#ifndef __SYNTHESIS__
				std::cout << "Encontrado hijo en " << accesos << " " << valor.to_uint() << std::endl;
#endif
			}



			if ((compare_node2 == nodo) && (relationship == node_relation2)) {
				result2.write(DST_NODE(valor2));

#ifndef __SYNTHESIS__
				std::cout << "Encontrado hijo2 en " << accesos << " " << valor2.to_uint() << std::endl;
#endif
			}

		}
	}


	result.write(EOT);
	result2.write(EOT);

#ifndef __SYNTHESIS__
	std::cout << "El numero de lecturas del arbol han sido " << accesos << std::endl;
#endif
	return;
}

/* Aqui te dejo el metodo del MUX, el combinar. Creo que la l�gica est� bien, faltaria probarlo pero hasta que no
 * me quede claro lo de DATAFLOW no creo que pueda avanzar.
 */
/*void combinar(hls::stream<node_t> &in1, hls::stream<node_t> &in2, hls::stream<node_t> &out) {
	bool end_1 = false, end_2 = false;
	bool isData_1 = false, isData_2 = false;
	node_t val1,val2;
	do {
		isData_1 = in1.read_nb(val1);
		isData_2 = in2.read_nb(val2);
		if (isData_1) {
			if (val1 == EOT) end_1=true;
			else out.write(val1);
		}
		//Aquí
		if (isData_2) {
			if (val2 == EOT)end_2=true;
			else out.write(val2);
		}
#ifndef __SYNTHESIS__
		std::cout << isData_1 << " " << isData_2 << " " << end_1 << " " << end_2 << " " << val1.to_uint() << " " << val2.to_uint() << std::endl;
#endif
	} while ((!end_1) || (!end_2));

	out.write(EOT);
}
 */
void combinar2(hls::stream<node_t> &in1, hls::stream<node_t> &in2,
	hls::stream<node_t> &in3,hls::stream<node_t> &in4, hls::stream<node_t> &out) {
	bool end[4] = {false,false,false,false};
#pragma HLS ARRAY_PARTITION variable=end complete dim=1
	//bool isData[3] = {false, false, false};
	node_t val1,val2,val3,val4;

	do {
		//		isData_1 = in1.read_nb(val1);
		//		isData_2 = in2.read_nb(val2);
		if (in1.read_nb(val1)) {
#ifndef __SYNTHESIS__
			std::cout << "Leido valor en 1 " << val1 << std::endl;
#endif
			if (val1 == EOT) end[0]=true;
			else{
				#ifndef __SYNTHESIS__
				std::cout << "Escribiendo valor en 1" << val1 << std::endl;
#endif
				out.write(val1);
			}
		}

		if (in2.read_nb(val2)) {
#ifndef __SYNTHESIS__

			std::cout << "Leido valor en 2 " << val2 << std::endl;
#endif
			if (val2 == EOT) end[1]=true;
			else {
#ifndef __SYNTHESIS__
				std::cout << "Escribiendo valor en 2 " << val2 << std::endl;
#endif
				out.write(val2);
			}

		}
		if (in3.read_nb(val3)) {
#ifndef __SYNTHESIS__

			std::cout << "Leido valor en 3  " << val3 << std::endl;
#endif
			if (val3 == EOT) end[2]=true;
			else{
#ifndef __SYNTHESIS__

				std::cout << "Escribiendo valor en 3" << val3 << std::endl;
#endif
				out.write(val3);
			}

}
	if (in4.read_nb(val4)) {

			if (val4==EOT){ end[3]=true;
#ifndef __SYNTHESIS__

			std::cout << "Leido valor en 4  " << val4 << std::endl;
#endif
			}else {
#ifndef __SYNTHESIS__

			std::cout << "Escribiendo valor en 4 " << val4 << std::endl;
#endif
			out.write(val4);
		}
	}

} while ((!end[0]) || (!end[1]) || (!end[2]) || (!end[3]));

out.write(EOT);
found=false;
}
