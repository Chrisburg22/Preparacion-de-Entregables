/**
 * DosTres
 * Tiempo: 00:20
 * Ejercicio0_EDA2
 * r0eda21122b Variante 1
*/

#include <iostream>
#include "Fecha.h"

#ifdef _WIN32
#define CLEAR "cls"
#elif defined(unix)||defined(__unix__)||defined(__uninx)||defined(__APPLE__)||defined(__MACH__)
#define CLEAR "clear"
#else
#error "SO no soportado pra limpiar la pantalla"
#endif

using namespace std;

#define MAX_VALIDACIONES 10
int fechasEvaluadas[MAX_VALIDACIONES];

void evaluandoFechas();
void pausar();

int main (){
    int i;
    cout << "Es Fecha Valida" << endl << endl;
    evaluandoFechas();
    for( i=0; i<MAX_VALIDACIONES ; i++){
        switch (fechasEvaluadas[i]){
            case 0:
                cout << "Fecha valida!!" << endl ;
                break;
            case -1:
                cout << "Mes no valido!!" << endl;
                break;
            case -2:
                cout << "Dia no valido!!" << endl;
                break;
            default:
                break;
        }
    }
    pausar();
    
    return 0;
}

void evaluandoFechas(){
    //Pruebas de caja negra
    validarFecha(2012,Febrero,30);
    fechasEvaluadas[0] = dameCodigoErrorFecha();
    validarFecha(2015,Marzo,32);  
    fechasEvaluadas[1] = dameCodigoErrorFecha();
    validarFecha(1999,Agosto,8);  
    fechasEvaluadas[2] = dameCodigoErrorFecha();
    validarFecha(2018,Febrero,35);  
    fechasEvaluadas[3] = dameCodigoErrorFecha();
    validarFecha(2152,Febrero,29);  
    fechasEvaluadas[4] = dameCodigoErrorFecha();
    validarFecha(1523,13,30);  
    fechasEvaluadas[5] = dameCodigoErrorFecha();
    validarFecha(2022,Diciembre, 25);  
    fechasEvaluadas[6] = dameCodigoErrorFecha();
    validarFecha(2012,Abril,0);  
    fechasEvaluadas[7] = dameCodigoErrorFecha();
    validarFecha(2152,0,23);
    fechasEvaluadas[8] = dameCodigoErrorFecha();
    validarFecha(2011,Julio,28);
    fechasEvaluadas[9] = dameCodigoErrorFecha();
}

void pausar(){
    cout << "Presione enter para continuar . . .";
    cin.ignore();
}

