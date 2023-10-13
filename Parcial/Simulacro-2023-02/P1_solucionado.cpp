#include <iostream>
using namespace std;

template <class T>
struct Node {
    Node* next = nullptr;
    T val;

    Node(T v) {
        this->val = v;
    }
};


template <class T>
class LinkedList {
public:
    Node<T>* head = nullptr;

    LinkedList() {}

    ~LinkedList() {
        while (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void push_back(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node<T>* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void print() {
        Node<T>* current = head;
        while (current) {
            cout << current->val << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }

    void reverse() {

        // TO DO:
        // Se debe terminar con la lista actual en reversa
        // No se puede crear nodos adicionales

        /* SOLUCION 1
        Node<T>* current = head;
        Node<T>* stop = nullptr;
        T temp;

        if (current->next == stop || head == nullptr)
            return;

        while (1) {
            if (current->next == stop) {
                if (current == head)
                    return;

                stop = current;
                current = head;
            }

            else {
                temp = current->val;
                current->val = current->next->val;
                current = current->next;
                current->val = temp;
            }
        }
        */

        /*SOLUCION 2*/

        Node<T>* current;
        Node<T>* forward;

        if (head == nullptr || head->next == nullptr)
            return;

        current = head->next;
        forward = current->next;
        head->next = nullptr;

        while (1) {
            current->next = head;
            head = current;
            current = forward;
            forward = forward == nullptr ? nullptr : forward->next;
            if (current == nullptr)
                return;
        }

    }

    void merge(LinkedList<T>& list2) {

        // TO DO: 
        // Se debe terminar con la lista actual ordenada y la lista pasada por referencia vacia
        // No se puede crear nodos adicionales

        Node<T>* current1 = head;
        Node<T>* current2 = list2.head;
        Node<T>* t;

        while (current1 != nullptr && current2 != nullptr) {

            if (current1->next == nullptr) {
                //if(current)
                current1->next == current2->next;
                current1 = nullptr;
            }

            else if (current2->next == nullptr) {
                current2->next == current1->next;
                current2 = nullptr;
            }
            else {
                if (current1->val < current2->val) {
                    if (current1->next->val > current2->val) {
                        t = current1->next;
                        current1->next = current2;
                        current1 = t;
                    }
                    else
                        current1 = current1->next;
                }
                else {
                    if (current2->next->val > current1->val) {
                        t = current2->next;
                        current2->next = current1;
                        if (current2->next == head) {
                            head = current2;
                        }
                        current2 = t;
                    }
                    else
                        current2 = current2->next;
                }
            }
            

        }


    }
};

int main() {

    // REVERSE TEST

    LinkedList<int> list1;
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);

    LinkedList<int> list2;
    list2.push_back(4);

    LinkedList<int> list3;
    list3.push_back(13);
    list3.push_back(11);
    list3.push_back(9);
    list3.push_back(20);
    list3.push_back(50);
    list3.push_back(100);


    cout << "REVERSE TEST:\n\n";

    cout << "Original List1: ";
    list1.print();
    cout << "Original List2: ";
    list2.print();
    cout << "Original List3: ";
    list3.print();

    cout << endl;

    // Test case 1: Reverse list1
    list1.reverse();
    cout << "Reversed list1: \n";
    list1.print();

    // Test case 2: Reverse list2
    list2.reverse();
    cout << "Reversed list2: \n";
    list2.print();

    // Test case 3: Reverse list3
    list3.reverse();
    cout << "Reversed list3: \n";
    list3.print();

    cout << endl << endl;

    // ---------------------------------

    LinkedList<int> list4;
    list4.push_back(0);
    list4.push_back(2);
    list4.push_back(95);
    list4.push_back(101);
    list4.push_back(150);

    LinkedList<int> list5;
    list5.push_back(-4);
    list5.push_back(7);
    list5.push_back(15);
    list5.push_back(78);
    list5.push_back(100);

    LinkedList<int> list6;
    list6.push_back(500);
    list6.push_back(600);

    LinkedList<int> list7; // Empty list

    cout << "MERGE TEST:\n\n";

    cout << "Original list4: ";
    list4.print();
    cout << "Original list5: ";
    list5.print();
    cout << "Original list6: ";
    list6.print();

    cout << endl;

    // Test case 1:
    list4.merge(list5); // list5 debe acabar vacia!
    cout << "Merged list4: " << endl;
    list4.print();
    cout << "Empty list5: " << endl;
    list5.print();

    cout << endl;

    // Test case 2:
    list4.merge(list6); // list6 debe acabar vacia!
    cout << "Merged list4: " << endl;
    list4.print();
    cout << "Empty list6: " << endl;
    list6.print();

    cout << endl;

    // Test case 3:
    list4.merge(list7); // list7 debe acabar vacia!
    cout << "Merged list4: " << endl;
    list4.print();
    cout << "Empty list7: " << endl;
    list7.print();

    cout << endl;

    return 0;
}