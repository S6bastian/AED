#include <iostream>
using namespace std;

template<class T, int size_parameter = 5>
struct nodo{
	int size = size_parameter;
	T array[size_parameter];
	
	nodo<T>* next;
	nodo(nodo<T>* n = nullptr){
		next = n;
	}
};

template<class T>
class cola {
	nodo<T>* head = nullptr;
	nodo<T>* tail = nullptr;
	T* hia = nullptr; //head in array
	T* tia = nullptr; //tail in array
public:
	void push(T v);
	T pop();
	void print();
};

template<class T>
void cola<T>::push(T v){
 	if(head == nullptr){
		head = new nodo<T>();
		tail = head;
		hia = head->array;
		tia = head->array;
	}
	else if(tia == tail->array + tail->size - 1){
		tail->next = new nodo<T>();
		tail = tail->next;
		tia = tail->array;
	}
	else{
		tia++;
	}

	*(tia) = v;	
}

template<class T>
T cola<T>::pop(){
	T tmp = 0;
	
	if(head != nullptr){
		if(hia == head->array + head->size - 1){
			nodo<T>* aux = head;
			tmp = *(hia);
			head = head->next;
			hia = head->array;
			delete aux;
			if(head == nullptr){
				tail = nullptr;
				hia = tia = nullptr;
			}
		}
		else{
			tmp = *(hia);
			hia++;
		}
	}
	return tmp;
}

template<class T>
void cola<T>::print(){
	nodo<T>* cNodo = head; //current nodo
	T* cHia = hia; //current hia
	cout<<"----> ||";

	while(1){
		cout<<" "<<*cHia;

		if(cHia == tia){
			break;
		}
		else if(cHia == cNodo->array + cNodo->size - 1){
			cNodo = cNodo->next;
			cHia = cNodo->array;
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