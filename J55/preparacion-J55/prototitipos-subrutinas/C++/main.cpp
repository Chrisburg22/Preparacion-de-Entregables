#include <cstdlib>
#include <iostream>
#include <string.h>


#ifdef _WIN32
#define CLEAR "cls"
#elif defined(unix)||defined(__unix__)||defined(__uninx)||defined(__APPLE__)||defined(__MACH__)
#define CLEAR "clear"
#else
#error "SO no soportado pra limpiar la pantalla"
#endif

#define TOTAL_PRACTICAS 7

using namespace std;

int calificacionPracticas[TOTAL_PRACTICAS];
//Prototipo de las funciones o declarar las funciones
void imprimirTitulo( string titulo );
void pausar();
void pedirCalificacion( int num );
void capturarCalificaciones();
void mostrarCalificaciones();
void calificacion_final();

int main() {
    capturarCalificaciones();
    mostrarCalificaciones();
    calificacion_final();
    return 0;
} 

void imprimirTitulo( string titulo ){
    system(CLEAR); 
    cout << titulo << endl;
}

void pausar(){
    cout << "Presione enter para continuar . . .";
    cin.ignore();
}

void pedirCalificacion( int num ){
    cout << "Dame la calificacion de la practica #" << num + 1 << ": ";
    cin >> calificacionPracticas[num];
    cin.ignore();
}

void capturarCalificaciones() { // Subrutina
    
    imprimirTitulo("CAPTURA DE CALIFICACION\n");
    for ( int i=0 ; i<TOTAL_PRACTICAS ; i++){
        pedirCalificacion(i);
    }
    pausar();
}

void mostrarCalificaciones(){ // Subrutina
    
    imprimirTitulo("LISTADO DE CALIFICACIONES\n");
    for ( int i = 0; i<TOTAL_PRACTICAS; i++ )
    {
         cout << "Calificacion #" << i+1 << " parcial: " << calificacionPracticas[i] << endl;
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
    cout << "\nCalificacion final: " << calificacionFinal << endl;
    pausar();
}
