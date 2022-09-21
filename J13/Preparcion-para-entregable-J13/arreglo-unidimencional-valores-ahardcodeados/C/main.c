#include <stdio.h>

#define CANTIDAD_AMIGOS 5

int main(){
    int edadAmigos[CANTIDAD_AMIGOS],sumaAmigos;
    float promedioEdadAmigos;

    edadAmigos[0]=30;
    edadAmigos[1]=25;
    edadAmigos[2]=18;
    edadAmigos[3]=40;
    edadAmigos[4]=55;
    edadAmigos[5]=32;


    printf("Las edades de mi amigo@s\n\n");
  

    promedioEdadAmigos = ( edadAmigos[0] + edadAmigos[1] + edadAmigos[2] + edadAmigos[3] + edadAmigos[4] +edadAmigos[5]) / CANTIDAD_AMIGOS ;

    printf("La edad de mi amigos #1 es: %d\n", edadAmigos[0]);
    printf("La edad de mi amigos #2 es: %d\n", edadAmigos[1]);
    printf("La edad de mi amigos #3 es: %d\n", edadAmigos[2]);
    printf("La edad de mi amigos #4 es: %d\n", edadAmigos[3]);
    printf("La edad de mi amigos #5 es: %d\n", edadAmigos[4]);
    printf("La edad de mi amigos #6 es: %d\n", edadAmigos[5]);

    printf("\n\nLe edad promedio de mis amigos es %f\n", promedioEdadAmigos);

}