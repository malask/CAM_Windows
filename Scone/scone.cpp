#include "hls_stream.h"
#include "ap_int.h"
#include "scone.h"
#include <ctype.h>
#include <string.h>




void top_function(cmd_scone_t entry, Scone_Ops::Op_scone op, hls::stream<node_t> &path) {
	static unsigned short count;
#pragma HLS reset variable=count
	static ap_uint<8> marks[N_NODES];
#pragma HLS reset variable=marks
#pragma HLS RESOURCE variable=marks core=RAM_2P_URAM
	static hls::stream<node_t> in1;
		#pragma HLS STREAM variable=in1 depth=1024
	switch (op) {
	case Scone_Ops::Upscan : // Upscan operation
	{
		scan(entry,false,true,count,marks,in1);
#ifndef __SYNTHESIS__
		std::cout << "Se han escrito los siguientes nodos en esta operacion: " << std::endl;
		for (int i = 0; i < N_NODES;i++) if (marks[i].test(count)) std::cout << "El nodo " << i+1 << " tiene la marca " << count << " en posicion " << marks[i][count] << std::endl;
#endif
		break;

	}

	case Scone_Ops::Downscan : // Downscan operation
	{
		scan(entry,false,false,count,marks,in1);
#ifndef __SYNTHESIS__
		std::cout << "Se han escrito los siguientes nodos en esta operacion: " << std::endl;
		for (int i = 0; i < N_NODES;i++) if (marks[i].test(count)) std::cout << "El nodo " << i+1 << " tiene la marca " << count << " en posicion " << marks[i][count] << std::endl;
#endif
		break;
	}
	case Scone_Ops::Propagate :  // Propagate marked nodes with cmd_scone_t relation and mark them
	{
		for (int i = 0; i < N_NODES;i+=2) {
#pragma HLS PIPELINE
			if (marks[i].test(count-1)){
				cmd_scone_t tmp = (i+1,entry(1,0));
				scan(tmp,true,true,count,marks,in1);
			}
			if (marks[i+1].test(count-1)) {
				cmd_scone_t tmp = (i+2,entry(1,0));
				scan(tmp,true,true,count, marks,in1);
			}
		}

#ifndef __SYNTHESIS__
		std::cout << "Se han escrito los siguientes nodos en esta operacion: " << std::endl;
		for (int i = 0; i < N_NODES;i++) if (marks[i].test(count)) std::cout << "El nodo " << i+1 << " tiene la marca " << count << " en posicion " << marks[i][count] << std::endl;
#endif
		break;
	}
	case Scone_Ops::Intersection : // Intersection: Which marks?
	{
		for (int i = 0; i < N_NODES; i++) {
#pragma HLS PIPELINE
/*#ifndef __SYNTHESIS__
		for (int i = 0; i < N_NODES;i++) std::cout << "El nodo " << i+1 << " tiene el valor " << marks[i] << std::endl;
#endif */
			if (marks[i] == entry) path.write(i+1);
	}
		break;
	}
	case Scone_Ops::Clear :  // Clear the marks
		count = 0;
	for (int i = 0; i < N_NODES; i++) {
#pragma HLS PIPELINE
		marks[i] = 0;


	}
		break;
	default:
	{
		return;
		break;
	}

	}
	count+=1;
	path.write(EOT);
	return;
}
void scan(cmd_scone_t word,bool propagate, bool upOrDown, unsigned short &count, ap_uint<8> marks[TREE_SIZE], hls::stream<node_t> &in1) {
		rel_t rel =  word(2,0);
		node_t nodo = WORD_NODE(word), salida;
		busqueda_cam(nodo, rel, upOrDown, in1);
		while (!in1.empty()) {
		#pragma HLS PIPELINE
				salida = in1.read();
				if (salida != EOT) {
					if (!propagate) busqueda_cam(salida, rel, upOrDown, in1);
					marks[salida-1][count] = 1;
				}
			}
			if (!propagate) marks[nodo-1][count] = 1;
		return;
	}
/*void propagate(cmd_scone_t word, unsigned short &count, ap_uint<8> marks[TREE_SIZE], hls::stream<node_t> &in1) {
	rel_t rel = word(1,0);
	node_t nodo = WORD_NODE(word), salida;
	busqueda_cam(nodo,rel,true,in1);
	while(!in1.empty()) {
#pragma HLS PIPELINE
		salida = in1.read();
		if (salida != EOT) marks[salida-1][count] = 1;
	}
}
 */
