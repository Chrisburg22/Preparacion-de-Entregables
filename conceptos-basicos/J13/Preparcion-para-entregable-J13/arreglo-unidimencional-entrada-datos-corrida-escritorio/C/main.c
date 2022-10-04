#include <stdio.h>

#define CANTIDAD_AMIGOS 5
#define EDAD_MINIMA_AMIGOS 18
#define EDAD_MAXIMA_AMIGOS 100

int main(){
    int edadAmigos[CANTIDAD_AMIGOS],sumaAmigos;
    float promedioEdadAmigos;

    printf("Las edades de mi amigo@s\n\n");

    for(int i=0; i <= 4 ; i++){
        printf("Dame la edad de tu amig@ #1 (un valor entre %d y %d): ", EDAD_MINIMA_AMIGOS, EDAD_MAXIMA_AMIGOS);
        scanf("%d", &edadAmigos[i]);
    }

   for( int i=0 ; i<=4 ; i++){
    sumaAmigos+=edadAmigos[i];
   }

    promedioEdadAmigos = (float)sumaAmigos / CANTIDAD_AMIGOS ;

   
   for(int i=0; i<=4 ; i++){
        printf("\nLa edad de mi amigo %d es %d", i+1, edadAmigos[i]);
    }

    printf("\n\nLe edad promedio de mis amigos es %f\n", promedioEdadAmigos);

}