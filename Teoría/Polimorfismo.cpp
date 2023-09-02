#include <iostream>
using namespace std;

struct CP;
struct CLess;
struct CGreater;

void bubble_sort_CLess(int* A, int size, CLess *l); //Cambia el comportamiento usando polimorfismo
void bubble_sort_CGreater(int* A, int size, CP *g);
void swap(int* a, int* b);
void print(int* A, int size);

struct CP{
    virtual bool cmp(int a, int b) = 0;
};

struct CLess : CP{
    bool cmp(int a, int b){
        return a < b;
    }
};

struct CGreater : CP{
    bool cmp(int a, int b){
        return a > b;
    }
};

void bubble_sort_CLess(int* A, int size, CLess *l){
    
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - 1; j++){
            if(l->cmp(A[j+1], A[j])){
                swap(A[j], A[j+1]);
            }
        }
    }
    print(A, size);
}

void bubble_sort_CGreater(int* A, int size, CP *g){ //Funciona si ponemos "CP* g" al igual que "CGreater* g"
    
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - 1; j++){
            if(g->cmp(A[j], A[j+1])){
                swap(A[j], A[j+1]);
            }
        }
    }
    print(A, size);
}

void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void print(int* A, int size){
    for(int i = 0; i < size; i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

int main(){
    
    int A[] = {9,5,6,15,2,1,3,7,4,11,14,12,13};
    int B[] = {9,5,6,15,2,1,3,7,4,11,14,12,13};
    int size = sizeof(A)/sizeof(int);
    CLess* l = new CLess; // Si solo ponemos "CLess* l" no funciona
    CGreater* g = new CGreater; // Si solo ponemos "CGreater* g" no funciona

    print(A, size);
    bubble_sort_CLess(A, size, l);
    cout<<endl<<endl;
    print(B, size);
    bubble_sort_CGreater(B, size, g);

    return 0;
}