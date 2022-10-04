#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#define CLEAR "cls"
#elif defined(unix)||defined(__unix__)||defined(__uninx)||defined(__APPLE__)||defined(__MACH__)
#define CLEAR "clear"
#else
#error "SO no soportado pra limpiar la pantalla"
#endif

#define TOTAL_PRACTICAS 7

int calificacionPracticas[TOTAL_PRACTICAS];

void imprimirTitulo( char* titulo ){
    system(CLEAR); 
    printf( "%s\n", titulo);
}

void pausar(){
    getchar();
    printf("Presiona enter para continuar");
    getchar();
}

void capturarCalificacion() { // Subrutina
    imprimirTitulo("CAPTURA DE CALIFICACION");
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
    pausar();
}

void mostrarCalificaciones(){ // Subrutina
    imprimirTitulo("LISTADO DE CALIFICACIONES");
    printf("Calidicacion #1 parcial: %d\n", calificacionPracticas[0]);
    printf("Calidicacion #2 parcial: %d\n", calificacionPracticas[1]);
    printf("Calidicacion #3 parcial: %d\n", calificacionPracticas[2]);
    printf("Calidicacion #4 parcial: %d\n", calificacionPracticas[3]);
    printf("Calidicacion #5 parcial: %d\n", calificacionPracticas[4]);
    printf("Calidicacion #6 parcial: %d\n", calificacionPracticas[5]);
    printf("Calidicacion #7 parcial: %d\n", calificacionPracticas[6]);
    pausar();
}

void calificacion_final(){ // Subrutina principal.
    imprimirTitulo( "CALIFICACION FINAL");
    int calificacionFinal=0;
    for( int i=0; i<TOTAL_PRACTICAS; i++){
        calificacionFinal += calificacionPracticas[i];
    }
    calificacionFinal = calificacionFinal/TOTAL_PRACTICAS;

    printf("\n\nCalificacion final: %d\n\n", calificacionFinal);
    pausar();
}

int main() {

    capturarCalificacion();
    mostrarCalificaciones();
    calificacion_final();
    
    return 0;
}