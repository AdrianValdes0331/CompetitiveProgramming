//Adrian Valdes Zavala 
//A01720439
//DBinaryTree

#include <iostream>
#include <stdio.h>
#include <map>

using namespace std;
//Complejidad O(n), Lineal
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
void llenaArbol(Node* root, int dist, int height, map<int, pair<int, int>>& m) {
	if (root == NULL) {
		return;
	}

	llenaArbol(root->left, dist - 1, height + 1, m);
	if (m.find(dist) == m.end()) {
		m[dist] = make_pair(root->data, height);
	}

	else if (m[dist].second > height) {
		m[dist] = make_pair(root->data, height);
	}

	llenaArbol(root->right, dist+1, height+1, m);
}
//Nuevo arbol para imprimir los datos de arriva.
void topView(Node* root) { 
	if (root == NULL) {
		return;
	}

	map<int, pair<int, int>> m;

	llenaArbol(root, 0, 0, m);

	for (auto tv = m.begin(); tv != m.end(); tv++) {
		cout << tv->second.first << " ";
	}
}

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

/*int main() {
	Node* root = new Node(1);
	root->right = new Node(2);
	root->right->right = new Node(5);
	root->right->right->right = new Node(6);
	root->right->right->left = new Node(3);
	root->right->right->left->right = new Node(4);

	topView(root);
	return 0;
}*/