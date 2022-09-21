#include <stdio.h>

#define CANTIDAD_AMIGOS 5
#define EDAD_MINIMA_AMIGOS 18
#define EDAD_MAXIMA_AMIGOS 100

int main(){
    int edadAmigos1,edadAmigos2,edadAmigos3, edadAmigos4, edadAmigos5;
    int promedioEdadAmigos;

    printf("Las edades de mi amigo@s\n\n");

    printf("Dame la edad de tu amig@ #1 (un valor entre %d y %d): ", EDAD_MINIMA_AMIGOS, EDAD_MAXIMA_AMIGOS);
    scanf("%d", &edadAmigos1);
    printf("Dame la edad de tu amig@ #2 (un valor entre %d y %d): ", EDAD_MINIMA_AMIGOS, EDAD_MAXIMA_AMIGOS);
    scanf("%d", &edadAmigos2);
    printf("Dame la edad de tu amig@ #3 (un valor entre %d y %d): ", EDAD_MINIMA_AMIGOS, EDAD_MAXIMA_AMIGOS);
    scanf("%d", &edadAmigos3);
    printf("Dame la edad de tu amig@ #4 (un valor entre %d y %d): ", EDAD_MINIMA_AMIGOS, EDAD_MAXIMA_AMIGOS);
    scanf("%d", &edadAmigos4);
    printf("Dame la edad de tu amig@ #5 (un valor entre %d y %d): ", EDAD_MINIMA_AMIGOS, EDAD_MAXIMA_AMIGOS);
    scanf("%d", &edadAmigos5);

    promedioEdadAmigos = (edadAmigos1+edadAmigos2+edadAmigos3+edadAmigos4+edadAmigos5) / CANTIDAD_AMIGOS ;

    printf("\nLa edad de mi amigo #1 es %d\n", edadAmigos1);
    printf("La edad de mi amigo #2 es %d\n", edadAmigos2);
    printf("La edad de mi amigo #3 es %d\n", edadAmigos3);
    printf("La edad de mi amigo #4 es %d\n", edadAmigos4);
    printf("La edad de mi amigo #5 es %d\n\n", edadAmigos5);

    printf("Le edad promedio de mis amigos es %d", promedioEdadAmigos);

}