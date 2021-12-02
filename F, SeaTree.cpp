//Adrian Valdes Zavala 
//A01720439

#include <iostream>
#include <stdio.h>

using namespace std;
//Cada Valor a la derecha debe de ser mayor
//Cada Valor a la izquierda debe de ser menor

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

bool checkBST(Node* root) {
	//Nos movemos a la izquierda, con valor minmo de -1
	return TorF(root->left, -1, root->data) &&
		//Nos movemos a la derecha con valor minimo data y maximo de 10^4
		TorF(root->right, root->data, 10000);
}

bool TorF(Node* root, int min, int max) {
	//Si es 0 es BST
	if (root == 0) {
		return true;
	}
	//Traemos el valor actual de la posicion.
	int VActual = root->data;
	if (VActual <= min || VActual >= max) {
		return false;
	}
	//Utilizamos la recursividad hasta llegar a 0 
	//(si es que es BST)
	return TorF(root->left, min, VActual) && TorF(root->right, VActual, max);
}
