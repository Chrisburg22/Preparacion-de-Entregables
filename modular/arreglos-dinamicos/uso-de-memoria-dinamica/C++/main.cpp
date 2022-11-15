#include <iostream>

#define MAX_ELEMENTOS 5

void inicializarPrograma(int elementos[]);
void imprimirArreglo(int elementos[], char* nombreArreglo);
void copiarElementos(int elementosDestino[], int elementosOrigen[] );

using namespace std;

int main(){
    int* elementosOrigen;
    int elementosDestino[MAX_ELEMENTOS];
    cout << "Memoria dinamica en C++!" << endl << endl;

//Crea un espacio de memoria con la funcion malloc
    elementosOrigen = new int[MAX_ELEMENTOS];

    inicializarPrograma(elementosOrigen);
    imprimirArreglo(elementosOrigen, "elementosOrigen");

    copiarElementos(elementosDestino,elementosOrigen); cout << endl;
    imprimirArreglo(elementosDestino,"elementosDestino");

//Liberando espacio de memoria que se crea de manera dinamica el elementosOrigen
    delete[] elementosOrigen;
    return 0;
}

void inicializarPrograma(int elementos[]){
    int i,j;

    for(i=0, j=MAX_ELEMENTOS;i<MAX_ELEMENTOS; i++,j--){
        elementos[i]=j;
    }
}

void imprimirArreglo(int elementos[], char* nombreArreglo){
    int i;
    for(i=0;i<MAX_ELEMENTOS;i++){
        cout << nombreArreglo << "[" << i << "]" << " = " << elementos[i] << endl;
    }
}

void copiarElementos(int elementosDestino[], int elementosOrigen[]){
    int i;
    for(i=0; i<MAX_ELEMENTOS;i++){
        elementosDestino[i]=elementosOrigen[i];
    }
}