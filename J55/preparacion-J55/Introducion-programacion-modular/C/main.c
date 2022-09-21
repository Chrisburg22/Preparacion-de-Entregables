<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>

#define CLEAR "cls"
#define TOTAL_PRACTICAS 7

int calificacionPracticas[TOTAL_PRACTICAS];

void capturarCalificacion() { // Subrutina
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
}

void mostrarCalificaciones(){ // Subrutina
    system(CLEAR); 
    printf("Calidicacion #1 parcial: %d\n", calificacionPracticas[0]);
    printf("Calidicacion #2 parcial: %d\n", calificacionPracticas[1]);
    printf("Calidicacion #3 parcial: %d\n", calificacionPracticas[2]);
    printf("Calidicacion #4 parcial: %d\n", calificacionPracticas[3]);
    printf("Calidicacion #5 parcial: %d\n", calificacionPracticas[4]);
    printf("Calidicacion #6 parcial: %d\n", calificacionPracticas[5]);
    printf("Calidicacion #7 parcial: %d\n", calificacionPracticas[6]);
}

void calificacion_final(){ // Subrutina principal.

    int calificacionFinal=0;
    system(CLEAR); 
    for( int i=0; i<TOTAL_PRACTICAS; i++){
        calificacionFinal += calificacionPracticas[i];
    }
    calificacionFinal = calificacionFinal/TOTAL_PRACTICAS;

    printf("\n\nCalificacion final: %d\n\n", calificacionFinal);
}

int main() {

    capturarCalificacion();
    mostrarCalificaciones();
    calificacion_final();
    
    return 0;
=======
#include <stdio.h>
#include <stdlib.h>

#define CLEAR "cls"
#define TOTAL_PRACTICAS 7

int calificacionPracticas[TOTAL_PRACTICAS];

void capturarCalificacion() {
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
}

void mostrarCalificaciones(){
    printf("Calidicacion #1 parcial: %d\n", calificacionPracticas[0]);
    printf("Calidicacion #2 parcial: %d\n", calificacionPracticas[1]);
    printf("Calidicacion #3 parcial: %d\n", calificacionPracticas[2]);
    printf("Calidicacion #4 parcial: %d\n", calificacionPracticas[3]);
    printf("Calidicacion #5 parcial: %d\n", calificacionPracticas[4]);
    printf("Calidicacion #6 parcial: %d\n", calificacionPracticas[5]);
    printf("Calidicacion #7 parcial: %d\n", calificacionPracticas[6]);
}

void calificacion_final(){

    int calificacionFinal=0;
    for( int i=0; i<TOTAL_PRACTICAS; i++){
        calificacionFinal += calificacionPracticas[i];
    }
    calificacionFinal = calificacionFinal/TOTAL_PRACTICAS;

    printf("\n\nCalificacion final: %d", calificacionFinal);
}

int main() {

    system(CLEAR);    
    capturarCalificacion();
    mostrarCalificaciones();
    calificacion_final();
    
    return 0;
>>>>>>> 6b4ddcdec1fd95e40d8ad5eda93e4856333ec062
}