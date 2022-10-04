#include <stdio.h>
#include <stdlib.h>

#define TAMANO_NOMBRE 60

typedef struct {
    char nombre[TAMANO_NOMBRE], genero;
    int edad;
    float estatura;
} Persona ;

int main() {
    Persona personaje1, personaje2;
    printf("Datos de personajes\n\n");

    printf("Dame los datos del personaje #1\n");
    printf("Dame su nombre: ");
    fgets(personaje1.nombre, TAMANO_NOMBRE, stdin);
    printf("Dame su edad: ");
    scanf("%d", &personaje1.edad);
    printf("Dame su estatura: ");
    scanf("%f", &personaje1.estatura);
    getchar();
    printf("Dame su genero: ");
    scanf("%c", &personaje1.genero);
    getchar();

    printf("Dame los datos del personaje #2\n");
    printf("Dame su nombre: ");
    fgets(personaje2.nombre, TAMANO_NOMBRE, stdin);
    printf("Dame su edad: ");
    scanf("%d", &personaje2.edad);
    printf("Dame su estatura: ");
    scanf("%f", &personaje2.estatura);
    getchar();
    printf("Dame su genero: ");
    scanf("%c", &personaje2.genero);
    getchar();

    printf("Datos de los personajes\n\n");
    printf("Personaje #1\n");
    printf("Nombre: %s\n", personaje1.nombre);
    printf("Edad: %d\n", personaje1.edad);
    printf("Estatura: %f\n", personaje1.estatura);
    printf("Genero: %c\n", personaje1.genero);

    printf("Personaje #2\n");
    printf("Nombre: %s\n", personaje2.nombre);
    printf("Edad: %d\n", personaje2.edad);
    printf("Estatura: %f\n", personaje2.estatura);
    printf("Genero: %c\n", personaje2.genero);

    return 0;
}
