#include <cstdlib>
#include <ctime>
#include <iostream>
#include <queue>
#include <list>
#include <fstream>
#include "tree.h"


void initNode (struct Nodo *n, int id, int nChilds, short rel) {
	n->id_nodo = id;
	n->n_hijos = nChilds;
	n->relacion = rel;

}

void tree_generator(int nodos, int max_hijos) {
	  srand((unsigned) time(0));
	  int randomNumber;


	 /* for (int index = 0; index < 20; index++) {
	    randomNumber = (rand() % (max_hijos+1));
	    std::cout << randomNumber << std::endl;
	  } */
	int contador = 1;
	int contador_nodos = 2;
	Nodo actual,hijo, temp,raiz;
	std::queue<int> hijos_libres;
	std::queue<Nodo> nodos_pendientes;
	std::vector<Nodo> tree;
	initNode(&raiz,1,(rand() % ((max_hijos) + 1)),(rand()% 4));
	nodos_pendientes.push(raiz);
	int position=0;
	while (tree.size() < nodos){
		if (nodos_pendientes.empty()) {

			/* Si no hemos llegado al numero de nodos que nos pide el usuario, lo que hacemos es coger alguna posicion
			de la lista de nodos que pueden aumentar sus hijos. Lo cogemos y le aumentamos en 1 el numero de hijos que
			dicho nodo puede tener, le hacemos los cambios pertinentes y lo sustituimos en el arbol debido a que hemos modificado
			alguno de sus datos */

			position=hijos_libres.front();
			hijos_libres.pop();
			temp = tree[position];
			temp.n_hijos +=1;
			initNode(&hijo,contador_nodos,(rand()%(max_hijos+1)),(rand()%4));
			temp.hijos.push_back(hijo.id_nodo);
			if (temp.n_hijos < max_hijos) hijos_libres.push(position);
			nodos_pendientes.push(hijo);
			tree[position]=temp;
			contador_nodos++;
		}

		/* Cogemos un nodo de los pendientes de procesar y efectuamos esta operacion:
		 * Crear sus hijos (de manera aleatoria), rellenar sus datos e introducirlo en el árbol y en el marcador de hijos libres
		 * si es que es candidato a expandir el numero de hijos posteriormente
		 */

		actual = nodos_pendientes.front();
		nodos_pendientes.pop();

		if (contador_nodos < nodos) {
			for (int k=0;k<actual.n_hijos;k++){
				initNode(&hijo,contador_nodos,(rand()%(max_hijos+1)),(rand()%4));
				actual.hijos.push_back(hijo.id_nodo);
				nodos_pendientes.push(hijo);
				contador_nodos++;
			}
		} ;
		tree.push_back(actual); // Se introduce en el arbol definitivo el nodo
		if (actual.n_hijos < max_hijos) hijos_libres.push(tree.size()-1); // Se marca el nodo por si necesitamos incluir mas nodos posteriormente
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
	std::ofstream file ("arbol.txt");
	for (int i = 0;i<tree.size();i++)  file << tree[i].id_nodo << "			" << tree[i].n_hijos << "			" << tree[i].relacion << "\n";
	file.close();
}
