#include <iostream>
using namespace std;

template<class T, int size_parameter = 5>
struct nodo{
	int size = size_parameter;
	T array[size_parameter];
	T* hia; //head in array
	T* tia; //tail in array
	nodo<T>* next;
	nodo(nodo<T>* n = nullptr){
		next = n;
		hia = tia = array;
	}
};

template<class T>
class cola {
	nodo<T>* head = nullptr;
	nodo<T>* tail = nullptr;
public:
	void push(T v);
	T pop();
	void print();
	nodo<T>* getHead(){
		return head;
	}
	nodo<T>* getTail(){
		return tail;
	}
};

template<class T>
void cola<T>::push(T v){
	//Movimiento del puntero 
	if(head == nullptr){
		head = new nodo<T>();
		tail = head;
	}
	else if(tail->tia == tail->array + tail->size - 1){
		tail->next = new nodo<T>();
		tail = tail->next;
	}
	else{
		tail->tia++;
	}

	*(tail->tia) = v;	
}

template<class T>
T cola<T>::pop(){
	T tmp = 0;
	
	if(head != nullptr){
		if(head->hia == head->tia){
			nodo<T>* aux = head;
			tmp = *(head->hia);
			head = head->next;
			delete aux;
			if (head == nullptr){
				tail = nullptr;
			}
		}
		else{
			tmp = *(head->hia);
			head->hia++;
		}
	}
	return tmp;
}

template<class T>
void cola<T>::print(){
	nodo<T>* cNodo = head; //current nodo
	T* cHia = cNodo->hia; //current hia
	cout<<"----> ||";

	while(1){
		cout<<" "<<*cHia;

		if(cHia == tail->tia){
			break;
		}
		else if(cHia == cNodo->tia){
			cNodo = cNodo->next;
			cHia = cNodo->hia;
			cout<<" || ----> ||";
		}
		else{
			cHia++;
		}
	}
	cout<<" ||"<<endl;
}

int main(){
	int size = 27;
	cola<int> C;

	//Creación de cola
	for(int i = 0; i < size; i++){
		C.push(i);
	}

	C.print();

	//Destrucción de cola
	cout<<"Popped elements:";
	for(int i = 0; i < 13; i++){
		cout<<" "<<C.pop();
	}
	cout<<endl;

	C.print();
	
	return 0;
}