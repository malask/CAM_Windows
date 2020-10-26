#include "hls_stream.h"
#include "ap_int.h"
#include "cam.h"


void top_function (node_t nodo, rel_t relationship, bool fatherSearch, hls::stream<node_t> &result) {
	static hls::stream<node_t> in1;
#pragma HLS STREAM variable=in1 depth=8 dim=1
	static hls::stream<node_t> in2;
#pragma HLS STREAM variable=in2 depth=8 dim=1

#pragma HLS DATAFLOW
		busqueda_cam(nodo,relationship,fatherSearch,in1,in2);
		combinar(in1,in2,result);
}

 void busqueda_cam (node_t nodo, rel_t relationship, bool fatherSearch, hls::stream<node_t> &result1, hls::stream<node_t> &result2) {
	 if (fatherSearch && nodo == 1) {
	 		result1.write(EOT);
	 		result2.write(EOT);
	 		return;
	 	}
	 extern short BUCKET_INDEX_BFS[];
	short min_limit=0;
	short bucket = (nodo/(TREE_SIZE/NUM_BUCKETS));
	if (bucket == NUM_BUCKETS) bucket -=1;
	min_limit = BUCKET_INDEX_BFS[bucket];

	extern edge_t bfstree[];

	ap_uint<EDGE_BITS> valor = 0;
	ap_uint<EDGE_BITS> valor2 = 0;
	ap_uint<REL_BITS> node_relation =0;
	bool flag = false;
	ap_uint<NODE_BITS> compare_node_min=0;
	ap_uint<NODE_BITS> compare_node_max=0;
	short max_limit = 0;
	if (bucket >= NUM_BUCKETS-1) max_limit = TREE_SIZE;
	else max_limit = BUCKET_INDEX_BFS[bucket+1];




	if (fatherSearch) {

		bucket = ((nodo-1)/(TREE_SIZE/NUM_BUCKETS));
		if (bucket>= NUM_BUCKETS-1) max_limit = TREE_SIZE-1;
		else max_limit = BUCKET_INDEX_BFS[bucket+1];
		valor = bfstree[max_limit];
		valor2 = bfstree[max_limit-1];
		if (max_limit % 2!=0) max_limit+=1;
		for (int i = max_limit-2; i >= 0; i-=2) {
#pragma HLS PIPELINE

					  node_relation = valor(1,0);
					  compare_node_min= DST_NODE(valor);
					  if ((compare_node_min == nodo) && (relationship == node_relation)) {
						  flag = true;
						  result1.write(SRC_NODE(valor));
						  break;
					  }
						valor = bfstree[i];
					compare_node_max = DST_NODE(valor2);
					if ((compare_node_max == nodo) && (relationship == node_relation)) {
						flag=true;
						result2.write(SRC_NODE(valor2));
						break;
					}
					valor2 = bfstree[i-1];

		}
		if (!flag) {
			node_relation = valor(1,0);
			compare_node_min = DST_NODE(valor);
			 if ((compare_node_min == nodo) && (relationship == node_relation)) result1.write(SRC_NODE(valor));
			compare_node_max = DST_NODE(valor2);
			 if ((compare_node_max == nodo) && (relationship == node_relation)) result2.write(SRC_NODE(valor2));
		}

	} else {
		valor = bfstree[min_limit];
		valor2 = bfstree[min_limit+1];
		min_limit+=2;
		for (; min_limit < max_limit; min_limit+=2) {
#pragma HLS PIPELINE


			node_relation = valor(1,0);
			compare_node_min = SRC_NODE(valor);
		  if (flag && (compare_node_min != nodo)) break;
		  if ((compare_node_min == nodo) && (relationship == node_relation)) {
			  flag=true;
			  result1.write(DST_NODE(valor));
		}
		valor = bfstree[min_limit];
		compare_node_max = SRC_NODE(valor2);
		if (flag && (compare_node_max != nodo)) break;
		if ((compare_node_max == nodo) && (relationship == node_relation)) {
			flag = true;
			result2.write(DST_NODE(valor2));
		}
		valor2 = bfstree[min_limit+1];
	}
		compare_node_min = SRC_NODE(valor);
		if ((compare_node_min == nodo) && (relationship == node_relation)) result1.write(DST_NODE(valor));
		compare_node_max = SRC_NODE(valor2);
		if ((compare_node_max == nodo) && (relationship == node_relation)) result2.write(DST_NODE(valor2));
}
	result1.write(EOT);
	result2.write(EOT);
}
 void combinar(hls::stream<node_t> &in1, hls::stream<node_t> &in2,hls::stream<node_t> &result) {
 		bool end[2] = {false,false};
 #pragma HLS ARRAY_PARTITION variable=end complete dim=1
 		bool isData_1 = false, isData_2 = false;
 		node_t val1,val2;
 		do {
 #pragma HLS PIPELINE
 			isData_1 = in1.read_nb(val1);
 			isData_2 = in2.read_nb(val2);

 			if (isData_1) {
 				if (val1 == EOT){
 					end[0]=true;
 				}
 				else{
 					 result.write(val1);
 				}
 			}

 			if (isData_2) {
 				if (val2 == EOT) end[1]=true;
 				else{
 				 result.write(val2);
 				}
 			}

 		} while ((!end[0]) || (!end[1]));

 		result.write(EOT);


 }
