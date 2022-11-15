#include <stdio.h>
#include <stdlib.h>

#define TAMANO_NOMBRE 60

typedef struct {
    int dia;
    int mes;
    int anio;
}Fecha;

typedef struct {
    char nombre[TAMANO_NOMBRE];
    int edad;
    float estatura;
    char genero;
    Fecha fechaNacimiento;
}Persona;

int main() {
    Persona personaje;
    printf("Datos de personajes\n\n");

    printf("Datos de un@ personaje\n");
    printf("Dame su nombre: ");
    fgets(personaje.nombre, TAMANO_NOMBRE, stdin);
    printf("Dame su edad: ");
    scanf("%d", &personaje.edad);
    printf("Dame su estatura: ");
    scanf("%f", &personaje.estatura);
    getchar();
    printf("Dame su genero: ");
    scanf("%c", &personaje.genero);
    printf("Dame su dia de nacimineto (AAAA/MM/DD): ");
    scanf("%d/%d/%d", &personaje.fechaNacimiento.dia, &personaje.fechaNacimiento.mes, &personaje.fechaNacimiento.anio );
   
    printf("\nDatos del personaje");
    printf("\nNombre: %s\n", personaje.nombre);
    printf("Edad: %d\n", personaje.edad);
    printf("Estatura: %f\n", personaje.estatura);
    printf("Genero: %c\n", personaje.genero);
    printf("Fecha de nacimineto (AAAA/MM/DD): %d/%d/%d\n",   personaje.fechaNacimiento.dia, personaje.fechaNacimiento.mes, personaje.fechaNacimiento.anio);


    return 0;
}
