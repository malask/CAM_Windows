#include <cstdlib>
#include <ctime>
#include <iostream>
#include <queue>
#include <list>
#include <fstream>
#include <string>
#include "tree.h"
#include <stack>
#include <math.h>

static int tree_size;
bool idSorter(struct Nodo *a, struct Nodo *b) {
	return (a->id_nodo < b->id_nodo);
}
void initNode(struct Nodo &nodo, unsigned int id, unsigned int n_hijos, unsigned short rel, struct Nodo* padre) {
	nodo.id_nodo = id;
	nodo.n_hijos = n_hijos;
	nodo.relacion = rel;
	nodo.padre = padre;
}


void treeGenerator(int nodos, int max_hijos) {
	tree_size = nodos;
	int counter = 2;
	std::vector<Nodo*> arbol;
	std::queue<Nodo*> analizar;
	std::queue<Nodo*> hijos_libres;
	Nodo* hijo;
	Nodo* actual;
	Nodo* temp;
	Nodo raiz = Nodo();
	initNode(raiz, 1, (rand() % max_hijos)+1,0,NULL);
	analizar.push(&raiz);
	while (arbol.size() < nodos ) {
		if (analizar.empty()) {
			temp = hijos_libres.front();
			hijos_libres.pop();
			temp->n_hijos += 1;
			hijo = new Nodo;
			initNode(*hijo, counter, rand() % max_hijos, 0, temp);
			temp->nodos_hijos.push_back(hijo);
			counter++;
			analizar.push(hijo);
			if ((hijo->n_hijos) < max_hijos) hijos_libres.push(hijo);
		}
		actual = analizar.front();
		analizar.pop();
		if (counter < nodos) {
			for (int i = 0; i < actual->n_hijos; i++) {
				if (counter < nodos) {
					hijo = new Nodo;
					initNode(*hijo, counter, rand() % max_hijos, 0, actual);
					actual->nodos_hijos.push_back(hijo);
					analizar.push(hijo);
					counter++;
					if (hijo->n_hijos < max_hijos) hijos_libres.push(hijo);

				}

			}
		}
		else {
			actual->n_hijos = 0;

		}
		arbol.push_back(actual);
	}
	/*for (Nodo* i : arbol) {
		if (i->padre == NULL) std::cout << i->id_nodo << " " << i->n_hijos << " " << "0" << " " << i->relacion << " " << std::endl;
		else std::cout << i->id_nodo << " " << i->n_hijos << " " << i->padre->id_nodo << " " << i->relacion << " " << std::endl;
	} */
	reorderTreeBFS(arbol);
	std::sort(arbol.begin(), arbol.end(), idSorter);
	treeData(arbol);
	graphGenerator(arbol,false);
	bfstreeToHLS(arbol, bits_needed(nodos));
	reorderTreeDFS(arbol);
	//std::sort(arbol.begin(), arbol.end(), idSorter);
	graphGenerator(arbol, true);
	dfstreeToHLS(arbol,bits_needed(nodos));
}

void reorderTreeDFS(std::vector<Nodo*> arbol) {
	std::stack<Nodo*> pila_dfs;
	unsigned int counter = 1;
	Nodo* raiz = arbol[0];
	Nodo* actual;
	pila_dfs.push(raiz);
	while (!pila_dfs.empty()) {
		actual = pila_dfs.top();
		pila_dfs.pop();
		for (auto it = actual->nodos_hijos.rbegin(); it != actual->nodos_hijos.rend(); ++it) pila_dfs.push(*it);
		actual->id_nodo = counter;
		counter++;
		
	}
	
}
void graphGenerator(std::vector<Nodo*> arbol, bool isDfs) {
	std::string file_name("graphviz_tree_");
	if (!isDfs) file_name += "bfs_";
	else file_name += "dfs_";
	file_name += std::to_string(tree_size) + ".txt";
	std::ofstream file(file_name);
	file << " graph T { " << std::endl;
	std::string hijos;
	for (Nodo* i : arbol) { 
		if (i->n_hijos != 0) {
			hijos += " {";
			for (Nodo* j : i->nodos_hijos) hijos += " " + std::to_string(j->id_nodo);
			//std::cout << hijos << std::endl;
			hijos += " }";
			switch (i->relacion) {
			case 0:
				file << "   " <<i->id_nodo << "  -- " << hijos << " [color = green];" << std::endl;
				break;
			case 1:
				file << "   " << i->id_nodo << " -- " << hijos << " [color = red];" << std::endl;
				break;
			case 2:
				file << "   " << i->id_nodo << " -- " << hijos << " [color = blue];" << std::endl;
				break;
			case 3:
				file << "   " << i->id_nodo << " -- " << hijos << " [color = yellow];" << std::endl;
				break;

			} // END SWITCH
		} // END IF 
		hijos = "";
	}// END FOR
	file << "}" << std::endl;
	file.close();
	
}
void bfstreeToHLS(std::vector<Nodo*> arbol, unsigned int necessaryBits) {
	std::string file_name("hls_tree_bfs_" + std::to_string(tree_size) + ".txt");
	std::ofstream file(file_name);
	std::queue<Nodo*> cola_bfs;
	unsigned int palabra;
	unsigned int padre, hijo;
	Nodo* i;
	cola_bfs.push(arbol[0]);
	while (!cola_bfs.empty()) {
		i = cola_bfs.front();
		cola_bfs.pop();
		padre = i->id_nodo;
		for (auto it = i->nodos_hijos.begin(); it != i->nodos_hijos.end(); ++it) {
			Nodo* j = *it;
			hijo = j->id_nodo;
			palabra = (((padre & 0xFFFF) << (necessaryBits+2)) | ((hijo & 0xFFFF) << 2) | (i->relacion & 0xFF));
			file << palabra << std::endl;
			cola_bfs.push(j);
		}
	}
	file.close();
}

void dfstreeToHLS(std::vector<Nodo*> arbol, unsigned int necessaryBits) {
	std::string file_name("hls_tree_dfs_" + std::to_string(tree_size) + ".txt");
	std::ofstream file(file_name);
	std::stack<Nodo*> pila_dfs;
	unsigned int palabra;
	unsigned int padre, hijo;
	Nodo* i = arbol[0];
	for (auto it = i->nodos_hijos.rbegin(); it != i->nodos_hijos.rend(); ++it) pila_dfs.push(*it);

	while (!pila_dfs.empty()) {
		i = pila_dfs.top();
		pila_dfs.pop();
		padre = i->padre->id_nodo;
		for (auto it = i->nodos_hijos.rbegin(); it != i->nodos_hijos.rend(); ++it) pila_dfs.push(*it);
		hijo = i->id_nodo;
		palabra = (((padre & 0xFFFF) << (necessaryBits + 2)) | ((hijo & 0xFFFF) << 2) | (i->relacion & 0xFF));
		file << palabra << std::endl;		
	}
	file.close();
}

void treeData(std::vector<Nodo*> arbol) {
	std::string file_name("arbol_" + std::to_string(tree_size) + ".txt");
	std::ofstream file(file_name);
	std::string hijos;
	file << "ID_NODO" << "    " << "PADRE:   " << "RELACION" << "    " << "ID_HIJOS " << std::endl;
	for (Nodo* i : arbol) {
		if (i->id_nodo == 1) {
			for (Nodo* j : i->nodos_hijos) hijos += " "+std::to_string(j->id_nodo);
			file << i->id_nodo << "    RAIZ        " << i->relacion << "         " << hijos << std::endl;
		} else if (i->n_hijos != 0) {
			for (Nodo* j : i->nodos_hijos) hijos += " "+std::to_string(j->id_nodo);
			file << i->id_nodo << "          " << i->padre->id_nodo <<"         " << i->relacion << "        " << hijos << std::endl;
		} else 	file << i->id_nodo << "         " << i->padre->id_nodo << "        " << i->relacion << "      " << "SIN HIJOS" << std::endl;
		hijos = "";
	}
	file.close();
}
void reorderTreeBFS(std::vector<Nodo*> arbol) {
	std::queue<Nodo*> cola_bfs;
	unsigned int counter = 2;
	Nodo* raiz = arbol[0];
	Nodo* actual;
	cola_bfs.push(raiz);
	while (!cola_bfs.empty()) {
		actual = cola_bfs.front();
		cola_bfs.pop();
		for (auto it = actual->nodos_hijos.begin(); it != actual->nodos_hijos.end(); ++it) {
			Nodo* hijo = *it;
			hijo->id_nodo = counter;
			cola_bfs.push(hijo);
			counter++;
		}
	}
	
}

unsigned int bits_needed(uint32_t value) {
	int bits = 0;
	for (int bit_test = 16; bit_test > 0; bit_test >>= 1)
	{
		if (value >> bit_test != 0)
		{
			bits += bit_test;
			value >>= bit_test;
		}
	}
	return bits + value;
}
int main() {
	for (int i = 7; i < 16; i++) treeGenerator(pow(2, i), 3);

		return 0;
	}
	