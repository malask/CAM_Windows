#include <vector>

struct Nodo {
	unsigned int id_nodo;
	Nodo* padre;
	unsigned int n_hijos;
	unsigned short relacion;
	std::vector<Nodo*> nodos_hijos;

	Nodo() : id_nodo(0), padre(nullptr),n_hijos(0),relacion(0) {}
};


void initNode(struct Nodo& nodo, unsigned int id, unsigned int n_hijos, unsigned short rel, struct Nodo* padre);
void treeGenerator(int nodos, int max_hijos);
void reorderTreeBFS(std::vector<Nodo*> arbol);
void reorderTreeDFS(std::vector<Nodo*> arbol);
void treeData(std::vector<Nodo*> arbol);
void graphGenerator(std::vector<Nodo*> arbol, bool isDfs);
void bfstreeToHLS(std::vector<Nodo*> arbol, unsigned int necessaryBits);
void dfstreeToHLS(std::vector<Nodo*> arbol, unsigned int neccessaryBits);
unsigned int bits_needed(uint32_t value);
std::string toBinary(int n);