#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANIO_NOMBRE 60

typedef struct {
    int dia;
    int mes;
    int anio;
}Fecha;

typedef struct {
    char nombre[TAMANIO_NOMBRE];
    int edad;
    float estatura;
    char genero;
    Fecha fechaNacimiento;
}Persona;

int main() {
    Persona personaje;
    
    printf("Datos de un nuevo personaje!\n");
    strcpy(personaje.nombre, "Petter Parker");
    
    personaje.edad = 22;
    personaje.estatura = 1.80;
    personaje.genero = 'M';
    personaje.fechaNacimiento.dia = 10;
    personaje.fechaNacimiento.mes =  8;
    personaje.fechaNacimiento.anio = 2001;
    
    printf("Datos del personaje...\n");
    printf("Nombre: %s\n", personaje.nombre);
    printf("Edad: %d\n", personaje.edad);
    printf("Estatura: %f\n", personaje.estatura);
    printf("Genero: %c\n", personaje.genero);
    printf("Fecha de nacimiento\n");
    printf("Dia: %d\n", personaje.fechaNacimiento.dia );
    printf("Mes: %d\n", personaje.fechaNacimiento.mes );
    printf("Anio: %d\n",personaje.fechaNacimiento.anio );

    return 0;
}