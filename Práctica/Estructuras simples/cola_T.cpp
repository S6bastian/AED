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
class cola{
    nodo<T>* head = nullptr;
    nodo<T>* tail = nullptr;
public:
    void push(T v);
    T pop();
    bool vacio(){
        return !head;
    }
};

template<class T>
void cola<T> :: push(T v){
    if(head != nullptr){
        tail->next = new nodo(v);
        tail=tail->next;
    }
    else{
        head = tail = new nodo(v);
    }
}

template<class T>
T cola<T> :: pop(){
    T tmp = 0;
    if(head){
        if(head != tail){
            nodo<T>* aux = head;
            tmp = head->valor;
            head = head->next;
            delete aux;
        }
        else{
            nodo<T>* aux = head;
            tmp = head->valor;
            head = tail = nullptr;
            delete aux;
        }
    }
    return tmp;
}

int main(){
    cola<int> C;

    cout<<"Push:";
    for(int i = 0; i < 10; i++){
        C.push(i);
        cout<<" "<<i;
    }
    cout<<endl;

    cout<<"Pop:";
    while(!C.vacio()){
        cout<<" "<<C.pop();
    }
    cout<<endl;
    
    return 0;
}