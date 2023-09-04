#include <iostream>
using namespace std;

template<class T>
struct Node{
    T value;
    Node<T>* next;
    Node<T>* prev;
    Node(T v, Node<T>* n = nullptr, Node<T>* p = nullptr){
        value = v;
        next = n;
        prev = p;
    }
};

template<class T>
struct List{
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;

    void push_back(T v);
    void push_front(T v);
    T pop_back();
    T pop_front();
    bool empty(){
        return !head;
    }
};

template<class T>
void List<T> :: push_back(T v){
    if(head == nullptr){
        head = tail = new Node(v);
    }
    else{
        tail->next = new Node(v, tail->next, tail);
        tail = tail->next;
    }
}

template<class T>
void List<T> :: push_front(T v){
    if(head == nullptr){
        head = tail = new Node(v);
    }
    else{
        head->prev = new Node(v, head);
        head = head->prev;
    }
}

template<class T>
T List<T> :: pop_back(){
    T tmp = 0;
    if(head){
        if(head != tail){
            Node<T>* aux = tail;
            tmp = tail->value;
            tail = tail->prev;
            tail->next = nullptr;
            delete aux;
        }
        else{
            Node<T>* aux = tail;
            tmp = tail->value;
            head = tail = nullptr;
            delete aux;
        }
    }
    return tmp;
}

template<class T>
T List<T> :: pop_front(){
    T tmp = 0;
    if(head){
        if(head != tail){
            Node<T>* aux = head;
            tmp = head->value;
            head = head->next;
            head->prev = nullptr;
            delete aux;
        }
        else{
            Node<T>* aux = head;
            tmp = head->value;
            head = tail = nullptr;
            delete aux;
        }
    }
    return tmp;
}

int main(){
    List<int> L;
    List<int> M;
    for(int i = 0; i < 5; i++){
        L.push_back(i);
        M.push_front(i+5);
    }

    cout<<"pop_back:";
    while(!L.empty()){
        cout<<" "<<L.pop_back();
    }
    cout<<endl;

    cout<<"pop_front:";
    while(!M.empty()){
        cout<<" "<<M.pop_front();
    }
    cout<<endl;
}