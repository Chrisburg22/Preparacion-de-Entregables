#include <stdio.h>
#include <string.h>

#define TAMANI_NOMBRE 12

typedef struct 
{
    char nombre[TAMANI_NOMBRE+2];//El mas 2 se utiliza para escanear con fgets
    int edad;
    float estatura;
    char genero;
} Persona;

int main() {
    Persona personaje1, personaje2;

    printf("Datos de Personajes\n\n");

    printf("Dame los datos de tu personaje #1\n");
    printf("Dime su nombre: ");
    fgets(personaje1.nombre, TAMANI_NOMBRE+2, stdin);
    personaje1.nombre[strlen(personaje1.nombre)-1]='\0';
    //scanf("%s", personaje1.nombre);
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
    fgets(personaje2.nombre, TAMANI_NOMBRE+2, stdin);
    personaje2.nombre[strlen(personaje2.nombre)-1]='\0';
    //scanf("%s", personaje2.nombre);
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

//Formato para imprimir aliniado a la Derecha el numero entre el parentecis 
// y el tipo de dato es la cantidad de espacio que se apartara para esa imprecion
    printf("\nDatos de los personajes\n");
    printf("Nombre         Edad   Estatura   Genero\n");
    printf("%12s    %3d    %4.2f m     %c\n", personaje1.nombre, personaje1.edad,
                                            personaje1.estatura, personaje1.genero);
    printf("%12s    %3d    %4.2f m     %c\n", personaje2.nombre, personaje2.edad,
                                            personaje2.estatura, personaje2.genero);
}