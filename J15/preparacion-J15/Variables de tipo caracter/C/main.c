#include <stdio.h>
#include <stdlib.h>

int main() {
    char* nombres[2];
    int edad[2];
    float estatura[2];
    char sexo[2];

    nombres[0] = "Lisa";
    edad[0] = 22;
    estatura[0]= 1.60;
    sexo[0] = 'F';
    nombres[1] = "Christian";
    edad[1] = 23;
    estatura[1] = 1.78;
    sexo[1] = 'M';


   printf("ELLA EN PANTALLA\n");
    printf("******************************************************************************************************\n");
    printf("Nombre: %s\n", nombres[0]);
    printf("Edad: %d\n",edad[0]);
    printf("Estatura: %f mts\n", estatura[0]);
    printf("Genero: %c\n", sexo[0]);
    printf("******************************************************************************************************\n\n");

    
    printf("EL EN PANTALLA\n");
    printf("******************************************************************************************************\n");
    printf("Nombre: %s\n", nombres[1]);
    printf("Edad: %d\n",edad[1]);
    printf("Estatura: %f mts\n", estatura[1]);
    printf("Genero: %c\n", sexo[1]);
    printf("******************************************************************************************************\n\n");

}