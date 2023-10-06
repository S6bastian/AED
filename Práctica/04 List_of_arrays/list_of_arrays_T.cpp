#include <iostream>
using namespace std;

template<class T, int size_parameter = 5>
struct Node{
    T array[size_parameter];
    int size = size_parameter;
    Node<T>* next;

    Node(Node<T>* n = nullptr){
        next = nullptr;
    }
    T* EndOfArray(){
        return array + size - 1;
    }
};

template<class T>
class List{
    Node<T>* head;
    T* pia; //pointer inside array 


public:
    List();
    ~List();
    bool Find(T x, Node<T>** &pn, T* &pa);
    bool Add(T x);
    bool Remove(T x);
    void Displace(T* start, T* end);
};

template<class T>
List<T>::List(){
    head = nullptr;
    pia = nullptr;
}

template<class T>
bool List<T>::Find(T x, Node<T>** &pn, T* &pa){
    for(*pn = &head, pa = (*pn)->array; *pn && *pa < x; (pa == (*pn)->array + (*pn)->size - 1) ? pn = &((*pn)->next) : pa++);

    return *pn && *pa == x; 
}

template<class T>
bool List<T>::Add(T x){
    Node<T>** pn; //pointer to node
    T* pa; //pointer to array
    if(Find(x,pn,pa))
        return false;
    
    if(head == nullptr || pia == (*pn)->EndOfArray()){
        head = new Node(head);
        pia = *pn ? (*pn)->array : head->array; 
    }
    else{
        pia++;
    }
//Continuar
    for(T t; pa <= pia; pa == (*pn)->EndOfArray ? ;)

}

template<class T>
void List<T>::Displace(T* start, T* end){
    T* tp = start;
    T t = *tp;

    t--;
    if
}

int main(){

    
    return 0;
}