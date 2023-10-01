#include <iostream>
using namespace std;

template<class T>
struct CNode{
    CNode* next;
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
    CList(){
        head = nullptr;
    }
    bool find(T x, CNode<T>** &p);
    bool insert(T x);
    bool remove(T x);
};

template<class T>
bool CList<T> :: find(T x, CNode<T>** &p){
    for (p = &head; *p && (*p)->v <x; p = &((*p)->next))
    
    return *p && (*p)->v == x;
}

template<class T>
bool CList