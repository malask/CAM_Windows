#include "cam.h"
#include <stdio.h>
#include <hls_stream.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
//#include "data_128.c"

using namespace std;


int main (int argc, char *argv[]) {
	ifstream infile;
	string line;
	unsigned int cnt = 0;
	extern int caminos_padres[];
	extern int caminos_hijos[];
	extern int selected[];
	node_t prueba;


	node_t salida_lectura;

	bool buscarPadre = true;
	hls::stream<node_t> salida_hw_1("CANAL_RESULTADO_1");
	std::vector<node_t> hijos;
    short relation = 0;
	for (int i = 0; i < TREE_SIZE/4;i++) {
		prueba = selected[i];
		cout << "Camino de padres del nodo: " << prueba << ": " << endl;
		word_t palabra = (((prueba & 0xFFFF) << 2) | (relation & 0xFF));
		top_function(palabra,true,salida_hw_1);
		while(!salida_hw_1.empty()) {
			salida_lectura = salida_hw_1.read();
			assert(caminos_padres[cnt]==salida_lectura);
			cout << salida_lectura << " " ;
			cnt+=1;

		}
		cout << endl;
	}

    cnt = 0;
    for (int i = 0; i < TREE_SIZE/4; i++) {
    	prueba = selected[i];
    	cout << "Camino de los hijos de " << prueba << ": " << endl;
		word_t palabra = (((prueba & 0xFFFF) << 2) | (relation & 0xFF));
		top_function(palabra,false,salida_hw_1);
		while (!salida_hw_1.empty()) {
			salida_lectura = salida_hw_1.read();
			assert(caminos_hijos[cnt]==salida_lectura);
			cout << salida_lectura << " ";
			cnt+=1;
		}
		cout << endl;
    }
	return 0;

}

