#include <vector>

struct Nodo {
	unsigned int id_nodo;
	unsigned int id_padre;
	unsigned int n_hijos;
	unsigned short relacion;
	std::vector<Nodo> nodos_hijos;
};


void initNode(struct Nodo* n, unsigned int id, unsigned int nChilds, unsigned short rel, unsigned int padre);
void initNode(struct Nodo* n, unsigned int id, unsigned int nChilds, unsigned short rel);
void tree_generator(int nodos, int max_hijos);
void graphGenerator(std::vector<Nodo> arbol);
void treeToHLS(std::vector<Nodo> root, unsigned int necessaryBits);
unsigned int bits_needed(uint32_t value);
std::string toBinary(int n);