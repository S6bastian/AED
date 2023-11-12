//Recorridos en profundidad utilizando recursividad de C++: inorder, preorder, posorder, reverse

#include <iostream>
using namespace std;

template <class T>
struct Node {
	T value;
	Node<T>* nodes[2];
	Node(T v) {
		value = v;
		nodes[0] = nodes[1] = nullptr;
	}
};

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

template <class T>
class BinTree {
public:
	BinTree();
	bool Find(T x, Node<T>**& p);
	bool Insert(T x);
	bool Remove(T x);
	
	void InOrder(Node<T>* n, bool d = 0);		// Puede efectuar tanto InOrder como Reverse (d = 0 o d = 1) respectivamente
	void PreOrder(Node<T>* n, bool d = 0);
	void PosOrder(Node<T>* n, bool d = 0);
	void Reverse(Node<T>* n, bool d = 1);		// Misma implementación que InOrder
	void Print();
	void Print(int opt);
	
private:
	Node<T>* root;
	Node<T>** getSuccessor(Node<T>** q);
};

template <class T>
BinTree<T>::BinTree() {
	root = nullptr;
}

template <class T>
bool BinTree<T>::Find(T x, Node<T>**& p) {
	p = &root;
	while (*p != nullptr && (*p)->value != x) {
		p = &((*p)->nodes[(*p)->value < x]);
	}
	return *p;
}

template <class T>
bool BinTree<T>::Insert(T x) {
	Node<T>** p;
	if (Find(x, p))
		return 0;

	*p = new Node<T>(x);
	return 1;
}

template <class T>
bool BinTree<T>::Remove(T x) {
	Node<T>** p;
	if (!Find(x, p))
		return 0;

	if ((*p)->nodes[0] && (*p)->nodes[1]) {
		Node<T>** q = getSuccessor(p);
		(*p)->value = (*q)->value;
		p = q;
	}
	Node<T>* t = *p;
	if ((*p)->nodes[1]) {
		p = &((*p)->nodes[1]);
	}
	else {
		p = &((*p)->nodes[0]);
	}
	delete* t;
	return 1;
}

template <class T>
Node<T>** BinTree<T>::getSuccessor(Node<T>** q) {
	q = &((*q)->nodes[1]);
	while ((*q)->nodes[0] != nullptr) {
		q = &((*q)->nodes[0]);
	}
	return q;
}

template <class T>
void BinTree<T>::InOrder(Node<T>* n, bool d) {
	//	d = 0	ascendente
	//	d = 1	descendente
	if (!n) return;
	InOrder(n->nodes[d]);
	cout << n->value << " ";
	InOrder(n->nodes[!d]);
}

template <class T>
void BinTree<T>::PreOrder(Node<T>* n, bool d) {
	//	d = 0	ascendente
	//	d = 1	descendente
	if (!n) return;
	cout << n->value << " ";
	PreOrder(n->nodes[d]);
	PreOrder(n->nodes[!d]);
}

template <class T>
void BinTree<T>::PosOrder(Node<T>* n, bool d) {
	//	d = 0	ascendente
	//	d = 1	descendente
	if (!n) return;
	PosOrder(n->nodes[d]);
	PosOrder(n->nodes[!d]);
	cout << n->value << " ";
}

template <class T>
void BinTree<T>::Reverse(Node<T>* n, bool d) {
	//	d = 0	ascendente
	//	d = 1	descendente
	if (!n) return;
	Reverse(n->nodes[d]);
	cout << n->value << " ";
	Reverse(n->nodes[!d]);
}

template <class T>
void BinTree<T>::Print() {
	cout << "Codigos de impresion\n"
		<< "1. InOrder()\n"
		<< "2. PreOrder()\n"
		<< "3. Posrder()\n"
		<< "4. Reverse()\n\n\n";
}


template <class T>
void BinTree<T>::Print(int opt) {
	switch (opt) {
	case 1:
		cout << "1. InOrder()\n";
		InOrder(root);
		break;
	case 2:
		cout << "2. PreOrder()\n";
		PreOrder(root);
		break;
	case 3:
		cout << "3. PosOrder()\n";
		PosOrder(root);
		break;
	case 4:
		cout << "4. Reverse()\n";
		Reverse(root);
		break;
	default:
		cout << "Codigo no admitido" << endl;
		break;
	}
	cout << endl;
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////



int main() {
	BinTree<int> A;
	A.Insert(0);
	A.Insert(-4);
	A.Insert(7);
	A.Insert(-10);
	A.Insert(-1);
	A.Insert(15);
	A.Insert(20);
	A.Insert(35);
	A.Insert(9);

	A.Print();

	A.Print(1);
	A.Print(2);
	A.Print(3);
	A.Print(4);

	return 0;
}
