/**
 * DosTres
 * Tiempo: 3:00
 * Ejercicio0_EDA2
 * r0eda21122b Variante 1
*/

#include <iostream>
#include "fechaValida.h"

#define MAX_VALIDACIONES 10

#ifdef _WIN32
#define CLEAR "cls"
#elif defined(unix)||defined(__unix__)||defined(__uninx)||defined(__APPLE__)||defined(__MACH__)
#define CLEAR "clear"
#else
#error "SO no soportado pra limpiar la pantalla"
#endif

using namespace std;

int main (){
    int validar[MAX_VALIDACIONES];

    cout << "Es Fecha Valida" << endl << endl;
    
    //Pruebas de caja negra
    validarFecha(2012,Febrero,30);
    validar[0] = dameCodigoErrorFecha();
    validarFecha(2015,Marzo,32);  
    validar[1] = dameCodigoErrorFecha();
    validarFecha(1999,Agosto,8);  
    validar[2] = dameCodigoErrorFecha();
    validarFecha(2018,Febrero,35);  
    validar[3] = dameCodigoErrorFecha();
    validarFecha(2152,Febrero,28);  
    validar[4] = dameCodigoErrorFecha();
    validarFecha(1523,13,30);  
    validar[5] = dameCodigoErrorFecha();
    validarFecha(2022,Diciembre, 25);  
    validar[6] = dameCodigoErrorFecha();
    validarFecha(2012,Abril,0);  
    validar[7] = dameCodigoErrorFecha();
    validarFecha(2152,0,23);
    validar[8] = dameCodigoErrorFecha();
    validarFecha(2011,Julio,28);
    validar[9] = dameCodigoErrorFecha();

    for(int i=0; i<MAX_VALIDACIONES ; i++){
        switch (validar[i]){
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
    
    return 0;
}




