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

typedef struct {
    int dia;
    int mes;
    int anio;
}Fecha;

int main() {
    Persona personaje;
    Fecha fechaNacimiento;
    
    printf("Datos de un nuevo personaje!\n");
    strcpy(personaje.nombre, "Petter Parker");
    
    personaje.edad = 22;
    personaje.estatura = 1.80;
    personaje.genero = 'M';
    fechaNacimiento.dia = 10;
    fechaNacimiento.mes =  8;
    fechaNacimiento.anio = 2001;
    
    printf("Datos del personaje...\n");
    printf("Nombre: %s\n", personaje.nombre);
    printf("Edad: %d\n", personaje.edad);
    printf("Estatura: %f\n", personaje.estatura);
    printf("Genero: %c\n", personaje.genero);
    printf("Fecha de nacimiento\n");
    printf("Dia: %d", fechaNacimiento.dia );
    printf("Mes: %d", fechaNacimiento.mes );
    printf("Anio: %d", fechaNacimiento.anio );

    return 0;
}