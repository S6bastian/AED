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
class pila{
    nodo<T>* top = nullptr;
    T* tia = nullptr; //top inside array
public:
    void push(T v);
    T pop();
    void print();
};

template<class T>
void pila<T>::push(T v){
    if(top == nullptr || tia == top->array + top->size - 1){ //Creación de una pila nueva o cuando se acaba el espacio en array
        top = new nodo<T>(top);
        tia = top->array;
    }
    else{
        tia++;
    }
    *(tia) = v;
}

template<class T>
T pila<T>::pop(){
    T tmp = 0;
    if(tia == top->array){
        nodo<T>* aux = top;
        tmp = *(tia);
        top = top->next;
        tia = top->array + top->size - 1;
        delete aux;
    }
    else{
        tmp = *(tia--);
    }

    return tmp;
}


template<class T>
void pila<T>::print(){
    nodo<T>* cNodo = top;
    T* cTia = tia;

    if(!(cTia == cNodo->array + cNodo->size - 1)){
        cout<<" -----> "<<"||";
    }

    while(1){
        if(cTia == cNodo->array + cNodo->size - 1){
            cout<<" -----> "<<"||";
        }

        cout<<" "<<*(cTia);

        if(cTia == cNodo->array){
            cout<<" "<<"||";
            if(cNodo->next == nullptr){
                cout<<endl;
                break;
            }
            else{
                cNodo = cNodo->next;
                cTia = cNodo->array + cNodo->size -1;
            }
        }
        else{
            cTia--;
        }
    }
    cout<<endl;
}


int main(){
    pila<int> P;
    int size = 53;
    // Creación de Pila
    for(int i = 0; i < size; i++){
        P.push(i);
    }

    P.print();
    
    // Destrucción 
    cout<<"Popped elements:";
    for(int i = 0; i < 25; i++){
        cout<<" "<<P.pop();
    }
    cout<<endl<<endl;

    P.print();
    
    return 0;
}
