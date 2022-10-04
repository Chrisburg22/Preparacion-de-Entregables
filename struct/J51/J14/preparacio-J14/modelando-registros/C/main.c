#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANIO_NOMBRE 60
typedef struct {
    char nombre[TAMANIO_NOMBRE];
    int edad;
    float estatura;
    char genero;
}Persona;

int main() {
    Persona personaje;

    printf("Datos de un nuevo personaje!\n");
    strcpy(personaje.nombre, "Petter Parker");
    personaje.edad = 22;
    personaje.estatura = 1.80;
    personaje.genero = 'M';

    printf("Datos del personaje...\n");
    printf("Nombre: %s\n", personaje.nombre);
    printf("Edad: %d\n", personaje.edad);
    printf("Estatura: %f\n", personaje.estatura);
    printf("Genero: %c\n", personaje.genero);
    
    return 0;
}