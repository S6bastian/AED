#include <iostream>
using namespace std;

template<class T>
struct CNode{
    CNode<T>* next;
    T v;
    CNode(T x){
        v = x;
        next = nullptr;
    }
};

template<class T>
class CList{
    CNode<T>* head;
public:
    CList();
    ~CList();
    bool Find(T x, CNode<T>** &p);
    bool Insert(T x);
    bool Remove(T x);
};

template<class T>
CList<T>::CList(){
    head = nullptr;
}

template<class T>
CList<T>::~CList(){
    for(CNode<T>* t = head; head; t = head){
        head = head->next;
        delete t;
    }
}

template<class T>
bool CList<T>::Find(T x, CNode<T>** &p){
    for (p = &head; *p && (*p)->v < x; p = &((*p)->next))
    
    return *p && (*p)->v == x;
}

template<class T>
bool CList<T>::Insert(T x){
    CNode<T>** p;
    
    if(Find(x,p))
        return false;
    
    CNode<T>* t = new CNode(x);
    t->next = *p;
    *p = t;

    return true;
}

template<class T>
bool CList<T>::Remove(T x){
    CNode<T>** p;

    if(!Find(x,p))
        return false;

    CNode<T>* t = *p;
    *p = t->next;
    delete t;
    return 1;
}



int main(){
    CList<int> List;
    
    //Insert
    for(int i = 0; i < 17; i++){
        List.Insert(i);
    }

    //Remove
    for(int i = 1; i < 17; i+=2){
        List.Remove(i);
    }

   return 0; 
}