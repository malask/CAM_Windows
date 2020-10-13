#include "cam.h"
#include <stdio.h>
#include <hls_stream.h>
#include <iostream>
#include <fstream>

using namespace std;



int printResult(hls::stream<node_t> &salida_hw, bool fatherOrChild, unsigned int prueba){
	node_t salida_lectura;
	if (salida_hw.empty()) {
			std::cout<< " ---- No nodes detected for this case. Try again ---- " << prueba << " ---- " <<std::endl;
			return -1;
		} else {
			if (fatherOrChild){ std::cout << "Node " << prueba << " 's father is:  " << std::endl;
			}else std::cout << "Node " << prueba << " 's children is/are: " << std::endl;
				while(!salida_hw.empty()){
					salida_lectura = salida_hw.read();
					if (salida_lectura == EOT) {
						std::cout << "SEARCH ENDED" << std::endl;
					}else std::cout << salida_lectura << std::endl;
				}
				std::cout << "---- Test succesful at the moment! ----" << std::endl;
		}
	return 0;
}

int main (int argc, char *argv[]) {
	ifstream infile;
	string line;
	unsigned int cnt;
	edge_t tree[TREE_SIZE];
	srand((unsigned)time(0));


	node_t salida_lectura, prueba = 0;
	rel_t rel = 0;


	hls::stream<node_t> salida_hw("CANAL_RESULTADO");

	//Leer el arbol del fichero
	//infile.open(TREE_FILE,ios::in);
	infile.open(TREE_FILE, ios::in);
	if (!infile.is_open()) {
		cout << "Archivo con los datos del árbol no abierto" << endl;
	}
	cout << "FICHERO DE ENTRADA CON NUMERO DE DATOS " << TREE_SIZE << " BUSQUEDA " << SEARCH_MODE <<  endl;
	cnt = 0;
	while (getline(infile,line)) {
		 cout << cnt << " Arco leído: " << line << endl;
		tree[cnt++] = stoul(line);
	}

	fillHashTables(tree);


	bool buscarPadre = true;
	std::cout << "---- CASE TESTING FOR PARENT CASES ---- " << std::endl;
	std::cout << "---- Testing nº of access for worst case (i = N) ---- " << std::endl;

	prueba = TREE_SIZE-1;

	//top_function(tree,&tree[TREE_SIZE/2],prueba,rel,buscarPadre,salida_hw);
	top_function(tree,prueba,rel,buscarPadre,salida_hw);
	printResult(salida_hw,true,prueba);
	std::cout << "---- Finalized test for worst case ---- " << std::endl;
	std::cout <<" " << std::endl;


	std::cout << "---- Testing nº of access for best case (i = 1) ---- " << std::endl;
	prueba = 2;
	top_function(tree,prueba,rel,buscarPadre,salida_hw);
	printResult(salida_hw,true,prueba);
	std::cout << "---- Finalized test for best case ---- " << std::endl;
	std::cout <<" " << std::endl;


	std::cout << "---- Testing nº of access for promedium case (i = N/2)" << std::endl;
	prueba = TREE_SIZE/2;
	top_function(tree,prueba,rel,buscarPadre,salida_hw);
	printResult(salida_hw,true,prueba);

	std::cout << "---- Finalized test for promedium case ---- " << std::endl;

	std::cout << "---- Finalized test for PARENT cases. Starting CHILDREN cases----" << std::endl;

	std::cout << "---- CASE TESTING FOR CHILDREN CASES ---- " << std::endl;
	buscarPadre = false;
		std::cout << "---- Testing nº of access for worst case (i = N). ---- " << std::endl;

		prueba = TREE_SIZE-1;

		top_function(tree,prueba,rel,buscarPadre,salida_hw);
		printResult(salida_hw,false,prueba);
		std::cout << "---- Finalized test for worst case ---- " << std::endl;
		std::cout <<" " << std::endl;


		std::cout << "---- Testing nº of access for best case (i = 1) ---- " << std::endl;
		prueba = 1;
		top_function(tree,prueba,rel,buscarPadre,salida_hw);
		printResult(salida_hw,false,prueba);
		std::cout << "---- Finalized test for best case ---- " << std::endl;
		std::cout <<" " << std::endl;


		std::cout << "---- Testing nº of access for promedium case (i = N/2)" << std::endl;
		prueba = TREE_SIZE/2;
		top_function(tree,prueba,rel,buscarPadre,salida_hw);
		printResult(salida_hw,false,prueba);
	std::cout <<" " << std::endl;

	return 0;

}

