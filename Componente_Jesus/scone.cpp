#include "hls_stream.h"
#include "ap_int.h"
#include "scone.h"
#include <ctype.h>
#include <string.h>

//static ap_uint<8> marks[N_NODES];

//void scone_engine(cmd_scone_t entry, scone_ops op, hls::stream<node_t> &path) {
void scone_engine(cmd_scone_t entry, scone_ops op, hls::stream<node_t> &path,ap_uint<8> marks[N_NODES]) {
#pragma HLS INTERFACE s_axilite register port=entry bundle=CONTROL_BUS
#pragma HLS INTERFACE s_axilite register port=return bundle=CONTROL_BUS
#pragma HLS INTERFACE s_axilite register port=op bundle=CONTROL_BUS
	static unsigned short count = 0;
#pragma HLS RESET variable=count off

//static ap_uint<8> marks[N_NODES];
//#pragma HLS RESET variable=marks off


	static hls::stream<node_t> in1;
#pragma HLS RESET variable=in1 off
#pragma HLS STREAM variable=in1 depth=1024
	switch (op) {
	case UPSCAN:  // Upscan operation
	{
		scan(entry,false,true,count,marks,in1);
#ifndef __SYNTHESIS__
		std::cout << "Se han escrito los siguientes nodos en UPSCAN: " << std::endl;
		for (int i = 0; i < N_NODES;i++) if (marks[i].test(count)) std::cout << "El nodo " << i+1 << " tiene la marca " << count << " en posicion " << marks[i][count] << std::endl;
#endif
		for (int i = 0; i < N_NODES;i++) if (marks[i].test(count)) path.write(i+1);
		break;

	}

	case DOWNSCAN : // Downscan operation
	{
		scan(entry,false,false,count,marks,in1);
#ifndef __SYNTHESIS__
		std::cout << "Se han escrito los siguientes nodos en DOWNSCAN: " << std::endl;
		for (int i = 0; i < N_NODES;i++) if (marks[i].test(count)) std::cout << "El nodo " << i+1 << " tiene la marca " << count << " en posicion " << marks[i][count] << std::endl;
#endif
		for (int i = 0; i < N_NODES;i++) if (marks[i].test(count)) path.write(i+1);

		break;
	}
	case PROPAGATE :  // Propagate marked nodes with cmd_scone_t relation and mark them
	{
	propagate_loop:	for (int i = 0; i < N_NODES;i+=2) {
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
		std::cout << "Se han escrito los siguientes nodos en PROPAGATE: " << std::endl;
		for (int i = 0; i < N_NODES;i++) if (marks[i].test(count)) std::cout << "El nodo " << i+1 << " tiene la marca " << count << " en posicion " << marks[i][count] << std::endl;
#endif
		for (int i = 0; i < N_NODES;i++) if (marks[i].test(count)) path.write(i+1);
		break;
	}
	case INTERSECTION : // Intersection: Which marks?
	{
	 intersection_loop:	for (int i = 0; i < N_NODES; i++) {
#pragma HLS PIPELINE
			//if (marks[i] == entry) 				path.write(i+1);

				path.write(marks[i]);
	}
		break;
	}
	case CLEAR :  // Clear the marks
		count = 0;
	clear_loop: for (int i = 0; i < N_NODES; i++) {
#pragma HLS PIPELINE
		marks[i] = ap_uint<8>(0);


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
		rel_t rel =  word(1,0);
		node_t nodo = WORD_NODE(word), salida;
		busqueda_cam(nodo, rel, upOrDown, in1);
		internal_fifo_scan_loop: while (!in1.empty()) {
		#pragma HLS PIPELINE
				salida = in1.read();
				if (salida != EOT) {
					if (!propagate) busqueda_cam(salida, rel, upOrDown, in1);
					marks[salida-1].set(count);
//					ap_uint<8> val = marks[salida-1];
//					val(count,count) = 1;
//					marks[salida-1] = val;
				}
			}
			if (!propagate) {
				marks[nodo-1].set(count);
//				ap_uint<8> val = marks[nodo-1];
//									val(count,count) = 1;
//						marks[nodo-1] = val;
			}
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
