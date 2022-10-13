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
        cout << "El ABC con Tipos de Datos Primitivos" << endl << endl;
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
            cout << "Dame un valor entero a guardar: ";
            cin >> elemento;
            elementos[cuentaElementos++]=elemento;
            break;
        case BAJA_ELEMENTO:
            cout << "Baja de elemento" << endl << endl;
            cout << "Dame la posicion del valor a remover: ";
            cin >> posicion;
            break;
        case LISTADO_ELEMENTOS:
            cout << "Lisado de elementos " << endl << endl;
            for(int i=0 ; i < cuentaElementos ; i++){
                cout << "Elemento[" << i << "]= " << elementos[i] << endl;
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