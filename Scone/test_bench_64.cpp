#include "scone.h"
#include <stdio.h>
#include <hls_stream.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctype.h>

using namespace std;


int main () {
	ifstream infile;
	string line;
	unsigned int cnt = 0;
	extern edge_t bfstree[];
	hls::stream<node_t> salida_hw;
	cmd_scone_t prueba = 216;

	top_function(prueba,1,salida_hw);
	assert(salida_hw.empty()==false);
node_t salida;
salida = salida_hw.read();


	top_function(1,3,salida_hw);
salida = salida_hw.read();

node_t node = 4;
rel_t rel = 0;
prueba = (node,rel);
top_function(prueba,2,salida_hw);
salida = salida_hw.read();
top_function(6,4, salida_hw);
while (!salida_hw.empty()){
	salida = salida_hw.read();
	cout << "Salida: "  << salida << endl;

}

top_function(1,0,salida_hw);
salida = salida_hw.read();

	return 0;

}

