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
    bool Find(T x, Node<T>**& pn, T*& pa, Node<T>**& bpn);
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
bool List<T>::Find(T x, Node<T>**& pn, T*& pa, Node<T>**& bpn) {
    pn = &head;
    pa = (*pn)->array;
    while (*pn && *pa < x) {
        if (pa == pia)
            break;
        if (pa == (*pn)->EndOfArray()) {
            bpn = pn;
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
    Node<T>** bpn = nullptr; //before pointer to node
    T* pa = nullptr; //pointer to array

    if (head == nullptr) {
        head = new Node<T>(head);
        pia = head->array;
        *pia = x;
    }
    else {
        if (Find(x, pn, pa, bpn))
            return false;

        //Movimiento y añadimiento de elemento en pia
        if (x > *pa) {
            if (pia == (*pn)->EndOfArray()) {
                (*pn)->next = new Node<T>();
                pn = &((*pn)->next);
                pia = (*pn)->array;
            }
            else {
                pia++;
            }

            *pia = x;
        }
        else {
            T t0, t1;
            t0 = x;
            while (1) {
                t1 = *pa;
                *pa = t0;
                t0 = t1;

                if (pa == pia) {
                    if (pia == (*pn)->EndOfArray()) {
                        (*pn)->next = new Node<T>();
                        pn = &((*pn)->next);
                        pia = (*pn)->array;
                    }
                    else {
                        pia++;
                    }

                    t1 = *pia;
                    *pia = t0;
                    t0 = t1;

                    break;
                }
                else if (pa == (*pn)->EndOfArray()) {
                    pn = &((*pn)->next);
                    pa = (*pn)->array;
                }
                else
                    pa++;
            }
        }
    }

    return true;
}

template<class T>
bool List<T>::Remove(T x) {
    Node<T>** pn = nullptr; //pointer to node
    Node<T>** bpn = nullptr; //before pointer to node
    T* pa = nullptr; //pointer to array

    if (head == nullptr) {
        cout << "Lista vacia" << endl;
        return false;
    }
    if (!Find(x, pn, pa, bpn)) {
        return false;
    }
    else {
        T* t = pa;
        
        if (*pia == x) {
            if (pia == (*pn)->array) {
                if (*pn == head) {
                    delete* pn;
                    head = nullptr;
                    pia = nullptr;
                }
                else {
                    delete* pn;
                    pia = (*bpn)->EndOfArray();
                    //(*bpn)->next = nullptr;
                }
            }
            else
                pia--;

            return true;
        }
        else {
            while (1) {
                //Aumento de pa
                if (pa == (*pn)->EndOfArray()) {
                    pn = &((*pn)->next);
                    pa = (*pn)->array;
                }
                else
                    pa++;

                *t = *pa;
                if (pa == pia) {
                    if (pia == (*pn)->array)
                        delete (*pn);
                    pia = t;
                    return true;
                }
                else
                    t = pa;
            }
        }
    }
}

template<class T>
void List<T>::Print() {
    Node<T>* pn = head;
    T* pa = head->array;

    cout << "HEAD ---> ||";
    while (pn) {
        cout << " " << *pa;
        if (pa == pia)
            break;

        if (pa == pn->EndOfArray()) {
            pn = pn->next;
            pa = pn->array;
            cout << " || ---> ||";
        }
        else
            pa++;
    }
    cout << " || ---> NULLPTR" << endl;
}

int main() {
    List<int> L;

    cout << "PRUEBAS ADD" << endl;
    for (int i = 0; i < 23; i+=2)
        L.Add(i);
    L.Print();
    for (int i = 0; i < 25; i += 3)
        L.Add(i);
    L.Print();
    L.Add(5);
    L.Print();

    cout <<endl<< "PRUEBAS REMOVE" << endl;
    for (int i = 0; i < 23; i += 2)
        L.Remove(i);
    L.Print();
    for (int i = 0; i < 25; i += 3)
        L.Remove(i);
    L.Print();
    L.Remove(5);
    L.Print();

    return 0;
}