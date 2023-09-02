#include <iostream>
using namespace std;

struct CP;
struct CLess;
struct CGreater;

void bubble_sort_CLess(int* A, int size, CLess *l);
void swap(int* a, int* b);
void print(int* A, int size);

int main(){
    
    int A[] = {9,5,6,15,2,1,3,7,4,11,14,12,13};
    int size = sizeof(A)/sizeof(int);
    CLess* l;
    CGreater* g;  

    int* pA = A;
    print(A, size);
    bubble_sort_CLess(A, size, l);
    print(A, size);


    return 0;
}

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
        print(A, size);
        for(int j = 0; j < size - 1; j++){
            if(l->cmp(A[j+1], A[j])){
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