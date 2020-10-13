#include "cam.h"
#include <stdio.h>
#include <hls_stream.h>
#include <iostream>
#include <fstream>
//#include "data_128.c"

using namespace std;



int printResult(hls::stream<node_t> &salida_hw, bool fatherOrChild, unsigned int prueba){
	node_t salida_lectura;
	if (salida_hw.empty()) {
			std::cout<< " ---- No nodes detected for this case. Try again ---- " << prueba << " ---- " <<std::endl;

		} else {
			if (fatherOrChild){ std::cout << "Node " << prueba << " 's father is:  " << std::endl;
			}else std::cout << "Node " << prueba << " 's children is/are: " << std::endl;
				while(!salida_hw.empty()){
					salida_lectura = salida_hw.read();
					if (salida_lectura == EOT && prueba != 1){
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
	extern int results_parents[];
	extern int results_childrens[];
	extern int selected[];
	extern edge_t bfstree[];


	node_t salida_lectura;
	int prueba = 0;
	rel_t rel = 0;
	bool buscarPadre = true;
	hls::stream<node_t> salida_hw("CANAL_RESULTADO");

	for (unsigned int i = 0; i < TREE_SIZE/4; i++) {
		prueba = selected[i];
		top_function(prueba,rel,buscarPadre,salida_hw);
		if (salida_hw.empty()) {
					std::cout<< " ---- No nodes detected for this case. Try again ---- " << prueba << " ---- " <<std::endl;

				} else {
					//if (buscarPadre){ std::cout << "Node " << prueba << " 's father is:  " << std::endl;
					//}else std::cout << "Node " << prueba << " 's children is/are: " << std::endl;
						while(!salida_hw.empty()){
							salida_lectura = salida_hw.read();
							if (salida_lectura == EOT && prueba != 1){
							//	std::cout << "SEARCH ENDED" << std::endl;
							}else{
								assert(salida_lectura==results_parents[i]);


							}
						}
				}
	}
	buscarPadre = false;
	for (unsigned int i = 0; i< TREE_SIZE/4 ;i++) {
		prueba = selected[i];
		int hijos = 0;
		top_function(prueba,rel,buscarPadre,salida_hw);
		if (salida_hw.empty()) {
			std::cout<<" --- No nodes detected for this case. Try again ---- " << prueba << " ---- " << std::endl;

		} else  {
			if (buscarPadre){std::cout << "Node " << prueba << " 's father is:  " << std::endl;
			}else std::cout << "Node " << prueba << " 's children is/are: " << std::endl;
			while (!salida_hw.empty()) {
				salida_lectura = salida_hw.read();
				hijos += salida_lectura;
				}
			}
			assert(hijos==results_childrens[i]);
	}

	return 0;

}

