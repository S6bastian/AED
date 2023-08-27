#include <iostream>
using namespace std;

int main()
{
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
    for(char** i = crucigrama; i < crucigrama + filas; *i++){
        *i = new char[columnas];
    }

    //Copiar _contenido_ a _crucigrama_
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            *(*(crucigrama + i) + j) = contenido[i][j];
        }
    }

    // Imprimir el contenido copiado
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << crucigrama[i][j] << " ";
        }
        cout << endl;
    }
}
/*
    for (char** i = crucigrama; i < crucigrama + filas; *i++){
        *i = new char[columnas];
        for (char* j = *i; j < *i + columnas; j++){
            j = new char;
        }
*/