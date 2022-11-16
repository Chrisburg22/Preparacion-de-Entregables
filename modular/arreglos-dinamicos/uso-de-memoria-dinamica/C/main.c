#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENTOS 5

void inicializarPrograma(int elementos[]);
void imprimirArreglo(int elementos[], char* nombreArreglo);
void copiarElementos(int elementosDestino[], int elementosOrigen[] );

int main(){
    int* elementosOrigen;
    int elementosDestino[MAX_ELEMENTOS];
    printf("Memoria dinamica en C!\n\n");

//Crea un espacio de memoria con la funcion malloc
//Esto es para el uso de arreglos dinamicos    
//Le dices cuantos bite de memoria vas a utilizar
    elementosOrigen = (int*)malloc(MAX_ELEMENTOS*sizeof(int));


    inicializarPrograma(elementosOrigen);
    imprimirArreglo(elementosOrigen, "elementosOrigen");

    copiarElementos(elementosDestino,elementosOrigen);
    printf("\n");
    imprimirArreglo(elementosDestino,"elementosDestino");

//Liberando espacio de memoria que se crea de manera dinamica el elementosOrigen
    free(elementosOrigen);
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
        printf("%s[%d]=%d\n",nombreArreglo,i,elementos[i]);
    }
}

void copiarElementos(int elementosDestino[], int elementosOrigen[]){
    int i;
    for(i=0; i<MAX_ELEMENTOS;i++){
        elementosDestino[i]=elementosOrigen[i];
    }
}