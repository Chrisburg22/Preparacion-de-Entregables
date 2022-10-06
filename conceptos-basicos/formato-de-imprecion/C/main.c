#include <stdio.h>

#define TAMANI_NOMBRE 12

typedef struct 
{
    char nombre[TAMANI_NOMBRE];
    int edad;
    float estatura;
    char genero;
} Persona;

int main() {
    Persona personaje1, personaje2;

    printf("Datos de Personajes\n\n");

    printf("Dame los datos de tu personaje #1\n");
    printf("Dime su nombre: ");
    //fgets(personaje1.nombre, TAMANI_NOMBRE, stdin);
    scanf("%s", personaje1.nombre);
    printf("Dame su edad: ");
    scanf("%d", &personaje1.edad);
    printf("Dame su estatura: ");
    scanf("%f", &personaje1.estatura);
    getchar();
    printf("Dame su genero: ");
    scanf("%c", &personaje1.genero);
    getchar();

    printf("\nDame los datos de tu personaje #2\n");
    printf("Dime su nombre");
    //fgets(personaje2.nombre, TAMANI_NOMBRE, stdin);
    scanf("%s", personaje2.nombre);
    printf("Dame su edad: ");
    scanf("%d", &personaje2.edad);
    printf("Dame su estatura: ");
    scanf("%f", &personaje2.estatura);
    getchar();
    printf("Dame su genero: ");
    scanf("%c", &personaje2.genero);
    getchar();

    printf("Presiona enter para continuar ...");
    getchar();

    printf("\nDatos de los personajes\n");
    printf("Nombre        Edad   Estatura      Genero\n");
    printf("%s    %d      %f     %c\n", personaje1.nombre, personaje1.edad,
                                            personaje1.estatura, personaje1.genero);
    printf("%s    %d      %f    %c\n", personaje2.nombre, personaje2.edad,
                                            personaje2.estatura, personaje2.genero);
}