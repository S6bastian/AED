#include <iostream>
using namespace std;

template<class T, int size = 5>
struct nodo{
    T valor;
    T* tia; //top inside array
    T array[size];
    nodo<T>* next;
    nodo(T v, nodo<T>* n = nullptr){
        valor = v;
        next = n;
        tia = array;
    }
};

template<class T>
class pila{
    nodo<T>* top = nullptr; 
public:
    void push(T v);
    T pop();
};

template<class T>
void pila<T>::push(T v){
    if(top == nullptr || top->tia-4 == top->array){
        top = new nodo(v, top);
        *(top->tia) = v;
    }
    
    else{
        top->tia++;
        *(top->tia) = v;
    }
    /*
    cout<<top<<endl;
    cout<<top->tia<<endl;
    cout<<top->array<<endl;
    */
}

template<class T>
T pila<T>::pop(){
    T tmp = 0;
    if(top->tia == top->array){
        nodo<T>* aux = top;
        tmp = *(top->tia);
        top = top->next;
        delete aux;
    }
    else{
        tmp = *(top->tia--);
    }

    return tmp;
}

int main(){
    pila<int> P;

    for(int i = 0; i < 6; i++){
        P.push(i);
    }
    cout<<P.pop();
    
    return 0;
}