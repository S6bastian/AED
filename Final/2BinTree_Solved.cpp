// BinTree.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>

using namespace std;

// Nodo del Arbol 
class Node
{
public:
	int key;
	Node* left;
	Node* right;
	int height;
};

//Calcula la altura del arbol 
int height(Node* N)
{
	if (N == NULL)
		return 0;
	return N->height;
}

//maximo de 2 enteros
int max(int a, int b)
{
	return (a > b) ? a : b;
}

//Crea nuevo nodo
Node* newNode(int key)
{
	Node* node = new Node();
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1; // nuevo nodo 
	// añadido como hoja
	return(node);
}


// Otiene el factor de balance de N 
int getBalance(Node* N)
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

// Función recursiva que inserta la clave
// en el subarbol con raiz en node y 
// devuelve la nueva raiz del subarbol 
Node* insert(Node* node, int key)
{
	/* 1. Insersión normal en un arbol */
	if (node == NULL)
		return(newNode(key));

	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	else // no permite valores duplicados 
		return node;

	/* 2. Actualiza la altura desde el ancestro */
	node->height = 1 + max(height(node->left),
		height(node->right));

	return node;
}


//Impresion de arbol en Pre Orden
void preOrder(Node* root)
{
	if (root != NULL)
	{
		cout << root->key << " H: " << root->height << " B: " << getBalance(root) << " HL(" << ((root->left) ? root->left->key : 0) << "): " << height(root->left) << " HR(" << ((root->right) ? root->right->key : 0) << "): " << height(root->right) << endl;
		preOrder(root->left);
		preOrder(root->right);
	}
}

//TO DO

void kill(Node* root) {
	if (root == nullptr)
		return;
	kill(root->left);
	kill(root->right);

	delete root;

}

void updateHeight(Node* root) {
	if (root == nullptr)
		return;

	updateHeight(root->left);
	updateHeight(root->right);

	root->height = root->left == nullptr ? 1 : root->left->height + 1;

}

void Podar(Node* root)
{
	//TO DO
	
	Node** proot = &root;
	
	vector<Node*>* first, * second;
	first = new vector<Node*>;
	second = new vector<Node*>;
	
	first->push_back(root);
	for (bool stop = 0; stop == 0;) {
		for (int i = 0; i < first->size(); i++) {
			if ((*first)[i]->left == nullptr || (*first)[i]->right == nullptr) {
				stop = 1;
				break;
			}
			second->push_back((*first)[i]->left);
			second->push_back((*first)[i]->right);
		}
		if (stop == 0) {
			vector<Node*>* tmp = first;
			first = second;
			delete tmp;
			second = new vector<Node*>;
		}
	}
	
	for (int i = 0; i < first->size(); i++) {
		kill((*first)[i]->left);
		kill((*first)[i]->right);

		(*first)[i]->left = nullptr;
		(*first)[i]->right = nullptr;

	}

	updateHeight(root);

}



int main()
{
	Node* root = NULL;
	int A[] = { 50,30,80,20,40,60,90,10,25,5,15,28,38,53,65,85,95 };
	int n = sizeof(A) / sizeof(int);


	for (int i = 0; i < n; i++)
	{
		root = insert(root, A[i]);
	}


	cout << "Recorrido preorden del arbol contruido \n";
	preOrder(root);

	Podar(root);

	cout << "\n \n Recorrido preorden del arbol podado \n";
	preOrder(root);


	return 0;
}
