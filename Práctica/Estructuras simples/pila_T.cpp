#include <iostream>
using namespace std;

template<class T>
struct nodo{
    T valor;
    nodo<T>* next;
    nodo(T v, nodo<T>* n = nullptr){
        valor = v;
        next = n;
    }
};

template<class T>
class pila{
    nodo<T>* top = nullptr;
public:
    void push(T v);
    T pop();
    bool vacio(){
        return !top;
    }
};

template<class T>
void pila<T> :: push(T v){
    top = new nodo(v, top);
}

template<class T>
T pila<T> :: pop(){
    T tmp = 0;
    if(top){
        nodo<T>* aux = top;
        tmp = top->valor;
        top = top->next;
        delete aux;
    }
    return tmp;
}

int main(){
    pila<int> P;

    for(int i = 0; i < 10; i++){
        P.push(i);
    }
    while(!P.vacio()){
        cout<<P.pop()<<endl;
    }
}