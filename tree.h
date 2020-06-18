#include <vector>

struct Nodo {
	int id_nodo;
	std::vector<int> hijos;
	int n_hijos;
	short relacion;
};


void tree_generator (int nodos, int max_hijos);
