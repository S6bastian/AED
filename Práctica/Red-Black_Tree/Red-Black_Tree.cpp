/*
	Notas:
	1. Hecho en base al video: https://www.youtube.com/playlist?list=PL9xmBV_5YoZNqDI8qfOZgzbqahCUmUEin
	2. root va a cambiar si se le hace una rotación (caso 3)
	3. Se modifica los colores de otras ramas?
*/


#include <iostream>
using namespace std;

template <class T>
struct Node {
	T value;
	Node* nodes[2];
	Node* parent;
	bool color; // 0 -> negro y 1 -> rojo

	Node(T v, *p = nullptr) {
		value = v;
		nodes[0] = nodes[1] = 0;
		color = 1;		// siempre rojo al crearse
		parent = p;
	}
};

///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

template <class T>
class RBTree {
public:
	RBTree();
	bool Find(T x, Node<T>**& p, Node<T>**& parent);
	bool Insert(T x);
	bool Remove(T x);

	void LeftRotate(Node<T>**& p);
	void RightRotate(Node<T>**& p);
	void InsertFixUp(Node<T>** p);
	Node<T>** GetSuccessor(Node<T>** q);

private:
	Node<T>* root;
};

template <class T>
RBTree<T>::RBTree() {
	root = nullptr;
}

template <class T>
bool RBTree<T>::Find(T x, Node<T>**& p, Node<T>**& parent) {
	*p = root;
	*parent = nullptr;
	while (*p != nullptr && (*p)->value != x) {
		parent = p;
		p = &((*p)->nodes[(*p)->value < x]);
	}

	return *p;
}

template <class T>
bool RBTree<T>::Insert(T x) {
	Node<T>** p, **parent;
	
	if (Find(x, p, parent))
		return 0;

	*p = new Node<T>(x, parent);

	InsertFixUp(p);

	return 1;
}

template <class T>
void RBTree<T>::InsertFixUp(Node<T>** p) {
	Node<T>* parent = nullptr;
	Node<T>* grandParent = nullptr;
	Node<T>* uncle = nullptr;

	// Caso 0
	if (*p == root) {
		root->color = 0;
		return;
	}

	parent = (*p)->parent;
	grandParent = parent->parent;
	uncle = grandParent->nodes[grandParent->nodes[0] == parent]
	/*
	if (grandParent->nodes[0] == parent) uncle = grandParent->nodes[1];
	else uncle = grandParent->nodes[0];
	*/

	// Caso 1
	if (uncle->color == 1) {
		parent->color = !(parent->color);
		grandParent->color = !(grandParent->color);
		uncle->color = !(uncle->color);
	}

	// Caso 2
	if (uncle->color == 0 && ) {

	}

	while (*p != root && (*p)->color == 1) {

	}

}

template <class T>
bool RBTree<T>::Remove(T x) { //FALTA IMPLEMENTAR PARA RBTREE
	Node<T>** p;
	if (!Find(x, p))
		return 0;
	if ((*p)->nodes[0] && (*p)->nodes[1]) {
		Node<T>** q = GetSuccessor(p);
		(*p)->value = (*q)->value;
		p = q;
	}
	Node<T>** t = p;
	*p = (*p)->nodes[(*p)->nodes[0] == 0];
	delete t;
	return 1;
}

template <class T>
void RBTree<T>::LeftRotate(Node<T>**& p){
	Node<T>** t = p;
	p = &((*p)->nodes[1]);
	(*p)->parent = (*t)->parent;

	(*t)->nodes[1] = (*p)->nodes[0];
	((*t)->nodes[1])->parent = *t;

	(*p)->nodes[0] = *t;
	(*t)->parent = *p;
}

template <class T>
void RBTree<T>::RightRotate(Node<T>**& p) {
	Node<T>** t = p;
	p = &((*p)->nodes[0]);
	(*p)->parent = (*t)->parent;

	(*t)->nodes[0] = (*p)->nodes[1];
	((*t)->nodes[0])->parent = *t;

	(*p)->nodes[1] = *t;
	(*t)->parent = *p;
}

template <class T>
Node<T>** RBTree<T>::GetSuccessor(Node<T>** q) {
	bool side = 1;	// menor más cercano = 0		(left)
					// mayor más cercano = 1		(right)
	q = &((*q)->nodes[side]);
	side = !side;
	while ((*q)->nodes[side])
		q = &((*q)->nodes[side]);
	return q;
}

///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

int main() {
	RBTree<int> t;

	t.Insert(50); t.Insert(30); t.Insert(60);
	t.Insert(80); t.Insert(55); t.Insert(11);
	t.Insert(33); t.Insert(5); t.Insert(14);
	t.Insert(31); t.Insert(48);

	return 0;
}