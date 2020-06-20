#include <cstdlib>
#include <ctime>
#include <iostream>
#include <queue>
#include <list>
#include <fstream>
#include <string>
#include "tree.h"




void initNode(struct Nodo* n, int id, int nChilds, short rel) {
	n->id_nodo = id;
	n->n_hijos = nChilds;
	n->relacion = rel;

}

void tree_generator(int nodos, int max_hijos) {
	srand((unsigned)time(0));
	int randomNumber;


	/* for (int index = 0; index < 20; index++) {
	   randomNumber = (rand() % (max_hijos+1));
	   std::cout << randomNumber << std::endl;
	 } */
	int contador = 1;
	int contador_nodos = 2;
	Nodo actual, hijo, temp, raiz;
	std::queue<int> hijos_libres;
	std::queue<Nodo> nodos_pendientes;
	std::vector<Nodo> tree;
	initNode(&raiz, 1, (rand() % ((max_hijos)+1)), (rand() % 4));
	nodos_pendientes.push(raiz);
	int position = 0;
	while (tree.size() < nodos) {
		if (nodos_pendientes.empty()) {

			/* Si no hemos llegado al numero de nodos que nos pide el usuario, lo que hacemos es coger alguna posicion
			de la lista de nodos que pueden aumentar sus hijos. Lo cogemos y le aumentamos en 1 el numero de hijos que
			dicho nodo puede tener, le hacemos los cambios pertinentes y lo sustituimos en el arbol debido a que hemos modificado
			alguno de sus datos */

			position = hijos_libres.front();
			hijos_libres.pop();
			temp = tree[position];
			temp.n_hijos += 1;
			initNode(&hijo, contador_nodos, (rand() % (max_hijos + 1)), (rand() % 4));
			temp.hijos.push_back(hijo.id_nodo);
			if (temp.n_hijos < max_hijos) hijos_libres.push(position);
			nodos_pendientes.push(hijo);
			tree[position] = temp;
			contador_nodos++;
		}

		/* Cogemos un nodo de los pendientes de procesar y efectuamos esta operacion:
		 * Crear sus hijos (de manera aleatoria), rellenar sus datos e introducirlo en el árbol y en el marcador de hijos libres
		 * si es que es candidato a expandir el numero de hijos posteriormente
		 */

		actual = nodos_pendientes.front();
		nodos_pendientes.pop();

		if (contador_nodos < nodos) {
			for (int k = 0; k < actual.n_hijos; k++) {
				initNode(&hijo, contador_nodos, (rand() % (max_hijos + 1)), (rand() % 4));
				actual.hijos.push_back(hijo.id_nodo);
				nodos_pendientes.push(hijo);
				contador_nodos++;
			}
		}
		else initNode(&actual, actual.id_nodo, 0, actual.relacion);
		tree.push_back(actual); // Se introduce en el arbol definitivo el nodo
		if (actual.n_hijos < max_hijos) hijos_libres.push(tree.size() - 1); // Se marca el nodo por si necesitamos incluir mas nodos posteriormente
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
	std::ofstream file("arbol.txt");
	file << "ID NODO			NUMERO DE HIJOS					RELACION			ID HIJOS" << std::endl;
	for (int i = 0; i < tree.size(); i++) {
		if (tree[i].n_hijos == 0) {
			file << tree[i].id_nodo << "			" << tree[i].n_hijos << "			" << tree[i].relacion << "       SIN HIJOS" << std::endl;
		}
		else {
			for (int j = 0; j < tree[i].hijos.size(); j++) {
				listahijos += std::to_string(tree[i].hijos[j]);
				if (tree[i].hijos.size() > 1 && j < tree[i].hijos.size()) listahijos += ",";
			}
			file << tree[i].id_nodo << "			" << tree[i].n_hijos << "			" << tree[i].relacion << "     " << listahijos << std::endl;
		}
		listahijos.clear();
		graphGenerator(tree);
	}
		file.close();
}
void graphGenerator(std::vector<Nodo> arbol) {
	std::ofstream graph("graphviz_data.txt");
	graph << "graph T {" << std::endl;
	for (Nodo i : arbol) {
		if (i.n_hijos != 0) {
			graph <<"   " << std::to_string(i.id_nodo) << "  --  {";
			for (int j : i.hijos) graph << " " << std::to_string(j);
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
int main() {
	tree_generator(128,3);
}
