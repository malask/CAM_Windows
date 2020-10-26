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
	unsigned int cnt;
	extern int results_parents[];
	extern int results_childrens[][3];
	extern int selected[];
	extern int n_hijos[];
	extern edge_t bfstree[];


	node_t salida_lectura;
	int prueba = 0;
	rel_t rel = 0;
	bool buscarPadre = true;
	hls::stream<node_t> salida_hw_1("CANAL_RESULTADO_1");
	hls::stream<node_t> salida_hw_2("CANAL_RESULTADO_2");
	std::vector<node_t> hijos;

	extern edge_t bfstree_2_1[];
	extern edge_t bfstree_2_2[];


	for (unsigned int i = 0; i < TREE_SIZE/4; i++) {
		prueba = selected[i];
		top_function(bfstree_2_1,bfstree_2_2,prueba,rel,buscarPadre,salida_hw_1);
		cout << "---- Comprobacion de que los canales no est�n vacios ----" << endl;
		assert(salida_hw_1.empty()==false);
		//assert(salida_hw_2.empty()==false);
		cout << "---- Los canales no estan vacios. Pasamos a lectura de valores ---- " << endl;
		cout << " ---- Caso de prueba: " << prueba << " ---- " << std::endl;

		while (!salida_hw_1.empty()){
			salida_lectura = salida_hw_1.read();
			cout << "Leido en 1: " << salida_lectura << endl;
			hijos.push_back(salida_lectura);
		}
		/*while (!salida_hw_2.empty()){
			salida_lectura = salida_hw_2.read();
			cout << "leido en 2: " << salida_lectura << endl;
			hijos.push_back(salida_lectura);
		} */
		if (results_parents[i] == EOT) {
			while (!hijos.empty()) {
				salida_lectura = hijos.back();
				hijos.pop_back();
				assert(salida_lectura==EOT);
				assert(salida_lectura == results_parents[i]);
			}
		}else {
			while(!hijos.empty()) {
				salida_lectura = hijos.back();
				hijos.pop_back();
				if (salida_lectura != EOT){
					cout << "---- Comprobando que " << salida_lectura << " es igual a " << results_parents[i] << endl;
					assert(salida_lectura == results_parents[i]);
					cout << "---- Comprobaci�n correcta, pasando al siguiente caso ---- " << endl;
				}

			}
		}
	}


	buscarPadre = false;
	int cont_hij = 0;
	for (unsigned int i = 0; i< TREE_SIZE/4 ;i++) {
		prueba = selected[i];
		top_function(bfstree_2_1,bfstree_2_2,prueba,rel,buscarPadre,salida_hw_1);
		cout << "---- Comprobacion de que los canales no est�n vacios ----" << endl;
		assert(salida_hw_1.empty()==false);
		//assert(salida_hw_2.empty()==false);
		cout << "---- Los canales no estan vacios. Pasamos a lectura de valores ---- " << endl;
		cout << " ---- Caso de prueba: " << prueba << " ---- " << std::endl;
		while (!salida_hw_1.empty()) hijos.push_back(salida_hw_1.read());
		//while (!salida_hw_2.empty()) hijos.push_back(salida_hw_2.read());
		stable_sort(hijos.begin(), hijos.end());

		if (results_childrens[cont_hij] == EOT) {
			while (!hijos.empty()) {
				salida_lectura = hijos.back();
				hijos.pop_back();
				assert(salida_lectura == EOT);
				assert(salida_lectura==results_childrens[0]);
			}
		} else {
			int index_hijos = 0;
			while(!hijos.empty()){
				salida_lectura = hijos.front();
				hijos.erase(hijos.begin());
				if (salida_lectura != EOT) {
					cout << " --- Comprobando que " << salida_lectura << " es " << results_childrens[i][index_hijos] << " ---- " << endl;
					assert(salida_lectura==results_childrens[i][index_hijos]);
					assert(salida_lectura != EOT);
					index_hijos+=1;
			}
		}
			assert(index_hijos == n_hijos[i]);
			cout << endl;
	}
}
*/
	return 0;

}

