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
#include <map>
#include <random>

static int tree_size;
static int n_buckets = 0;
static 	std::ofstream supremo;
static std::string tree_string("a");

bool idSorter(struct Nodo* a, struct Nodo* b) {
	return (a->id_nodo < b->id_nodo);
}
bool hlsSorter(unsigned int a, unsigned int b) {
	return (a < b);
}
void initNode(struct Nodo& nodo, unsigned int id, unsigned int n_hijos, unsigned short rel, struct Nodo* padre) {
	nodo.id_nodo = id;
	nodo.n_hijos = n_hijos;
	nodo.relacion = rel;
	nodo.padre = padre;
}
unsigned int  bitExtracted(unsigned int number, int k, int p)
{
	return (((1 << k) - 1) & (number >> (p - 1)));
}

void generateBucketIndex(std::vector<unsigned int> arbolhls, bool isDFS) {
	if (n_buckets == 0 || isDFS || (n_buckets%2 != 0)) return;
	supremo <<  "short BUCKET_INDEX_BFS [" << n_buckets << "] = {0,";
	
	int index = tree_size / n_buckets;
	int necessaryBits = bits_needed(tree_size);
	int count = 0;
	int formula = 1;
	unsigned int padre = 0;
	unsigned int padre_anterior = 0;
	std::cout << "Para el arbol : " << tree_size << std::endl;
	for (int i = 0; i < tree_size -1; i++) {
		padre = bitExtracted(arbolhls[i], necessaryBits, 3 + necessaryBits);
		if (padre == formula * index && (formula < n_buckets)) {
			unsigned int padre_anterior = bitExtracted(arbolhls[i - 1], necessaryBits, 3 + necessaryBits);
			if (padre != padre_anterior) {
				std::cout << "Padre: " << padre << " y padre anterior: " << padre_anterior << std::endl;
				std::cout << "Valor: " << arbolhls[i] << std::endl;
				formula += 1;
				if (formula == n_buckets) supremo << i << "};"  << std::endl;
				else supremo << i <<",";
			}
		}
		else if (padre > formula * index && (formula < n_buckets)) {
			unsigned int padre_anterior = bitExtracted(arbolhls[i - 1], necessaryBits, 3 + necessaryBits);
			if (padre != padre_anterior) {
				std::cout << "Padre mayor: " << padre << " y padre anterior: " << padre_anterior << std::endl;
				std::cout << "Valor hls: " << arbolhls[i] << std::endl;
				formula += 1; 
				
				if (formula == n_buckets) supremo << i << "};" << std::endl;
				else supremo << i << ",";
			}
		}
	}
	supremo << std::endl;
	supremo << "short FULL_CHILDREN_BUCKET_INDEX_BFS[" << tree_size << "] = {0";
	padre = 1;
	padre_anterior = 1;
	std::vector<bool> visited;
	std::vector<int> child_pos;
	visited.push_back(true);
	for (int i = 0; i < tree_size; i++) {
		visited.push_back(false);
		child_pos.push_back(0);
	}
	std::cout << "Valor inicial: " << visited[0] << std::endl;
	for (int i = 0; i < tree_size - 1; i++) {
		padre = bitExtracted(arbolhls[i], necessaryBits, 3 + necessaryBits);
		if (!visited[padre - 1]) {
			visited[padre - 1] = true;
			child_pos[padre - 1] = i;
		}
	}
	for (int i = 1; i < tree_size; i++) {
		supremo << "," << child_pos[i];
	}
	supremo << "};" << std::endl;
	supremo << "short FULL_PARENTS_BUCKET_INDEX_BFS[" << tree_size << "] = {-1";
	int buscar = 2;
	for (int j = 1; j < tree_size; j++) {
		for (int i = 0; i < tree_size - 1; i++) {
			padre = bitExtracted(arbolhls[i], necessaryBits, 3);
			if (padre == buscar) {
				supremo << "," << i;
				buscar += 1;
				break;
			}
		}
	}
	supremo << "};" << std::endl;
}

void results(std::vector<Nodo*> arbol, int n_hijos) {
	std::ofstream fichero("results_" + std::to_string(tree_size) + ".cpp");
	std::map<int, Nodo*> passed;

	for (int i = 0; i < arbol.size() / 4; i++) {
		int number = (rand() % tree_size) + 1;
		while (passed[number] != NULL) {
			number = (rand() % tree_size) + 1;
		}
		passed[number] = arbol[number - 1];
	}

	//fichero << "int results_parents[" << tree_size / 4 << "] = {";
	fichero << "int selected [" << tree_size / 4 << "] = {";

	for (std::map<int, Nodo*>::iterator it = passed.begin(); it != passed.end(); ++it) {
		if (std::next(it) == passed.end()) fichero << it->first << "};" << std::endl;
		else fichero << it->first << ",";
	}
	fichero << "int results_parents[" << tree_size / 4 << "] = {";

	for (std::map<int, Nodo*>::iterator it = passed.begin(); it != passed.end(); ++it) {
		if (std::next(it) == passed.end()) fichero << it->second->padre->id_nodo << "};" << std::endl;
		else {
			if (it->second->padre == NULL) fichero << "0,";
			else fichero << it->second->padre->id_nodo << ",";
		}
	}


	//int contador = 0;
	fichero << "int results_childrens [" << tree_size / 4 << "][" << n_hijos << "] = {";

	for (std::map<int, Nodo*>::iterator it = passed.begin(); it != passed.end(); ++it) {
		fichero << "{";
		if (it->second->nodos_hijos.size() > 0) {
			for (int i = 0; i < it->second->nodos_hijos.size(); i++) {
				fichero << it->second->nodos_hijos[i]->id_nodo;
				if ((i + 1) != (it->second->nodos_hijos.size())) fichero << ",";


			}
		}
		else {
			fichero << 0;

			//contador += 1;
		}
		if (std::next(it) == passed.end()) fichero << "}};" << std::endl;
		else fichero << "},";
	}

	fichero << "int n_hijos [" << tree_size / 4 << "] = {";
	for (std::map<int, Nodo* >::iterator it = passed.begin(); it != passed.end(); ++it) {
		if (std::next(it) == passed.end()) {
			fichero << it->second->n_hijos << "};" << std::endl;
		}
		else fichero << it->second->n_hijos << ",";
	}

	fichero << "int caminos_padres[] = { ";
	std::vector<Nodo*> padres;
	for (std::map<int, Nodo* >::iterator it = passed.begin(); it != passed.end(); ++it) {
		if (it->second->padre == NULL) fichero << "0,";
		else {
			fichero << it->second->padre->id_nodo << ",";
		padres.push_back(it->second->padre);
		while (!padres.empty()) {
			Nodo* a = padres.front();
			padres.erase(padres.begin());
			if (a->padre != NULL) {
				padres.push_back(a->padre);
				fichero << a->padre->id_nodo << "," ;
			}
		}
		if (std::next(it) != passed.end()) fichero << "0,";
		else fichero << "0";
		
		}
	}
	fichero << "}; " << std::endl;
	fichero << "int caminos_hijos[] = {";
	for (std::map<int, Nodo* >::iterator it = passed.begin(); it != passed.end(); ++it) {
		for (int i = 0; i < it->second->nodos_hijos.size(); i++) padres.push_back(it->second->nodos_hijos[i]);
		while (!padres.empty()) {
			Nodo* a = padres.front();
			padres.erase(padres.begin());
			fichero << a->id_nodo;
			for (int j = 0; j< a->nodos_hijos.size(); j++) padres.push_back(a->nodos_hijos[j]);
			fichero << ",";
		} 
		if (std::next(it) != passed.end()) fichero << "0,";
		else fichero << "0";
	}
	fichero << "};" << std::endl;
	fichero.close();
}




void treeGenerator(int nodos, int max_hijos, int buckets) {

	n_buckets = buckets;
	tree_size = nodos;
	int necessaryBits = bits_needed(nodos);
	int ap_bits = necessaryBits * 2 + 2;
	tree_string = "ap_uint<" + std::to_string(ap_bits) + "> ";
	int counter = 2;
	std::vector<Nodo*> arbol,arbol_2;
	std::queue<Nodo*> analizar;
	std::queue<Nodo*> hijos_libres;
	Nodo* hijo;
	Nodo* actual;
	Nodo* temp;
	Nodo raiz = Nodo();
	initNode(raiz, 1, (rand() % max_hijos) + 1, 0, NULL);
	analizar.push(&raiz);
	while (arbol.size() < nodos) {
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
	unsigned short count = 0;
	
	reorderTreeBFS(arbol);

	std::sort(arbol.begin(), arbol.end(), idSorter);
	treeData(arbol);
	results(arbol,max_hijos);
	
	bfstreeToHLS(arbol, bits_needed(nodos));
	//std::sort(arbol.begin(), arbol.end(), idSorter);
	//graphGenerator(arbol, true);
	//dfstreeToHLS(arbol, bits_needed(nodos));
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
void graphGenerator(std::vector<unsigned int> arbol, unsigned int necessaryBits) {
	std::string file_name("graphviz_tree_");
	file_name += std::to_string(tree_size) + ".txt";
	std::ofstream file(file_name);
	file << " digraph T { " << std::endl;
	
	
	for (unsigned int i : arbol) {
		unsigned int padre = bitExtracted(i, necessaryBits, 3 + necessaryBits);
		unsigned int hijo = bitExtracted(i, necessaryBits, 3);
		unsigned int relacion = bitExtracted(i, 2, 1);

		switch (relacion) {
		case 0:
			file << "   " << padre << "  -> " << hijo << " [color = green];" << std::endl;
			break;
		case 1:
			file << "   " << padre << " -> " << hijo << " [color = red];" << std::endl;
			break;
		case 2:
			file << "   " << padre << " ->  " << hijo << " [color = blue];" << std::endl;
			break;
		case 3:
			file << "   " << padre << " -> " << hijo << " [color = yellow];" << std::endl;
			break;
		}
	}
	file << "}" << std::endl;
	file.close();

}
void generateSubTrees(std::vector<std::vector<unsigned int>>& arboles, std::vector<unsigned int>& arbol, unsigned int n_arboles, unsigned int necessaryBits) {
	int f = 0;

	for (unsigned int i = 0; i < n_arboles; i++) {
		std::vector<unsigned int> sub_arbol;
		int limit_loop = (i+1) * (tree_size / n_arboles);
		supremo << tree_string << " bfstree_" << n_arboles << "_" << i+1 << " [" << tree_size / n_arboles << "] = {";
		for (; f < limit_loop-1; f++) sub_arbol.push_back(arbol[f]);
		for (int j = 0; j < sub_arbol.size()-1; j++) supremo << sub_arbol[j] << ",";
		if (i == n_arboles - 1) {
			supremo << arbol[arbol.size() - 1] << "};";
			
		}
		else supremo << sub_arbol[sub_arbol.size() - 1] << "};" << std::endl;
		
		arboles.push_back(sub_arbol);
		
		}
	}
	
	

void bfstreeToHLS(std::vector<Nodo*> arbol, unsigned int necessaryBits) {
	
	std::string file_name("hls_tree_bfs_" + std::to_string(tree_size) + ".txt");
	std::vector<unsigned int> arbol_hls;
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
			cola_bfs.push(j);
			palabra = (((padre & 0xFFFF) << (necessaryBits + 2)) | ((hijo & 0xFFFF) << 2) | (i->relacion & 0xFF));
			//file << palabra << std::endl;
			//supremo << palabra << ",";
			arbol_hls.push_back(palabra);
		}
			
		
	}
	unsigned int count = 0;
	std::random_device rd; // obtain a random number from hardware
	std::mt19937 gen(rd()); // seed the generator
	std::uniform_int_distribution<> distr_1(1, tree_size);
	std::uniform_int_distribution<> distr_2(2, tree_size);
	while (count < tree_size / 4) {
		padre = distr_1(gen);
		hijo = distr_2(gen);
		while (padre == hijo) {
			padre = distr_1(gen);
			hijo = distr_2(gen);
		}
		palabra = (((padre & 0xFFFF) << (necessaryBits + 2)) | ((hijo & 0xFFFF) << 2) | (1 & 0xFF));
		arbol_hls.push_back(palabra);
		count++;
	}
	supremo << tree_string << "bfstree [" << arbol_hls.size()+1 << "] = { ";
	std::sort(arbol_hls.begin(), arbol_hls.end(), hlsSorter);
	for (int i = 0; i < arbol_hls.size(); i++) {
		supremo << arbol_hls[i] << ",";
	}
	
	supremo << "0};" << std::endl;
	

	std::vector<std::vector<unsigned int>>subarboles;
	graphGenerator(arbol_hls, necessaryBits);
	generateBucketIndex(arbol_hls, false);
	//generateSubTrees(subarboles, arbol_hls, 2, necessaryBits);
    //generateSubBucketIndex(subarboles, false, 2);
	//subarboles.clear(); 
	//generateSubTrees(subarboles, arbol_hls, 4, necessaryBits);
	//generateSubBucketIndex(subarboles, false, 4);
	file.close();
}


void generateSubBucketIndex(std::vector<std::vector<unsigned int>>& arbol_hls, bool isDFS, int n_trees) {
	if (n_buckets == 0 || isDFS || (n_buckets % 2 != 0)) return;
	int counter = 1;

	int index = tree_size / (n_buckets * n_trees);
	int necessaryBits = bits_needed(tree_size);

	int cuenta_buckets;
	unsigned int hijo, padre;

	int formula = 0;
	for (int i = 0; i < n_trees; i++) {
		supremo << "short BUCKET_INDEX_" << n_trees << "_" << i + 1 <<  " [" << n_buckets << "] = {0,";
		std::vector<unsigned int> current_tree = arbol_hls[i];
		unsigned int padre_anterior = 0;
		for (int j = 0; j < current_tree.size(); j++) {
			padre = bitExtracted(current_tree[j], necessaryBits, 3 + necessaryBits);
			if (padre >= formula * index && (formula < n_buckets * (i + 1))) {
				if (j != 0) padre_anterior = bitExtracted(current_tree[j - 1], necessaryBits, 3 + necessaryBits);
				if (padre != padre_anterior) {
					formula += 1;
					if (formula == (n_buckets * (i + 1))) {
						supremo << j << "};" << std::endl;
						break;
					}
					else if (j != 0) supremo << j << ",";
				}
			}
		}
		while (formula < (n_buckets *(i + 1))) {
			formula += 1;
			if (formula == (n_buckets * (i + 1))) supremo << "-1};" << std::endl;
			else supremo << "-1,";
			
		}
		formula += 1;
	}
	supremo << std::endl;
}


void dfstreeToHLS(std::vector<Nodo*> arbol, unsigned int necessaryBits) {

	std::string file_name("hls_tree_dfs_" + std::to_string(tree_size) + ".txt");
	supremo << tree_string << "dfstree [" << std::to_string(tree_size) << "] = { ";
	std::vector<unsigned int> arbol_hls;

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
		supremo << palabra << ", ";

		file << palabra << std::endl;
		arbol_hls.push_back(palabra);
	}

	supremo << "0};" << std::endl;
	supremo << tree_string << "dfstree_1 [" << std::to_string(tree_size / 2) << "] = { ";
	int tamano = arbol_hls.size();
	for (int i = 0; i < tamano; i++) {
		if ((i + 1) % (tree_size / 2) == 0) {
			supremo << arbol_hls[i] << "};" << std::endl;
			supremo << tree_string << "dfstree_2 [" << std::to_string(tree_size / 2) << "] = {";
		}
		else if (i == tamano - 1) supremo << arbol_hls[i] << "};" << std::endl;
		else supremo << arbol_hls[i] << ",";
	}
	generateBucketIndex(arbol_hls, true);
	file.close();
}

void treeData(std::vector<Nodo*> arbol) {
	std::string file_name("arbol_" + std::to_string(tree_size) + ".txt");
	std::ofstream file(file_name);
	std::string hijos;
	file << "ID_NODO" << "    " << "PADRE:   " << "RELACION" << "    " << "ID_HIJOS " << std::endl;
	for (Nodo* i : arbol) {
		if (i->id_nodo == 1) {
			for (Nodo* j : i->nodos_hijos) hijos += " " + std::to_string(j->id_nodo);
			file << i->id_nodo << "    RAIZ        " << i->relacion << "         " << hijos << std::endl;
		}
		else if (i->n_hijos != 0) {
			for (Nodo* j : i->nodos_hijos) hijos += " " + std::to_string(j->id_nodo);
			file << i->id_nodo << "          " << i->padre->id_nodo << "         " << i->relacion << "        " << hijos << std::endl;
		}
		else 	file << i->id_nodo << "         " << i->padre->id_nodo << "        " << i->relacion << "      " << "SIN HIJOS" << std::endl;
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
	std::ofstream fichero("data_128.cpp");
	supremo.swap(fichero);
	supremo << "#include \"ap_int.h\"" << std::endl;
	srand(time(NULL));
	
	/*for (int i = 7; i < 14; i++) {
		std::ofstream fichero("data_" + std::to_string((int)pow(2, i)) + ".cpp");
		supremo.swap(fichero);
		supremo << "#include \"ap_int.h\"" << std::endl;

		treeGenerator(pow(2, i), 3, 8);
		supremo.close();
		fichero.close();
	
	} */ // Para generar automaticamente los arboles desde 128 hasta 8K nodos. 
	for (int i = 6; i < 8; i++) {
		std::ofstream fichero("data_" + std::to_string((int)pow(2, i)) + ".cpp");
		supremo.swap(fichero);
		supremo << "#include \"ap_int.h\"" << std::endl;

		treeGenerator(pow(2, i), 3, 8);
		supremo.close();
		fichero.close();
	}
	return 0;

}