#include "cam.h"
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
	hls::stream<node_t> salida_hw;
	word_t prueba = 48;
	//top_function(prueba,op,salida_hw);
	word_t tmp;
	tmp = ((12 & 0xFFFF) << 2 | (0 &0xFF)); // DUMBO
	top_function(tmp,'u',salida_hw);
	assert(salida_hw.empty()==false);
node_t salida;
salida = salida_hw.read();
	top_function(tmp,'i',salida_hw);
salida = salida_hw.read();
tmp = ((4 & 0xFFFF) << 2 | (0 &0xFF));
top_function(tmp,'d',salida_hw);

	cout << "Salida: "  << salida << endl;
	return 0;

}

