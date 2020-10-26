#include "cam.h"
#include <stdio.h>
#include <hls_stream.h>
#include <iostream>
#include <fstream>
//#include "data_128.c"

using namespace std;

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
/*

	for (unsigned int i = 0; i < TREE_SIZE/4; i++) {
		prueba = selected[i];
		top_function(prueba,rel,buscarPadre,salida_hw);
		cout << "El padre del nodo " << prueba << "es " << results_parents[i] << std::endl;

		cout << "Ha salido: ";
		if (salida_hw.empty()) {
					std::cout<< " ---- No nodes detected for this case. Try again ---- " << prueba << " ---- " <<std::endl;

				} else {
						while(!salida_hw.empty()){
							salida_lectura = salida_hw.read();
							cout << salida_lectura << " " ;

							if (results_parents[i] == EOT) {
								assert(salida_lectura == results_parents[i]);

							}
							else {
								if (salida_lectura != EOT) {
									assert(salida_lectura == results_parents[i]);
								}
							}
						}
						cout << endl;
				}
	}
	*/
	buscarPadre = false;
	int cont_hij = 0;
	for (unsigned int i = 0; i< TREE_SIZE/4 ;i++) {
		prueba = selected[i];
		bool flag = false;
		top_function(prueba,rel,buscarPadre,salida_hw);
		cout << "Los hijos del nodo " << prueba << " son: " ;
		if (results_childrens[cont_hij] == EOT) {
			salida_lectura = salida_hw.read();
			assert(salida_lectura == results_childrens[cont_hij]);
			cout << "Ninguno! " << endl;
			assert(salida_hw.empty()==true);
			cont_hij+=1;
		} else {

			while(!salida_hw.empty()){
				salida_lectura = salida_hw.read();
				if (salida_lectura != EOT) {
					//assert(salida_lectura==results_childrens[cont_hij]);
					cout << salida_lectura << " " ;
					cont_hij+=1;
					flag = true;
			} else {
					assert(flag==true);
			}
		}
			cout << endl;
	}
}
std::cout << "Numero de hijos contados es : " << cont_hij;
	return 0;

}

