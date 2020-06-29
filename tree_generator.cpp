#include <cstdlib>
#include <ctime>
#include <iostream>
#include <queue>
#include <stack>
#include <list>
#include <fstream>
#include <string>
#include "tree.h"
#include <math.h>
#include <bitset>
#include <bit>


void initNode(struct Nodo* n,unsigned int id, unsigned int nChilds, unsigned short rel, unsigned int padre) {
	n->id_nodo = id;
	n->n_hijos = nChilds;
	n->relacion = rel;
	n->id_padre = padre;

}
void initNode(struct Nodo* n, unsigned int id, unsigned int nChilds, unsigned short rel) {
		n->id_nodo = id;
		n->n_hijos = nChilds;
		n->relacion = rel;
}

void tree_generator(int nodos, int max_hijos) {
	srand((unsigned)time(0));



	/* for (int index = 0; index < 20; index++) {
	   randomNumber = (rand() % (max_hijos+1));
	   std::cout << randomNumber << std::endl;
	 } */

	unsigned int contador_nodos = 2;
	Nodo actual, hijo, temp, raiz;
	std::queue<unsigned int> hijos_libres;
	std::queue<Nodo> nodos_pendientes;
	std::vector<Nodo> tree;
	initNode(&raiz, 1, (unsigned int) (rand() % max_hijos)+1, (unsigned short) (rand() % 4), 0 );
	nodos_pendientes.push(raiz);
	unsigned int position = 0;
	while (tree.size() < nodos) {
		if (nodos_pendientes.empty() && tree.size() < nodos) {

			/* Si no hemos llegado al numero de nodos que nos pide el usuario, lo que hacemos es coger alguna posicion
			de la lista de nodos que pueden aumentar sus hijos. Lo cogemos y le aumentamos en 1 el numero de hijos que
			dicho nodo puede tener, le hacemos los cambios pertinentes y lo sustituimos en el arbol debido a que hemos modificado
			alguno de sus datos */

			position = hijos_libres.front();
			hijos_libres.pop();
			temp = tree[position];
			temp.n_hijos += 1;
			initNode(&hijo, contador_nodos, (unsigned int) (rand() % (max_hijos + 1)), (unsigned short) (rand() % 4),temp.id_nodo);
			temp.nodos_hijos.push_back(hijo);
			if (temp.n_hijos < max_hijos) hijos_libres.push(position);
			nodos_pendientes.push(hijo);
			tree[position] = temp;
			contador_nodos+=1;
		}

		/* Cogemos un nodo de los pendientes de procesar y efectuamos esta operacion:
		 * Crear sus hijos (de manera aleatoria), rellenar sus datos e introducirlo en el árbol y en el marcador de hijos libres
		 * si es que es candidato a expandir el numero de hijos posteriormente
		 */

		actual = nodos_pendientes.front();
		nodos_pendientes.pop();

		if (contador_nodos < nodos) {
			for (int k = 0; k < actual.n_hijos; k++) {
				initNode(&hijo, contador_nodos, (unsigned int) (rand() % (max_hijos + 1)), (unsigned short) (rand() % 4),actual.id_nodo);
				actual.nodos_hijos.push_back(hijo);
				nodos_pendientes.push(hijo);
				contador_nodos+=1;
				if (contador_nodos >= nodos) break;
			}
		}
		else initNode(&actual, actual.id_nodo, 0, actual.relacion);
		tree.push_back(actual); // Se introduce en el arbol definitivo el nodo
		if (actual.n_hijos < max_hijos) hijos_libres.push(actual.id_nodo); // Se marca el nodo por si necesitamos incluir mas nodos posteriormente
	}
	/*for (int i =0; i<tree.size();i++) {

		// PROBAR SI ESTÁN BIEN HECHAS LAS RELACIONES PADRE-HIJO
		if (tree[i].n_hijos == 0) {
			std::cout << tree[i].id_nodo << "			" << tree[i].n_hijos << "			" << tree[i].relacion << std::endl;
		}
		else {
			for (int j=0;j<tree[i].n_hijos;j++) {
				std::cout << "  " << tree[i].id_nodo << "		"<< tree[i].n_hijos << "		" << tree[i].relacion << "			" << tree[i].hijos[j] << std::endl;
			}
		}
	}
	*/
	std::string listahijos;
	std::string filetext_name = "arbol_" + std::to_string(nodos) + ".txt";
	std::ofstream file(filetext_name);
	file << "ID NODO			NUMERO DE HIJOS					RELACION			ID HIJOS" << std::endl;
	for (int i = 0; i < tree.size(); i++) {
		if (tree[i].n_hijos == 0) {
			file << tree[i].id_nodo << "			" << tree[i].n_hijos << "			" << tree[i].relacion << "       SIN HIJOS" << std::endl;
		}
		else {
			for (int j = 0; j < tree[i].nodos_hijos.size(); j++) {
				listahijos += std::to_string(tree[i].nodos_hijos[j].id_nodo);
				if (tree[i].nodos_hijos.size() > 1 && j < tree[i].nodos_hijos.size()) listahijos += ",";
			}
			file << tree[i].id_nodo << "			" << tree[i].n_hijos << "			" << tree[i].relacion << "     " << listahijos << std::endl;
		}
		listahijos.clear();

 	}
		file.close();
		graphGenerator(tree); // Comprobado que funciona correctamente
		treeToHLS(tree, bits_needed(tree.size()));


		
}
void graphGenerator(std::vector<Nodo> arbol) {
	std::string filetext_name = "graphviz_data_" + std::to_string(arbol.size()) + ".txt";
	std::ofstream graph(filetext_name);
	graph << "graph T {" << std::endl;
	for (Nodo i : arbol) {
		if (i.n_hijos != 0) {
			graph <<"   " << std::to_string(i.id_nodo) << "  --  {";
			for (Nodo j : i.nodos_hijos) graph << " " << std::to_string(j.id_nodo);
			graph << "}";
			switch (i.relacion) {
			case 0 :
				graph << " [color = green];" << std::endl;
				break;
			case 1: 
				graph << " [color = blue];" << std::endl;
				break;
			case 2: 
				graph << " [color = red];" << std::endl;
				break;
			case 3: 
				graph << " [color = darkturquoise];" << std::endl;
				break;
			}
		}
		}
	graph << "}" << std::endl;
	graph.close();
}

void treeToHLS(std::vector<Nodo> root, unsigned int necessaryBits) {
	unsigned int palabra = 0;
	std::string dfs_filetext_name = "hls_tree_dfs_" + std::to_string(root.size()) + ".txt"; // NOMBRE DEL ARCHIVO Y FORMATO 
	std::string bfs_filetext_name = "hls_tree_bfs_" + std::to_string(root.size()) + ".txt";
	std::ofstream hls_tree_dfs(dfs_filetext_name);
	std::ofstream hls_tree_bfs(bfs_filetext_name);
	std::cout << necessaryBits << " " << std::endl;
	Nodo i;
	std::stack<Nodo> pila_dfs;
	std::queue<Nodo> cola_bfs;
	i = root[0];
	for (auto it = i.nodos_hijos.rbegin(); it != i.nodos_hijos.rend(); ++it) pila_dfs.push(root[it->id_nodo-1]);
	for (auto it = i.nodos_hijos.begin(); it != i.nodos_hijos.end() ; ++it) cola_bfs.push(root[it->id_nodo-1]);
	while (!pila_dfs.empty()) {
		Nodo actual = pila_dfs.top();
		pila_dfs.pop();
		palabra = (((actual.id_padre & 0xFF) << (necessaryBits+2)) | ((actual.id_nodo & 0xFF) << 2) | (actual.relacion & 0xF));
		hls_tree_dfs << palabra << std::endl;
		for (auto it = actual.nodos_hijos.rbegin(); it != actual.nodos_hijos.rend(); ++it) {
			pila_dfs.push(root[it->id_nodo-1]);
		}
	}
	hls_tree_dfs.close();
	while (!cola_bfs.empty()) {
		Nodo actual = cola_bfs.front();
		cola_bfs.pop();
		palabra = (((actual.id_padre & 0xFF) << (necessaryBits + 2)) | ((actual.id_nodo & 0xFF) << 2) | (actual.relacion & 0xF));
		hls_tree_bfs << palabra << std::endl;
		for (auto it = actual.nodos_hijos.begin(); it != actual.nodos_hijos.end(); it++) cola_bfs.push(root[it->id_nodo-1]);
	}
	hls_tree_bfs.close(); 
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
std::string toBinary(int n) {
	std::string r;
	while (n != 0) { r = (n % 2 == 0 ? "0" : "1") + r; n /= 2; }
	return r;
}

int main() {
	int arbol_size = 128;
	for (int i = 1; i < 10; i++) {
		tree_generator(arbol_size, 3);
		arbol_size = arbol_size * 2;
		
	}
}
