#include "cam.h"
#include <stdio.h>
#include <hls_stream.h>
#include <iostream>
#include <fstream>

using namespace std;

int printResult(hls::stream<node_t> &salida_hw, bool fatherOrChild, unsigned int prueba){
	node_t salida_lectura;
	if (salida_hw.empty()) {
			std::cout<< " ---- Failed test. Check test or CAM solution for node == " << prueba << " ---- " <<std::endl;
			return -1;
		} else {
			if (fatherOrChild) std::cout << "Node " << prueba << " 's father is:  " << std::endl;
			else std::cout << "Node " << prueba << " 's children is/are: " << std::endl;
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

int main () {
	ifstream infile;
	string line;
	unsigned int cnt;
	edge_t tree[TREE_SIZE] = 0;
	//edge_t tree2[TREE_SIZE];

	srand((unsigned)time(0));


	node_t salida_lectura, prueba_mejor, prueba_peor, prueba_mitad = 0;
	edge_t lectura_mejor, lectura_peor, lectura_mitad=0;
	rel_t rel = 0;


	hls::stream<node_t> salida_hw;

	//Leer el arbol del fichero
	//infile.open(TREE_FILE,ios::in);
	infile.open(TREE_FILE, ios::in);
	if (!infile.is_open()) {
		cout << "Archivo con los datos del ï¿½rbol no abierto" << endl;
	}
	cout << "FICHERO DE ENTRADA CON NUMERO DE DATOS " << TREE_SIZE << " BUSQUEDA " << SEARCH_MODE <<  endl;
	cnt = 0;
	while (getline(infile,line)) {
		//cout << cnt << " Arco leido: " << line << endl;
		tree[cnt++] = stoul(line);
	}

	/*for (unsigned int idx = 0; idx < TREE_SIZE; idx++) {
			cout << "Leï¿½do: "<< idx << " " << tree[idx].to_uint() << endl;
			cout << "Nodo SRC (PADRE) " << SRC_NODE(tree[idx]).to_uint() << endl;
			cout << "Nodo DST (HIJO)" << DST_NODE(tree[idx]).to_uint() << endl;

		}*/


	bool buscarPadre = true;
	lectura_peor = tree[cnt-1];
	lectura_mejor = tree[0];
	unsigned int mitad = (cnt-1)/2;
	lectura_mitad = tree[mitad];
	unsigned int prueba = DST_NODE(lectura_peor).to_uint();

	std::cout << "---- Testing nº of access for worst case (i = N) ---- " << std::endl;
	cam_top(tree,prueba,rel,true,salida_hw);
	printResult(salida_hw,true,prueba);
	std::cout << "---- Finalized test for worst case ---- " << std::endl;
	std::cout <<" " << std::endl;


	std::cout << "---- Testing nº of access for best case (i = 1) ---- " << std::endl;
	prueba = DST_NODE(lectura_mejor).to_uint();
	cam_top(tree,&tree[TREE_SIZE/2],prueba,rel,true,salida_hw);
	printResult(salida_hw,true,prueba);
	std::cout << "---- Finalized test for best case ---- ";
	std::cout <<" " << std::endl;

	std::cout << "---- Testing nº of access for promedium case (i = N/2)" << std::endl;
	prueba = DST_NODE(lectura_mitad).to_uint();
	cam_top(tree,&tree[TREE_SIZE/2], prueba,rel,true,salida_hw);
	printResult(salida_hw,true,prueba);
	std::cout << "---- Finalized test por promedium case ---- " << std::endl;


	return 0;
}
