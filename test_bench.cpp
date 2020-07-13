#include "cam.h"
#include <stdio.h>
#include <hls_stream.h>
#include <iostream>
#include <fstream>

using namespace std;


int main (int argc, char *argv[]) {
	ifstream infile;
	string line;
	unsigned int cnt;
	srand((unsigned)time(0));

	edge_t arbol[TREE_SIZE];
	node_t salida_lectura, prueba = 0;
	rel_t rel = 0;


	hls::stream<node_t> salida_hw;

	//Leer el arbol del fichero
	//infile.open(TREE_FILE,ios::in);
	infile.open(TREE_FILE, ios::in);
	if (!infile.is_open()) {
		cout << "Archivo con los datos del árbol no abierto" << endl;
	}
	cout << "FICHERO DE ENTRADA CON NUMERO DE DATOS " << TREE_SIZE << " BUSQUEDA " << SEARCH_MODE <<  endl;
	cnt = 0;
	while (getline(infile,line)) {
		// cout << cnt << " Arco leído: " << line << endl; Sabemos que funciona correctamente.
		arbol[cnt++] = stoul(line);
	}
	bool buscarPadre = false;

	/*for (unsigned int idx = 0; idx < TREE_SIZE; idx++) {
		cout << "Leído: " << arbol[idx].to_uint() << endl;
		cout << "Nodo SRC (PADRE) " << SRC_NODE(arbol[idx]).to_uint() << endl;
		cout << "Nodo DST (HIJO)" << DST_NODE(arbol[idx]).to_uint() << endl;

	} El metodo de leer el árbol sabemos que funciona correctamente. */
	prueba= (rand() % TREE_SIZE-2)+2;

	// leer el padre de un nodo busqueda_cam(arbol,192,rel,true,&salida_hw);
	busqueda_cam(arbol,prueba,rel,buscarPadre,&salida_hw);
	//if ((salida_hw.read(salida_lectura))==false) salida_lectura = 0;

	if (salida_hw.empty()) {
		std::cout<< "Failed test. Check test or CAM solution for node == " << prueba << std::endl;
	} else {
		if (buscarPadre) std::cout << "El padre del nodo " << prueba << " es: " << std::endl;
		else std::cout << "El/Los hijo(s) del nodo " << prueba << " es/son: " << std::endl;
			while(!salida_hw.empty()){
				salida_lectura = salida_hw.read();
				if (salida_lectura > TREE_SIZE) {
					std::cout << "No se ha encontrado ningún nodo compatible. Seguramente no tenga padre/hijos" << std::endl;
					break;
				}
				std::cout << salida_lectura << std::endl;
			}
			std::cout << "Test succesful at the moment!" << std::endl;
	}

	return 0;
}
