#include <iostream>

#define MAX_ELEMENTOS 3

enum { ALTA_ELEMENTO=1,BAJA_ELEMENTO, LISTADO_ELEMENTOS, SALIR};

using namespace std;

int main(){
    int elementos[MAX_ELEMENTOS];
    int cuentaElementos=0;
    int elemento, opcionMenu, posicion, i;
    bool salir=true;

    do{
        cout << endl << "El ABC con Tipos de Datos Primitivos" << endl << endl;
        cout << "Elige una de las siguientes opciones" << endl;
        cout << "1. Alta de elemento" << endl;
        cout << "2. Baja de elemento" << endl;
        cout << "3. Listar elementos" << endl;
        cout << "4. Salir" << endl;
        cin >> opcionMenu;

        switch (opcionMenu)
        {
        case ALTA_ELEMENTO:
            cout << "Alta de elemento" << endl << endl;
            if(cuentaElementos<MAX_ELEMENTOS){
               cout << "Dame un valor entero a guardar: ";
               cin >> elemento;
               elementos[cuentaElementos++]=elemento;
            } else {
                cout << endl << "No hay mas espacio para captura de elementos" << endl;
            }
            break;
        case BAJA_ELEMENTO:
            cout << "Baja de elemento" << endl << endl;
            cout << "Dame la posicion (0 a 2) del valor a remover: ";
            cin >> posicion;
            if( posicion<MAX_ELEMENTOS ){
                for(i=posicion, cuentaElementos-- ; i<cuentaElementos ; i++){
                    elementos[i] = elementos[i+1];
                }
            } else {
                cout << endl << "Posicion invalida" << endl;
            }
            break;
        case LISTADO_ELEMENTOS:
            cout << "Listado de elementos " << endl << endl;
            for(int i=0 ; i < cuentaElementos ; i++){
                cout << "Elemento[" << i << "]= " << elementos[i] << endl;
            } 
            if(cuentaElementos == 0){
                cout << endl << "No hay elementos que mostrar" << endl;
            }
            break;
        case SALIR:
            salir = false;
            cout << "bytes!" << endl;
            break;
        default:
            cout << "Opcion no valida";
        }

    } while(salir);
}