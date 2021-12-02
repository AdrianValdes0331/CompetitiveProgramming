//Adrian Valdes Zavala 
//A01720439
//DBinaryTree

#include <iostream>
#include <functional>
#include <stdio.h>
#include <map>

using namespace std;

//Complejidad O(n)
class Node {
	public:
		int data;
		Node* left;
		Node* right;
		Node(int d) {
			data = d;
			left = NULL;
			right = NULL;
		}
};

//Funcion que llena el mapa
void llenaArbol(Node* root, int dist, int nivel, map<int, pair<int, int> > &map) {
	//Caso arbol Vacio
	if (root == NULL) {
		return;
	}
	//Actualiza nivel y valor de la distancia actual
	if (map.find(dist) == map.end() || nivel < map[dist].second) {
		map[dist] = {root->data, nivel};
	}
	
	llenaArbol(root->left, dist - 1, nivel + 1, map);

	llenaArbol(root->right, dist + 1, nivel + 1, map);
}

//Nuevo arbol para imprimir los datos de arriva.
void topView(Node * root) {
	
	map<int, pair<int, int>> map;

	llenaArbol(root, 0, 0, map);

	for (auto tv = map.begin(); tv != map.end(); tv++) {
		cout << tv->second.first << " ";
	}

}

//Complejidad O(n)
int main() {
	Node* root = new Node(1);
	root->right = new Node(2);
	root->right->right = new Node(5);
	root->right->right->right = new Node(6);
	root->right->right->left = new Node(3);
	root->right->right->left->right = new Node(4);

	topView(root);
	return 0;
}

/*
	1
	 2
	  5
	 3 6
	  4
*/