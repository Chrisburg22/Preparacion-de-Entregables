#include <stdio.h>
#include <stdlib.h>

#define CLEAR "cls"
#define TOTAL_PRACTICAS 7

int main() {

    int calificacionPracticas[TOTAL_PRACTICAS], calificacionFinal=0;

    system(CLEAR);
    printf("Dame la calificacion de la practica #1: ");
    scanf("%d", &calificacionPracticas[0]);
    printf("\nDame la calificacion de la practica #2: ");
    scanf("%d", &calificacionPracticas[1]);
    printf("\nDame la calificacion de la practica #3: ");
    scanf("%d", &calificacionPracticas[2]);
    printf("\nDame la calificacion de la practica #4: ");
    scanf("%d", &calificacionPracticas[3]);
    printf("\nDame la calificacion de la practica #5: ");
    scanf("%d", &calificacionPracticas[4]);
    printf("\nDame la calificacion de la practica #6: ");
    scanf("%d", &calificacionPracticas[5]);
    printf("\nDame la calificacion de la practica #7: ");
    scanf("%d", &calificacionPracticas[6]);

    for( int i=0; i<TOTAL_PRACTICAS; i++){
        calificacionFinal += calificacionPracticas[i];
    }
    calificacionFinal /= TOTAL_PRACTICAS;

    printf("\n\nCalificacion final: %d", calificacionFinal);
}