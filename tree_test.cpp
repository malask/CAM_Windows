#include "tree.h"
#include <iostream>
#include <cstdlib>
int main () {
	/*std::vector<Nodo> tree;
	tree = tree_generator(1000,3);
	for (int i =0; i<tree.size();i++) {
		 std::cout << tree[i].id_nodo << "			" << tree[i].n_hijos << "			" << tree[i].relacion << std::endl;

	}
    */
	tree_generator(500,3);
}
