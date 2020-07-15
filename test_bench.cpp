#include "cam.h"
#include <stdio.h>
#include <hls_stream.h>
#include <iostream>
#include <fstream>

using namespace std;


int main () {
	ifstream infile;
	string line;
	unsigned int cnt;
	edge_t tree[TREE_SIZE] = 0;
	//edge_t tree2[TREE_SIZE];

	srand((unsigned)time(0));


	node_t salida_lectura, prueba = 0;
	rel_t rel = 0;


	hls::stream<node_t> salida_hw;

	//Leer el arbol del fichero
	//infile.open(TREE_FILE,ios::in);
	infile.open(TREE_FILE, ios::in);
	if (!infile.is_open()) {
		cout << "Archivo con los datos del �rbol no abierto" << endl;
	}
	cout << "FICHERO DE ENTRADA CON NUMERO DE DATOS " << TREE_SIZE << " BUSQUEDA " << SEARCH_MODE <<  endl;
	cnt = 0;
	while (getline(infile,line)) {
		cout << cnt << " Arco leido: " << line << endl;
		tree[cnt++] = stoul(line);
	//	tree2[cnt++] = stoul(line);

	}
	bool buscarPadre = true;

	/*for (unsigned int idx = 0; idx < TREE_SIZE; idx++) {
		cout << "Le�do: " << tree[idx].to_uint() << endl;
		cout << "Nodo SRC (PADRE) " << SRC_NODE(tree[idx]).to_uint() << endl;
		cout << "Nodo DST (HIJO)" << DST_NODE(tree[idx]).to_uint() << endl;

	}*/
	//prueba= (rand() % TREE_SIZE-2)+2;
	prueba = 692;
	// leer el padre de un nodo busqueda_cam(arbol,192,rel,true,&salida_hw);
	cam_top(tree,&tree[TREE_SIZE/2],prueba,rel,buscarPadre,salida_hw);
	//if ((salida_hw.read(salida_lectura))==false) salida_lectura = 0;

	if (salida_hw.empty()) {
		std::cout<< "Failed test. Check test or CAM solution for node == " << prueba << std::endl;
	} else {
		if (buscarPadre) std::cout << "El padre del nodo " << prueba << " es: " << std::endl;
		else std::cout << "El/Los hijo(s) del nodo " << prueba << " es/son: " << std::endl;
			while(!salida_hw.empty()){
				salida_lectura = salida_hw.read();
				std::cout << salida_lectura.to_uint() << std::endl;

				if (salida_lectura == EOT) {
					std::cout << "FIN DE LA B�SQUEDA" << std::endl;

				}
			}
			std::cout << "Test succesful at the moment!" << std::endl;
	}
	cam_top(tree,&tree[TREE_SIZE/2],51,rel,false,salida_hw);
	if (salida_hw.empty()) {
		std::cout<< "Failed test. Check test or CAM solution for node == " << prueba << std::endl;
	} else {
		 std::cout << "El/Los hijo(s) del nodo " << prueba << " es/son: " << std::endl;
			while(!salida_hw.empty()){
				salida_lectura = salida_hw.read();
				std::cout << salida_lectura.to_uint() << std::endl;

				if (salida_lectura == EOT) {
					std::cout << "FIN DE LA B�SQUEDA" << std::endl;

				}
			}
			std::cout << "Test succesful at the moment!" << std::endl;
	}
	return 0;
}
