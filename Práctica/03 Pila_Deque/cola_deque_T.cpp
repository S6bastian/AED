#include <iostream>
using namespace std;

template<class T, int size_parameter = 5>
struct nodo{
	int size = sizeparameter;
	T array[size parameter];
	T* tia;
	nodo<T>* next;
	nodo(nodo<T>* n = nullptr){
		next = n;
		tia = array;
	}
};

template<class T>
class cola {
	nodo<T>* head = nullptr;
	nodo<T>* tail = nullptr;
public:
	void push(T v);
	T pop();
	nodo<T>* getHead(){
		return head;
	}
	nodo<T>* getTail(){
		return tail;
	}
};

template<class T>
void cola<T>::push(T v){
	if (tia == array + size - 1){
		tail->next = new nodo();
		tail = tail->next;
	}
	else if(head == nullptr){
		head = new nodo(head);
		tail = head;
	}
	*(tail->tia) = v;
}

template<class T>
T cola<T>::pop(){
	T tmp = 0;
	
	if(head->tia == array + size - 1){
		nodo<T>* aux = head;
		tmp = *(head->tia);
		head = head->next;
		delete aux;
		if (head == nullptr){
			tail = nullptr;
		}
	}
	else{
		tmp = *(head->tia);
	}
	return tmp;
}