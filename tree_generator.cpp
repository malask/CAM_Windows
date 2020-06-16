#include <cstdlib>
#include <ctime>
#include <iostream>
#include <queue>
#include <list>

void tree_generator(int nodos, int max_hijos) {
	  srand((unsigned) time(0));
	  int randomNumber;

	  typedef struct {
		  int id_nodo;
		  std::list<nodo> hijos[max_hijos];
		  int n_hijos;
		  short relacion;
	  } nodo;
	  nodo tree[nodos];
	 /* for (int index = 0; index < 20; index++) {
	    randomNumber = (rand() % (max_hijos+1));
	    std::cout << randomNumber << std::endl;
	  } */
	int contador,nodo_actual = 1;
	std::queue<nodo> hijos_libres;
	std::queue<nodo> arbol;
	nodo raiz = {1,NULL,(rand()%(max_hijos)+1), (rand()%4)};
	if (raiz.n_hijos < max_hijos) hijos_libres.push(raiz);
	tree[0] = raiz;
	arbol.push(raiz);
	nodo actual;
	while (contador < nodos){
		if (arbol.empty()) {
			actual = hijos_libres.pop();
			actual.n_hijos +=1;
			nodo nuevo_hijo = {contador+1,NULL,rand()%max_hijos, rand()%4};
			actual.hijos[]
		actual = arbol.pop();
		for (int k=0;k<actual.n_hijos;k++){
			nodo hijo = {contador+1,NULL,rand()%max_hijos,rand()%4};
			if (hijo.n_hijos < max_hijos) hijos_libres.push(hijo);
			actual.hijos[k] = hijo;
			arbol.push(hijo);
			contador++;
		};
	}













































		}







	}
}
