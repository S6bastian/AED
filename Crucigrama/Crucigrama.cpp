#include <iostream>
using namespace std;

void search(char[], char[], int, char**, int, int);
void reverse(char*, int);
void swap(char*, char*);

int main()
{
    char word[] = "PATO";
    int wordsize = sizeof(word)-1;
    char reversedword[] = "PATO";
    reverse(reversedword, wordsize);
    
    int filas = 5;
    int columnas = 6;
    char contenido[5][6] = {
        {'A', 'J', 'P', 'A', 'T', 'O'},
        {'M', 'L', 'O', 'T', 'A', 'P'},
        {'N', 'T', 'T', 'H', 'L', 'O'},
        {'K', 'H', 'A', 'T', 'O', 'J'},
        {'T', 'I', 'P', 'O', 'L', 'M'}};

    //Crear _crucigrama_ dinámico
    char** crucigrama = new char* [filas];
    for(char** i = crucigrama; i < crucigrama + filas; i++){
        *i = new char[columnas];
    }

    //Copiar _contenido_ a _crucigrama_
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            *(*(crucigrama + i) + j) = contenido[i][j];
        }
    }

    //Imprimir el contenido copiado
    for(char** i = crucigrama; i < crucigrama + filas; i++){
        for(char* j = *i; j < *i + columnas; j++){
            cout<<*j<<" ";
        }
        cout<<endl;
    }

    search(word, reversedword, wordsize, crucigrama, filas, columnas);

    return 0; 
}

void search(char word[], char reversedword[], int wordsize, char** crossword, int filas, int columnas){
    int founded = 0;
    
    //Horizontal
    for(int i = 0; i < filas; i++){
        int k = 0;
        int l = 0;
        for(int j = 0; j < columnas; j++){
            
            //Normal
            if(*(word + k) == *(*(crossword + i) + j)){
                k++;
                if(k == wordsize){
                    founded++;
                    cout<<"Encontrado en la fila "<<i<<" columna "<<j-wordsize<<endl<<"Total encontrados "<<founded<<endl;
                }
            }
            
            //Inversa
            if(*(reversedword + l) == *(*(crossword + i) + j)){
                l++;
                if(l == wordsize){
                    founded++;
                    cout<<"Encontrado en la fila "<<i<<" columna "<<j-wordsize<<endl<<"Total encontrados "<<founded<<endl;
                }
            }
            
        }
    }

}

void reverse(char* x, int wordsize){
    for(int i = 0; i < wordsize/2; i++){
        swap(*(x+i), *(x + wordsize - i - 1));
    }
}

void swap(char* a, char* b){
    char tmp = *a;
    *b = *a;
    *a = tmp;
}