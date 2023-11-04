#include <iostream>
using namespace std;

template <class T>
struct Node {
	T value;
	Node* nodes[2];
	Node* parent;
	bool color; // 0 -> black and 1 -> red

	Node(T v, *p = nullptr) {
		value = v;
		nodes[0] = nodes[1] = 0;
		color = 1;		// always red when its created
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

	void leftRotate(Node<T>**& p);
	void rightRotate(Node<T>**& p);
	void insertFixUp(Node<T>** p);
	Node<T>** getSuccessor(Node<T>** q);

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

	insertFixUp(p);

	return 1;
}

template <class T>
void RBTree<T>::insertFixUp(Node<T>** p) {
	Node<T>* parent = nullptr;
	Node<T>* grandParent = nullptr;

	while (*p != root && (*p)->color == 1) {

	}

	// Case 0
	
}

template <class T>
bool RBTree<T>::Remove(T x) {
	Node<T>** p;
	if (!Find(x, p))
		return 0;
	if ((*p)->nodes[0] && (*p)->nodes[1]) {
		Node<T>** q = getSuccessor(p);
		(*p)->value = (*q)->value;
		p = q;
	}
	Node<T>** t = p;
	*p = (*p)->nodes[(*p)->nodes[0] == 0];
	delete t;
	return 1;
}

template <class T>
void RBTree<T>::leftRotate(Node<T>**& p){
	Node<T>** t = p;
	p = &((*p)->nodes[1]);
	(*p)->parent = (*t)->parent;

	(*t)->nodes[1] = (*p)->nodes[0];
	((*t)->nodes[1])->parent = *t;

	(*p)->nodes[0] = *t;
	(*t)->parent = *p;
}

template <class T>
void RBTree<T>::rightRotate(Node<T>**& p) {
	Node<T>** t = p;
	p = &((*p)->nodes[0]);
	(*p)->parent = (*t)->parent;

	(*t)->nodes[0] = (*p)->nodes[1];
	((*t)->nodes[0])->parent = *t;

	(*p)->nodes[1] = *t;
	(*t)->parent = *p;
}

template <class T>
Node<T>** RBTree<T>::getSuccessor(Node<T>** q) {
	bool side = 1;	// closest smallest = 0		(left)
					// closest largest = 1		(right)
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