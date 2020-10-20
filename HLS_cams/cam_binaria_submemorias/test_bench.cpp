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
	extern int results_parents[];
	extern int results_childrens[];
	extern int selected[];
	extern edge_t bfstree[];


	node_t salida_lectura;
	int prueba = 0;
	int j = 0;
	rel_t rel = 0;
	bool buscarPadre = true;
	hls::stream<node_t> salida_hw("CANAL_RESULTADO");


	for (unsigned int i = 0; i < TREE_SIZE/4; i++,j++) {
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

							if (results_parents[i] == EOT && prueba == 1) {
								assert(salida_lectura == results_parents[i]);
							}
							else  {
								if (salida_lectura != EOT) {
									assert(salida_lectura == results_parents[i]);
								}
							}
						}
						cout << endl;
				}
	}

	buscarPadre = false;
	int cont_hij = 0, n_hijos_real = 0;
	int contador_hijos_hw=0;
	extern int n_hijos[];
	for (int i = 0; i < TREE_SIZE/4; i++,j++) {
		prueba = selected[i];
		n_hijos_real = n_hijos[i];
		top_function(prueba,rel,buscarPadre,salida_hw);
		cout << "Los hijos del nodo " << prueba << " son: ";
		if (results_childrens[cont_hij] == EOT) {
			salida_lectura = salida_hw.read();
			cout << results_childrens[cont_hij] << " y ha salido " << salida_lectura << std::endl;
			assert(results_childrens[cont_hij] == salida_lectura); // Verificamos que EOT es igual al numero de hijos del caso
			cont_hij +=1;
			assert(salida_hw.empty() == true); // Si no hay hijo, en cuanto recibamos EOT el canal_hw debe de quedar vacio
		}
		else {
			cout << "Ha salido " ;
			contador_hijos_hw = 0;
			while (!salida_hw.empty()) {
				salida_lectura = salida_hw.read();
				if (salida_lectura == EOT) cout << "FIN DE LA SALIDA" << std::endl;
				else{
					cout << "Salida de la cam: " << salida_lectura << std::endl;
					cout << "El valor en los resultados es : " << results_childrens[cont_hij] << std::endl;
					contador_hijos_hw +=1;
				cont_hij+=1;
				}

			}
			assert(contador_hijos_hw == n_hijos_real);

		}
	}
	std::cout << "El numero de hijos contado es: " << cont_hij << std::endl;



	return 0;

}

