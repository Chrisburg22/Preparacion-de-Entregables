#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int disco[];
    int tope;
}Pila;

int push(Pila& pila, int disco);
int pop(Pila& pila, int disco);
int pilaVacia(Pila pila);
void iniciarPila(Pila& pila);

void torreDeHanoi(int numeroDiscos,Pila& pilaA,Pila& pilaB,Pila& pilaC,
                                   Pila* posicionPilaA, 
                                   Pila* posicionPilaB,
                                   Pila* posicionPilaC);
void mostrar(Pila C);

int main(){
    int numeroDeDiscos,i;
    Pila pilaA, pilaB, pilaC;
    Pila* posicionPilaA, posicionPilaB, posicionPilaC;

    iniciarPila(pilaA);
    iniciarPila(pilaB);
    iniciarPila(pilaC);

    posicionPilaA = &pilaA;
    posicionPilaB = &pilaB;
    posicionPilaC = &pilaC;

    printf("TORRES DE HANOI\n\n");
    printf("Ingrese la cantidad de discos: ");
    scanf("%d", numeroDeDiscos);
    
    for(i=numeroDeDiscos, i>0; i--){
        push(pilaA, i);
        push(pilaB, 0);
        push(pilaC, 0);
    }
    
    mostrar(pilaA);
    mostrar(pilaA);
    mostrar(pilaB);

    torreDeHanoi(numeroDeDiscos,pilaA,pilaB,pilaC,&posicionPilaA,&posicionPilaB,&posicionPilaC);

}

