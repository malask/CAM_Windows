#include "scone.h"
#include <stdio.h>
#include <hls_stream.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctype.h>

using namespace std;

// 128: 127, 8-> Este ultimo es un commando de la operacion
// 64: 64, 47
// 256:: 250, 11
// 512 : 317,39
// 1024: 1022, 58
int main () {
	ifstream infile;
	string line;
	unsigned int cnt = 0;
	extern edge_t bfstree[];
	hls::stream<node_t> salida_hw;
	node_t node = 127;
	rel_t rel = 0;
	cmd_scone_t prueba = (node,rel);
	node_t salida;
	ap_uint<8> marks[N_NODES];

	scone_engine(1,CLEAR,salida_hw,marks);  // Reset
	//scone_engine(1,CLEAR,salida_hw);
	while (!salida_hw.empty()){
		salida = salida_hw.read();
		cout << "Salida CLEAR: "  << salida << endl;
	}

	scone_engine(prueba,UPSCAN,salida_hw,marks); // Operacion upScan desde el nodo 127.
	//scone_engine(prueba,UPSCAN,salida_hw); // Operacion upScan desde el nodo 127.
	//	assert(salida_hw.empty()==false);
	//	salida = salida_hw.read();
	while (!salida_hw.empty()){
		salida = salida_hw.read();
		cout << "Salida UP: "  << salida << endl;
	}

	scone_engine(1,PROPAGATE,salida_hw,marks); // Operacion de propagaci�n de la relacion 1 por los nodos marcados
	//scone_engine(1,PROPAGATE,salida_hw);
	//salida = salida_hw.read();
	while (!salida_hw.empty()){
		salida = salida_hw.read();
		cout << "Salida PROP: "  << salida << endl;
	}

	node = 8;
	rel=0;
	prueba = (node,rel);
	scone_engine(prueba,DOWNSCAN,salida_hw,marks);  // Operacion downscan desde el 8
	//scone_engine(prueba,DOWNSCAN,salida_hw);
	//salida = salida_hw.read();
	while (!salida_hw.empty()){
		salida = salida_hw.read();
		cout << "Salida DOWN: "  << salida << endl;
	}

	scone_engine(6,INTERSECTION, salida_hw,marks); // Operacion intersecci�n
	//scone_engine(6,INTERSECTION, salida_hw);
	while (!salida_hw.empty()){
		salida = salida_hw.read();
		cout << "Salida INTER: "  << salida << endl;
	}

	return 0;
}

