#include <iostream>
using namespace std;

template<class T, int size_parameter = 5>
struct Node {
    T array[size_parameter];
    int size = size_parameter;
    Node<T>* next;

    Node(Node<T>* n = nullptr) {
        next = nullptr;
    }
    T* EndOfArray() {
        return array + size - 1;
    }
};

template<class T>
class List {
    Node<T>* head;
    T* pia; //pointer inside array 


public:
    List();
    //~List();
    bool Find(T x, Node<T>**& pn, T*& pa);
    bool Add(T x);
    bool Remove(T x);
    void Print();
};

template<class T>
List<T>::List() {
    head = nullptr;
    pia = nullptr;
}

template<class T>
bool List<T>::Find(T x, Node<T>**& pn, T*& pa) {
    pn = &head;
    pa = (*pn)->array;
    while (*pn && *pa < x) {
        if (pa == pia)
            break;
        if (pa == (*pn)->EndOfArray()) {
            pn = &((*pn)->next);
            pa = (*pn)->array;
        }
        else {
            pa++;
        }
    }

    return *pn && *pa == x;
}

template<class T>
bool List<T>::Add(T x) {
    Node<T>** pn = nullptr; //pointer to node
    T* pa = nullptr; //pointer to array

    if (head == nullptr) {
        head = new Node<T>(head);
        pia = head->array;
        *pia = x;
    }
    else {
        if (Find(x, pn, pa))
            return false;

        //Aumento de pia
        if (pia == (*pn)->EndOfArray()) {
            (*pn)->next = new Node<T>();
            pn = &((*pn)->next);
            pia = (*pn)->array;
        }
        else {
            pia++;
        }

        //Añadimiento de elemento
        if (x > *pa) {
            *pia = x;
        }
        else {
            T t0, t1;
            t0 = x;
            while (1) {
                t1 = *pa;
                *pa = t0;
                t0 = t1;
                //pa == (*pn)->EndOfArray() ? pn = &((*pn)->next), pa = (*pn)->array : pa++; REVISAR
                if (pa == pia)
                    break;
                else if (pa == (*pn)->EndOfArray() && pa != pia) {
                    pn = &((*pn)->next);
                    pa = (*pn)->array;
                }
                else if(pa != pia)
                    pa++;

            }
        }
    }

    return true;
}

template<class T>
void List<T>::Print() {
    Node<T>* pn = head;
    T* pa = head->array;

    cout << "HEAD ---> ||";
    while (pn) {
        cout << " " << *pa;
        if (pa == pn->EndOfArray()) {
            pn = pn->next;
            pa = pn->array;
        }
        else if (pa == pia)
            break;
        else if (pa == pn->EndOfArray()) {
            cout << " || ---> ||";
        }
        else
            pa++;

        
    }
    cout << " ||" << endl;
}

int main() {
    List<int> L;

    for (int i = 0; i < 10; i+=2)
        L.Add(i);
    L.Add(5);

    L.Print();

    return 0;
}