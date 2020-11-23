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



	node_t salida_lectura;
	int prueba = 0;
	rel_t rel = 0;
	bool buscarPadre = true;
	hls::stream<node_t> salida_hw_1("CANAL_RESULTADO_1");
	hls::stream<node_t> salida_hw_2("CANAL_RESULTADO_2");
	std::vector<node_t> hijos;
	extern int selected[];
	extern int results_parents[];
	extern int results_childrens[][3];
	extern int n_hijos[];
	extern edge_t bfstree[];

	for (unsigned int i = 0; i < TREE_SIZE/4; i++) {
		prueba = selected[i];
		top_function(prueba,rel,buscarPadre,salida_hw_1);
		cout << "---- Comprobacion de que los canales no están vacios ----" << endl;
		assert(salida_hw_1.empty()==false);
		cout << "---- Los canales no estan vacios. Pasamos a lectura de valores ---- " << endl;
		cout << " ---- Caso de prueba: " << prueba << " ---- " << std::endl;

		while (!salida_hw_1.empty()){
			salida_lectura = salida_hw_1.read();
			cout << "Leido en 1: " << salida_lectura << endl;
			hijos.push_back(salida_lectura);
		}

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
					cout << "---- Comprobación correcta, pasando al siguiente caso ---- " << endl;
				}


			}
		}
	}


	buscarPadre = false;
	int cont_hij = 0;
	for (unsigned int i = 0; i< TREE_SIZE/4 ;i++) {
		prueba = selected[i];
		top_function(prueba,rel,buscarPadre,salida_hw_1);
		assert(salida_hw_1.empty()==false);
		cout << " ---- Caso de prueba: " << prueba << " ---- " << std::endl;
		while (!salida_hw_1.empty()) hijos.push_back(salida_hw_1.read());
		stable_sort(hijos.begin(), hijos.end());

		if (results_childrens[i][0] == EOT) {
			while (!hijos.empty()) {
				salida_lectura = hijos.back();
				cout << "Salida: " << salida_lectura << " ";
				hijos.pop_back();
				assert(salida_lectura == EOT);
				assert(salida_lectura==results_childrens[i][0]);
			}
		} else {
			short index_hijos = 0;
			while(!hijos.empty()){
				salida_lectura = hijos.front();
				cout << "Salida: " << salida_lectura << " ";
				hijos.erase(hijos.begin());
				if (salida_lectura != EOT) {
				assert(salida_lectura==results_childrens[i][index_hijos]);
				assert(salida_lectura != EOT);
				index_hijos+=1;

			}
		}
			cout << endl;
	}
}


	return 0;

}

