#include <stdio.h>
#include <stdlib.h>

#define TAMANO_NOMBRE 100

int main(){
    short enteroCorto = 32767;
    int entero= 2147483647;
    long enteroLargo = entero;
    unsigned int enteroSinSigno= -1;
    float flotante = 8.9;
    double doble = 9.8;
    char nombre[TAMANO_NOMBRE];
    const int MAX=100;

    printf("Temaños de enteros\n\n");
    printf("Entero corto:%ld\n", sizeof(enteroCorto));
    printf("Entero: %ld\n", sizeof(entero));
    printf("Entero largo: %ld\n", sizeof(enteroLargo));
    printf("Entero sin sigo: %ld\n", sizeof(enteroSinSigno));
    printf("Foltante: %ld\n", sizeof(flotante));
    printf("Doble: %ld \n", sizeof(doble));
    printf("Arreglo Char: %ld\n", sizeof(nombre));
    printf("Const int MAX: %ld\n", sizeof(MAX));
    printf("Constante simbolica TAMANO_NOMBRE: %ld\n", sizeof(TAMANO_NOMBRE));

    return 0;
}