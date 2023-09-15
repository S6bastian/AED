#include <iostream>
using namespace std;

template<class T, int size_parameter = 5>
struct nodo{
    int size = size_parameter;
    T* tia; //top inside array
    T array[size_parameter];
    nodo<T>* next;
    nodo(nodo<T>* n = nullptr){
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
    nodo<T>* getTop() const{
        return top;
    }
};

template<class T>
void pila<T>::push(T v){
    if(top == nullptr || top->tia == top->array+(top->size)-1){ //Creación de una pila nueva o cuando se acaba el espacio en array
        top = new nodo(top);
        *(top->tia) = v;
    }
    else{
        top->tia++;
        *(top->tia) = v;
    }
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


template<class T>
void print(const pila<T>& P){
    nodo<T>* currentTop = P.getTop();
    T* currentTia = currentTop->tia;
    //currentTia = currentTop->array+currentTop->size-1; // en caso de mostrar los array completos
    if(!(currentTia == currentTop->array+currentTop->size-1)){
        cout<<" -----> "<<"||";
    }

    while(1){
        if(currentTia == currentTop->array+currentTop->size-1){
            cout<<" -----> "<<"||";
        }
        cout<<" "<<*(currentTia);
        if(currentTia == currentTop->array){
            cout<<" "<<"||";
            if(currentTop->next == nullptr && currentTia == currentTop->array){
                cout<<endl;
                break;
            }
            else{
                currentTop = currentTop->next;
                currentTia = currentTop->tia;
            }
        }
        else{
            currentTia--;
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

    print<int>(P);
    
    // Destrucción 
    cout<<"Popped elements:";
    for(int i = 0; i < 25; i++){
        cout<<" "<<P.pop();
    }
    cout<<endl<<endl;

    print<int>(P);
    
    return 0;
}