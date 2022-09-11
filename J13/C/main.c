#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int factor, vector[10];
    printf("Numeros del vector\n\n");
    
    vector[0]=1;
    vector[1]=2;
    vector[2]=3;
    vector[3]=4;
    vector[4]=5;
    vector[5]=6;
    vector[6]=7;
    vector[7]=8;
    vector[8]=9;
    vector[9]=10;

    printf("Valor celda 1: %d\n", vector[0]);
    printf("Valor celda 2: %d\n", vector[1]);
    printf("Valor celda 3: %d\n", vector[2]);
    printf("Valor celda 4: %d\n", vector[3]);
    printf("Valor celda 5: %d\n", vector[4]);
    printf("Valor celda 6: %d\n", vector[5]);
    printf("Valor celda 7: %d\n", vector[6]);
    printf("Valor celda 8: %d\n", vector[7]);
    printf("Valor celda 9: %d\n", vector[8]);
    printf("Valor celda 10: %d\n\n", vector[9]);

    printf("\nMultiplicaremos los vectores\n");
    printf("Ingresa el valor para multiplicar: ");
    scanf("%d", &factor);

    vector[0]*=factor;
    vector[1]*=factor;
    vector[2]*=factor;
    vector[3]*=factor;
    vector[4]*=factor;
    vector[5]*=factor;
    vector[6]*=factor;
    vector[7]*=factor;
    vector[8]*=factor;
    vector[9]*=factor;   

    printf("Valores modificados\n\n");
    printf("Valor celda 1: %d\n", vector[0]);
    printf("Valor celda 2: %d\n", vector[1]);
    printf("Valor celda 3: %d\n", vector[2]);
    printf("Valor celda 4: %d\n", vector[3]);
    printf("Valor celda 5: %d\n", vector[4]);
    printf("Valor celda 6: %d\n", vector[5]);
    printf("Valor celda 7: %d\n", vector[6]);
    printf("Valor celda 8: %d\n", vector[7]);
    printf("Valor celda 9: %d\n", vector[8]);
    printf("Valor celda 10: %d\n", vector[9]);
    
    return 0;
}