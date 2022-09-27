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
    printf("Presione enter para continuar . . .");
    getchar();
}

void pedirCalificacion( int num ){
    printf("Dame la calificacion de la practica #%d: ", num + 1);
    scanf("%d", &calificacionPracticas[num]);
}

void capturarCalificaciones() { // Subrutina
    
    imprimirTitulo("CAPTURA DE CALIFICACION");
    for ( int i=0 ; i<TOTAL_PRACTICAS ; i++){
        pedirCalificacion(i);
    }
    pausar();
}

void mostrarCalificaciones(){ // Subrutina
    
    imprimirTitulo("LISTADO DE CALIFICACIONES");
    for ( int i = 0; i<TOTAL_PRACTICAS; i++ )
    {
        printf("Calidicacion #1 parcial: %d\n", calificacionPracticas[i]);
    }
    pausar();
}

void calificacion_final(){ // Subrutina principal.
    
    int calificacionFinal=0;
    imprimirTitulo( "CALIFICACION FINAL");
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