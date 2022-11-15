#include <stdio.h>

#define CANTIDAD_AMIGOS 5
#define EDAD_MINIMA_AMIGOS 18
#define EDAD_MAXIMA_AMIGOS 100

int main(){
    int edadAmigos[CANTIDAD_AMIGOS],sumaAmigos, edadMayor;
    float promedioEdadAmigos;

    printf("Las edades de mi amigo@s\n\n");

    for(int i=0; i <= 4 ; i++){
        printf("Dame la edad de tu amig@ #%d (un valor entre %d y %d): ", i+1,  EDAD_MINIMA_AMIGOS, EDAD_MAXIMA_AMIGOS);
        scanf("%d", &edadAmigos[i]);
    }

   for( int i=0 ; i<CANTIDAD_AMIGOS ; i++){
    sumaAmigos+=edadAmigos[i];
   }

    promedioEdadAmigos = (float)sumaAmigos / CANTIDAD_AMIGOS ;

    for(int i=0; i<CANTIDAD_AMIGOS ; i++){
        edadMayor = edadAmigos[i];
        if(edadMayor<edadAmigos[i+1]){
        edadMayor = edadAmigos[i+1];
        }
    };
    

   for(int i=0; i<CANTIDAD_AMIGOS ; i++){
        printf("\nLa edad de mi amigo %d es %d", i+1, edadAmigos[i]);
    }

    printf("\n\nLe edad promedio de mis amigos es %f\n", promedioEdadAmigos);
    printf("LA edad mayor de mis amigos es : %d", edadMayor);

    return 0;
}