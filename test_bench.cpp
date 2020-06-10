#include "cam.h"
#include "stdio.h"
#include "hls_stream.h"



#define TREE_SIZE 1024


int main (int argc, char *argv[]) {
	ap_uint<10> arbol[TREE_SIZE];
	ap_uint<10> salida_lectura, prueba =0;
	hls::stream<ap_uint<10>> salida_hw;
	std::fill(arbol, arbol+TREE_SIZE,0);
	/*for(int i=0;i<TREE_SIZE;i++){
		std::cout<< i+1 << " value: " << arbol[i] << "\n";
	} Checkeado que esta todo el árbol a 0, lo que significa que esta vacio */

	arbol[0]=442; // 0110 0000 10
	/*arbol[1]=26;
	arbol[2]=8;
	arbol[3]=11;
	arbol[4]=180; */
	prueba = arbol[0](5,2);
	//Con (1,0) coge los dos bits mas pequeños


	/*busqueda_cam(arbol, 6,1,true,&salida_hw);
	salida_hw.read(salida_lectura);
	if ((salida_hw.read(salida_lectura))==false) salida_lectura = 0;

	if (salida_lectura==0) {
		std::cout<< "Failed test. Check test or CAM solution";
	} else {
		std::cout << salida_lectura<< " Test successful at the moment!! Exiting";
	}
	*/
	std::cout << "El valor de esto es " << prueba ;
	return 0;
}
