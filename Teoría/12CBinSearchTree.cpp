#include <iostream>
using namespace std;


template <class T>
struct Node {
	T value;
	T *left, *right;
	Node(T v){
		left = right = nullptr;
	}
};

template <class T>
class BinTree {
public:
	BinTree();
	bool Find(T x, Node<T>** &p);
	bool Insert(T x);
	bool Remove(T x);

private:
	Node<T>* root;
	Node<T>** getSuccessor(Node<T>** q);
};

template <class T>
BinTree<T>::BinTree() {
	root = nullptr;
}

template <class T>
bool BinTree<T>::Find(T x, Node<T>** &p) {
	p = &root;
	while (*p != nullptr && (*p)->value != x) {
		p = &((*p)->value < x ? (*p)->right : (*p)->left);
	}
	return *p;
}

template <class T>
bool BinTree<T>::Insert(T x) {
	Node<T>** p;
	if(Find(x, p))
		return 0;

	*p = new Node<T>(x);
	return 1;
}

template <class T>
bool BinTree<T>::Remove(T x) {
	Node<T>** p;
	if (!Find(x, p))
		return 0;

	if ((*p)->left && (*p)->right) {
		Node<T>** q = getSuccessor(p);
		(*p)->value = (*q)->value;
		p = q;
	}
	Node<T>* t = *p;
	if ((*p)->right) {
		p = &((*p)->right);
	}
	else {
		p = &((*p)->left);
	}
	delete* t;
	return 1;
}

template <class T>
Node<T>** BinTree<T>::getSuccessor(Node<T>** q) {
	q = &((*q)->right);
	while ((*q)->left != nullptr) {
		q = &((*q)->left);
	}
	return q;
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

int main() {
	return 0;
}